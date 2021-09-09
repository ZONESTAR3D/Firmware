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

/**
 * DWIN.cpp
 */

#include "../../../inc/MarlinConfig.h"

#if HAS_DWIN_LCD
#include <WString.h>
#include <stdio.h>
#include <string.h>

#include "../language/dwin_multi_language.h"
#include "../dwin_lcd.h"
#include "../rotary_encoder.h"
#include "dwin_comm.h"
#include "autotest.h"
#include "dwinmenu_main.h"
#include "dwinmenu_print.h"
#include "dwinmenu_prepare.h"
#include "dwinmenu_control.h"
#include "dwinmenu_infor.h"

#if ENABLED(MIXING_EXTRUDER)
  #include "../../../feature/mixing.h"
#endif

#if ENABLED(OPTION_REPEAT_PRINTING)
  #include "../../../feature/repeat_printing.h"
	#include "dwinmenu_repeatprint.h"
#endif

#include "../../fontutils.h"
#include "../../ultralcd.h"

#include "../../../sd/cardreader.h"

#include "../../../MarlinCore.h"
#include "../../../core/serial.h"
#include "../../../core/macros.h"
#include "../../../gcode/queue.h"

#ifdef DEBUG_DWIN_LCD
static uint8_t old_DwinMenuID = 255;
static uint8_t old_DwinStatus = 255;
#endif

_emDWINState DWIN_status = ID_SM_START;
_emDWIN_MENUID_ DwinMenuID = DWMENU_MAIN;
HMI_value_t HMI_Value;
HMI_Flag_t HMI_flag;
MIXER_DIS MixerDis;

uint8_t DwinMenu::now;
uint8_t DwinMenu::last;
uint8_t DwinMenu::index;


DwinMenu DwinMenu_main;
//Prepare
DwinMenu DwinMenu_prepare;
DwinMenu DwinMenu_home;
DwinMenu DwinMenu_move;
DwinMenu DwinMenu_temp;
DwinMenu DwinMenu_filament;
DwinMenu DwinMenu_leveling;
DwinMenu DwinMenu_powerdown;
DwinMenu DwinMenu_language;
//control
DwinMenu DwinMenu_control;
DwinMenu DwinMenu_motion;
DwinMenu DwinMenu_PreheatPLA;
DwinMenu DwinMenu_PreheatABS;
DwinMenu DwinMenu_configure;
DwinMenu DwinMenu_feedrate;
DwinMenu DwinMenu_accel;
DwinMenu DwinMenu_jerk;
DwinMenu DwinMenu_step;
#if ENABLED(MIXING_EXTRUDER)
DwinMenu DwinMenu_mixer;
DwinMenu DwinMenu_manualmix;
DwinMenu DwinMenu_GradientMix;
DwinMenu DwinMenu_RandomMix;
#endif
#if ENABLED(BLTOUCH)
DwinMenu DwinMenu_bltouch;
#endif
#if ENABLED(FWRETRACT)
DwinMenu DwinMenu_fwretract;
#endif
#if ENABLED(OPTION_REPEAT_PRINTING)
DwinMenu DwinMenu_reprint;
#endif
//Print
DwinMenu DwinMenu_print;
DwinMenu DwinMenu_file;
DwinMenu DwinMenu_PauseOption;
DwinMenu DwinMenu_tune;
//Infor
DwinMenu DwinMenu_infor;

void set_status_bar_showtime(const uint8_t t){
	if(t > 0) HMI_flag.clean_status_delay = t;
}

inline void _check_clean_status_bar(){
	if(HMI_flag.clean_status_delay > 0){
		HMI_flag.clean_status_delay--;
		if(HMI_flag.clean_status_delay == 0) Clear_Dwin_Area(AREA_BOTTOM);
	}
}

inline void _check_kill_times_ElapsedTime(){
	if(HMI_flag.killElapsedTime > 0 && HMI_flag.killtimes > 0){
		HMI_flag.killElapsedTime--;
		if(HMI_flag.killElapsedTime == 0){ 
			HMI_flag.killtimes = 0;
			if(HMI_flag.clean_status_delay == 0) Clear_Dwin_Area(AREA_BOTTOM);
		}
	}
}

