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

enum {
	HOME_CASE_BACK = 0,
	HOME_CASE_ALL,
	HOME_CASE_X,
	HOME_CASE_Y,
	HOME_CASE_Z,
	HOME_CASE_END
};
#define	HOME_CASE_TOTAL	4

enum {
	LEVELING_CASE_BACK = 0,
	LEVELING_CASE_POINT1,
	LEVELING_CASE_POINT2,
	LEVELING_CASE_POINT3,
	LEVELING_CASE_POINT4,
#if ABL_GRID
#if ENABLED(AUTO_UPDATA_PROBE_Z_OFFSET)
	LEVELING_CASE_CATCHOFFSET,
#endif
	LEVELING_CASE_PROBEZOFFSET,
	LEVELING_CASE_ACTION,
#endif 
	LEVELING_CASE_END
};
#define	LEVELING_CASE_TOTAL	(4 + ABL_GRID*2 + ENABLED(AUTO_UPDATA_PROBE_Z_OFFSET))

enum {
	AXISMOVE_CASE_BACK = 0,
	AXISMOVE_CASE_MOVEX,
	AXISMOVE_CASE_MOVEY,
	AXISMOVE_CASE_MOVEZ,
#if HAS_HOTEND
	AXISMOVE_CASE_EX1,
#if(E_STEPPERS > 1) 
	AXISMOVE_CASE_EX2,
#endif
#if(E_STEPPERS > 2) 
	 AXISMOVE_CASE_EX3,
#endif
#if(E_STEPPERS > 3)
	AXISMOVE_CASE_EX4,
#endif
#if ENABLED(MIXING_EXTRUDER)
	AXISMOVE_CASE_EXALL,
#endif 
#endif
	AXISMOVE_CASE_END
};
#define	AXISMOVE_CASE_TOTAL	(3+E_STEPPERS+ENABLED(MIXING_EXTRUDER))

enum {
	LANGUAGE_CASE_BACK = 0,
	LANGUAGE_CASE_EN,
	LANGUAGE_CASE_SP,
	LANGUAGE_CASE_RU,
	LANGUAGE_CASE_FR,
	LANGUAGE_CASE_PT,
	//LANGUAGE_CASE_ZH,
	LANGUAGE_CASE_END
};
#define	LANGUAGE_CASE_TOTAL	5

enum {
	PREPARE_CASE_BACK = 0,
	PREPARE_CASE_HOME,
	PREPARE_CASE_TEMP,
	PREPARE_CASE_MOVE,
	PREPARE_CASE_FILAMENT,
	PREPARE_CASE_LEVELING,	
	PREPARE_CASE_LANG,
	PREPARE_CASE_DISA,
	PREPARE_CASE_POWERDOWN,
	PREPARE_CASE_END
};
#define	PREPARE_CASE_TOTAL	8

enum {
	FILAMENT_CASE_BACK = 0,
	FILAMENT_CASE_PREHEAT,
	FILAMENT_CASE_EXTRUDER,
	FILAMENT_CASE_PURGELENGTH,
	FILAMENT_CASE_FEEDLENGTH,
	FILAMENT_CASE_PURGE,
	FILAMENT_CASE_RETRACT,
	FILAMENT_CASE_LOAD,
	FILAMENT_CASE_UNLOAD,	
	FILAMENT_CASE_END,
};
#define	FILAMENT_CASE_TOTAL	8

typedef enum {
	G29_LEVLE_DEFAULT = 0,
	G29_CATCH_START,
	G29_CATCH_NORMAL,
	G29_CATCH_FAIL1,
	G29_CATCH_FAIL2,
	G29_CATCH_DONE,
	G29_MESH_START,
	G29_MESH_READY,
	G29_MESH_PROBING,	
	G29_MESH_VALUE,
	G29_MESH_DONE
}_emDWIN_G29_MSG;

void DWIN_G29_Show_Messge(const _emDWIN_G29_MSG message = G29_LEVLE_DEFAULT,const int pt_index = 0,const int all_points = 0,const float fvalue = 0.0);
void DWIN_PopMenu_LevelingDone();
void Draw_Prepare_Menu(const uint8_t MenuItem = 0); 
void Draw_Home_Menu(); 
void Draw_Temperature_Menu(); 
void Draw_Move_Menu(); 
void Draw_Filament_Menu();
void Draw_Leveling_Menu(); 
void DWIN_PopMenu_HomeDone();


void HMI_Home(); 
void HMI_Temperature(); 
void HMI_Move_X(); 
void HMI_Move_Y(); 
void HMI_Move_Z(); 
#if HAS_HOTEND
void HMI_Move_Extr(uint8_t extr); 
#if ENABLED(MIXING_EXTRUDER)
void HMI_Move_AllExtr(); 
#endif
#endif
void HMI_Filament_Extuder();
void HMI_Filament_FeedLength();
void HMI_Filament_PurgeLength();
void HMI_Filament();
void HMI_MoveAxis(); 
void HMI_SetProbZoffset();
void HMI_BedLeveling(); 
void HMI_SetLanguage_PicCache(); 
void HMI_Language(); 
void HMI_Powerdown(); 
void HMI_Prepare(); 


#endif
