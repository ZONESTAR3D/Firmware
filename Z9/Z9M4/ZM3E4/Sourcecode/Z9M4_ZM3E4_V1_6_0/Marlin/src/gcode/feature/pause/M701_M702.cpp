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

#include "../../../inc/MarlinConfigPre.h"

#if ENABLED(FILAMENT_LOAD_UNLOAD_GCODES)

#include "../../gcode.h"
#include "../../../MarlinCore.h"
#include "../../../module/motion.h"
#include "../../../module/temperature.h"
#include "../../../feature/pause.h"

#if HAS_MULTI_EXTRUDER
  #include "../../../module/tool_change.h"
#endif

#if HAS_LCD_MENU
  #include "../../../lcd/ultralcd.h"
#endif

#if ENABLED(PRUSA_MMU2)
  #include "../../../feature/mmu2/mmu2.h"
#endif

#if ENABLED(MIXING_EXTRUDER)
  #include "../../../feature/mixing.h"
#endif

#if HAS_DWIN_LCD
  #include "../../../lcd/dwin/dwin_ui/dwin.h"
#endif

/**
 * M701: Load filament
 *
 *  T<extruder> - Extruder number. Required for mixing extruder.
 *                For non-mixing, current extruder if omitted.
 *  Z<distance> - Move the Z axis by this distance
 *  L<distance> - Extrude distance for insertion (positive value) (manual reload)
 *
 *  Default values are used for omitted arguments.
 */
void GcodeSuite::M701() {
  xyz_pos_t park_point = NOZZLE_PARK_POINT;
	static uint8_t mix_multiplier = 1;
	
  #if ENABLED(NO_MOTION_BEFORE_HOMING)
    // Don't raise Z if the machine isn't homed
    if (axes_should_home()) park_point.z = 0;
  #endif

  #if ENABLED(MIXING_EXTRUDER)
    const int8_t target_e_stepper = get_target_e_stepper_from_command();
    if (target_e_stepper < 0) return;
    const uint8_t old_mixing_tool = mixer.get_current_vtool();

		#if ENABLED(GRADIENT_MIX)
		const bool old_gradientmix_enabled = mixer.gradient.enabled;
		mixer.gradient.enabled = false;
		#endif
		#if ENABLED(RANDOM_MIX)
		const bool old_randommix_enabled = mixer.random_mix.enabled;
		mixer.random_mix.enabled = false;
		#endif			
		static mixer_perc_t back_mix[MIXING_STEPPERS];
		COPY(back_mix, mixer.percentmix);
		
    mixer.T(MIXER_DIRECT_SET_TOOL);
		if(target_e_stepper < MIXING_STEPPERS)
	    MIXER_STEPPER_LOOP(i) mixer.set_collector(i, (i == (uint8_t)target_e_stepper) ? 1.0 : 0.0);
		else{
			MIXER_STEPPER_LOOP(i) mixer.set_collector(i, 1.0);
			mix_multiplier = MIXING_STEPPERS;
		}			
    mixer.normalize();
		TERN_(USE_PRECENT_MIXVALUE,mixer.copy_collector_to_percentmix());
    const int8_t target_extruder = active_extruder;
  #else
    const int8_t target_extruder = get_target_extruder_from_command();
    if (target_extruder < 0) return;
  #endif

  // Z axis lift
  if (parser.seenval('Z')) park_point.z = parser.linearval('Z');

  // Show initial "wait for load" message
  TERN_(HAS_LCD_MENU, lcd_pause_show_message(PAUSE_MESSAGE_LOAD, PAUSE_MODE_LOAD_FILAMENT, target_extruder));
  TERN_(HAS_DWIN_LCD, DWIN_Pause_Show_Message(PAUSE_MESSAGE_LOAD, PAUSE_MODE_LOAD_FILAMENT, target_extruder));
  //SERIAL_ECHOLNPGM("Filament runout load...");
  //SERIAL_EOL();

  #if HAS_MULTI_EXTRUDER && DISABLED(PRUSA_MMU2)
    // Change toolhead if specified
    uint8_t active_extruder_before_filament_change = active_extruder;
    if (active_extruder != target_extruder)
      tool_change(target_extruder, false);
  #endif

  // Lift Z axis
  if (park_point.z > 0)
    do_blocking_move_to_z(_MIN(current_position.z + park_point.z, Z_MAX_POS), feedRate_t(NOZZLE_PARK_Z_FEEDRATE));

  // Load filament
  #if ENABLED(PRUSA_MMU2)
    mmu2.load_filament_to_nozzle(target_extruder);
  #else
    constexpr float     purge_length = ADVANCED_PAUSE_PURGE_LENGTH,
                    slow_load_length = FILAMENT_CHANGE_SLOW_LOAD_LENGTH;
        const float fast_load_length = ABS(parser.seen('L') ? parser.value_axis_units(E_AXIS)
                                                            : fc_settings[active_extruder].load_length);
    load_filament(
      slow_load_length, fast_load_length, purge_length,
      FILAMENT_CHANGE_ALERT_BEEPS,
      true,                                           // show_lcd
      thermalManager.still_heating(target_extruder),  // pause_for_user
      PAUSE_MODE_LOAD_FILAMENT,
      mix_multiplier
      #if ENABLED(DUAL_X_CARRIAGE)
        , target_extruder                             // Dual X target
      #endif			
    );
  #endif

  // Restore Z axis
  if (park_point.z > 0)
    do_blocking_move_to_z(_MAX(current_position.z - park_point.z, 0), feedRate_t(NOZZLE_PARK_Z_FEEDRATE));

  #if HAS_MULTI_EXTRUDER && DISABLED(PRUSA_MMU2)
    // Restore toolhead if it was changed
    if (active_extruder_before_filament_change != active_extruder)
      tool_change(active_extruder_before_filament_change, false);
  #endif

  //MIXING_EXTRUDER
	#if ENABLED(MIXING_EXTRUDER)
		mixer.selected_vtool = old_mixing_tool;	
		COPY(mixer.percentmix, back_mix);
		mixer.copy_percentmix_to_collector();
		mixer.normalize();
		TERN_(GRADIENT_MIX,mixer.gradient.enabled = old_gradientmix_enabled);
		TERN_(RANDOM_MIX, mixer.random_mix.enabled = old_randommix_enabled);	
	#endif

  // Show status screen
  TERN_(HAS_LCD_MENU, lcd_pause_show_message(PAUSE_MESSAGE_STATUS));
  TERN_(HAS_DWIN_LCD, DWIN_Pause_Show_Message(PAUSE_MESSAGE_RETURN));

  //SERIAL_ECHOLNPGM("Filament runout state...");
  //SERIAL_EOL();
}

