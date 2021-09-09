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

//Menu item
//
#if ENABLED(MIXING_EXTRUDER)
//Control >> Mixer
enum {
	MIXER_CASE_BACK = 0,
	MIXER_CASE_MANUAL,
	MIXER_CASE_GRADIENT,
	MIXER_CASE_RANDOM,
	MIXER_CASE_VTOOL,
	MIXER_CASE_END
};
#define	MIXER_CASE_TOTAL 4

//Control >> Mixer >> Manual
enum {
	MANUAL_CASE_BACK = 0,
	MANUAL_CASE_VTOOL,
	MANUAL_CASE_EXTRUDER1,
	MANUAL_CASE_EXTRUDER2,
#if(MIXING_STEPPERS > 2)
	MANUAL_CASE_EXTRUDER3,
#endif
#if(MIXING_STEPPERS > 3)
	MANUAL_CASE_EXTRUDER4,
#endif
	MANUAL_CASE_COMMIT,
	MANUAL_CASE_END
};
#define	MANUAL_CASE_TOTAL (MIXING_STEPPERS+2)


//Control >> Mixer >> Gradient
#ifdef GRADIENT_MIX
enum {
	GRADIENT_CASE_BACK = 0,
	GRADIENT_CASE_ZPOS_START,
	GRADIENT_CASE_ZPOS_END,
	GRADIENT_CASE_VTOOL_START,
	GRADIENT_CASE_VTOOL_END,
	GRADIENT_CASE_END
};
#define	GRADIENT_CASE_TOTAL 4
#endif



//Control >> Mixer >> Random
#ifdef RANDOM_MIX
enum {
	RANDOM_CASE_BACK = 0,
	RANDOM_CASE_ZPOS_START,
	RANDOM_CASE_ZPOS_END,
	RANDOM_CASE_HEIGHT,
	RANDOM_CASE_EXTRUDERS,
	RANDOM_CASE_END
};
#define	RANDOM_CASE_TOTAL 4
#endif
#endif

//Control >> configure
enum {
	CONFIG_CASE_BACK = 0,
#if ENABLED(FWRETRACT)
	CONFIG_CASE_RETRACT,
#endif
#if ENABLED(FILAMENT_RUNOUT_SENSOR)
	CONFIG_CASE_FILAMENT,
#endif
#if ENABLED(POWER_LOSS_RECOVERY)
	CONFIG_CASE_POWERLOSS,
#endif
#if ENABLED(OPTION_AUTOPOWEROFF)
	CONFIG_CASE_SHUTDOWN,
#endif
	CONFIG_TUNE_CASE_END,
	//===
#if ENABLED(OPTION_WIFI_MODULE)
	CONFIG_CASE_WIFI = CONFIG_TUNE_CASE_END,
#if ENABLED(OPTION_WIFI_BAUDRATE)
	CONFIG_CASE_WIFISPEED,
#endif
#endif	
#if ENABLED(OPTION_REPEAT_PRINTING)
	CONFIG_CASE_REPRINT,
#endif	
#if ENABLED(OPTION_BED_COATING)
	CONFIG_CASE_COATING,
#endif
#if ABL_GRID
	CONFIG_CASE_LEVELING,
	CONFIG_CASE_ACTIVELEVEL,
#endif
#if ENABLED(RGB_LED)
	CONFIG_CASE_RGB,
#endif
	CONFIG_CASE_END
};
#define	CONFIG_TUNE_CASE_TOTAL (ENABLED(FWRETRACT)+ENABLED(FILAMENT_RUNOUT_SENSOR)+ENABLED(POWER_LOSS_RECOVERY)+ ENABLED(OPTION_AUTOPOWEROFF))
#define	CONFIG_CASE_TOTAL (CONFIG_TUNE_CASE_TOTAL + ENABLED(OPTION_WIFI_MODULE) + ENABLED(OPTION_WIFI_BAUDRATE) + ENABLED(OPTION_REPEAT_PRINTING) + ENABLED(OPTION_BED_COATING) + ABL_GRID*2 + ENABLED(RGB_LED))

//Control >> Configure >> Auto retract
#if ENABLED(FWRETRACT)
enum {
	RETRACT_CASE_BACK = 0,
	RETRACT_CASE_AUTO,
	RETRACT_CASE_RETRACT_MM,
	RETRACT_CASE_RETRACT_V,
	RETRACT_CASE_RETRACT_ZHOP,
	RETRACT_CASE_RECOVER_MM,
	RETRACT_CASE_RECOVER_V,
	RETRACT_CASE_END
};
#define	RETRACT_CASE_TOTAL	6
#endif

//Control >> Configure >> BLTouch
#if ENABLED(BLTOUCH)
enum {
	BLTOUCH_CASE_BACK = 0,
	BLTOUCH_CASE_RESET,
	BLTOUCH_CASE_TEST,
	BLTOUCH_CASE_STOW,
	BLTOUCH_CASE_DEPLOY,
	BLTOUCH_CASE_SW,
	BLTOUCH_CASE_END
};
#define	BLTOUCH_CASE_TOTAL	5
#endif

//Control >> Configure >> Preheat
enum {
	PREHEAT_CASE_BACK = 0,
#if HAS_HOTEND
	PREHEAT_CASE_TEMP,
#endif
#if HAS_HEATED_BED
	PREHEAT_CASE_BED,
#endif
#if HAS_FAN
	PREHEAT_CASE_FAN,
#endif
#if ENABLED(EEPROM_SETTINGS)
	PREHEAT_CASE_SAVE,
#endif
	PREHEAT_CASE_END
};
#define	PREHEAT_CASE_TOTAL	(HAS_HOTEND+HAS_HEATED_BED+HAS_FAN+ENABLED(EEPROM_SETTINGS))

