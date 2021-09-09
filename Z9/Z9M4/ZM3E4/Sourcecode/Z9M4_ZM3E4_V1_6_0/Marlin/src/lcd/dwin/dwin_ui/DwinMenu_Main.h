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

#pragma once

#include "../../../inc/MarlinConfig.h"
#if HAS_DWIN_LCD
#include "../rotary_encoder.h"
#include "../dwin_lcd.h"
#include "dwin_comm.h"
#include "dwin.h"

enum{
	MAIN_CASE_PRINT = 0,
	MAIN_CASE_PREPARE,
	MAIN_CASE_CONTROL,
	MAIN_CASE_INFO,
	MAIN_CASE_END,
};

void Draw_Main_Menu(const bool with_update = false, const uint8_t MenuItem = 0); 
void Draw_File_Menu();
void HMI_MainMenu();

#endif