inline void _Update_printing_Timer(){
	// print process
	if(card.isPrinting()){
		const uint8_t card_pct = card.percentDone();
		static uint8_t last_cardpercentValue = 101;
	
		if(last_cardpercentValue != card_pct) { // print percent
			last_cardpercentValue = card_pct;
			if(card_pct) {
				HMI_Value.Percentrecord = card_pct;
				if(DwinMenuID == DWMENU_PRINTING) Draw_Print_ProgressBar();
			}
		}
		duration_t elapsed = print_job_timer.duration(); // print timer

		// Print time so far
		static uint16_t last_Printtime = 0;
		const uint16_t min = (elapsed.value % 3600) / 60;
		if (last_Printtime != min) { // 1 minute update
			last_Printtime = min;			
			if(DwinMenuID == DWMENU_PRINTING) Draw_Print_ElapsedTime();
		}

		// Estimate remaining time every 20 seconds
		const millis_t ms = millis();	
		static millis_t next_remain_time_update = 0;
		if(HMI_Value.Percentrecord >= 1 && ELAPSED(ms, next_remain_time_update) && !HMI_flag.heat_flag) {
			 HMI_Value.remain_time = (((elapsed.value - HMI_Value.dwin_heat_time) * 100) / HMI_Value.Percentrecord) - (elapsed.value - HMI_Value.dwin_heat_time);
			 next_remain_time_update += 20 * 1000UL;
			 if(DwinMenuID == DWMENU_PRINTING) Draw_Print_RemainTime();
		}
	}
}


#if ENABLED(OPTION_AUTOPOWEROFF)
inline void _setAutoPowerDown(){
	HMI_flag.free_close_timer_rg = POWERDOWN_MACHINE_TIMER;
}
#endif


#if ENABLED(OPTION_WIFI_MODULE)
inline void _check_wifi(){
	if(WiFi_Enabled && queue.wifi_Handshake_ok){
		HMI_flag.wifi_link_timer = 0;		
		if(DwinMenuID == DWMENU_MAIN)	DWIN_Show_ICON(ICON_WIFI, 0, 0);
	}		
}

inline void _check_wifi_feedback(){	
	if(WiFi_Enabled && HMI_flag.wifi_link_timer > 0){
		HMI_flag.wifi_link_timer--;
		if(queue.wifi_Handshake_ok){
			HMI_flag.wifi_link_timer = 0;			
			if(DwinMenuID == DWMENU_MAIN) DWIN_Show_ICON(ICON_WIFI, 0, 0);
		}
		else if(HMI_flag.wifi_link_timer == 0){
			DWIN_Show_Status_Message(COLOR_RED, PSTR("WiFi connect fail!"));
		}		
	}
}
#endif

#if(ENABLED(POWER_LOSS_RECOVERY))
inline void _check_Powerloss_resume(){
	static bool recovery_flag = false;

	auto update_selection = [&](const bool sel) {
		HMI_flag.select_flag = sel;
		const uint16_t c1 = sel ? COLOR_BG_WINDOW : SELECT_COLOR;
		dwinLCD.Draw_Rectangle(0, c1, 25, 306, 126, 345);
		dwinLCD.Draw_Rectangle(0, c1, 24, 305, 127, 346);
		const uint16_t c2 = sel ? SELECT_COLOR : COLOR_BG_WINDOW;
		dwinLCD.Draw_Rectangle(0, c2, 145, 306, 246, 345);
		dwinLCD.Draw_Rectangle(0, c2, 144, 305, 247, 346);
	};
	
	if(HMI_flag.lcd_sd_status && recovery.dwin_flag && recovery.enabled){
		recovery.dwin_flag = false;
		recovery_flag = true;
		Popup_Window_Resume();
		update_selection(true);
		/// TODO: Get the name of the current file from someplace
		//
		//(void)recovery.interrupted_file_exists();
		char * const name = card.longest_filename();
		const int8_t npos = _MAX(0U, DWIN_WIDTH - strlen(name) * 10) / 2;
		DWIN_Draw_MaskString_Default_PopMenu( npos, 252, name);
		dwinLCD.UpdateLCD();

		while (recovery_flag) {
			ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
			if (encoder_diffState != ENCODER_DIFF_NO) {
				if (encoder_diffState == ENCODER_DIFF_ENTER) {
					//cancel resume!
					recovery_flag = false;
					if(HMI_flag.select_flag) break;
					queue.inject_P(PSTR("M1000C"));
					DWIN_Show_Status_Message(COLOR_RED, PSTR("Delete Power loss Record!"));
					DWIN_status = ID_SM_RETURN_MAIN;
					return;
				}
				else {
					update_selection(encoder_diffState == ENCODER_DIFF_CW);
					DWIN_FEEDBACK_TICK();
				}
				dwinLCD.UpdateLCD();
			}
			TERN_(USE_WATCHDOG, HAL_watchdog_refresh());
		}		
		HMI_flag.show_mode = SHOWED_TUNE;
		DWIN_status = ID_SM_PRINTING;
		queue.inject_P(PSTR("M1000"));
		DwinMenu_print.reset();
		Draw_Printing_Menu(true);
	}
}
#endif//(ENABLED(POWER_LOSS_RECOVERY))

