#### :warning: !ATTETION PLEASE! 
#### You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware to 2.1.0 or last version, otherwise it will cause some display issue on LCD MENU. For more details, please refer to :point_right: [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN). 

----
#### :green_book: Firmware Upload Steps
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:  ***MENU>>Control>>Restore Defaults***

----
## Release Note
### V3.2.5 beta 
### Upgraded 3DTouch [:arrow_down:](./Z9V5Pro_3DTouch_V3_2_5_beta.zip)
### Upgraded TMC220x motor drivers [:arrow_down:](./Z9V5Pro_TMC220xALL_V3_2_5_beta.zip)
### Upgraded 3DTouch and TMC220x motor drivers [:arrow_down:](./Z9V5Pro_3DTouch_TMC220xALL_V3_2_5_beta.zip)
- **Date:** 2023-03-31
- [**NEW**] Add a "Auto Unload" menu, turn on it, the printer will unload filament automatically if the printing is abort.    
  --**This feature only work on E4 (4-IN-1-OUT Non-Mix Color) Hotend**.   
- [**NEW**] Display the print elapsed time xxxHxxM after printing finished.
- [**NEW**] Add a "laser" item in "confire" menu, Turn it on when you use the laser engraving function.      
- [**NEW**] Add a "troubleshooting" item in "infor" menu, click it to pop up a QRcord of troubleshooting link.     
- [**NEW**] Add to support M73 gcode command to obtain more accurate printing progress percent and printing remaining time. **[:point_right: How to set in PrusaSlicer](M73_PrusaSlicer.jpg)**
- [**CHG**] Doesn't turn off power if the hotend/hotbed can't heat to the setting temperature.
- [**CHG**] Correct shows temperature of hotend and hotbed
- [**CHG**] Correct temperature when the temperature is less than 20 degree
- [**CHG**] Change the home-offset default value
- [**CHG**] Modify print remain time on LCD screen
- [**BUG**] Fixed the system crashes on gradient and random mixing color printing.
- [**BUG**] Fixed temperature instability issue on over 230 degreeC.

**About laser item**    
For ZM3E4 control board, laser engraving PWM and the extruder fan PWM  of the 3D printer used the same pin of MCU. When it be used as a extruder fan PWM of the 3D printing function, at the instant the fan is turned on, the PWM pin should output a short time high level (it is 500ms in the firmware) to help the fan to rotate successfully. However, this is not good at the engraving resolution. After adding this menu, the user can turn the "laser" on on LCD MENU when using laser engraving, so the machine don't out put a short time high level while the PWM output.

### Z9V5Pro3DTouch V3.1.1 beta [:arrow_down:](./Z9V5Pro_3DTouch_V3_1_1_beta.zip)
- **Date:** 2022-10-12
- [**NEW**] Add a "HOME OFFSET" menu, support to adjust the X/Y/Z HOME offset on LCD screen.
- [**NEW**] Add a "flow rate" tune menu when priinting from SD card  
- [**NEW**] Add a menu to adjust the brightness of LOGO backlight
- [**CHG**] Change "PID auto tune" feature.
- [**CHG**] Delete "HOT end Max temperature" setting menu, please take care to the highest work temperature of your hotend.
- [**CHG**] Optimize automatic test display.
- [**CHG**] Allow to move extruder motors without heating the nozzle.
- [**CHG**] Allow to move extruder motors while printing is paused.
- [**BUG**] Fixed some known bugs.

-----
## Wiring
![](./Z9V5Pro%2B3DTouch_wiring.jpg)

