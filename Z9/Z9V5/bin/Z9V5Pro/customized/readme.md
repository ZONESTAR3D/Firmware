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
#### [Release Note](https://github.com/ZONESTAR3D/Firmware/tree/master/Z9/Z9V5/bin/Z9V5Pro/beta)
### :warning:Note
If you upgraded TMC220x motor drivers, please use [:point_right:the firmware for Z9V5Pro-MK3](https://github.com/ZONESTAR3D/Firmware/tree/master/Z9/Z9V5/bin/Z9V5Pro-MK3/customized).

### Upgraded 3DTouch bed leveling sensor 
- **[:arrow_down:Z9V5Pro_3DTouch_V3_5_1](./Z9V5Pro_3DTouch_V3_5_1.zip)**
- **[:arrow_down:Z9V5Pro_3DTouch_V3_3_0](./Z9V5Pro_3DTouch_V3_3_0.zip)**
- **[:arrow_down:Z9V5Pro_3DTouch_V3_2_5](./Z9V5Pro_3DTouch_V3_2_5.zip)**
- **[:arrow_down:Z9V5Pro_3DTouch_V3_1_1](./Z9V5Pro_3DTouch_V3_1_1.zip)**

### Upgraded 500x500
- **[:arrow_down:Z9V5ProMax_V3_5_2](./Z9V5ProMax_V3_5_2.zip)**
<!-- - **[:arrow_down:Z9V5ProMax_V3_5_1](./Z9V5ProMax_V3_5_1.zip)** -->
- **[:arrow_down:Z9V5ProMax_V3_3_0](./Z9V5ProMax_V3_3_0.zip)**

### Upgraded 500x500 and Dual Gear Extruders (2x left hand and 2x right hand)
- **[:arrow_down:Z9V5ProMax_BMGLR_V3_5_2](./Z9V5ProMax_BMGLR_V3_5_2.zip)**

### Upgraded 500x500 and 3DTouch bed leveling sensor 
- **[:arrow_down:Z9V5ProMax_3DTouch_V3_5_1](./Z9V5ProMax_3DTouch_V3_5_1.zip)**
- **[:arrow_down:Z9V5ProMax_3DTouch_V3_3_0](./Z9V5ProMax_3DTouch_V3_3_0.zip)**

### Upgrade ZL-Sensor bed leveling sensor 
- **[:file_folder: ZLSENSOR](./ZLSENSOR/readme.md)**

### Change Hotend Maximus work temperature to 300℃ 
- **[:arrow_down:Z9V5Pro_V3_5_1_300C](./Z9V5Pro_V3_5_1_300C.zip)**     
#### :warning: NOTE:
1. Please confirm that your hot end can support this temperature before use.
2. If your control board is the ZM3E4 V1 V2.0 or V2.1 version, please modify the resistance R34 on the motherboard to 0 ohms (originally 22 ohms), otherwise it may not be stable when the temperature exceeds 280 degrees Celsius.     
![](./R34.jpg)

-----
## Wiring
![](./Z9V5Pro%2B3DTouch_wiring.jpg)

