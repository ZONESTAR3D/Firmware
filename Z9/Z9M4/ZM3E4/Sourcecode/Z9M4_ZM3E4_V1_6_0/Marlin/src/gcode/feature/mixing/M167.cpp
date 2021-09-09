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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "../../../inc/MarlinConfig.h"

#if ENABLED(RANDOM_MIX)

#include "../../gcode.h"
#include "../../../module/motion.h"
#include "../../../module/planner.h"
#include "../../../feature/mixing.h"

#if HAS_DWIN_LCD
  #include "../../../lcd/dwin/dwin_ui/dwin.h"
#endif

/**
 * M167: Start a random mixing      
 *
 *   S[bool]  - Enable / disable random mixing
 *   A[float] - Starting Z for the random mixing
 *   Z[float] - Ending Z for the random mixing. (Must be greater than the starting Z.)
 *   H[float] - Minimum height of changing mixing rate
 *   E[int] - how many extruders used on random mixing 
 * Example: M167 S1 A0 Z100 H0.2 E3
 */
void GcodeSuite::M167() {
  if (parser.seen('S')) mixer.random_mix.enabled = parser.value_bool();
  if (parser.seenval('A')) mixer.random_mix.start_z = parser.value_float();
  if (parser.seenval('Z')) mixer.random_mix.end_z = parser.value_float();
  if (parser.seenval('H')) 
  	mixer.random_mix.height= parser.value_float();
  else
  	mixer.random_mix.height = 0.2;
  if (parser.seenval('E')) 
  	mixer.random_mix.extruders = parser.value_byte();
  else
  	mixer.random_mix.extruders = MIXING_STEPPERS;
  
  mixer.refresh_random_mix();

  SERIAL_ECHOPGM("Random Mix ");
  serialprint_onoff(mixer.random_mix.enabled);
  
  if (mixer.random_mix.enabled) {
    SERIAL_ECHOPGM(" ; Start");
		SERIAL_ECHOPAIR_P(SP_Z_STR, mixer.random_mix.start_z);	
    SERIAL_ECHOPGM(" ; End");
		SERIAL_ECHOPAIR_P(SP_Z_STR, mixer.random_mix.end_z);
		SERIAL_ECHOPAIR(" ; Height", mixer.random_mix.height);
    SERIAL_ECHOPAIR(" ; extruders", mixer.random_mix.extruders);
		SERIAL_ECHOPAIR(" ; Current Z", planner.get_axis_position_mm(Z_AXIS));
  }
  SERIAL_EOL();
}

#endif // RANDOM_MIX