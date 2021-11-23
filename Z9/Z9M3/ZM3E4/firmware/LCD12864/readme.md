# Release Note:
## Version: V5.4.1
**Date:**    2021-2-2
**NOTE:**  
- [**BUG**] correct the PID parameter of hotend  
- [**BUG**] Improve communication reliability with 3.5inch TFT-LCD interface  

##  Version: V5.4.0
**Date:**    2020-12-13  
**NOTE:**  
- [**BUG**] correct the hotbed temperature when the temperature is lower than 15 degree  
- [**NEW**]   
1. Modify random mixing feature:  
1.1. add a "Height" parameter, When the z-axis height change is greater than or equal to this value, the color mixing ratio change is performed once  
1.2. add a "Extruders" parameter, it means how many extruders involved in random mixing;  
when Extruders = 1,switch between the all of extruders randomlly.
when Extruders = 2, extruder 1 and 2 will be mixed on a random mixing ratio.
when Extruders = 3, extruder 1,2 and 3 will be mixed on a random mixing ratio.
2. Auto reset the VTOOL setting to default if printed complete from SD card.


# About the firmware name:
for example: Z9M3_ZM3E4_xxx(add features)_V(version)_en(Menu language).bin
## Default firmware for Z9M3
- **Filename:** Z9M3_ZM3E4_Vxxxx_en(es/pt/ru/fr).bin
- **Firmware descriptions:**  
  - Control board	: ZM3E4
  - Exturder     	: Default
  - LCD SCREEN   	: LCD128x64 or/and TFT-LCD
  - Leveling Sensor	: PL-08N
  - Motor Diver     : A4988  

## Default for Z9M3_Titan
- **Filename:** Z9M3_ZM3E4_TITAN_Vxxxx_en(es/pt/ru/fr).bin
- **Firmware descriptions:**  
  - Control board	: ZM3E4
  - Exturder     	: Titan 
  - LCD SCREEN   	: LCD128x64 or/and TFT-LCD
  - Leveling Sensor	: PL-08N
  - Motor Diver     : A4988

## Titan extruder + TMC220x@XYZ:
- **Filename:** Z9M3_ZM3E4_TITAN_TMC220x@XYZ_Vxxxx_en.bin:
  - Control board	: ZM3E4
  - Exturder     	: Titan 
  - LCD SCREEN   	: LCD128x64 or/and TFT-LCD
  - Leveling Sensor	: PL-08N
  - Motor Diver     : TMC2208 or TMC2209 be used to X/Y/Z axis

## Titan extruder + TMC220x@XYZE:
- **Filename:** Z9M3_ZM3E4_TITAN_TMC220x@ALL_Vxxxx_en.bin:
- **Firmware descriptions:**  
  - Control board	: ZM3E4
  - Exturder     	: Titan 
  - LCD SCREEN   	: LCD128x64 or/and TFT-LCD
  - Leveling Sensor	: PL-08N
  - Motor Diver     : TMC2208 or TMC2209 be used all axis

## Titan extruder + 3D Touch:
- **Filename:** Z9M3_ZM3E4_TITAN_3DTouch_Vxxxx_en.bin:
- **Firmware descriptions:**  
  - Control board	: ZM3E4
  - Exturder     	: Titan 
  - LCD SCREEN   	: LCD128x64 or/and TFT-LCD
  - Leveling Sensor	: 3D Touch (BLTouch)
  - Motor Diver     : A4988

## Titan extruder + TMC220x@XYZE + 3D Touch:
- **Filename:**  Z9M3_ZM3E4_TITAN_TMC220x@ALL_3DTouch_Vxxxx_en.bin:
- **Firmware descriptions:**  
  - Control board	: ZM3E4
  - Exturder     	: Titan 
  - LCD SCREEN   	: LCD128x64 or/and TFT-LCD
  - Leveling Sensor	: 3D Touch
  - Motor Diver     : TMC2208 or TMC2209 be used all axis

## Titan extruder + TMC220x@XYZ + DualZ endstops:
- **Filename:**   Z9M3_ZM3E4_TITAN_TMC220x@XYZ_DualZENDSTOP_Vxxxx_en.bin:
- **Firmware descriptions:** 
  - Control board	: ZM3E4
  - Exturder     	: Titan 
  - LCD SCREEN   	: LCD128x64 or/and TFT-LCD
  - Leveling Sensor	: PL-08N
  - Motor Diver     : TMC2208 or TMC2209 be used to X/Y/Z axis
  - Others          : Dual Z ENDSTOPs

##  Titan extruder + TMC220x@XYZE + DualZ endstops:
- **Filename:**  Z9M3_ZM3E4_TITAN_TMC220xXYZE_DualZENDSTOP_Vxxxx_en.bin:
- **Firmware descriptions:** 
  - Control board	: ZM3E4
  - Exturder     	: Titan 
  - LCD SCREEN   	: LCD128x64 or/and TFT-LCD
  - Leveling Sensor	: PL-08N
  - Motor Diver     : TMC2208 or TMC2209 be used all axis
  - Others          : Dual Z ENDSTOPs
