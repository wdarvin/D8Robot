
void crank() {
    //ALIGN WITH CRANK from buttonpress



    pulseRight(TPOWER, TURN45COUNTS, TIMEOUT2);
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
    pulseForward(MPOWER, encodeLength(4), TIMEOUT2);
    rpsYMinus(53.);
    pulseLeft(TPOWER, TURN90COUNTS, TIMEOUT2);
    pulseForward(MPOWER, encodeLength(14.), TIMEOUT5);
    //go towards the side wall
    rpsXPlus(28.);
    //go towards the side wall
    rpsXPlus(28.);

  if(RPS.BlueButtonOrder() == 3){
            ForkHeight.SetPercent(SPOWER);
            Sleep(.7);
            ForkHeight.Stop();
            ForkAngle.SetDegree(67);
    }
    else if(RPS.WhiteButtonOrder() == 3) {
      ForkHeight.SetPercent(SPOWER);
      Sleep(.3);
      ForkHeight.Stop();
      ForkAngle.SetDegree(67);
    }else if(RPS.RedButtonOrder() == 3) {
      ForkHeight.SetPercent(-SPOWER);
      Sleep(.4);
      ForkHeight.Stop();
      ForkAngle.SetDegree(67);
    }

    pulseRight(TPOWER, TURN90COUNTS, TIMEOUT2);
    //turn using rps and turn subfunctions
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

    int turn = 1;
    float red = .3;
    float blue = .6;

    if (CdS.Value() < red){
        turn = 0;
    }
    else if (CdS.Value() > red && CdS.Value() < blue){
        turn = 1;
    }

    //Run into the crank
    pulseForward(15, encodeLength(1.), 2);
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
    rpsYMinus(55.5);

    if (CdS.Value() < red){
        turn = 0;
    }
    else if (CdS.Value() > red && CdS.Value() < blue){
        turn = 1;
    }

    pulseForward(15, encodeLength(.5), TIMEOUT2);
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

    if (CdS.Value() < red){
        turn = 0;
    }
    else if (CdS.Value() > red && CdS.Value() < blue){
        turn = 1;
    }


    rpsYMinus(56.6);

    if (turn == 1){
        //turn crank left
        ForkAngle.SetDegree(0);
        Sleep(.5);
        pulseForward(MPOWER, encodeLength(4.), TIMEOUT2);
        ForkAngle.SetDegree(85);
        //Run into the crank
        pulseForward(15, encodeLength(1.), TIMEOUT2);
        rpsTurnTo0();
//        while(RPS.Heading() < 0 || RPS.Heading() > 1.)
//        {
//            if(RPS.Heading() < 180)
//            {
//               //pulse the motors for a short duration in the correct direction
//               sleepRight(TURNPOWER);
//               //pulseRight(TURNPOWER,count,TIMEOUT);
//               LCD.WriteLine("HEADING CHECK RIGHT");
//            }
//            else if(RPS.Heading() > 180)
//            {
//               sleepLeft(TURNPOWER);
//               //pulseLeft(TURNPOWER,count,TIMEOUT);
//               LCD.WriteLine("HEADING CHECK LEFT");
//            }
//        }
        pulseForward(15, encodeLength(1.), TIMEOUT2);
        rpsTurnTo0();
//        while(RPS.Heading() < 0 || RPS.Heading() > 1.)
//        {
//            if(RPS.Heading() < 180)
//            {
//               //pulse the motors for a short duration in the correct direction
//               sleepRight(TURNPOWER);
//               //pulseRight(TURNPOWER,count,TIMEOUT);
//               LCD.WriteLine("HEADING CHECK RIGHT");
//            }
//            else if(RPS.Heading() > 180)
//            {
//               sleepLeft(TURNPOWER);
//               //pulseLeft(TURNPOWER,count,TIMEOUT);
//               LCD.WriteLine("HEADING CHECK LEFT");
//            }
//        }
        //Run into the crank
        pulseForward(15, encodeLength(1.), TIMEOUT2);
        rpsTurnTo0();
//        while(RPS.Heading() < 0 || RPS.Heading() > 1.)
//        {
//            if(RPS.Heading() < 180)
//            {
//               //pulse the motors for a short duration in the correct direction
//               sleepRight(TURNPOWER);
//               //pulseRight(TURNPOWER,count,TIMEOUT);
//               LCD.WriteLine("HEADING CHECK RIGHT");
//            }
//            else if(RPS.Heading() > 180)
//            {
//               sleepLeft(TURNPOWER);
//               //pulseLeft(TURNPOWER,count,TIMEOUT);
//               LCD.WriteLine("HEADING CHECK LEFT");
//            }
//        }
        rpsYMinus(56.5);
        ForkAngle.SetDegree(0);
    }


    //If the crank has to be turned left
    else if (turn == 0){
        //turn crank right
        ForkAngle.SetDegree(180);
        Sleep(.5);
        pulseForward(MPOWER, encodeLength(4.), TIMEOUT2);
        ForkAngle.SetDegree(67);
        //Run into the crank
        pulseForward(15, encodeLength(1.), TIMEOUT2);
        rpsTurnTo0();
//        while(RPS.Heading() < 0 || RPS.Heading() > 1.)
//        {
//            if(RPS.Heading() < 180)
//            {
//               //pulse the motors for a short duration in the correct direction
//               sleepRight(TURNPOWER);
//               //pulseRight(TURNPOWER,count,TIMEOUT);
//               LCD.WriteLine("HEADING CHECK RIGHT");
//            }
//            else if(RPS.Heading() > 180)
//            {
//               sleepLeft(TURNPOWER);
//               //pulseLeft(TURNPOWER,count,TIMEOUT);
//               LCD.WriteLine("HEADING CHECK LEFT");
//            }
//        }
        pulseForward(15, encodeLength(1.), TIMEOUT2);
        rpsTurnTo0();
//        while(RPS.Heading() < 0 || RPS.Heading() > 1.)
//        {
//            if(RPS.Heading() < 180)
//            {
//               //pulse the motors for a short duration in the correct direction
//               sleepRight(TURNPOWER);
//               //pulseRight(TURNPOWER,count,TIMEOUT);
//               LCD.WriteLine("HEADING CHECK RIGHT");
//            }
//            else if(RPS.Heading() > 180)
//            {
//               sleepLeft(TURNPOWER);
//               //pulseLeft(TURNPOWER,count,TIMEOUT);
//               LCD.WriteLine("HEADING CHECK LEFT");
//            }
//        }
        //Run into the crank
        pulseForward(15, encodeLength(1.), TIMEOUT2);
        rpsTurnTo0();
//        while(RPS.Heading() < 0 || RPS.Heading() > 1.)
//        {
//            if(RPS.Heading() < 180)
//            {
//               //pulse the motors for a short duration in the correct direction
//               sleepRight(TURNPOWER);
//               //pulseRight(TURNPOWER,count,TIMEOUT);
//               LCD.WriteLine("HEADING CHECK RIGHT");
//            }
//            else if(RPS.Heading() > 180)
//            {
//               sleepLeft(TURNPOWER);
//               //pulseLeft(TURNPOWER,count,TIMEOUT);
//               LCD.WriteLine("HEADING CHECK LEFT");
//            }
//        }

        rpsYMinus(56.5);

        ForkAngle.SetDegree(180);
    }

    Sleep(1.);

    pulseForward(MPOWER, encodeLength(4), TIMEOUT2);
    pulseLeft(TPOWER, TURN90COUNTS * 2, TIMEOUT3);
    rpsTurn(180);

    //go down ramp
    pulseForward(-MPOWER, encodeLength(10), TIMEOUT5);
    rpsTurn(180);
    pulseForward(-MPOWER, encodeLength(16), TIMEOUT5);


    pulseRight(TPOWER, TURN90COUNTS, TIMEOUT2);
    rpsTurn(90);
    rpsXPlus(20.);


    ForkAngle.SetDegree(90);\

    ForkHeight.SetPercent(SPOWER);
    Sleep(.6);
    ForkHeight.Stop();
}
