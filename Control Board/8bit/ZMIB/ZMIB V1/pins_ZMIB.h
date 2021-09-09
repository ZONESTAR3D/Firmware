/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Melzi (Creality) pin assignments
 *
 * The Creality board needs a bootloader installed before Marlin can be uploaded.
 * If you don't have a chip programmer you can use a spare Arduino plus a few
 * electronic components to write the bootloader.
 *
 * See http://www.instructables.com/id/Burn-Arduino-Bootloader-with-Arduino-MEGA/
 */
#if !defined(__AVR_ATmega644P__) && !defined(__AVR_ATmega1284P__)
  #error "Oops!  Make sure you have 'Sanguino' selected from the 'Tools -> Boards' menu."
#endif

#define BOARD_NAME "ZMIB (ZONESTAR)"
//#define	IS_ZMIB_V2

/**
  PIN:   0   Port: B0        HEATER_0_PIN                
  PIN:   1   Port: B1        HEATER_BED_PIN              
  PIN:   2   Port: B2        EXP1_4(BTN_EN2)
  PIN:   3   Port: B3        V1: SD_DETECT_PIN
  PIN:   3   Port: B3        V2: EXP1_6
  PIN:   4   Port: B4        SDSS
  PIN:   4   Port: B4        V1: EXP1_6
  PIN:   5   Port: B5        AVR_MOSI_PIN                
  .                          MOSI_PIN                    
  PIN:   6   Port: B6        AVR_MISO_PIN                
  .                          EXP1_9(MISO_PIN)
  PIN:   7   Port: B7        AVR_SCK_PIN                 
  .                          EXP1_10(SCK_PIN)
  PIN:   8   Port: D0        RXD                         
  PIN:   9   Port: D1        TXD                         
  PIN:  10   Port: D2        EXP1_8                     
  PIN:  11   Port: D3        EXP1_7                      
  PIN:  12   Port: D4        EXP1_5(BTN_EN1)
  PIN:  13   Port: D5        Z_MIN_PIN                   
  PIN:  14   Port: D6        E1_DIR_PIN                  
  PIN:  15   Port: D7        E1_STEP_PIN                 
  PIN:  16   Port: C0        Z_DIR_PIN                   
  PIN:  17   Port: C1        Z_STEP_PIN             	 
  PIN:  18   Port: C2        Y_MIN_PIN                   
  PIN:  19   Port: C3        Y_DIR_PIN                   
  PIN:  20   Port: C4        Y_STEP_PIN                  
  PIN:  21   Port: C5        X_MIN_PIN                   
  PIN:  22   Port: C6        X_DIR_PIN                   
  PIN:  23   Port: C7        X_STEP_PIN                  
  PIN:  24   Port: A7        X_ENABLE_PIN                
  							 Y_ENABLE_PIN                
  							 Z_ENABLE_PIN                
  							 E0_ENABLE_PIN               
  							 E1_ENABLE_PIN               
  PIN:  25   Port: A6        FIL_RUNOUT_PIN              
  PIN:  26   Port: A5        E0_DIR_PIN                  
  PIN:  27   Port: A4        E0_STEP_PIN                 
  PIN:  28   Port: A3        FAN_PIN                     
  PIN:  29   Port: A2        EXP1_3(BTN_ENC)
                             ADC_KEY_PIN
  PIN:  30   Port: A1        TEMP_0_PIN                  
  PIN:  31   Port: A0        TEMP_BED_PIN                
**/

//
// Limit Switches
//
#define X_MIN_PIN		21
#define Y_MIN_PIN		18
#define Z_MIN_PIN		13

//
// Steppers
//
#define X_STEP_PIN		23
#define X_DIR_PIN		22
#define	X_ENABLE_PIN	24

#define Y_STEP_PIN		20
#define Y_DIR_PIN		19
#define	Y_ENABLE_PIN	24

#define Z_STEP_PIN		17
#define Z_DIR_PIN		16
#define	Z_ENABLE_PIN	24

#define E0_STEP_PIN		27
#define E0_DIR_PIN		26
#define	E0_ENABLE_PIN	24

#define E1_STEP_PIN		15
#define E1_DIR_PIN		14
#define	E1_ENABLE_PIN	24

//
// Temperature Sensors
//
#define TEMP_0_PIN		 1   // Analog Input
#define TEMP_BED_PIN	 0   // Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN     0
#define HEATER_BED_PIN   1
#define	FAN_PIN			 28
#define	FAN1_PIN		 -1

