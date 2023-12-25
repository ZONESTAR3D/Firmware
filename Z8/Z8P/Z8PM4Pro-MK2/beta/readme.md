#### :green_book: Firmware Upload Steps
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:  ***MENU>>Control>>Restore Defaults***

----
# :warning: Notice
Starting from version 1.5.0, the firmware of **MK2** and **MK2A** has been separated because **Z8PM4Pro-MK2** and **Z8PM4Pro-MK2A** used different control board - **Z8PM4Pro-MK2** used **ZM3E4 V2.1** and **Z8PM4Pro-MK2** used **ZM3E4 V3.0**. If the firmware does not correspond to the control board version, the temperature measurement results may not be accurate.    
Please select the corresponding firmware based on the model of your machine. Regarding how to distinguish between **Z8PM4Pro-MK2** and **Z8PM4Pro-MK2A**, please refer to [**:link: this link**](https://github.com/ZONESTAR3D/Z8P/tree/main?tab=readme-ov-file#z8p-mk2-has-been-upgraded-to-z8p-mk2a-since-2024-the-main-upgrades-of-z8p-mk2a).    
:pushpin: If your machine is MK2, but you have upgraded to a ZM3E4 V3.0, you should choose the firmware for MK2A.

----
# Release Note
### [ :arrow_down: Z8PM4-MK2 V1.5.0 beta](./Z8PM4MK2_V1_5_0.zip)
### [ :arrow_down: Z8PM4-MK2A V1.5.0 beta](./Z8PM4MK2A_V1_5_0.zip)
- **Date:** 2023-12-25
- [**CHG**] Support to access the SD card files from USB.      
  :pushpin: Hint:      
  - Do not access the SD card during printing.
  - The speed of accessing the SD card through USB is about 300KB/S. If the file is large, please be patient to wait for the access to be completed.
  - If the SD card cannot be found when inserting USB, please restart the 3D printer and unplug the USB cable to try again.


### [ :arrow_down: Z8PM4-MK2 V1.4.3 beta](./Z8PM4MK2_V1_4_3.zip)
- **Date:** 2023-11-29
- [**CHG**] Improved the issue of sudden jumps when adjusting values on LCD screen.

### [ :arrow_down: Z8PM4-MK2 V1.4.2 beta](./Z8PM4MK2_V1_4_2.zip)
- **Date:** 2023-08-23
- [**CHG**] Remove the independent E-step setting since it is not very compatible with the color mixing feature. 

### [ :arrow_down: Z8PM4-MK2 V1.4.1 beta](./Z8PM4MK2_V1_4_1.zip)
- **Date:** 2023-08-22
- [**BUG**] Solve the problem of some machines mistakenly displaying the maximum temperature or even crashing / auto shutting down during printing due to temperature flipping of the hotbed and hotend.

-----
### :warning:Removed some previously released firmware that may have this issue.

#### ~~[Z8PM4-MK2 V1.4.0 beta]~~
- **Date:** 2023-08-15
- [**CHG**] Build on new PlatformIO core 6.0.
- [**CHG**] Change temperature watch period and hysteresis. 
- [**CHG**] Correct Steps/mm of extruders.

#### ~~[Z8PM4-MK2 V1.3.6 beta]~~
- **Date:** 2023-08-12
- [**CHG**] Optimize configure menu more.
- [**BUG**] Fix bugs on random mixing features.

#### ~~[Z8PM4-MK2 V1.3.5 beta ]~~
- **Date:** 2023-08-11
- [**CHG**] Optimize Configure menu.
- [**CHG**] Optimize Mixer Menu.

#### ~~[Z8PM4-MK2 V1.3.4 beta ]~~
- **Date:** 2023-08-10
- [**BUG**] Fix some known bugs on power loss recovery feature.
- [**CHG**] Change "Configre" menu, shows grey color when the feature is unavailable.

#### ~~[Z8PM4-MK2 V1.3.3 beta]~~
- **Date:** 2023-08-08
- [**CHG**] Improved processing logic for high and low temperature error alarms.
- [**CHG**] Increase the knob running speed for selecting menu options on the main menu.

#### ~~[Z8PM4-MK2 V1.3.2 beta]~~
- **Date:** 2023-08-05
- [**BUG**]Fix the issue where the machine crashes when starting the gradient mixing during printing. 
- [**CHG**]Add debounce for measuring hot end and hot bed temperature.

#### ~~[Z8PM4-MK2 V1.3.1 beta]~~
- **Date:** 2023-07-24
- [**NEW**]Enable the function of separately adjusting parameters such as steps/mm for each extruder    
  - **Menu**: Control>>Motion    
  - **Gcode**: M92 Tn Exxx.xx 

-----
### [:arrow_down: Z8PM4-MK2 V1.2.1](./Z8PM4MK2_V1_2_1.zip)
- **Date:** 2023-04-26
- [BUG]Fix a bug on doing "Prepare>>Move>>Extruder All".

### [:arrow_down: Z8PM4-MK2 V1.2.0](./Z8PM4MK2_V1_2_0.zip)
- **Date:** 2023-04-06
- [NEW]Add a laser menu, about the detail, please refer to [**:point_right:here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/Laser_Engraving#two-turn-on-the-laser-engine-feature).
- [CHG]Change the initlize mix rate table (suit for Whit+Cyan+Magenta+Yellow)
- [BUG]Fix a bug, it will cause the printer auto shutdown when doing auto mixing
