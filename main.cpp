#include "Defines.h"
#include "encoderFunctions.h"
#include "getAngle.h"
#include "Saltbag.h"
#include "Buttonpress.h"
#include "ButtonpressInOrder.h"
#include "Crank.h"
#include "Oilpump.h"



int main(){

    LCD.Clear();
    
    //Default calibration values assigned
    float cds1 = .6;
    float bagx =  24.51, bagheading = 225., bagy = 12.48;
    float buttonx = 15.4, buttonheading = 45., buttony = 61.4;
    float crankx = 28.35, cranky = 56.3;
    float pumpx = 11.5, pumpyleft = 13.5, pumpyright = 6.;
    
    //Servo calibration
    ForkAngle.SetMin(500);
    ForkAngle.SetMax(2500);

    ForkAngle.SetDegree(103);

    /*
     *CALIBRATION:
     *
     *press left to get X then right to get Y
     *
     *Set the robot to have to saltbag to be slightly to the right of the forklift
     *Set the robot to the left of the buttons
     *Set the robot to be directly lined up with the crank
    */

    while(!(buttons.MiddlePressed()) ) {
        LCD.Write("Voltage: ");
        LCD.WriteLine(Battery.Voltage());
        LCD.Write("CdS Value: ");
        LCD.WriteLine(CdS.Value());
        LCD.Write("Optosensor Value: ");
        LCD.WriteLine(Optosensor.Value());
        LCD.Write("Microswitch Value: ");
        LCD.WriteLine(Microswitch.Value());
        Sleep(.1);
        LCD.Clear();
    }
    Sleep(1.);


    RPS.InitializeMenu();

    ForkAngle.SetDegree(103);
    while(!(buttons.MiddlePressed()) ) {
    LCD.Write("CdS Value: ");
    LCD.WriteLine(CdS.Value());
    LCD.Write("X: ");
    LCD.WriteLine(RPS.X());
    LCD.Write("Y: ");
    LCD.WriteLine(RPS.Y());
    LCD.Write("Heading: ");
    LCD.WriteLine(RPS.Heading());

    Sleep(.2);
    LCD.Clear();
    }

    Sleep(1.);
        //Input saltbag coordinates
        LCD.WriteLine("Left press to get Saltbag X");
        while (!buttons.LeftPressed()){
            LCD.Write("X: ");
            LCD.WriteLine(RPS.X());
            LCD.Write("Y: ");
            LCD.WriteLine(RPS.Y());
            bagx = RPS.X();
            LCD.Clear();
        }
        LCD.WriteLine("Middle pressed to get Saltbag heading");
        while (!buttons.MiddlePressed()){
            bagheading = RPS.Heading();
        }
        LCD.WriteLine("Right press to get Saltbag Y");
        while (!buttons.RightPressed()){
            LCD.Write("X: ");
            LCD.WriteLine(RPS.X());
            LCD.Write("Y: ");
            LCD.WriteLine(RPS.Y());
            bagy = RPS.Y();
            LCD.Clear();
        }

        //Input button coordinates
        LCD.WriteLine("Left press to get Button X");
        while (!buttons.LeftPressed()){
            LCD.Write("X: ");
            LCD.WriteLine(RPS.X());
            LCD.Write("Y: ");
            LCD.WriteLine(RPS.Y());
            buttonx = RPS.X();
            LCD.Clear();
        }
        LCD.WriteLine("Middle pressed to get Button heading");
        while (!buttons.MiddlePressed()){
            buttonheading = RPS.Heading();
        }
        LCD.WriteLine("Right press to get Button Y");
        while (!buttons.RightPressed()){
            LCD.Write("X: ");
            LCD.WriteLine(RPS.X());
            LCD.Write("Y: ");
            LCD.WriteLine(RPS.Y());
            buttony = RPS.Y();
            LCD.Clear();
        }

        //Input crank coordinates
        LCD.WriteLine("Left press to get Crank X");
        while (!buttons.LeftPressed()){
            LCD.Write("X: ");
            LCD.WriteLine(RPS.X());
            LCD.Write("Y: ");
            LCD.WriteLine(RPS.Y());
            crankx = RPS.X();
            LCD.Clear();
        }
        LCD.WriteLine("Right press to get Crank Y");
        while (!buttons.RightPressed()){
            LCD.Write("X: ");
            LCD.WriteLine(RPS.X());
            LCD.Write("Y: ");
            LCD.WriteLine(RPS.Y());
            cranky = RPS.Y();
            LCD.Clear();
        }

        while(!buttons.MiddlePressed()){
    LCD.WriteLine("DONE CALIBRATING");
    LCD.Clear();
}

    waitForLightChange( cds1 );

    saltbag(bagx,  bagheading, bagy);
    buttonpressinorder(buttonx, buttonheading, buttony);
    crank(crankx, cranky);
    oilpump(pumpx, pumpyleft, pumpyright);
}