void DWIN_Show_M117(const char * const message){
	#define MAX_WIFI_MESSAGE_LENGTH 27
	#define START_OF_UTF8_CHAR(C) (((C) & 0xC0u) != 0x80U)
	
	char wifi_status_message[MAX_WIFI_MESSAGE_LENGTH+1] = {0};
	// Here we have a problem. The message is encoded in UTF8, so
	// arbitrarily cutting it will be a problem. We MUST be sure
	// that there is no cutting in the middle of a multibyte character!
	// Get a pointer to the null terminator
	const char* pend = message + strlen(message);
	// If length of supplied UTF8 string is greater than
	// our buffer size, start cutting whole UTF8 chars
	while ((pend - message) > MAX_WIFI_MESSAGE_LENGTH) {
	 --pend;
	 while (!START_OF_UTF8_CHAR(*pend)) --pend;
	};	
	uint8_t maxLen = pend - message;
	strncpy(wifi_status_message, message, maxLen);
	wifi_status_message[maxLen] = '\0';
	
	Clear_Dwin_Area(AREA_BOTTOM);
	DWIN_Draw_MaskString_Default_Color(COLOR_WHITE, 10, 455, wifi_status_message);

	TERN_(OPTION_WIFI_MODULE, _check_wifi());
}

#if ENABLED(MIXING_EXTRUDER)
inline void DWIN_Show_Mixing_status() {
	static uint8_t last_mixer_percent[MIXING_STEPPERS] = {0};
  static uint8_t last_vtool = 0;
	static bool bupdata = false;
	if(DwinMenuID == DWMENU_PRINTING){
		//mixing rate changed?
		MIXER_STEPPER_LOOP(i){
			if(last_mixer_percent[i] != mixer.percentmix[i]){
				bupdata = true;
				break;
			}
		}
		//vool changed?
		if(last_vtool != mixer.selected_vtool){
			last_vtool = mixer.selected_vtool;
			mixer.update_mix_from_vtool();
			bupdata = true;
		}
		if(bupdata){
			MIXER_STEPPER_LOOP(i) last_mixer_percent[i] = mixer.percentmix[i];
			DWIN_Refresh_Mix_Rate();
			Draw_Print_ProgressMixModel();		
			bupdata = false;
		}
	}	
}
#endif

inline void DWIN_Update_Variable() {
 #if HAS_HOTEND
  static float last_temp_hotend_target = 0, last_temp_hotend_current = 0;
 #endif
 #if HAS_HEATED_BED
  static float last_temp_bed_target = 0, last_temp_bed_current = 0;
 #endif
 #if HAS_FAN
  static uint8_t last_fan_speed = 0;
 #endif

 static uint8_t flash_mask = 0;

 /* Tune page temperature update */
	if (DwinMenuID == DWMENU_TUNE){
#if HAS_HOTEND
		if(last_temp_hotend_target != thermalManager.temp_hotend[0].target)
		  DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(TUNE_CASE_ETEMP + MROWS - DwinMenu_tune.index), thermalManager.temp_hotend[0].target);
#endif
#if HAS_HEATED_BED
		if(last_temp_bed_target != thermalManager.temp_bed.target)
		  DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(TUNE_CASE_BTEMP + MROWS - DwinMenu_tune.index), thermalManager.temp_bed.target);
#endif
#if HAS_FAN
		if(last_fan_speed != thermalManager.fan_speed[0]) {
		  DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(TUNE_CASE_FAN + MROWS - DwinMenu_tune.index), thermalManager.fan_speed[0]);
		  last_fan_speed = thermalManager.fan_speed[0];
		}
#endif
	}

 /* Temperature page temperature update */
	if (DwinMenuID == DWMENU_TEMPERATURE) {
#if HAS_HOTEND
		if (last_temp_hotend_target != thermalManager.temp_hotend[0].target)
			DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(TEMP_CASE_ETEMP + MROWS - DwinMenu_temp.index), thermalManager.temp_hotend[0].target);
#endif
#if HAS_HEATED_BED
		if (last_temp_bed_target != thermalManager.temp_bed.target)
			DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(TEMP_CASE_BTEMP + MROWS - DwinMenu_temp.index), thermalManager.temp_bed.target);
