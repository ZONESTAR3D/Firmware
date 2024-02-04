## Parts picture
If the printer used different parts, the control board need to be uploaded different firmware. If you don't ensure that which part used, please click the part name below to watch its picture.
- **Control Board: [:art: ZM3E4](https://github.com/ZONESTAR3D/Control-Board/blob/main/32bit/ZM3E4.jpg)**
- **LCD Screen: [:art: DWIN 4.3" TFT-LCD](../../../../../partpic/DWIN_LCD.jpg)**
- **Extruder: [:art: Metal Extruder](../../../../../partpic/EM4.jpg) , [:art: Titan Extruder](../../../../../partpic/Titan.jpg) or [:art: BGM Dual Gear Extruder](../../../../../partpic/bgm.jpg)**
- **Bed Leveling Sensor: [:art: PL-08N](../../../../../partpic/PL08N.jpg) or [:art: 3DTouch or BLtoch](../../../../../partpic/3dtouch.jpg)**
- **Motor Driver Module: [:art: A4988](../../../../../partpic/A4988.jpg), [:art: TMC2208](../../../../../partpic/TMC2208.jpg) [:art: TMC2209](../../../../../partpic/TMC2209.jpg) or [:art: TMC2225](../../../../../partpic/TMC2225.jpg)**

## Firmware Description
### [:arrow_down: Z9M3_ZM3E4V3_LCDDWIN_TITAN_TMC220x@All](./Z9M3_ZM3E4V3_LCDDWIN_TITAN_TMC220x@All.zip)
- **Control board:** ZM3E4V3.x
- **LCD screen:** DWIN 4.3" TFT-LCD
- **Extruder:** Titan Extruder
- **Motor Drivers:** TMC2208 or TMC2209 used to all axis
- **Bed Leveling Sensor:** PL-08N
### [:arrow_down: Z9M3_ZM3E4_LCDDWIN_TITAN](./Z9M3_ZM3E4_LCDDWIN_TITAN.zip)
- **Control board:** ZM3E4(V1.0, V2.0. V2.1)
- **LCD screen:** DWIN 4.3" TFT-LCD
- **Extruder:** Titan Extruder
- **Motor Drivers:** A4988 used to XYZ axis and Extruder's motors 
- **Bed Leveling Sensor:** PL-08N
### [:arrow_down: Z9M3_ZM3E4_LCDDWIN_TITAN_TMC220x%40XYZ](./Z9M3_ZM3E4_LCDDWIN_TITAN_TMC220x%40XYZ.zip)
- **Control board:** ZM3E4(V1.0, V2.0. V2.1)
- **LCD screen:** DWIN 4.3" TFT-LCD
- **Extruder:** Titan Extruder
- **Motor Drivers:** TMC2208 or TMC2209 used to XYZ axis motors and A4988 used to Extruders
- **Bed Leveling Sensor:** PL-08N
### [:arrow_down: Z9M3_ZM3E4_LCDDWIN_TITAN_TMC220x@XYZ_3DTouch](./Z9M3_ZM3E4_LCDDWIN_TITAN_TMC220x%40XYZ_3DTouch.zip)
- **Control board:** ZM3E4(V1.0, V2.0. V2.1)
- **LCD screen:** DWIN 4.3" TFT-LCD
- **Extruder:** Titan Extruder
- **Motor Drivers:** TMC2208 or TMC2209 used to XYZ axis motors and A4988 used to Extruders motors
- **Bed Leveling Sensor:** 3DTouch or BLtoch
### [:arrow_down: Z9M3_ZM3E4_LCDDWIN_TMC2225@ALL](./Z9M3_ZM3E4_LCDDWIN_TMC2225%40ALL.zip)
- **Control board:** ZM3E4(V1.0, V2.0. V2.1)
- **LCD screen:** DWIN 4.3" TFT-LCD
- **Extruder:** Metal Extruder
- **Motor Drivers:** TMC2208 or TMC2209 used to XYZ axis and Extruders motors
- **Bed Leveling Sensor:** PL-08N
### [:arrow_down: Z9M3_ZM3E4_LCDDWIN_TITAN_TMC2225@ALL](./Z9M3_ZM3E4_LCDDWIN_TITAN_TMC2225%40ALL.zip)
- **Control board:** ZM3E4(V1.0, V2.0. V2.1)
- **LCD screen:** DWIN 4.3" TFT-LCD
- **Extruder:** Titan Extruder
- **Motor Drivers:** TMC2208 or TMC2209 used to XYZ axis and Extruders motors
- **Bed Leveling Sensor:** PL-08N


-----
### Firmware Upload Steps
1. Download and unzip the firmware zip file
2. Copy firmware.bin to the root directoy of Micro-SD card
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, wait about 30 seconds (need to push the DC power switch if you have installed it)
5. Reset the EEPROM after uploaded frimware:    
  `MENU>>Contol>>Restore defaults`