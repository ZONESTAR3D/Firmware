#### Firmware Upload Steps:
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:
MENU>>config>>Restore Defaults

## Release Note
### Z9V5Pro_MK3_RePrint_V2_3_1_beta
- **Date:** 2022-02-26
- [**BUG**] Fix the bug of setting max hotend temperature.  
- [**CHG**] Change LCD message while temperature error occured.  

### Z9V5Pro_MK3_RePrint_V2_3_0_beta
- **Date:** 2022-01-05
- [**New**]Add "Hotend PID tune" menu.  
- [**CHG**]Optimize the setting of motion to improve the printing quality.  
- [**CHG**]Optimize menu display characters.
- [**CHG**]Optimize automatic test display and process.

### Z9V5Pro_MK3 V2.2.3 beta
- **Date:** 2021-01-06
- [**BUG**] Add M183 command to print the next file. 

### Z9V5Pro_MK3 V2.2.2 beta
- **Date:** 2021-01-04
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
