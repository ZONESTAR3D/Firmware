## :file_folder:[Released](./released/)
Released firmware are for the mass production machine. If you did not upgrade any features, please use the firmware in this directory. 
:point_right:[**Details of released firmware**](./released/readme.md)
>
**NOTE**:Please upgrade the firmware to V2.1.0 or newer version to the 3d printer if you have upgraded the below features, and set the value to 260 on menu "***Control>Configure>>Max hotend temp.***"    
- **E4(4-IN-1-OUT Non-Mixing color) hotend**  
- **Direct drive extruder**  
- **Single color high flow rate hotend**  
 
## :file_folder:[Beta](./beta/)
Beta firmware have the latest updata firmware, but it may be unstable.
:point_right:[**Details of beta firmware**](./beta/readme.md)


## :file_folder:[Customized](./customized/)
Customized firmware for some customers who upgraded some parts or feature, e.g. 3d touch leveling sensor, etc.
:point_right:[**Details of special firmware**](./customized/readme.md)

----
### Firmware upload steps:
1. Download the zip file and unzip it.
1. Copy firmware.bin to the root directory of Micro-SD card.   
**NOTE:!!if there is a "old_fw.bin" in the SD card, delete it first!!**
1. Power off the printer and plug the Micro-SD card into socket on control board.
1. Power on the printer, push the power button and wait about 30 seconds.
1. Do the below step on LCD screen to initialize EEPROM after upload firmware:  ***MENU>>Control>>Restore Defaults***
