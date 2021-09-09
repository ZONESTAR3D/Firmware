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

#if HAS_DWIN_LCD

#define LANG_NUMBER  							5

//Big ICON
typedef enum{
	ICON_BIG_PRINT = 0,
	ICON_BIG_PREPARE,
	ICON_BIG_CONTROL,
	ICON_BIG_INFO,
	ICON_BIG_TUNE,
	ICON_BIG_PAUSE,
	ICON_BIG_CONTINUE,
	ICON_BIG_STOP,	
	ICON_BIG_NUMBER
}_emPicture_Item;

// ICON ID
typedef enum{
	ICON_LOGO = 0,
	ICON_PRINT,
	ICON_PRINT_SEL,
	ICON_PREPARE,
	ICON_PREPARE_SEL,
	ICON_CONTROL,
	ICON_CONTROL_SEL,
	ICON_LEVELING,
	ICON_LEVELING_SEL,
	ICON_HOTENDTEMP,
	ICON_BEDTEMP = 10,
	ICON_SPEED,  
	ICON_ZOFFSET,
	ICON_BACK,
	ICON_FILE,
	ICON_PRINTTIME,
	ICON_REMAINTIME,
	ICON_SETUP,
	ICON_SETUP_SEL,
	ICON_PAUSE,
	ICON_PAUSE_SEL = 20,
	ICON_CONTINUE,
	ICON_CONTINUE_SEL,
	ICON_STOP, 
	ICON_STOP_SEL, 
	ICON_BAR, 
	ICON_MORE = 26,
	ICON_FOLDER = ICON_MORE,
	ICON_AXIS,
	ICON_CLOSEMOTOR,
	ICON_HOMING, 
	ICON_SETHOME = 30,
	ICON_PLAPREHEAT,
	ICON_ABSPREHEAT,
	ICON_COOL,
	ICON_LANGUAGE, 
	ICON_MOVEX,  
	ICON_MOVEY,  
	ICON_MOVEZ,  
	ICON_EXTRUDER, 
	ICON_TEMPERATURE,
	ICON_MOTION = 40,
	ICON_MIXER,  
	ICON_BLTOUCH,
	ICON_WRITEEEPROM,
	ICON_READEEPROM,
	ICON_RESUMEEEPROM, 
	ICON_INFO,
	ICON_SETENDTEMP,
	ICON_SETBEDTEMP,
	ICON_FANSPEED, 
	ICON_SETPLAPREHEAT = 50,
	ICON_SETABSPREHEAT,
	ICON_MAXSPEED, 
	ICON_MAXACCELERATED,
	ICON_MAXJERK,
	ICON_STEP,
	ICON_PRINTSIZE,
	ICON_VERSION,
	ICON_CONTACT,
	ICON_STOCKCONFIGURATON,    
	ICON_MAXSPEEDX = 60,
	ICON_MAXSPEEDY,
	ICON_MAXSPEEDZ,
	ICON_MAXSPEEDE,
	ICON_MAXACCX,
	ICON_MAXACCY,
	ICON_MAXACCZ,
	ICON_MAXACCE,
	ICON_MAXSPEEDJERKX,
	ICON_MAXSPEEDJERKY,
	ICON_MAXSPEEDJERKZ = 70,
	ICON_MAXSPEEDJERKE,
	ICON_STEPX,  
	ICON_STEPY,  
	ICON_STEPZ,  
	ICON_STEPE,  
	ICON_SETSPEED, 
	ICON_SETZOFFSET,
	ICON_RECTANGLE,
	ICON_TEMPTOOLOW,
	ICON_AUTOLEVELING = 80,
	ICON_TEMPTOOHIGH,
	ICON_NOTIPS_C, 
	ICON_NOTIPS_E, 
	ICON_CONTINUE_C,
	ICON_CONTINUE_E,
	ICON_CANCEL_C, 
	ICON_CANCEL_E, 
	ICON_CONFIRM_C,
	ICON_CONFIRM_E,
	ICON_BIGINFO = 90,
	ICON_BIGINFO_SEL, 
	ICON_MIXER_MANUAL, 
	ICON_MIXER_GRADIENT,
	ICON_MIXER_RANDOM, 
	ICON_EXTRUDER1,
	ICON_EXTRUDER2,
	ICON_EXTRUDER3,
	ICON_EXTRUDER4,
	ICON_C_VTOOL,
	ICON_S_VTOOL = 100,
	ICON_EXTRUDER1_P,
	ICON_EXTRUDER2_P,
	ICON_EXTRUDER3_P,
	ICON_EXTRUDER4_P,
	ICON_VTOOL_P,
	ICON_VTOOL_DROP,
	ICON_VTOOL_RISE,
	ICON_ZPOS_DROP,
	ICON_ZPOS_RISE,
	ICON_LEVELING0 = 110,
	ICON_LEVELING_POINT1,      
	ICON_LEVELING_POINT2,      
	ICON_LEVELING_POINT3,      
	ICON_LEVELING_POINT4,     
	ICON_LEVELING_AUTO,
	ICON_LEVELING_SAVE,
	ICON_BLANK,
	ICON_CURSOR,
	ICON_HOME_ALL,	
	ICON_HOME_X = 120,
	ICON_HOME_Y,
	ICON_HOME_Z,
	ICON_WAITING,
	ICON_YES_SEL,  	
	ICON_YES_UNSEL,  	
	ICON_NO_SEL,  		
	ICON_NO_UNSEL,  		
	ICON_BLTOUCH_RESET,
	ICON_BLTOUCH_TEST, 
	ICON_BLTOUCH_STOW = 130,
	ICON_BLTOUCH_DEPLOY,       
	ICON_BLTOUCH_SW,
	ICON_POWER_DOWN,
	ICON_POWERDOWN,
	ICON_REMAIN_TIME,
	ICON_PRINT_TIME,
		
	ICON_EN=140,
	ICON_SP,
	ICON_RU,
	ICON_FR,
	ICON_PT,
	ICON_CH,
	ICON_WIFI,
	
	ICON_PRINT_EN=150,
	ICON_PREPARE_EN,
	ICON_CONTROL_EN,
	ICON_STARTINFO_EN, 
	ICON_TUNE_EN,
	ICON_PAUSE_EN,
	ICON_STOP_EN,
	ICON_CONTINUE_EN=ICON_PRINT_EN,
	
	ICON_PRINT_SP=160,
	ICON_PREPARE_SP,
	ICON_CONTROL_SP,
	ICON_STARTINFO_SP, 
	ICON_TUNE_SP,
	ICON_PAUSE_SP,
	ICON_STOP_SP,
	ICON_CONTINUE_SP=ICON_PRINT_SP,
	
	ICON_PRINT_RU=170,
	ICON_PREPARE_RU,
	ICON_CONTROL_RU,
	ICON_STARTINFO_RU, 
	ICON_TUNE_RU,
	ICON_PAUSE_RU,
	ICON_STOP_RU,
	ICON_CONTINUE_RU=ICON_PRINT_RU,
	
	ICON_PRINT_FR=180,
	ICON_PREPARE_FR,
	ICON_CONTROL_FR,
	ICON_STARTINFO_FR, 
	ICON_TUNE_FR,
	ICON_PAUSE_FR,
	ICON_STOP_FR,
	ICON_CONTINUE_FR=ICON_PRINT_FR,
	
	ICON_PRINT_PT=190,
	ICON_PREPARE_PT,
	ICON_CONTROL_PT,
	ICON_STARTINFO_PT,
	ICON_TUNE_PT,
	ICON_PAUSE_PT,
	ICON_STOP_PT,
	ICON_CONTINUE_PT=ICON_PRINT_PT
}_emICON_Item;


