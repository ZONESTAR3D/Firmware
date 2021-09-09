===============================================================================
HOW to upload firmware to the control board
1. Download Upload tool from the below link: https://github.com/ZONESTAR3D/Firmware-Upload-tool
2. refer to the guide in that link and upload firmware to the control board
===============================================================================

===============================================================================
How to Connect the LCD 128x64 screen and TFT-LCD screen:
LCD12864 connect to EXP1 connector
TFT_LCD connect to EXP1 connector (Upload a firmware supportin TFT-LCD to the control board of printer first)
TFT_LCD files download link: https://github.com/ZONESTAR3D/TFT-LCD

===============================================================================

===============================================================================
About the firmware name:
Z8T_ZRIBV6_xxx(add features)_V(version)_en(Menu language).bin
===============================================================================

===============================================================================
firmware file description:
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Default for Z8T(M3)
filename: Z8T_ZRIBV6_V1_7_3_en(es/pt/ru/fr).hex
----------------
Control board	: ZRIBV6
Exturder     	: Titan 
LCD SCREEN   	: LCD128x64 
Leveling Sensor	: PL-08N
Motor Diver     : A4988
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TMC220x@XYZ:
Z8T_ZRIBV6_TMC220xXYZ_Vxxxx_en(es/pt/ru/fr).hex:
----------------
Control board	: ZRIBV6
Exturder     	: Titan 
LCD SCREEN   	: LCD128x64
Leveling Sensor	: PL-08N
Motor Diver     : TMC2208 or TMC2209 be used to X/Y/Z axis
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TMC220x@XYZE:
Z8T_ZRIBV6_TMC220xXYZE_Vxxxx_en.hex:
----------------
Control board	: ZRIBV6
Exturder     	: Titan 
LCD SCREEN   	: LCD128x64
Leveling Sensor	: PL-08N
Motor Diver     : TMC2208 or TMC2209 be used all axis
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

+ 3D Touch:
Z8T_ZRIBV6_TMC220xXYZE_3DTouch_Vxxxx_en.bin:
----------------
Control board	: ZRIBV6
Exturder     	: Titan 
LCD SCREEN   	: LCD128x64
Leveling Sensor	: 3D Touch (BLTouch)
Motor Diver     : TMC2208 or TMC2209 be used all axis
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

+ TFT_LCD:
Z8T_ZRIBV6_TFTLCD_Vxxxx.bin:
----------------
Control board	: ZRIBV6
Exturder     	: Titan 
LCD SCREEN   	: TFT_LCD
Leveling Sensor	: PL-08N
Motor Diver     : A4988
===============================================================================

+ TFT_LCD:
Z8T_ZRIBV6_TFTLCD_Vxxxx.bin:
----------------
Control board	: ZRIBV6
Exturder     	: Titan 
LCD SCREEN   	: TFT_LCD
Leveling Sensor	: PL-08N
Motor Diver     : A4988
===============================================================================

+ TFT_LCD + TMC220x:
Z8T_ZRIBV6_TFTLCD_TMC220xXYZE_Vxxxx.bin:
----------------
Control board	: ZRIBV6
Exturder     	: Titan 
LCD SCREEN   	: TFT_LCD
Leveling Sensor	: PL-08N
Motor Diver     : TMC2208 or TMC2209 be used all axis
===============================================================================

Release Note:
===============================================================================
Date:    2020-11-09
Version: V1.2.4
NOTE:
[DEBUG] fix an issue of power loss resume:
when auto leveling feature is enable, it doesn't work well when resume from power loss

Date:    2020-11-05
Version: V1.2.3
NOTE:
[DEBUG] fix an issue: when the file in the root directory on SD card, 
"power loss fail resume" can't start to work.
