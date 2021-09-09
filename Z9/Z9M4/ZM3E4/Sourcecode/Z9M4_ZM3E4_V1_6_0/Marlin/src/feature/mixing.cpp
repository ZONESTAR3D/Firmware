/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../inc/MarlinConfig.h"

#if ENABLED(MIXING_EXTRUDER)

//#define MIXER_NORMALIZER_DEBUG

#include "mixing.h"
#include "../module/motion.h"
#include "../module/planner.h"

Mixer mixer;

#ifdef MIXER_NORMALIZER_DEBUG
  #include "../core/serial.h"
#endif

// Used up to Planner level
int8_t  	  Mixer::selected_vtool = 0;
float         Mixer::collector[MIXING_STEPPERS]; // mix proportion. 0.0 = off, otherwise <= COLOR_A_MASK.
mixer_comp_t  Mixer::color[NR_MIXING_VIRTUAL_TOOLS][MIXING_STEPPERS];
mixer_perc_t Mixer::percentmix[MIXING_STEPPERS];

// Used in Stepper
int_fast8_t   Mixer::runner = 0;
mixer_comp_t  Mixer::s_color[MIXING_STEPPERS];
mixer_accu_t  Mixer::accu[MIXING_STEPPERS] = { 0 };

void Mixer::normalize(const uint8_t tool_index) {
  float cmax = 0;
  #ifdef MIXER_NORMALIZER_DEBUG
    float csum = 0;
  #endif
  MIXER_STEPPER_LOOP(i) {
    const float v = collector[i];
    NOLESS(cmax, v);
    #ifdef MIXER_NORMALIZER_DEBUG
      csum += v;
    #endif
  }
  #ifdef MIXER_NORMALIZER_DEBUG
	SERIAL_ECHOLNPGM("normalize");
	SERIAL_EOL();
	SERIAL_ECHOLNPAIR("tool_index=",uint16_t(tool_index));
	SERIAL_ECHOPGM("Mixer: Old relation : [ ");
	MIXER_STEPPER_LOOP(i) {
		SERIAL_ECHO_F(collector[i] / csum, 3);
		SERIAL_ECHOPGM(", ");
  }
  SERIAL_ECHOLNPGM("]");
	SERIAL_EOL();
  #endif

  // Scale all values so their maximum is COLOR_A_MASK
  const float scale = float(COLOR_A_MASK) / cmax;
  MIXER_STEPPER_LOOP(i) color[tool_index][i] = collector[i] * scale;

#ifdef MIXER_NORMALIZER_DEBUG
  csum = 0;
  SERIAL_ECHOPGM("Mixer: Normalize to : [ ");
  MIXER_STEPPER_LOOP(i) {
    SERIAL_ECHO(uint16_t(color[tool_index][i]));
    SERIAL_ECHOPGM(", ");
    csum += color[tool_index][i];
  }
  SERIAL_ECHOLNPGM("]");
  SERIAL_ECHOPGM("Mixer: New relation : [ ");
  MIXER_STEPPER_LOOP(i) {
    SERIAL_ECHO_F(uint16_t(color[tool_index][i]) / csum, 3);
    SERIAL_ECHOPGM(", ");
  }
  SERIAL_ECHOLNPGM("]");
	SERIAL_EOL();

  SERIAL_ECHOPGM("Mix Percent: [ ");
  MIXER_STEPPER_LOOP(i) {
    SERIAL_ECHO(uint16_t(percentmix[i]));
    SERIAL_ECHOPGM(", ");
  }
  SERIAL_ECHOLNPGM("]");
	SERIAL_EOL();
#endif

}

