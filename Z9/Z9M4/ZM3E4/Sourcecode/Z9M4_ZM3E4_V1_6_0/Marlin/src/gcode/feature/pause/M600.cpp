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

#include "../../../inc/MarlinConfig.h"

#if ENABLED(ADVANCED_PAUSE_FEATURE)

#include "../../gcode.h"
#include "../../../feature/pause.h"
#include "../../../module/motion.h"
#include "../../../module/printcounter.h"

#if HAS_MULTI_EXTRUDER
  #include "../../../module/tool_change.h"
#endif

#if HAS_LCD_MENU
  #include "../../../lcd/ultralcd.h"
#endif

#if ENABLED(MMU2_MENUS)
  #include "../../../lcd/menu/menu_mmu2.h"
#endif

#if ENABLED(MIXING_EXTRUDER)
  #include "../../../feature/mixing.h"
#endif

#if HAS_FILAMENT_SENSOR
  #include "../../../feature/runout.h"
#endif

#if HAS_DWIN_LCD
  #include "../../../lcd/dwin/dwin_ui/dwin.h"
#endif

/**
 * M600: Pause for filament change
 *
 *  E[distance] - Retract the filament this far
 *  Z[distance] - Move the Z axis by this distance
 *  X[position] - Move to this X position, with Y
 *  Y[position] - Move to this Y position, with X
 *  U[distance] - Retract distance for removal (manual reload)
 *  L[distance] - Extrude distance for insertion (manual reload)
 *  B[count]    - Number of times to beep, -1 for indefinite (if equipped with a buzzer)
 *  T[toolhead] - Select extruder for filament change
 *  R[temp]     - Resume temperature (in current units)
 *
 *  Default values are used for omitted arguments.
 */
