#### Firmware Upload Steps:
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware: ***MENU>>Control>>Restore Defaults***

## Release Note
### Z9V5Pro-MK4 V1.1.0 [:arrow_down:](./Z9V5ProMK4_V1_1_0.zip)
- **Date:** 2022-09-26
- [**BUG**] To sollve the PID parameter of hotend stored issue.
- [**NEW**] Add a **"HOME Offset"** menu to replace the **"HOME Z Offset"** menu. It can correct the offset between the nozzle and the original position of the printing platform when printing and do bed leveling. e.g., if you uprgaded a "Direct Drive Extruder" to replace the origin hot end, you can set **"HOME OFFSET X = -15, HOME OFFSET Y = -15"**.  

### Z9V5Pro-MK4 V1.0.6 [:arrow_down:](./Z9V5ProMK4_V1_0_6.zip)
- **Date:** 2022-06-18
- [**BUG**] To solve the misjudgment issue on checking the hot bed when the ambient temperature is low in the automatic test program.
- [**CHG**] Optimize automatic test display.
- [**CHG**] Allow to move extruder motors without heating the nozzle.
- [**CHG**] Allow to move extruder motors while printing is paused.

### Z9V5Pro-MK4 V1.0.5 [:arrow_down:](./Z9V5ProMK4_V1_0_5.zip)
- **Date:** 2022-06-11
- [BUG] fix text display issue on printing pause
- [NEW] Auto return printing menu from tune menu without operation within 8 seconds.

### Z9V5Pro-MK4 V1.0.1 [:arrow_down:](./Z9V5ProMK4_V1_0_1.zip)
- **Date:** 2022-04-09
- [BUG] fix text display issue on printing pause
- [NEW] Auto return printing menu from tune menu without operation within 8 seconds.





