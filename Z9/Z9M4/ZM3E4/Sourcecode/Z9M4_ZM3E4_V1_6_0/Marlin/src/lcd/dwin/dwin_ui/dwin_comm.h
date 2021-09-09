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

#ifdef HAS_DWIN_LCD
#include "../rotary_encoder.h"
#include "../dwin_lcd.h"
#if ANY(HAS_HOTEND, HAS_HEATED_BED, HAS_FAN) && PREHEAT_COUNT
  #define HAS_PREHEAT 1
  #if PREHEAT_COUNT < 2
    #error "DWIN requires two material preheat presets."
  #endif
#endif

#define F_STRING_ONOFF(V) ((V)?PSTR("ON "):PSTR("OFF"))

//Color
#define COLOR_WHITE       0xFFFF
#define COLOR_YELLOW      0xFF0F
#define COLOR_GREEN       0x07E0
#define COLOR_RED         0xF00F  // Red background color
#define COLOR_BLUE        0x001F  // 
#define COLOR_BG_WINDOW   0x31E8  //
#define COLOR_BG_BLUE     0x1125  //1125// Dark blue background color
#define COLOR_BG_DEEPBLUE 0x000F  //1125// Dark blue background color
#define COLOR_BG_BLACK    0x0000  //841// Black background color      
#define COLOR_BG_RED      0xF00F  // Red background color
#define POP_TEXT_COLOR  	0xD6BA  // Popup font background color
#define LINE_COLOR        0x3A6A  // Split line color
#define RECTANGLE_COLOR   0xEE2F  // Orange square cursor color
#define BARFILL_COLOR     0x10E4  // Fill color of progress bar
#define SELECT_COLOR      0x33BB  // Selected color

// Picture ID
#define	IMAGE_CACHE_ID1		1

#define	FIL_FONT					font12x24
#define	FIL_FONT_W				12
#define	FIL_FONT_H				24
#define	FIL_TEXT_COLOR		POP_TEXT_COLOR
#define	FIL_WINDOW_COLOR	COLOR_BG_WINDOW
#define	FIL_TEXT_Y				240

// Mininum unit (0.1) : multiple (10)
#define MINUNITMULT     10
// Maxinum unit (0.01) : multiple (100)
#define MAXUNITMULT     100


#define	MROWS					5			// Menu lines (don't include return)
#define	TROWS					6			// Total menu lines
#define	TITLE_HEIGHT	30		// Title bar height
#define	MLINE					53		// Menu line height
#define	LBLX					55		// Menu item label X
#define	LBLX_INFO			25		// Info Menu item label X
#define	MENU_CHR_W		8			// menu char width
#define	MENU_CHR_H		16		// menu char height
#define	STAT_CHR_W		10		// state char width
#define	STAT_CHR_H		20		// state char height

#define MBASE(L) (49 + MLINE * (L))

#define ICON_IMAGE_ID	8

#define DWIN_FONT_MENU font8x16
#define DWIN_FONT_STAT font10x20
#define DWIN_FONT_HEAD font10x20
#define DWIN_FONT_MIX  font14x28

#define MENU_CHAR_LIMIT  	24

#define	MENUICON_X			26
#define	MENUVALUE_X			210
#define	MENUMORE_X			226
#define	CONFIGVALUE_X		210
#define	MENUONOFF_X			220

#define	TITAL_Y_START			0
#define	TITAL_Y_END				30
#define	MENU_Y_START			31
#define	MENU_Y_END				359
#define	MIXVALUE_X_START	10
#define	MIXVALUE_X_END		267
#define	MIXVALUE_Y_START	143
#define	MIXVALUE_Y_END		171
#define STATUS_Y_START 	 	360
#define STATUS_Y_END 	 		449
#define BOTTOM_Y_START 	 	450
#define BOTTOM_Y_END 	 		DWIN_HEIGHT
#define	POP_X_START				0
#define	POP_X_END					258
#define	POP_Y_START				31
#define	POP_Y_END					359

typedef enum{
	AREA_TITAL = 0x01,
	AREA_MENU = 0x02,
	AREA_MIXVALUE = 0x04,	
	AREA_STATUS  = 0x08,
	AREA_BOTTOM  = 0x10,
	AREA_POPMENU  = 0x20,
}_emMenuArea;

