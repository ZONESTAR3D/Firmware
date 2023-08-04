#### :green_book: Firmware Upload Steps
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:  ***MENU>>Control>>Restore Defaults***

----
# Release Note
### [Z8PM4-MK2 V1.3.1 beta :arrow_down: ](./Z8PM4MK2_V1_3_1.zip)
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
