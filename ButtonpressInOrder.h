
void buttonpressinorder(float buttonx, float buttonheading, float buttony) {
    //Beginning of button code from end of saltbag

    //Turn left to back up
    pulseLeft(TPOWER, TURN45COUNTS, TIMEOUT2);
    rpsTurn(90);
    //back up to line up with button coordinate
    pulseForward(MPOWER, encodeLength(2.), TIMEOUT1);
    rpsXPlus(buttonx);


    //set the height and angle of the forklift based on the first button to be pressed
    if(RPS.BlueButtonOrder() == 1){
        ForkAngle.SetDegree(BLUEFORKANGLE);
        ForkLiftHeightEncode(SPOWER, 8);
      //  ForkHeight.SetPercent(SPOWER);
    }
    else if(RPS.WhiteButtonOrder() == 1) {
        ForkAngle.SetDegree(WHITEFORKANGLE);
        ForkLiftHeightEncode(SPOWER, 7 + BLUEWHITE);
    }
    else if(RPS.RedButtonOrder() == 1){
        ForkAngle.SetDegree(REDFORKANGLE);
        ForkLiftHeightEncode(SPOWER, 7 + BLUERED);
    }


    //turn robot to go up towards buttons
    pulseRight(TPOWER - 10, TURN90COUNTS, TIMEOUT2);
    rpsTurnTo0();
    rpsTurnTo0();

    //go up in Y-direction towards the buttons
    pulseForward(-MPOWER, encodeLength(5.5), TIMEOUT3);
    rpsYMinus(buttony);
    rpsTurnTo0();

    float min = (buttonheading - .75);
    float max = (buttonheading + .75);
    float redmin = (buttonheading + .5);
    float redmax = (buttonheading + 2);

    //turn left about 45 degrees to face buttons
    pulseLeft(TPOWER, TURN45COUNTS, TIMEOUT2);
    if (RPS.BlueButtonOrder() == 1 || RPS.WhiteButtonOrder() == 1){
        rpsTurn(min);
    }
    else {
        rpsTurn(redmax);
    }
    pulseForward(-MPOWER, encodeLength(1.), 1.);

    //start trying to press the button
    time2.tic();
        if (RPS.BlueButtonOrder() == 1 ) {
            while (RPS.BlueButtonPressed() == 0 && time2.toc() < TIMEOUT5) {
                //move forward for the first button press
                rpsTurn(min);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                rpsTurn(min);
                pulseForward(-MPOWER, encodeLength(1.), 1.);

                //if the time is within the timeout and the button isn't pressed correctly run into the buttons again
                if (RPS.BlueButtonPressed() == 0 && time2.toc() < TIMEOUT5) {
                    //backup robot for next button press attempt
                    pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);

                    rpsTurn(max);
                    pulseForward(-MPOWER, encodeLength(1.), 1.);
                    rpsTurn(max);
                    pulseForward(-MPOWER, encodeLength(1.), 1.);
                    }
                //backup
                pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);
                }
        }
        else if (RPS.WhiteButtonOrder() == 1 ) {
            while (RPS.WhiteButtonPressed() == 0 && time2.toc() < TIMEOUT5) {
            //move forward for the first button press
            rpsTurn(min);
            pulseForward(-MPOWER, encodeLength(1.), 1.);
            rpsTurn(min);
            pulseForward(-MPOWER, encodeLength(1.), 1.);


            //if the time is within the timeout and the button isn't pressed correctly run into the buttons again
            if (RPS.WhiteButtonPressed() == 0 && time2.toc() < TIMEOUT5) {
                //backup robot for next button press attempt
                pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);

                rpsTurn(max);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                rpsTurn(max);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                }
            //backup
            pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);
            }
        }
        else if (RPS.RedButtonOrder() == 1 ) {
            while (RPS.RedButtonPressed() == 0 && time2.toc() < TIMEOUT5) {
            //move forward for the first button press
            rpsTurn(redmax);
            pulseForward(-MPOWER, encodeLength(1.), 1.);
            rpsTurn(redmax);
            pulseForward(-MPOWER, encodeLength(1.), 1.);

            //if the time is within the timeout and the button isn't pressed correctly run into the buttons again
            if (RPS.RedButtonPressed() == 0 && time2.toc() < TIMEOUT5) {
                //backup robot for next button press attempt
                pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);

                rpsTurn(redmin);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                rpsTurn(redmin);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                }
            //backup
            pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);
            }
        }

        //backup robot for 2nd button press
        pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);





        //adjust forklift for second button press
        if(RPS.BlueButtonOrder() == 2){
            if (RPS.WhiteButtonOrder() == 1){
                //Adjust fork height/angle from white to blue
                    ForkAngle.SetDegree(BLUEFORKANGLE);
                ForkLiftHeightEncode(-SPOWER, WHITEBLUE);
                //ForkAdjust(-SPOWER, WHITEBLUE, 100.);
            }
            else if (RPS.RedButtonOrder() == 1){
                //Adjust fork height/angle from red to blue
                    ForkAngle.SetDegree(BLUEFORKANGLE);
                ForkLiftHeightEncode(-SPOWER, REDBLUE);
                //ForkAdjust(-SPOWER, REDBLUE, 100.);
            }
        }
        else if(RPS.WhiteButtonOrder() == 2) {
            if (RPS.BlueButtonOrder() == 1){
                //Adjust fork height/angle from blue to white
                    ForkAngle.SetDegree(WHITEFORKANGLE);
                ForkLiftHeightEncode(SPOWER, BLUEWHITE);
//                ForkAdjust(SPOWER, BLUEWHITE, 100);
            }
            else if (RPS.RedButtonOrder() == 1){
               //Adjust fork height/angle from red to white
                    ForkAngle.SetDegree(WHITEFORKANGLE);
                ForkLiftHeightEncode(-SPOWER, REDWHITE);
               //ForkAdjust(-SPOWER, REDWHITE, 100.);
            }
        }else if(RPS.RedButtonOrder() == 2) {
            if (RPS.BlueButtonOrder() == 1){
                //Adjust fork height/angle from blue to red
                ForkAngle.SetDegree(REDFORKANGLE);
                ForkLiftHeightEncode(SPOWER, BLUERED);
                //ForkAdjust(SPOWER, BLUERED, 45.);
            }
            else if (RPS.WhiteButtonOrder() == 1){
                //Adjust fork height/angle from white to red
                ForkAngle.SetDegree(REDFORKANGLE);
                ForkLiftHeightEncode(SPOWER, WHITERED);
                //ForkAdjust(SPOWER, WHITERED, 45.);
            }
        }

        time3.tic();
        //run forward for the second button press
        if (RPS.BlueButtonOrder() == 2 ) {
                while (RPS.BlueButtonPressed() == 0 && time3.toc() < TIMEOUT5) {
                //move forward for the second button press
                rpsTurn(min);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                rpsTurn(min);
                pulseForward(-MPOWER, encodeLength(1.), 1.);

                //if the time is within the timeout and the button isn't pressed correctly run into the buttons again
                if (RPS.BlueButtonPressed() == 0 && time3.toc() < TIMEOUT5) {
                    pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);

                    rpsTurn(max);
                    pulseForward(-MPOWER, encodeLength(1.), 1.);
                    rpsTurn(max);
                    pulseForward(-MPOWER, encodeLength(1.), 1.);
                    }
                //backup
                pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);
                }
        }
        else if (RPS.WhiteButtonOrder() == 2 ) {
            while (RPS.WhiteButtonPressed() == 0 && time3.toc() < TIMEOUT5) {
            //move forward for the second button press
            rpsTurn(min);
            pulseForward(-MPOWER, encodeLength(1.), 1.);
            rpsTurn(min);
            pulseForward(-MPOWER, encodeLength(1.), 1.);

            //if the time is within the timeout and the button isn't pressed correctly run into the buttons again
            if (RPS.WhiteButtonPressed() == 0 && time3.toc() < TIMEOUT5) {
                pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);

                rpsTurn(max);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                rpsTurn(max);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                }
            //backup
            pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);
            }
        }
        else if (RPS.RedButtonOrder() == 2) {
            while (RPS.RedButtonPressed() == 0  && time3.toc() < TIMEOUT5) {
            //move forward for the second button press
            rpsTurn(redmax);
            pulseForward(-MPOWER, encodeLength(1.), 1.);
            rpsTurn(redmax);
            pulseForward(-MPOWER, encodeLength(1.), 1.);

            //if the time is within the timeout and the button isn't pressed correctly run into the buttons again
            if (RPS.RedButtonPressed() == 0 && time3.toc() < TIMEOUT5) {
                pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);

                rpsTurn(redmin);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                rpsTurn(redmin);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                }
            //backup
            pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);
            }
        }




        //adjust forkheight for 3rd button press
        if(RPS.BlueButtonOrder() == 3){
            if (RPS.WhiteButtonOrder() == 2){
                //Adjust fork height/angle from white to blue
                    ForkAngle.SetDegree(BLUEFORKANGLE);
                ForkLiftHeightEncode(-SPOWER, WHITEBLUE);
                //ForkAdjust(-SPOWER, WHITEBLUE, 100.);
            }
            else if (RPS.RedButtonOrder() == 2){
                //Adjust fork height/angle from red to blue
                    ForkAngle.SetDegree(BLUEFORKANGLE);
                ForkLiftHeightEncode(-SPOWER, REDBLUE);
                //ForkAdjust(-SPOWER, REDBLUE, 100.);
            }
        }
        else if(RPS.WhiteButtonOrder() == 3) {
            if (RPS.BlueButtonOrder() == 2){
                //Adjust fork height/angle from blue to white
                    ForkAngle.SetDegree(WHITEFORKANGLE);
                ForkLiftHeightEncode(SPOWER, BLUEWHITE);
                //ForkAdjust(SPOWER, BLUEWHITE, 100.);
            }
            else if (RPS.RedButtonOrder() == 2){
                //Adjust fork height/angle from red to white
                    ForkAngle.SetDegree(WHITEFORKANGLE);
                ForkLiftHeightEncode(-SPOWER, REDWHITE);
                //ForkAdjust(-SPOWER, REDWHITE, 100.);
            }
        }else if(RPS.RedButtonOrder() == 3) {
            if (RPS.BlueButtonOrder() == 2){
                //Adjust fork height/angle from blue to red
                ForkAngle.SetDegree(REDFORKANGLE);
                ForkLiftHeightEncode(SPOWER, BLUERED);
                //ForkAdjust(SPOWER, BLUERED, 45);
            }
            else if (RPS.WhiteButtonOrder() == 2){
                //Adjust fork height/angle from white to red
                    ForkAngle.SetDegree(REDFORKANGLE);
                ForkLiftHeightEncode(SPOWER, WHITERED);
                //ForkAdjust(SPOWER, WHITERED, 45.);
            }
        }

        //Run into the buttons for the third press
        time4.tic();
        if (RPS.BlueButtonOrder() == 3 ) {
                while (RPS.BlueButtonPressed() == 0 && time4.toc() < TIMEOUT5) {
                //move forward for the third button press
                rpsTurn(min);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                rpsTurn(min);
                pulseForward(-MPOWER, encodeLength(1.), 1.);

                //if the time is within the timeout and the button isn't pressed correctly run into the buttons again
                if (RPS.BlueButtonPressed() == 0 && time4.toc() < TIMEOUT5) {
                    pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);

                    rpsTurn(max);
                    pulseForward(-MPOWER, encodeLength(1.), 1.);
                    rpsTurn(max);
                    pulseForward(-MPOWER, encodeLength(1.), 1.);
                    }
                //backup
                pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);
                }
        }
        else if (RPS.WhiteButtonOrder() == 3 ) {
            while (RPS.WhiteButtonPressed() == 0 && time4.toc() < TIMEOUT5) {
            //move forward for the third button press
            rpsTurn(min);
            pulseForward(-MPOWER, encodeLength(1.), 1.);
            rpsTurn(min);
            pulseForward(-MPOWER, encodeLength(1.), 1.);

            //if the time is within the timeout and the button isn't pressed correctly run into the buttons again
            if (RPS.WhiteButtonPressed() == 0 && time4.toc() < TIMEOUT5) {
                pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);

                rpsTurn(max);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                rpsTurn(max);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                }
            //backup
            pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);
            }
        }
        else if (RPS.RedButtonOrder() == 3) {
            while (RPS.RedButtonPressed() == 0 && time4.toc() < TIMEOUT5) {
            //move forward for the third button press
            rpsTurn(redmax);
            pulseForward(-MPOWER, encodeLength(1.), 1.);
            rpsTurn(redmax);
            pulseForward(-MPOWER, encodeLength(1.), 1.);

            //if the time is within the timeout and the button isn't pressed correctly run into the buttons again
            if (RPS.RedButtonPressed() == 0 && time4.toc() < TIMEOUT5) {
                pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);

                rpsTurn(redmin);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                rpsTurn(redmin);
                pulseForward(-MPOWER, encodeLength(1.), 1.);
                }
            //backup
            pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);
            }
        }
        pulseForward(MPOWER, encodeLength(2.), TIMEOUT2);
    //*
    //*End of button code
    //*
}
