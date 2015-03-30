
void oilpump() {
    //switch to the right
    if (RPS.OilDirec() == 0) {
        pulseRight(TPOWER, TURN90COUNTS, TIMEOUT2);
        rpsYMinus(6.);
        pulseLeft(TPOWER, TURN90COUNTS, TIMEOUT2);
        rpsTurn(90);
        rpsXPlus(13.3);
        pulseRight(70, TURN90COUNTS, TIMEOUT2);

    }
    //Switch to the left
    else if (RPS.OilDirec() == 1) {
        pulseRight(TPOWER, TURN90COUNTS, TIMEOUT2);
        rpsYMinus(13.5);
        pulseLeft(TPOWER, TURN90COUNTS, TIMEOUT2);
        rpsTurn(90);
        rpsXPlus(13.3);
        pulseLeft(70, TURN90COUNTS, TIMEOUT2);
    }
}