enum{
	TEMP_CASE_BACK = 0,
#if HAS_HOTEND		
	TEMP_CASE_ETEMP,
#endif
#if HAS_HEATED_BED		
	TEMP_CASE_BTEMP,
#endif
#if HAS_FAN
	TEMP_CASE_FAN,
#endif
#if HAS_HOTEND
	TEMP_CASE_PREHEATPLA,
	TEMP_CASE_PREHEATABS,
	TEMP_CASE_COOL,
#endif
	TEMP_CASE_END
	
};
#define	TEMP_CASE_TOTAL (0+HAS_HOTEND*4+HAS_HEATED_BED+HAS_FAN)

#define	DWIN_Draw_Small_Float21(x,y,v)							dwinLCD.Draw_SignedFloatValue(font8x16, COLOR_WHITE, COLOR_BG_BLACK, 2, 1, x, y, v)
#define	DWIN_Draw_Small_Float22(x,y,v)							dwinLCD.Draw_SignedFloatValue(font8x16, COLOR_WHITE, COLOR_BG_BLACK, 2, 2, x, y, v)
#define	DWIN_Draw_Small_Float31(x,y,v)							dwinLCD.Draw_SignedFloatValue(font8x16, COLOR_WHITE, COLOR_BG_BLACK, 3, 1, x, y, v)
#define	DWIN_Draw_Small_Float32(x,y,v)							dwinLCD.Draw_SignedFloatValue(font8x16, COLOR_WHITE, COLOR_BG_BLACK, 3, 2, x, y, v)
#define	DWIN_Draw_Small_Float41(x,y,v)							dwinLCD.Draw_SignedFloatValue(font8x16, COLOR_WHITE, COLOR_BG_BLACK, 4, 1, x, y, v)
#define	DWIN_Draw_Selected_Small_Float21(x,y,v)			dwinLCD.Draw_SignedFloatValue(font8x16, SELECT_COLOR, COLOR_BG_BLACK, 2, 1, x, y, v)
#define	DWIN_Draw_Selected_Small_Float22(x,y,v)			dwinLCD.Draw_SignedFloatValue(font8x16, SELECT_COLOR, COLOR_BG_BLACK, 2, 2, x, y, v)
#define	DWIN_Draw_Selected_Small_Float31(x,y,v)			dwinLCD.Draw_SignedFloatValue(font8x16, SELECT_COLOR, COLOR_BG_BLACK, 3, 1, x, y, v)
#define	DWIN_Draw_Selected_Small_Float32(x,y,v)			dwinLCD.Draw_SignedFloatValue(font8x16, SELECT_COLOR, COLOR_BG_BLACK, 3, 2, x, y, v)
#define	DWIN_Draw_Selected_Small_Float41(x,y,v)			dwinLCD.Draw_SignedFloatValue(font8x16, SELECT_COLOR, COLOR_BG_BLACK, 4, 1, x, y, v)
#define	DWIN_Draw_Big_Float32(x,y,v)								dwinLCD.Draw_SignedFloatValue(font14x28, COLOR_WHITE, COLOR_BG_BLACK, 3, 2, x, y, v)
#define	DWIN_Draw_MaskString_Default(x,y,s) 				dwinLCD.Draw_String(false, true, font8x16, COLOR_WHITE, COLOR_BG_BLACK, x, y, s)
#define DWIN_Draw_MaskString_Default_Color(c,x,y,s)	dwinLCD.Draw_String(false, true, font8x16, c, COLOR_BG_BLACK, x, y, s)
#define	DWIN_Draw_MaskString_FONT12(a,b,x,y,s) 			dwinLCD.Draw_String(false, true, font12x24, a, b, x, y, s)
#define	DWIN_Draw_MaskString_Default_PopMenu(x,y,s) dwinLCD.Draw_String(false, true, font10x20, POP_TEXT_COLOR, COLOR_BG_WINDOW, x, y, s)
#define	DWIN_Draw_UnMaskString_Default(x,y,s) 			dwinLCD.Draw_String(false, false, font8x16, COLOR_WHITE, COLOR_BG_BLACK, x, y, s)
#define	DWIN_Draw_UnMaskString_FONT10(x,y,s) 				dwinLCD.Draw_String(false, false, font10x20, COLOR_WHITE, COLOR_BG_BLACK, x, y, s)
#define	DWIN_Draw_UnMaskString_FONT10_TITLE(x,y,s) 	dwinLCD.Draw_String(false, false, font10x20, COLOR_WHITE, COLOR_BG_BLUE, x, y, s)
#define	DWIN_Draw_IntValue_Default(n,x,y,v) 				dwinLCD.Draw_IntValue(true, true, 0, font8x16, COLOR_WHITE, COLOR_BG_BLACK, n, x, y, v)
#define	DWIN_Draw_IntValue_Default_Color(c,n,x,y,v) dwinLCD.Draw_IntValue(true, true, 0, font8x16, c, COLOR_BG_BLACK, n, x, y, v)
#define DWIN_Draw_MaskIntValue_Default(n,x,y,v) 		dwinLCD.Draw_IntValue(true, true, 1, font8x16, COLOR_WHITE, COLOR_BG_BLACK, n, x, y, v)
#define DWIN_Draw_UnMaskIntValue_Default(n,x,y,v) 	dwinLCD.Draw_IntValue(false, true, 1, font8x16, COLOR_WHITE, COLOR_BG_BLACK, n, x, y, v)
#define DWIN_Draw_IntValue_FONT10(c,n,x,y,v)				dwinLCD.Draw_IntValue(true, true, 0, font10x20, c, COLOR_BG_BLACK, n, x, y, v)
#define DWIN_Draw_Select_IntValue_Default(n,x,y,v)	dwinLCD.Draw_IntValue(true, true, 0, font8x16, SELECT_COLOR, COLOR_BG_BLACK, n, x, y, v)
#define DWIN_Draw_Warn_IntValue_Default(n,x,y,v)		dwinLCD.Draw_IntValue(true, true, 0, font8x16, COLOR_RED, COLOR_BG_BLACK, n, x, y, v)
#define DWIN_Draw_String_FIL(x, y, s)								dwinLCD.Draw_String(false, true, FIL_FONT, FIL_TEXT_COLOR, FIL_WINDOW_COLOR, x, y, s)


