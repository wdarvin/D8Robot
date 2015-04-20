#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include <FEHRPS.h>
#include <FEHBattery.h>
#include "Time.h"

//initialization statements
ButtonBoard buttons(FEHIO::Bank3);

AnalogInputPin CdS (FEHIO::P0_0);
AnalogInputPin Optosensor(FEHIO::P1_0);

DigitalEncoder rEncoder(FEHIO::P2_0);
DigitalEncoder lEncoder(FEHIO::P2_1);
DigitalInputPin Microswitch(FEHIO::P2_4);

FEHMotor ForkHeight (FEHMotor::Motor0);
FEHMotor rMotor(FEHMotor::Motor2);
FEHMotor lMotor(FEHMotor::Motor3);

FEHServo ForkAngle (FEHServo::Servo7);

Time time;
Time time2;
Time time3;
Time time4;
Time time5;
Time time6;

//Changes the hight of the forklift through the encoders
void ForkLiftHeightEncode(float percent, int maxcounts) {
    int count = 0;
    time6.tic();
    if (Optosensor.Value() > OPTOTHRESHOLD){
        while (count < maxcounts && time6.toc() < TIMEOUT4){
            ForkHeight.SetPercent(percent);
            while (Optosensor.Value() > OPTOTHRESHOLD && time6.toc() < TIMEOUT4){
                }
            count++;
            if (count < maxcounts && time6.toc() < TIMEOUT4){
                while (Optosensor.Value() < OPTOTHRESHOLD && time6.toc() < TIMEOUT4){
                }
                count++;
            }
        }
    } else if (Optosensor.Value() < OPTOTHRESHOLD){

        while (count < maxcounts && time6.toc() < TIMEOUT4){
           ForkHeight.SetPercent(percent);
           while (Optosensor.Value() < OPTOTHRESHOLD && time6.toc() < TIMEOUT4){
           }
           count++;
           if (count < maxcounts && time6.toc() < TIMEOUT4){
               while (Optosensor.Value() > OPTOTHRESHOLD && time6.toc() < TIMEOUT4){
               }
               count++;
           }
       }
    }
    ForkHeight.Stop();
}


//Demo code for public showings
void Demo()
{
   int counter = 0;
	while(true) {

		 if (buttons.RightPressed()) {
			  ForkAngle.SetDegree(180);
		 }
		 if (buttons.LeftPressed()) {
			  ForkAngle.SetDegree(45);
		 }
		 if (buttons.MiddlePressed()) {
			  ForkAngle.SetDegree(100);
		 }
		 if (buttons.MiddlePressed() && buttons.LeftPressed()) {
			  ForkLiftHeightEncode(-SPOWER, 1);
			  counter++;
		 }
		 if (buttons.MiddlePressed() && buttons.RightPressed()) {
			  ForkLiftHeightEncode(SPOWER, 1);
			  counter--;
		 }

		 LCD.Clear();
		 LCD.Write("Counts: ");
		 LCD.WriteLine(counter);
		 Sleep(.1);
	}

}