void GcodeSuite::M600() {
	static uint8_t mix_multiplier = 1;
  #if ENABLED(MIXING_EXTRUDER)		
		const uint8_t old_mixing_tool = mixer.get_current_vtool();
    #if(NUM_RUNOUT_SENSORS >= MIXING_STEPPERS)
	    const int8_t target_e_stepper = get_target_e_stepper_from_command();
	    if (target_e_stepper < 0) return;
			mixer.T(MIXER_DIRECT_SET_TOOL);
			MIXER_STEPPER_LOOP(i) mixer.set_collector(i, i == uint8_t(target_e_stepper) ? 1.0 : 0.0);
			mixer.normalize();
		#else
			static mixer_perc_t back_mix[MIXING_STEPPERS];
			COPY(back_mix, mixer.percentmix);
			const int8_t target_e_stepper = get_target_e_stepper_from_command();
	    if(target_e_stepper > 0 && target_e_stepper <= MIXING_STEPPERS)
				mixer.T(target_e_stepper);
			else{				
				mixer.T(MIXER_DIRECT_SET_TOOL);
				mix_multiplier = 0;
				MIXER_STEPPER_LOOP(i){					
					if(back_mix[i] >= 5){ 
						mix_multiplier++;
						mixer.set_collector(i, 1.0);
					}
					else
						mixer.set_collector(i, 0.0);
				}
				mixer.normalize();
			}
		#endif	    
			TERN_(USE_PRECENT_MIXVALUE, mixer.copy_collector_to_percentmix());
	    const int8_t target_extruder = active_extruder;
			#if ENABLED(GRADIENT_MIX)
			const bool old_gradientmix_enabled = mixer.gradient.enabled;
			mixer.gradient.enabled = false;
			#endif
			#if ENABLED(RANDOM_MIX)
			const bool old_randommix_enabled = mixer.random_mix.enabled;
			mixer.random_mix.enabled = false;
			#endif
  #else
    const int8_t target_extruder = get_target_extruder_from_command();
    if (target_extruder < 0) return;
  #endif

  #if ENABLED(DUAL_X_CARRIAGE)
    int8_t DXC_ext = target_extruder;
    if (!parser.seen('T')) {  // If no tool index is specified, M600 was (probably) sent in response to filament runout.
                              // In this case, for duplicating modes set DXC_ext to the extruder that ran out.
      #if HAS_FILAMENT_SENSOR && NUM_RUNOUT_SENSORS > 1
        if (dxc_is_duplicating())
          DXC_ext = (READ(FIL_RUNOUT2_PIN) == FIL_RUNOUT_STATE) ? 1 : 0;
      #else
        DXC_ext = active_extruder;
      #endif
    }
  #endif

  // Show initial "wait for start" message
  #if HAS_LCD_MENU && DISABLED(MMU2_MENUS)
    lcd_pause_show_message(PAUSE_MESSAGE_CHANGING, PAUSE_MODE_PAUSE_PRINT, target_extruder);
  #elif HAS_DWIN_LCD    
    DWIN_Pause_Show_Message(PAUSE_MESSAGE_CHANGING, PAUSE_MODE_PAUSE_PRINT, target_extruder);	
  #endif
  

  #if ENABLED(HOME_BEFORE_FILAMENT_CHANGE)
    // If needed, home before parking for filament change
    if (!all_axes_known()) home_all_axes();
  #endif

  #if HAS_MULTI_EXTRUDER
    // Change toolhead if specified
    const uint8_t active_extruder_before_filament_change = active_extruder;
    if (active_extruder != target_extruder && TERN1(DUAL_X_CARRIAGE, !dxc_is_duplicating()))
      tool_change(target_extruder, false);
  #endif

  // Initial retract before move to filament change position
  const float retract = -ABS(parser.seen('E') ? parser.value_axis_units(E_AXIS) : (PAUSE_PARK_RETRACT_LENGTH));

  xyz_pos_t park_point NOZZLE_PARK_POINT;

  // Lift Z axis
  if (parser.seenval('Z')) park_point.z = parser.linearval('Z');

  // Move XY axes to filament change position or given position
  if (parser.seenval('X')) park_point.x = parser.linearval('X');
  if (parser.seenval('Y')) park_point.y = parser.linearval('Y');

  #if HAS_HOTEND_OFFSET && NONE(DUAL_X_CARRIAGE, DELTA)
    park_point += hotend_offset[active_extruder];
  #endif

  #if ENABLED(MMU2_MENUS)
    // For MMU2 reset retract and load/unload values so they don't mess with MMU filament handling
    constexpr float unload_length = 0.5f,
                    slow_load_length = 0.0f,
                    fast_load_length = 0.0f;
  #else
    // Unload filament
    const float unload_length = -ABS(parser.seen('U') ? parser.value_axis_units(E_AXIS)
                                                      : fc_settings[active_extruder].unload_length);

    // Slow load filament
    constexpr float slow_load_length = FILAMENT_CHANGE_SLOW_LOAD_LENGTH;

    // Fast load filament
    const float fast_load_length = ABS(parser.seen('L') ? parser.value_axis_units(E_AXIS)
                                                        : fc_settings[active_extruder].load_length);
  #endif

  const int beep_count = parser.intval('B', -1
    #ifdef FILAMENT_CHANGE_ALERT_BEEPS
      + 1 + FILAMENT_CHANGE_ALERT_BEEPS
    #endif
  );
  if (pause_print(retract, park_point, unload_length, true, mix_multiplier DXC_PASS)){
    #if ENABLED(MMU2_MENUS)
      mmu2_M600();
      resume_print(slow_load_length, fast_load_length, 0, beep_count, mix_multiplier DXC_PASS);
    #else
      wait_for_confirmation(true, beep_count DXC_PASS);
      resume_print(slow_load_length, fast_load_length, ADVANCED_PAUSE_PURGE_LENGTH,
                   beep_count, mix_multiplier, (parser.seenval('R') ? parser.value_celsius() : 0) DXC_PASS);
    #endif
  }

  #if HAS_MULTI_EXTRUDER
    // Restore toolhead if it was changed
    if (active_extruder_before_filament_change != active_extruder)
      tool_change(active_extruder_before_filament_change, false);
  #endif

	#if ENABLED(MIXING_EXTRUDER)
		mixer.selected_vtool = old_mixing_tool;	
		COPY(mixer.percentmix, back_mix);
		mixer.copy_percentmix_to_collector();
		mixer.normalize();
		TERN_(GRADIENT_MIX,mixer.gradient.enabled = old_gradientmix_enabled);
		TERN_(RANDOM_MIX, mixer.random_mix.enabled = old_randommix_enabled);	
	#endif

  TERN_(HAS_DWIN_LCD, DWIN_Pause_Show_Message(PAUSE_MESSAGE_RETURN));
}

#endif // ADVANCED_PAUSE_FEATURE
