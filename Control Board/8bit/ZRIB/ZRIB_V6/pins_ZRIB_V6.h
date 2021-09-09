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
 * Arduino Mega with RAMPS v1.4 (or v1.3) pin assignments
 *
 * Applies to the following boards:
 *
 *  ZRIB_V1 (X-MOT, Y-MOT, Z-MOT, E0-MOT, E1-MOT, Hotend0, Hotend1, Fan, Bed)
 *  ZRIB_V2 (X-MOT, Y-MOT, Z-MOT, E0-MOT, E1-MOT, Hotend0, Hotend1, Fan, Fan2, Bed)
 *  ZRIB_V3 (X-MOT, Y-MOT, Z-MOT, E0-MOT, E1-MOT, Hotend0, Hotend1, Fan, Fan2, Bed)
 *  ZRIB_V5 (X-MOT, Y-MOT, Z-MOT, E0-MOT, E1-MOT, E2-MOT, Hotend0, Hotend1, Fan, Fan2, Bed)
 *  ZRIB_V6 (X-MOT, Y-MOT, Z-MOT, E0-MOT, E1-MOT, E2-MOT, E3-MOT, Hotend0, Hotend1, Fan, Fan2, Bed)
 */

#if !defined(__AVR_ATmega2560__)
  #error "Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu."
#endif
#define LARGE_FLASH true

#ifndef BOARD_NAME
#define BOARD_NAME "ZONESTAR ZRIB_V6"
#endif

/**
 D0   Port: E0       AUX_PIN4		RX0
 D1   Port: E1       AUX_PIN3		TX0
 D2   Port: E4       X_MAX_PIN
 D3   Port: E5       X_MIN_PIN
 D4   Port: G5       				XS1_PIN_1
 D5   Port: E3						XS1_PIN_3
 D6   Port: H3		 FAN2_PIN		XS1_PIN_2
 D7   Port: H4       HEATER2_PIN
 D8   Port: H5		 HEAT_BED_PIN
 D9   Port: H6		 FAN_PIN			LASER_PWM
D10   Port: B4		 HEATER1_PIN       
D11   Port: B5       				XS1_PIN_4
D12   Port: B6		 PS_ON_PIN       
D13   Port: B7		 LED_PIN        
D14   Port: J1		 Y_MIN_PIN
D15   Port: J0		 Y_MAX_PIN
D16   Port: H1		 EXP1_PIN_7		TXD2
D17   Port: H0		 EXP1_PIN_8		RXD2
D18   Port: D3		 Z_MIN_PIN
D19   Port: D2		 Z_MAX_PIN
D20   Port: D1		 AUX_PIN1		SDA
D21   Port: D0		 AUX_PIN2		SCL
D22   Port: A0		 E2_EN_PIN		
D23   Port: A1		 EXP1_PIN6
D24   Port: A2		 E0_EN_PIN
D25   Port: A3		 EXP1_PIN5
D26   Port: A4		 E0_STEP_PIN
D27   Port: A5		 EXP1_PIN4
D28   Port: A6		 E0_DIR_PIN
D29   Port: A7       EXP1_PIN3                     
D30   Port: C7		 E1_EN_PIN
D31   Port: C6		 EXP2_PIN8
D32   Port: C5		 
D33   Port: C4		 EXP2_PIN6
D34   Port: C3		 E1_DIR_PIN
D35   Port: C2		 EXP1_PIN9
D36   Port: C1		 E1_STEP_PIN
D37   Port: C0		 EXP1_PIN10
D38   Port: D7		 X_EN_PIN
D39   Port: G2		 E2_DIR_PIN
D40   Port: G1		 E2_STEP_PIN
D41   Port: G0		 EXP2_PIN3
D42   Port: L7		 E3_EN_PIN
D43   Port: L6		 E2_STEP_PIN
D44   Port: L5		 E3_DIR_PIN
D45   Port: L4		
D46   Port: L3		 Z_STEP_PIN
D47   Port: L2		
D48   Port: L1		 Z_DIR_PIN
D49   Port: L0		 EXP2_PIN4
D50   Port: B3		 EXP2_PIN10		AVR_SPI_MISO
D51   Port: B2		 EXP2_PIN5		AVR_SPI_MOSI
D52   Port: B1		 EXP2_PIN9		AVR_SPI_SCK
D53   Port: B0		 EXP2_PIN7		AVR_SPI_SS
D54   Port: F0		 X_STEP_PIN		A0
D55   Port: F1		 X_DIR_PIN		A1
D56   Port: F2		 Y_EN_PIN		A2
D57   Port: F3		 E0_SW_PIN		A3
D58   Port: F4		 E1_SW_PIN		A4
D59   Port: F5						A5
D60   Port: F6		 Y_STEP_PIN		A6
D61   Port: F7		 Y_DIR_PIN		A7
D62   Port: K0		 Z_EN_PIN		A8
D63   Port: K1						A9
D64   Port: K2		 EXP2_PIN1		A10		ADC_KEYPAD_PIN
D65   Port: K3						A11
D66   Port: K4						A12
D67   Port: K5		 E0_TEMP		A13				
D68   Port: K6		 BED_TEMP		A14
D69   Port: K7		 E1_TEMP		A15
**/



