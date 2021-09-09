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
#include <WString.h>
#include <stdio.h>
#include <string.h>
#include "../../../module/temperature.h"
#include "../../../module/printcounter.h"
#include "../../../module/motion.h"
#include "../../../module/planner.h"
#include "../../../module/tool_change.h"
#include "../../thermistornames.h"
#include "../../../module/settings.h"
#include "../../../libs/buzzer.h"

#include "../../fontutils.h"
#include "../../ultralcd.h"
#include "../../../sd/cardreader.h"
#include "../../../MarlinCore.h"
#include "../../../core/serial.h"
#include "../../../core/macros.h"
#include "../../../gcode/queue.h"

#if ENABLED(HOST_ACTION_COMMANDS)
  #include "../../../feature/host_actions.h"
#endif
#if ENABLED(FILAMENT_RUNOUT_SENSOR)
#include "../../../feature/runout.h"
#endif
#include "../../../feature/pause.h"
#if HAS_BED_PROBE
  #include "../../../module/probe.h"
#endif
#if ENABLED(BABYSTEPPING)
  #include "../../../feature/babystep.h"
#endif
#if ENABLED(POWER_LOSS_RECOVERY)
  #include "../../../feature/powerloss.h"
#endif
#if HAS_LEVELING
  #include "../../../feature/bedlevel/bedlevel.h"
#endif
#if ENABLED(BLTOUCH)
  #include "../../../feature/bltouch.h"
#endif
#if ENABLED(FWRETRACT)
  #include "../../../feature/fwretract.h"
#endif
#if ENABLED(MIXING_EXTRUDER)
  #include "../../../feature/mixing.h"
#endif

//#define	DEBUG_DWIN_LCD
#define	DWIN_AUTO_TEST

#include "../language/dwin_multi_language.h"
#include "../dwin_lcd.h"
#include "../rotary_encoder.h"
#include "dwin_comm.h"
#include "autotest.h"
#include "DwinMenu_main.h"
#include "DwinMenu_Infor.h"
#include "DwinMenu_Control.h"
#include "DwinMenu_Prepare.h"
#include "DwinMenu_Print.h"

#if ENABLED(OPTION_REPEAT_PRINTING)
#include "DwinMenu_RepeatPrint.h"
#endif

#if ENABLED(SPEAKER)
#define	DWIN_FEEDBACK_TICK()	do{buzzer.tone(10, 500);} while(0)
#else
#define	DWIN_FEEDBACK_TICK()
#endif

#define DWIN_SCROLL_UPDATE_INTERVAL 			1000
#define DWIN_REMAIN_TIME_UPDATE_INTERVAL 	10000
#define POWERDOWN_MACHINE_TIMER 					900//(900*1000/DWIN_SCROLL_UPDATE_INTERVAL)


typedef enum{
	ID_SM_START = 0,
	ID_SM_IDEL,
	ID_SM_PRINTING,	
	ID_SM_PAUSING,				//pause >> wait paused
	ID_SM_PAUSED,
	ID_SM_RESUMING,				//Resuming
	ID_SM_STOPED,					//
	ID_SM_RUNOUTING,
	ID_SM_RETURN_MAIN
}_emDWINState;

extern _emDWINState DWIN_status;