#endif
#if HAS_FAN
		if (last_fan_speed != thermalManager.fan_speed[0]) {
			DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(TEMP_CASE_FAN + MROWS - DwinMenu_temp.index), thermalManager.fan_speed[0]);
			last_fan_speed = thermalManager.fan_speed[0];
		}
#endif
	}

 /* Bottom temperature update */
#if HAS_HOTEND
	if (last_temp_hotend_current != thermalManager.temp_hotend[0].celsius) {
		DWIN_Draw_IntValue_FONT10((thermalManager.temp_hotend[0].celsius > 230)? COLOR_RED : COLOR_WHITE, State_text_extruder_num, State_text_extruder_X, State_text_extruder_Y, thermalManager.temp_hotend[0].celsius);
		last_temp_hotend_current = thermalManager.temp_hotend[0].celsius;
	}
	if (last_temp_hotend_target != thermalManager.temp_hotend[0].target) {
		if(DwinMenuID == DWMENU_POP_FROD_HEAT && ((++flash_mask&0x01) == 0x01))
			DWIN_Draw_UnMaskString_FONT10(State_text_extruder_X + (State_text_extruder_num + 1) * STAT_CHR_W, State_text_extruder_Y, PSTR("    "));		
		else 
			DWIN_Draw_IntValue_FONT10((thermalManager.temp_hotend[0].target > 230)?COLOR_RED : COLOR_WHITE, State_text_extruder_num, State_text_extruder_X + (State_text_extruder_num + 1) * STAT_CHR_W, State_text_extruder_Y, thermalManager.temp_hotend[0].target);					
		last_temp_hotend_target = thermalManager.temp_hotend[0].target;
	}
#endif
 
 #if HAS_HEATED_BED
	if (last_temp_bed_current != thermalManager.temp_bed.celsius) {
		DWIN_Draw_IntValue_FONT10(COLOR_WHITE, State_text_bed_num, State_text_bed_X, State_text_bed_Y, thermalManager.temp_bed.celsius);
		last_temp_bed_current = thermalManager.temp_bed.celsius;
	}
	if (last_temp_bed_target != thermalManager.temp_bed.target) {
		DWIN_Draw_IntValue_FONT10(COLOR_WHITE, State_text_bed_num, State_text_bed_X + (State_text_bed_num + 1) * STAT_CHR_W, State_text_bed_Y, thermalManager.temp_bed.target);
		last_temp_bed_target = thermalManager.temp_bed.target;
	}
 #endif
 
 	/* printing speed*/
	static int16_t last_speed = 0;
	if (last_speed != feedrate_percentage) {
		DWIN_Draw_IntValue_FONT10(COLOR_WHITE, 3, State_text_speed_X, State_text_speed_Y, feedrate_percentage);
		last_speed = feedrate_percentage;
	}
	
	/*Z postion*/
	DWIN_Show_Z_Position(true);

	/*Mixing*/
	TERN_(MIXING_EXTRUDER, DWIN_Show_Mixing_status());
}

void Popup_Window_Temperature(const char *msg) {
	Clear_Dwin_Area(AREA_TITAL|AREA_POPMENU);
	Draw_Popup_Bkgd_105();
	DWIN_Show_ICON(ICON_TEMPTOOHIGH, 102, 165);		
	dwinLCD.Draw_String(false, true, font8x16, POP_TEXT_COLOR, COLOR_BG_WINDOW, (272 - strlen(msg)*10)/2, 300, (char*)msg);
#if 1
	for(uint8_t i=0; i<20; i++){
		buzzer.tone(200, 2000);
		buzzer.tone(200, 0);
	}
#endif
}


#if ENABLED(OPTION_AUTOPOWEROFF)
inline void Draw_Freedown_Machine(){
	dwinLCD.Draw_Rectangle(1, (DwinMenuID==DWMENU_MAIN)?COLOR_BG_BLACK : COLOR_BG_BLUE, 230, 7, 256, 23);
	if(HMI_flag.free_close_timer_rg >= POWERDOWN_MACHINE_TIMER)
		DWIN_Draw_UnMaskString_Default(230, 7, PSTR("   "));
	else if(HMI_flag.free_close_timer_rg >= 100)
		DWIN_Draw_UnMaskIntValue_Default(3, 230, 7, HMI_flag.free_close_timer_rg);
	else if((HMI_flag.free_close_timer_rg < 100)&&(HMI_flag.free_close_timer_rg >= 10))
		DWIN_Draw_IntValue_Default_Color(COLOR_YELLOW, 3, 230, 7, HMI_flag.free_close_timer_rg);		
	else
		DWIN_Draw_IntValue_Default_Color(COLOR_RED, 3, 230, 7, HMI_flag.free_close_timer_rg);
}

