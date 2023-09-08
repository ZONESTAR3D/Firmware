#### :green_book: Firmware Upload Steps
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:  ***MENU>>Control>>Restore Defaults***

----
# Release Note
### [:arrow_down: Z8PM4-MK2 V1.4](./Z8PM4MK2_V1_4.zip)
- **Date:** 2023-08-23
- [**CHG**] Build on new PlatformIO core 6.0.
- [**CHG**] Optimize Configure menu.
- [**CHG**] Optimize Mixer Menu.
- [**NEW**] Enable the function of separately adjusting parameters such as steps/mm for each extruder    
- [**CHG**] Improved processing logic for high and low temperature error alarms.
- [**CHG**] Increase the knob running speed for selecting menu options on the main menu.
- [**CHG**] Correct Steps/mm of extruders.
- [**BUG**] Fix some known bugs on power loss recovery feature.
- [**BUG**] Fix the issue where the machine crashes when starting the gradient mixing during printing. 

### [:arrow_down: Z8PM4-MK2 V1.2](./Z8PM4MK2_V1_2.zip)
- **Date:** 2023-04-26
- [NEW]Add a laser menu, about the detail, please refer to [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/Laser_Engraving#two-turn-on-the-laser-engine-feature)
- [CHG]Change the initialize mix rate table (suit for Whit+Cyan+Magenta+Yellow)
- [BUG]Fix a bug, it will cause the printer auto shutdown when doing auto mixing

### [:arrow_down: Z8PM4-MK2 V1.1](./Z8PM4MK2_V1_1.zip)
- **Date:** 2022-12-14
- [CHG]Correct the temperature when the temperature is less than 20 degree

### [:arrow_down: Z8PM4-MK2 V1.0](./Z8PM4MK2_V1_0.zip)
- **Date:** 2022-12-03
- ***First release***