/**
 * M702: Unload filament
 *
 *  T<extruder> - Extruder number. Required for mixing extruder.
 *                For non-mixing, if omitted, current extruder
 *                (or ALL extruders with FILAMENT_UNLOAD_ALL_EXTRUDERS).
 *  Z<distance> - Move the Z axis by this distance
 *  U<distance> - Retract distance for removal (manual reload)
 *
 *  Default values are used for omitted arguments.
 */
void GcodeSuite::M702() {
  xyz_pos_t park_point = NOZZLE_PARK_POINT;
	uint8_t mix_multiplier = 1;

  #if ENABLED(NO_MOTION_BEFORE_HOMING)
    // Don't raise Z if the machine isn't homed
    if (axes_should_home()) park_point.z = 0;
  #endif

  #if ENABLED(MIXING_EXTRUDER)		
    const uint8_t old_mixing_tool = mixer.get_current_vtool();
		int8_t target_e_stepper = get_target_e_stepper_from_command();
		#if ENABLED(GRADIENT_MIX)
		const bool old_gradientmix_enabled = mixer.gradient.enabled;
		mixer.gradient.enabled = false;
		#endif
		#if ENABLED(RANDOM_MIX)
		const bool old_randommix_enabled = mixer.random_mix.enabled;
		mixer.random_mix.enabled = false;
		#endif			
		static mixer_perc_t back_mix[MIXING_STEPPERS];
		COPY(back_mix, mixer.percentmix);
		if (target_e_stepper < 0){
	    #if ENABLED(FILAMENT_UNLOAD_ALL_EXTRUDERS)
				target_e_stepper = MIXING_STEPPERS;
			#else
				return;
			#endif
		}
    mixer.T(MIXER_DIRECT_SET_TOOL);
		if(target_e_stepper < MIXING_STEPPERS){
	    MIXER_STEPPER_LOOP(i) mixer.set_collector(i, (i == (uint8_t)target_e_stepper) ? 1.0 : 0.0);
		}
		else{
			MIXER_STEPPER_LOOP(i) mixer.set_collector(i, 1.0);
			mix_multiplier = MIXING_STEPPERS;
		}
    mixer.normalize();
		TERN_(USE_PRECENT_MIXVALUE,mixer.copy_collector_to_percentmix());

    const int8_t target_extruder = active_extruder;
  #else
    const int8_t target_extruder = get_target_extruder_from_command();
    if (target_extruder < 0) return;
  #endif

  // Z axis lift
  if (parser.seenval('Z')) park_point.z = parser.linearval('Z');

  // Show initial "wait for unload" message
  TERN_(HAS_LCD_MENU, lcd_pause_show_message(PAUSE_MESSAGE_UNLOAD, PAUSE_MODE_UNLOAD_FILAMENT, target_extruder));
  TERN_(HAS_DWIN_LCD, DWIN_Pause_Show_Message(PAUSE_MESSAGE_UNLOAD, PAUSE_MODE_UNLOAD_FILAMENT, target_extruder));

  #if HAS_MULTI_EXTRUDER && DISABLED(PRUSA_MMU2)
    // Change toolhead if specified
    uint8_t active_extruder_before_filament_change = active_extruder;
    if (active_extruder != target_extruder)
      tool_change(target_extruder, false);
  #endif

  // Lift Z axis
  if (park_point.z > 0)
    do_blocking_move_to_z(_MIN(current_position.z + park_point.z, Z_MAX_POS), feedRate_t(NOZZLE_PARK_Z_FEEDRATE));

  // Unload filament
  #if ENABLED(PRUSA_MMU2)
    mmu2.unload();
  #else
    #if BOTH(HAS_MULTI_EXTRUDER, FILAMENT_UNLOAD_ALL_EXTRUDERS)
    if (!parser.seenval('T')) {
      HOTEND_LOOP() {
        if (e != active_extruder) tool_change(e, false);
	   		unload_filament(-fc_settings[e].unload_length, true, PAUSE_MODE_UNLOAD_FILAMENT);
      }
    }
    else
    #endif
    {
      // Unload length
      const float unload_length = -ABS(parser.seen('U') ? parser.value_axis_units(E_AXIS)
                                                        : fc_settings[target_extruder].unload_length);
	    unload_filament(unload_length, true, PAUSE_MODE_UNLOAD_FILAMENT, mix_multiplier);
    }
  #endif

  // Restore Z axis
  if (park_point.z > 0)
    do_blocking_move_to_z(_MAX(current_position.z - park_point.z, 0), feedRate_t(NOZZLE_PARK_Z_FEEDRATE));

  #if HAS_MULTI_EXTRUDER && DISABLED(PRUSA_MMU2)
    // Restore toolhead if it was changed
    if (active_extruder_before_filament_change != active_extruder)
      tool_change(active_extruder_before_filament_change, false);
  #endif

	//MIXING_EXTRUDER
	#if ENABLED(MIXING_EXTRUDER)
		mixer.selected_vtool = old_mixing_tool;	
		COPY(mixer.percentmix, back_mix);
		mixer.copy_percentmix_to_collector();
		mixer.normalize();
		TERN_(GRADIENT_MIX,mixer.gradient.enabled = old_gradientmix_enabled);
		TERN_(RANDOM_MIX, mixer.random_mix.enabled = old_randommix_enabled);	
	#endif

  // Show status screen
  TERN_(HAS_LCD_MENU, lcd_pause_show_message(PAUSE_MESSAGE_STATUS));
  TERN_(HAS_DWIN_LCD, DWIN_Pause_Show_Message(PAUSE_MESSAGE_RETURN));

  //SERIAL_ECHOLNPGM("Filament runout state...");
  //SERIAL_EOL();
}

#endif // ADVANCED_PAUSE_FEATURE
