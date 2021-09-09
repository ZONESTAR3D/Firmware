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
 * DwinMenu_control.cpp
 */

 #include "../../../inc/MarlinConfig.h"

#if HAS_DWIN_LCD
#include "dwin.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Control >>> Main
//
static void Item_Control_Mixer(const uint8_t row) {
 DWIN_Show_MultiLanguage_String(MTSTRING_MIXER, LBLX, MBASE(row));
 Draw_Menu_Line(row, ICON_MIXER);
 Draw_More_Icon(row);
}

static void Item_Control_Config(const uint8_t row) {
 DWIN_Show_MultiLanguage_String(MTSTRING_CONFIG, LBLX, MBASE(row));
 Draw_Menu_Line(row, ICON_CONTACT);
 Draw_More_Icon(row);
}

static void Item_Control_Motion(const uint8_t row) {
	DWIN_Show_MultiLanguage_String(MTSTRING_MOTION, LBLX, MBASE(row));
	Draw_Menu_Line(row, ICON_MOTION);
	Draw_More_Icon(row);
}

static void Item_Control_PLA(const uint8_t row) {
	DWIN_Show_MultiLanguage_String(MTSTRING_PREHEAT, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(MTSTRING_PLA, LBLX+GET_ICON_X(PREHEAT), MBASE(row));
	Draw_Menu_Line(row, ICON_PLAPREHEAT);
	Draw_More_Icon(row);
}

static void Item_Control_ABS(const uint8_t row) {
	DWIN_Show_MultiLanguage_String(MTSTRING_PREHEAT, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(MTSTRING_ABS, LBLX+GET_ICON_X(PREHEAT), MBASE(row));
	Draw_Menu_Line(row, ICON_ABSPREHEAT);
	Draw_More_Icon(row);	
}

#if ENABLED(BLTOUCH)
static void Item_Control_BLtouch(const uint8_t row) {
 DWIN_Show_MultiLanguage_String(MTSTRING_BLTOUCH, LBLX, MBASE(row)); 
 Draw_Menu_Line(row, ICON_BLTOUCH);
 Draw_More_Icon(row);
}
#endif

#if ENABLED(EEPROM_SETTINGS)
static void Item_Control_Save(const uint8_t row) {
 DWIN_Show_MultiLanguage_String(MTSTRING_STORE, LBLX, MBASE(row));
 DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_SETTINGS, LBLX+GET_ICON_X(STORE), MBASE(row));
 Draw_Menu_Line(row, ICON_WRITEEEPROM);
}

static void Item_Control_Load(const uint8_t row) {
 DWIN_Show_MultiLanguage_String(MTSTRING_LOAD, LBLX, MBASE(row));
 DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_SETTINGS, LBLX+GET_ICON_X(LOAD), MBASE(row));
 Draw_Menu_Line(row, ICON_READEEPROM);
}

static void Item_Control_Reset(const uint8_t row) {
 DWIN_Show_MultiLanguage_String(MTSTRING_RESET, LBLX, MBASE(row));
 Draw_Menu_Line(row, ICON_RESUMEEEPROM);
}
#endif

void Draw_Control_Menu(const uint8_t MenuItem) {
	DwinMenuID = DWMENU_CONTROL;	
	DwinMenu_control.set(MenuItem);
	DwinMenu_control.index = _MAX(DwinMenu_control.now, MROWS);

#if (CONTROL_CASE_TOTAL > MROWS)
	const int16_t scroll = MROWS - DwinMenu_control.index;
	#define CCSCROL(L) (scroll + (L))
#else
	#define CCSCROL(L) (L)
#endif
	#define CCVISI(L) WITHIN(CCSCROL(L), 0, MROWS)

	Clear_Dwin_Area(AREA_TITAL|AREA_MENU|AREA_STATUS);
	
	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_CONTROL, TITLE_X, TITLE_Y);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);
	if (CCVISI(CONTROL_CASE_BACK)) Draw_Back_First(DwinMenu_control.now == CONTROL_CASE_BACK);             // < Back

	if (CCVISI(CONTROL_CASE_MIXER)) Item_Control_Mixer(CCSCROL(CONTROL_CASE_MIXER));
	if (CCVISI(CONTROL_CASE_CONFIG)) Item_Control_Config(CCSCROL(CONTROL_CASE_CONFIG));
	if (CCVISI(CONTROL_CASE_MOTION)) Item_Control_Motion(CCSCROL(CONTROL_CASE_MOTION));
	if (CCVISI(CONTROL_CASE_SETPLA)) Item_Control_PLA(CCSCROL(CONTROL_CASE_SETPLA));
	if (CCVISI(CONTROL_CASE_SETABS)) Item_Control_ABS(CCSCROL(CONTROL_CASE_SETABS));

#if ENABLED(BLTOUCH)
	if (CCVISI(CONTROL_CASE_BLTOUCH)) Item_Control_BLtouch(CCSCROL(CONTROL_CASE_BLTOUCH));
#endif
#if ENABLED(EEPROM_SETTINGS)
	if (CCVISI(CONTROL_CASE_SAVE)) Item_Control_Save(CCSCROL(CONTROL_CASE_SAVE));
	if (CCVISI(CONTROL_CASE_LOAD)) Item_Control_Load(CCSCROL(CONTROL_CASE_LOAD));
	if (CCVISI(CONTROL_CASE_RESET)) Item_Control_Reset(CCSCROL(CONTROL_CASE_RESET));
#endif

	if(DwinMenu_control.now)	Draw_Menu_Cursor(CCSCROL(DwinMenu_control.now));	
	Draw_Status_Area();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Control >> Mixer
//
#if ENABLED (MIXING_EXTRUDER)
void Draw_Mixer_Menu(const uint8_t MenuItem) {	
	DwinMenuID = DWMENU_MIXER;	
	DwinMenu_mixer.set(MenuItem);
	DwinMenu_mixer.index = _MAX(DwinMenu_mixer.now, MROWS);
	
	Clear_Dwin_Area(AREA_TITAL|AREA_MENU);
	
	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_MIXER, TITLE_X, TITLE_Y);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);
	Draw_Back_First(DwinMenu_mixer.now == MIXER_CASE_BACK);

	//Mauanl
	Draw_Menu_Line(MIXER_CASE_MANUAL,ICON_MIXER_MANUAL);
	DWIN_Show_MultiLanguage_String(MIXER_MENU_MIX, LBLX, MBASE(MIXER_CASE_MANUAL));
	Draw_More_Icon(MIXER_CASE_MANUAL);
	//Gradient
	Draw_Menu_Line(MIXER_CASE_GRADIENT,ICON_MIXER_GRADIENT);
	DWIN_Show_MultiLanguage_String(MIXER_MENU_GRADIENT, LBLX, MBASE(MIXER_CASE_GRADIENT));
	Draw_More_Icon(MIXER_CASE_GRADIENT);
	DWIN_Draw_MaskString_Default(190, MBASE(MIXER_CASE_GRADIENT), F_STRING_ONOFF(mixer.gradient.enabled)); 
	//Random	
	Draw_Menu_Line(MIXER_CASE_RANDOM,ICON_MIXER_RANDOM);
	DWIN_Show_MultiLanguage_String(MIXER_MENU_RANDOM, LBLX, MBASE(MIXER_CASE_RANDOM));	
	Draw_More_Icon(MIXER_CASE_RANDOM);
	DWIN_Draw_MaskString_Default(190, MBASE(MIXER_CASE_RANDOM), F_STRING_ONOFF(mixer.random_mix.enabled));
	//Current VTOOL	
	Draw_Menu_Line(MIXER_CASE_VTOOL,ICON_S_VTOOL);
	DWIN_Show_MultiLanguage_String(MIXER_MENU_CURRENT, LBLX, MBASE(MIXER_CASE_VTOOL));
	DWIN_Show_MultiLanguage_String(MIXER_MENU_VTOOL, LBLX+GET_ICON_X(CURRENT), MBASE(MIXER_CASE_VTOOL));	
	DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(MIXER_CASE_VTOOL), mixer.selected_vtool);
	
	if (DwinMenu_mixer.now) Draw_Menu_Cursor(DwinMenu_mixer.now);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Control >> Mixer >>> Manual
//
static void Item_Mixer_Manual_VTOOL(const uint8_t row) {
	DWIN_Show_MultiLanguage_String(MIX_MENU_VTOOL, LBLX, MBASE(row));
	DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(row), HMI_Value.current_vtool);
	Draw_Menu_Line(row, ICON_S_VTOOL);
}
static void Item_Mixer_Manual_EXT1(const uint8_t row) {
	DWIN_Show_MultiLanguage_String(MIX_MENU_EXTRUDER, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(MIX_MENU_1, LBLX+GET_ICON_X(EXTRUDER), MBASE(row));
	DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(row), HMI_Value.mix_percent[0]);
	Draw_Menu_Line(row, ICON_EXTRUDER1);
}
static void Item_Mixer_Manual_EXT2(const uint8_t row) {
	DWIN_Show_MultiLanguage_String(MIX_MENU_EXTRUDER, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(MIX_MENU_2, LBLX+GET_ICON_X(EXTRUDER), MBASE(row));
	DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(row), HMI_Value.mix_percent[1]);
	Draw_Menu_Line(row, ICON_EXTRUDER2);

}
#if(MIXING_STEPPERS > 2)	
static void Item_Mixer_Manual_EXT3(const uint8_t row) {
	DWIN_Show_MultiLanguage_String(MIX_MENU_EXTRUDER, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(MIX_MENU_3, LBLX+GET_ICON_X(EXTRUDER), MBASE(row));
	DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(row), HMI_Value.mix_percent[2]);
	Draw_Menu_Line(row, ICON_EXTRUDER3);
}
#endif

#if(MIXING_STEPPERS > 3)	
static void Item_Mixer_Manual_EXT4(const uint8_t row) {
	DWIN_Show_MultiLanguage_String(MIX_MENU_EXTRUDER, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(MIX_MENU_4, LBLX+GET_ICON_X(EXTRUDER), MBASE(row));
	DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(row), HMI_Value.mix_percent[3]);
	Draw_Menu_Line(row, ICON_EXTRUDER4);
}
#endif

static void Item_Mixer_Manual_Commit(const uint8_t row) {
	DWIN_Show_MultiLanguage_String(MIX_MENU_COMIT, LBLX, MBASE(row));	
	Draw_Menu_Line(row, ICON_C_VTOOL);
}

inline void Draw_Mixer_Manual_Menu() {
	Clear_Dwin_Area(AREA_TITAL|AREA_MENU);
	DwinMenu_manualmix.reset();
	//DwinMenu_manualmix.index = _MAX(DwinMenu_manualmix.now, MROWS);

#if (MANUAL_CASE_TOTAL > MROWS)
	const int16_t scroll = MROWS - DwinMenu_manualmix.index; // Scrolled-up lines
	#define MCSCROL(L) (scroll + (L))
#else
	#define MCSCROL(L) (L)
#endif
	#define MCVISI(L) WITHIN(MCSCROL(L), 0, MROWS)

	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_MIX, TITLE_X, TITLE_Y);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);
  // < Back
	if (MCVISI(MANUAL_CASE_BACK)) Draw_Back_First(DwinMenu_manualmix.now == MANUAL_CASE_BACK);
	//VTOOL
	if (MCVISI(MANUAL_CASE_VTOOL)) Item_Mixer_Manual_VTOOL(MCSCROL(MANUAL_CASE_VTOOL));
	//Extruder 1
	if (MCVISI(MANUAL_CASE_EXTRUDER1)) Item_Mixer_Manual_EXT1(MCSCROL(MANUAL_CASE_EXTRUDER1));
	//Extruder 2
	if (MCVISI(MANUAL_CASE_EXTRUDER2)) Item_Mixer_Manual_EXT2(MCSCROL(MANUAL_CASE_EXTRUDER2));
	//Extruder 3
	#if(MIXING_STEPPERS > 2)	
	if (MCVISI(MANUAL_CASE_EXTRUDER3)) Item_Mixer_Manual_EXT3(MCSCROL(MANUAL_CASE_EXTRUDER3));
	#endif
	//Extruder 4
	#if(MIXING_STEPPERS > 3)
	if (MCVISI(MANUAL_CASE_EXTRUDER4)) Item_Mixer_Manual_EXT4(MCSCROL(MANUAL_CASE_EXTRUDER4));
	#endif
	if (MCVISI(MANUAL_CASE_COMMIT)) Item_Mixer_Manual_Commit(MCSCROL(MANUAL_CASE_COMMIT));
			
	if (DwinMenu_manualmix.now) Draw_Menu_Cursor(MCSCROL(DwinMenu_manualmix.now));
}

void HMI_Adjust_Mixer_Manual_Vtool() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int8(encoder_diffState, &HMI_Value.current_vtool)) {			
			DWIN_Draw_IntValue_Default(2, MENUVALUE_X+16, MBASE(MROWS + MANUAL_CASE_VTOOL - DwinMenu_manualmix.index), HMI_Value.current_vtool);
			mixer.update_mix_from_vtool(HMI_Value.current_vtool);
			memcpy(HMI_Value.mix_percent, mixer.percentmix, sizeof(mixer.percentmix));
			if((MROWS + MANUAL_CASE_EXTRUDER1 - DwinMenu_manualmix.index) > MANUAL_CASE_BACK) 
				DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS + MANUAL_CASE_EXTRUDER1 - DwinMenu_manualmix.index), HMI_Value.mix_percent[0]);
			if((MROWS + MANUAL_CASE_EXTRUDER2 - DwinMenu_manualmix.index) > MANUAL_CASE_BACK) 
				DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS + MANUAL_CASE_EXTRUDER2 - DwinMenu_manualmix.index), HMI_Value.mix_percent[1]);
		#if (MIXING_STEPPERS > 2)
			if((MROWS + MANUAL_CASE_EXTRUDER3 - DwinMenu_manualmix.index) > MANUAL_CASE_BACK) 
				DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS + MANUAL_CASE_EXTRUDER3 - DwinMenu_manualmix.index), HMI_Value.mix_percent[2]);
		#endif
		#if (MIXING_STEPPERS > 3)
			if((MROWS + MANUAL_CASE_EXTRUDER4 - DwinMenu_manualmix.index) > MANUAL_CASE_BACK) 
				DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS + MANUAL_CASE_EXTRUDER4 - DwinMenu_manualmix.index), HMI_Value.mix_percent[3]);
		#endif		
			DwinMenuID = DWMENU_MIXER_MANUAL;
			EncoderRate.enabled = false;
			dwinLCD.UpdateLCD();
			return;
		}
		NOLESS(HMI_Value.current_vtool, 0);
		NOMORE(HMI_Value.current_vtool, (MIXING_VIRTUAL_TOOLS-1));
		DWIN_Draw_Select_IntValue_Default(2, MENUVALUE_X+16, MBASE(MROWS + MANUAL_CASE_VTOOL-DwinMenu_manualmix.index), HMI_Value.current_vtool);		
		dwinLCD.UpdateLCD();
	}
}

void HMI_Adjust_Ext_Percent(uint8_t Extruder_Number) {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int8(encoder_diffState, &HMI_Value.mix_percent[Extruder_Number])) {
			DwinMenuID = DWMENU_MIXER_MANUAL;
			EncoderRate.enabled = false;
			DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS+MANUAL_CASE_EXTRUDER1+Extruder_Number-DwinMenu_manualmix.index), HMI_Value.mix_percent[Extruder_Number]);
			dwinLCD.UpdateLCD();
			return;
		}
		NOLESS(HMI_Value.mix_percent[Extruder_Number], 0);
		NOMORE(HMI_Value.mix_percent[Extruder_Number], 100);
		DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS+MANUAL_CASE_EXTRUDER1+Extruder_Number-DwinMenu_manualmix.index), HMI_Value.mix_percent[Extruder_Number]);
		dwinLCD.UpdateLCD();
	}
}