#if MIXING_2_IN_1_OUT
void Mixer::init_collector(const uint8_t index){
	switch(index){
		default:
		case 0:
			mixer.collector[0] = 10.0;
			mixer.collector[1] = 0.0;
		break;
		case 1:
			mixer.collector[0] = 0.0;
			mixer.collector[1] = 10.0;
		break;
		case 2:
			mixer.collector[0] = 10.0;
			mixer.collector[1] = 10.0;
		break;
		case 3:
			mixer.collector[0] = 9.0;
			mixer.collector[1] = 1.0;
		break;
		case 4:
			mixer.collector[0] = 8.5;
			mixer.collector[1] = 1.5;
		break;
		case 5:
			mixer.collector[0] = 8.0;
			mixer.collector[1] = 2.0;
		break;
		case 6:
			mixer.collector[0] = 7.5;
			mixer.collector[1] = 2.5;
		break;
		case 7:
			mixer.collector[0] = 7.0;
			mixer.collector[1] = 3.0;
		break;
		case 8:
			mixer.collector[0] = 6.5;
			mixer.collector[1] = 3.5;
		break;
		case 9:
			mixer.collector[0] = 6.0;
			mixer.collector[1] = 4.0;
		break;
		case 10:
			mixer.collector[0] = 4.0;
			mixer.collector[1] = 6.0;
		break;
		case 11:
			mixer.collector[0] = 3.5;
			mixer.collector[1] = 6.5;
		break;
		case 12:
			mixer.collector[0] = 3.0;
			mixer.collector[1] = 7.0;
		break;
		case 13:
			mixer.collector[0] = 2.5;
			mixer.collector[1] = 7.5;
		break;
		case 14:
			mixer.collector[0] = 2.0;
			mixer.collector[1] = 8.0;
		break;
		case 15:
			mixer.collector[0] = 1.0;
			mixer.collector[1] = 9.0;
		break;
	}	
}
#endif

#if MIXING_3_IN_1_OUT
void Mixer::init_collector(const uint8_t index){
	switch(index){
		default:
		case 0:
			mixer.collector[0] = 10.0;
			mixer.collector[1] = 0.0;
			mixer.collector[2] = 0.0;
			break;
		case 1:
			mixer.collector[0] = 0.0;
			mixer.collector[1] = 10.0;
			mixer.collector[2] = 0.0;
		break;
		case 2:
			mixer.collector[0] = 0.0;
			mixer.collector[1] = 0.0;
			mixer.collector[2] = 10.0;
		break;
		case 3:
			mixer.collector[0] = 10.0;
			mixer.collector[1] = 10.0;
			mixer.collector[2] = 10.0;
		break;
		case 4:
			mixer.collector[0] = 5.0;
			mixer.collector[1] = 5.0;
			mixer.collector[2] = 0.0;
		break;
		case 5:
			mixer.collector[0] = 5.0;
			mixer.collector[1] = 0.0;
			mixer.collector[2] = 5.0;
		break;
		case 6:
			mixer.collector[0] = 0.0;
			mixer.collector[1] = 5.0;
			mixer.collector[2] = 5.0;
		break;
		case 7:
			mixer.collector[0] = 5.0;
			mixer.collector[1] = 2.5;
			mixer.collector[2] = 2.5;
		break;
		case 8:
			mixer.collector[0] = 2.5;
			mixer.collector[1] = 5.0;
			mixer.collector[2] = 2.5;
		break;
		case 9:
			mixer.collector[0] = 2.5;
			mixer.collector[1] = 2.5;
			mixer.collector[2] = 5.0;
		break;
		case 10:
			mixer.collector[0] = 7.0;
			mixer.collector[1] = 1.5;
			mixer.collector[2] = 1.5;
		break;
		case 11:
			mixer.collector[0] = 1.5;
			mixer.collector[1] = 7.0;
			mixer.collector[2] = 1.5;
		break;
		case 12:
			mixer.collector[0] = 1.5;
			mixer.collector[1] = 1.5;
			mixer.collector[2] = 7.0;
		break;
		case 13:
			mixer.collector[0] = 5.5;
			mixer.collector[1] = 1.5;
			mixer.collector[2] = 3.0;
		break;
		case 14:
			mixer.collector[0] = 5.5;
			mixer.collector[1] = 3.0;
			mixer.collector[2] = 1.5;
		break;
		case 15:
			mixer.collector[0] = 1.5;
			mixer.collector[1] = 3.0;
			mixer.collector[2] = 5.5;
		break;
	}
}
#endif