bool Apply_Encoder_int16(const ENCODER_DiffState &encoder_diffState, int16_t *valref);
bool Apply_Encoder_uint8(const ENCODER_DiffState &encoder_diffState, uint8_t *valref);
bool Apply_Encoder_int8(const ENCODER_DiffState &encoder_diffState, int8_t *valref);

void Draw_Menu_Line(const uint8_t line, const uint8_t icon=0, const char * const label = nullptr);
void Draw_Menu_Icon(const uint8_t line, const uint8_t icon);
void Draw_More_Icon(const uint8_t line);
void Draw_Menu_Cursor(const uint8_t line);
void DWIN_Show_MultiLanguage_String(uint8_t ItemID, uint16_t x, uint16_t y);
void DWIN_Show_ICON(uint8_t picID, uint16_t x, uint16_t y);
void Draw_Back_First(const bool is_sel=true);
void Draw_Popup_Bkgd_60();
void Erase_Menu_Cursor(const uint8_t line);
void Move_Highlight(const int16_t from, const uint16_t newline);
void Scroll_Menu(const int8_t dir = DWIN_SCROLL_DOWN);
void Clear_Dwin_Area(const uint8_t area);

void Draw_Title(PGM_P title);
void Draw_Wifi_Title(PGM_P title);
void DWIN_Show_Status_Message(uint16_t color, PGM_P string, const uint8_t t=3 );

void Draw_Popup_Bkgd_105();
void Add_Menu_Line();
void Erase_Menu_Text(const uint8_t line);
void DWIN_Show_Z_Position(bool bshowICON);
void Draw_Status_Area();

void HMI_AudioFeedback(const bool success=true);

#if HAS_HOTEND
void HMI_ETemp();
#endif // HAS_HOTEND

#if HAS_HEATED_BED
void HMI_BedTemp(); 
#endif // HAS_HEATED_BED

#if HAS_FAN
void HMI_FanSpeed(); 
#endif
void ICON_YESorNO(uint8_t Option);


#endif
