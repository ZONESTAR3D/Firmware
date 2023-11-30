#### :green_book: Firmware Upload Steps
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:  ***MENU>>Control>>Restore Defaults***

#### :heavy_exclamation_mark:ATTETION PLEASE:heavy_exclamation_mark:
#### DWIN LCD MENU
1. You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware 2.0 or last version, otherwise it will cause some display issue on LCD MENU. 
2. The firmware of DWIN display screen is downward compatible, please upgrade to the latest version.
3. About how to upgrade firmware of DWIN LCD screen ,please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN#upload-firmware)  
4. About the new LCD screen function description, please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/blob/main/TFT-LCD/LCD-DWIN/user_guide/LCD-DWIN%20MENU%20Description%20V3.pdf)  

# Release Note
--------------
## V3.x.x
:warning: You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware 2.0 or last version, otherwise it will cause some display issue on LCD MENU, about details, please refer to [:point_up: **here**](#dwin-lcd-menu)

### [:arrow_down: Z8PM4Pro V3.4.1](./Z8PM4Pro_V3_4_1.zip)
- **Date:** 2023-11-29
- [**CHG**] Improved the issue of sudden jumps when adjusting values

### [:arrow_down: Z8PM4Pro V3.4.0](./Z8PM4Pro_V3_4_0.zip)
- **Date:** 2023-09-09
- [**CHG**] Build on new PlatformIO core 6.0.
- [**CHG**] Optimize Configure menu.
- [**CHG**] Optimize Mixer Menu.
- [**NEW**] Enable the function of separately adjusting parameters such as steps/mm for each extruder    
- [**CHG**] Improved processing logic for high and low temperature error alarms.
- [**CHG**] Increase the knob running speed for selecting menu options on the main menu.
- [**CHG**] Correct Steps/mm of extruders.
- [**BUG**] Fix some known bugs on power loss recovery feature.
- [**BUG**] Fix the issue where the machine crashes when starting the gradient mixing during printing. 

### [:arrow_down: Z8PM4Pro V3.3.1](./Z8PM4Pro_V3_3_1.zip)
- **Date:** 2023-04-26
- [BUG]Fix a bug on doing "Prepare>>Move>>Extruder All".

### [Z8PM4Pro V3.3.0 beta :arrow_down:](./Z8PM4Pro_V3_3_0.zip)
- **Date:** 2023-04-06
- [NEW]Add a laser menu, about the detail, please refer to [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/Laser_Engraving#two-turn-on-the-laser-engine-feature)
- [CHG]Change the initlize mix rate table (suit for Whit+Cyan+Magenta+Yellow)
- [BUG]Fix a bug, it will cause the printer auto shutdown when doing auto mixing

### [Z8PM4Pro V3.2.4 beta :arrow_down:](./Z8PM4Pro_V3_2_4.zip)
- **Date:** 2022-12-14
- [**CHG**] Correct temperature when the temperature is less than 20 degree

### Z8PM4Pro V3.2.3 [:arrow_down:Download](./Z8PM4Pro_V3_2_3.zip)
- **Date:** 2022-12-03
- [**NEW**] Add to support M73 gcode command to obtain more accurate printing progress percent and printing remaining time. **[:point_right: How to set in PrusaSlicer](M73_PrusaSlicer.jpg)**

### Z8PM4Pro V3.2.2 [:arrow_down:Download](./Z8PM4Pro_V3_2_2.zip)
- **Date:** 2022-11-18
- [**CHG**] Don't turn off power if the hotend/hotbed can't heat to the setting temperature.

### Z8PM4Pro V3.0.0 [:arrow_down:Download](./Z8PM4Pro_V3_0_0.zip)
- [**NEW**] Upgrade to [:point_up: **DWIN LCD MENU V3**](#dwin-lcd-menu)
- [**NEW**] Add a FlowRate Menu in "Print>>Tune" menu