void HMI_Mixer_Manual() { 
	ENCODER_DiffState encoder_diffState = get_encoder_state();
	if (encoder_diffState == ENCODER_DIFF_NO) return;

	// Avoid flicker by updating only the previous menu
	if (encoder_diffState == ENCODER_DIFF_CW) {		
		if (DwinMenu_manualmix.inc(MANUAL_CASE_END)){
			if (DwinMenu_manualmix.now > MROWS && DwinMenu_manualmix.now > DwinMenu_manualmix.index) {
				DwinMenu_manualmix.index = DwinMenu_manualmix.now;				
				Scroll_Menu(DWIN_SCROLL_UP);
				if(DwinMenu_manualmix.index == MANUAL_CASE_COMMIT) Item_Mixer_Manual_Commit(MROWS);
				#if (MIXING_STEPPERS > 4)
				else if(DwinMenu_manualmix.index == MANUAL_CASE_EXTRUDER4) Item_Mixer_Manual_EXT4(MROWS);			
				#endif
			}
			else 
				Move_Highlight(1, DwinMenu_manualmix.now + MROWS - DwinMenu_manualmix.index);		
		}
	}
	else if (encoder_diffState == ENCODER_DIFF_CCW) {
		if (DwinMenu_manualmix.dec()){
			if (DwinMenu_manualmix.now < DwinMenu_manualmix.index - MROWS) {
				DwinMenu_manualmix.index--;
				Scroll_Menu(DWIN_SCROLL_DOWN);
				if(DwinMenu_manualmix.index - MROWS == MANUAL_CASE_BACK) Draw_Back_First();				
				else if(DwinMenu_manualmix.index - MROWS == MANUAL_CASE_EXTRUDER1) Item_Mixer_Manual_EXT1(0);
				else if(DwinMenu_manualmix.index - MROWS == MANUAL_CASE_VTOOL) Item_Mixer_Manual_VTOOL(0);
			}
			else 
				Move_Highlight(-1, DwinMenu_manualmix.now + MROWS - DwinMenu_manualmix.index);			
		}
	}
	else if (encoder_diffState == ENCODER_DIFF_ENTER) {
		switch (DwinMenu_manualmix.now) {
			case 0: 						// Back				
				Draw_Mixer_Menu(MIXER_CASE_MANUAL);
			break;

			case MANUAL_CASE_VTOOL: 	// Vtool
				DwinMenuID = DWMENU_MANUALMIXER_VTOOL;
				DWIN_Draw_Select_IntValue_Default(2, MENUVALUE_X+16, MBASE(MROWS + MANUAL_CASE_VTOOL -DwinMenu_manualmix.index), HMI_Value.current_vtool);
				EncoderRate.enabled = true;
			break;
			
			case MANUAL_CASE_EXTRUDER1: 	// ex1
				DwinMenuID = DWMENU_MIXER_EXT1;
				DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS + MANUAL_CASE_EXTRUDER1 -DwinMenu_manualmix.index), HMI_Value.mix_percent[0]);
				EncoderRate.enabled = true;
			break;
				
			case MANUAL_CASE_EXTRUDER2: 	// ex2
				DwinMenuID = DWMENU_MIXER_EXT2;
				DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS + MANUAL_CASE_EXTRUDER2 -DwinMenu_manualmix.index), HMI_Value.mix_percent[1]);
				EncoderRate.enabled = true;
			break;

#if(MIXING_STEPPERS > 2)
			case MANUAL_CASE_EXTRUDER3: 	// ex3
				DwinMenuID = DWMENU_MIXER_EXT3;
				DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS + MANUAL_CASE_EXTRUDER3 -DwinMenu_manualmix.index), HMI_Value.mix_percent[2]);
				EncoderRate.enabled = true;
			break;
#endif

#if(MIXING_STEPPERS > 3) 
			case MANUAL_CASE_EXTRUDER4: 	// ex4
				DwinMenuID = DWMENU_MIXER_EXT4;
				DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS + MANUAL_CASE_EXTRUDER4 -DwinMenu_manualmix.index), HMI_Value.mix_percent[3]);
				EncoderRate.enabled = true;
			break;
#endif
				
			case MANUAL_CASE_COMMIT: 		// COMMIT
				DwinMenuID = DWMENU_MIXER_MANUAL;				
				mixer.normalize_mixer_percent(&HMI_Value.mix_percent[0]);
				MIXER_STEPPER_LOOP(i) {mixer.percentmix[i] = HMI_Value.mix_percent[i];}
				mixer.copy_percentmix_to_collector();
				mixer.normalize(HMI_Value.current_vtool);
				DwinMenu_manualmix.reset();				
				Draw_Mixer_Manual_Menu();
			break;
		 
			default: break;
		}
	}
	dwinLCD.UpdateLCD();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Control >> Mixer >>> Gradient
//
#if ENABLED(GRADIENT_MIX)
inline void Draw_Mixer_Gradient_Menu() {
	Clear_Dwin_Area(AREA_TITAL|AREA_MENU);	
	DwinMenu_GradientMix.reset();
	//DwinMenu_GradientMix.index = _MAX(DwinMenu_GradientMix.now, MROWS);
	
#if GRADIENT_CASE_TOTAL >= 6
	const int16_t scroll = MROWS - DwinMenu_GradientMix.index; // Scrolled-up lines
	#define ACSCROL(L) (scroll + (L))
#else
	#define ACSCROL(L) (L)
#endif
	#define ACLINE(L) MBASE(ACSCROL(L))
	#define ACVISI(L) WITHIN(ACSCROL(L), 0, MROWS)

	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_GRADIENT, TITLE_X, TITLE_Y);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);
	if (ACVISI(0)) Draw_Back_First(DwinMenu_GradientMix.now == 0);             // < Back
	
	DWIN_Show_MultiLanguage_String(GRADIENT_MENU_START, LBLX, ACLINE(GRADIENT_CASE_ZPOS_START));
	DWIN_Show_MultiLanguage_String(GRADIENT_MENU_Z, LBLX+GET_ICON_X(START), ACLINE(GRADIENT_CASE_ZPOS_START));
	HMI_Value.Auto_Zstart_scale = mixer.gradient.start_z*MINUNITMULT;
	DWIN_Draw_Small_Float31(MENUVALUE_X, MBASE(GRADIENT_CASE_ZPOS_START), HMI_Value.Auto_Zstart_scale);
	Draw_Menu_Line(GRADIENT_CASE_ZPOS_START,ICON_ZPOS_RISE);
	
	DWIN_Show_MultiLanguage_String(GRADIENT_MENU_END, LBLX, ACLINE(GRADIENT_CASE_ZPOS_END));
	DWIN_Show_MultiLanguage_String(GRADIENT_MENU_Z, LBLX+GET_ICON_X(END), ACLINE(GRADIENT_CASE_ZPOS_END));
	HMI_Value.Auto_Zend_scale = mixer.gradient.end_z*MINUNITMULT;
	DWIN_Draw_Small_Float31(MENUVALUE_X, MBASE(2), HMI_Value.Auto_Zend_scale);
	Draw_Menu_Line(GRADIENT_CASE_ZPOS_END,ICON_ZPOS_DROP);

	DWIN_Show_MultiLanguage_String(GRADIENT_MENU_START, LBLX, ACLINE(GRADIENT_CASE_VTOOL_START));
	DWIN_Show_MultiLanguage_String(GRADIENT_MENU_VTOOL, LBLX+GET_ICON_X(START), ACLINE(GRADIENT_CASE_VTOOL_START));
	DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(3), mixer.gradient.start_vtool);
	Draw_Menu_Line(GRADIENT_CASE_VTOOL_START,ICON_VTOOL_RISE);
	
	DWIN_Show_MultiLanguage_String(GRADIENT_MENU_END, LBLX, ACLINE(GRADIENT_CASE_VTOOL_END));
	DWIN_Show_MultiLanguage_String(GRADIENT_MENU_VTOOL, LBLX+GET_ICON_X(END), ACLINE(GRADIENT_CASE_VTOOL_END));
	DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(4), mixer.gradient.end_vtool); 
	Draw_Menu_Line(GRADIENT_CASE_VTOOL_END,ICON_VTOOL_DROP);
  
 	if (DwinMenu_GradientMix.now) Draw_Menu_Cursor(DwinMenu_GradientMix.now);
}

void HMI_Adjust_Gradient_Zpos_Start() {
	static int16_t last_Z_scale = 0;
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();

	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.Auto_Zstart_scale)) {			
			EncoderRate.enabled = false;
			last_Z_scale = HMI_Value.Auto_Zstart_scale;
			DWIN_Draw_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_GradientMix.index + GRADIENT_CASE_ZPOS_START), HMI_Value.Auto_Zstart_scale);
			DwinMenuID = DWMENU_MIXER_GRADIENT;			
			mixer.gradient.start_z = (float)HMI_Value.Auto_Zstart_scale / MINUNITMULT;
			mixer.refresh_gradient();
			dwinLCD.UpdateLCD();
			return;
	  }
		
	  if ((HMI_Value.Auto_Zstart_scale - last_Z_scale) > (Z_MAX_POS) * MINUNITMULT)
			HMI_Value.Auto_Zstart_scale = last_Z_scale + (Z_MAX_POS) * MINUNITMULT;
	  else if ((last_Z_scale - HMI_Value.Auto_Zstart_scale) > (Z_MAX_POS) * MINUNITMULT)
			HMI_Value.Auto_Zstart_scale = last_Z_scale - (Z_MAX_POS) * MINUNITMULT;		
		NOLESS(HMI_Value.Auto_Zstart_scale, 0);
		NOMORE(HMI_Value.Auto_Zstart_scale, Z_MAX_POS*MINUNITMULT);
		DWIN_Draw_Selected_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_GradientMix.index + GRADIENT_CASE_ZPOS_START), HMI_Value.Auto_Zstart_scale);		
		dwinLCD.UpdateLCD();
	}
}

void HMI_Adjust_Gradient_Zpos_End() {
	static int16_t last_Z_scale = 0;
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();

	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.Auto_Zend_scale)) {			
			EncoderRate.enabled = false;
			last_Z_scale = HMI_Value.Auto_Zend_scale;
			DWIN_Draw_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_GradientMix.index + GRADIENT_CASE_ZPOS_END), HMI_Value.Auto_Zend_scale);
			DwinMenuID = DWMENU_MIXER_GRADIENT;
			mixer.gradient.end_z = (float)HMI_Value.Auto_Zend_scale / MINUNITMULT;
		 	mixer.refresh_gradient();
			dwinLCD.UpdateLCD();
			return;
	  }		
	  if ((HMI_Value.Auto_Zend_scale - last_Z_scale) > (Z_MAX_POS) * MINUNITMULT)
			HMI_Value.Auto_Zend_scale = last_Z_scale + (Z_MAX_POS) * MINUNITMULT;
	  else if ((last_Z_scale - HMI_Value.Auto_Zend_scale) > (Z_MAX_POS) * MINUNITMULT)
			HMI_Value.Auto_Zend_scale = last_Z_scale - (Z_MAX_POS) * MINUNITMULT;
	   NOLESS(HMI_Value.Auto_Zend_scale, 0);	
		 NOMORE(HMI_Value.Auto_Zend_scale, Z_MAX_POS*MINUNITMULT);	
		 DWIN_Draw_Selected_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_GradientMix.index + GRADIENT_CASE_ZPOS_END), HMI_Value.Auto_Zend_scale);		
		 dwinLCD.UpdateLCD();
	}
}

void HMI_Adjust_Gradient_VTool_Start() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int8(encoder_diffState, &mixer.gradient.start_vtool)) {			
			EncoderRate.enabled = false;
			DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS -DwinMenu_GradientMix.index + GRADIENT_CASE_VTOOL_START), mixer.gradient.start_vtool);			
			DwinMenuID = DWMENU_MIXER_GRADIENT;
			dwinLCD.UpdateLCD();
			mixer.refresh_gradient();
			return;
		}
		NOLESS(mixer.gradient.start_vtool, 0);
		NOMORE(mixer.gradient.start_vtool, MIXING_VIRTUAL_TOOLS-1);
		DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS -DwinMenu_GradientMix.index + GRADIENT_CASE_VTOOL_START), mixer.gradient.start_vtool);
		dwinLCD.UpdateLCD();
	}
}

void HMI_Adjust_Gradient_VTool_End() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int8(encoder_diffState,&mixer.gradient.end_vtool)) {			
			EncoderRate.enabled = false;
			DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS -DwinMenu_GradientMix.index + GRADIENT_CASE_VTOOL_END), mixer.gradient.end_vtool);			
			DwinMenuID = DWMENU_MIXER_GRADIENT;
			dwinLCD.UpdateLCD();
			mixer.refresh_gradient();
			return;
		}
		NOLESS(mixer.gradient.end_vtool, 0);
		NOMORE(mixer.gradient.end_vtool, MIXING_VIRTUAL_TOOLS-1);
		DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS -DwinMenu_GradientMix.index + GRADIENT_CASE_VTOOL_END), mixer.gradient.end_vtool);
		dwinLCD.UpdateLCD();
	}
}

void HMI_Mixer_Gradient() {
 ENCODER_DiffState encoder_diffState = get_encoder_state();
 if (encoder_diffState == ENCODER_DIFF_NO) return;
 
 // Avoid flicker by updating only the previous menu
 if (encoder_diffState == ENCODER_DIFF_CW) {
  if (DwinMenu_GradientMix.inc(GRADIENT_CASE_END)) {
   if (DwinMenu_GradientMix.now > MROWS && DwinMenu_GradientMix.now > DwinMenu_GradientMix.index) {
    DwinMenu_GradientMix.index = DwinMenu_GradientMix.now;
		Scroll_Menu(DWIN_SCROLL_UP);
   }
   else 
    Move_Highlight(1, DwinMenu_GradientMix.now + MROWS - DwinMenu_GradientMix.index);
  }
 }
 else if (encoder_diffState == ENCODER_DIFF_CCW) {
  if (DwinMenu_GradientMix.dec()) {
   if (DwinMenu_GradientMix.now < DwinMenu_GradientMix.index - MROWS) {
    DwinMenu_GradientMix.index--;
    Scroll_Menu(DWIN_SCROLL_DOWN);
   }
   else 
    Move_Highlight(-1, DwinMenu_GradientMix.now + MROWS - DwinMenu_GradientMix.index);   
  }
 }
 else if (encoder_diffState == ENCODER_DIFF_ENTER) {
  switch (DwinMenu_GradientMix.now) {
	 case 0: 						// Back	 
    Draw_Mixer_Menu(MIXER_CASE_GRADIENT);
    break;
		
	 case GRADIENT_CASE_ZPOS_START: 		// zpos_start
    DwinMenuID = DWMENU_MIXER_GRADIENT_ZSTART;
		HMI_Value.Auto_Zstart_scale = mixer.gradient.start_z*MINUNITMULT;
		DWIN_Draw_Selected_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_GradientMix.index + GRADIENT_CASE_ZPOS_START), HMI_Value.Auto_Zstart_scale);
	  EncoderRate.enabled = true;
    break;
		
	 case GRADIENT_CASE_ZPOS_END: 		// zpos_end
    DwinMenuID = DWMENU_MIXER_GRADIENT_ZEND;
		HMI_Value.Auto_Zstart_scale = mixer.gradient.end_z*MINUNITMULT;
		DWIN_Draw_Selected_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_GradientMix.index + GRADIENT_CASE_ZPOS_END), HMI_Value.Auto_Zend_scale);
	  EncoderRate.enabled = true;
    break;
		
	 case GRADIENT_CASE_VTOOL_START: 		// vtool_start
    DwinMenuID = DWMENU_MIXER_GRADIENT_TSTAR;
    DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS -DwinMenu_GradientMix.index + GRADIENT_CASE_VTOOL_START), mixer.gradient.start_vtool);
		EncoderRate.enabled = true;
    break;
		
	 case GRADIENT_CASE_VTOOL_END: 		// vtool_end
    DwinMenuID = DWMENU_MIXER_GRADIENT_TEND;
		DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(MROWS -DwinMenu_GradientMix.index + GRADIENT_CASE_VTOOL_END), mixer.gradient.end_vtool);
		EncoderRate.enabled = true;
    break;
		
   default: break;
  }
 }
 dwinLCD.UpdateLCD();
}
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Control >> Mixer >>> Random
//
#if ENABLED(RANDOM_MIX)
inline void Draw_Mixer_Random_Menu() {
	Clear_Dwin_Area(AREA_TITAL|AREA_MENU);
	DwinMenu_RandomMix.reset();
	DwinMenu_RandomMix.index = _MAX(DwinMenu_RandomMix.now, MROWS);
	
	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_RANDOM, TITLE_X, TITLE_Y);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);
	
	Draw_Back_First(DwinMenu_RandomMix.now == RANDOM_CASE_BACK); // < Back
	//Z start
	DWIN_Show_MultiLanguage_String(RANDOM_MENU_START, LBLX, MBASE(RANDOM_CASE_ZPOS_START));
	DWIN_Show_MultiLanguage_String(RANDOM_MENU_Z, LBLX+GET_ICON_X(START), MBASE(RANDOM_CASE_ZPOS_START));
	HMI_Value.Random_Zstart_scale = mixer.random_mix.start_z*MINUNITMULT;
	DWIN_Draw_Small_Float31(MENUVALUE_X, MBASE(RANDOM_CASE_ZPOS_START), HMI_Value.Random_Zstart_scale);
	Draw_Menu_Line(RANDOM_CASE_ZPOS_START,ICON_ZPOS_RISE);
	//Z END
	DWIN_Show_MultiLanguage_String(RANDOM_MENU_END, LBLX, MBASE(RANDOM_CASE_ZPOS_END));
	DWIN_Show_MultiLanguage_String(RANDOM_MENU_Z, LBLX+GET_ICON_X(END), MBASE(RANDOM_CASE_ZPOS_END));
	HMI_Value.Random_Zend_scale = mixer.random_mix.end_z*MINUNITMULT;
	DWIN_Draw_Small_Float31(MENUVALUE_X, MBASE(RANDOM_CASE_ZPOS_END), HMI_Value.Random_Zend_scale);
	Draw_Menu_Line(RANDOM_CASE_ZPOS_END,ICON_ZPOS_DROP);
	//Height
	Draw_Menu_Line(RANDOM_CASE_HEIGHT,ICON_CURSOR);
	HMI_Value.Random_Height = mixer.random_mix.height*MINUNITMULT;
	DWIN_Draw_MaskString_Default(LBLX, MBASE(RANDOM_CASE_HEIGHT), PSTR("Height:"));
	DWIN_Draw_Small_Float31(MENUVALUE_X, MBASE(RANDOM_CASE_HEIGHT), HMI_Value.Random_Height);
	//Extruders
	Draw_Menu_Line(RANDOM_CASE_EXTRUDERS,ICON_CURSOR);
	DWIN_Draw_MaskString_Default(LBLX, MBASE(RANDOM_CASE_EXTRUDERS), PSTR("Extruders:"));
	DWIN_Draw_IntValue_Default(1, MENUVALUE_X+4*8, MBASE(RANDOM_CASE_EXTRUDERS), mixer.random_mix.extruders);
	
 if (DwinMenu_RandomMix.now) Draw_Menu_Cursor(DwinMenu_RandomMix.now); 
}