typedef enum {
  // Process ID
  DWMENU_MAIN = 0,
  DWMENU_FILE,
  DWMENU_PREPARE,
  DWMENU_CONTROL,
  DWMENU_INFO,
  
  //Print Menu
  DWMENU_PRINTING,
  DWMENU_TUNE,

	//Prepare menu
  DWMENU_HOME,
  DWMENU_TEMPERATURE,
  DWMENU_PREHEAT_PLA,
	DWMENU_PREHEAT_ABS = 10,
  DWMENU_MOVEAXIS,
  DWMENU_MOVEX,
  DWMENU_MOVEY,
  DWMENU_MOVEZ,
	DWMENU_MOVE_EXT1,
	DWMENU_MOVE_EXT2,
	DWMENU_MOVE_EXT3,
	DWMENU_MOVE_EXT4,
	DWMENU_MOVE_EXTALL,	
	DWMENU_FILAMENT = 20,
	DWMENU_FILAMENT_EXTRUDER,
	DWMENU_FILAMENT_FEEDLENGTH,
	DWMENU_FILAMENT_PURGELENGTH,
	DWMENU_LEVELING,
	DWMENU_POP_LEVEL_CATCH,
	DWMENU_LEVEL_CATCHOFFSET,
	DWMENU_LEVEL_SETOFFSET,
	DWMENU_LEVEL_BEDLEVELING,	
	DWMENU_LEVEL_DONECONFIRM,
		
  //Control menu  
  DWMENU_MIXER  = 30,
  DWMENU_CONFIG,
  DWMENU_MOTION,
  DWMENU_POWERDOWN,
	DWMENU_LANGUAGE,
	DWMENU_SET_ETMP,
	DWMENU_SET_BTMP,
  DWMENU_SET_FANSPEED,
	
	//Tune
	DWMENU_TUNE_PRINTSPEED,
	DWMENU_TUNE_BABYSTEPS,
  
  //Control>>Motion
  DWMENU_SET_MAXSPEED = 40,
  DWMENU_SET_MAXSPEED_VALUE,
  DWMENU_SET_MAXACC,
  DWMENU_SET_MAXACC_VALUE,
  DWMENU_SET_MAXJERK,
  DWMENU_SET_MAXJERK_VALUE,
  DWMENU_SET_STEPPREMM,
  DWMENU_SET_STEPPREMM_VALUE,
  DWMENU_SET_ZOFFSET,

	//Control>>Mixer
	DWMENU_MIXER_MANUAL,
	DWMENU_MIXER_GRADIENT = 50,
	DWMENU_MIXER_RANDOM,
	DWMENU_MIXER_VTOOL,
	//Control>>Mixer>>manual
	DWMENU_MANUALMIXER_VTOOL,
	DWMENU_MIXER_EXT1,
	DWMENU_MIXER_EXT2,
	DWMENU_MIXER_EXT3,
	DWMENU_MIXER_EXT4,
	//Control>>Mixer>>Gradient
	DWMENU_MIXER_GRADIENT_ZSTART,
	DWMENU_MIXER_GRADIENT_ZEND,
	DWMENU_MIXER_GRADIENT_TSTAR = 60,
	DWMENU_MIXER_GRADIENT_TEND,	
	//Control>>Mixer>>Random
	DWMENU_MIXER_RANDOM_ZSTART,
	DWMENU_MIXER_RANDOM_ZEND,
	DWMENU_MIXER_RANDOM_HEIGHT,
	DWMENU_MIXER_RANDOM_EXTN,	
	
 	//config
 	DWMENU_SET_BLTOUCH,
 	DWMENU_SET_RETRACT,
 	//config>>Retract
 	DWMENU_SET_RETRACT_MM,
 	DWMENU_SET_RETRACT_V,
 	DWMENU_SET_RETRACT_ZHOP = 70,
 	DWMENU_SET_UNRETRACT_MM,
 	DWMENU_SET_UNRETRACT_V,	
	//BED Coating
	DWMENU_SET_BEDCOATING,
	DWMENU_SET_WIFIBAUDRATE,
	//Repeat printing
	DWMENU_SET_REPRINT,
	DWMENU_SET_REPRINT_TIMES,
	DWMENU_SET_REPRINT_RUNLENGTH,

	// Pop Menu
	DWMENU_POP_HOME,
	DWMENU_POP_STOPPRINT,
	DWMENU_POP_FROD_OPTION = 80,
	DWMENU_POP_FROD_INSERT,
	DWMENU_POP_FROD_HEAT,
	DWMENU_POP_PAUSEORSTOP,	
	DWMENU_POP_WAITING,

	DWMENU_END
}_emDWIN_MENUID_;

extern _emDWIN_MENUID_ DwinMenuID;


#define	TITLE_X		14
#define	TITLE_Y		7

//
// logo  offset define
//
#define LOGO_OFFSET_X         		20
#define LOGO_OFFSET_Y         		45