//Control >> Configure >> Motion
enum {
	MOTION_CASE_BACK = 0,
	MOTION_CASE_FEEDRATE,
	MOTION_CASE_ACCEL,
#if ENABLED(HAS_CLASSIC_JERK)
	MOTION_CASE_JERK,
#endif	
	MOTION_CASE_STEPS,
	MOTION_CASE_END
};
#define	MOTION_CASE_TOTAL	(3+ENABLED(HAS_CLASSIC_JERK))

enum {
	MAXFEEDRATE_CASE_BACK = 0,
	MAXFEEDRATE_CASE_X,
	MAXFEEDRATE_CASE_Y,
	MAXFEEDRATE_CASE_Z,
#if HAS_HOTEND
	MAXFEEDRATE_CASE_E,
#endif	
	MAXFEEDRATE_CASE_END
};
#define	MAXFEEDRATE_CASE_TOTAL	(3+HAS_HOTEND)

enum {
	MAXACCL_CASE_BACK = 0,
	MAXACCL_CASE_X,
	MAXACCL_CASE_Y,
	MAXACCL_CASE_Z,
#if HAS_HOTEND
	MAXACCL_CASE_E,
#endif	
	MAXACCL_CASE_END
};
#define	MAXACCL_CASE_TOTAL	(3+HAS_HOTEND)


enum {
	MAXJERK_CASE_BACK = 0,
	MAXJERK_CASE_X,
	MAXJERK_CASE_Y,
	MAXJERK_CASE_Z,
#if HAS_HOTEND
	MAXJERK_CASE_E,
#endif	
	MAXJERK_CASE_END
};
#define	MAXJERK_CASE_TOTAL	(3+HAS_HOTEND)

enum {
	STEPSMM_CASE_BACK = 0,
	STEPSMM_CASE_X,
	STEPSMM_CASE_Y,
	STEPSMM_CASE_Z,
#if HAS_HOTEND
	STEPSMM_CASE_E,
#endif	
	STEPSMM_CASE_END
};
#define	STEPSMM_CASE_TOTAL	(3+HAS_HOTEND)

//Control
enum {
	CONTROL_CASE_BACK = 0,
	CONTROL_CASE_MIXER,
	CONTROL_CASE_CONFIG,
	CONTROL_CASE_MOTION,
	CONTROL_CASE_SETPLA,
	CONTROL_CASE_SETABS,
#if ENABLED(BLTOUCH)	
	CONTROL_CASE_BLTOUCH,
#endif
#if ENABLED(EEPROM_SETTINGS)
	CONTROL_CASE_SAVE,
	CONTROL_CASE_LOAD,
	CONTROL_CASE_RESET,
#endif	
	CONTROL_CASE_END
};
#define	CONTROL_CASE_TOTAL	(3+ENABLED(BLTOUCH)+3*ENABLED(EEPROM_SETTINGS))


void Draw_Control_Menu(const uint8_t MenuItem = 0);

#if ENABLED(MIXING_EXTRUDER)
void Draw_Mixer_Menu(const uint8_t MenuItem = 0);
void HMI_Adjust_Mixer_Manual_Vtool();
void HMI_Adjust_Ext_Percent(uint8_t Extruder_Number);
void HMI_Adjust_Mixer_Vtool();
void HMI_Mixer_Manual();

#if ENABLED(GRADIENT_MIX)
void HMI_Adjust_Gradient_Zpos_Start(); 
void HMI_Adjust_Gradient_Zpos_End(); 
void HMI_Adjust_Gradient_VTool_Start();
void HMI_Adjust_Gradient_VTool_End(); 
void HMI_Mixer_Gradient(); 
#endif

#if ENABLED(RANDOM_MIX)
void HMI_Adjust_Random_Zpos_Start();
void HMI_Adjust_Random_Zpos_End();
void HMI_Adjust_Random_Height();
void HMI_Adjust_Random_Extruders();
void HMI_Mixer_Random();
#endif

void HMI_Mixer(); 
#endif//MIXING_EXTRUDER

void Draw_Config_Menu(const uint8_t MenuItem = 0);

#if ENABLED(FWRETRACT)
void HMI_Retract_MM();
void HMI_Retract_V();
void HMI_Retract_ZHOP();
void HMI_UnRetract_MM();
void HMI_UnRetract_V();
void HMI_Retract(); 
#endif
void HMI_MaxSpeed();
void HMI_MaxFeedspeedXYZE(); 
void HMI_MaxAccelerationXYZE(); 
void HMI_MaxAcceleration(); 

void HMI_MaxJerkXYZE(); 
void HMI_MaxJerk(); 

void HMI_StepXYZE(); 
void HMI_StepPermm(); 
void HMI_Motion();


#if ENABLED(BLTOUCH)
void HMI_Option_Bltouch();
#endif

#if ENABLED(OPTION_BED_COATING)
void HMI_Adjust_Coating_Thickness();
#endif
#if ENABLED(OPTION_WIFI_BAUDRATE)
void HMI_Adjust_WiFi_BaudRate();
#endif


void HMI_Config();

#if HAS_PREHEAT
void HMI_PLAPreheatSetting();
void HMI_ABSPreheatSetting();  
#endif

void HMI_Control(); 

#endif