void HMI_Adjust_Random_Zpos_Start() {
	static int16_t last_Z_scale = 0;
	
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.Random_Zstart_scale)) {			
			EncoderRate.enabled = false;
			last_Z_scale = HMI_Value.Random_Zstart_scale;
			DWIN_Draw_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_RandomMix.index + RANDOM_CASE_ZPOS_START), HMI_Value.Random_Zstart_scale);
			DwinMenuID = DWMENU_MIXER_RANDOM;
			dwinLCD.UpdateLCD();
			mixer.random_mix.start_z = (float)HMI_Value.Random_Zstart_scale / MINUNITMULT;
			mixer.refresh_random_mix();
			return;
	  }		
	  if ((HMI_Value.Random_Zstart_scale - last_Z_scale) > (Z_MAX_POS) * MINUNITMULT)
			HMI_Value.Random_Zstart_scale = last_Z_scale + (Z_MAX_POS) * MINUNITMULT;
	  else if ((last_Z_scale - HMI_Value.Random_Zstart_scale) > (Z_MAX_POS) * MINUNITMULT)
			HMI_Value.Random_Zstart_scale = last_Z_scale - (Z_MAX_POS) * MINUNITMULT;
		NOLESS(HMI_Value.Random_Zstart_scale, 0);		
		DWIN_Draw_Selected_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_RandomMix.index + RANDOM_CASE_ZPOS_START), HMI_Value.Random_Zstart_scale);
		dwinLCD.UpdateLCD();
	}
}

void HMI_Adjust_Random_Zpos_End() {
	static int16_t last_Z_scale = 0;
	
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.Random_Zend_scale)) {			
			EncoderRate.enabled = false;
			last_Z_scale = HMI_Value.Random_Zend_scale;
			DWIN_Draw_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_RandomMix.index + RANDOM_CASE_ZPOS_END), HMI_Value.Random_Zend_scale);			
			DwinMenuID = DWMENU_MIXER_RANDOM;
			dwinLCD.UpdateLCD();
			mixer.random_mix.end_z = (float)HMI_Value.Random_Zend_scale / MINUNITMULT;
		 	mixer.refresh_random_mix();
			return;
	  }
		
	  if ((HMI_Value.Random_Zend_scale - last_Z_scale) > (Z_MAX_POS) * MINUNITMULT)
			HMI_Value.Random_Zend_scale = last_Z_scale + (Z_MAX_POS) * MINUNITMULT;
	  else if ((last_Z_scale - HMI_Value.Random_Zend_scale) > (Z_MAX_POS) * MINUNITMULT)
			HMI_Value.Random_Zend_scale = last_Z_scale - (Z_MAX_POS) * MINUNITMULT;
	   NOLESS(HMI_Value.Random_Zend_scale, 0);		 
		 DWIN_Draw_Selected_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_RandomMix.index + RANDOM_CASE_ZPOS_END), HMI_Value.Random_Zend_scale);
		 dwinLCD.UpdateLCD();
	}
}

void HMI_Adjust_Random_Height() {
	static float last_Height = 0;
	
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.Random_Height)) {			
			EncoderRate.enabled = false;
			last_Height = HMI_Value.Random_Height;
			DWIN_Draw_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_RandomMix.index + RANDOM_CASE_HEIGHT), HMI_Value.Random_Height);
			DwinMenuID = DWMENU_MIXER_RANDOM;
			dwinLCD.UpdateLCD();
			mixer.refresh_random_mix();
			return;
	  }
		
	  if ((HMI_Value.Random_Height - last_Height) > 100 * MINUNITMULT)
			HMI_Value.Random_Height = last_Height + 100 * MINUNITMULT;
	  else if ((last_Height - HMI_Value.Random_Height) > Z_MAX_POS * MINUNITMULT)
			HMI_Value.Random_Height = last_Height - Z_MAX_POS * MINUNITMULT;
	   NOLESS(HMI_Value.Random_Height, 0);
		 NOMORE(HMI_Value.Random_Height, Z_MAX_POS * MINUNITMULT);
		 mixer.random_mix.height = (float)HMI_Value.Random_Height / MINUNITMULT;
		 DWIN_Draw_Selected_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_RandomMix.index + RANDOM_CASE_HEIGHT), HMI_Value.Random_Height);
		 dwinLCD.UpdateLCD();
	}
}


void HMI_Adjust_Random_Extruders() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_uint8(encoder_diffState, &mixer.random_mix.extruders)) {			
			EncoderRate.enabled = false;
			DWIN_Draw_IntValue_Default(1, MENUVALUE_X+4*8, MBASE(MROWS -DwinMenu_RandomMix.index + RANDOM_CASE_EXTRUDERS), mixer.random_mix.extruders);
			DwinMenuID = DWMENU_MIXER_RANDOM;
			dwinLCD.UpdateLCD();
			mixer.refresh_random_mix();
			return;
		}
		NOLESS(mixer.random_mix.extruders, 1);
		NOMORE(mixer.random_mix.extruders, MIXING_STEPPERS);		
		DWIN_Draw_Select_IntValue_Default(1, MENUVALUE_X+4*8, MBASE(MROWS -DwinMenu_RandomMix.index + RANDOM_CASE_EXTRUDERS), mixer.random_mix.extruders);
		dwinLCD.UpdateLCD();
	}
}

void HMI_Mixer_Random() {
 ENCODER_DiffState encoder_diffState = get_encoder_state();
 if (encoder_diffState == ENCODER_DIFF_NO) return;
 
 // Avoid flicker by updating only the previous menu
 if (encoder_diffState == ENCODER_DIFF_CW) {
  if (DwinMenu_RandomMix.inc(RANDOM_CASE_END)) {
   if (DwinMenu_RandomMix.now > MROWS && DwinMenu_RandomMix.now > DwinMenu_RandomMix.index) {
    DwinMenu_RandomMix.index = DwinMenu_RandomMix.now;
		Scroll_Menu(DWIN_SCROLL_UP);
   }
   else
    Move_Highlight(1, DwinMenu_RandomMix.now + MROWS - DwinMenu_RandomMix.index);
  }
 }
 else if (encoder_diffState == ENCODER_DIFF_CCW) {
  if (DwinMenu_RandomMix.dec()) {
   if (DwinMenu_RandomMix.now < DwinMenu_RandomMix.index - MROWS) {
    DwinMenu_RandomMix.index--;
    Scroll_Menu(DWIN_SCROLL_DOWN);
   }
   else
    Move_Highlight(-1, DwinMenu_RandomMix.now + MROWS - DwinMenu_RandomMix.index);
  }
 }
 else if (encoder_diffState == ENCODER_DIFF_ENTER) {
  switch (DwinMenu_RandomMix.now) {
	 case 0: 						// Back
    Draw_Mixer_Menu(MIXER_CASE_RANDOM);
   break;
		
	 case RANDOM_CASE_ZPOS_START: 		// zpos_start
    DwinMenuID = DWMENU_MIXER_RANDOM_ZSTART;
		HMI_Value.Random_Zstart_scale = mixer.random_mix.start_z*MINUNITMULT;
		DWIN_Draw_Selected_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_RandomMix.index + RANDOM_CASE_ZPOS_START), HMI_Value.Random_Zstart_scale);
	  EncoderRate.enabled = true;
   break;
	 
	 case RANDOM_CASE_ZPOS_END: 			// zpos_end
    DwinMenuID = DWMENU_MIXER_RANDOM_ZEND;
		HMI_Value.Random_Zend_scale = mixer.random_mix.end_z*MINUNITMULT;
		DWIN_Draw_Selected_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_RandomMix.index + RANDOM_CASE_ZPOS_END), HMI_Value.Random_Zend_scale);
	  EncoderRate.enabled = true;
   break;
	 
  case RANDOM_CASE_HEIGHT: 		// Height
    DwinMenuID = DWMENU_MIXER_RANDOM_HEIGHT;
		HMI_Value.Random_Height = mixer.random_mix.height*MINUNITMULT;
		DWIN_Draw_Selected_Small_Float31(MENUVALUE_X, MBASE(MROWS -DwinMenu_RandomMix.index + RANDOM_CASE_HEIGHT), HMI_Value.Random_Height);
	  EncoderRate.enabled = true;	
   break;
	 
  case RANDOM_CASE_EXTRUDERS: 		// Extruders
    DwinMenuID = DWMENU_MIXER_RANDOM_EXTN;
		DWIN_Draw_Select_IntValue_Default(1, MENUVALUE_X+4*8, MBASE(RANDOM_CASE_EXTRUDERS), mixer.random_mix.extruders);
	  EncoderRate.enabled = true;
   break;
	 
   default: break;
  }
 }
 dwinLCD.UpdateLCD();
}
#endif

void HMI_Adjust_Mixer_Vtool() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int8(encoder_diffState, &mixer.selected_vtool)) {
			DwinMenuID = DWMENU_MIXER;
			EncoderRate.enabled = false;
			DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(MIXER_CASE_VTOOL), mixer.selected_vtool);	
			mixer.update_mix_from_vtool();
			dwinLCD.UpdateLCD();
			return;
		}
		NOLESS(mixer.selected_vtool, 0);
		NOMORE(mixer.selected_vtool, (MIXING_VIRTUAL_TOOLS-1));
		DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(MIXER_CASE_VTOOL), mixer.selected_vtool);
		dwinLCD.UpdateLCD();
	}
}

void HMI_Mixer() {
	ENCODER_DiffState encoder_diffState = get_encoder_state();
	if (encoder_diffState == ENCODER_DIFF_NO) return;

	// Avoid flicker by updating only the previous menu
	if (encoder_diffState == ENCODER_DIFF_CW) {
		if (DwinMenu_mixer.inc(MIXER_CASE_END)) Move_Highlight(1, DwinMenu_mixer.now);
	}
	else if (encoder_diffState == ENCODER_DIFF_CCW) {
		if (DwinMenu_mixer.dec()) Move_Highlight(-1, DwinMenu_mixer.now);
	}
	else if (encoder_diffState == ENCODER_DIFF_ENTER){
		switch (DwinMenu_mixer.now){
			case 0: 																// Back
			if(IS_SD_PRINTING() || IS_SD_PAUSED() || IS_SD_FILE_OPEN()){
				HMI_flag.show_mode = SHOWED_TUNE;				
				Draw_Tune_Menu(TUNE_CASE_MIXER);
			}
			else{
				Draw_Control_Menu(CONTROL_CASE_MIXER);				
			}
			break;

			case MIXER_CASE_MANUAL: 	// Manual mix
				DwinMenuID = DWMENU_MIXER_MANUAL;				
				HMI_Value.current_vtool= mixer.selected_vtool;
				mixer.update_mix_from_vtool();
				MIXER_STEPPER_LOOP(i) {HMI_Value.mix_percent[i] = mixer.percentmix[i];}
				DwinMenu_manualmix.reset();
				Draw_Mixer_Manual_Menu();
			break;

			case MIXER_CASE_GRADIENT:  	// Gradient mix
				DwinMenuID = DWMENU_MIXER_GRADIENT;				
				mixer.selected_vtool = mixer.gradient.start_vtool;
				mixer.update_mix_from_vtool();
				DwinMenu_GradientMix.reset();
				Draw_Mixer_Gradient_Menu();
			break;

			case MIXER_CASE_RANDOM: 	// Random  mix
				DwinMenuID = DWMENU_MIXER_RANDOM;
				DwinMenu_RandomMix.reset();
				Draw_Mixer_Random_Menu();
			break;

			case MIXER_CASE_VTOOL: 	// vtool
				DwinMenuID = DWMENU_MIXER_VTOOL;
				DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(MIXER_CASE_VTOOL), mixer.selected_vtool);
				EncoderRate.enabled = true;
			break;

			default: break;
		}
	}
	dwinLCD.UpdateLCD();
}

#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Control >> Configure
//
#if ENABLED(FWRETRACT) 
static void Item_Config_Retract(const uint8_t row) {
	DWIN_Draw_MaskString_Default(LBLX, MBASE(row), PSTR("Auto Retract"));
	Draw_Menu_Line(row,ICON_CURSOR);
	Draw_More_Icon(row);
}
#endif

#if ENABLED(FILAMENT_RUNOUT_SENSOR)
static void Item_Config_Filament(const uint8_t row) {
	DWIN_Draw_MaskString_Default(LBLX, MBASE(row), PSTR("Runout Sensor:"));
	Draw_Menu_Line(row,ICON_CURSOR);	
	DWIN_Draw_MaskString_Default(MENUONOFF_X, MBASE(row), F_STRING_ONOFF(runout.enabled));	
}
#endif

#if ENABLED(POWER_LOSS_RECOVERY)
static void Item_Config_Powerloss(const uint8_t row) {
	DWIN_Draw_MaskString_Default(LBLX, MBASE(row), PSTR("PowerLossRecovery:"));
	Draw_Menu_Line(row,ICON_CURSOR);
	DWIN_Draw_MaskString_Default(MENUONOFF_X, MBASE(row), F_STRING_ONOFF(recovery.enabled));	
}
#endif

#if ENABLED(OPTION_AUTOPOWEROFF)
static void Item_Config_Shutdown(const uint8_t row) {
	DWIN_Draw_MaskString_Default(LBLX, MBASE(row), PSTR("Auto Shutdown:"));
	Draw_Menu_Line(row,ICON_CURSOR);
	DWIN_Draw_MaskString_Default(MENUONOFF_X, MBASE(row), F_STRING_ONOFF(HMI_flag.Autoshutdown_enabled));
}
#endif

#if ENABLED(OPTION_WIFI_MODULE)
static void Item_Config_Wifi(const uint8_t row) {
 DWIN_Draw_MaskString_Default(LBLX, MBASE(row),PSTR("Wifi:"));
 Draw_Menu_Line(row,ICON_CURSOR);
 DWIN_Draw_MaskString_Default(MENUONOFF_X, MBASE(row), F_STRING_ONOFF(WiFi_Enabled)); 
}