//
// Status Area offset define
//
#define State_space_Y         		20
#define State_icon_offset_X    		13
#define State_icon_offset_Y    		381
#define State_text_offset_X    		State_icon_offset_X + STAT_CHR_W*2
#define State_text_offset_Y    		State_icon_offset_Y + 1
#define State_string_offset_X    	State_icon_offset_X + STAT_CHR_W*5
#define State_string_offset_Y    	State_icon_offset_Y + 2

#define State_text_extruder_num		3
#define State_icon_extruder_X 		State_icon_offset_X
#define State_icon_extruder_Y		State_icon_offset_Y
#define State_text_extruder_X		State_text_offset_X
#define State_text_extruder_Y		State_text_offset_Y
#define State_string_extruder_X		State_string_offset_X
#define State_string_extruder_Y		State_string_offset_Y

#define State_text_bed_num			3
#define State_icon_bed_X 			State_icon_offset_X + DWIN_WIDTH/2
#define State_icon_bed_Y			State_icon_offset_Y
#define State_text_bed_X			State_text_offset_X	+ DWIN_WIDTH/2
#define State_text_bed_Y			State_text_offset_Y
#define State_string_bed_X			State_string_offset_X + DWIN_WIDTH/2
#define State_string_bed_Y			State_string_offset_Y

#define State_text_speed_num		3
#define State_icon_speed_X 			State_icon_offset_X
#define State_icon_speed_Y			State_icon_offset_Y + STAT_CHR_H + State_space_Y
#define State_text_speed_X			State_text_offset_X
#define State_text_speed_Y			State_text_offset_Y + STAT_CHR_H + State_space_Y
#define State_string_speed_X		State_string_offset_X
#define State_string_speed_Y		State_string_offset_Y + STAT_CHR_H + State_space_Y

#define State_text_Zoffset_inum		3
#define State_text_Zoffset_fnum		2
#define State_icon_Zoffset_X 		State_icon_offset_X + DWIN_WIDTH/2
#define State_icon_Zoffset_Y		State_icon_offset_Y + STAT_CHR_H + State_space_Y
#define State_text_Zoffset_X		State_text_offset_X + DWIN_WIDTH/2
#define State_text_Zoffset_Y		State_text_offset_Y + STAT_CHR_H + State_space_Y
#define State_string_Zoffset_X		State_string_offset_X + DWIN_WIDTH/2
#define State_string_Zoffset_Y		State_string_offset_Y + STAT_CHR_H + State_space_Y

#define State_text_vtool_num		2

#define State_text_mix_num			3
#define State_icon_mix_X 			13
#define State_icon_mix_Y			45
#define State_text_mix_X			13
#define STATE_TEXT_MIX_Y			State_icon_mix_Y + 25

//
// Menu Area offset define
//
#define Menu_control_start_temp_X		57
#define Menu_control_start_temp_Y		104
#define Menu_control_end_temp_X			84
#define Menu_control_end_temp_Y			116

#define Menu_control_start_motion_X		Menu_control_start_temp_X + 30
#define Menu_control_start_motion_Y		Menu_control_start_temp_Y
#define Menu_control_end_motion_X		Menu_control_end_temp_X + 30
#define Menu_control_end_motion_Y		Menu_control_end_temp_Y

#define Menu_control_start_mixer_X		Menu_control_start_motion_X + 30
#define Menu_control_start_mixer_Y		Menu_control_start_motion_Y
#define Menu_control_end_mixer_X		Menu_control_end_motion_X + 30
#define Menu_control_end_mixer_Y		Menu_control_end_motion_Y

#define Menu_control_start_store_X		Menu_control_start_mixer_X + 30
#define Menu_control_start_store_Y		Menu_control_start_mixer_Y
#define Menu_control_end_store_X		Menu_control_end_mixer_X + 30
#define Menu_control_end_store_Y		Menu_control_end_mixer_Y

#define Menu_control_start_read_X		Menu_control_start_store_X + 30
#define Menu_control_start_read_Y		Menu_control_start_store_Y
#define Menu_control_end_read_X			Menu_control_end_store_X + 30
#define Menu_control_end_read_Y			Menu_control_end_store_Y

