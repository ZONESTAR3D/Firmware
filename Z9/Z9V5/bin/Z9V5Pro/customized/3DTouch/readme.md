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