#if ENABLED(OPTION_WIFI_BAUDRATE)
static void Item_Config_WifiBaudrate(const uint8_t row) {
 DWIN_Draw_MaskString_Default(LBLX, MBASE(row),PSTR("Wifi BaudRate:"));
 Draw_Menu_Line(row,ICON_CURSOR);
 DWIN_Draw_IntValue_Default(6, MENUVALUE_X-24, MBASE(row), Table_Baudrate[WiFi_BaudRate]);
}
#endif
#endif


#if ENABLED(OPTION_BED_COATING)
static void Item_Config_bedcoating(const uint8_t row) { 
	HMI_Value.coating_thickness = (int16_t)(coating_thickness * MINUNITMULT);
	DWIN_Draw_MaskString_Default(LBLX, MBASE(row), PSTR("HOME Z OFFSET:"));
	DWIN_Draw_Small_Float21(MENUVALUE_X-8, MBASE(row), HMI_Value.coating_thickness);
	Draw_Menu_Line(row,ICON_CURSOR);
}
#endif

#if ABL_GRID
static void Item_Config_Leveling(const uint8_t row) {
	DWIN_Draw_MaskString_Default(LBLX, MBASE(row), PSTR("Auto Leveling:"));
	DWIN_Draw_MaskString_Default(MENUONOFF_X, MBASE(row),F_STRING_ONOFF(HMI_flag.Leveling_Menu_Fg));	
	Draw_Menu_Line(row,ICON_CURSOR);
}

static void Item_Config_ActiveLevel(const uint8_t row) {
	DWIN_Draw_MaskString_Default(LBLX, MBASE(row), PSTR("Active Autolevel:"));
	DWIN_Draw_MaskString_Default(MENUONOFF_X, MBASE(row), F_STRING_ONOFF(planner.leveling_active));		
	Draw_Menu_Line(row,ICON_CURSOR);
}
#endif

void Draw_Config_Menu(const uint8_t MenuItem) {	
	DwinMenuID = DWMENU_CONFIG;
	DwinMenu_configure.set(MenuItem);
	DwinMenu_configure.index = _MAX(DwinMenu_configure.now, MROWS);

#if CONFIG_CASE_TOTAL > MROWS
	const int16_t scroll = MROWS - DwinMenu_configure.index;
	#define COSCROL(L) (scroll + (L))
#else
	#define COSCROL(L) (L)
#endif
	#define COVISI(L) WITHIN(COSCROL(L), 0, MROWS)

	Clear_Dwin_Area(AREA_TITAL|AREA_MENU|AREA_STATUS);	
	DWIN_Show_MultiLanguage_String(MTSTRING_CONFIG, TITLE_X, TITLE_Y);

	if (COVISI(CONFIG_CASE_BACK)) Draw_Back_First(DwinMenu_configure.now == CONFIG_CASE_BACK);  // < Back 

	#if ENABLED(FWRETRACT) 
	if (COVISI(CONFIG_CASE_RETRACT)) 	Item_Config_Retract(COSCROL(CONFIG_CASE_RETRACT));   			// Retract >
	#endif 

	#if ENABLED(FILAMENT_RUNOUT_SENSOR) 
	if (COVISI(CONFIG_CASE_FILAMENT)) Item_Config_Filament(COSCROL(CONFIG_CASE_FILAMENT));  		// filament runout
	#endif 

	#if ENABLED(POWER_LOSS_RECOVERY) 
	if (COVISI(CONFIG_CASE_POWERLOSS)) Item_Config_Powerloss(COSCROL(CONFIG_CASE_POWERLOSS));  // powerloss
	#endif

	#if ENABLED(OPTION_AUTOPOWEROFF) 
	if (COVISI(CONFIG_CASE_SHUTDOWN)) Item_Config_Shutdown(COSCROL(CONFIG_CASE_SHUTDOWN));  	 // shutdown
	#endif
	
 	if(!IS_SD_PRINTING() && !IS_SD_PAUSED()){
	 #if ENABLED(OPTION_WIFI_MODULE) 
	 if (COVISI(CONFIG_CASE_WIFI)) 	Item_Config_Wifi(COSCROL(CONFIG_CASE_WIFI));  	 							// WIFI
	 #if ENABLED(OPTION_WIFI_BAUDRATE)
	 if (COVISI(CONFIG_CASE_WIFISPEED)) Item_Config_WifiBaudrate(COSCROL(CONFIG_CASE_WIFISPEED));// WIFI Baudrate
	 #endif
	 #endif

	 #if ENABLED(OPTION_REPEAT_PRINTING) 
	 if (COVISI(CONFIG_CASE_REPRINT)) 	Item_Config_Reprint(COSCROL(CONFIG_CASE_REPRINT));  	 	// repeat print
	 #endif

	 #if ENABLED(OPTION_BED_COATING) 
	 if (COVISI(CONFIG_CASE_COATING)) 	Item_Config_bedcoating(COSCROL(CONFIG_CASE_COATING));  	 	// GLASS LEVELING
	 #endif

	 #if ABL_GRID 		
	 if (COVISI(CONFIG_CASE_LEVELING)) Item_Config_Leveling(COSCROL(CONFIG_CASE_LEVELING));  	 			// auto LEVELING
	 if (COVISI(CONFIG_CASE_ACTIVELEVEL)) Item_Config_ActiveLevel(COSCROL(CONFIG_CASE_ACTIVELEVEL)); // auto LEVELING
	 #endif	 
 }
 if (DwinMenu_configure.now) Draw_Menu_Cursor(COSCROL(DwinMenu_configure.now));
 Draw_Status_Area();
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//
// Control >> Config >> Auto retraction
//
#if ENABLED(FWRETRACT) 
static void Item_Retract_Retract_Enabled(const uint8_t row) {
	DWIN_Draw_MaskString_Default(LBLX, MBASE(row), PSTR("Auto-Retract:"));
	DWIN_Draw_MaskString_Default(MENUONOFF_X, MBASE(row), F_STRING_ONOFF(fwretract.autoretract_enabled));
	Draw_Menu_Line(row,ICON_CURSOR);
}

static void Item_Retract_Retract_mm(const uint8_t row) {
	DWIN_Draw_MaskString_Default(LBLX, MBASE(row), PSTR("Retract MM:"));
	DWIN_Draw_Small_Float22(MENUVALUE_X, MBASE(row), fwretract.settings.retract_length*MAXUNITMULT);
	Draw_Menu_Line(row,ICON_CURSOR);
}

static void Item_Retract_Retract_V(const uint8_t row) {
	DWIN_Draw_MaskString_Default(LBLX, MBASE(row), PSTR("Retract V:"));
	DWIN_Draw_Small_Float32(MENUVALUE_X-8, MBASE(row), fwretract.settings.retract_feedrate_mm_s*MAXUNITMULT);
	Draw_Menu_Line(row,ICON_CURSOR);
}

static void Item_Retract_Retract_ZHop(const uint8_t row) {
	DWIN_Draw_MaskString_Default(LBLX, MBASE(row), PSTR("Retract ZHop:"));
	 DWIN_Draw_Small_Float31(MENUVALUE_X, MBASE(row), fwretract.settings.retract_zraise*MINUNITMULT);
	Draw_Menu_Line(row,ICON_CURSOR);
}

static void Item_Retract_UnRetract_mm(const uint8_t row) {
	DWIN_Draw_MaskString_Default(LBLX, MBASE(row), PSTR("UnRetract MM:"));
	DWIN_Draw_Small_Float22(MENUVALUE_X, MBASE(row), fwretract.settings.retract_recover_extra*MAXUNITMULT);
	Draw_Menu_Line(row,ICON_CURSOR);
}

static void Item_Retract_UnRetract_V(const uint8_t row) {
	DWIN_Draw_MaskString_Default(LBLX, MBASE(row), PSTR("UnRetract V:"));
	DWIN_Draw_Small_Float32(MENUVALUE_X-8, MBASE(row), fwretract.settings.retract_recover_feedrate_mm_s*MAXUNITMULT);
	Draw_Menu_Line(row,ICON_CURSOR);
}

inline void Draw_Retract_Menu() {
	Clear_Dwin_Area(AREA_TITAL|AREA_MENU);
	DwinMenu_fwretract.reset();
	//DwinMenu_fwretract.index = _MAX(DwinMenu_fwretract.now, MROWS);

#if CONFIG_CASE_TOTAL > MROWS
	const int16_t scroll = MROWS - DwinMenu_fwretract.index;
	#define RESCROL(L) (scroll + (L))
#else
	#define RESCROL(L) (L)
#endif
	#define REVISI(L) WITHIN(RESCROL(L), 0, MROWS)
	
	//title
	DWIN_Draw_UnMaskString_Default(14, 7, PSTR("Retract")); 
	if (REVISI(RETRACT_CASE_BACK)) Draw_Back_First(DwinMenu_fwretract.now == RETRACT_CASE_BACK);
	
	if (REVISI(RETRACT_CASE_AUTO)) Item_Retract_Retract_Enabled(RESCROL(RETRACT_CASE_AUTO));
	if (REVISI(RETRACT_CASE_RETRACT_MM)) Item_Retract_Retract_mm(RESCROL(RETRACT_CASE_RETRACT_MM));
	if (REVISI(RETRACT_CASE_RETRACT_V)) Item_Retract_Retract_V(RESCROL(RETRACT_CASE_RETRACT_V));
	if (REVISI(RETRACT_CASE_RETRACT_ZHOP)) Item_Retract_Retract_ZHop(RESCROL(RETRACT_CASE_RETRACT_ZHOP));
	if (REVISI(RETRACT_CASE_RECOVER_MM)) Item_Retract_UnRetract_mm(RESCROL(RETRACT_CASE_RECOVER_MM));
	if (REVISI(RETRACT_CASE_RECOVER_V)) Item_Retract_UnRetract_V(RESCROL(RETRACT_CASE_RECOVER_V));
	
	if (DwinMenu_fwretract.now) Draw_Menu_Cursor(RESCROL(DwinMenu_fwretract.now));
}

char Retract_Buf[50]={0};
void HMI_Retract_MM() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.Retract_MM_scale)) {
			DwinMenuID = DWMENU_SET_RETRACT;
			EncoderRate.enabled = false;
			DWIN_Draw_Small_Float22(MENUVALUE_X, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RETRACT_MM), HMI_Value.Retract_MM_scale);
			ZERO(Retract_Buf);
			sprintf_P(Retract_Buf,PSTR("M207 S%.2f"),(fwretract.settings.retract_length));
			queue.inject(Retract_Buf);
			dwinLCD.UpdateLCD();			
			return;
		}
		NOLESS(HMI_Value.Retract_MM_scale, 0);
		NOMORE(HMI_Value.Retract_MM_scale, 100*MAXUNITMULT);
		fwretract.settings.retract_length = (float)HMI_Value.Retract_MM_scale/MAXUNITMULT;
		DWIN_Draw_Selected_Small_Float22(MENUVALUE_X, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RETRACT_MM), HMI_Value.Retract_MM_scale);
		dwinLCD.UpdateLCD();
	}
}

void HMI_Retract_V() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.Retract_V_scale)) {
			DwinMenuID = DWMENU_SET_RETRACT;
			EncoderRate.enabled = false;
			DWIN_Draw_Small_Float32(MENUVALUE_X-8, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RETRACT_V), HMI_Value.Retract_V_scale);
			ZERO(Retract_Buf);
			sprintf_P(Retract_Buf,PSTR("M207 F%.2f"),(MMS_TO_MMM(fwretract.settings.retract_feedrate_mm_s)));
			queue.inject(Retract_Buf);
			dwinLCD.UpdateLCD();
			return;
		}
		NOLESS(HMI_Value.Retract_V_scale, 0);
		NOMORE(HMI_Value.Retract_V_scale, 100*MAXUNITMULT);
		fwretract.settings.retract_feedrate_mm_s = (float)HMI_Value.Retract_V_scale/MAXUNITMULT;
		DWIN_Draw_Selected_Small_Float32(MENUVALUE_X-8, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RETRACT_V), HMI_Value.Retract_V_scale);
		dwinLCD.UpdateLCD();
	}
}

void HMI_Retract_ZHOP() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.Retract_ZHOP_scale)) {
			DwinMenuID = DWMENU_SET_RETRACT;
			EncoderRate.enabled = false;
			DWIN_Draw_Small_Float32(MENUVALUE_X-8, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RETRACT_ZHOP), HMI_Value.Retract_ZHOP_scale);
			ZERO(Retract_Buf);
			sprintf_P(Retract_Buf,PSTR("M207 Z%.2f"), fwretract.settings.retract_zraise);
			queue.inject(Retract_Buf);
			dwinLCD.UpdateLCD();			
			return;
		}
		NOLESS(HMI_Value.Retract_ZHOP_scale, 0);
		NOMORE(HMI_Value.Retract_ZHOP_scale, 10*MAXUNITMULT);
		fwretract.settings.retract_zraise = (float)HMI_Value.Retract_ZHOP_scale/MAXUNITMULT;
		DWIN_Draw_Selected_Small_Float32(MENUVALUE_X-8, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RETRACT_ZHOP), HMI_Value.Retract_ZHOP_scale);
		dwinLCD.UpdateLCD();
	}
}

void HMI_UnRetract_MM() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.unRetract_MM_scale)) {
			DwinMenuID = DWMENU_SET_RETRACT;
			EncoderRate.enabled = false;
			DWIN_Draw_Small_Float22(MENUVALUE_X, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RECOVER_MM), HMI_Value.unRetract_MM_scale);
			ZERO(Retract_Buf);
			sprintf_P(Retract_Buf,PSTR("M208 S%.2f"),(fwretract.settings.retract_recover_extra));
			queue.inject(Retract_Buf);
			dwinLCD.UpdateLCD();			
			return;
		}
		NOLESS(HMI_Value.unRetract_MM_scale, 0);
		NOMORE(HMI_Value.unRetract_MM_scale, 100*MAXUNITMULT);
		fwretract.settings.retract_recover_extra = (float)HMI_Value.unRetract_MM_scale/MAXUNITMULT;
		DWIN_Draw_Selected_Small_Float22(MENUVALUE_X, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RECOVER_MM), HMI_Value.unRetract_MM_scale);
		dwinLCD.UpdateLCD();
	}
}

void HMI_UnRetract_V() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.unRetract_V_scale)) {
			DwinMenuID = DWMENU_SET_RETRACT;
			EncoderRate.enabled = false;
			DWIN_Draw_Small_Float32(MENUVALUE_X-8, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RECOVER_V), HMI_Value.unRetract_V_scale);
			ZERO(Retract_Buf);
			sprintf_P(Retract_Buf,PSTR("M208 F%.2f"),(MMS_TO_MMM(fwretract.settings.retract_recover_feedrate_mm_s)));
			queue.inject(Retract_Buf);
			dwinLCD.UpdateLCD();			
			return;
		}
		NOLESS(HMI_Value.unRetract_V_scale, 0);
		NOMORE(HMI_Value.unRetract_V_scale, 100*MAXUNITMULT);
		fwretract.settings.retract_recover_feedrate_mm_s = (float)HMI_Value.unRetract_V_scale/MAXUNITMULT;
		DWIN_Draw_Selected_Small_Float32(MENUVALUE_X-8, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RECOVER_V), HMI_Value.unRetract_V_scale);
		dwinLCD.UpdateLCD();
	}
}

