#### :green_book: Firmware Upload Steps
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:  ***MENU>>Control>>Restore Defaults***

#### :heavy_exclamation_mark:ATTENTION PLEASE:heavy_exclamation_mark:
#### DWIN LCD MENU
1. You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware 2.0 or last version, otherwise it will cause some display issue on LCD MENU. 
2. The firmware of DWIN display screen is downward compatible, please upgrade to the latest version.
3. About how to upgrade firmware of DWIN LCD screen ,please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN#upload-firmware)  
4. About the new LCD screen function description, please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/blob/main/TFT-LCD/LCD-DWIN/user_guide/LCD-DWIN%20MENU%20Description%20V3.pdf)  

# Release Note
--------------
## V3.x.x
:warning: You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware 2.0 or last version, otherwise it will cause some display issue on LCD MENU, about details, please refer to [:point_up: **here**](#dwin-lcd-menu)

### [:arrow_down: Z8PM4Pro V3.4.1](./Z8PM4ProMK1_V3_4_1.zip)
- **Date:** 2023-11-29
- [**CHG**] Improved the issue of sudden jumps when adjusting values

### [Z8PM4Pro V3.2.4 beta :arrow_down:](./Z8PM4ProMK1_V3_2_4.zip)
- **Date:** 2022-12-14
- [**CHG**] Correct temperature when the temperature is less than 20 degree

### Z8PM4Pro V3.2.3 [:arrow_down:Download](./Z8PM4ProMK1_V3_2_3.zip)
- **Date:** 2022-12-03
- [**NEW**] Add to support M73 gcode command to obtain more accurate printing progress percent and printing remaining time. **[:point_right: How to set in PrusaSlicer](M73_PrusaSlicer.jpg)**

### Z8PM4Pro V3.2.2 [:arrow_down:Download](./Z8PM4ProMK1_V3_2_2.zip)
- **Date:** 2022-11-18
- [**CHG**] Don't turn off power if the hotend/hotbed can't heat to the setting temperature.

### Z8PM4Pro V3.2.1 [:arrow_down:Download](./Z8PM4ProMK1_V3_2_1.zip)
- **Date:** 2022-11-15
- [**CHG**] Correct shows temperature of hotend and hotbed

### Z8PM4Pro V3.2.0 [:arrow_down:Download](./Z8PM4ProMK1_V3_2_0.zip)
- **Date:** 2022-11-11
- [**NEW**] Add a "Auto Unload" menu, turn on it, the printer will unload filament automatically if the printing is abort.    
  --**This feature only for 4-IN-1-OUT Non-Mix Color Hotend**.   
- [**NEW**] Display the print elapsed time xxxHxxM after printing finished.
- [**CHG**] Set the home-offset default value to 0
- [**CHG**] Modify print remain time on LCD screen
- [**BUG**] Fixed the system crashes on gradient and random mixing color printing.
- [**BUG**] Fixed temperature instability issue on over 230 degreeC.

### Z8PM4Pro V3.1.0 [:arrow_down:Download](./Z8PM4ProMK1_V3_1_0.zip)
- **Date:** 2022-10-18
- [**BUG**] Fixed the bug HOME Z offset after did "Baby Step Z".

### Z8PM4Pro V3.0.0 [:arrow_down:Download](./Z8PM4ProMK1_V3_0_0.zip)
- [**NEW**] Upgrade to [:point_up: **DWIN LCD MENU V3**](#dwin-lcd-menu)
- [**NEW**] Add a FlowRate Menu in "Print>>Tune" menu

--------------
## V2.x.x
:warning: You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware 2.0 or last version, otherwise it will cause some display issue on LCD MENU, about details, please refer to [:point_up: **here**](#dwin-lcd-menu)

### Z8PM4Pro V2.2.0 [:arrow_down:Download](./Z8PM4ProMK1_V2_3_0.zip)
- **Date:** 2022-10-18
- [**BUG**] Fixed the bug HOME Z offset after did "Baby Step Z".

### Z8PM4Pro V2.2.0 [:arrow_down:Download](./Z8PM4ProMK1_V2_2_0.zip)
- **Date:** 2022-09-26
- [**NEW**] Add a "HOME OFFSET" menu, support to adjust the X/Y/Z HOME offset on LCD screen.
- [**CHG**] Change "PID auto tune" feature.
- [**CHG**] Delete "HOT end Max temperature" setting menu, but you still need to take care when setting temperature of the mixing color hotend.
- [**BUG**] Fixed some bugs.

### Z8PM4Pro V2.1.0 [:arrow_down:Download](./Z8PM4ProMK1_V2_1_0.zip)
- **Date:** 2022-04-25
- [**BUG**] Correct print and remine time

### Z8PM4Pro V2.0.0 [:arrow_down:Download](./Z8PM4ProMK1_V2_0_0.zip)
- **Date:** 2022-04-25
- [**NEW**] Upgrade to **DWIN LCD MENU V2** [:point_up:](#dwin-lcd-menu)
- [**NEW**] Auto return to print menu if doesn't operature on tune menu for a while.
- [**NEW**] Add "View User Guide" on INFO menu.
- [**NEW**] Add "View Update News" on INFO menu.
- [**NEW**] Show a QRcode for visiting the ESP3D website page while WiFi is connected (WiFi module is required).
- [**NEW**] Auto save "baby Z offset adjustment" on the previous printing. 
- [**NEW**] Add "Extr. Sequence" menu to exchange the extruders while hotend type is Non-mixing hotend.
- [**NEW**] Auto disable motors after did "Stop printing".

- [**BUG**] Extend the waiting time to confirm the connection of WiFi.
- [**BUG**] fix the bug of setting max hotend temperature.    

- [**CHG**] Change "Mixing Feature" to "Hotend Type" on "Control>>Configure" menu.
- [**CHG**] Add Nozzle temperature setting on filament menu.
- [**CHG**] Correct HOTEND temperature.
- [**CHG**] Change the menu [HOTEND Temp] to [Nozzle Temp].   
- [**CHG**] Change LCD message while temperature error occured.

--------------
## V1.x.x
### Z8PM4Pro V1.3.0 [:arrow_down:Download](./Z8PM4ProMK1_V1_3_0.zip)
- **Date:** 2022-03-2
- ***First release***