constexpr uint16_t PRINT_X_COORDINATE[]				PROGMEM	= {53,36,44,35,30};
constexpr uint16_t PREPARE_X_COORDINATE[]			PROGMEM = {172,165,150,168,164};
constexpr uint16_t CONTROL_X_COORDINATE[] 		PROGMEM	= {44,44,27,37,36};
constexpr uint16_t INFO_X_COORDINATE[]				PROGMEM	= {184,184,160,182,185};
constexpr uint16_t TUNE_X_COORDINATE[] 				PROGMEM	= {32,19,25,23,24};
constexpr uint16_t PAUSE_X_COORDINATE[] 			PROGMEM	= {116,104,114,116,110};
constexpr uint16_t CONTINUE_X_COORDINATE[] 		PROGMEM	= {117,101,107,107,105};
constexpr uint16_t STOP_X_COORDINATE[] 				PROGMEM	= {208,189,204,208,196};
constexpr uint16_t FILE_X_COORDINATE[]				PROGMEM	= {49,81,62,79,87};
constexpr uint16_t HOME_X_COORDINATE[] 				PROGMEM	= {52,59,62,59,65};
constexpr uint16_t POINT_X_COORDINATE[] 			PROGMEM	= {47,51,54,43,54};
constexpr uint16_t CATCH_X_COORDINATE[] 			PROGMEM	= {48,67,69,73,76};
constexpr uint16_t BED_X_COORDINATE[] 				PROGMEM	= {33,49,52,21,40};
constexpr uint16_t AUTO_X_COORDINATE[] 				PROGMEM	= {43,49,52,21,40};
constexpr uint16_t MAX_X_COORDINATE[] 				PROGMEM	= {38,38,38,38,38};
constexpr uint16_t FEEDRATE_X_COORDINATE[] 		PROGMEM	= {73,59,78,59,87};
constexpr uint16_t ACCEL_X_COORDINATE[] 			PROGMEM	= {46,70,95,97,91};
constexpr uint16_t JERK_X_COORDINATE[] 				PROGMEM	= {39,38,62,34,55};
constexpr uint16_t STEP_X_COORDINATE[] 				PROGMEM	= {79,90,114,65,89};
constexpr uint16_t EXTRUDER_X_COORDINATE[] 		PROGMEM	= {72,93,105,79,68};
constexpr uint16_t COMMIT_X_COORDINATE[] 			PROGMEM	= {54,63,96,113,52};
constexpr uint16_t START_X_COORDINATE[] 			PROGMEM	= {44,52,65,50,52};
constexpr uint16_t END_X_COORDINATE[] 				PROGMEM	= {32,93,100,24,33};
constexpr uint16_t CURRENT_X_COORDINATE[] 		PROGMEM	= {65,74,78,95,46};
constexpr uint16_t HOTEND_X_COORDINATE[] 			PROGMEM	= {64,48,56,41,38};
constexpr uint16_t PROBE_X_COORDINATE[] 			PROGMEM	= {52,43,114,61,53};
constexpr uint16_t MOVE_X_COORDINATE[] 				PROGMEM	= {49,55,93,71,55};
constexpr uint16_t PREHEAT_X_COORDINATE[] 		PROGMEM	= {66,66,66,50,100};
constexpr uint16_t STORE_X_COORDINATE[] 			PROGMEM	= {51,70,74,68,92};
constexpr uint16_t LOAD_X_COORDINATE[] 				PROGMEM	= {44,59,76,59,51};

#define	GET_ICON_X(N) pgm_read_word(&N##_X_COORDINATE[HMI_flag.language])

constexpr uint8_t PICTURE_INDEX[LANG_NUMBER][ICON_BIG_NUMBER] PROGMEM={
	{ICON_PRINT_EN,ICON_PREPARE_EN,ICON_CONTROL_EN,ICON_STARTINFO_EN,ICON_TUNE_EN,ICON_PAUSE_EN,ICON_CONTINUE_EN,ICON_STOP_EN},
	{ICON_PRINT_SP,ICON_PREPARE_SP,ICON_CONTROL_SP,ICON_STARTINFO_SP,ICON_TUNE_SP,ICON_PAUSE_SP,ICON_CONTINUE_SP,ICON_STOP_SP},
	{ICON_PRINT_RU,ICON_PREPARE_RU,ICON_CONTROL_RU,ICON_STARTINFO_RU,ICON_TUNE_RU,ICON_PAUSE_RU,ICON_CONTINUE_RU,ICON_STOP_RU},
	{ICON_PRINT_FR,ICON_PREPARE_FR,ICON_CONTROL_FR,ICON_STARTINFO_FR,ICON_TUNE_FR,ICON_PAUSE_FR,ICON_CONTINUE_FR,ICON_STOP_FR},
	{ICON_PRINT_PT,ICON_PREPARE_PT,ICON_CONTROL_PT,ICON_STARTINFO_PT,ICON_TUNE_PT,ICON_PAUSE_PT,ICON_CONTINUE_PT,ICON_STOP_PT},
};

#define	GET_PIC_ID(n) pgm_read_byte(&PICTURE_INDEX[HMI_flag.language][n])


//Multi-language strings
enum{
	MTSTRING_TITLE_MAIN,
	MTSTRING_TITLE_PREPARE,
	MTSTRING_TITLE_CONTROL,
	MTSTRING_TITLE_INFO,
	MTSTRING_TITLE_MOVE,
	MTSTRING_TITLE_HOME,
	MTSTRING_TITLE_LEVELING,
 	MTSTRING_TITLE_TEMPERATURE,
 	MTSTRING_TITLE_MOTION,
 	MTSTRING_TITLE_MIXER,
 	MTSTRING_TITLE_BLTOUCH,
 	MTSTRING_TITLE_PLA,
 	MTSTRING_TITLE_ABS,
 	MTSTRING_TITLE_FEEDRATE,
 	MTSTRING_TITLE_ACCEL,
 	MTSTRING_TITLE_JERK,
 	MTSTRING_TITLE_STEP,
 	MTSTRING_TITLE_MIX,
 	MTSTRING_TITLE_GRADIENT,
 	MTSTRING_TITLE_RANDOM,
 	MTSTRING_TITLE_SDPRINT,
 	MTSTRING_TITLE_FILE,
 	MTSTRING_TITLE_PRINTING,
 	MTSTRING_TITLE_TUNE,
 	MTSTRING_TITLE_LANGUAGE,