void HMI_Retract() {
	ENCODER_DiffState encoder_diffState = get_encoder_state();
	if (encoder_diffState == ENCODER_DIFF_NO) return;

	 // Avoid flicker by updating only the previous menu
	if (encoder_diffState == ENCODER_DIFF_CW) {
		if (DwinMenu_fwretract.inc(RETRACT_CASE_END)) {
			if (DwinMenu_fwretract.now > MROWS && DwinMenu_fwretract.now > DwinMenu_fwretract.index) {				
				// Scroll up and draw a blank bottom line
				DwinMenu_fwretract.index = DwinMenu_fwretract.now;
				Scroll_Menu(DWIN_SCROLL_UP);
				if(DwinMenu_configure.index == RETRACT_CASE_AUTO) Item_Retract_Retract_Enabled(MROWS);
				else if(DwinMenu_configure.index == RETRACT_CASE_RETRACT_MM) Item_Retract_Retract_mm(MROWS);
				else if(DwinMenu_configure.index == RETRACT_CASE_RETRACT_V) Item_Retract_Retract_V(MROWS);
				else if(DwinMenu_configure.index == RETRACT_CASE_RETRACT_ZHOP) Item_Retract_Retract_ZHop(MROWS);
				else if(DwinMenu_configure.index == RETRACT_CASE_RECOVER_MM) Item_Retract_UnRetract_mm(MROWS);
				else if(DwinMenu_configure.index == RETRACT_CASE_RECOVER_V) Item_Retract_UnRetract_V(MROWS);
			}
			else {
				Move_Highlight(1, DwinMenu_fwretract.now + MROWS - DwinMenu_fwretract.index);
			}
		}
	}
	else if (encoder_diffState == ENCODER_DIFF_CCW) {
		if (DwinMenu_fwretract.dec()) {
			if (DwinMenu_fwretract.now < DwinMenu_fwretract.index - MROWS) {
				DwinMenu_fwretract.index--;
				Scroll_Menu(DWIN_SCROLL_DOWN);
				if(DwinMenu_configure.index - MROWS == RETRACT_CASE_BACK) Draw_Back_First();
				else if(DwinMenu_configure.index - MROWS == RETRACT_CASE_AUTO) Item_Retract_Retract_Enabled(MROWS);
				else if(DwinMenu_configure.index - MROWS == RETRACT_CASE_RETRACT_MM) Item_Retract_Retract_mm(MROWS);
				else if(DwinMenu_configure.index - MROWS == RETRACT_CASE_RETRACT_V) Item_Retract_Retract_V(MROWS);
				else if(DwinMenu_configure.index - MROWS == RETRACT_CASE_RETRACT_ZHOP) Item_Retract_Retract_ZHop(MROWS);
				else if(DwinMenu_configure.index - MROWS == RETRACT_CASE_RECOVER_MM) Item_Retract_UnRetract_mm(MROWS);
				else if(DwinMenu_configure.index - MROWS == RETRACT_CASE_RECOVER_V) Item_Retract_UnRetract_V(MROWS);
			}
			else {
				Move_Highlight(-1, DwinMenu_fwretract.now + MROWS - DwinMenu_fwretract.index);
			}
		}
	}
	else if (encoder_diffState == ENCODER_DIFF_ENTER) {
		switch (DwinMenu_fwretract.now) {
			case 0: 									// Back				
				Draw_Config_Menu(CONFIG_CASE_RETRACT);
			break;

			case RETRACT_CASE_AUTO: 					// auto
				DwinMenuID = DWMENU_SET_RETRACT;
				fwretract.autoretract_enabled = !fwretract.autoretract_enabled;
				DWIN_Draw_MaskString_Default(MENUONOFF_X, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_AUTO), F_STRING_ONOFF(fwretract.autoretract_enabled));
				if(fwretract.autoretract_enabled)
					queue.inject_P(PSTR("M209 S1"));
				else
					queue.inject_P(PSTR("M209 S0"));
			break;
	 
			case RETRACT_CASE_RETRACT_MM:  			// RETRACT_MM
				DwinMenuID = DWMENU_SET_RETRACT_MM;
				HMI_Value.Retract_MM_scale = fwretract.settings.retract_length*MAXUNITMULT;
				DWIN_Draw_Selected_Small_Float22(MENUVALUE_X, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RETRACT_MM), HMI_Value.Retract_MM_scale);
				EncoderRate.enabled = true;
			break;

			case RETRACT_CASE_RETRACT_V:  			// RETRACT_V
				DwinMenuID = DWMENU_SET_RETRACT_V;
				HMI_Value.Retract_V_scale = fwretract.settings.retract_feedrate_mm_s*MAXUNITMULT;
				DWIN_Draw_Selected_Small_Float32(MENUVALUE_X-8, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RETRACT_V), HMI_Value.Retract_V_scale);
				EncoderRate.enabled = true;
			break;

			case RETRACT_CASE_RETRACT_ZHOP:  			// RETRACT_ZHOP
				DwinMenuID = DWMENU_SET_RETRACT_ZHOP;
				HMI_Value.Retract_ZHOP_scale = fwretract.settings.retract_zraise*MAXUNITMULT;
				DWIN_Draw_Selected_Small_Float32(MENUVALUE_X-8, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RETRACT_ZHOP), HMI_Value.Retract_ZHOP_scale);
				EncoderRate.enabled = true;
			break;

			case RETRACT_CASE_RECOVER_MM:  			// RECOVER_MM
				DwinMenuID = DWMENU_SET_UNRETRACT_MM;
				HMI_Value.unRetract_MM_scale = fwretract.settings.retract_recover_extra*MAXUNITMULT;
				DWIN_Draw_Selected_Small_Float22(MENUVALUE_X, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RECOVER_MM), HMI_Value.unRetract_MM_scale);
				EncoderRate.enabled = true;
			break;

			case RETRACT_CASE_RECOVER_V:  			// RECOVER_V
				DwinMenuID = DWMENU_SET_UNRETRACT_V;
				HMI_Value.unRetract_V_scale = fwretract.settings.retract_recover_feedrate_mm_s*MAXUNITMULT;
				DWIN_Draw_Selected_Small_Float32(MENUVALUE_X-8, MBASE(MROWS -DwinMenu_fwretract.index + RETRACT_CASE_RECOVER_V), HMI_Value.unRetract_V_scale);
				EncoderRate.enabled = true;
			break;
   
   default: break;
  }
 }
 dwinLCD.UpdateLCD();
}
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Control >> Motion
//
static void Item_Motion_Feedrate(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXSPEED);
	DWIN_Show_MultiLanguage_String(MOTION_MENU_FEEDRATE, LBLX, MBASE(row));
	Draw_More_Icon(row);
}

static void Item_Motion_Accel(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXACCELERATED);
	DWIN_Show_MultiLanguage_String(MOTION_MENU_ACC, LBLX, MBASE(row));
	Draw_More_Icon(row);
}

static void Item_Motion_Jerk(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXJERK);
	DWIN_Show_MultiLanguage_String(MOTION_MENU_JERK, LBLX, MBASE(row));
	Draw_More_Icon(row);
}

static void Item_Motion_Steps(uint8_t row){
	Draw_Menu_Line(row, ICON_STEP);
	DWIN_Show_MultiLanguage_String(MOTION_MENU_STEPS, LBLX, MBASE(row));
	Draw_More_Icon(row);
}

static void Draw_Motion_Menu(const uint8_t MenuItem = 0) {
	DwinMenuID = DWMENU_MOTION;
	DwinMenu_motion.set(MenuItem);
  DwinMenu_motion.index = _MAX(DwinMenu_motion.now, MROWS);
	 
	Clear_Dwin_Area(AREA_TITAL|AREA_MENU);

	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_MOTION, TITLE_X, TITLE_Y);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);
	Draw_Back_First(DwinMenu_motion.now == MOTION_CASE_BACK);
	
	Item_Motion_Feedrate(MOTION_CASE_FEEDRATE);
	Item_Motion_Accel(MOTION_CASE_ACCEL);
	Item_Motion_Jerk(MOTION_CASE_JERK);
	Item_Motion_Steps(MOTION_CASE_STEPS);	
	if (DwinMenu_motion.now) Draw_Menu_Cursor(DwinMenu_motion.now);
}

///////////////////////////////////////////////
//
// Control >> Motion >> Feedrate
//
static void Item_Feedrate_MaxX(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXSPEEDX);
	DWIN_Show_MultiLanguage_String(FEEDRATE_MENU_MAX, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(FEEDRATE_MENU_FEEDRATE, LBLX+GET_ICON_X(MAX), MBASE(row));
	DWIN_Show_MultiLanguage_String(MTSTRING_X, LBLX+GET_ICON_X(MAX)+GET_ICON_X(FEEDRATE), MBASE(row));	
	DWIN_Draw_IntValue_Default(4,CONFIGVALUE_X, MBASE(row), planner.settings.max_feedrate_mm_s[X_AXIS]);
}

static void Item_Feedrate_MaxY(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXSPEEDY);
	DWIN_Show_MultiLanguage_String(FEEDRATE_MENU_MAX, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(FEEDRATE_MENU_FEEDRATE, LBLX+GET_ICON_X(MAX), MBASE(row));
	DWIN_Show_MultiLanguage_String(MTSTRING_Y, LBLX+GET_ICON_X(MAX)+GET_ICON_X(FEEDRATE), MBASE(row));	
	DWIN_Draw_IntValue_Default(4,CONFIGVALUE_X, MBASE(row), planner.settings.max_feedrate_mm_s[Y_AXIS]);
}

static void Item_Feedrate_MaxZ(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXSPEEDZ);
	DWIN_Show_MultiLanguage_String(FEEDRATE_MENU_MAX, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(FEEDRATE_MENU_FEEDRATE, LBLX+GET_ICON_X(MAX), MBASE(row));
	DWIN_Show_MultiLanguage_String(MTSTRING_Z, LBLX+GET_ICON_X(MAX)+GET_ICON_X(FEEDRATE), MBASE(row));	
	DWIN_Draw_IntValue_Default(4,CONFIGVALUE_X, MBASE(row), planner.settings.max_feedrate_mm_s[Z_AXIS]);
}

static void Item_Feedrate_MaxE(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXSPEEDE);
	DWIN_Show_MultiLanguage_String(FEEDRATE_MENU_MAX, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(FEEDRATE_MENU_FEEDRATE, LBLX+GET_ICON_X(MAX), MBASE(row));
	DWIN_Show_MultiLanguage_String(FEEDRATE_MENU_E, LBLX+GET_ICON_X(MAX)+GET_ICON_X(FEEDRATE), MBASE(row));	
	DWIN_Draw_IntValue_Default(4,CONFIGVALUE_X, MBASE(row), planner.settings.max_feedrate_mm_s[E_AXIS]);
}

inline void Draw_Max_Speed_Menu() {
	Clear_Dwin_Area(AREA_TITAL|AREA_MENU);
	DwinMenu_feedrate.reset();

	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_FEEDRATE, TITLE_X, TITLE_Y);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);
	Draw_Back_First(DwinMenu_feedrate.now == MAXFEEDRATE_CASE_BACK);	
	Item_Feedrate_MaxX(MAXFEEDRATE_CASE_X);
	Item_Feedrate_MaxY(MAXFEEDRATE_CASE_Y);
	Item_Feedrate_MaxZ(MAXFEEDRATE_CASE_Z);
	Item_Feedrate_MaxE(MAXFEEDRATE_CASE_E);
	if (DwinMenu_feedrate.now) Draw_Menu_Cursor(DwinMenu_feedrate.now);
}
/* Max Speed */
void HMI_MaxSpeed() {
 ENCODER_DiffState encoder_diffState = get_encoder_state();
 if (encoder_diffState == ENCODER_DIFF_NO) return;

 // Avoid flicker by updating only the previous menu
 if (encoder_diffState == ENCODER_DIFF_CW) {
  if (DwinMenu_feedrate.inc(MAXFEEDRATE_CASE_END)) Move_Highlight(1, DwinMenu_feedrate.now);
 }
 else if (encoder_diffState == ENCODER_DIFF_CCW) {
  if (DwinMenu_feedrate.dec()) Move_Highlight(-1, DwinMenu_feedrate.now);
 }
 else if (encoder_diffState == ENCODER_DIFF_ENTER) {
  if (WITHIN(DwinMenu_feedrate.now, MAXFEEDRATE_CASE_X, MAXFEEDRATE_CASE_E)) {
   DwinMenuID = DWMENU_SET_MAXSPEED_VALUE;
   HMI_flag.axis = AxisEnum(DwinMenu_feedrate.now - 1);
   HMI_Value.Max_Feedspeed = planner.settings.max_feedrate_mm_s[HMI_flag.axis];
   DWIN_Draw_Select_IntValue_Default(3, CONFIGVALUE_X+8, MBASE(DwinMenu_feedrate.now), HMI_Value.Max_Feedspeed);
   EncoderRate.enabled = true;
  }
  else { // Back   
   Draw_Motion_Menu(MOTION_CASE_FEEDRATE);
  }
 }
 dwinLCD.UpdateLCD();
}


constexpr float default_max_feedrate[]    = DEFAULT_MAX_FEEDRATE;
constexpr float default_max_acceleration[]  = DEFAULT_MAX_ACCELERATION;
constexpr float default_max_jerk[]      = { DEFAULT_XJERK, DEFAULT_YJERK, DEFAULT_ZJERK, DEFAULT_EJERK };
constexpr float default_axis_steps_per_unit[] = DEFAULT_AXIS_STEPS_PER_UNIT;
// Feedspeed limit (max feedspeed = DEFAULT_MAX_FEEDRATE * 2)
#define MIN_MAXFEEDSPEED      1
#define MIN_MAXACCELERATION   10
#define MIN_MAXJERK           0.1
#define MIN_STEP              1

void HMI_MaxFeedspeedXYZE() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.Max_Feedspeed)) {
			DwinMenuID = DWMENU_SET_MAXSPEED;
			EncoderRate.enabled = false;
			if (WITHIN(HMI_flag.axis, X_AXIS, E_AXIS))
				planner.set_max_feedrate(HMI_flag.axis, HMI_Value.Max_Feedspeed);
			DWIN_Draw_IntValue_Default(3, CONFIGVALUE_X+8, MBASE(DwinMenu_feedrate.now), HMI_Value.Max_Feedspeed);
			return;
		}
		// MaxFeedspeed limit
		if (WITHIN(HMI_flag.axis, X_AXIS, E_AXIS))
			NOMORE(HMI_Value.Max_Feedspeed, default_max_feedrate[HMI_flag.axis]*2);
		if (HMI_Value.Max_Feedspeed < MIN_MAXFEEDSPEED) 
			HMI_Value.Max_Feedspeed = MIN_MAXFEEDSPEED;
		// MaxFeedspeed value
		DWIN_Draw_Select_IntValue_Default(3, CONFIGVALUE_X+8, MBASE(DwinMenu_feedrate.now), HMI_Value.Max_Feedspeed);
	}
}

///////////////////////////////////////////////
//
// Control >> Motion >> Acceleration
//
inline void Item_Accel_MaxX(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXACCX);
	DWIN_Show_MultiLanguage_String(ACCEL_MENU_MAX, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(ACCEL_MENU_ACCEL, LBLX+GET_ICON_X(MAX), MBASE(row));
	DWIN_Show_MultiLanguage_String(ACCEL_MENU_X, LBLX+GET_ICON_X(MAX)+GET_ICON_X(ACCEL)+6, MBASE(row));	
	DWIN_Draw_IntValue_Default(4,CONFIGVALUE_X, MBASE(row), planner.settings.max_acceleration_mm_per_s2[X_AXIS]);
}

inline void Item_Accel_MaxY(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXACCY);
	DWIN_Show_MultiLanguage_String(ACCEL_MENU_MAX, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(ACCEL_MENU_ACCEL, LBLX+GET_ICON_X(MAX), MBASE(row));
	DWIN_Show_MultiLanguage_String(ACCEL_MENU_Y, LBLX+GET_ICON_X(MAX)+GET_ICON_X(ACCEL)+6, MBASE(row));	
	DWIN_Draw_IntValue_Default(4,CONFIGVALUE_X, MBASE(row), planner.settings.max_acceleration_mm_per_s2[Y_AXIS]);
}

inline void Item_Accel_MaxZ(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXACCZ);
	DWIN_Show_MultiLanguage_String(ACCEL_MENU_MAX, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(ACCEL_MENU_ACCEL, LBLX+GET_ICON_X(MAX), MBASE(row));
	DWIN_Show_MultiLanguage_String(ACCEL_MENU_Z, LBLX+GET_ICON_X(MAX)+GET_ICON_X(ACCEL)+6, MBASE(row));	
	DWIN_Draw_IntValue_Default(4,CONFIGVALUE_X, MBASE(row), planner.settings.max_acceleration_mm_per_s2[Z_AXIS]);
}

inline void Item_Accel_MaxE(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXACCE);
	DWIN_Show_MultiLanguage_String(ACCEL_MENU_MAX, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(ACCEL_MENU_ACCEL, LBLX+GET_ICON_X(MAX), MBASE(row));
	DWIN_Show_MultiLanguage_String(ACCEL_MENU_E, LBLX+GET_ICON_X(MAX)+GET_ICON_X(ACCEL)+6, MBASE(row));	
	DWIN_Draw_IntValue_Default(5,CONFIGVALUE_X-8, MBASE(row), planner.settings.max_acceleration_mm_per_s2[E_AXIS]);
}