inline void _check_autoshutdown(){
	if((HMI_flag.Autoshutdown_enabled) && (DwinMenuID == DWMENU_POP_STOPPRINT || DwinMenuID == DWMENU_MAIN)){
		//is heating?
		if(thermalManager.temp_hotend[0].target > 50 || thermalManager.temp_bed.target > 25){
			HMI_flag.free_close_timer_rg = POWERDOWN_MACHINE_TIMER;
		}		
		else if(HMI_flag.free_close_timer_rg == 0){
			queue.inject_P(PSTR("M81"));
			HMI_flag.free_close_timer_rg = POWERDOWN_MACHINE_TIMER;
			return;
		}
		else {
			HMI_flag.free_close_timer_rg--;
			if(HMI_flag.free_close_timer_rg < 10) buzzer.tone(50, 5000);
		}
		Draw_Freedown_Machine();
	}
	else 
		HMI_flag.free_close_timer_rg = POWERDOWN_MACHINE_TIMER;	
}

void _reset_shutdown_timer(){
	if(HMI_flag.Autoshutdown_enabled) HMI_flag.free_close_timer_rg = POWERDOWN_MACHINE_TIMER;
}
#endif

void DWIN_HandleScreen() {	
 	switch (DwinMenuID){
		//Main
		case DWMENU_MAIN:    						HMI_MainMenu(); break;
		case DWMENU_FILE:   						HMI_SelectFile(); break;
		case DWMENU_PREPARE:     				HMI_Prepare(); break;
		case DWMENU_CONTROL:     				HMI_Control(); break;
		case DWMENU_INFO:								HMI_Info(); break;

		//print
		case DWMENU_POP_STOPPRINT:  		
		case DWMENU_PRINTING:  					HMI_Printing(); break;
		case DWMENU_TUNE:      					HMI_Tune(); break;
		case DWMENU_TUNE_PRINTSPEED:   	HMI_PrintSpeed(); break;
		case DWMENU_POP_PAUSEORSTOP:		HMI_PauseOrStop(); break;
	#if HAS_HEATED_BED
	  case DWMENU_SET_BTMP:   		 		HMI_BedTemp(); break;
	#endif
	#if HAS_FAN
		case DWMENU_SET_FANSPEED:   		HMI_FanSpeed(); break;
	#endif	
  #if ENABLED(BABYSTEPPING)
	  case DWMENU_SET_ZOFFSET:  			HMI_Zoffset(); break;
	#endif

		//Prepare
		case DWMENU_HOME:    	 					HMI_Home(); break; 		
		case DWMENU_TEMPERATURE:  	 		HMI_Temperature(); break;		
	#if HAS_PREHEAT
		case DWMENU_PREHEAT_PLA:				HMI_PLAPreheatSetting(); break;
		case DWMENU_PREHEAT_ABS:				HMI_ABSPreheatSetting(); break;
	#endif
		case DWMENU_MOVEAXIS:  					HMI_MoveAxis(); break;			
		case DWMENU_MOVEX:     					HMI_Move_X(); break;
	  case DWMENU_MOVEY:     					HMI_Move_Y(); break;
	  case DWMENU_MOVEZ:     					HMI_Move_Z(); break;
#if HAS_HOTEND
		case DWMENU_SET_ETMP: 					HMI_ETemp(); break;
		case DWMENU_MOVE_EXT1:					HMI_Move_Extr(0); break;
	#if(E_STEPPERS > 1)
		case DWMENU_MOVE_EXT2:					HMI_Move_Extr(1); break;
	#endif
	#if(E_STEPPERS > 2)
		case DWMENU_MOVE_EXT3:					HMI_Move_Extr(2); break;
	#endif
	#if(E_STEPPERS > 3)
		case DWMENU_MOVE_EXT4:					HMI_Move_Extr(3); break;
	#endif
	#if ENABLED(MIXING_EXTRUDER)
		case DWMENU_MOVE_EXTALL:				HMI_Move_AllExtr(); break;	
	#endif   
#endif	
		case DWMENU_FILAMENT:  					HMI_Filament();  break;
		case DWMENU_FILAMENT_EXTRUDER:	HMI_Filament_Extuder();  break;
		case DWMENU_FILAMENT_FEEDLENGTH:  		HMI_Filament_FeedLength();  break;
		case DWMENU_FILAMENT_PURGELENGTH:  		HMI_Filament_PurgeLength();  break;
		case DWMENU_POP_LEVEL_CATCH:		HMI_BedLeveling(); break;
		case DWMENU_LEVELING:						HMI_BedLeveling(); break;
		case DWMENU_LEVEL_DONECONFIRM:	HMI_BedLeveling(); break;
		case DWMENU_LEVEL_SETOFFSET:    HMI_SetProbZoffset(); break;		
		case DWMENU_LANGUAGE:						HMI_Language(); break;
		case DWMENU_POWERDOWN:					HMI_Powerdown(); break;		
		
		//Control
		case DWMENU_MIXER:     					HMI_Mixer(); break;
#if ENABLED(MIXING_EXTRUDER)
		case DWMENU_MIXER_MANUAL: 			HMI_Mixer_Manual(); break;
		case DWMENU_MIXER_GRADIENT: 		HMI_Mixer_Gradient(); break;
		case DWMENU_MIXER_RANDOM: 			HMI_Mixer_Random(); break;
		case DWMENU_MIXER_VTOOL:				HMI_Adjust_Mixer_Vtool(); break;
		case DWMENU_MANUALMIXER_VTOOL:	HMI_Adjust_Mixer_Manual_Vtool(); break;
		case DWMENU_MIXER_EXT1: 				HMI_Adjust_Ext_Percent(0); break;
		case DWMENU_MIXER_EXT2: 				HMI_Adjust_Ext_Percent(1); break;
	#if(MIXING_STEPPERS > 2)		
			case DWMENU_MIXER_EXT3: 			HMI_Adjust_Ext_Percent(2); break;
	#endif
	#if(MIXING_STEPPERS > 3)
			case DWMENU_MIXER_EXT4: 			HMI_Adjust_Ext_Percent(3); break;
	#endif
			
		case DWMENU_MIXER_GRADIENT_ZSTART:		HMI_Adjust_Gradient_Zpos_Start(); break;
		case DWMENU_MIXER_GRADIENT_ZEND:			HMI_Adjust_Gradient_Zpos_End(); break;
		case DWMENU_MIXER_GRADIENT_TSTAR: 		HMI_Adjust_Gradient_VTool_Start(); break;
		case DWMENU_MIXER_GRADIENT_TEND:			HMI_Adjust_Gradient_VTool_End(); break;

		case DWMENU_MIXER_RANDOM_ZSTART:			HMI_Adjust_Random_Zpos_Start(); break;
		case DWMENU_MIXER_RANDOM_ZEND:				HMI_Adjust_Random_Zpos_End(); break;
		case DWMENU_MIXER_RANDOM_HEIGHT:			HMI_Adjust_Random_Height(); break;
		case DWMENU_MIXER_RANDOM_EXTN:				HMI_Adjust_Random_Extruders(); break;
#endif
		//Control>>Config
		case DWMENU_CONFIG:							HMI_Config(); break;	
		//Control>>Config>>Retraction
	#if ENABLED(FWRETRACT) 
		case DWMENU_SET_RETRACT:				HMI_Retract(); break;
		case DWMENU_SET_RETRACT_MM:			HMI_Retract_MM(); break;
		case DWMENU_SET_RETRACT_V:			HMI_Retract_V(); break;
		case DWMENU_SET_RETRACT_ZHOP:		HMI_Retract_ZHOP(); break;		
		case DWMENU_SET_UNRETRACT_MM:		HMI_UnRetract_MM(); break;
		case DWMENU_SET_UNRETRACT_V:		HMI_UnRetract_V(); break;
	#endif	

	#if ENABLED(OPTION_BED_COATING)
	  case DWMENU_SET_BEDCOATING:			HMI_Adjust_Coating_Thickness(); break;
	#endif

	#if ENABLED(OPTION_WIFI_BAUDRATE)
		case DWMENU_SET_WIFIBAUDRATE: 		HMI_Adjust_WiFi_BaudRate(); break;
	#endif
	
	#if ENABLED(BLTOUCH)
		case DWMENU_SET_BLTOUCH: 				HMI_Option_Bltouch(); break;
	#endif

	#if ENABLED(OPTION_REPEAT_PRINTING)
		case DWMENU_SET_REPRINT:							HMI_Reprint(); break;
		case DWMENU_SET_REPRINT_TIMES:				HMI_Reprint_Times(); break;
		case DWMENU_SET_REPRINT_RUNLENGTH:		HMI_Forward_Lenght(); break;
	#endif
		//Control>>Motion
		case DWMENU_MOTION:    					HMI_Motion(); break;			
	  case DWMENU_SET_MAXSPEED: 			HMI_MaxSpeed(); break;
	  case DWMENU_SET_MAXACC: 				HMI_MaxAcceleration(); break;
	  case DWMENU_SET_MAXJERK:  			HMI_MaxJerk(); break;
	  case DWMENU_SET_STEPPREMM:			HMI_StepPermm(); break;	  
	  case DWMENU_SET_MAXSPEED_VALUE: HMI_MaxFeedspeedXYZE(); break;
	  case DWMENU_SET_MAXACC_VALUE: 	HMI_MaxAccelerationXYZE(); break;
	  case DWMENU_SET_MAXJERK_VALUE: 	HMI_MaxJerkXYZE(); break;
	  case DWMENU_SET_STEPPREMM_VALUE: HMI_StepXYZE(); break;

		case DWMENU_POP_FROD_OPTION:		HMI_Filament_Runout_Option(); break;
		case DWMENU_POP_FROD_INSERT:		HMI_Filament_Runout_Confirm(); break;
		case DWMENU_POP_FROD_HEAT:			HMI_Filament_Runout_Confirm(); break;

 	#if ENABLED(BABYSTEPPING)
		case DWMENU_TUNE_BABYSTEPS:			HMI_Pop_BabyZstep(); break;
	#endif		
		
		case DWMENU_POP_WAITING:				HMI_Waiting(); break;
  default: break;
	}
}