//
//filament run out sensor
//
#define FIL_RUNOUT_PIN   25 // 

//
//SD card
//
#if ENABLED(SDSUPPORT)
#define	SDSS			 4
#endif

//misc pins
#if ENABLED(IS_ZMIB_V2)
#define	EXP1_PIN6		 3
#else
#define	EXP1_PIN6		 4
#if(MODEL_NUMBER == Z6B_WiFi)
#define	SD_DETECT_PIN	 -1
#else
#define	SD_DETECT_PIN	 3

#endif
#endif

//================================================================================
// 							Spindle & Laser control
//================================================================================
#if ENABLED(SPINDLE_LASER_ENABLE)
#define SPINDLE_LASER_ENABLE_PIN	HEATER_0_PIN
#endif


//===============================================================================
//		ZMIB Version 1
//		EXP1 Connector
//		MOSI(D5)	TX1(D11)	ENA(D12)	ENC(D29/A2)	5V
//		SCK(D7)		RX1(D10)	SCS(D4)		ENB(D2)	GND
//===============================================================================
//		ZMIB Version 2
//		EXP1 Connector
//		MOSI(D5)	TX1(D11)	ENA(D12)	ENC(D29/A2)	5V
//		SCK(D7)		RX1(D10)	SCS(D3)		ENB(D2)	GND
//================================================================================
// 							LCD
//================================================================================
//LCD 128x64
//================================================================================
#if ENABLED(ZONESTAR_LCD12864)
#define	LCDSCREEN_NAME	"ZONESTAR_LCD12864"
//#define	LCD_SDSS		11
#define LCD_PINS_RS    	11 			//11 ST7920_CS_PIN		LCD_PIN_RS 		(PIN4 of LCD module)
#define LCD_PINS_ENABLE EXP1_PIN6 	// 4 ST7920_DAT_PIN	LCD_PIN_R/W		(PIN5 of LCD module)
#define LCD_PINS_D4	   	10 			//10 ST7920_CLK_PIN	LCD_PIN_ENABLE	(PIN6 of LCD module)

// Alter timing for graphical display
#define ST7920_DELAY_1 DELAY_2_NOP
#define ST7920_DELAY_2 DELAY_2_NOP
#define ST7920_DELAY_3 DELAY_2_NOP
#endif

//================================================================================
//OLED 128x64
//================================================================================
#if ENABLED(ZONESTAR_OLED12864)
#define	LCDSCREEN_NAME	"ZONESTAR OLED12864"
#define LCD_PINS_RS     EXP1_PIN6		//RESET
#define LCD_PINS_DC     10				//DC
#define DOGLCD_CS       11				//CS
#if ENABLED(OLED_HW_IIC)
#error "Oops! can't choose HW IIC for ZMIB board!!"
#elif ENABLED(OLED_HW_SPI)
//HW SPI
#define DOGLCD_A0       LCD_PINS_DC		//A0 = DC
#else
//SW SPI
#define DOGLCD_A0       LCD_PINS_DC		//A0 = DC
#define	DOGLCD_MOSI		AVR_MOSI_PIN	//SDA
#define	DOGLCD_SCK		AVR_SCK_PIN		//SCK
#endif
#endif//ENABLED(ZONESTAR_OLED12864)

//================================================================================
//LCD2004
//================================================================================
#if ENABLED(ZONESTAR_LCD2004_ADCKEY)
#define	LCDSCREEN_NAME	"LCD2004 ADCKEY"
#define LCD_PINS_RS 	2
#define LCD_PINS_ENABLE 12
#define LCD_PINS_D4 	EXP1_PIN6
#define LCD_PINS_D5 	11
#define LCD_PINS_D6 	10
#define LCD_PINS_D7 	5
#define	BEEPER_PIN		7
#endif

//================================================================================
//								KEYPAD
//================================================================================
#if ENABLED(ZONESTAR_LCD2004_ADCKEY)
#define	ADC_KEYPAD_PIN	2 //A2 for ADCKEY
#endif

//Knob
#if ENABLED(ZONESTAR_LCD12864) || ENABLED(ZONESTAR_OLED12864)
#define BTN_EN1 		12
#define BTN_EN2 		 2
#define BTN_ENC 		29
#define BEEPER_PIN 		-1
#define KILL_PIN 		-1
#endif

#if ENABLED(ZONESTAR_LCD2004_KNOB)
#error "Oops! ZMIB control board don't support LCD2004 Knob display control pad!!"
#endif