inline void Draw_Max_Accel_Menu() {
	Clear_Dwin_Area(AREA_TITAL|AREA_MENU);
	DwinMenu_accel.reset();
	//DwinMenu_accel.index = _MAX(DwinMenu_accel.now, MROWS);

	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_ACCEL, TITLE_X, TITLE_Y);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);
	Draw_Back_First(DwinMenu_accel.now == 0);
	Item_Accel_MaxX(MAXACCL_CASE_X);
	Item_Accel_MaxY(MAXACCL_CASE_Y);
	Item_Accel_MaxZ(MAXACCL_CASE_Z);
	Item_Accel_MaxE(MAXACCL_CASE_E);
	if (DwinMenu_accel.now) Draw_Menu_Cursor(DwinMenu_accel.now);
}

void HMI_MaxAccelerationXYZE() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.Max_Acceleration)) {
			DwinMenuID = DWMENU_SET_MAXACC;
			EncoderRate.enabled = false;
			if (HMI_flag.axis == X_AXIS) planner.set_max_acceleration(X_AXIS, HMI_Value.Max_Acceleration);
			else if (HMI_flag.axis == Y_AXIS) planner.set_max_acceleration(Y_AXIS, HMI_Value.Max_Acceleration);
			else if (HMI_flag.axis == Z_AXIS) planner.set_max_acceleration(Z_AXIS, HMI_Value.Max_Acceleration);
		#if HAS_HOTEND
			else if (HMI_flag.axis == E_AXIS) planner.set_max_acceleration(E_AXIS, HMI_Value.Max_Acceleration);
		#endif
			DWIN_Draw_IntValue_Default(5, CONFIGVALUE_X-8, MBASE(DwinMenu_accel.now), HMI_Value.Max_Acceleration);
			return;
		}
		// Max Acceleration limit
		if (WITHIN(HMI_flag.axis, X_AXIS, E_AXIS))
			NOMORE(HMI_Value.Max_Acceleration, default_max_acceleration[HMI_flag.axis]*2);
		if (HMI_Value.Max_Acceleration < MIN_MAXACCELERATION) 
			HMI_Value.Max_Acceleration = MIN_MAXACCELERATION;
		// Max Acceleration value
		DWIN_Draw_Select_IntValue_Default(5, CONFIGVALUE_X-8, MBASE(DwinMenu_accel.now), HMI_Value.Max_Acceleration);
	}
}

/* Max Acceleration */
void HMI_MaxAcceleration() {
	ENCODER_DiffState encoder_diffState = get_encoder_state();
	if (encoder_diffState == ENCODER_DIFF_NO) return;

	// Avoid flicker by updating only the previous menu
	if (encoder_diffState == ENCODER_DIFF_CW) {
		if (DwinMenu_accel.inc(MAXACCL_CASE_END)) Move_Highlight(1, DwinMenu_accel.now);
	}
	else if (encoder_diffState == ENCODER_DIFF_CCW) {
		if (DwinMenu_accel.dec()) Move_Highlight(-1, DwinMenu_accel.now);
	}
	else if (encoder_diffState == ENCODER_DIFF_ENTER) {
		if (WITHIN(DwinMenu_accel.now, MAXACCL_CASE_X, MAXACCL_CASE_E)) {
			DwinMenuID = DWMENU_SET_MAXACC_VALUE;
			HMI_flag.axis = AxisEnum(DwinMenu_accel.now - 1);
			HMI_Value.Max_Acceleration = planner.settings.max_acceleration_mm_per_s2[HMI_flag.axis];
			DWIN_Draw_Select_IntValue_Default(5, CONFIGVALUE_X-8, MBASE(DwinMenu_accel.now), HMI_Value.Max_Acceleration);
			EncoderRate.enabled = true;
		}
		else { // Back
			Draw_Motion_Menu(MOTION_CASE_ACCEL);
		}
	}
	dwinLCD.UpdateLCD();
}




///////////////////////////////////////////////
//
// Control >> Motion >> Jerk
//
#if HAS_CLASSIC_JERK
static void Item_Jerk_MaxX(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXSPEEDJERKX);
	DWIN_Show_MultiLanguage_String(JERK_MENU_MAX, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(JERK_MENU_JERK, LBLX+GET_ICON_X(MAX), MBASE(row));
	DWIN_Show_MultiLanguage_String(JERK_MENU_X, LBLX+GET_ICON_X(MAX)+GET_ICON_X(JERK)+6, MBASE(row));	
	DWIN_Draw_Small_Float21(CONFIGVALUE_X+8, MBASE(row), planner.max_jerk[X_AXIS] * MINUNITMULT);
}

static void Item_Jerk_MaxY(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXSPEEDJERKY);
	DWIN_Show_MultiLanguage_String(JERK_MENU_MAX, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(JERK_MENU_JERK, LBLX+GET_ICON_X(MAX), MBASE(row));
	DWIN_Show_MultiLanguage_String(JERK_MENU_Y, LBLX+GET_ICON_X(MAX)+GET_ICON_X(JERK)+6, MBASE(row));	
	DWIN_Draw_Small_Float21(CONFIGVALUE_X+8, MBASE(row), planner.max_jerk[Y_AXIS] * MINUNITMULT);
}

static void Item_Jerk_MaxZ(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXSPEEDJERKZ);
	DWIN_Show_MultiLanguage_String(JERK_MENU_MAX, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(JERK_MENU_JERK, LBLX+GET_ICON_X(MAX), MBASE(row));
	DWIN_Show_MultiLanguage_String(JERK_MENU_Z, LBLX+GET_ICON_X(MAX)+GET_ICON_X(JERK)+6, MBASE(row));	
	DWIN_Draw_Small_Float21(CONFIGVALUE_X+8, MBASE(row), planner.max_jerk[Z_AXIS] * MINUNITMULT);
}

static void Item_Jerk_MaxE(uint8_t row){
	Draw_Menu_Line(row, ICON_MAXSPEEDJERKE);
	DWIN_Show_MultiLanguage_String(JERK_MENU_MAX, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(JERK_MENU_JERK, LBLX+GET_ICON_X(MAX), MBASE(row));
	DWIN_Show_MultiLanguage_String(JERK_MENU_E, LBLX+GET_ICON_X(MAX)+GET_ICON_X(JERK)+6, MBASE(row));	
	DWIN_Draw_Small_Float21(CONFIGVALUE_X+8, MBASE(row), planner.max_jerk[E_AXIS] * MINUNITMULT);
}

inline void Draw_Max_Jerk_Menu() {
	Clear_Dwin_Area(AREA_TITAL|AREA_MENU);
	DwinMenu_jerk.reset();
	//DwinMenu_jerk.index = _MAX(DwinMenu_jerk.now, MROWS);

	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_JERK, TITLE_X, TITLE_Y);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);
	Draw_Back_First(DwinMenu_jerk.now == 0);
	Item_Jerk_MaxX(MAXJERK_CASE_X);
	Item_Jerk_MaxY(MAXJERK_CASE_Y);
	Item_Jerk_MaxZ(MAXJERK_CASE_Z);
	Item_Jerk_MaxE(MAXJERK_CASE_E);
	if (DwinMenu_jerk.now) Draw_Menu_Cursor(DwinMenu_jerk.now); 
}


void HMI_MaxJerkXYZE() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.Max_Jerk)) {
			DwinMenuID = DWMENU_SET_MAXJERK;
			EncoderRate.enabled = false;
			if(WITHIN(HMI_flag.axis, X_AXIS, E_AXIS))
				planner.set_max_jerk(HMI_flag.axis, ((float)HMI_Value.Max_Jerk / MINUNITMULT));
				DWIN_Draw_Small_Float21(CONFIGVALUE_X+8, MBASE(DwinMenu_jerk.now), HMI_Value.Max_Jerk);
				return;
		}
		// Max Jerk limit
		if (WITHIN(HMI_flag.axis, X_AXIS, E_AXIS)){
			NOMORE(HMI_Value.Max_Jerk, default_max_jerk[HMI_flag.axis] * 2 * MINUNITMULT);
			NOLESS(HMI_Value.Max_Jerk, (MIN_MAXJERK) * MINUNITMULT);
		}
		// Max Jerk value
		DWIN_Draw_Selected_Small_Float21(CONFIGVALUE_X+8, MBASE(DwinMenu_jerk.now), HMI_Value.Max_Jerk);
	}
}

 /* Max Jerk */
void HMI_MaxJerk() {
	ENCODER_DiffState encoder_diffState = get_encoder_state();
	if (encoder_diffState == ENCODER_DIFF_NO) return;

	// Avoid flicker by updating only the previous menu
	if (encoder_diffState == ENCODER_DIFF_CW) {
		if (DwinMenu_jerk.inc(MAXJERK_CASE_END)) Move_Highlight(1, DwinMenu_jerk.now);
	}
	else if (encoder_diffState == ENCODER_DIFF_CCW) {
		if (DwinMenu_jerk.dec()) Move_Highlight(-1, DwinMenu_jerk.now);
	}
	else if (encoder_diffState == ENCODER_DIFF_ENTER) {
		if (WITHIN(DwinMenu_jerk.now, 1, 4)) {
			DwinMenuID = DWMENU_SET_MAXJERK_VALUE;
			HMI_flag.axis = AxisEnum(DwinMenu_jerk.now - 1);
			HMI_Value.Max_Jerk = planner.max_jerk[HMI_flag.axis] * MINUNITMULT;
			DWIN_Draw_Selected_Small_Float21(CONFIGVALUE_X+8, MBASE(DwinMenu_jerk.now), HMI_Value.Max_Jerk);
			EncoderRate.enabled = true;
		}
		else { // Back 
			Draw_Motion_Menu(MOTION_CASE_JERK);
		}
	}
	dwinLCD.UpdateLCD();
}
#endif // HAS_CLASSIC_JERK

///////////////////////////////////////////////
//
// Control >> Motion >> Step/mm
//
static void Item_Steps_X(uint8_t row){
	Draw_Menu_Line(row, ICON_STEPX);
	DWIN_Show_MultiLanguage_String(STEP_MENU_STEP, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(STEP_MENU_X, LBLX+GET_ICON_X(STEP)+6, MBASE(row));
	DWIN_Draw_Small_Float41(CONFIGVALUE_X-8, MBASE(row), planner.settings.axis_steps_per_mm[X_AXIS] * MINUNITMULT);
}

static void Item_Steps_Y(uint8_t row){
	Draw_Menu_Line(row, ICON_STEPY);
	DWIN_Show_MultiLanguage_String(STEP_MENU_STEP, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(STEP_MENU_Y, LBLX+GET_ICON_X(STEP)+6, MBASE(row));
	DWIN_Draw_Small_Float41(CONFIGVALUE_X-8, MBASE(row), planner.settings.axis_steps_per_mm[Y_AXIS] * MINUNITMULT);
}

static void Item_Steps_Z(uint8_t row){
	Draw_Menu_Line(row, ICON_STEPZ);
	DWIN_Show_MultiLanguage_String(STEP_MENU_STEP, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(STEP_MENU_Z, LBLX+GET_ICON_X(STEP)+6, MBASE(row));
	DWIN_Draw_Small_Float41(CONFIGVALUE_X-8, MBASE(row), planner.settings.axis_steps_per_mm[Z_AXIS] * MINUNITMULT);
}

static void Item_Steps_E(uint8_t row){
	Draw_Menu_Line(row, ICON_STEPE);
	DWIN_Show_MultiLanguage_String(STEP_MENU_STEP, LBLX, MBASE(row));
	DWIN_Show_MultiLanguage_String(STEP_MENU_E, LBLX+GET_ICON_X(STEP)+6, MBASE(row));
	DWIN_Draw_Small_Float41(CONFIGVALUE_X-8, MBASE(row), planner.settings.axis_steps_per_mm[E_AXIS] * MINUNITMULT);
}

inline void Draw_Steps_Menu() {
	DwinMenu_step.reset();
	Clear_Dwin_Area(AREA_TITAL|AREA_MENU);

	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_STEP, TITLE_X, TITLE_Y);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);
	
	Draw_Back_First(DwinMenu_step.now == STEPSMM_CASE_BACK);
	Item_Steps_X(STEPSMM_CASE_X);
	Item_Steps_Y(STEPSMM_CASE_Y);
	Item_Steps_Z(STEPSMM_CASE_Z);
	Item_Steps_E(STEPSMM_CASE_E);
	if (DwinMenu_step.now) Draw_Menu_Cursor(DwinMenu_step.now);
}

void HMI_StepXYZE() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.Max_Step)) {
			DwinMenuID = DWMENU_SET_STEPPREMM;
			EncoderRate.enabled = false;
			if (WITHIN(HMI_flag.axis, X_AXIS, E_AXIS))
				planner.settings.axis_steps_per_mm[HMI_flag.axis] = (float)HMI_Value.Max_Step / MINUNITMULT;
			DWIN_Draw_Small_Float41(CONFIGVALUE_X-8, MBASE(DwinMenu_step.now), HMI_Value.Max_Step);
			return;
		}
		// Step/mm limit
		if (WITHIN(HMI_flag.axis, X_AXIS, E_AXIS)){
			NOMORE(HMI_Value.Max_Step, default_axis_steps_per_unit[HMI_flag.axis]*4*MINUNITMULT);
			NOLESS(HMI_Value.Max_Step, MIN_STEP*MINUNITMULT);
		}
		// Step/mm value
		DWIN_Draw_Selected_Small_Float41(CONFIGVALUE_X-8, MBASE(DwinMenu_step.now), HMI_Value.Max_Step);
	}
}

/* Step */
void HMI_StepPermm() {
 ENCODER_DiffState encoder_diffState = get_encoder_state();
 if (encoder_diffState == ENCODER_DIFF_NO) return;

 // Avoid flicker by updating only the previous menu
 if (encoder_diffState == ENCODER_DIFF_CW) {
  if (DwinMenu_step.inc(STEPSMM_CASE_END)) Move_Highlight(1, DwinMenu_step.now);
 }
 else if (encoder_diffState == ENCODER_DIFF_CCW) {
  if (DwinMenu_step.dec()) Move_Highlight(-1, DwinMenu_step.now);
 }
 else if (encoder_diffState == ENCODER_DIFF_ENTER) {
  if (WITHIN(DwinMenu_step.now, STEPSMM_CASE_X, STEPSMM_CASE_E)) {
   DwinMenuID = DWMENU_SET_STEPPREMM_VALUE;
   HMI_flag.axis = AxisEnum(DwinMenu_step.now - 1);
   HMI_Value.Max_Step = planner.settings.axis_steps_per_mm[HMI_flag.axis] * MINUNITMULT;
   DWIN_Draw_Selected_Small_Float41(CONFIGVALUE_X-8, MBASE(DwinMenu_step.now), HMI_Value.Max_Step);
   EncoderRate.enabled = true;
  }
  else { // Back   
   Draw_Motion_Menu(MOTION_CASE_STEPS);
  }
 }
 dwinLCD.UpdateLCD();
}


void HMI_Motion() {
	ENCODER_DiffState encoder_diffState = get_encoder_state();
	if (encoder_diffState == ENCODER_DIFF_NO) return;

	// Avoid flicker by updating only the previous menu
	if (encoder_diffState == ENCODER_DIFF_CW) {
		
		if (DwinMenu_motion.inc(MOTION_CASE_END)){ 			
			Move_Highlight(1, DwinMenu_motion.now);
		}
	}
	else if (encoder_diffState == ENCODER_DIFF_CCW) {		
		if (DwinMenu_motion.dec()){ 
			Move_Highlight(-1, DwinMenu_motion.now);
		}
	}
	else if (encoder_diffState == ENCODER_DIFF_ENTER) {
		switch (DwinMenu_motion.now) {
		case 0: // Back
			Draw_Control_Menu(CONTROL_CASE_MOTION);
		break;
		
		case MOTION_CASE_FEEDRATE:  // Max speed
			DwinMenuID = DWMENU_SET_MAXSPEED;
			DwinMenu_feedrate.reset();
			Draw_Max_Speed_Menu();
		break;
		
		case MOTION_CASE_ACCEL: // Max acceleration
			DwinMenuID = DWMENU_SET_MAXACC;
			DwinMenu_accel.reset();
			Draw_Max_Accel_Menu();
		break;
		
	#if HAS_CLASSIC_JERK
		case MOTION_CASE_JERK: // Max jerk
			DwinMenuID = DWMENU_SET_MAXJERK;
			DwinMenu_jerk.reset();
			Draw_Max_Jerk_Menu();
		break;
	#endif
	
		case MOTION_CASE_STEPS: // Steps per mm
			DwinMenuID = DWMENU_SET_STEPPREMM;
			DwinMenu_step.reset();
			Draw_Steps_Menu();
		break;
		
		default: break;
		}
	}
	dwinLCD.UpdateLCD();
}

