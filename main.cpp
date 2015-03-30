#include "Defines.h"
#include "encoderFunctions.h"
#include "getAngle.h"
#include "Saltbag.h"
#include "Buttonpress.h"
#include "Crank.h"
#include "Oilpump.h"

int main(){

    LCD.Clear();
    float cds1 = .7;

    ForkAngle.SetMin(500);
    ForkAngle.SetMax(2500);

    ForkAngle.SetDegree(100);


    while(!(buttons.MiddlePressed()) ) {
    LCD.Write("CdS Value: ");
    LCD.WriteLine(CdS.Value());
    Sleep(.2);
    LCD.Clear();
    }


    Sleep(1.);
//    Demo();

    RPS.InitializeMenu();
    waitForLightChange( cds1 );

    saltbag();
    buttonpress();
    crank();
    oilpump();
}
