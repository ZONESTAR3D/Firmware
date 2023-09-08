#### :green_book: Firmware Upload Steps
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:  ***MENU>>Control>>Restore Defaults***

----
# Release Note
### [ :arrow_down: Z8PM4-MK2 V1.4.3 beta](./Z8PM4MK2_V1_4_3.zip)
- **Date:** 2023-09-08
- [**NEW**] Enable the function of separately adjusting parameters for each extruder motors (such as steps/mm)      

### [ :arrow_down: Z8PM4-MK2 V1.4.2 beta](./Z8PM4MK2_V1_4_2.zip)
- **Date:** 2023-08-23
- [**CHG**] Remove the independent E-step setting since it is not very compatible with the color mixing feature. 

### [ :arrow_down: Z8PM4-MK2 V1.4.1 beta](./Z8PM4MK2_V1_4_1.zip)
- **Date:** 2023-08-22
- [**BUG**] Solve the problem of some machines mistakenly displaying the maximum temperature or even crashing / auto shutting down during printing due to temperature flipping of the hotbed and hotend.
#### :warning:Removed some previously released firmware that may have this issue.

### ~~~[Z8PM4-MK2 V1.4.0 beta]~~~
- **Date:** 2023-08-15
- [**CHG**] Build on new PlatformIO core 6.0.
- [**CHG**] Change temperature watch period and hysteresis. 
- [**CHG**] Correct Steps/mm of extruders.

### ~~~[Z8PM4-MK2 V1.3.6 beta]~~~
- **Date:** 2023-08-12
- [**CHG**] Optimize configure menu more.
- [**BUG**] Fix bugs on random mixing features.

### ~~~[Z8PM4-MK2 V1.3.5 beta ]~~~
- **Date:** 2023-08-11
- [**CHG**] Optimize Configure menu.
- [**CHG**] Optimize Mixer Menu.

### ~~~[Z8PM4-MK2 V1.3.4 beta ]~~~
- **Date:** 2023-08-10
- [**BUG**] Fix some known bugs on power loss recovery feature.
- [**CHG**] Change "Configre" menu, shows grey color when the feature is unavailable.

### ~~~[Z8PM4-MK2 V1.3.3 beta]~~~
- **Date:** 2023-08-08
- [**CHG**] Improved processing logic for high and low temperature error alarms.
- [**CHG**] Increase the knob running speed for selecting menu options on the main menu.

### ~~~[Z8PM4-MK2 V1.3.2 beta]~~~
- **Date:** 2023-08-05
- [**BUG**]Fix the issue where the machine crashes when starting the gradient mixing during printing. 
- [**CHG**]Add debounce for measuring hot end and hot bed temperature.

### ~~~[Z8PM4-MK2 V1.3.1 beta]~~~
- **Date:** 2023-07-24
- [**NEW**]Enable the function of separately adjusting parameters such as steps/mm for each extruder    
  - **Menu**: Control>>Motion    
  - **Gcode**: M92 Tn Exxx.xx 

### [:arrow_down: Z8PM4-MK2 V1.2.1](./Z8PM4MK2_V1_2_1.zip)
- **Date:** 2023-04-26
- [BUG]Fix a bug on doing "Prepare>>Move>>Extruder All".

### [:arrow_down: Z8PM4-MK2 V1.2.0](./Z8PM4MK2_V1_2_0.zip)
- **Date:** 2023-04-06
- [NEW]Add a laser menu, about the detail, please refer to [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/Laser_Engraving#two-turn-on-the-laser-engine-feature)
- [CHG]Change the initlize mix rate table (suit for Whit+Cyan+Magenta+Yellow)
- [BUG]Fix a bug, it will cause the printer auto shutdown when doing auto mixing
