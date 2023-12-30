## How to upload firmware to ZM3E4 Control board
Please following the below steps to upload the firmware: 
1. Download the zip file and unzip it, you can get a ***firmware.bin*** file.
2. Copy that ***firmware.bin*** to the root directory of Micro-SD card.    
:bell: **Suggest to format the SD card or deleted all files in SD card before copy firmware.bin file**.      
3. Power off the printer and plug the Micro-SD card with firmware.bin file into socket on control board.
4. Power on the printer and wait until you can see the LCD screen shows "ZONESTAR" logo page.
5. Do ***MENU>>Control>>Restore Defaults*** LCD screen to reset settings. 

-----
## Firmware Download Link and Release Note
### Firmware V3.6.0
**Date:** 	 2023-12-30    
#### Release Note
- [**NEW**] Support to access the SD card files from USB Port.    
  :pushpin: Hint:      
  - Do not access the SD card during printing.
  - Must plug the SD card before power on the machine if you need to access it from USB port.
  - If released the SD card from machine, you need to disconnect the USB cable and restart the machine, otherwise you can't find the SD card from PC.
  - The speed of accessing the SD card through USB is about 300KB/S. If the file is large, please be patient to wait for the access to be completed.
#### Firmware download link
- **[:arrow_down: Z9M4 + LCDDWIN](./Z9M4_LCDDWIN_V3_6_0.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Z9M4 + LCDDWIN + BMG Extruders](./Z9M4_LCDDWIN_BMG_V3_6_0.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Upgraded TMC2209 motor drivers @ XYZ axis](./Z9M4_LCDDWIN_TMC220x@XYZ_V3_6_0.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Upgraded TMC2209 motor drivers @ all axis](./Z9M4_LCDDWIN_TMC220x@All_V3_6_0.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Upgraded TMC2209 motor drivers @ all axis and BMG Extruders](./Z9M4_LCDDWIN_BMG_TMC220x%40All_V3_5_2.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down:Upgraded TMC2209 motor drivers @ all axis and 3Dtouch bed leveling sensor](./Z9M4_LCDDWIN_3DTouch_TMC220x%40All_V3_5_2.zip) [:art: Wiring Diagram: Wiring 2](#wiring-1)**
- **[:arrow_down:Upgraded TMC2209 motor drivers @ all axis and 3Dtouch bed leveling sensor and BMG Extruders](./Z9M4_LCDDWIN_BMG_3DTouch_TMC220x@All_V3_5_2.zip) [:art: Wiring Diagram: Wiring 2](#wiring-1)**

-----
### Firmware V3.5.2
**Date:** 	 2023-12-21    
#### Release Note
[**NEW**] Add Laser Menu
#### Firmware download link
- **[:arrow_down: Z9M4 + LCDDWIN](./Z9M4_LCDDWIN_V3_5_2.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Upgraded TMC2209 motor drivers @ XYZ axis](./Z9M4_LCDDWIN_TMC220x%40XYZ_V3_5_2.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Upgraded TMC2209 motor drivers @ all axis](./Z9M4_LCDDWIN_TMC220x%40All_V3_5_2.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Upgraded TMC2209 motor drivers @ all axis and BMG Extruders](./Z9M4_LCDDWIN_BMG_TMC220x%40All_V3_5_2.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down:Upgraded TMC2209 motor drivers @ all axis and 3Dtouch bed leveling sensor](./Z9M4_LCDDWIN_3DTouch_TMC220x%40All_V3_5_2.zip) [:art: Wiring Diagram: Wiring 2](#wiring-1)**
- **[:arrow_down:Upgraded TMC2209 motor drivers @ all axis and 3Dtouch bed leveling sensor and BMG Extruders](./Z9M4_LCDDWIN_BMG_3DTouch_TMC220x@All_V3_5_2.zip) [:art: Wiring Diagram: Wiring 2](#wiring-1)**

-----
### Firmware V3.5.1
**Date:** 	 2023-08-23    
#### Release Note
[**NEW**] Add a "probe offset" item in control menu, to set the offset from probe to nozzle.
[**CHG**] Optimize Configure menu.     
[**CHG**] Optimize Mixer Menu.     
[**CHG**] Change the maximus work temperature of hotend to 300 degreeC.       
[**CHG**] Increase the knob running speed for selecting menu options on the main menu.     
[**CHG**] Correct temperature table of nozzle to get more accurate temperature.     
[**BUG**] Fix the machine crashes issue when set the gradient mixing on printing.     
[**BUG**] Fix some known bugs on power loss recovery feature.     
#### Firmware download link
- **[:arrow_down: Z9M4 + LCDDWIN](./Z9M4_LCDDWIN_V3_5_1.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Upgraded TMC2209 motor drivers @ XYZ axis](./Z9M4_LCDDWIN_TMC220x%40XYZ_V3_5_1.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Upgraded TMC2209 motor drivers @ all axis](./Z9M4_LCDDWIN_TMC220x%40All_V3_5_1.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Upgraded TMC2209 motor drivers @ all axis and BMG Extruders](./Z9M4_LCDDWIN_BMG_TMC220x%40All_V3_5_1.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down:Upgraded TMC2209 motor drivers @ all axis and 3Dtouch bed leveling sensor](./Z9M4_LCDDWIN_3DTouch_TMC220x%40All_V3_5_1.zip) [:art: Wiring Diagram: Wiring 2](#wiring-1)**
- **[:arrow_down:Upgraded TMC2209 motor drivers @ all axis and 3Dtouch bed leveling sensor and BMG Extruders](./Z9M4_LCDDWIN_BMG_3DTouch_TMC220x@All_V3_5_1.zip) [:art: Wiring Diagram: Wiring 2](#wiring-1)**

-----
### Firmware V3.2.3
**Date:** 	 2023-03-23    
#### Firmware download link
- **[:arrow_down: Z9M4 + LCDDWIN](./Z9M4_LCDDWIN_V3_2_3.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Z9M4 + LCDDWIN + TMC220x@XYZ ](./Z9M4_LCDDWIN_TMC220x%40XYZ_V3_2_3.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Z9M4 + LCDDWIN + TMC220x@All ](./Z9M4_LCDDWIN_TMC220x%40All_V3_2_3.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Z9M4 + LCDDWIN + TMC220x@All + BMG Extruder](./Z9M4_LCDDWIN_BMG_TMC220x%40All_V3_2_3.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Z9M4 + LCDDWIN + TMC220x@All + 3DTouch](./Z9M4_LCDDWIN_3DTouch_TMC220x%40All_V3_2_3.zip) [:art: Wiring Diagram: Wiring 2](#wiring-1)**

-----
### Firmware V3.2.2
**Date:** 	 2022-11-24    
#### Release Note
You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware to 3.0.0 or last version, otherwise it will cause some display issue on LCD MENU. For more details, please refer to :point_right: [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN)
[**NEW**] Add a "Auto Unload" menu, turn on it, the printer will unload filament automatically if the printing is abort.    
  --**This feature only work on E4 (4-IN-1-OUT Non-Mix Color) Hotend**.   
[**NEW**] Display the print elapsed time xxxHxxM after printing finished.  
[**CHG**] Don't turn off power if the hotend/hotbed can't heat to the setting temperature.   
[**CHG**] Correct shows temperature of hotend and hotbed.   
[**CHG**] Set the home-offset default value to 0.   
[**CHG**] Modify print remain time on LCD screen.   
[**CHG**] Change "PID auto tune" feature.  
[**BUG**] Fixed the system crashes on gradient and random mixing color printing.  
[**BUG**] Fixed temperature instability issue on over 230 degreeC.  
[**BUG**] Fixed some bugs.  
#### Firmware download link
- **[:arrow_down: Z9M4 + LCDDWIN](./Z9M4_LCDDWIN_V3_2_2.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Z9M4 + LCDDWIN + TMC220x@XYZ ](./Z9M4_LCDDWIN_TMC220x%40XYZ_V3_2_2.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Z9M4 + LCDDWIN + TMC220x@All ](./Z9M4_LCDDWIN_TMC220x%40All_V3_2_2.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Z9M4 + LCDDWIN + TMC220x@All + BMG Extruder](./Z9M4_LCDDWIN_BMG_TMC220x%40All_V3_2_2.zip) [:art: Wiring Diagram: Wiring 1](#wiring-1)**
- **[:arrow_down: Z9M4 + LCDDWIN + TMC220x@All + 3DTouch](./Z9M4_LCDDWIN_3DTouch_TMC220x%40All_V3_2_2.zip) [:art: Wiring Diagram: Wiring 2](#wiring-1)**

-----
### Wiring 1
- **4.3" TFT_LCD (+ WiFi Module)**     
**:warning: WiFi Module is optional**    
![](./LCDDWIN_Wiring1.jpg)

### Wiring 2:
- **4.3" TFT_LCD + 3DTouch (+ WiFi Module)**     
**:warning: WiFi Module is optional**    
![](./LCDDWIN_Wiring2.jpg)


