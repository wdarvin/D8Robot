#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include <FEHRPS.h>
#include "Time.h"

#define POWER 10
#define TURNPOWER 10
#define COUNTS 5
#define LINEACC .5
#define TURNACC .5
#define TIMEOUT 10

//initialization statements
//initialization statements
ButtonBoard buttons(FEHIO::Bank3);

DigitalEncoder rEncoder(FEHIO::P2_0);
DigitalEncoder lEncoder(FEHIO::P2_1);

AnalogInputPin CdS (FEHIO::P0_0);

FEHMotor ForkHeight (FEHMotor::Motor0);
FEHMotor rMotor(FEHMotor::Motor2);
FEHMotor lMotor(FEHMotor::Motor3);

FEHServo ForkAngle (FEHServo::Servo0);

Time time;

//demo code for showing functions to kids and best engineered judges
void runDemo()
{
	while(true)
	{
		if (buttons.RightPressed())
		{
			ForkAngle.SetDegree(180);
		}
		if (buttons.LeftPressed())
		{
			ForkAngle.SetDegree(0);
		}
		if (buttons.MiddlePressed())
		{
			ForkAngle.SetDegree(90);
		}
		if (buttons.MiddlePressed() && buttons.LeftPressed())
		{
			ForkHeight.SetPercent(30);
			Sleep(.5);
			ForkHeight.Stop();
		}
		if (buttons.MiddlePressed() && buttons.RightPressed())
		{
			ForkHeight.SetPercent(-30);
			Sleep(.5);
			ForkHeight.Stop();
		}
	} 
}

//returns an int with button order
void getOrder(char order)
{
	int red = RPS.RedButtonOrder();
	int blue = RPS.BlueButtonOrder();
	int white = RPS.WhiteButtonOrder();


    order[red-1] = 'R';
    order[blue-1] = 'B'
    order[white-1] = 'W';
}

//returns boolean for if all buttons are pressed
bool allButtonsPressed()
{
	if(RPS.RedButtonPressed() && RPS.BlueButtonPressed() && RPS.WhiteButtonPressed())
	{
		return true;
	}
	return false;
}

//returns an expected encoder count for a given distance in inches
int encodeLength(float dist)
{
	return dist*33.7408; //test but it should truncate the float to an int
}

//wait until the light changes to start the course
void waitForLightChange()
{
    LCD.WriteLine("WAITING");
    while(CdS.Value()>.6);
    LCD.WriteLine("LIGHT CHANGE");
}


//pulse forward measuring using encoders
//for use withen the rpsForward command
void pulseForward(int percent, int counts, int timeout)
{
	time.tic();
	//Rest encoder counts
	rEncoder.ResetCounts();
	lEncoder.ResetCounts();
	
	//set both motors to the desired percen
	rMotor.SetPercent(percent);
	lMotor.SetPercent(percent);
	
	//move each motor forward the expected number of counts
	while((lEncoder.Counts()+rEncoder.Counts()) < counts*2 && time.toc()<timeout);
	
	//turn motors off
	rMotor.Stop();
	lMotor.Stop();
}

//pulse right with the sleep function
void sleepRight(int percent)
{
	//set both motors to the desired percent
	rMotor.SetPercent(percent);
	lMotor.SetPercent(-percent);
	
	Sleep(30);
	
	rMotor.Stop();
	lMotor.Stop();
}

//pulse left with the sleep function
void sleepLeft(int percent)
{
	//set both motors to the desired percent
	rMotor.SetPercent(-percent);
	lMotor.SetPercent(percent);
	
	Sleep(30);
	
	rMotor.Stop();
	lMotor.Stop();
}

//pulse left measuring using encoders
//for use withen the rpsTurn command
void pulseLeft(int percent, int counts, int timeout)
{
	time.tic();
	//Rest encoder counts
	rEncoder.ResetCounts();
	lEncoder.ResetCounts();
	
	//set both motors to the desired percent
	rMotor.SetPercent(percent);
	lMotor.SetPercent(-percent);
	
	//move each motor forward the expected number of counts
	while((lEncoder.Counts()+rEncoder.Counts()) < counts*2 && time.toc()<timeout);

	//turn motors off
	rMotor.Stop();
	lMotor.Stop();
}

