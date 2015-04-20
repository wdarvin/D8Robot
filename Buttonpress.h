
void buttonpress() {
    //Beginning of button code from end of saltbag

    pulseLeft(TPOWER, TURN45COUNTS, TIMEOUT2);
    rpsTurn(90);
    pulseForward(MPOWER, encodeLength(2.), TIMEOUT1);
    rpsXPlus(15.4);


    ForkHeight.SetPercent(SPOWER);
    Sleep(1.45);
    ForkHeight.Stop();
    ForkAngle.SetDegree(100);

    pulseRight(TPOWER - 10, TURN90COUNTS, TIMEOUT2);
    rpsTurnTo0();
    rpsTurnTo0();

    pulseForward(-MPOWER, encodeLength(6), TIMEOUT3);
    rpsYMinus(61.4);
    rpsTurnTo0();


    //turn to face the buttons
    pulseLeft(TPOWER, TURN45COUNTS, TIMEOUT2);
    rpsTurn(42.);

    //move forward for the first button press
    rpsTurn(42.);
    pulseForward(-MPOWER, encodeLength(1.), 1.);
    rpsTurn(42.);
    pulseForward(-MPOWER, encodeLength(1.), 1.);
    rpsTurn(42.);
    pulseForward(-MPOWER, encodeLength(1.), 1.);

    //backup robot for 2nd button press
    pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);


    rpsTurn(44.);
    pulseForward(-MPOWER, encodeLength(1.), 1.);
    rpsTurn(44.);
    pulseForward(-MPOWER, encodeLength(1.), 1.);
    rpsTurn(44.);

    //backup robot for 2nd button press
    pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);
    rpsTurn(44.);

    ForkHeight.SetPercent(SPOWER);
    Sleep(.9);
    ForkHeight.Stop();
    ForkAngle.SetDegree(100);

    //move forward for the second button press
    rpsTurn(42.);
    pulseForward(-MPOWER, encodeLength(1.), 1.);
    rpsTurn(42.);
    pulseForward(-MPOWER, encodeLength(1.), 1.);


    //backup robot for 3rd button press
    pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);


    rpsTurn(44.);
    pulseForward(-MPOWER, encodeLength(1.), 1.);
    rpsTurn(44.);
    pulseForward(-MPOWER, encodeLength(1.), 1.);
    rpsTurn(44.);

    //backup robot for 2nd button press
    pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);
    rpsTurn(44.);

    ForkHeight.SetPercent(SPOWER);
    Sleep(.7);
    ForkHeight.Stop();
    ForkAngle.SetDegree(45);


    //adjust/move forward for the third button press
    rpsTurn(47.);
    pulseForward(-MPOWER, encodeLength(1.), 1.);
    rpsTurn(47.);
    pulseForward(-MPOWER, encodeLength(1.), 1.);


    //backup robot
    pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);
    //adjust/move forward for 3rd button press again
    rpsTurn(49.);
    pulseForward(-MPOWER, encodeLength(1.), 1.);
    rpsTurn(49.);
    pulseForward(-MPOWER, encodeLength(1.), 1.);
    rpsTurn(49.);

    //backup robot after 3rd button press
    pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);

}
