### How to upload firmware to ZRIBV6 control board
- **Windows**: 
Please refer to [**here**](https://github.com/ZONESTAR3D/Firmware/tree/master/Firmware_Upload_tool_for_ZRIB_ZMIB).  
- **Macos or Linux** Please upload firmware by cura, refer to this [**video toturial**](https://www.youtube.com/watch?v=I7Kn7YI0fIo)  

# Release Note:
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



