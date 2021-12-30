#### Firmware Upload Steps:
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:
LCD12864: MENU>>config>>Advanced setting>>Initlizate EEPROM
TFT_LCD: MENU>>config>>Restore Defaults

### LCDDWIN
Firmware for 4.3" TFT-LCD screen.

- **Z8T_ZM3E4_LCDDWIN_TMC220x@XYZL**: Upgraded XYZ motor drivers to TMC2208(9)    
- **Z8T_ZM3E4_LCDDWIN_TMC220X@ALL** : Upgraded all motor drivers to TMC2208(9)       
- **Z8T_ZM3E4_LCDDWIN_TMC220X@ALL_3DTouch** Upgraded all motor drivers to TMC2208(9) and upgrade 3d touch leveling sensor  
- **Z8T_ZM3E4_LCDDWIN_TMC2225@ALL** Upgraded XYZ motor drivers to TMC2225

### LCD128x64
Firmware for 12864 LCD screen

- **Z8T_ZM3E4_V201.zip** the Z8T only upgraded control board to ZM3E4
