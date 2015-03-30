
void buttonpress() {
    //Beginning of button code from end of saltbag

    pulseLeft(TPOWER, TURN45COUNTS, TIMEOUT2);
    rpsTurn(90);
    rpsXPlus(17.);
    pulseRight(TPOWER, TURN90COUNTS, TIMEOUT2);
    rpsTurnTo0();
//    while(RPS.Heading() < 0 || RPS.Heading() > 1.)
//    {
//        if(RPS.Heading() < 180)
//        {
//           //pulse the motors for a short duration in the correct direction
//           sleepRight(TURNPOWER);
//           //pulseRight(TURNPOWER,count,TIMEOUT);
//           LCD.WriteLine("HEADING CHECK RIGHT");
//        }
//        else if(RPS.Heading() > 180)
//        {
//           sleepLeft(TURNPOWER);
//           //pulseLeft(TURNPOWER,count,TIMEOUT);
//           LCD.WriteLine("HEADING CHECK LEFT");
//        }
//    }
    pulseForward(-MPOWER, encodeLength(6), TIMEOUT3);
    rpsYMinus(62.);

        /**
         * ButtonOrder() returns int
         * Button order returns :
         * 1 = first
         * 2 = second
         * 3 = third
         *
         * Red/Blue/WhiteButtonPressed() returns int
         * 1= button was pressed in right order
         * 0 = button was not pressed or pressed out of order
         *
         * ButtonsPressed() returns int
         * 0 = no buttons have been pressed
         * 1 = 1 button has been pressed
         * 2 = 2 buttons have been pressed
         * 3 = all buttons have been pressed
         *
         *x = 17.4
         *y = 61.3
         */


    //turn to face the buttons
    pulseLeft(TPOWER, TURN45COUNTS, TIMEOUT2);
    rpsTurn(45);

    //set the height and angle of the forklift based on the first button to be pressed
    if(RPS.BlueButtonOrder() == 1){
        ForkHeight.SetPercent(SPOWER);
        Sleep(1.2);
        ForkHeight.Stop();
        ForkAngle.SetDegree(100);
    }
    else if(RPS.WhiteButtonOrder() == 1) {
        ForkHeight.SetPercent(SPOWER);
        Sleep(1.6);
        ForkHeight.Stop();
        ForkAngle.SetDegree(100);
    }
    else if(RPS.RedButtonOrder() == 1){
        ForkHeight.SetPercent(SPOWER);
        Sleep(2.1);
        ForkHeight.Stop();
        ForkAngle.SetDegree(45);
    }

    //move forward for the first button press
    rpsTurn(45);
    pulseForward(-MPOWER, encodeLength(1.), 1.);
    rpsTurn(45);
    pulseForward(-MPOWER, encodeLength(1.), 1.);


    //backup robot for 2nd button press
    pulseForward(MPOWER, encodeLength(3.), TIMEOUT2);
    rpsTurn(45);

    //adjust forklift for second button press
    if(RPS.BlueButtonOrder() == 2){
        if (RPS.WhiteButtonOrder() == 1){
            ForkHeight.SetPercent(-SPOWER);
            Sleep(.5);
            ForkHeight.Stop();
        }
        else if (RPS.RedButtonOrder() == 1){
            ForkHeight.SetPercent(-SPOWER);
            Sleep(1.2);
            ForkHeight.Stop();
            ForkAngle.SetDegree(45);
        }
    }
    else if(RPS.WhiteButtonOrder() == 2) {
        if (RPS.BlueButtonOrder() == 1){
            ForkHeight.SetPercent(SPOWER);
            Sleep(.7);
            ForkHeight.Stop();
        }
        else if (RPS.RedButtonOrder() == 1){
            ForkHeight.SetPercent(-SPOWER);
            Sleep(.5);
            ForkHeight.Stop();
            ForkAngle.SetDegree(90);
        }
    }else if(RPS.RedButtonOrder() == 2) {
        if (RPS.BlueButtonOrder() == 1){
            ForkHeight.SetPercent(SPOWER);
            Sleep(1.3);
            ForkHeight.Stop();
            ForkAngle.SetDegree(45);
        }
        else if (RPS.WhiteButtonOrder() == 1){
            ForkHeight.SetPercent(SPOWER);
            Sleep(.8);
            ForkHeight.Stop();
        }
    }
    //run forward for the second button press
    rpsTurn(45);
    pulseForward(-MPOWER, encodeLength(1.), 1.);
    rpsTurn(45);
    pulseForward(-MPOWER, encodeLength(1.), 1.);

    //backup robot to adjust for the final button press
    pulseForward(MPOWER, encodeLength(3.), TIMEOUT2);
    rpsTurn(45);

    if(RPS.BlueButtonOrder() == 3){
        if (RPS.WhiteButtonOrder() == 2){
            ForkHeight.SetPercent(-SPOWER);
            Sleep(.5);
            ForkHeight.Stop();
        }
        else if (RPS.RedButtonOrder() == 2){
            ForkHeight.SetPercent(-SPOWER);
            Sleep(1.2);
            ForkHeight.Stop();
            ForkAngle.SetDegree(45);
        }
    }
    else if(RPS.WhiteButtonOrder() == 3) {
        if (RPS.BlueButtonOrder() == 2){
            ForkHeight.SetPercent(SPOWER);
            Sleep(.7);
            ForkHeight.Stop();
        }
        else if (RPS.RedButtonOrder() == 2){
            ForkHeight.SetPercent(-SPOWER);
            Sleep(.5);
            ForkHeight.Stop();
            ForkAngle.SetDegree(90);
        }
    }else if(RPS.RedButtonOrder() == 3) {
        if (RPS.BlueButtonOrder() == 2){
            ForkHeight.SetPercent(SPOWER);
            Sleep(1.3);
            ForkHeight.Stop();
            ForkAngle.SetDegree(45);
        }
        else if (RPS.WhiteButtonOrder() == 2){
            ForkHeight.SetPercent(SPOWER);
            Sleep(.8);
            ForkHeight.Stop();
        }
    }
    //Run into the buttons for the third press
    rpsTurn(45);
    pulseForward(-MPOWER, encodeLength(1.), 1);
    rpsTurn(45);
    pulseForward(-MPOWER, encodeLength(1.), 1);


    pulseForward(MPOWER, encodeLength(3.), TIMEOUT2);
    rpsTurn(45); 
    //*
    //*End of button code
    //*
}
