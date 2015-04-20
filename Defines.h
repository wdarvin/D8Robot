#include <math.h>
#define RADTODEG 57.2957795

#define POWER 10
#define TURNPOWER 10
#define HEADINGCOUNTS 4
#define COUNTS 10
#define LINEACC .5
#define TURNACC .75
#define TIMEOUT 10.
#define INITIALX
#define INITIALY
#define INITIALHEADER

#define TIMEOUT 10.
//Power to move the robot backwards (not the direction of the forklift
#define MPOWER -30
//Power to rotate the robot
#define TPOWER 30
#define TPOWERPOSTBAG 15
//Power to lift the fork upwards
#define SPOWER 22
//timeout for pulse functions
#define TIMEOUT1 1.
#define TIMEOUT2 2.
#define TIMEOUT3 3.
#define TIMEOUT4 4.
#define TIMEOUT5 5.
#define TURN90COUNTS 196
#define TURN45COUNTS 96
#define BUTTONXCORRECT 15.3
//THE number of counts between button presses(from blue to white, etc.)
#define BLUEWHITE 7
#define BLUERED 9
#define WHITEBLUE 7
#define WHITERED 3
#define REDBLUE 11
#define REDWHITE 3
//the angle of the forklift for each button
#define BLUEFORKANGLE 45.
#define WHITEFORKANGLE 45.
#define REDFORKANGLE 180.

#define CRANKTIMEOUT 25.

#define TRACTHRESHOLD 20.
#define RPSCOUNTOUT 50
//the threshold for the optosensor encoder
#define OPTOTHRESHOLD .35