//returns an int with button order
void getOrder(char order[])
{
	int red = RPS.RedButtonOrder();
	int blue = RPS.BlueButtonOrder();
	int white = RPS.WhiteButtonOrder();


    order[red-1] = 'R';
    order[blue-1] = 'B';
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


//returns an expected encoder count for a given distance in inches
int ForkencodeLength(float dist)
{
    return dist*3.638; //test but it should truncate the float to an int
}


//wait until the light changes to start the course
void waitForLightChange(float cds)
{
    LCD.WriteLine("WAITING");
    time.tic();
    while(CdS.Value() > cds && time.toc() < 30.) {
        LCD.WriteLine(CdS.Value());
    }
    LCD.WriteLine("LIGHT CHANGE");
}


//pulse forward measuring using encoders
//for use withen the rpsForward command
void pulseForward(int percent, int counts, double timeout)
{
	//Rest encoder counts
	rEncoder.ResetCounts();
	lEncoder.ResetCounts();
	
	//set both motors to the desired percen
	rMotor.SetPercent(percent);
	lMotor.SetPercent(percent);
	
	//move each motor forward the expected number of counts
    time.tic();
    while((lEncoder.Counts() + rEncoder.Counts()) / 2. < counts && time.toc() < timeout)
    {}
	
	//turn motors off
	rMotor.Stop();
	lMotor.Stop();
}

//pulse left with sleep method
void sleepLeft(int percent)
{
    rMotor.SetPercent(percent);
    lMotor.SetPercent(-percent);

    Sleep(20);

    rMotor.Stop();
    lMotor.Stop();
}



//pulse left with sleep method
void sleepRight(int percent)
{
    rMotor.SetPercent(-percent);
    lMotor.SetPercent(percent);

    Sleep(20);

    rMotor.Stop();
    lMotor.Stop();
}



//pulse left measuring using encoders
//for use withen the rpsTurn command
void pulseLeft(int percent, int counts, double timeout)
{
	//Rest encoder counts
	rEncoder.ResetCounts();
	lEncoder.ResetCounts();
	
	//set both motors to the desired percent
	rMotor.SetPercent(percent);
	lMotor.SetPercent(-percent);
	
	//move each motor forward the expected number of counts
    time.tic();
    while((lEncoder.Counts() + rEncoder.Counts()) / 2. < counts && time.toc()  < timeout)
    {}


	//turn motors off
	rMotor.Stop();
	lMotor.Stop();
}



//pulse right measuring using encoders
//for use withen the rpsTurn command
void pulseRight(int percent, int counts, double timeout)
{
	//Rest encoder counts
	rEncoder.ResetCounts();
	lEncoder.ResetCounts();
	
	//set both motors to the desired percent
	rMotor.SetPercent(-percent);
	lMotor.SetPercent(percent);
	
	//move each motor forward the expected number of counts
    time.tic();
    while((lEncoder.Counts() + rEncoder.Counts()) / 2. < counts && time.toc() < timeout)
    {}

	//turn motors off
	rMotor.Stop();
	lMotor.Stop();
}


//use RPS to check x location while robot is facing the +x direction
void rpsXPlus(float x_coordinate)
{
	int count = 0;
	//check whether the robot is within an acceptable range
    time.tic();
    while(RPS.X() < x_coordinate - LINEACC || RPS.X() > x_coordinate + LINEACC && (time.toc() <= TIMEOUT3))
    {
        LCD.Write(count);
        if(RPS.X() < 0) {
           count++;
           if (count > RPSCOUNTOUT) {
              break;
           }
        }

        if(RPS.X() > x_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(POWER,COUNTS,TIMEOUT);
        LCD.Write("CHECK BACK : ");
        LCD.WriteLine(RPS.X());
        }
        else if(RPS.X() < x_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(-POWER,COUNTS,TIMEOUT);
            LCD.Write("CHECK FORWARD : ");
            LCD.WriteLine(RPS.X());
        }
	}
}


//use RPS to check x location while robot is facing the -x direction
void rpsXMinus(float x_coordinate)
{
	int count = 0;
	//check whether the robot is within an acceptable range
    time.tic();
    while(RPS.X() < x_coordinate - LINEACC || RPS.X() > x_coordinate + LINEACC && (time.toc() <= TIMEOUT3))
    {
        if(RPS.X() < 0) {
            count++;
            if (count > RPSCOUNTOUT) {
                break;
            }
        }
        LCD.Write(count);
    		if(RPS.X() > x_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(-POWER,COUNTS,TIMEOUT);
        LCD.Write("CHECK BACK : ");
        LCD.WriteLine(RPS.X());
        }
        else if(RPS.X() < x_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(POWER,COUNTS,TIMEOUT);
        LCD.Write("CHECK FORWARD : ");
        LCD.WriteLine(RPS.X());
        }
	}
}


//use RPS to check y location while robot is facing the -y direction
void rpsYMinus(float y_coordinate)
{
	int count = 0;
	//check whether the robot is within an acceptable range
    time.tic();
    while(RPS.Y() < y_coordinate - LINEACC || RPS.Y() > y_coordinate + LINEACC && (time.toc() <= TIMEOUT3))
    {
        if(RPS.Y() < 0) {
            count++;
            if (count > RPSCOUNTOUT) {
                break;
            }
        }
        LCD.Write(count);
        if(RPS.Y() > y_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(-POWER,COUNTS,TIMEOUT);
        LCD.Write("CHECK BACK : ");
        LCD.WriteLine(RPS.Y());
        }
        else if(RPS.Y() < y_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(POWER,COUNTS,TIMEOUT);
        LCD.Write("CHECK FORWARD :");
        LCD.WriteLine(RPS.Y());
        }
	}
}


//use RPS to check y location while robot is facing the +y direction
void rpsYPlus(float y_coordinate)
{
	int count = 0;
	//check whether the robot is within an acceptable range
    time.tic();
    while(RPS.Y() < y_coordinate - LINEACC || RPS.Y() > y_coordinate + LINEACC && (time.toc() <= TIMEOUT3))
    {
        if(RPS.Y() < 0) {
            count++;
            if (count > RPSCOUNTOUT) {
                break;
            }
        }
        if(RPS.Y() > y_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(POWER,COUNTS,TIMEOUT);
        LCD.Write("CHECK BACK : ");
        LCD.WriteLine(RPS.Y());
        }
        else if(RPS.Y() < y_coordinate)
        {
        //pulse the motors for a short duration in the correct direction
        pulseForward(-POWER,COUNTS,TIMEOUT);
        LCD.Write("CHECK FORWARD :");
        LCD.WriteLine(RPS.Y());
        }
	}
}


//turn using rps and turn subfunctions
void rpsTurn(float heading)
{
    int count = 0;
    time.tic();
    while((RPS.Heading() < heading - TURNACC || RPS.Heading() > heading + TURNACC) && (time.toc() <= TIMEOUT3))
    {
        if(RPS.Heading() < 0) {
            count++;
            if (count > RPSCOUNTOUT) {
                break;
            }
        }
        if(RPS.Heading() > heading)
        {
            //pulse the motors for a short duration in the correct direction
            sleepRight(TURNPOWER);
            LCD.Write("HEADING CHECK RIGHT");
            LCD.WriteLine(RPS.Heading());
        }
        else if(RPS.Heading() < heading)
        {
            sleepLeft(TURNPOWER);
            LCD.Write("HEADING CHECK LEFT");
            LCD.WriteLine(RPS.Heading());
        }
     }
}


void rpsTurnTo0() {
    int count = 0;
    time.tic();
    while(RPS.Heading() > 1.5 && (time.toc() <= TIMEOUT3))
    {
        if(RPS.Heading() < 0) {
            count++;
            if (count > RPSCOUNTOUT) {
                break;
            }
        }
        if(RPS.Heading() < 180)
        {
            //pulse the motors for a short duration in the correct direction
            sleepRight(TURNPOWER);
            //pulseRight(TURNPOWER,count,TIMEOUT);
            LCD.WriteLine("HEADING CHECK RIGHT");
        }
        else if(RPS.Heading() > 180)
        {
            sleepLeft(TURNPOWER);
            //pulseLeft(TURNPOWER,count,TIMEOUT);
            LCD.WriteLine("HEADING CHECK LEFT");
        }
    }
}

//Obsolete Forklift adjust method using timing
void ForkAdjust(float power, float time, float angle) {
    ForkAngle.SetDegree(angle);
    ForkHeight.SetPercent(power);
    Sleep(time);
    ForkHeight.Stop();
}


int CrankCdS(float redblue) {
    int turn = 0;
    LCD.WriteLine(CdS.Value());
    if (CdS.Value() < redblue){
        turn = 0;
        return turn;
    }
    else if (CdS.Value() > redblue && CdS.Value() < .7){
        turn = 1;

        pulseLeft((TPOWER/2.), 24, TIMEOUT1);
        LCD.WriteLine(CdS.Value());

        if (CdS.Value() < redblue){
            turn = 0;
            return turn;
        }
        else {
            pulseRight((TPOWER/2.), 34, TIMEOUT1);
            LCD.WriteLine(CdS.Value());
            if (CdS.Value() < redblue){
                turn = 0;
                return turn;
            }
            else if (CdS.Value() > redblue && CdS.Value() < .7){
                turn = 1;
                rpsTurnTo0();
                if (CdS.Value() < redblue){
                   turn = 0;
                   return turn;
                }
                else if (CdS.Value() > redblue && CdS.Value() < .7){
                   turn = 1;
                }
            }
        }
    }
    else{
        pulseLeft((TPOWER/2.), 24, TIMEOUT1);
        LCD.WriteLine(CdS.Value());

        if (CdS.Value() < redblue){
            turn = 0;
            return turn;
        }
        else {
            pulseRight((TPOWER/2.), 34, TIMEOUT1);
            LCD.WriteLine(CdS.Value());
            if (CdS.Value() < redblue){
                turn = 0;
                return turn;
            }
            else if (CdS.Value() > redblue && CdS.Value() < .7){
                turn = 1;
                rpsTurnTo0();
                if (CdS.Value() < redblue){
                   turn = 0;
                   return turn;
                }
                else if (CdS.Value() > redblue && CdS.Value() < .7){
                   turn = 1;
                }
            }
        }
    }
    return turn;
}


