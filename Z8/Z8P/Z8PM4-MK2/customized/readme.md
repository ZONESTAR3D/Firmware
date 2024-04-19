## Firmware for upgraded some optional features
- **Upgraded 3DTouch bed leveling sensor [:arrow_down:Z8PM4MK2_3DTouch_V1_4_3](./Z8PM4MK2_3DTouch_V1_4_3.zip)**
- **Upgraded 3DTouch and TMC2209 motor drivers [:arrow_down:Z8PM4MK2_TMC220x_3DTouch_V1_4_3](./Z8PM4MK2_TMC220x_3DTouch_V1_4_3.zip)**
- **Upgraded Dual Gear Extruders(4x right hand) [:arrow_down:Z8PM4MK2_BMG_V1_4_3](./Z8PM4MK2_BMG_V1_4_3.zip)**
- **Upgraded 3DTouch and Dual Gear Extruders(4x right hand) [:arrow_down:Z8PM4MK2_3DTouch_BMG_V1_4_3](./Z8PM4MK2_3DTouch_BMG_V1_4_3.zip)**
- **Upgraded TMC220x motor drivers and Dual Gear Extruders (4x right hand) [:arrow_down:Z8PM4MK2_TMC220x_BMG_V1_4_3](./Z8PM4MK2_TMC220x_BMG_V1_4_3.zip)**
- **Upgraded TMC220x motor drivers, 3DTouch and Dual Gear Extruders(4x right hand) [:arrow_down:Z8PM4MK2_TMC220x_3DTouch_BMG_V1_4_3](./Z8PM4MK2_TMC220x_3DTouch_BMG_V1_4_3.zip)**

----
## Wiring
Connect the 3d touch bed leveling sensor to EXP1  
![](Wiring_3DTouch.png)

----
## User Guide
#### 3DTouch/BLTouch
About how to install and debug the 3DTouch/BLTouch, please refer to [:book:**this guide.**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/Bed_Leveling_Sensor/3DTouch)

#### Dual Gear Extruder
About how to install Dual Gear Extruder, please refer to [:book:**this guide.**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/blob/main/Dual_Gear_Extruder/Z8P.md)

----
## :green_book: Firmware Upload Steps
1. Download the zip file and unzip it.
2. Copy firmware.bin to the root directory of Micro-SD card. :bulb: [*How to copy files to the root directory of an SD card*](https://techques.net/how-to-copy-a-file-to-the-root-of-an-sd-card/)      
NOTE: If there is a "old_fw.bin" in the SD card, delete it first.      
3. Power off the printer and plug the Micro-SD card into socket on control board.
4. Power on the printer, push the power button and wait about 30 seconds.
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:  ***MENU>>Control>>Restore Defaults***