/*===============================================================================

===============================================================================*/


//
// Limit Switches
//
#define X_MIN_PIN           3
#define X_MAX_PIN         	2

#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#define	E0_SW_PIN			57
#define	E1_SW_PIN			58


//
// Z Probe (when not Z_MIN_PIN)
//
#if ENABLED(Z_MIN_PROBE_ENDSTOP) 
#define	Z_MIN_PROBE_PIN	   Z_MAX_PIN
#endif

//
// Steppers
//
#if ENABLED(COREXY_SWAPXY_MOTOR)
#define X_STEP_PIN         60
#define X_DIR_PIN          61
#define X_ENABLE_PIN       56

#define Y_STEP_PIN         54
#define Y_DIR_PIN          55
#define Y_ENABLE_PIN       38
#else
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#endif

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62

#if ENABLED(Z_DUAL_STEPPER_DRIVERS)
#define Z2_STEP_PIN        26
#define Z2_DIR_PIN         28
#define Z2_ENABLE_PIN      24
#define	Z2_SW_PIN	   	   57

#define E0_STEP_PIN        36
#define E0_DIR_PIN         34
#define E0_ENABLE_PIN      30

#define E1_STEP_PIN        40
#define E1_DIR_PIN         39
#define E1_ENABLE_PIN      22

#define E2_STEP_PIN        43
#define E2_DIR_PIN         44
#define E2_ENABLE_PIN      42
#else
#define E0_STEP_PIN        26
#define E0_DIR_PIN         28
#define E0_ENABLE_PIN      24

#define E1_STEP_PIN        36
#define E1_DIR_PIN         34
#define E1_ENABLE_PIN      30

#define E2_STEP_PIN        40
#define E2_DIR_PIN         39
#define E2_ENABLE_PIN      22

#define E3_STEP_PIN        43
#define E3_DIR_PIN         44
#define E3_ENABLE_PIN      42
#endif

//
// Temperature Sensors
//
#define TEMP_0_PIN         13   // Analog Input
#define TEMP_BED_PIN       14   // Analog Input
#define TEMP_1_PIN         15   // Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN		10
#define HEATER_BED_PIN		8
#define HEATER_1_PIN 		7

#if ENABLED(USE_DUAL_HEATBED_PINS)
  #error "HEATER_1_PIN has been repeated distribution for ZRIB V6!!"
#endif

#define FAN_PIN        		9		//Laser PWM
#define FAN1_PIN        	6

//
// Misc. Functions
//
#define SDSS               53
#define LED_PIN            13
#define SD_DETECT_PIN 	   49

//Filament run out detection
#define FILWIDTH_PIN	   -1  // Analog Input
#if ENABLED(Z_DUAL_STEPPER_DRIVERS)
 #define FIL_RUNOUT_PIN 	E1_SW_PIN
 #define FIL_RUNOUT2_PIN 	X_MAX_PIN
#else
#define FIL_RUNOUT_PIN	   	E0_SW_PIN
#define FIL_RUNOUT2_PIN    	E1_SW_PIN
#endif

//Power hold pin
#define SUICIDE_PIN        	12

//
// Servos
//
#define SERVO0_PIN        4		//XS1(AUX3) Pin1
#define SERVO1_PIN        -1	//XS1(AUX3) Pin3
#define SERVO2_PIN        5		//XS1(AUX3) Pin5
#define SERVO3_PIN       11		//XS1(AUX3) Pin7

//================================================================================
// 							Spindle & Laser control
//================================================================================
#if ENABLED(SPINDLE_LASER_ENABLE)
#define SPINDLE_LASER_ENABLE_PIN	HEATER_0_PIN
#endif