#define Menu_control_start_reset_X		Menu_control_start_read_X + 30
#define Menu_control_start_reset_Y		Menu_control_start_read_Y
#define Menu_control_end_reset_X		Menu_control_end_read_X + 30
#define Menu_control_end_reset_Y		Menu_control_end_read_Y

#define Menu_control_start_info_X		Menu_control_start_reset_X + 30
#define Menu_control_start_info_Y		Menu_control_start_reset_Y
#define Menu_control_end_info_X			Menu_control_end_reset_X + 30
#define Menu_control_end_info_Y			Menu_control_end_reset_Y



typedef struct Mixer_Display_cfg{
	uint16_t Extruder_X_Coordinate[MIXING_STEPPERS] = {0};
	uint8_t Extruder_Int_Number[MIXING_STEPPERS] = {0};
	uint16_t VTool_X_Coordinate = 0;
	uint8_t VTool_Int_Number = 0;
	uint8_t Extruder_X_Start_Coordinate[5] = {0,0,34,19,8};
	uint8_t Extruder_X_Start_Gap[5] = {0,0,78,63,52};
	uint8_t Y_Coordinate = 143;
}MIXER_DIS;
extern MIXER_DIS MixerDis;


typedef struct {
  TERN_(HAS_HOTEND,     int16_t E_Temp    = 0);
  TERN_(HAS_HEATED_BED, int16_t Bed_Temp  = 0);
  TERN_(HAS_PREHEAT,    int16_t Fan_speed = 0);
  int16_t print_speed     = 100;
  int16_t Max_Feedspeed     = 0;
  int16_t Max_Acceleration  = 0;
  int16_t Max_Jerk          = 0;
  int16_t Max_Step          = 0;
  int16_t Move_X_scale      = 0;
  int16_t Move_Y_scale      = 0;
  int16_t Move_Z_scale      = 0;	
  int16_t Auto_Zstart_scale  = 0;
  int16_t Auto_Zend_scale    = 0;
  int16_t Random_Zstart_scale  = 0;
  int16_t Random_Zend_scale    = 0;
  int16_t Random_Height = 0;
	#if ENABLED(OPTION_BED_COATING)
  int16_t coating_thickness = 0;
	#endif
  int16_t Retract_MM_scale      = 0;
  int16_t Retract_V_scale      = 0;
	int16_t Retract_ZHOP_scale      = 0;
  int16_t unRetract_MM_scale      = 0;
  int16_t unRetract_V_scale      = 0;
	int16_t Zoffset_Scale      = 0;
	int16_t ProbeZoffset_Scale = 0;
	
  #if HAS_HOTEND	
	int16_t Current_E_Scale[E_STEPPERS];
	float Last_E_Coordinate[E_STEPPERS];
	#if ENABLED(MIXING_EXTRUDER)
	int16_t Current_EAll_Scale    = 0;
	float Last_EAll_Coordinate    = 0;
	int8_t current_vtool = MIXING_STEPPERS+1;
	mixer_perc_t mix_percent[MIXING_STEPPERS] = {0};
	#endif
  #endif

	//load and unload filament
	uint8_t	load_extruder = 1;
	int16_t	feedlength = FILAMENT_CHANGE_FAST_LOAD_LENGTH;
	int16_t	purgelength = FILAMENT_CHANGE_SLOW_LOAD_LENGTH;
		
	uint8_t Percentrecord = 0;
	uint16_t remain_time = 0;
	millis_t dwin_heat_time = 0;
} HMI_value_t;
extern HMI_value_t HMI_Value;

typedef enum{
	SHOWED_TUNE = 0,
	SHOWED_TEMPERATURE,	
	SHOWED_PEHEAT_PLA,
	SHOWED_PEHEAT_ABS
}_emShowMode;


