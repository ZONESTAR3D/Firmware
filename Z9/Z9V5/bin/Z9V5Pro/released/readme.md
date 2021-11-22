# ***Release Note***
## Z9V5Pro V1.2.7 
- **Date:** 2021-11-19 
- [**BUG**] fix the issue on auto testing  
***Auto testing feature: move the cursor to the "Info>>Data:xx-xx-xx" and click the knob 5 time to start an auto testing process***      

## Z9V5Pro V1.2.6 
- **Date:** 2021-07-15  
- [**BUG**] fix the issue on filament run out

## Z9V5Pro V1.2.5 
- **Date:** 2021-07-15   
- [**BUG**] fix the issue on power loss recovery  
- [**NEW**]Add feedback on menu scroll
- [**CHG**]Improbe menu operature (auto return to the last item)
- [**CHG**]Change leveling table to 5x5 grid and improve the accuracy of automatic leveling
- [**BUG**]fix the display issue when G29 command in the gcode file
- [**BUG**]fix the issue on filament run out when mixing printing 
- [**BUG**]fix several known bugs

## Z9V5Pro V1.2.4 
- **Date:** 2021-07-14
- [**NEW**]Add feedback on menu scroll  
- [**BUG**]fix the disply issue when G29 command in the gcode file  
- [**BUG**]fix the issue on filament run out when mixing printing   
- [**CHG**]Improbe menu operature (auto return to the last item)  

## Z9V5Pro V1.2.0 
- **Date:** 2021-07-07
- [**NEW**] Add filament Load/Unload menu, please refer to "user guide\LCD-DWIN MENU Description V1_2.pdf"
- [**NEW**] Add WiFi BaudRate setting menu, please refer to "user guide\How to Change WiFi BaudRate.pdf"  

## Z9V5Pro V1.1.2 
- **Date:** 2021-6-26 
- [**BUG**] fix the bug on powerloss recovery and pause print

## Z9V5Pro V1.1.1 
- **Date:** 2021-6-24  
- [**CHG**] Set the highest temperature of hotend to 260 degree

## Z9V5Pro V1.1.0 
- **Date:** 2021-6-19
- [**CHG**] Optimize the menu arrangement and display effect.
- [**CHG**] Fix the confirmation logic of WiFi module.
- [**CHG**] Optimize automatic leveling function:
  - Add probe offset setting (usually, if the catch offset effect is not good and the height of the nozzle is not suitable when printing the first layer after auto leveling, you need to adjust babystepz. You can add babystep value to probezofaffset and do auto leveling again).
  - Add Probing heigh table display for automatic leveling.
  - For more description of the auto leveling function, please refer to the directory "bed auto leveling"
- [**CHG**]Change the text of the menu item "bed coasting" to "home Z offset"
- [**BUG**] Fixed several known bugs  

## Z9V5Pro V1.0.8 
- **Date:** 2021-5-15   
- [**CHG**] Save WiFi On Off  
- [**CHG**] Remove unactived menu option of config when printing from SD card  

## Z9V5Pro V1.0.7 
- **Date:** 2021-4-18   
- [**CHG**] Improve the auto leveling feature for glass bed
Following the below steps to do:  
  - Adjust the Z axis adjust screws (left and right) to the bottom as far as possible
  - Do Level corners(Menu>>Prepare>>Bed Levling), let the 4 corners on the same heigth as far as possible
  - Copy level_test_310.gcode file to SD card and print it, if the bed is enough leveling, do need to enable bed auto leveling feature.
  - Turn on the auto leveling feature(MENU>>Config>>configure>>Auto Leveling: ON)
  - Remove the glass
  - Do Menu>>Prepare>>Bed Levling>>Catch Z-offset
  - Do Menu>>Prepare>>Bed Levling>>AutoLevling
  - Print "level_test_310.gcode" file again to check.  
***NOTE: if you find the nozzle is too Heigth/Low when printing the first layer, Redunce/Add the coating thickness value on menu (Config>>configure>>Coating Thickness)***   


## Z9V5Pro V1.0.6 
- **Date:** 2021-3-18   
- [**NEW**] Add WIFI function

## Z9V5Pro V1.0.5 
- **Date:** 2021-3-9   
- [**CHG**] Modifying bed leveling display；
- [**BUG**] Fix several known bugs

## Z9V5Pro V1.0.4 
- **Date:** 2021-2-25   
- [**CHG**] Modify the bug of manual extrusion of extruder in the move menu;
- [**CHG**] Modify the display of several menu names;

## Z9V5Pro V1.0.3 
- **Date:** 2021-2-4   
- [**NEW**] Add the function of all extruders moving at the same time in the move menu;
- [**BUG**] fixed some other known bugs;

## Z9V5Pro V1.0.1 
- **Date:** 2021-1-26
- [**CHG**] Dwin screen refreshes the display after receiving m166 m167 instruction;
- [**CHG**] Automatic retraction speed modification;
- [**BUG**] fixed some other known bugs;

## Z9V5Pro V1.0.0 
- **Date:** 2021-1-15
- ***First release***





