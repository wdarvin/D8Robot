
void oilpump(float pumpx, float pumpyleft, float pumpyright)
{
    //switch to the right
    if (RPS.OilDirec() == 0) {
        pulseRight(TPOWER, TURN90COUNTS, TIMEOUT2);
        rpsTurnTo0();
        //set both motors to the desired percen
        rMotor.SetPercent(MPOWER);
        lMotor.SetPercent(MPOWER);

        time.tic();
        while(Microswitch.Value() == 1 && time.toc() < TIMEOUT2)
        {}
        //turn motors off
        rMotor.Stop();
        lMotor.Stop();

        pulseForward(-MPOWER, encodeLength(2.5), TIMEOUT1);
        pulseLeft(TPOWER, TURN90COUNTS, TIMEOUT2);
        rpsTurn(90);
        pulseForward(-MPOWER, encodeLength(4.), 1.5);

        pulseRight(70, TURN90COUNTS, TIMEOUT2);
    }
    //Switch to the left
    else if (RPS.OilDirec() == 1) {
        pulseRight(TPOWER, TURN90COUNTS, TIMEOUT2);
        pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);
        rpsYMinus(pumpyleft);
        pulseLeft(TPOWER, TURN90COUNTS, TIMEOUT2);
        rpsTurn(90);
        pulseForward(-MPOWER, encodeLength(4.), 1.5);

        //turn motors off
        rMotor.Stop();
        lMotor.Stop();

        pulseLeft(70, TURN90COUNTS, TIMEOUT2);
    }
}