//
// Control >> BLTouch
//
#if ENABLED(BLTOUCH)
inline void Draw_Bltouch_Menu() {
	DwinMenuID = DWMENU_SET_BLTOUCH;
	DwinMenu_bltouch.reset();
	//DwinMenu_bltouch.index = _MAX(DwinMenu_bltouch.now, MROWS);
	
	Clear_Dwin_Area(AREA_TITAL|AREA_MENU);
	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_BLTOUCH, TITLE_X, TITLE_Y);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);

	Draw_Back_First(DwinMenu_bltouch.now == 0);
	DWIN_Show_MultiLanguage_String(BLTOUCH_MENU_RESET, LBLX, MBASE(BLTOUCH_CASE_RESET));
	Draw_Menu_Line(BLTOUCH_CASE_RESET,ICON_BLTOUCH_RESET);
	DWIN_Show_MultiLanguage_String(BLTOUCH_MENU_TEST, LBLX, MBASE(BLTOUCH_CASE_TEST));
	Draw_Menu_Line(BLTOUCH_CASE_TEST,ICON_BLTOUCH_TEST);
	DWIN_Show_MultiLanguage_String(BLTOUCH_MENU_STOW, LBLX, MBASE(BLTOUCH_CASE_STOW));
	Draw_Menu_Line(BLTOUCH_CASE_STOW,ICON_BLTOUCH_STOW);	
	DWIN_Show_MultiLanguage_String(BLTOUCH_MENU_DEPLOY, LBLX, MBASE(BLTOUCH_CASE_DEPLOY));
	Draw_Menu_Line(BLTOUCH_CASE_DEPLOY,ICON_BLTOUCH_DEPLOY);	
	DWIN_Show_MultiLanguage_String(BLTOUCH_MENU_MODE, LBLX, MBASE(BLTOUCH_CASE_SW));
	Draw_Menu_Line(BLTOUCH_CASE_SW,ICON_BLTOUCH_SW);
	if (DwinMenu_bltouch.now) Draw_Menu_Cursor(DwinMenu_bltouch.now);	
}

void HMI_Option_Bltouch() {
	ENCODER_DiffState encoder_diffState = get_encoder_state();
	if (encoder_diffState == ENCODER_DIFF_NO) return;

	// Avoid flicker by updating only the previous menu
	if (encoder_diffState == ENCODER_DIFF_CW) {
		if (DwinMenu_bltouch.inc(BLTOUCH_CASE_END)) Move_Highlight(1, DwinMenu_bltouch.now);
	}
	else if (encoder_diffState == ENCODER_DIFF_CCW) {
		if (DwinMenu_bltouch.dec()) Move_Highlight(-1, DwinMenu_bltouch.now);
	}
	else if (encoder_diffState == ENCODER_DIFF_ENTER) {
		switch (DwinMenu_bltouch.now) {
			case 0: 					// Back
				Draw_Control_Menu(CONTROL_CASE_BLTOUCH);
			break;

			case BLTOUCH_CASE_RESET: 	// Reset
				DwinMenuID = DWMENU_SET_BLTOUCH;
				bltouch._reset();
			break;

			case BLTOUCH_CASE_TEST: 	// Test
					DwinMenuID = DWMENU_SET_BLTOUCH;
					bltouch._selftest();
			break;

			case BLTOUCH_CASE_STOW: 	// Stow
					DwinMenuID = DWMENU_SET_BLTOUCH;
					bltouch._stow();
			break;

			case BLTOUCH_CASE_DEPLOY: 	// Proc
					DwinMenuID = DWMENU_SET_BLTOUCH;
					bltouch._deploy();
			break;
			
			case BLTOUCH_CASE_SW: 	// sw
				DwinMenuID = DWMENU_SET_BLTOUCH;
				bltouch._set_SW_mode();
			break;
			
			default: break;
		}
	}
	dwinLCD.UpdateLCD();
}
#endif

#if ENABLED(OPTION_BED_COATING)
void HMI_Adjust_Coating_Thickness() {
	static float last_G = 0;
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze(); 
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.coating_thickness)) {
			DwinMenuID = DWMENU_CONFIG;
			EncoderRate.enabled = false;
			last_G = HMI_Value.coating_thickness;
			DWIN_Draw_Small_Float21(MENUVALUE_X-8, MBASE(MROWS -DwinMenu_configure.index + CONFIG_CASE_COATING), HMI_Value.coating_thickness);			
			dwinLCD.UpdateLCD();
			coating_thickness = (float)HMI_Value.coating_thickness/MINUNITMULT;			
			return;
	 }		
		if ((HMI_Value.coating_thickness - last_G) > 10*MINUNITMULT)
			HMI_Value.coating_thickness = last_G + 10*MINUNITMULT;
		else if ((last_G - HMI_Value.coating_thickness) > 10*MINUNITMULT)
			HMI_Value.coating_thickness = last_G - 10*MINUNITMULT;
		NOLESS(HMI_Value.coating_thickness, 0);
		NOMORE(HMI_Value.coating_thickness, 10*MINUNITMULT);		
		DWIN_Draw_Selected_Small_Float21(MENUVALUE_X-8, MBASE(MROWS -DwinMenu_configure.index + CONFIG_CASE_COATING), HMI_Value.coating_thickness);
		dwinLCD.UpdateLCD();
	}
}
#endif

#if BOTH(OPTION_WIFI_MODULE, OPTION_WIFI_BAUDRATE)
void HMI_Adjust_WiFi_BaudRate(){
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze(); 
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_uint8(encoder_diffState, &WiFi_BaudRate)) {
			DwinMenuID = DWMENU_CONFIG;
			EncoderRate.enabled = false;
			DWIN_Draw_IntValue_Default(6, MENUVALUE_X-24, MBASE(CONFIG_CASE_WIFISPEED + MROWS -DwinMenu_configure.index), Table_Baudrate[WiFi_BaudRate]);
			dwinLCD.UpdateLCD();			
			return;
		}
		NOLESS(WiFi_BaudRate, 0);
		NOMORE(WiFi_BaudRate, 3);
		DWIN_Draw_IntValue_Default_Color(SELECT_COLOR, 6, MENUVALUE_X-24, MBASE(CONFIG_CASE_WIFISPEED + MROWS -DwinMenu_configure.index), Table_Baudrate[WiFi_BaudRate]);
		dwinLCD.UpdateLCD();		
	}
}
#endif

void HMI_Config() {
 ENCODER_DiffState encoder_diffState = get_encoder_state();
 if (encoder_diffState == ENCODER_DIFF_NO) return;

 // Avoid flicker by updating only the previous menu
	if (encoder_diffState == ENCODER_DIFF_CW) {
		if(IS_SD_PRINTING() || IS_SD_PAUSED()){
			if(DwinMenu_configure.inc(CONFIG_TUNE_CASE_END)){					
				if (DwinMenu_configure.now > MROWS && DwinMenu_configure.now > DwinMenu_configure.index) {
					DwinMenu_configure.index = DwinMenu_configure.now;
					// Scroll up and draw a blank bottom line
					Scroll_Menu(DWIN_SCROLL_UP);
				}
				else 
					Move_Highlight(1, DwinMenu_configure.now + MROWS - DwinMenu_configure.index);
			}
		}
		else if(DwinMenu_configure.inc(CONFIG_CASE_END)){
			if (DwinMenu_configure.now > MROWS && DwinMenu_configure.now > DwinMenu_configure.index) {
				DwinMenu_configure.index = DwinMenu_configure.now;
				// Scroll up and draw a blank bottom line
				Scroll_Menu(DWIN_SCROLL_UP);
				
			#if ENABLED(OPTION_REPEAT_PRINTING) 
				if(DwinMenu_configure.index == CONFIG_CASE_REPRINT) Item_Config_Reprint(MROWS);
			#endif

			#if ENABLED(OPTION_WIFI_MODULE)
			if(DwinMenu_configure.index == CONFIG_CASE_WIFI) Item_Config_Wifi(MROWS);
			#if ENABLED(OPTION_WIFI_BAUDRATE) 
			if(DwinMenu_configure.index == CONFIG_CASE_WIFISPEED) Item_Config_WifiBaudrate(MROWS);
			#endif
			#endif
			#if ENABLED(OPTION_BED_COATING) 
				if(DwinMenu_configure.index == CONFIG_CASE_COATING) Item_Config_bedcoating(MROWS);
			#endif

			#if ABL_GRID
				if(DwinMenu_configure.index == CONFIG_CASE_LEVELING) Item_Config_Leveling(MROWS);
				if(DwinMenu_configure.index == CONFIG_CASE_ACTIVELEVEL) Item_Config_ActiveLevel(MROWS);
			#endif

			}
			else 
				Move_Highlight(1, DwinMenu_configure.now + MROWS - DwinMenu_configure.index);
		}
	}
	else if (encoder_diffState == ENCODER_DIFF_CCW) {
		if (DwinMenu_configure.dec()) {
			if (DwinMenu_configure.now < DwinMenu_configure.index - MROWS) {
				DwinMenu_configure.index--;
				Scroll_Menu(DWIN_SCROLL_DOWN);
				if(DwinMenu_configure.index - MROWS == CONFIG_CASE_BACK) Draw_Back_First();
			#if ENABLED(FWRETRACT) 
				else if(DwinMenu_configure.index - MROWS == CONFIG_CASE_RETRACT) Item_Config_Retract(0);
			#endif
			#if ENABLED(FILAMENT_RUNOUT_SENSOR)
				else if(DwinMenu_configure.index - MROWS == CONFIG_CASE_FILAMENT) Item_Config_Filament(0);
			#endif
			#if ENABLED(POWER_LOSS_RECOVERY)
				else if(DwinMenu_configure.index - MROWS == CONFIG_CASE_POWERLOSS) Item_Config_Powerloss(0);
			#endif
			#if ENABLED(OPTION_AUTOPOWEROFF)
				else if(DwinMenu_configure.index - MROWS == CONFIG_CASE_SHUTDOWN) Item_Config_Shutdown(0);
			#endif
			#if ENABLED(OPTION_WIFI_MODULE)
				else if(DwinMenu_configure.index - MROWS == CONFIG_CASE_WIFI) Item_Config_Wifi(0);
			 #if ENABLED(OPTION_WIFI_BAUDRATE)
				else if(DwinMenu_configure.index - MROWS == CONFIG_CASE_WIFISPEED) Item_Config_WifiBaudrate(0);
			 #endif			
			#endif
			#if ABL_GRID
				else if(DwinMenu_configure.index - MROWS == CONFIG_CASE_LEVELING) Item_Config_Leveling(0);
				else if(DwinMenu_configure.index - MROWS == CONFIG_CASE_ACTIVELEVEL) Item_Config_ActiveLevel(0);
			#endif

			}
			else {
				Move_Highlight(-1, DwinMenu_configure.now + MROWS - DwinMenu_configure.index);
			}
		}
	}
	else if (encoder_diffState == ENCODER_DIFF_ENTER) {
	  switch (DwinMenu_configure.now) {
			case 0: 									// Back
				if(IS_SD_PRINTING() || IS_SD_PAUSED() || IS_SD_FILE_OPEN()){
					HMI_flag.show_mode = SHOWED_TUNE;
					Draw_Tune_Menu(TUNE_CASE_CONFIG);
				}
				else{
					Draw_Control_Menu(CONTROL_CASE_CONFIG);					
				}
		  break;

 #if ENABLED(FWRETRACT) 
			case CONFIG_CASE_RETRACT: 				// RETRACT
				DwinMenuID = DWMENU_SET_RETRACT;
				DwinMenu_fwretract.index = MROWS;
				Draw_Retract_Menu();				
			break;
 #endif
	 
 #if ENABLED(FILAMENT_RUNOUT_SENSOR)
	case CONFIG_CASE_FILAMENT:  				// FILAMENT
		DwinMenuID = DWMENU_CONFIG;
		runout.enabled = !runout.enabled;
		DWIN_Draw_MaskString_Default(MENUONOFF_X, MBASE(CONFIG_CASE_FILAMENT + MROWS - DwinMenu_configure.index), F_STRING_ONOFF(runout.enabled));		
		if(runout.enabled)
			queue.inject_P(PSTR("M412 S1"));		
		else
			queue.inject_P(PSTR("M412 S0"));
   break;
 #endif
	 
 #if ENABLED(POWER_LOSS_RECOVERY)
	 case CONFIG_CASE_POWERLOSS:  			// POWERLOSS	 		
			DwinMenuID = DWMENU_CONFIG;
			recovery.enabled = !recovery.enabled;
			DWIN_Draw_MaskString_Default(MENUONOFF_X, MBASE(CONFIG_CASE_POWERLOSS + MROWS - DwinMenu_configure.index), F_STRING_ONOFF(recovery.enabled));
			if(recovery.enabled)
				queue.inject_P(PSTR("M413 S1"));			
			else
				queue.inject_P(PSTR("M413 S0"));
  break;
 #endif
		
 #if ENABLED(OPTION_AUTOPOWEROFF)
	 case CONFIG_CASE_SHUTDOWN:
		DwinMenuID = DWMENU_CONFIG;
		HMI_flag.Autoshutdown_enabled = !HMI_flag.Autoshutdown_enabled;
		DWIN_Draw_MaskString_Default(MENUONOFF_X, MBASE(CONFIG_CASE_SHUTDOWN + MROWS - DwinMenu_configure.index), F_STRING_ONOFF(HMI_flag.Autoshutdown_enabled));
		break;
 #endif
   
 #if ENABLED(OPTION_WIFI_MODULE)
	 case CONFIG_CASE_WIFI:
			if(IS_SD_PRINTING() || IS_SD_PAUSED())	break;
			
			WiFi_Enabled = !WiFi_Enabled;
			DWIN_Draw_MaskString_Default(MENUONOFF_X, MBASE(CONFIG_CASE_WIFI + MROWS - DwinMenu_configure.index), F_STRING_ONOFF(WiFi_Enabled));
			HMI_AudioFeedback(settings.save());
		  if(WiFi_Enabled){
				queue.wifi_Handshake_ok = false;
				HMI_flag.wifi_link_timer = 12;
				WIFI_onoff();
				DWIN_Show_Status_Message(COLOR_WHITE, PSTR("Turn on WiFi and connecting...."));
		  }
			else{
				DwinMenuID = DWMENU_CONFIG;
				WIFI_onoff();
			}			
		break;
	#if ENABLED(OPTION_WIFI_BAUDRATE)
	case CONFIG_CASE_WIFISPEED:
			if(IS_SD_PRINTING() || IS_SD_PAUSED())	break;

			DwinMenuID = DWMENU_SET_WIFIBAUDRATE;
			DWIN_Draw_IntValue_Default_Color(SELECT_COLOR, 6, MENUVALUE_X-24, MBASE(CONFIG_CASE_WIFISPEED + MROWS -DwinMenu_configure.index), Table_Baudrate[WiFi_BaudRate]);
	break;
	#endif
		
 #endif
	 		
 #if ENABLED(OPTION_REPEAT_PRINTING)
 	case CONFIG_CASE_REPRINT:
			if(IS_SD_PRINTING() || IS_SD_PAUSED())	break;
			
			DwinMenuID = DWMENU_SET_REPRINT;
			DwinMenu_reprint.index = MROWS;
			Draw_Reprint_Menu();
		break;
 #endif

 #if ENABLED(OPTION_BED_COATING)
 	case CONFIG_CASE_COATING:
			if(IS_SD_PRINTING() || IS_SD_PAUSED())	break;
			
			DwinMenuID = DWMENU_SET_BEDCOATING;
			axis_homed = 0;
			HMI_Value.coating_thickness = (int16_t)(coating_thickness * MINUNITMULT);
			DWIN_Draw_Selected_Small_Float21(MENUVALUE_X-8, MBASE(CONFIG_CASE_COATING + MROWS -DwinMenu_configure.index), HMI_Value.coating_thickness);			
		break;
 #endif

 #if ABL_GRID
	  case CONFIG_CASE_LEVELING:
			if(IS_SD_PRINTING() || IS_SD_PAUSED()) 	break;

			DwinMenuID = DWMENU_CONFIG;
			HMI_flag.Leveling_Menu_Fg = !HMI_flag.Leveling_Menu_Fg;
			DWIN_Draw_MaskString_Default(MENUONOFF_X, MBASE(CONFIG_CASE_LEVELING + MROWS - DwinMenu_configure.index), F_STRING_ONOFF(HMI_flag.Leveling_Menu_Fg));
			if(HMI_flag.Leveling_Menu_Fg)	set_bed_leveling_enabled(false);
		break;

		case CONFIG_CASE_ACTIVELEVEL:
			if(IS_SD_PRINTING() || IS_SD_PAUSED()) 	break;	
			
			DwinMenuID = DWMENU_CONFIG;			
			planner.leveling_active = !planner.leveling_active;
			DWIN_Draw_MaskString_Default(MENUONOFF_X, MBASE(CONFIG_CASE_ACTIVELEVEL + MROWS - DwinMenu_configure.index), F_STRING_ONOFF(planner.leveling_active));
			set_bed_leveling_enabled(planner.leveling_active);
		break;
 #endif
   
		default: break;
		}
	}
	dwinLCD.UpdateLCD();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Control >> PreHeat PLA
//
#if HAS_PREHEAT
inline void Draw_SetPreHeatPLA_Menu(){
	DwinMenuID = DWMENU_PREHEAT_PLA;
	DwinMenu_PreheatPLA.reset();
	//DwinMenu_PreheatPLA.index = _MAX(DwinMenu_PreheatPLA.now, MROWS);
	
	Clear_Dwin_Area(AREA_TITAL|AREA_MENU);

	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_PLA, TITLE_X, TITLE_Y);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);

	Draw_Back_First();
	
	DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_NOZZLE, LBLX, MBASE(PREHEAT_CASE_TEMP));
	DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_TEMP, LBLX+58, MBASE(PREHEAT_CASE_TEMP));
	DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(PREHEAT_CASE_TEMP), ui.material_preset[0].hotend_temp);
	Draw_Menu_Line(PREHEAT_CASE_TEMP, ICON_SETENDTEMP);
	