typedef struct {  
  bool 	select_flag:1,
   			heat_flag:1,  					// 0: heating done  1: during heating
   			lcd_sd_status:1,
   			Is_purged:1,
   			Is_retracted:1
		#if (ABL_GRID)
				,Leveling_Menu_Fg:1			
		#endif
		#if ENABLED(OPTION_AUTOPOWEROFF)
				,Autoshutdown_enabled:1
		#endif
		#if ENABLED(FILAMENT_RUNOUT_SENSOR)
				,IS_cancel_runout:1
		#endif
		;

	uint8_t	clean_status_delay = 0;
	uint8_t language;
  uint8_t Title_Menu_Backup = 0;
	
  #if ENABLED(OPTION_WIFI_MODULE)  
  uint8_t wifi_link_timer;
  #endif
  
	#if ENABLED(LCD_BED_LEVELING)	 
  uint8_t Leveling_Case_Total = LEVELING_CASE_POINT4;
  #endif
  
	uint8_t killtimes = 0;
	uint8_t killElapsedTime = 0;
 	
  #if ENABLED(OPTION_AUTOPOWEROFF)
		uint16_t free_close_timer_rg = POWERDOWN_MACHINE_TIMER;
  #endif 

	_emShowMode show_mode  = SHOWED_TUNE;
	#if ENABLED(DWIN_AUTO_TEST)
	uint8_t auto_test_flag = 0x55; //0x55: disable, 0xAA: enabled
  #endif
	#if ENABLED(BABYSTEPPING)
	uint8_t babyshowtime = 0;
	#endif
	
  AxisEnum axis;
} HMI_Flag_t;
extern HMI_Flag_t HMI_flag;

class DwinMenu{
	private:
			
	public:		 	
		static uint8_t now, last;	
		static uint8_t index;
  	void set(uint8_t v) { now = last = v; }
  	void reset() { set(0); index = MROWS;}
  	bool changed() { bool c = (now != last); if (c) last = now; return c; }
  	bool dec() { if (now) now--; return changed(); }
  	bool inc(uint8_t v) { if (now < (v - 1)) now++; else now = (v - 1); return changed(); }
};

extern DwinMenu DwinMenu_main;

extern DwinMenu DwinMenu_prepare;
extern DwinMenu DwinMenu_home;
extern DwinMenu DwinMenu_move;
extern DwinMenu DwinMenu_temp;
extern DwinMenu DwinMenu_filament;
extern DwinMenu DwinMenu_leveling;
extern DwinMenu DwinMenu_powerdown;
extern DwinMenu DwinMenu_language;

extern DwinMenu DwinMenu_control;
extern DwinMenu DwinMenu_motion;
extern DwinMenu DwinMenu_PreheatPLA;
extern DwinMenu DwinMenu_PreheatABS;
extern DwinMenu DwinMenu_feedrate;
extern DwinMenu DwinMenu_accel;
extern DwinMenu DwinMenu_jerk;
extern DwinMenu DwinMenu_step;
#if ENABLED(MIXING_EXTRUDER)
extern DwinMenu DwinMenu_mixer;
extern DwinMenu DwinMenu_manualmix;
extern DwinMenu DwinMenu_GradientMix;
extern DwinMenu DwinMenu_RandomMix;
#endif
#if ENABLED(BLTOUCH)
extern DwinMenu DwinMenu_bltouch;
#endif
#if ENABLED(FWRETRACT)
extern DwinMenu DwinMenu_fwretract;
#endif
extern DwinMenu DwinMenu_configure;

extern DwinMenu DwinMenu_print;
extern DwinMenu DwinMenu_file;
extern DwinMenu DwinMenu_PauseOption;
extern DwinMenu DwinMenu_tune;

extern DwinMenu DwinMenu_infor;

#if ENABLED(OPTION_REPEAT_PRINTING)
extern DwinMenu DwinMenu_reprint;
#endif


#if ENABLED(OPTION_AUTOPOWEROFF)
void _reset_shutdown_timer();
#endif
void set_status_bar_showtime(const uint8_t t);


void Popup_Window_Temperature(const char *msg);
void HMI_DWIN_Init();
void DWIN_Update();
void EachMomentUpdate();
void DWIN_HandleScreen();
void DWIN_Show_M117(const char * const message);

#endif
