## Firmware for upgraded some optional features
- **Upgraded 3DTouch/BLTouch bed leveling sensor: [:arrow_down:Z8PM4MK2A_3DTouch_V1_5_0](./Z8PM4MK2A_3DTouch_V1_5_0.zip)**
- **Upgraded 3DTouch/BLTouch and TMC2209 motor drivers: [:arrow_down:Z8PM4MK2A_TMC220x_3DTouch_V1_5_0](./Z8PM4MK2_TMC220x_3DTouch_V1_5_0.zip)**

---
#### Wiring
Connect the 3d touch bed leveling sensor to EXP1  
![](Wiring_3DTouch.png)

----
#### :blue_book: [Firmware Release Note](../releasenote.md)   
Detailed information about firmware versions, please refer to [**releasenote.md**](../releasenote.md).

----
#### :green_book: Firmware Upload Steps
1. Download the zip file and unzip it.
2. Copy firmware.bin to the root directory of Micro-SD card. :bulb: [*How to copy files to the root directory of an SD card*](https://techques.net/how-to-copy-a-file-to-the-root-of-an-sd-card/)      
NOTE: If there is a "old_fw.bin" in the SD card, delete it first.      
3. Power off the printer and plug the Micro-SD card into socket on control board.
4. Power on the printer, push the power button and wait about 30 seconds.
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:  ***MENU>>Control>>Restore Defaults***

