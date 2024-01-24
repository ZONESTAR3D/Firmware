## How to upload firmware to the control board
1. Download Upload tool from this link: https://github.com/ZONESTAR3D/Firmware/tree/master/Firmware_Upload_tool_for_ZRIB_ZMIB
2. refer to the guide in the link and upload firmware to the control board.

- **If you have a 128x64 LCD screen please do the below steps on LCD MENU after upload firmware:**
1. **Initliza EEPROM:**  *Configuaration>>Advance settings>>Initlize EEPROM* 
2. **Fine Tune PID parameter of hotend:**     *Configuaration>>Advance settings>>Temperature>> PID AutoTune E1: 200*, set to 200 if you used to print PLA filament and 240 degree if you used to print ABS filament, and then wait about 10 minute until it finished.  
- **If you use TFT-LCD screen,  please do the below steps:**    
1. **Initliza EEPROM:** copy ResetNVRAM.gcode to the SD card and print it.  
2. **Fine Tune PID parameter of hotend:** if you used to print PLA filament, copy CalNozzleTemp_200c.gcode to the SD card and print it, if you used to print ABS filament, CalNozzleTemp_240c.gcode and print it.

---
## About Features:
### Deafult features:
1. **TITAN Extruder:**  
In the older version, Z9 use a default extruder part, from 2020-05, we have upgraded it to Titan exturder, by using Titan extuder, it can provide more torque to extruder this feature is default on since V5.3   
2. **Power off after printer:**      
A POWER push button (Non self locking button) can be connected to the control board, when power on, you need to push button until LCD show LOGO, add a M81 command in the ENDcode of slicing software, it can realize automatic shutdown after printing. 
**NOTE:** It is only shut down the control board, but not the Power supply
  **Hardware:**  
  - a push button should connect to the power on jumper.
  - a LED connect to VCC & GND
this feature is default on since V5.3.x  

### Option features:
- **TMC220x:**  
TMC220x motor dirver is reversed on the work direction with A4988 

- **TFT-LCD:**  
TFT-LCD screen use EXP1 connector pins of +5/GNG/D16/D17,it is connected to UART2 of ATMEGA2560  
	- **D16<=>TXD2**  
	- **D17<=>RXD2**  
**ATTENTION:** for ZRIB control board, TFT-LCD and LCD12864 can't work at the same time   

- **3Dtouch:**  
Defaulf Z9 use a proximity sensor as a bed leveling sensor, if you upgrade it to BLtouch or 3D touch, please choose this firmware  
  **Hardware:**  
	- D4 - SERVO PIN (S PIN of 3DTouch)
	- D11 - Probe Pin (Z- PIN of 3DTouch)

- **Dual Z Driver:**  
Defaulf Z9 use a sync single Z drive system, you can upgrade it to dual Z motor with/without dual Z endstop.  
	



