
void saltbag(float bagx, float bagheading, float bagy) {
    //SALT BAG CODE
    //Go forward 10 inches
    pulseForward(-MPOWER, encodeLength(15.), TIMEOUT5);

    //Position the robot to be able to run straight into the salt bag
    rpsYPlus(bagy);
    pulseLeft(TPOWER, TURN90COUNTS, TIMEOUT2);
    rpsTurn(270);
    pulseForward(-MPOWER, encodeLength(3), TIMEOUT2);
    rpsXMinus(bagx);

    //turn to face the saltbag
    pulseRight(TPOWER, TURN45COUNTS, TIMEOUT2);
    rpsTurn(bagheading);
    
    //move forward and have salt bag slide on to the fork
    pulseForward(-MPOWER, encodeLength(2.5), TIMEOUT2);

    //turn to face the saltbag
    rpsTurn(bagheading);

    //Lower fork to get under the bag
    ForkLiftHeightEncode(-15, 3);

    //move forward and have salt bag slide on to the fork
    pulseForward((-MPOWER) + 5, encodeLength(4.5), TIMEOUT2);

    //last try to get the saltbag
    pulseForward((-MPOWER) + 5, encodeLength(2.5), TIMEOUT1);

    //move backward with salt bag on there
    pulseForward(MPOWER, encodeLength(.5), TIMEOUT1);
    pulseLeft(TPOWER, 10, TIMEOUT1);

    //move backward with salt bag on there
    pulseForward(MPOWER, encodeLength(1.), TIMEOUT1);

    //Lift fork with salt bag hopefully
    ForkLiftHeightEncode(SPOWER, 16);

    //go backwards with the salt bag
    pulseForward(MPOWER + 15, encodeLength(9.), TIMEOUT5);

    //turn to move towards wall
    pulseRight(TPOWERPOSTBAG, (TURN90COUNTS + TURN45COUNTS), TIMEOUT5);
    rpsTurn(90);

    //set both motors to the desired percent and run into the wall until the microswitch it pressed
    rMotor.SetPercent(-20);
    lMotor.SetPercent(-20);

    time.tic();
    while(Microswitch.Value() == 1 && time.toc() < TIMEOUT5)
    {}

    //turn motors off
    rMotor.Stop();
    lMotor.Stop();

    pulseForward(-MPOWER, encodeLength(2.7), TIMEOUT1);
    //go towards the side wall to go up the ramp

    pulseRight(TPOWERPOSTBAG, TURN90COUNTS, TIMEOUT2);
    
    //Check angle before going up ramp
    rpsTurnTo0();


    //Move forward to get up the ramp
    pulseForward((-MPOWER), encodeLength(29.), TIMEOUT + 5);
    //Check the Y position
    rpsYMinus(53.);

    //turn 90 and check angle
    pulseLeft(TPOWERPOSTBAG, TURN90COUNTS, TIMEOUT2);
    rpsTurn(90);

    //push snow out of the way
    pulseForward(20, encodeLength(18.), TIMEOUT5);
    rpsXPlus(6.7);

    //position robot to go into garage
    pulseForward(MPOWER , encodeLength(2.), TIMEOUT2);
    rpsXPlus(9.0);

    //turn robot to face garage
    pulseRight(TPOWERPOSTBAG, TURN45COUNTS, TIMEOUT2);
    rpsTurn(45);
    rpsTurn(45);


    //lower fork to fit in the garage
    ForkLiftHeightEncode(-SPOWER, 8);


    //go forward to drop saltbag in garage
    pulseForward(-MPOWER, encodeLength(7.), TIMEOUT2);

    //angle fork to drop saltbag
    ForkAngle.SetDegree(0);
    Sleep(.75);

    //go backwards out of the garage
    pulseForward(MPOWER, encodeLength(9.), TIMEOUT3);
    //lift fork to slide it off the top of the garage (HELLO BOYS ;))
    ForkAngle.SetDegree(100);
    Sleep(.5);

    //Lower fork to push bag again
    ForkLiftHeightEncode(-SPOWER, 4);

    //go forwards into the garage
    pulseForward(-MPOWER, encodeLength(9.), TIMEOUT2);
    //go backwards out of the garage
    pulseForward(MPOWER, encodeLength(8.), TIMEOUT3);
}