  MTSTRING_LANGUAGE_EN,
  MTSTRING_LANGUAGE_SP,
  MTSTRING_LANGUAGE_RU,
  MTSTRING_LANGUAGE_FR,
  MTSTRING_LANGUAGE_PT,
  MTSTRING_LANGUAGE_ZH,
	
  MTSTRING_MAIN_PRINT,
  MTSTRING_MAIN_PREPARE,
  MTSTRING_MAIN_CONTROL,
  MTSTRING_MAIN_INFO,

  MTSTRING_MENU_BACK,

  MTSTRING_MOVE,
  MTSTRING_DISABLE_STEPPERS,
  MTSTRING_AUTO_HOME,
  MTSTRING_BED,
  MTSTRING_LEVELING,
  MTSTRING_POWER_OUTAGE,
  MTSTRING_POWER_OFF,
  MTSTRING_Z_OFFSET,
  MTSTRING_PREHEAT,
  MTSTRING_PLA,
  MTSTRING_ABS,
  MTSTRING_COOLDOWN,
  MTSTRING_LANGUAGE,

  MTSTRING_TEMPERATURE,
  MTSTRING_MOTION,
  MTSTRING_MIXER,
  MTSTRING_CONFIG,
  MTSTRING_BLTOUCH,
  MTSTRING_STORE,
  MTSTRING_LOAD,
  MTSTRING_RESET,
  MTSTRING_INFO,

  MOVE_MENU_MOVE,
  MTSTRING_X,
  MTSTRING_Y,
  MTSTRING_Z,
  MTSTRING_EXTRUDER,
  MTSTRING_1,
  MTSTRING_2,
  MTSTRING_3,
  MTSTRING_4,

  MTSTRING_HOME,
  MTSTRING_ALL,

  LEVELING_MENU_POINT,
  LEVELING_MENU_1,
  LEVELING_MENU_2,
  LEVELING_MENU_3,
  LEVELING_MENU_4,
  LEVELING_MENU_CATCH,
  LEVELING_MENU_Z_OFFSET,
  //LEVELING_MENU_BED,
  LEVELING_MENU_AUTO,
  LEVELING_MENU_LEVEL,

  TEMP_MENU_TEMP,
  TEMP_MENU_HOTEND,
  TEMP_MENU_BED,
  TEMP_MENU_FAN_SPEED,
  TEMP_MENU_PLA,
  TEMP_MENU_ABS,
  TEMP_MENU_PREHEAT,

  MOTION_MENU_FEEDRATE,
  MOTION_MENU_ACC,
  MOTION_MENU_JERK,
  MOTION_MENU_STEPS,

  MIXER_MENU_MIX,
  MIXER_MENU_GRADIENT,
  MIXER_MENU_RANDOM,
  MIXER_MENU_CURRENT,
  MIXER_MENU_VTOOL,

  BLTOUCH_MENU_RESET,
  BLTOUCH_MENU_TEST,
  BLTOUCH_MENU_STOW,
  BLTOUCH_MENU_DEPLOY,
  BLTOUCH_MENU_MODE,

  PLA_ABS_MENU_NOZZLE,
  PLA_ABS_MENU_TEMP,
  PLA_ABS_MENU_BED,
  PLA_ABS_MENU_FAN_SPEED,
  PLA_ABS_MENU_SETTINGS,
  PLA_ABS_MENU_STORE,

  FEEDRATE_MENU_MAX,
  FEEDRATE_MENU_FEEDRATE,
  FEEDRATE_MENU_X,
  FEEDRATE_MENU_Y,
  FEEDRATE_MENU_Z,
  FEEDRATE_MENU_E,

  ACCEL_MENU_MAX,
  ACCEL_MENU_ACCEL,
  ACCEL_MENU_X,
  ACCEL_MENU_Y,
  ACCEL_MENU_Z,
  ACCEL_MENU_E,

  JERK_MENU_MAX,
  JERK_MENU_JERK,
  JERK_MENU_X,
  JERK_MENU_Y,
  JERK_MENU_Z,
  JERK_MENU_E,

  STEP_MENU_MAX,
  STEP_MENU_STEP,
  STEP_MENU_X,
  STEP_MENU_Y,
  STEP_MENU_Z,
  STEP_MENU_E,

  MIX_MENU_EXTRUDER,
  MIX_MENU_1,
  MIX_MENU_2,
  MIX_MENU_3,
  MIX_MENU_4,
  MIX_MENU_COMIT,
  MIX_MENU_VTOOL,

  GRADIENT_MENU_START,
  GRADIENT_MENU_END,
  GRADIENT_MENU_Z,
  GRADIENT_MENU_VTOOL,

  RANDOM_MENU_START,
  RANDOM_MENU_END,
  RANDOM_MENU_Z,

  PRINTING_MENU_TUNE,
  PRINTING_MENU_PAUSE,
  PRINTING_MENU_CONTINUE,
  PRINTING_MENU_STOP,

  TUNE_MENU_SPEED,
  TUNE_MENU_TEMP,
  TUNE_MENU_HOTEND,
  TUNE_MENU_BED,
  TUNE_MENU_FAN_SPEED,
  TUNE_MENU_PROBE,
  TUNE_MENU_Z_OFFSET,
  TUNE_MENU_MIXER,
  TUNE_MENU_CONFIG,
  MTSTRING_NUMBER
};

