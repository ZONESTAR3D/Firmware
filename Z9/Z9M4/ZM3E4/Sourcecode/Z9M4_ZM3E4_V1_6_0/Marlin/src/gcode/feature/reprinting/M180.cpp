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

#if ENABLED(OPTION_REPEAT_PRINTING)

#include "../../gcode.h"
#include "../../../feature/repeat_printing.h"
/**
 * M180: Repeat printing control
 * 
 * S[bool] - enabled or disabled Repeat printing
 * T[int] -  Repeat printing times 
 * L[int] -  Forward move lenght 
 * Example: M180 S1 T10 F310
 * 
 */

void GcodeSuite::M180() {
    if (parser.seen('S')) ReprintManager.enabled = parser.value_bool();
	if (parser.seen('T')) ReprintManager.Reprint_times = parser.value_byte();
	if (parser.seen('L')) ReprintManager.Forward_lenght = parser.value_byte();
}

#endif // OPTION_REPEAT_PRINTING