#if ENABLED(DEBUG_DWIN_LCD)
void DWIN_Show_Status(){
	switch(DWIN_status){
		case ID_SM_START:
			SERIAL_ECHOLNPGM("DWIN_status = ID_SM_START");
		break;
		default:
		case ID_SM_IDEL:
			SERIAL_ECHOLNPGM("DWIN_status = ID_SM_IDEL");
		break;
		case ID_SM_PRINTING:
			SERIAL_ECHOLNPGM("DWIN_status = ID_SM_PRINTING");
		break;
		case ID_SM_PAUSING:
			SERIAL_ECHOLNPGM("DWIN_status = ID_SM_PAUSING");
		break;
		case ID_SM_PAUSED:
			SERIAL_ECHOLNPGM("DWIN_status = ID_SM_PAUSED");
		break;
		case ID_SM_RESUMING:
			SERIAL_ECHOLNPGM("DWIN_status = ID_SM_RESUMING");
		break;
		case ID_SM_STOPED:
			SERIAL_ECHOLNPGM("DWIN_status = ID_SM_STOPED");
		break;			
	}
}
#endif

//
// Watch for media mount / unmount
//
inline void HMI_SDCardUpdate() {
	if (HMI_flag.lcd_sd_status != card.isMounted()) {
		HMI_flag.lcd_sd_status = card.isMounted();
		// SERIAL_ECHOLNPAIR("HMI_SDCardUpdate: ", int(HMI_flag.lcd_sd_status));
		if(HMI_flag.lcd_sd_status) {
			if(DwinMenuID == DWMENU_FILE) { Redraw_SD_List(); dwinLCD.UpdateLCD();}
		}
		else {
		 // clean file icon
		 if(DwinMenuID == DWMENU_FILE) { Redraw_SD_List();	dwinLCD.UpdateLCD();}
		 else if(DwinMenuID == DWMENU_PRINTING || DwinMenuID == DWMENU_TUNE || printingIsActive()) {
		  	/// TODO: Move card removed abort handling
		  	// to CardReader::manage_media.		  	
		  	wait_for_heatup = wait_for_user = false;
				thermalManager.disable_all_heaters();
				card.flag.abort_sd_printing = true;      		// Let the main loop handle SD abort
			}
		}		
	}
}

