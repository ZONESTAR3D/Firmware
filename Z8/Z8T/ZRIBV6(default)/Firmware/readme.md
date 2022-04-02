### How to upload firmware to ZRIBV6 control board
- **Windows**: 
Please refer to [**here**](https://github.com/ZONESTAR3D/Firmware/tree/master/Firmware_Upload_tool_for_ZRIB_ZMIB).  
- **Macos or Linux** Please upload firmware by cura, refer to this [**video toturial**](https://www.youtube.com/watch?v=I7Kn7YI0fIo)  

# Release Note:
## Version: V2.2.0 beta
- **Date:**    2022-04-02  
- **NOTE:** 
You must to upgrade the DWIN LCD screen firmware before upgrading the printer firmware to 2.2.0 or last version, otherwise it will cause some display issue on LCD MENU. 
About how to upgrade firmware of DWIN LCD screen ,please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN#upload-firmware)  
About the new LCD screen function description, please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/blob/main/TFT-LCD/LCD-DWIN/user_guide/LCD-DWIN%20MENU%20Description%20V2.pdf)  
- [**BUG**] Extend the waiting time to confirm the connection to prevent misjudgment (Connecting fail).
- [**BUG**] fix the bug of setting max hotend temperature.
- [**BUG**] Initlize the current Extruder to #1 while starting print from SD card.    
- [**NEW**] Upgrade to DWIN LCD MENU V2
- [**NEW**] Auto save "baby Z offset adjustment" on the previous printing. 
- [**NEW**] Auto disable motors after did "Stop printing".
- [**NEW**] Add a "Extr.Sequence" menu to exchange the extrders sequence (only work on Non-mixing hotend).  
- [**New**] Add "Hotend PID tune" menu.  
- [**New**] force to do once HOME while start bed leveling
- [**CHG**] Add Nozzle temperature setting on filament menu.
- [**CHG**] Correct HOTEND temperature.
- [**CHG**] Change the menu [HOTEND Temp] to [Nozzle Temp].   
- [**CHG**] Change LCD message while temperature error occured.
- [**CHG**] Optimize the setting of motion to improve the printing quality.  
- [**CHG**] Optimize menu display characters.
- [**CHG**] Optimize automatic test display and process.
- [**CHG**] Auto HOME when do "Catch Z probe offset" and "Bed auto leveling" on LCD screen
- [**CHG**] Change MAX_AUTORETRACT to 20 (from 10 ). to solve the issue that the automatic extraction does not work while slicing set the "retraction length is bigger than 10 mm". About the setting of MAX_AUTORETRACT, please refer to  [**here**](https://marlinfw.org/docs/configuration/configuration.html#firmware-retraction)  

## Version: V2.1.0
- **Date:**    2021-07-08  
- **NOTE:** 
- [**CHG**] Change the BLtouch(3DTouch) wiring, about detail, please refer to the readme file in "3DTouch" directory.

## Version: V2.0.0
- **Date:**    2021-07-08  
- **NOTE:** 
- [**BUG**] Add leveling measure points to improve bed leveling accuracy.  
  
## Version: V1.8.1
- **Date:**    2021-01-10    
- **NOTE:**   
- [**NEW**] Modify random mixing feature:  
    1.1. add a "Height" parameter, When the z-axis height change is greater than or equal to this value, the color mixing ratio change is performed once  
    1.2. add a "Extruders" parameter, it means how many extruders involved in random mixing;  
    when Extruders = 1,switch between the all of extruders randomlly.  
    when Extruders = 2, extruder 1 and 2 will be mixed on a random mixing ratio.  
    when Extruders = 3, extruder 1,2 and 3 will be mixed on a random mixing ratio.  
- [**NEW**] Auto reset the VTOOL setting to default if printed complete from SD card.  

## Version: V1.7.3  
- **Date:**    2020-11-09  
- **NOTE:**  
- [**BUG**] fix an issue of power loss resume:  
when auto leveling feature is enable, it doesn't work well when resume from power loss  

## Version: V1.7.1
- **Date:**    2020-11-05  
- **NOTE:**  
- [**BUG**] fix an issue: when the file in the root directory on SD card, 
- [**BUG**] fix "power loss fail resume" can't start to work.



