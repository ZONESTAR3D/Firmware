# ***Release Note***
- 2021-1-18  Z9V5Pro_V1_0_0.bin 	First issue
           Z9V5_V1_0_0_EN.bin 	First issue


- 2021-1-26  Z9V5Pro_V1_0_1.bin.
           Z9V5_V1_0_1_EN.bin. 
1.Dwin screen refreshes the display after receiving m166 m167 instruction;
2.Automatic retraction speed modification;
3.fixed some other known bugs;

- 2021-2-4   Z9V5Pro_V1_0_3.bin.
1.Add the function of all extruders moving at the same time in the move menu;
2.fixed some other known bugs;

- 2021-2-25   Z9V5Pro_V1_0_4
1.Modify the bug of manual extrusion of extruder in the move menu;
2.Modify the display of several menu names;

- 2021-3-9   Z9V5Pro_V1_0_5
1.Modifying bed leveling display；
2.Fix several known bugs

- 2021-3-18   Z9V5Pro_V1_0_6
1.Add WIFI function；

- 2021-4-18   Z9V5Pro_V1_0_7
[CHG] Improve the auto leveling feature for glass bed
Following the below steps to do:
1. Adjust the Z axis adjust screws (left and right) to the bottom as far as possible
2. Do Level corners(Menu>>Prepare>>Bed Levling), let the 4 corners on the same heigth as far as possible
3. copy level_test_310.gcode file to SD card and print it, if the bed is enough leveling, do need to enable bed auto leveling feature.
4. Turn on the auto leveling feature(MENU>>Config>>configure>>Auto Leveling: ON)
5. Remove the glass
6. do Menu>>Prepare>>Bed Levling>>Catch Z-offset
7. do Menu>>Prepare>>Bed Levling>>AutoLevling
8. Print "level_test_310.gcode" file again to check.

PS: if you find the nozzle is too Heigth/Low when printing the first layer, Redunce/Add the coating thickness value on menu (Config>>configure>>Coating Thickness)

- 2021-5-15   Z9V5Pro_V1_0_8_beta
[CHG]1. Save WiFi On Off
[CHG]2. Remove unactived menu option of config when printing from SD card

- 2021-6-19   Z9V5Pro_V1_1_0
[CHG]1. Optimize the menu arrangement and display effect.


[CHG]2. Fix the confirmation logic of WiFi module.

[CHG]
3. Optimize automatic leveling function:

3.1. Add probe offset setting (usually, if the catch offset effect is not good and the height of the nozzle is not suitable when printing the first layer after auto leveling, you need to adjust babystepz. You can add babystep value to probezofaffset and do auto leveling again)


3.2 Add Probing heigh table display for automatic leveling.


For more description of the auto leveling function, please refer to the directory "bed auto leveling"
[CHG]4. Change the text of the menu item "bed coasting" to "home Z offset"


- [BUG]5. Fixed several known bugs

- 2021-6-24   Z9V5Pro_V1_1_1_beta
[CHG]Set the highest temperature of hotend to 260 degree

- 2021-6-26   Z9V5Pro_V1_1_2_beta
[BUG]fix the bug on powerloss recovery and pause print

- 2021-07-07   Z9V5Pro_V1_2_0_beta
[NEW]Add filament Load/Unload menu, please refer to "LCD-DWIN MENU Description V1_2.pdf"
[NEW]Add WiFi BaudRate setting menu, please refer to "How to Change WiFi BaudRate.pdf"

- 2021-07-14   Z9V5Pro_V1_2_4
[NEW]Add feedback on menu scroll
[BUG]fix the disply issue when G29 command in the gcode file
[BUG]fix the issue on filament run out when mixing printing 
[CHG]Improbe menu operature (auto return to the last item)

- 2021-07-15   Z9V5Pro_V1_2_5
[BUG]fix the issue on power loss recovery

- 2021-07-15   Z9V5Pro_V1_2_6
[BUG]fix the issue on filament run out

- 2021-11-03   Z9V5Pro_V1_2_7
[NEW]fix the issue on auto testing
NOTE: move the cursor to the "Info>>Data:xx-xx-xx" and click the knob 5 time to start an auto testing process
