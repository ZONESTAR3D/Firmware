## Upgrade BMG(Titan) Extruder 
To upgrade [:point_right: **BMG extruder**](https://www.aliexpress.com/item/1005003473360998.html) or [:point_right: **Titan Extruder**](https://www.aliexpress.com/item/1005001678239017.html), your printer can get better quality and greatly reduce the probability of printing defects. If you have upgraded them, please download this firmware to the control board of your machine.    
:arrow_down: [**Download Firmware HEX file**](./Z6BS_BMG_Z300.zip)    
The motor working direction may be reversed, please refer to [**change motor direction by modifing the stepping motor wire**](./Change_motor_working_direction.jpg).

----
## Add bed auto leveling sensor
If you want to add a bed leveling sensor to Z6F(B), please refer to [:point_right: **here**](./withAutoBedLevling/readme.md)

----
## Firmware for damaged motor driver
### Z6BS_XMFault
If the "X axis motor driver" of the control board is damaged, please upload this firmware to the control board and change the wiring.    
:arrow_down: [**Download Firmware HEX file**](./Z6BS_XMFault.zip)   
#### How to wiring
Exchange X axis motor connector to E0 motor connector and exchange E0 motor connector to E1 motor connector.    
![](./Z6BS_XMFAULT_Wiring.png)

-----
### Z6BS_YMFault 
If the "Y axis motor driver" of the control board is damaged, please upload this firmware to the control board and change the wiring.    
:arrow_down: [**Download Firmware HEX file**](./Z6BS_YMFault.zip)   
#### How to wiring
Exchange Y axis motor connector to E0 motor connector and exchange E0 motor connector to E1 motor connector.
![](./Z6BS_YMFAULT_Wiring.png)

-----
### Z6BS_ZMFault
If the "Z axis motor driver" of the control board is damaged, please upload this firmware to the control board and change the wiring.     
:arrow_down: [**Download Firmware HEX file**](./Z6BS_ZMFault.zip)   
#### How to wiring
Exchange Z axis motor connector to E0 motor connector and exchange E0 motor connector to E1 motor connector.    
![](./Z6BS_ZMFAULT_Wiring.png)

-----
### Z6BS_EMFault
If the "Extruder motor driver" of the control board is damaged, please upload this firmware to the control board and change the wiring.        
:arrow_down: [**Download Firmware HEX file**](./Z6BS_EMFault.zip)   
#### How to wiring
Exchange E0 motor connector to E1 motor connector.    
![](./Z6BS_EMFAULT_Wiring.png)