//Coordinate of Multi-language strings
constexpr uint16_t MULTILANGSTR_COORDINATE[LANG_NUMBER][MTSTRING_NUMBER][4] PROGMEM={
	//EN
	{	
		{1,  391,39, 404},										//main
		{41, 391,102,408},										//prepare
		{103,391,164,404},										//control
		{166,391,196,404},										//startinfo
		{198,391,241,404},										//move
		{1,  410,48, 423},										//home
		{50, 409,115,426},										//leveling 
		{117,410,219,426},										//temperture
	  {1,  427,59, 441},										//motion					
		{221,410,266,423},										//mixer
		{61, 428,128,441},										//bltouch
		{130,428,160,441},										//pla
		{161,428,194,441},										//abs
		{195,428,263,441},										//feedrate
		{1,  443,99, 456},										//accel 
		{100,442,134,456},										//jerk
	  {135,443,210,458},										//step					
		{212,443,241,456},										//mix
		{1,  461,69, 475},										//gradient
		{71, 461,137,475},										//random
		{139,461,177,479},										//print 
		{204,461,228,474},										//file
		{139,461,203,479},										//printing
		{229,461,267,475},										//tune 
		{87, 375,164,391},										//language
	  //language
	  {3,  262,59, 278},										//en
		{61, 262,122,278},										//sp 
		{124,262,183,274},										//ru
		{185,262,236,274},										//fr
		{2,  282,93, 297},										//po 
		{95, 281,155,293},										//zh
		//main
	  {2,  1,  42,  15},										//print0			
		{68, 1,  130, 19},										//prepare0
		{131,1,  192, 15},										//control0
		{193,1,  224, 15},										//info0
	  //back
		{2,  231,40, 245},										//back
	    //prepare
		{3,  22, 47,  35},										//move			
		{48, 22, 184, 38},										//disable steppers
		{108,40, 200, 53},										//auto home
		{2,  75, 30,  93},										//bed
		{38, 75, 104, 93},										//leveling
		//{105,77, 219, 94},									//power outage
		{105,77, 156, 94},										//power outage
		{204,57, 229, 71},										//power oFF
		{187,59, 254, 72},										//z-offset
		{1,  95, 62, 109},										//preheat 
		{62, 95, 93, 109},										//PLA
		{94, 95, 126,109},										//ABS
		{86, 111,169,125},										//cooldown
		{171,112,248,128},										//language
	    //control
		{3,  40, 106, 56},										//temperature			
		{185,21, 243, 35},										//motion
		{202,39, 248, 52},										//mixer
		{160,281,239,299},										//config
		{119,59, 186, 72},										//bltouch
		{2,  59, 47,  72},										//store
		{42, 232,81, 244},										//load
		{82, 232,214,244},										//restore
		{193,2,  224, 15},										//info
	    //move axis
		{3,  22, 47,  35},										//move			
		{226,3,  235, 15},										//x
		{236,3,  245, 15},										//y
		{247,3,  255, 15},										//z
		{2,  131,69, 143},										//extruder
		{215,187,221,199},										//1
		{230,187,237,199},										//2
		{245,187,252,199},										//3
		{259,187,269,199},										//4
	    //home
		{154,40, 201, 52},										//home			
		{245,22, 265, 34},										//all
		//leveling	
		{217,130,259,144},										//point
		{215,187,221,199},										//1
		{230,187,237,199},										//2
		{245,187,252,199},										//3
		{259,187,269,199},										//4
		{2,  146,45, 160},										//Catch
		{188,58, 253, 71},										//Z OFFSET
		//{2,  75, 30,  93},									//bed
		{108,39, 146, 56},										//auto
		{38, 75, 104, 93},										//leveling
	    //temperature
		{46, 147,92, 164},										//temp
		{94, 147,153,160},										//hotend
		{3,  76, 31,  89},										//bed
		{155,147,235,163},										//Fan speed
		{62, 95, 93, 109},										//PLA 
		{94, 95, 126,109},										//ABS 
		{1,  95, 62, 109},										//preheat
	    //motion
		{147,130,215,143},										//feedrate
		{78, 167,177,179},										//acceleration
		{237,96, 271,109},										//jerk
		{2,  167,77, 183},										//steps/mm 
		//mixer
		{222,76, 251, 89},										//mix
		{179,166,248,179},										//gradient 
		{3,  185,68, 198},										//random 
		{2,  217,61, 228},										//current  
		{67, 217,128,228},										//vtool 
		//bltouch
		{71, 186,113,198},										//reset
		{85, 201,155,215},										//self-test
		{114,186,155,198},										//stow 
		{157,186,213,201},										//deploy
	    {2,  202,82, 215},										//sw-mode
		//PLA&ABS settings
		{217,232,270,246},										//nozzle
		{46, 147,92, 164},										//temp
		{3,  76, 31,  89},										//bed 
		{155,147,235,163},										//fan speed 
		{51, 59, 118, 74},										//settings
		{2,  59, 47,  72},										//store
		//MAX feedrate 
		{70, 131,103,143},										//max
		{147,130,215,143},										//feedrate
		{226,3,  235, 15},										//x
		{236,3,  245, 15},										//y
		{247,3,  255, 15},										//z
		{258,3,  265, 15},										//e
		//MAX acceleration 
		{70, 131,103,143},										//max
		{79, 166,118,179},										//acceleration
		{226,3,  235, 15},										//x
		{236,3,  245, 15},										//y
		{247,3,  255, 15},										//z
		{258,3,  265, 15},										//e
		//MAX jerk 
		{70, 131,103,143},										//max
		{237,96, 271,109},										//jerk
		{226,3,  235, 15},										//x
		{236,3,  245, 15},										//y
		{247,3,  255, 15},										//z
		{258,3,  265, 15},										//e
		//MAX step 
		{70, 131,103,143},										//max
		{2,  167,77, 183},										//step
		{226,3,  235, 15},										//x
		{236,3,  245, 15},										//y
		{247,3,  255, 15},										//z
		{258,3,  265, 15},										//e
		//Mix 
		{2,  131,69, 143},										//extruder
		{215,187,221,199},										//1
		{230,187,237,199},										//2
		{245,187,252,199},										//3
		{259,187,269,199},										//4
		{131,216,179,230},										//comit
		{185,216,237,230},										//vtool
		//gradient 
		{167, 96,206,108},										//start
		{208, 96,235,108},										//end
		{247,3,  255, 15},										//z
		{186,218,237,230},										//vtool
		//random 
		{167, 97,206,108},										//start
		{208, 97,235,108},										//end
		{247,3,  255, 15},										//z
		//printing tune pause continue stop 
		{127, 95,166,108},										//tune
		{1,  111,47, 124},										//pause
		{2,  1,  42,  15},										//continue(print)
		{47, 111,85, 128},										//stop
		//tune
		{187,146,236,163},										//speed
		{46, 147,92, 164},										//temp
		{94, 147,153,160},										//hotend
		{3,  76, 31,  89},										//bed
		{155,147,235,163},										//fan speed
		{76, 246,123,259},										//probe
		{188,58, 253, 71},										//z-offset
		{202,39, 248, 52},										//mixer
		{160,281,239,299},										//config
	},
	//ES	
	{
		{3,  266,68, 279},										//main					
		{73, 282,141,297},										//prepare
		{142,281,203,294},										//control
		{206,281,236,294},										//startinfo
		{186,250,237,262},										//move
		{1,  299,55, 315},										//home
		{57, 299,138,311},										//leveling 
		{139,300,242,315},										//temperture
	    {2,  317,99, 330},										//motion					
		{142,266,230,278},										//mixer
		{101,317,168,330},										//bltouch
		{170,317,200,330},										//pla
		{201,317,234,330},										//abs
		{129,248,184,264},										//feedrate
		{1,  332,66, 343},										//accel 
		{67, 332,100,343},										//jerk
	    {102,332,187,345},										//step					
		{189,332,250,343},										//mix
		{1,  347,90, 363},										//gradient
		{92, 348,130,359},										//random
		{133,347,203,363},										//print 
		{2,  248,127,260},										//file
		{133,347,203,363},										//printing
		{204,347,262,363},										//tune 
		{2,  234,66, 247},										//language
		//language
	    {3,  331,49, 347},										//en
		{51, 332,111,347},										//sp 
		{114,332,152,343},										//ru
		{154,331,212,343},										//fr
		{85, 313,167,329},										//po 
		{169,313,211,325},										//zh
		//main
	    {0,  0,  72,  18},										//print0			
		{73, 1,  142, 18},										//prepare0
		{142,0,  203, 14},										//caontrol0
		{204,0,  235, 14},										//info0
	    //back
		{182,190,224,203},										//back
	    //prepare
		{1,  20, 51,  32},										//move			
		{52, 20, 184, 35},										//disable steppers
		{204,37, 258, 53},										//home
		{203,156,247,167},										//bed
		{1,  90, 82, 103},										//leveling
		{173,90, 236,106},										//power outage
		{173,90, 236,106},										//power outage
		{100,74, 165, 87},										//z-offset
		{1,  108,53, 121},										//preheat 
		{55, 108,85, 121},										//PLA
		{86, 108,118,121},										//ABS
		{74, 141,126,154},										//cooldown
		{127,141,191,154},										//language
	    //control
		{99, 38, 202, 53},										//temperature			
		{1,  37, 98,  50},										//motion
		{84, 90, 171,102},										//mixer
		{84, 90, 171,102},										//config
		{3,  350,117,367},										//bltouch
		{1,  55, 64,  68},										//store
		{124,56, 177, 72},										//load
		{1,  74, 98,  87},										//restore
		{205,1,  235, 14},										//info
	    //move axis
		{1,  20, 51,  32},										//move			
		{237,2,  246, 14},										//x
		{248,2,  256, 14},										//y
		{259,2,  267, 14},										//z
		{68, 156,151,168},										//extruder
		{215,75, 220, 87},										//1
		{225,75, 232, 87},										//2
		{234,75, 242, 87},										//3
		{244,75, 253, 87},										//4
	    //home
		{204,37, 258, 54},										//home			
		{185,20, 226, 32},										//all
		//leveling	
		{153,156,200,168},										//point
		{215,75, 220, 87},										//1
		{225,75, 232, 87},										//2
		{234,75, 242, 87},										//3
		{244,75, 253, 87},										//4
		{1,  172,62, 187},										//Catch
		{100,74, 165, 87},										//Z OFFSET
		//{203,156,247,167},										//bed
		{203,156,247,167},										//auto
		{1,  90, 82, 103},										//leveling
	    //temperature
		{63, 171,108,187},										//temp
		{110,171,153,183},										//hotend
		{203,156,247,167},										//bed
		{155,171,239,182},										//Fan speed
		{55, 108,85, 121},										//PLA
		{86, 108,118,121},										//ABS
		{1,  108,53, 121},										//preheat
	    //motion
		{143,259,197,275},										//feedrate
		{2,  156,67, 167},										//acceleration
		{63, 124,95, 136},										//jerk
		{2,  191,86, 203},										//steps/mm 
		//mixer
		{2,  124,60, 136},										//mix
		{90, 191,179,207},										//gradient 
		{1,  274,76, 287},										//random 
		{167,227,235,239},										//current
		{66, 243,118,255},										//vtool 
		//bltouch
		{1,  209,91, 221},										//reset
		{167,279,268,291},										//self-test
		{94, 210,153,224},										//stow 
		{157,208,245,225},										//deploy
	    {80, 278,162,291},										//sw-mode
		//PLA&ABS settings
		{214,243,269,256},										//nozzle
		{63, 171,108,187},										//temp
		{203,156,247,167},										//bed 
		{155,171,239,182},										//fan speed 
		{66, 55, 123, 71},										//settings
		{1,  55, 64,  68},										//store
		//MAX feedrate 
		{193,142,225,154},										//max
		{143,259,197,275},										//feedrate
		{237,2,  246, 14},										//x
		{248,2,  256, 14},										//y
		{259,2,  267, 14},										//z
		{260,38, 267, 50},										//e
		//MAX acceleration 
		{193,142,225,154},										//max
		{2,  156,67, 167},										//acceleration
		{237,2,  246, 14},										//x
		{248,2,  256, 14},										//y
		{259,2,  267, 14},										//z
		{260,38, 267, 50},										//e
		//MAX jerk 
		{193,142,225,154},										//max
		{63, 124,95, 136},										//jerk
		{237,2,  246, 14},										//x
		{248,2,  256, 14},										//y
		{259,2,  267, 14},										//z
		{260,38, 267, 50},										//e
		//MAX step 
		{193,142,225,154},										//max
		{2,  191,86, 203},										//step
		{237,2,  246, 14},										//x
		{248,2,  256, 14},										//y
		{259,2,  267, 14},										//z
		{260,38, 267, 50},										//e
		//Mix 
		{68, 156,151,168},										//extruder
		{215,75, 220, 87},										//1
		{225,75, 232, 87},										//2
		{234,75, 242, 87},										//3
		{244,75, 253, 87},										//4
		{1,  243,60, 256},										//comit
		{66, 243,118,255},										//vtool
		//gradient 
		{120,108,168,121},										//start
		{169,109,257,121},										//end
		{259,2,  267, 14},										//z
		{66, 243,118,255},										//vtool
		//random 
		{120,108,168,121},										//start
		{169,109,257,121},										//end
		{259,2,  267, 14},										//z
		//printing tune pause continue stop 
		{2,  294,60, 311},										//tune
		{61, 294,126,308},										//pause
		{0,  0,  72,  18},										//continue(print)
		{128,294,199,308},										//stop
		//tune
		{2,  313,81, 326},										//speed
		{63, 171,108,187},										//temp
		{110,171,153,183},										//hotend
		{203,156,247,167},										//bed
		{155,171,239,182},										//fan speed
		{174,243,212,256},										//probe
		{100,74, 165, 87},										//z-offset
		{84, 90, 171,102},										//mixer
		{84, 90, 171,102},										//config
	},
	//RU
	{
		{1,  210,62, 222},										//main					
		{123,211,232,225},										//prepare
		{2,  193,92, 209},										//control
		{93, 193,174,208},										//startinfo
		{175,193,263,207},										//move
		{2,  159,60, 173},										//home
		{2,  176,128,191},										//leveling 
		{61, 159,169,174},										//temperture
	    {172,159,260,174},										//motion					
		{131,176,220,187},										//mixer
		{2,  140,66, 152},										//bltouch
		{68, 141,98, 153},										//pla
		{100,141,132,153},										//abs
		{133,141,212,157},										//feedrate
		{2,  124,92, 137},										//accel 
		{214,142,269,153},										//jerk
	    {93, 123,202,138},										//step					
		{2,  106,96, 117},										//mix
		{99, 106,176,121},										//gradient
		{1,  88, 108,103},										//random
		{64, 211,121,222},										//print 
		{110,88, 233,103},										//file
		{64, 211,121,222},										//printing
		{2,  72, 89,  86},										//tune 
		{96, 74, 138, 82},										//language
		//language
	    {2,  316,99, 327},										//en
		{106,316,194,327},										//sp 
		{202,316,268,332},										//ru
		{1,  334,112,351},										//fr
		{119,335,244,351},										//po 
		{142,298,228,310},										//zh
		//main
	    {1,  0,  59,  13},										//print0			
		{61, 0,  160, 16},										//prepare0
		{171,0,  262, 16},										//caontrol0
		{0,  17, 82,  32},										//info0
	    //back
		{145,263,194,277},										//back
	    //prepare
		{84, 19, 170, 32},										//move			
		{2,  35, 99,  46},										//disable steppers
		{111,51, 169, 65},										//home
		{69, 87, 116, 98},										//bed
		{118,85, 243,101},										//leveling
		{2,  102,107,115},										//power outage
		{2,  102,107,115},										//power outage
		{2,  86, 67,  98},										//z-offset
		{207,103,264,117},										//preheat 
		{212,353,242,365},										//PLA
		{231,353,263,365},										//ABS
		{1,  157,73, 170},										//cooldown
		{186,122,227,130},										//language
	    //control
		{2,  50, 110, 65},										//temperature			
		{172,19, 259, 32},										//motion
		{171,51, 258, 61},										//mixer
		{3,  367,90, 384},										//config
		{166,68, 230, 79},										//bltouch
		{2,  66, 70,  79},										//store
		{195,263,266,278},										//load
		{2,  283,93, 296},										//restore
		{1,  18, 81,  32},										//info
	    //move axis
		{84, 19, 170, 32},										//move			
		{189,33, 199, 46},										//x
		{200,33, 209, 46},										//y
		{210,33, 219, 46},										//z
		{108,136,208,152},										//extruder
		{232,67, 237, 79},										//1
		{242,67, 249, 79},										//2
		{252,67, 258, 79},										//3
		{261,67, 270, 79},										//4
	    //home
		{112,51, 169, 65},										//home			
		{230,35, 258, 45},										//all
		//leveling	
		{212,137,261,148},										//point
		{232,67, 237, 79},										//1
		{242,67, 249, 79},										//2
		{252,67, 258, 79},										//3
		{261,67, 270, 79},										//4
		{166,155,230,166},										//Catch
		{2,  86, 67,  98},										//Z OFFSET
		//{68, 86, 117, 98},										//bed
		{68, 86, 117, 98},										//auto
		{119,87, 244, 102},										//leveling
	    //temperature
		{2,  172,46, 188},										//temp
		{48, 173,98, 184},										//hotend
		{68, 86, 117, 98},										//bed
		{100,173,199,188},										//Fan speed
		{212,353,242,365},										//PLA
		{231,353,263,365},										//ABS
		{207,103,264,117},										//preheat
	    //motion
		{2,  156,73, 169},										//feedrate
		{75, 154,165,169},										//acceleration
		{2,  353,56, 365},										//jerk
		{80, 190,188,205},										//steps/mm 
		//mixer
		{109,103,204,115},										//mix
		{191,191,268,205},										//gradient 
		{2,  208,109,224},										//random 
		{167,245,240,261},										//current
		{2,  263,52, 275},										//vtool 
		//bltouch
		{109,208,189,223},										//reset
		{41, 246,166,260},										//self-test
		{190,208,251,219},										//stow 
		{2,  228,78, 243},										//deploy
	    {80, 228,171,238},										//sw-mode
		//PLA&ABS settings
		{96, 281,148,292},										//nozzle
		{2,  173,46, 188},										//temp
		{68, 86, 117, 98},										//bed
		{100,173,199,188},										//Fan speed
		{74, 68, 163, 83},										//settings
		{2,  68, 71,  79},										//store
		//MAX feedrate 
		{229,120,262,131},										//max
		{2,  157,73, 169},										//feedrate
		{189,33, 199, 46},										//x
		{200,33, 209, 46},										//y
		{210,33, 219, 46},										//z
		{260,37, 267, 50},										//e
		//MAX acceleration 
		{229,120,262,131},										//max
		{75, 155,165,169},										//acceleration
		{189,33, 199, 46},										//x
		{200,33, 209, 46},										//y
		{210,33, 219, 46},										//z
		{260,37, 267, 50},										//e
		//MAX jerk 
		{229,120,262,131},										//max
		{2,  354,56, 365},										//jerk
		{189,33, 199, 46},										//x
		{200,33, 209, 46},										//y
		{210,33, 219, 46},										//z
		{260,37, 267, 50},										//e
		//MAX step 
		{229,120,262,131},										//max
		{80, 191,188,206},										//step
		{189,33, 199, 46},										//x
		{200,33, 209, 46},										//y
		{210,33, 219, 46},										//z
		{260,37, 267, 50},										//e
		//Mix 
		{108,137,208,152},										//extruder
		{232,67, 237, 79},										//1
		{242,67, 249, 79},										//2
		{252,67, 258, 79},										//3
		{261,67, 270, 79},										//4
		{54, 264,143,278},										//comit
		{2,  264,52, 275},										//vtool
		//gradient 
		{58, 354,118,365},										//start
		{1,  120,95, 131},										//end
		{210,33, 219, 46},										//z
		{2,  264,52, 275},										//vtool
		//random 
		{58, 354,118,365},										//start
		{1,  120,95, 131},										//end
		{210,33, 219, 46},										//z
		//printing tune pause continue stop 
		{119,352,167,368},										//tune
		{96, 118,143,134},										//pause
		{1,  0,  59,  13},										//continue(print)
		{144,118,184,131},										//stop
		//tune
		{1,  191,79, 205},										//speed
		{2,  173,46, 188},										//temp
		{48, 173,98, 184},										//hotend
		{68, 86, 117, 98},										//bed
		{100,173,199,188},										//fan speed
		{150,281,258,295},										//probe
		{2,  86, 67,  98},										//z-offset
		{171,51, 258, 61},										//mixer
		{3,  367,90, 384},										//config
	},
	//FR
	{
		{1,  462,69, 479},										//main					
		{148,461,217,479},										//prepare
		{1,  443,78, 457},										//control
		{80, 443,110,457},										//startinfo
		{120,443,189,461},										//move
		{1,  424,60, 442},										//home
		{191,444,245,457},										//leveling 
		{61, 424,164,442},										//temperture
	    {166,425,261,438},										//motion					
		{170,390,225,404},										//mixer
		{1,  407,68, 420},										//bltouch
		{70, 407,100,420},										//pla
		{101,407,133,420},										//abs
		{135,406,194,420},										//feedrate
		{1,  390,100,404},										//accel 
		{194,406,226,424},										//jerk
	    {102,391,168,405},										//step					
		{170,390,225,404},										//mix
		{1,  354,68, 372},										//gradient
		{70, 354,136,368},										//random
		{72, 461,146,479},										//print 
		{1,  372,125,386},										//file
		{72, 461,146,479},										//printing
		{127,372,177,390},										//tune 
		{179,373,235,389},										//language
		//language
	    {189,232,248,250},										//en
		{48, 251,115,266},										//sp 
		{2,  251,46, 264},										//ru
		{122,251,185,268},										//fr
		{187,251,264,268},										//po 
		{1,  267,60, 281},										//zh
		//main
	    {0,  1,  75,  17},										//print0			
		{77, 2,  141, 18},										//prepare0
		{141,1,  212, 14},										//caontrol0
		{213,1,  249, 14},										//info0
	    //back
		{164,218,217,231},										//back
	    //prepare
		{1,  18, 67,  34},										//move			
		{1,  35, 120, 48},										//disable steppers
		{121,35, 175, 51},										//home
		{183,52, 199, 65},										//bed
		{201,52, 252, 65},										//leveling
		{1,  83, 151, 99},										//power outage
		{1,  83, 151, 99},										//power outage
		{119,52, 181, 65},										//z-offset
		{200,69, 245, 82},										//preheat 
		{143,134,173,146},										//PLA
		{174,134,206,146},										//ABS
		{2,  134,66, 147},										//cooldown
		{130,118,184,133},										//language
	    //control
		{160,18, 257, 34},										//temperature			
		{68, 19, 159, 31},										//motion
		{177,36, 229, 48},										//mixer
		{65, 269, 178,288},										//config
		{135,69, 198, 82},										//bltouch
		{2,  52, 64,  69},										//store
		{65, 53, 118, 69},										//load
		{2,  69, 133, 82},										//restore
		{213,1,  249, 14},										//info
	    //move axis
		{1,  18, 67,  34},										//move			
		{218,118,228,130},										//x
		{229,118,239,130},										//y
		{239,118,248,130},										//z
		{67, 134,141,147},										//extruder
		{224,185,229,198},										//1
		{234,185,241,198},										//2
		{244,185,251,198},										//3
		{253,185,263,198},										//4
	    //home
		{121,35, 175, 51},										//home			
		{151,233,189,246},										//all
		//leveling	
		{230,35, 269, 48},										//point
		{224,185,229,198},										//1
		{234,185,241,198},										//2
		{244,185,251,198},										//3
		{253,185,263,198},										//4
		{1,  148,69, 165},										//Catch
		{119,52, 181, 65},										//Z OFFSET
		//{183,52, 199, 65},										//bed
		{183,52, 199, 65},										//auto
		{201,52, 252, 65},										//leveling
	    //temperature
		{70, 148,115,164},										//temp
		{117,148,153,161},										//hotend
		{183,52, 199, 65},										//bed
		{154,147,243,160},										//Fan speed
		{143,134,173,146},										//PLA
		{174,134,206,146},										//ABS
		{200,69, 245, 82},										//preheat
	    //motion
		{206,84, 260, 96},										//feedrate
		{1,  100,93, 113},										//acceleration
		{94, 97, 123,117},										//jerk
		{125,101,186,113},										//steps/mm 
		//mixer
		{177,36, 229, 48},										//mix
		{116,165,183,183},										//gradient 
		{185,165,251,179},										//random 
		{2,  232,92, 246},										//current
		{2,  218,52, 231},										//vtool 
		//bltouch
		{2,  184,47, 198},										//reset
		{122,185,222,198},										//self-test
		{2,  166,57, 183},										//stow 
		{49, 184,121,201},										//deploy
	    {2,  203,79, 216},										//sw-mode
		//PLA&ABS settings
		{117,148,153,161},										//nozzle
		{70, 148,115,164},										//temp
		{183,52, 199, 65},										//bed
		{154,147,243,160},										//Fan speed
		{221,219,246,231},										//settings
		{2,  52, 64,  69},										//store
		//MAX feedrate 
		{187,119,218,130},										//max
		{206,84, 260, 96},										//feedrate
		{218,118,228,130},										//x
		{229,118,239,130},										//y
		{239,118,248,130},										//z
		{260,37, 267, 50},										//e
		//MAX acceleration 
		{187,119,218,130},										//max
		{1,  100,93, 113},										//acceleration
		{218,118,228,130},										//x
		{229,118,239,130},										//y
		{239,118,248,130},										//z
		{260,37, 267, 50},										//e
		//MAX jerk 
		{187,119,218,130},										//max
		{94, 97, 123,117},										//jerk
		{218,118,228,130},										//x
		{229,118,239,130},										//y
		{239,118,248,130},										//z
		{260,37, 267, 50},										//e
		//MAX step 
		{187,119,218,130},										//max
		{125,101,186,113},										//step
		{218,118,228,130},										//x
		{229,118,239,130},										//y
		{239,118,248,130},										//z
		{260,37, 267, 50},										//e
		//Mix 
		{67, 134,141,147},										//extruder
		{224,185,229,198},										//1
		{234,185,241,198},										//2
		{244,185,251,198},										//3
		{253,185,263,198},										//4
		{54, 218,163,231},										//comit
		{2,  219,52, 231},										//vtool
		//gradient 
		{188,101,234,113},										//start
		{235,101,255,113},										//end
		{251,119,258,131},										//z
		{2,  219,52, 231},										//vtool
		//random 
		{188,101,234,113},										//start
		{235,101,255,113},										//end
		{251,119,258,131},										//z
		//printing tune pause continue stop 
		{2,  117,49, 133},										//tune
		{50, 118,93, 130},										//pause
		{0,  1,  59,  17},										//continue(print)
		{94, 118,129,133},										//stop
		//tune
		{58, 166,115,179},										//speed
		{70, 148,115,164},										//temp
		{117,148,153,161},										//hotend
		{183,52, 199, 65},										//bed
		{154,147,243,160},										//Fan speed
		{94, 233,151,246},										//probe
		{119,52, 181, 65},										//z-offset
		{177,36, 229, 48},										//mixer
		{65, 269, 178,288},										//config
	},
	//PT
	{
		{1,  325,69, 343},										//main					
		{156,326,225,343},										//prepare
		{1,  310,73, 324},										//control
		{75, 310,105,324},										//startinfo
		{107,311,157,324},										//move
		{91, 292,149,310},										//home
		{159,310,261,324},										//leveling 
		{150,293,253,309},										//temperture
	  {1,  277,93, 291},										//motion					
		{1,  292,90, 306},										//mixer
		{1,  263,68, 276},										//bltouch
		{70, 263,100,276},										//pla
		{101,263,123,276},										//abs
		{134,262,216,276},										//feedrate
		{1,  244,87, 262},										//accel 
		{57, 208,108,222},										//jerk
	   {89, 245,174,259},										//step					
		{176,244,236,258},										//mix
		{1,  226,79, 240},										//gradient
		{80, 226,155,240},										//random
		{72, 326,154,343},										//print 
		{156,226,220,243},										//file
		{72, 326,154,343},										//printing
		{221,226,270,240},										//tune 
		{2,  208,54, 225},										//language
		//language
	    {1,  291,47, 308},										//en
		{50, 291,120,307},										//sp 
		{123,292,173,304},										//ru
		{176,291,233,304},										//fr
		{1,  310,83, 327},										//po 
		{85, 310,136,323},										//zh
		//main
	    {0,  1,  84,  18},										//print0			
		{85, 1,  153, 17},										//prepare0
		{154,1,  227, 14},										//caontrol0
		{227,0,  259, 14},										//info0
	    //back
		{92, 275,135,288},										//back
	    //prepare
		{1,  20, 52,  31},										//move			
		{1,  37, 155, 50},										//disable steppers
		{147,19, 206, 36},										//home
		{1,  88, 36, 100},										//bed
		{39, 87, 141,100},										//leveling
		{1,  105,128,121},										//power outage
		{1,  105,128,121},										//power outage
		{167,73, 233, 86},										//z-offset
		{143,88, 238,103},										//preheat 
		{203,158,233,170},										//PLA
		{234,158,266,170},										//ABS
		{1,  175,75, 188},										//cooldown
		{114,157,165,173},										//language
	    //control
		{156,38, 259, 54},										//temperature			
		{54, 19, 146, 32},										//motion
		{1,  55, 90,  68},										//mixer
		{144,310,231,328},										//config
		{100,74, 166, 86},										//bltouch
		{91, 56, 178, 68},										//store
		{179,56, 225, 71},										//load
		{1,  73, 98,  85},										//restore
		{228,1, 259,  14},										//info
	    //move axis
		{1,  20, 52,  31},										//move			
		{207,20, 217, 32},										//x
		{218,20, 228, 32},										//y
		{229,20, 238, 32},										//z
		{77, 175,140,188},										//extruder
		{192,106,198,118},										//1
		{202,106,210,118},										//2
		{213,106,220,118},										//3
		{222,106,231,118},										//4
	    //home
		{147,19, 207, 36},										//home			
		{217,141,267,154},										//all
		//leveling	
		{142,176,189,188},										//point
		{192,106,198,118},										//1
		{202,106,210,118},										//2
		{213,106,220,118},										//3
		{222,106,231,118},										//4
		{191,176,262,192},										//Catch
		{167,73, 233, 86},										//Z OFFSET
		//{1,  88, 36, 100},										//bed
		{1,  88, 36, 100},										//auto
		{39, 87, 141,100},										//leveling
	    //temperature
		{1,  195,47, 210},										//temp
		{49, 194,82, 207},										//hotend
		{1,  88, 36, 100},										//bed
		{82, 194,167,207},										//Fan speed
		{203,158,233,170},										//PLA
		{234,158,266,170},										//ABS
		{143,88, 238,103},										//preheat
	    //motion
		{1,  123,84, 136},										//feedrate
		{85, 123,171,139},										//acceleration
		{172,123,223,136},										//jerk
		{1,  142,86, 154},										//steps/mm 
		//mixer
		{1,  55, 60,  68},										//mix
		{2,  212,80, 225},										//gradient 
		{80, 212,156,225},										//random 
		{50, 275,91, 288},										//current
		{85, 260,135,273},										//vtool 
		//bltouch
		{158,212,226,225},										//reset
		{175,245,261,257},										//self-test
		{1,  227,96, 240},										//stow 
		{99, 227,230,240},										//deploy
	    {1,  260,81, 272},										//sw-mode
		//PLA&ABS settings
		{136,276,193,288},										//nozzle
		{1,  195,46, 210},										//temp
		{1,  88, 36, 100},										//bed
		{82, 194,167,207},										//Fan speed
		{190,260,248,277},										//settings
		{91, 56, 178, 68},										//store
		//MAX feedrate 
		{167,158,201,170},										//max
		{1,  123,84, 136},										//feedrate
		{207,20, 217, 32},										//x
		{218,20, 228, 32},										//y
		{229,20, 238, 32},										//z
		{260,37, 267, 50},										//e
		//MAX acceleration 
		{167,158,201,170},										//max
		{85, 123,171,139},										//acceleration
		{207,20, 217, 32},										//x
		{218,20, 228, 32},										//y
		{229,20, 238, 32},										//z
		{240,20, 247, 32},										//e
		//MAX jerk 
		{167,158,201,170},										//max
		{172,123,223,136},										//jerk
		{207,20, 217, 32},										//x
		{218,20, 228, 32},										//y
		{229,20, 238, 32},										//z
		{240,20, 247, 32},										//e
		//MAX step 
		{167,158,201,170},										//max
		{1,  142,86, 154},										//step
		{207,20, 217, 32},										//x
		{218,20, 228, 32},										//y
		{229,20, 238, 32},										//z
		{240,20, 247, 32},										//e
		//Mix 
		{77, 175,140,188},										//extruder
		{192,106,198,118},										//1
		{202,106,210,118},										//2
		{213,106,220,118},										//3
		{222,106,231,118},										//4
		{1,  275,48, 288},										//comit
		{85, 260,135,273},										//vtool
		//gradient 
		{88, 141,136,154},										//start
		{138,141,166,154},										//end
		{229,20, 238, 32},										//z
		{85, 260,135,273},										//vtool
		//random 
		{88, 141,136,154},										//start
		{138,141,166,154},										//end
		{229,20, 238, 32},										//z
		//printing tune pause continue stop 
		{166,141,215,154},										//tune
		{1,  157,54, 170},										//pause
		{0,  1,  63,  18},										//continue
		{55, 157,112,170},										//stop
		//tune
		{168,194,256,207},										//speed
		{1,  195,46, 210},										//temp
		{49, 194,82, 207},										//hotend
		{1,  88, 36, 100},										//bed
		{82, 194,167,207},										//Fan speed
		{138,260,188,273},										//probe
		{167,73, 233, 86},										//z-offset
		{1,  55, 90,  68},										//mixer
		{144,310,231,328},										//config
	}
};

#endif
