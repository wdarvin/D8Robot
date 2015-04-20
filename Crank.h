void crankturn(int turn, float backup) {
    if (turn == 1){
        //turn crank left
        ForkAngle.SetDegree(0);
        Sleep(.2);
        //turn motors off
        rMotor.Stop();
        lMotor.Stop();

        Sleep(.5);


        if (RPS.Time() < CRANKTIMEOUT){
            return;
        }

        //backup from crank
        pulseForward(-20, encodeLength(backup), TIMEOUT1);
        ForkAngle.SetDegree(100);

        //Run into the crank
        rpsTurnTo0();
                rpsTurnTo0();
        rMotor.SetPercent(15);
        lMotor.SetPercent(15);
                Sleep(1.);
        ForkAngle.SetDegree(0);
                Sleep(.2);
        //turn motors off
        rMotor.Stop();
        lMotor.Stop();


        if (RPS.Time() < CRANKTIMEOUT){
            return;
        }

        //backup from crank
        pulseForward(-20, encodeLength(backup), TIMEOUT1);
        ForkAngle.SetDegree(100);


        //Run into the crank
        rpsTurnTo0();
                rpsTurnTo0();
        rMotor.SetPercent(15);
        lMotor.SetPercent(15);
                Sleep(1.);
        ForkAngle.SetDegree(0);
                Sleep(.2);
        //turn motors off
        rMotor.Stop();
        lMotor.Stop();


        if (RPS.Time() < CRANKTIMEOUT) {
            return;
        }


        //backup from crank
        pulseForward(-20, encodeLength(backup), TIMEOUT1);
        ForkAngle.SetDegree(100);


        //Run into the crank
        rpsTurnTo0();
                rpsTurnTo0();
        rMotor.SetPercent(15);
        lMotor.SetPercent(15);
                Sleep(1.);
        ForkAngle.SetDegree(0);
                Sleep(.2);
        //turn motors off
        rMotor.Stop();
        lMotor.Stop();


        if (RPS.Time() < CRANKTIMEOUT){
            return;
        }

        //backup from crank
        pulseForward(-20, encodeLength(backup), TIMEOUT1);
        ForkAngle.SetDegree(100);


        //Run into the crank
        rpsTurnTo0();
                rpsTurnTo0();
        rMotor.SetPercent(15);
        lMotor.SetPercent(15);
                Sleep(1.);
        ForkAngle.SetDegree(0);
                Sleep(.2);
        //turn motors off
        rMotor.Stop();
        lMotor.Stop();


        if (RPS.Time() < CRANKTIMEOUT){
            return;
        }


        //backup from crank
        pulseForward(-20, encodeLength(backup), TIMEOUT1);
        ForkAngle.SetDegree(100);

        //Run into the crank
        rpsTurnTo0();
                rpsTurnTo0();
        rMotor.SetPercent(15);
        lMotor.SetPercent(15);
                Sleep(1.);
        ForkAngle.SetDegree(0);
                Sleep(.2);
        //turn motors off
        rMotor.Stop();
        lMotor.Stop();
    }


    //If the crank has to be turned right
    else if (turn == 0){
        //turn crank right


        //rotate the fork while running into the crank so that it turns it even if its not in the spokes
        ForkAngle.SetDegree(180);
                Sleep(.2);
        //turn motors off
        rMotor.Stop();
        lMotor.Stop();


        if (RPS.Time() < CRANKTIMEOUT){
            return;
        }


        //backup from crank
        pulseForward(-20, encodeLength(backup), TIMEOUT1);
        ForkAngle.SetDegree(100);
        //Run into the crank

        //Run into the crank
        rpsTurnTo0();
                rpsTurnTo0();
        //rotate the fork while running into the crank so that it turns it even if its not in the spokes
        rMotor.SetPercent(15);
        lMotor.SetPercent(15);
        Sleep(1.);
        ForkAngle.SetDegree(180);
        Sleep(.2);
        //turn motors off
        rMotor.Stop();
        lMotor.Stop();



        if (RPS.Time() < CRANKTIMEOUT){
            return;
        }

        //backup from crank
        pulseForward(-20, encodeLength(backup), TIMEOUT1);
        ForkAngle.SetDegree(90);

        //rotate the fork while running into the crank so that it turns it even if its not in the spokes
        rpsTurnTo0();
                rpsTurnTo0();
        rMotor.SetPercent(15);
        lMotor.SetPercent(15);
                Sleep(1.);
        ForkAngle.SetDegree(180);
        Sleep(.2);
        //turn motors off
        rMotor.Stop();
        lMotor.Stop();


        if (RPS.Time() < CRANKTIMEOUT){
            return;
        }


        //backup from crank
        pulseForward(-20, encodeLength(backup), TIMEOUT1);
        ForkAngle.SetDegree(90);

        //rotate the fork while running into the crank so that it turns it even if its not in the spokes
        rpsTurnTo0();
                rpsTurnTo0();
        rMotor.SetPercent(15);
        lMotor.SetPercent(15);
                Sleep(1.);
        ForkAngle.SetDegree(180);
        Sleep(.2);
        //turn motors off
        rMotor.Stop();
        lMotor.Stop();


        if (RPS.Time() < CRANKTIMEOUT){
            return;
        }

        //backup from crank
        pulseForward(-20, encodeLength(backup), TIMEOUT1);
        ForkAngle.SetDegree(90);

        //rotate the fork while running into the crank so that it turns it even if its not in the spokes
        rpsTurnTo0();
                rpsTurnTo0();
        rMotor.SetPercent(15);
        lMotor.SetPercent(15);
                Sleep(1.);
        ForkAngle.SetDegree(180);
        Sleep(.2);
        //turn motors off
        rMotor.Stop();
        lMotor.Stop();
    }
}





