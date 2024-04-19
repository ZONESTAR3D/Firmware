## :warning: ATTENTION
Because the verison of the control board of **Z8PM4Pro-MK2** and **Z8PM4Pro-MK2A** are different, **Z8PM4Pro-MK2** used **ZM3E4 V2.1** and **Z8PM4Pro-MK2A** used **ZM3E4 V3.0**. The need to upload different firmware. If the firmware does not correspond to the control board, the temperature may not be accurate. Please select the corresponding firmware based on the model of your machine. Regarding how to distinguish **Z8PM4Pro-MK2** and **Z8PM4Pro-MK2A**, please refer to [**:book: this link**](https://github.com/ZONESTAR3D/Z8P/tree/main#main-upgrades-of-z8p-mk2a).    
:pushpin: **HINT:** If your machine is **Z8PM4Pro-MK2**, but you have upgraded to a  **ZM3E4 V3.x control board**, you should choose [:point_right:**Z8PM4Pro-MK2A Firmware**](https://github.com/ZONESTAR3D/Firmware/tree/master/Z8/Z8P/Z8PM4-MK2A).


----
## Firmware
- **[:arrow_down: Z8PM4-MK2 V1.5.0](./Z8PM4MK2_V1_5_0.zip)**
- **[:arrow_down: Z8PM4-MK2 V1.4.3](./Z8PM4MK2_V1_4_3.zip)**
- **[:arrow_down: Z8PM4-MK2 V1.4.2](./Z8PM4MK2_V1_4_2.zip)**
- **[:arrow_down: Z8PM4-MK2 V1.4.1](./Z8PM4MK2_V1_4_1.zip)**
- **[:arrow_down: Z8PM4-MK2 V1.2.1](./Z8PM4MK2_V1_2_1.zip)**
- **[:arrow_down: Z8PM4-MK2 V1.2.0](./Z8PM4MK2_V1_2_0.zip)**

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