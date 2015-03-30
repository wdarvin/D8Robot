
void saltbag() {
    //SALT BAG CODE
//    //Beginning of ramp code
//    //Position the robot to be able to run straight into the salt bag
//    rpsYMinus(14.);
//    pulseRight(TPOWER, 200, TIMEOUT1);
//    rpsTurn(270);
//    LCD.WriteLine(RPS.Heading());
//    Sleep(.5);
//    rpsTurn(270);
//    LCD.WriteLine(RPS.Heading());
//    rpsXMinus(24.);

//    //turn to face the saltbag
//    rpsTurn(getAngle(7.8,29.7))


    //Go forward 10 inches
    pulseForward(-MPOWER, encodeLength(10.), TIMEOUT5);

    //Position the robot to be able to run straight into the salt bag
    rpsYPlus(13.5);
    pulseLeft(TPOWER, TURN90COUNTS, TIMEOUT2);
    rpsTurn(270);
    pulseForward(-MPOWER, encodeLength(2), TIMEOUT2);
    rpsXMinus(24.5);

    //turn to face the saltbag
    rpsTurn(getAngle(7.8,29.7));

    //move forward and have salt bag slide on to the fork
    pulseForward((-MPOWER), encodeLength(4.), TIMEOUT2);

    //turn to face the saltbag
    rpsTurn(getAngle(7.8,29.7));


    //Lower fork to get under the bag
    ForkHeight.SetPercent((-SPOWER)-10);
    Sleep(.4);
    ForkHeight.Stop();

    //move forward and have salt bag slide on to the fork
    pulseForward((-MPOWER)+ 10, encodeLength(4.), TIMEOUT2);

    //move backward with salt bag on there
    pulseForward(MPOWER, encodeLength(1.), TIMEOUT2);

    //turn to face the saltbag
    rpsTurn(getAngle(7.8,29.7));

//    rpsYMinus(9.);

    //Lift fork with salt bag hopefully
    ForkHeight.SetPercent(SPOWER);
    Sleep(2.3);
    ForkHeight.Stop();

    //go backwards with the salt bag
    pulseForward(MPOWER + 15, encodeLength(8.), TIMEOUT5);
    pulseRight(TPOWERPOSTBAG, TURN45COUNTS, TIMEOUT);
    rpsTurn(180);
    rpsYPlus(16.);

    //turn to move towards wall
    pulseRight(TPOWERPOSTBAG, TURN90COUNTS, TIMEOUT2);
    rpsTurn(90);

    pulseForward(MPOWER, encodeLength(5.), TIMEOUT2);
    //go towards the side wall to go up the ramp
    rpsXPlus(27.6);

    pulseRight(TPOWERPOSTBAG, TURN90COUNTS, TIMEOUT2);
    //Check angle before going up ramp


    rpsTurnTo0();
//        while(RPS.Heading() < 1.75 || RPS.Heading() > 2.5)
//        {
//            if(RPS.Heading() < 180)
//            {
//                //pulse the motors for a short duration in the correct direction
//                sleepRight(TURNPOWER);
//                //pulseRight(TURNPOWER,count,TIMEOUT);
//                LCD.WriteLine("HEADING CHECK RIGHT");
//            }
//            else if(RPS.Heading() > 180)
//            {
//                sleepLeft(TURNPOWER);
//                //pulseLeft(TURNPOWER,count,TIMEOUT);
//                LCD.WriteLine("HEADING CHECK LEFT");
//          }
//}


    LCD.Write("Angle: ");
    LCD.WriteLine(RPS.Heading());

    //Move forward to get up the ramp
    pulseForward((-MPOWER)+10,encodeLength(28.), TIMEOUT + 5);
    //Check the Y position
    rpsYMinus(53.);

    //turn 90 and check angle
    pulseLeft(TPOWERPOSTBAG, TURN90COUNTS, TIMEOUT2);
    rpsTurn(90);

    //push snow out of the way
    pulseForward(-MPOWER, encodeLength(16.), TIMEOUT5);
    rpsXPlus(7.);

    //position robot to go into garage
    pulseForward(MPOWER + 5, encodeLength(2.), TIMEOUT2);
    rpsXPlus(10.);

    //turn robot to face garage
    rpsTurn(45);
    rpsTurn(45);
    //lower fork to fit in the garage
    ForkHeight.SetPercent((-SPOWER)-10);
    Sleep(1.8);
    ForkHeight.Stop();

    //go forward to drop saltbag in garage
    pulseForward(-MPOWER, encodeLength(9.), TIMEOUT3);

    //angle fork to drop saltbag
    ForkAngle.SetDegree(0);

    //go backwards out of the garage
    pulseForward(MPOWER, encodeLength(10.), TIMEOUT5);
    //lift fork to slide it off the top of the garage
    ForkAngle.SetDegree(90);


    //Lower fork to push bag again
    ForkHeight.SetPercent((-SPOWER)-10);
    Sleep(.8);
    ForkHeight.Stop();

    //go forwards into the garage
    pulseForward(-MPOWER, encodeLength(11.), TIMEOUT5);
    //go backwards out of the garage
    pulseForward(MPOWER, encodeLength(10.), TIMEOUT5);
}