#if MIXING_4_IN_1_OUT
void Mixer::init_collector(const uint8_t index)
{
	switch(index){
		default:
		case 0:
			mixer.collector[0] = 10.0;
			mixer.collector[1] = 0.0;
			mixer.collector[2] = 0.0;
			mixer.collector[3] = 0.0;
		break;
		case 1:
			mixer.collector[0] = 0.0;
			mixer.collector[1] = 10.0;
			mixer.collector[2] = 0.0;
			mixer.collector[3] = 0.0;
		break;
		case 2:
			mixer.collector[0] = 0.0;
			mixer.collector[1] = 0.0;
			mixer.collector[2] = 10.0;
			mixer.collector[3] = 0.0;
		break;
		case 3:
			mixer.collector[0] = 0.0;
			mixer.collector[1] = 0.0;
			mixer.collector[2] = 0.0;
			mixer.collector[3] = 10.0;
		break;
		case 4:
			mixer.collector[0] = 2.5;
			mixer.collector[1] = 2.5;
			mixer.collector[2] = 2.5;
			mixer.collector[3] = 2.5;
		break;
		case 5:
			mixer.collector[0] = 5.0;
			mixer.collector[1] = 5.0;
			mixer.collector[2] = 0.0;
			mixer.collector[3] = 0.0;
		break;
		case 6:
			mixer.collector[0] = 5.0;
			mixer.collector[1] = 0.0;
			mixer.collector[2] = 5.0;
			mixer.collector[3] = 0.0;
		break;
		case 7:
			mixer.collector[0] = 5.0;
			mixer.collector[1] = 0.0;
			mixer.collector[2] = 0.0;
			mixer.collector[3] = 5.0;
		break;
		case 8:
			mixer.collector[0] = 0.0;
			mixer.collector[1] = 5.0;
			mixer.collector[2] = 5.0;
			mixer.collector[3] = 0.0;
		break;
		case 9:
			mixer.collector[0] = 0.0;
			mixer.collector[1] = 5.0;
			mixer.collector[2] = 0.0;
			mixer.collector[3] = 5.0;
		break;
		case 10:
			mixer.collector[0] = 2.0;
			mixer.collector[1] = 8.0;
			mixer.collector[2] = 0.0;
			mixer.collector[3] = 0.0;
		break;
		case 11:
			mixer.collector[0] = 2.0;
			mixer.collector[1] = 0.0;
			mixer.collector[2] = 8.0;
			mixer.collector[3] = 0.0;
		break;
		case 12:
			mixer.collector[0] = 2.0;
			mixer.collector[1] = 0.0;
			mixer.collector[2] = 0.0;
			mixer.collector[3] = 8.0;
		break;
		case 13:
			mixer.collector[0] = 8.0;
			mixer.collector[1] = 2.0;
			mixer.collector[2] = 0.0;
			mixer.collector[3] = 0.0;
		break;
		case 14:
			mixer.collector[0] = 8.0;
			mixer.collector[1] = 0.0;
			mixer.collector[2] = 2.0;
			mixer.collector[3] = 0.0;
		break;
		case 15:
			mixer.collector[0] = 8.0;
			mixer.collector[1] = 0.0;
			mixer.collector[2] = 0.0;
			mixer.collector[3] = 2.0;
		break;
	}
}
#endif
void Mixer::reset_vtools() {

#if 0
  // Virtual Tools 0, 1, 2, 3 = Filament 1, 2, 3, 4, etc.
  // Every virtual tool gets a pure filament
  LOOP_L_N(t, _MIN(MIXING_VIRTUAL_TOOLS, MIXING_STEPPERS))
    MIXER_STEPPER_LOOP(i)
      color[t][i] = (t == i) ? COLOR_A_MASK : 0;

  // Remaining virtual tools are 100% filament 1
  #if MIXING_VIRTUAL_TOOLS > MIXING_STEPPERS
    LOOP_S_L_N(t, MIXING_STEPPERS, MIXING_VIRTUAL_TOOLS)
      MIXER_STEPPER_LOOP(i)
        color[t][i] = (i == 0) ? COLOR_A_MASK : 0;
  #endif
#else
  mixer.selected_vtool = 0;
  LOOP_L_N(t, MIXING_VIRTUAL_TOOLS){
		init_collector(t);
		normalize(t);
		TERN_(USE_PRECENT_MIXVALUE,copy_collector_to_percentmix());
  }
	mixer.gradient.enabled = 0;
	mixer.gradient.start_z = 0.0;
	mixer.gradient.end_z = 0.0;
	mixer.gradient.start_vtool= 0;
	mixer.gradient.end_vtool = 1;
	
	mixer.random_mix.enabled = 0;
	mixer.random_mix.start_z = 0.0;
	mixer.random_mix.end_z = 0.0;
	mixer.random_mix.height = 0.2;
	mixer.random_mix.extruders = MIXING_STEPPERS;
#endif

  #ifdef MIXER_NORMALIZER_DEBUG
  SERIAL_EOL();
  SERIAL_ECHOLNPGM("reset_vtools!");
  SERIAL_EOL();
  for(uint8_t t=0; t<MIXING_VIRTUAL_TOOLS; t++){
    for(uint8_t i=0; i<MIXING_STEPPERS; i++){ 
    	SERIAL_ECHOPGM("color[ ");
        SERIAL_ECHO(uint16_t(t));
		SERIAL_ECHOPGM("]");
		SERIAL_ECHOPGM("[");
		SERIAL_ECHO(uint16_t(i));
		SERIAL_ECHOPGM("]=");
		SERIAL_ECHO(uint16_t(color[t][i]));
		SERIAL_ECHOPGM(", ");
		SERIAL_EOL();
  	}
  }  
  #endif
}

