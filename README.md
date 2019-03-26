# CNC-project
This application is made for the purpose of maneuvering a simple 2 bar linkage in a CNC fashion. The program has the ability to decode NC codes(or G codes) and translate that into mechanical movement.
The interface was written in C# and the algorithms were written in C.

NC Code executed
All descriptions describe the motion or position of the tool tip (tip of the bar linkage)
Position described in millimeters
Motion is commented after each line starting with a "//" symbol

//The tooltip is initialized at the position X=75 Y=75 Z=0
N100 G90 G01 X75 Y0 Z100 F50
//Linear movement from (75,75,0) to (75,0,100)
N100 G91 G02 G19  J0 k-50 X-150  A1800 
//Does 5 complete clockwise revolutions in the Y-Z plane that starts at (75,0,100) and ends at (-75, 0,100)
// 以 Z=50 Y=0為軸心 由X=75往X=-75運動 轉1800度 (5 revolutions)
G04 10000 
//Dwell time of 10 seconds: system stops for10000ms (10 sec)
N100 G90 G01 X0 Y75 Z0
//Linear movement from (-75,0,100) to (0,75,0)
N100 G91 G02 G17 I 0 J-75 Z20  A1800 
//Does 5 complete clockwise revolutions in the X-Y plane that starts at (0,75,0) and ends at (0,75,150) 
// 以 X=0 Y=0 為軸心 由Z=0往Z=150運動 轉1800度 (5revolutions)
M00 
//Program stop 按 cycle start 繼續執行
//M00: Program stop continue by pressing the CYCLE START button
N100 G90 G01 X0 Y75 Z100 
//Linear movement from (0,75,150) to (0,75,100)
N100 G91 G03 G18 i0 j0 k -50 Y-150 A1800
//螺旋線 以 X=0 Z=50 為軸心 由Y=75往Y=-75運動 轉1800度 (5圈)
//Does 5 complete clockwise revolutions in the X-Z plane that starts at (0,75,100) and ends at (0,-75,100) 
M01
//Optional program stop 若在執行這行前按m01則在此造成M00的效果
//M01: Optional program stop that could be triggered by pressing the m01 button before the program reaches this line
N100 G90 G01 X75 Y75 Z0
//Linear movement from (0,-75,100)  to (75,75,0)
M01
N100 G90 G01 X -75 Y75 Z0
//Linear movement from (75,75,0) to (-75,75,0)
N100 G90 G01 X-75 Y-75 Z0
//Linear movement from(-75,75,0) to (-75,-75,0)
N100 G90 G01 X75 Y-75 Z0
//Linear movement from(-75,-75,0) to (75,-75,0)
N100 G90 G01 X -75 Y75 Z0
//Linear movement from(75,-75,0) to (-75,75,0)
M30
//M30: End of program/return to start

G-code stands for “geometric code,” and follows some variation of the alpha numeric pattern:

N## G## X## Y## Z## F##  M##

N: Line number
G: Motion
X: X-axis position
Y: Y-axis position
Z: Z-axis position
F: Feed rate
M: Miscellaneous functions
I and J: Incremental center of an arc
R: Radius of an arc

G01:Linear Feed
G02:Clockwise Interpolation
G90: Absolute positioning.
G91: Incremental(Relative) Positioning.