//pulse right measuring using encoders
//for use withen the rpsTurn command
void pulseRight(int percent, int counts, int timeout)
{
	time.tic();
	//Rest encoder counts
	rEncoder.ResetCounts();
	lEncoder.ResetCounts();
	
	//set both motors to the desired percent
	rMotor.SetPercent(-percent);
	lMotor.SetPercent(percent);
	
	//move each motor forward the expected number of counts
	while((lEncoder.Counts()+rEncoder.Counts()) < counts*2 && time.toc()<timeout);

	//turn motors off
	rMotor.Stop();
	lMotor.Stop();
}

//use RPS to check x location while robot is facing the +x direction
void rpsXPlus(float x_coordinate)
{
	int count = 0;
	//check whether the robot is within an acceptable range
    while(RPS.X() < x_coordinate - LINEACC || RPS.X() > x_coordinate + LINEACC)
    {
    	  LCD.Write(count);
        if(RPS.X() > x_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(-POWER,COUNTS,TIMEOUT);
        LCD.WriteLine("CHECK BACK");
        }
        else if(RPS.X() < x_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(POWER,COUNTS,TIMEOUT);
        LCD.WriteLine("CHECK FORWARD");
        }
        count++;
	}
}

//use RPS to check x location while robot is facing the -x direction
void rpsXMinus(float x_coordinate)
{
	int count = 0;
	//check whether the robot is within an acceptable range
    while(RPS.X() < x_coordinate - LINEACC || RPS.X() > x_coordinate + LINEACC)
    {
    		LCD.Write(count);
    		if(RPS.X() > x_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(POWER,COUNTS,TIMEOUT);
        LCD.WriteLine("CHECK BACK");
        }
        else if(RPS.X() < x_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(-POWER,COUNTS,TIMEOUT);
        LCD.WriteLine("CHECK FORWARD");
        }
        count++;
	}
}


//use RPS to check y location while robot is facing the -y direction
void rpsYMinus(float y_coordinate)
{
	int count = 0;
	//check whether the robot is within an acceptable range
    while(RPS.Y() < y_coordinate - LINEACC || RPS.Y() > y_coordinate + LINEACC)
    {
    		LCD.Write(count);
        if(RPS.Y() > y_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(POWER,COUNTS,TIMEOUT);
        LCD.WriteLine("CHECK BACK");
        }
        else if(RPS.Y() < y_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(-POWER,COUNTS,TIMEOUT);
        LCD.WriteLine("CHECK FORWARD");
        }
        count++;
	}
}

//use RPS to check y location while robot is facing the +y direction
void rpsYPlus(float y_coordinate)
{
	int count = 0;
	//check whether the robot is within an acceptable range
    while(RPS.Y() < y_coordinate - LINEACC || RPS.Y() > y_coordinate + LINEACC)
    {
        if(RPS.Y() > y_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(-POWER,COUNTS,TIMEOUT);
        LCD.WriteLine("CHECK BACK");
        }
        else if(RPS.Y() < y_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(POWER,COUNTS,TIMEOUT);
        LCD.WriteLine("CHECK FORWARD");
        }
        count++;
	}
}


//turn using rps and turn subfunctions
void rpsTurn(float heading)
{
	int count = 0;
	while(RPS.Heading() < heading - TURNACC || RPS.Heading() > heading + TURNACC)
	{
		LCD.Write(count);
		if(RPS.Heading() > heading)
		{
			//pulse the motors for a short duration in the correct direction
			sleepRight(TURNPOWER);
			//pulseRight(TURNPOWER,COUNTS,TIMEOUT);
			LCD.WriteLine("HEADING CHECK RIGHT");
		}
		else if(RPS.Heading() < heading)
		{
			sleepLeft(TURNPOWER);
			//pulseLeft(TURNPOWER,COUNTS,TIMEOUT);
			LCD.WriteLine("HEADING CHECK LEFT");
      }
      count++:
   } 
}