#if HAS_HEATED_BED
	DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_BED, LBLX, MBASE(PREHEAT_CASE_BED));
	DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_TEMP, LBLX+33, MBASE(PREHEAT_CASE_BED));
	DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(PREHEAT_CASE_BED), ui.material_preset[0].bed_temp);
	Draw_Menu_Line(PREHEAT_CASE_BED, ICON_SETBEDTEMP);
#endif

#if HAS_FAN
	DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_FAN_SPEED, LBLX, MBASE(PREHEAT_CASE_FAN));
	DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(PREHEAT_CASE_FAN), ui.material_preset[0].fan_speed);
	Draw_Menu_Line(PREHEAT_CASE_FAN, ICON_FANSPEED);
#endif

#if ENABLED(EEPROM_SETTINGS)
	DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_STORE, LBLX, MBASE(PREHEAT_CASE_SAVE));
	DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_SETTINGS, LBLX+50, MBASE(PREHEAT_CASE_SAVE));
	Draw_Menu_Line(PREHEAT_CASE_SAVE, ICON_WRITEEEPROM);
#endif
} 

///////////////////////////////////////////////////////////////////////////
//
// Control >> PreHeat ABS
//
inline void Draw_SetPreHeatABS_Menu(){
	DwinMenuID = DWMENU_PREHEAT_ABS;
	DwinMenu_PreheatABS.reset();
	//DwinMenu_PreheatABS.index = _MAX(DwinMenu_PreheatABS.now, MROWS);
	
	Clear_Dwin_Area(AREA_TITAL|AREA_MENU);

	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_ABS, TITLE_X, TITLE_Y);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);

	Draw_Back_First();
	
	DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_NOZZLE, LBLX, MBASE(PREHEAT_CASE_TEMP));
	DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_TEMP, LBLX+58, MBASE(PREHEAT_CASE_TEMP));	
	DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(PREHEAT_CASE_TEMP), ui.material_preset[1].hotend_temp);
	Draw_Menu_Line(PREHEAT_CASE_TEMP, ICON_SETENDTEMP);
	
#if HAS_HEATED_BED
	DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_BED, LBLX, MBASE(PREHEAT_CASE_BED));
	DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_TEMP, LBLX+33, MBASE(PREHEAT_CASE_BED));
	DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(PREHEAT_CASE_BED), ui.material_preset[1].bed_temp);	
	Draw_Menu_Line(PREHEAT_CASE_BED, ICON_SETBEDTEMP);
#endif

#if HAS_FAN
	DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_FAN_SPEED, LBLX, MBASE(PREHEAT_CASE_FAN));
	DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(PREHEAT_CASE_FAN), ui.material_preset[1].fan_speed);
	Draw_Menu_Line(PREHEAT_CASE_FAN, ICON_FANSPEED);
#endif

#if ENABLED(EEPROM_SETTINGS)
	DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_STORE, LBLX, MBASE(PREHEAT_CASE_SAVE));
	DWIN_Show_MultiLanguage_String(PLA_ABS_MENU_SETTINGS, LBLX+50, MBASE(PREHEAT_CASE_SAVE));
	Draw_Menu_Line(PREHEAT_CASE_SAVE, ICON_WRITEEEPROM);
#endif
}

 /* PLA Preheat */
void HMI_PLAPreheatSetting() {
  ENCODER_DiffState encoder_diffState = get_encoder_state();
  if (encoder_diffState == ENCODER_DIFF_NO) return;

  // Avoid flicker by updating only the previous menu
  if (encoder_diffState == ENCODER_DIFF_CW) {
   if (DwinMenu_PreheatPLA.inc(PREHEAT_CASE_END)) Move_Highlight(1, DwinMenu_PreheatPLA.now);
  }
  else if (encoder_diffState == ENCODER_DIFF_CCW) {
   if (DwinMenu_PreheatPLA.dec()) Move_Highlight(-1, DwinMenu_PreheatPLA.now);
  }
  else if (encoder_diffState == ENCODER_DIFF_ENTER) {
   switch (DwinMenu_PreheatPLA.now) {
    case 0: // Back
			Draw_Control_Menu(CONTROL_CASE_SETPLA);
     break;
    #if HAS_HOTEND
     case PREHEAT_CASE_TEMP: // Nozzle temperature
      DwinMenuID = DWMENU_SET_ETMP;
      HMI_Value.E_Temp = ui.material_preset[0].hotend_temp;			
			if(HMI_Value.E_Temp > 230)
				DWIN_Draw_Warn_IntValue_Default(3, MENUVALUE_X+8, MBASE(PREHEAT_CASE_TEMP + MROWS - DwinMenu_PreheatPLA.index), HMI_Value.E_Temp);
			else
				DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(PREHEAT_CASE_TEMP + MROWS - DwinMenu_PreheatPLA.index), HMI_Value.E_Temp);
      EncoderRate.enabled = true;
      break;
    #endif
    #if HAS_HEATED_BED
     case PREHEAT_CASE_BED: // Bed temperature
      DwinMenuID = DWMENU_SET_BTMP;
      HMI_Value.Bed_Temp = ui.material_preset[0].bed_temp;
      DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(PREHEAT_CASE_BED + MROWS - DwinMenu_PreheatPLA.index), HMI_Value.Bed_Temp);
      EncoderRate.enabled = true;
      break;
    #endif
    #if HAS_FAN
     case PREHEAT_CASE_FAN: // Fan speed
      DwinMenuID = DWMENU_SET_FANSPEED;
      HMI_Value.Fan_speed = ui.material_preset[0].fan_speed;
      DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(PREHEAT_CASE_FAN + MROWS - DwinMenu_PreheatPLA.index), HMI_Value.Fan_speed);
      EncoderRate.enabled = true;
      break;
    #endif
    #if ENABLED(EEPROM_SETTINGS)
     case PREHEAT_CASE_SAVE:  // Save PLA configuration
      HMI_AudioFeedback(settings.save());
      break;
    #endif
    default: break;
   }
  }
  dwinLCD.UpdateLCD();
}

/* ABS Preheat */
void HMI_ABSPreheatSetting() {
	ENCODER_DiffState encoder_diffState = get_encoder_state();
	if (encoder_diffState == ENCODER_DIFF_NO) return;

	// Avoid flicker by updating only the previous menu
	if (encoder_diffState == ENCODER_DIFF_CW) {
		if (DwinMenu_PreheatABS.inc(PREHEAT_CASE_END)) Move_Highlight(1, DwinMenu_PreheatABS.now);
	}
	else if (encoder_diffState == ENCODER_DIFF_CCW) {
		if (DwinMenu_PreheatABS.dec()) Move_Highlight(-1, DwinMenu_PreheatABS.now);
	}
  else if (encoder_diffState == ENCODER_DIFF_ENTER) {
		switch (DwinMenu_PreheatABS.now) {
			case 0: // Back
				Draw_Control_Menu(CONTROL_CASE_SETABS);
			break;
		#if HAS_HOTEND
			case PREHEAT_CASE_TEMP: // Set nozzle temperature
				DwinMenuID = DWMENU_SET_ETMP;
				HMI_Value.E_Temp = ui.material_preset[1].hotend_temp;			
				if(HMI_Value.E_Temp > 230)
					DWIN_Draw_Warn_IntValue_Default(3, MENUVALUE_X+8, MBASE(PREHEAT_CASE_TEMP + MROWS - DwinMenu_PreheatABS.index), HMI_Value.E_Temp);
				else
					DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(PREHEAT_CASE_TEMP + MROWS - DwinMenu_PreheatABS.index), HMI_Value.E_Temp);
				EncoderRate.enabled = true;
			break;
		#endif

		#if HAS_HEATED_BED
			case PREHEAT_CASE_BED: // Set bed temperature
				DwinMenuID = DWMENU_SET_BTMP;
				HMI_Value.Bed_Temp = ui.material_preset[1].bed_temp;
				DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(PREHEAT_CASE_BED + MROWS - DwinMenu_PreheatABS.index), HMI_Value.Bed_Temp);
				EncoderRate.enabled = true;
			break;
		#endif

		#if HAS_FAN
			case PREHEAT_CASE_FAN: // Set fan speed
				DwinMenuID = DWMENU_SET_FANSPEED;
				HMI_Value.Fan_speed = ui.material_preset[1].fan_speed;
				DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(PREHEAT_CASE_FAN + MROWS - DwinMenu_PreheatABS.index), HMI_Value.Fan_speed);
				EncoderRate.enabled = true;
			break;
		#endif

		#if ENABLED(EEPROM_SETTINGS)
			case PREHEAT_CASE_SAVE:  // Save ABS configuration
				HMI_AudioFeedback(settings.save());
			break;
		#endif
			default: break;
		}
	}
	dwinLCD.UpdateLCD();
}
#endif



/* Control */
void HMI_Control() {
	ENCODER_DiffState encoder_diffState = get_encoder_state();
	if (encoder_diffState == ENCODER_DIFF_NO) return;

	// Avoid flicker by updating only the previous menu
	if (encoder_diffState == ENCODER_DIFF_CW) {
		if (DwinMenu_control.inc(CONTROL_CASE_END)) {
			if (DwinMenu_control.now > MROWS && DwinMenu_control.now > DwinMenu_control.index) {
				DwinMenu_control.index = DwinMenu_control.now;
				// Scroll up and draw a blank bottom line
				Scroll_Menu(DWIN_SCROLL_UP);		
				if (DwinMenu_control.index == CONTROL_CASE_SETPLA ) Item_Control_PLA(MROWS);
				if (DwinMenu_control.index == CONTROL_CASE_SETABS ) Item_Control_ABS(MROWS);
#if ENABLED(BLTOUCH)
				if(DwinMenu_control.index == CONTROL_CASE_BLTOUCH) Item_Control_BLtouch(MROWS);
#endif
#if ENABLED(EEPROM_SETTINGS)
				if(DwinMenu_control.index == CONTROL_CASE_SAVE) Item_Control_Save(MROWS);
				if(DwinMenu_control.index == CONTROL_CASE_LOAD)	Item_Control_Load(MROWS);
				if(DwinMenu_control.index == CONTROL_CASE_RESET)	Item_Control_Reset(MROWS);
#endif		
			}
			else {
				Move_Highlight(1, DwinMenu_control.now + MROWS - DwinMenu_control.index);
			}
		}
	}
	else if (encoder_diffState == ENCODER_DIFF_CCW) {
		if (DwinMenu_control.dec()) {
			if (DwinMenu_control.now < DwinMenu_control.index - MROWS) {
				DwinMenu_control.index--;
				Scroll_Menu(DWIN_SCROLL_DOWN);
				if (DwinMenu_control.index - MROWS == CONTROL_CASE_BACK) Draw_Back_First(1);    		
				else if (DwinMenu_control.index - MROWS == CONTROL_CASE_MIXER ) Item_Control_Mixer(0);
				else if (DwinMenu_control.index - MROWS == CONTROL_CASE_CONFIG ) Item_Control_Config(0);
				else if (DwinMenu_control.index - MROWS == CONTROL_CASE_MOTION ) Item_Control_Motion(0);
				else if (DwinMenu_control.index - MROWS == CONTROL_CASE_SETPLA ) Item_Control_PLA(0);
				else if (DwinMenu_control.index - MROWS == CONTROL_CASE_SETABS ) Item_Control_ABS(0);		
			}
			else {
				Move_Highlight(-1, DwinMenu_control.now + MROWS - DwinMenu_control.index);
			}
		}
	}
	else if (encoder_diffState == ENCODER_DIFF_ENTER) {
		switch (DwinMenu_control.now) {
			case 0: // Back				
				Draw_Main_Menu(false, MAIN_CASE_CONTROL);
			break;

			case CONTROL_CASE_MIXER: // Mixer
				Draw_Mixer_Menu();
			break;
			
			case CONTROL_CASE_CONFIG: // Config
				Draw_Config_Menu();
			break;
			
			case CONTROL_CASE_MOTION: // Motion
				Draw_Motion_Menu();
			break;

			case CONTROL_CASE_SETPLA:	// PLA preheat setting				
				DwinMenu_PreheatPLA.reset();
				HMI_flag.show_mode = SHOWED_PEHEAT_PLA;
				Draw_SetPreHeatPLA_Menu();
			break;

			case CONTROL_CASE_SETABS: // ABS preheat setting				
				DwinMenu_PreheatABS.reset();
				HMI_flag.show_mode = SHOWED_PEHEAT_ABS;
				Draw_SetPreHeatABS_Menu();
			break;	

		#if ENABLED(BLTOUCH)
			case CONTROL_CASE_BLTOUCH: // Bltouch				
				DwinMenu_bltouch.reset();
				SERIAL_ECHOLNPAIR("DwinMenu_control.now = ", DwinMenu_control.now);
				SERIAL_ECHOLNPAIR("DwinMenu_control.last = ", DwinMenu_control.last);
				SERIAL_ECHOLNPAIR("DwinMenu_control.index = ", DwinMenu_control.index);
				Draw_Bltouch_Menu();
			break;
		#endif

		#if ENABLED(EEPROM_SETTINGS)
			case CONTROL_CASE_SAVE: // Write EEPROM    
				HMI_AudioFeedback(settings.save());				
			break;
			
			case CONTROL_CASE_LOAD: // Read EEPROM
				SERIAL_ECHOLNPAIR("\n eeprom size = ", settings.datasize());
				HMI_AudioFeedback(settings.load());
			break;
			
			case CONTROL_CASE_RESET: // Reset EEPROM				
				if(card.isMounted()){
					card.closefile();
					card.removeFile("/old_fw.bin");
				}
				settings.reset();
				HMI_AudioFeedback(settings.save());
				Draw_Control_Menu();
			break;			
		#endif
				
			default: break;
		}
	}
	dwinLCD.UpdateLCD();
}
#endif

