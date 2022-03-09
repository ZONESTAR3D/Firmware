## Firmware Upload Steps:
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:
MENU>>config>>Restore Defaults

## Release Note
### Z9V5Pro V2.4.0 beta
#### :warning: You must to upgrade the DWIN LCD screen firmware before upgrade this firmware, otherwise it will cause some display issue on LCD MENU. About how to upgrade firmware of DWIN LCD screen ,please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN#upload-firmware)
- **Date:** 2022-03-09
- [**NEW**] Upgrade to DWIN LCD MENU V2 [**Read the guide**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/blob/main/TFT-LCD/LCD-DWIN/user_guide/LCD-DWIN%20MENU%20Description%20V2.pdf)
- [**NEW**] Add a "Mixing Feature" to switch on/off mixing feature.
- [**NEW**] Add a "Extr.Sequence" menu to exchange the extrders sequence (only work on Non-mixing hotend).  

### Z9V5Pro V2.3.2 beta
- **Date:** 2022-03-08
- [**CHG**] Correct HOTEND temperature.
- [**CHG**] Change the menu [HOTEND Temp] to [Nozzle Temp].   
- [**NEW**] Auto save "baby Z offset adjustment" on the previous printing. 
- [**NEW**] Auto disable motors after did "Stop printing".

### Z9V5Pro_MK3 V2.3.1 beta
- **Date:** 2022-02-25
- [**BUG**] fix the bug of setting max hotend temperature.  
- [**CHG**] Change LCD message while temperature error occured.  

### Z9V5Pro_MK3 V2.3.0 beta
- **Date:** 2022-01-07
- [**New**]Add "Hotend PID tune" menu.  
- [**CHG**]Optimize the setting of motion to improve the printing quality.  
- [**CHG**]Optimize menu display characters.
- [**CHG**]Optimize automatic test display and process.

### Z9V5Pro_MK3 V2.2.2 beta
- **Date:** 2021-12-30
- [**BUG**] Add Base Heigth settings for repeat printing feature. 

### Z9V5Pro_MK3 V2.2.1 beta
- **Date:** 2021-12-28
- [**New**] Add auto repeat printing feature. 

### Z9V5Pro_MK3 V2.1.3 beta
- **Date:** 2021-12-15 
- [**CHG**] Auto HOME when do "Catch Z probe offset" and "Bed auto leveling" on LCD screen

### Z9V5Pro_MK3 V2.1.2 beta
- **Date:** 2021-12-13 
- [**BUG**] Initlize the current Extruder to #1 while starting print from SD card.   

### Z9V5Pro_MK3 V2.1.1 beta
- **Date:** 2021-12-11 
- [**New**] force to do once HOME while start bed leveling
- [**CHG**] Change MAX_AUTORETRACT to 20 (from 10 ). to solve the issue that the automatic extraction does not work while slicing set the "retraction length is bigger than 10 mm". About the setting of MAX_AUTORETRACT, please refer to  [**here**](https://marlinfw.org/docs/configuration/configuration.html#firmware-retraction)  

### Z9V5Pro_MK3 V2.1.0 beta 
- **Date:** 2021-12-01 
- [**New**] Add a "***Control>>configre>>Max HOTEND Temp***" menu, so that you can upgrade to high temperature hotend. **ATTETION: Overheating may damaged the hotend, ensure your hotend can work in that temperature before set the temperature.**  
- [**New**] Add a "***Control>>configre>>PID AutoTune***" menu to auto tune the PID parameter.   **NOTE: While do PID autotune, please wait until the LCD show PID Auto tune finished!**  
- [**CHG**] Correct the temperature table of hotend and hotbed to get more accurate temperature display.  
