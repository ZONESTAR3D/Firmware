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
#include "../../../feature/pause.h"

#define PAUSE_HEAT

enum{
  PRINT_CASE_TUNE = 0,
  PRINT_CASE_PAUSE,
  PRINT_CASE_STOP,
  PRINT_CASE_END,
};
  
enum{
	TUNE_CASE_BACK = 0,
  TUNE_CASE_SPEED,
#if HAS_HOTEND
  TUNE_CASE_ETEMP,
#endif
#if HAS_HEATED_BED
  TUNE_CASE_BTEMP,
#endif
#if HAS_FAN
  TUNE_CASE_FAN,
#endif
#if ENABLED(BABYSTEPPING)
  TUNE_CASE_ZOFF,
#endif
#if ENABLED(MIXING_EXTRUDER)
  TUNE_CASE_MIXER,
#endif 
  TUNE_CASE_CONFIG,
  TUNE_CASE_END
};
#define	TUNE_CASE_TOTAL	(2+HAS_HOTEND+HAS_HEATED_BED+HAS_FAN+ENABLED(BABYSTEPPING)+ENABLED(MIXING_EXTRUDER))

void DWIN_Refresh_Mix_Rate();
void Redraw_SD_List();
void Draw_Printing_Menu(const bool with_update = false);
void Draw_Print_ProgressBar();
void Draw_Print_ElapsedTime();
void Draw_Print_RemainTime();
void DWIN_Draw_PrintDone_Confirm();
void Draw_Print_ProgressMixModel();

void DWIN_Pause_Show_Message(const PauseMessage message,	const PauseMode mode=PAUSE_MODE_SAME, const uint8_t extruder = 0);
void Draw_Tune_Menu(const uint8_t MenuItem = 0);

void Popup_Window_Resume(); 
void HMI_SDCardInit();
void HMI_SelectFile();
void HMI_Pop_BabyZstep();
void HMI_Zoffset();
void HMI_PrintSpeed();
void HMI_PauseOrStop();
void HMI_Tune();
void HMI_Filament_Runout_Option();
void HMI_Filament_Runout_Confirm();
void HMI_Waiting();
void HMI_Printing();


#endif