//================================================================================
// 							LCD / Controller
//================================================================================
//LCD 128x64
//================================================================================
#if ENABLED(ZONESTAR_LCD12864)
#define	LCDSCREEN_NAME	"ZONESTAR LCD12864"
#define	LCD_SDSS		16
#define LCD_PINS_RS    	16 // ST7920_CS_PIN	LCD_PIN_RS 		(PIN4 of LCD module)
#define LCD_PINS_ENABLE 23 // ST7920_DAT_PIN	LCD_PIN_R/W		(PIN5 of LCD module)
#define LCD_PINS_D4	   	17 // ST7920_CLK_PIN	LCD_PIN_ENABLE	(PIN6 of LCD module)

// Alter timing for graphical display
#define ST7920_DELAY_1 	DELAY_2_NOP
#define ST7920_DELAY_2 	DELAY_2_NOP
#define ST7920_DELAY_3 	DELAY_2_NOP
#elif ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
#define	LCDSCREEN_NAME	"Reprap LCD12864"
//USE EXP1 & EXP2 CONNECTOR
#define LCD_PINS_RS    	16 // ST7920_CS_PIN	LCD_PIN_RS
#define LCD_PINS_ENABLE 17 // ST7920_DAT_PIN	LCD_PIN_ENABLE
#define LCD_PINS_D4	   	23 // ST7920_CLK_PIN	LCD_PIN_R/W 
// Alter timing for graphical display
#define ST7920_DELAY_1 	DELAY_2_NOP
#define ST7920_DELAY_2 	DELAY_2_NOP
#define ST7920_DELAY_3 	DELAY_2_NOP
#endif

#if ENABLED(MKS_MINI_12864)
#define	LCDSCREEN_NAME	"MKS MINI12864"
#define DOGLCD_CS     	25
#define DOGLCD_A0     	27
#endif
//================================================================================
//OLED 128x64
//================================================================================
#if ENABLED(ZONESTAR_OLED12864)
#define	LCDSCREEN_NAME	"ZONESTAR OLED12864"
#define	LCD_SDSS		16
#define LCD_PINS_RS    	23 				//RESET Pull low for 1s to init
#define LCD_PINS_DC    	17 				//
#define DOGLCD_CS       16				//CS
#if ENABLED(OLED_HW_IIC)
//IIC
#error "Oops!  must choose SW SPI for ZRIB board and connect the OLED screen to EXP1 connector"
#elif ENABLED(OLED_HW_SPI)
//HW_SPI
#error "Oops!  must choose SW SPI for ZRIB board and connect the OLED screen to EXP1 connector"
#else
//SW_SPI
#define DOGLCD_A0       LCD_PINS_DC		//DC
#define	DOGLCD_MOSI		35				//SDA
#define	DOGLCD_SCK		37				//SCK
#endif
#endif//OLED 128x64

//================================================================================
//LCD 2004
//================================================================================
#if ENABLED(ZONESTAR_LCD2004_ADCKEY) || ENABLED(ZONESTAR_LCD2004_KNOB)
#define	LCDSCREEN_NAME	"LCD 2004"
#define LCD_PINS_RS 	16
#define LCD_PINS_ENABLE 17
#define LCD_PINS_D4 	23
#define LCD_PINS_D5 	25
#define LCD_PINS_D6 	27
#define LCD_PINS_D7 	29
#endif

//================================================================================
//	KEYPAD
//================================================================================
#if ENABLED(ZONESTAR_LCD2004_ADCKEY)
#define	LCDSCREEN_NAME	"LCD2004 ADCKEY"
#define	ADC_KEYPAD_PIN	10			//A10 for ADCKEY
#endif

#if ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER)
#if ENABLED(ZONESTAR_LCD12864) 
#define BTN_EN1 		25
#define BTN_EN2 		27
#define BTN_ENC 		29
#define BEEPER_PIN 		37
#define KILL_PIN 		35
#elif ENABLED(ZONESTAR_OLED12864)
#define BTN_EN1 		25
#define BTN_EN2 		27
#define BTN_ENC 		29
#define BEEPER_PIN 		-1
#define KILL_PIN 		-1
#elif ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
#define BTN_EN1 		31
#define BTN_EN2 		33
#define BTN_ENC 		35
#define BEEPER_PIN 		37
#define KILL_PIN 		41
#elif ENABLED(ZONESTAR_LCD2004_KNOB) 
#define BTN_EN1 		31
#define BTN_EN2 		33
#define BTN_ENC 		35
#define BEEPER_PIN 		37
#define KILL_PIN 		41
#endif
#elif ENABLED(MKS_MINI_12864)
#define BTN_EN1 		31
#define BTN_EN2 		33
#define BTN_ENC 		35
#define BEEPER_PIN 		37
#define KILL_PIN 		41
#endif
//================================================================================
// End of LCD / Controller
//================================================================================