void crank(float crankx, float cranky) {

    int turn = 1;
    float redblue = .185;
    float backup = 2.25;

    //ALIGN WITH CRANK from buttonpress
    pulseRight(TPOWER, TURN45COUNTS, TIMEOUT2);
    rpsTurnTo0();
    pulseForward(MPOWER, encodeLength(7.), TIMEOUT2);
    rpsYMinus(53.);
    pulseLeft(TPOWER, TURN90COUNTS, TIMEOUT2);
    //go backwards towards the crank
    rpsTurn(90);
    pulseForward(MPOWER, encodeLength(6.), TIMEOUT3);
    rpsTurn(90);

    //set both motors to the desired percent and stop when the wall is hit
    rMotor.SetPercent(MPOWER);
    lMotor.SetPercent(MPOWER);
    time.tic();
    while(Microswitch.Value() == 1 && time.toc() < TIMEOUT5)
    {}
    //turn motors off
    rMotor.Stop();
    lMotor.Stop();

    pulseForward(-MPOWER, encodeLength(2.7), TIMEOUT1);

    //Turn right to face the Crank
    pulseRight(TPOWER, TURN90COUNTS, TIMEOUT2);
    rpsTurnTo0();

    //adjust the angle/height of the forklift from the last button press so it can read the CdS
      if(RPS.BlueButtonOrder() == 3){
          ForkAngle.SetDegree(45);
          ForkLiftHeightEncode(-SPOWER, 2);
         // ForkAdjust(-SPOWER, .13, 100.);
        } else if(RPS.WhiteButtonOrder() == 3) {
              ForkAngle.SetDegree(45);
          ForkLiftHeightEncode(-SPOWER, 9);
          //ForkAdjust(-SPOWER, 1., 100.);
        } else if(RPS.RedButtonOrder() == 3) {
              ForkAngle.SetDegree(45);
          ForkLiftHeightEncode(-SPOWER, 12);
          //ForkAdjust(-SPOWER, 1.6, 100.);
        }

    //go forkward to read cds
    rpsYMinus(cranky + .28);
    //read the cds
    LCD.WriteLine(CdS.Value());
    //try to read the CdS value using CrankCdS(redblue) with redblue as the threshold
    turn = CrankCdS(redblue);

    //straighten up the robot and back up
    rpsTurnTo0();
    pulseForward(MPOWER, encodeLength(3.), TIMEOUT3);
    rpsTurnTo0();

    //Adjust fork to be at crank height
    ForkAngle.SetDegree(100);
    ForkLiftHeightEncode(SPOWER, 11);

    //go forward into the robot
    rpsTurnTo0();
    rpsYMinus(55.6);
    rpsTurnTo0();
    rpsYMinus(cranky - .1);
    rpsTurnTo0();
    //set both motors to the desired percent
    rMotor.SetPercent(15);
    lMotor.SetPercent(15);
    Sleep(1.);


    crankturn(turn, backup);

    Sleep(.5);



    //back up and turn 180 to go down the ramp
    pulseForward(MPOWER, encodeLength(4), TIMEOUT2);
    pulseLeft(TPOWER, TURN90COUNTS, TIMEOUT2);



    rMotor.SetPercent(MPOWER);
    lMotor.SetPercent(MPOWER);
    time.tic();
    while(Microswitch.Value() == 1 && time.toc() < TIMEOUT2)
    {}
    //turn motors off
    rMotor.Stop();
    lMotor.Stop();


    pulseForward(-MPOWER, encodeLength(2.5), TIMEOUT2);
    pulseLeft(TPOWER, TURN90COUNTS, TIMEOUT2);
    rpsTurn(180);

    //go down ramp
    pulseForward((-MPOWER) - 5, encodeLength(10), TIMEOUT5);
    rpsTurn(180);
    pulseForward(-MPOWER, encodeLength(18), TIMEOUT5);


    //turn right and move to the X-coordinate of 20 to lineup with pump switch
    pulseRight(TPOWER, TURN90COUNTS, TIMEOUT2);
    rpsTurn(90);
    pulseForward(-MPOWER, encodeLength(8.), TIMEOUT3);
    rpsXPlus(20.);

    //adjust the forklift to hit the pump switch
    ForkLiftHeightEncode(SPOWER, 1);
    ForkAngle.SetDegree(100);

}