void HMI_DWIN_Init() {
	Encoder_Configuration();
	
	dwinLCD.JPG_ShowAndCache(0);
	HMI_SDCardInit();

	for (uint16_t t = 0; t <= 100; t += 2) {
		DWIN_Show_ICON(ICON_BAR, 15, 260);
		dwinLCD.Draw_Rectangle(1, COLOR_BG_BLACK, 15 + t * 242 / 100, 260, 257, 280);
		dwinLCD.UpdateLCD();
		delay(20);
	}
	HMI_SetLanguage_PicCache();
	Draw_Main_Menu(true);
}

void EachMomentUpdate() {	
	
	static millis_t next_rts_update_ms = 0;
	const millis_t ms = millis();	
	if (PENDING(ms, next_rts_update_ms)) 	return;
	next_rts_update_ms = ms + DWIN_SCROLL_UPDATE_INTERVAL;
	
	#if ENABLED(DEBUG_DWIN_LCD)
	if(old_DwinMenuID != DwinMenuID || old_DwinStatus != DWIN_status){
		SERIAL_ECHOLNPAIR("DwinMenuID = ", DwinMenuID);
		DWIN_Show_Status();
		old_DwinMenuID = DwinMenuID;
		old_DwinStatus = DWIN_status;
	}
	#endif

	//variable update
	DWIN_Update_Variable();

	//check repeat printing
 	TERN_(OPTION_REPEAT_PRINTING, _check_repeatPrint());
	
	//check auto power off
	TERN_(OPTION_AUTOPOWEROFF, _check_autoshutdown());
	
	//check wifi feedback after turn on WiFi module
	TERN_(OPTION_WIFI_MODULE, _check_wifi_feedback());

	//clean the status bar if need
	_check_clean_status_bar();
	
	if(DWIN_status == ID_SM_START){
		//check resume print when power on
		DWIN_status = ID_SM_IDEL;
		//TERN_(POWER_LOSS_RECOVERY, _check_Powerloss_resume());
	}
	else if(DWIN_status == ID_SM_IDEL){
		TERN_(POWER_LOSS_RECOVERY, _check_Powerloss_resume());
	}
#if ENABLED(POWER_LOSS_RECOVERY)
	else if(DWIN_status == ID_SM_RETURN_MAIN){
		if(!queue.has_commands_queued()){
			DWIN_status = ID_SM_IDEL;
			card.mount();
			Draw_Main_Menu(true);
		}
	}
#endif
	else if(DWIN_status == ID_SM_PRINTING){
		TERN_(POWER_LOSS_RECOVERY,recovery.save(false));
		_Update_printing_Timer();		
		#if ENABLED(BABYSTEPPING)
		if(DwinMenuID == DWMENU_TUNE_BABYSTEPS){
			if(HMI_flag.babyshowtime > 0){
				HMI_flag.babyshowtime--;
				if(HMI_flag.babyshowtime == 0){
					EncoderRate.enabled = false;	
					Draw_Printing_Menu(true);
				}
			} 	
		}
		#endif
	}	
	else if(DWIN_status == ID_SM_RESUMING || DWIN_status == ID_SM_PAUSING){
		_check_kill_times_ElapsedTime();
		#if DISABLED(PARK_HEAD_ON_PAUSE)
		if(HMI_flag.clean_status_delay ==0){			
			if(DWIN_status == ID_SM_RESUMING && printingIsActive() && !runout.filament_ran_out && wait_for_heatup == false){
				DWIN_status = ID_SM_PRINTING;
				Draw_Printing_Menu(true);
			}			
			else if(DWIN_status == ID_SM_PAUSING && printingIsPaused() && !planner.has_blocks_queued() && !runout.filament_ran_out && wait_for_heatup == false){
				DWIN_status = ID_SM_PAUSED;
				Draw_Printing_Menu(true);
			}
		}
		#endif
	}	
	else if(DWIN_status == ID_SM_PAUSED){		
		if(!printingIsPaused()){
				DWIN_status = ID_SM_PRINTING;
				Draw_Printing_Menu(true);
		}
	}
	else if(DWIN_status == ID_SM_STOPED){
		HMI_Value.Percentrecord = 0;
		HMI_Value.remain_time = 0;		
	#if ENABLED(OPTION_REPEAT_PRINTING)
		if(ReprintManager.enabled && (current_position.z >= 20)){
			planner.synchronize();
			Popup_Window_BTempCooldown();
			ReprintManager.Reprint_goon();
		}
		else
	#endif
		{
			TERN_(POWER_LOSS_RECOVERY, recovery.cancel());
			TERN_(OPTION_AUTOPOWEROFF, _setAutoPowerDown());
			TERN_(MIXING_EXTRUDER, mixer.reset_vtools());
			HMI_Value.print_speed = feedrate_percentage = 100;
			DWIN_status = ID_SM_IDEL;
			Draw_Main_Menu();			
		}
	}		
	dwinLCD.UpdateLCD();
  TERN_(USE_WATCHDOG, HAL_watchdog_refresh());
}

void DWIN_Update() {
#if ENABLED(DWIN_AUTO_TEST)
	if(HMI_flag.auto_test_flag == 0xaa){
		if(autotest.DWIN_AutoTesting()){
			HMI_flag.auto_test_flag = 0x55;
			Draw_Main_Menu(true);
		}
	}
	else
#endif		
	{				
		EachMomentUpdate();  // Status update		
		DWIN_HandleScreen(); // Rotary encoder update
		HMI_SDCardUpdate();	 // SD card update
	}
}
#endif // HAS_DWIN_LCD