// called at boot
void Mixer::init() {

  mixer.selected_vtool = 0;
  reset_vtools();

  #if HAS_MIXER_SYNC_CHANNEL
    // AUTORETRACT_TOOL gets the same amount of all filaments
    MIXER_STEPPER_LOOP(i) color[MIXER_AUTORETRACT_TOOL][i] = COLOR_A_MASK;
  #endif

  ZERO(collector);
  
  update_mix_from_vtool(); 

  TERN_(GRADIENT_MIX, update_gradient_for_planner_z());
  TERN_(RANDOM_MIX, update_randommix_for_planner_z());
}

void Mixer::refresh_collector(const float proportion/*=1.0*/, const uint8_t t/*=selected_vtool*/, float (&c)[MIXING_STEPPERS]/*=collector*/) {
  float csum = 0, cmax = 0;
  MIXER_STEPPER_LOOP(i) {
    const float v = color[t][i];
    cmax = _MAX(cmax, v);
    csum += v;
  }

  #ifdef MIXER_NORMALIZER_DEBUG
  SERIAL_ECHOPAIR("Mixer::refresh_collector(", proportion, ", ", int(t), ") cmax=", cmax, "  csum=", csum, "	color");
  #endif
  
  const float inv_prop = proportion / csum;
  MIXER_STEPPER_LOOP(i) {
    c[i] = color[t][i] * inv_prop;
	#ifdef MIXER_NORMALIZER_DEBUG
	SERIAL_ECHOPAIR(" [", int(t), "][", int(i), "] = ", int(color[t][i]), " (", c[i], ")	");
	#endif
  }
  #ifdef MIXER_NORMALIZER_DEBUG
  SERIAL_EOL();
  #endif
}


void Mixer::copy_percentmix_to_collector() {
  MIXER_STEPPER_LOOP(i){
  	collector[i] = (float)percentmix[i]/10.0;
  }
  #ifdef MIXER_NORMALIZER_DEBUG
    SERIAL_ECHOPGM("copy_percentmix_to_collector");
    SERIAL_EOL();
    SERIAL_ECHOPGM("Mix [ ");
    MIXER_STEPPER_LOOP(i){ 
		SERIAL_ECHO(int(percentmix[i]));
		SERIAL_ECHOPGM(", ");
    }
		SERIAL_ECHOPGM(" ] to collector [ ");
		MIXER_STEPPER_LOOP(i){ 
		SERIAL_ECHO(int(collector[i]));
		SERIAL_ECHOPGM(", ");
    }    
    SERIAL_ECHOLNPGM(" ]");
		SERIAL_EOL();
  #endif
}

#if ENABLED(USE_PRECENT_MIXVALUE)
void Mixer::normalize_mixer_percent(mixer_perc_t mix[MIXING_STEPPERS]){
		static uint16_t sum_mix;
		static uint8_t remainder_mix;	
		sum_mix = 0;
		MIXER_STEPPER_LOOP(i) sum_mix += mix[i];	
		MIXER_STEPPER_LOOP(i) mix[i] =	(mixer_perc_t)((mix[i]*100)/sum_mix);
		sum_mix = 0;
		MIXER_STEPPER_LOOP(i) sum_mix += mix[i];
		if(sum_mix < 100){
			sum_mix = 0;
			for(uint8_t i=0; i<MIXING_STEPPERS-1; i++) sum_mix += mix[i];
			if(mix[MIXING_STEPPERS-1] > 0)
				mix[MIXING_STEPPERS-1] = 100 - sum_mix;
			else {
				remainder_mix = 100 - sum_mix;
				for(uint8_t i=0; i<MIXING_STEPPERS-1; i++){
					if(mix[i] > 0 && mix[i] < 100-remainder_mix){
						mix[i] += remainder_mix;
						return;
					}
				}
			}
		}
		else if(sum_mix > 100){
			remainder_mix = sum_mix - 100;
			for(uint8_t i=0; i<MIXING_STEPPERS-1; i++){
				if(mix[i] > 5*remainder_mix){
						mix[i] -= remainder_mix;
						return;
				}
			}
		}
		else
			return;
	}	

void Mixer::copy_collector_to_percentmix() {
	bool need_mux = false;
	float sum_collector = 0.0;
	MIXER_STEPPER_LOOP(i) sum_collector += collector[i];
	if(sum_collector <= 20) 
		need_mux = true;
	else {
		MIXER_STEPPER_LOOP(i)	{
			if(collector[i] > 0.0 && collector[i] <= 1.0) {
				need_mux = true;
				break;
			}
		}
	}
	if(need_mux)
		MIXER_STEPPER_LOOP(i)	percentmix[i] = (mixer_perc_t)(collector[i]*10);
	else
  	MIXER_STEPPER_LOOP(i)	percentmix[i] = (mixer_perc_t)(collector[i]);
  normalize_mixer_percent(&percentmix[0]);
  
  #ifdef MIXER_NORMALIZER_DEBUG
    SERIAL_ECHOLNPGM("copy_collector_to_percentmix");
    SERIAL_EOL();
    SERIAL_ECHOPGM("collector [ ");
    MIXER_STEPPER_LOOP(i){ 
		SERIAL_ECHO(int(collector[i]));
		SERIAL_ECHOPGM(", ");
    }
	SERIAL_ECHOPGM(" ] to Mix [ ");
	MIXER_STEPPER_LOOP(i){ 
		SERIAL_ECHO(int(percentmix[i]));
		SERIAL_ECHOPGM(", ");
    }    
    SERIAL_ECHOLNPGM(" ]");
	SERIAL_EOL();
  #endif
}  
#endif

float Mixer::mix_prev_z = 0.0;

#if ENABLED(GRADIENT_MIX)
gradient_t Mixer::gradient = {
  false,    // enabled
  {0},      // color (array)
  0, 0,     // start_z, end_z
  0, 1,     // start_vtool, end_vtool
  {0}, {0}  // start_mix[], end_mix[]
  #if ENABLED(GRADIENT_VTOOL)
    , -1    // vtool_index
  #endif
};

void Mixer::update_gradient_for_z(const float z) {
  if (z - mix_prev_z < 0.05) return;
  mix_prev_z = z;
	int16_t pct = 0;
	if(z >= gradient.start_z){
		pct = (int16_t)(((z - gradient.start_z) / (gradient.end_z - gradient.start_z))*100);
    NOLESS(pct, 0); 
		NOMORE(pct, 100);
		MIXER_STEPPER_LOOP(i) {
    	const mixer_perc_t sm = gradient.start_mix[i];
    	percentmix[i] = sm + (mixer_perc_t)(((gradient.end_mix[i] - sm) * pct)/100);
  	}
  	copy_percentmix_to_color(gradient.color);		
	}
}

void Mixer::update_gradient_for_planner_z() {
  update_gradient_for_z(planner.get_axis_position_mm(Z_AXIS));
}

#endif // GRADIENT_MIX

#if ENABLED(RANDOM_MIX)
randommix_t Mixer::random_mix = {
    false,    // enabled
    0, 0,     // start_z, end_z
    0.2,      // height
    MIXING_STEPPERS
};

void Mixer::update_randommix_for_z(const float z) {	
	if (z - mix_prev_z < (random_mix.height - 0.05)) return;	
	if(z >= random_mix.start_z && z <= random_mix.end_z){
		mix_prev_z = z;
		if(random_mix.extruders == 1){
			uint8_t cur_ext = random(100)%MIXING_STEPPERS;
			MIXER_STEPPER_LOOP(i){
				if(i == cur_ext)
					collector[i] = 10.0;
				else
					collector[i] = 0.0;					
			}
		}
		else{
			MIXER_STEPPER_LOOP(i){
			  if(i < random_mix.extruders) 
				collector[i] = (float)(random(100)/10);
			  else
				collector[i] = 0;
			}
		}
		//collector==>color, it is for printing
		normalize(selected_vtool);
		//collector==>percentmix,it is for display
		TERN_(USE_PRECENT_MIXVALUE,copy_collector_to_percentmix());
  }
}

void Mixer::update_randommix_for_planner_z() {
    update_randommix_for_z(planner.get_axis_position_mm(Z_AXIS));
}

#endif//RANDOM_MIX
#endif // MIXING_EXTRUDER
