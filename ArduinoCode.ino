// ---------------------------------------------------------------------------
// FA17 flexi-feet arduino code.
// ---------------------------------------------------------------------------

#include <Mouse.h>
//ascii value REMOVE 45

int incomingByte0 = 1;

int incomingByte = 5;
int incomingByte2 = 5;
int incomingByte3 = 0;
int incomingByte4 = 5;

int pressSensitivity;
int downValue1 = 0;
int downValue2 = 0;
int downValue3 = 0;
int downValue4 = 0;
int downValue5 = 0;

int upValue1 = 0;
int upValue2 = 0;
int upValue3 = 0;
int upValue4 = 0;
int upValue5 = 0;

boolean basicForm1 = true;
boolean basicForm2 = true;


boolean leftPressed= false;
boolean rightPressed = false;

float downScroll = 0;
float upScroll = 0;

int inputPin = 0;
int val = 0;


#define outputA 6
#define outputB 7
#define outputC 8
#define outputD 9
int counter = 0;
int counter2 = 0;
int aState;
int cState;
int aLastState;
int cLastState;



void setup() {
  Mouse.begin();
  Serial.begin(9600);
  pinMode (outputA, INPUT);
  pinMode (outputB, INPUT);
  pinMode (outputC, INPUT);
  pinMode (outputD, INPUT);
  aLastState = digitalRead(outputA);
  cLastState = digitalRead(outputA);
}

int byteToInt(char in) {
  return in - '0';
}

void loop() {
  // updating counter //
  aState = digitalRead(outputA);
  if (aState != aLastState) {
    if (digitalRead(outputB) != aState) {
      counter ++;
    } else {
      counter --;
    }
    Serial.print("Position: ");
    Serial.println(counter);
  }
  aLastState = aState;
  cState = digitalRead(outputC);
  if (cState != cLastState) {
    if (digitalRead(outputD) != cState) {
      counter2 ++;
    } else {
      counter2 --;
    }
    Serial.print("Position 2: ");
    Serial.println(counter2);
  }
  cLastState = cState;
  // updating counter //

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte0 = Serial.read();
    incomingByte2 = Serial.read();
    incomingByte = Serial.read();
    incomingByte3 = Serial.read();
    incomingByte4 = Serial.read();

    incomingByte0 = byteToInt(incomingByte0);
    incomingByte = byteToInt(incomingByte);
    incomingByte2 = byteToInt(incomingByte2);
    incomingByte3 = byteToInt(incomingByte3);
    incomingByte4 = byteToInt(incomingByte4);



    // say what you got (-48):

    Serial.print("I received: ");
    Serial.println(incomingByte);
    Serial.print("I also received: ");
    Serial.println(incomingByte2);
    Serial.print("I also also received: ");
    Serial.println(incomingByte3);
    Serial.print("I also also also received: ");
    Serial.println(incomingByte4);
    while (Serial.available() > 0) Serial.read(); //Flushes the serial

  }

  val = analogRead(inputPin);
  upScroll = static_cast< float > (-counter2 / 10);
  downScroll = static_cast< float > (counter / 10);
  pressSensitivity = static_cast< float > (incomingByte4 / 5);
  if (incomingByte3 == 0) {
    
    mouseMoveValueAdjuster();
    if (incomingByte0 == 0) {
      int temp = upScroll;
//      upScroll = downScroll;
//      downScroll = temp;
      upValue1 = -upValue1;
      upValue2 = -upValue2;
      upValue3 = -upValue3;
      upValue4 = -upValue4;
      upValue5 = -upValue5;
      downValue1 = -downValue1;
      downValue2 = -downValue2;
      downValue3 = -downValue3;
      downValue4 = -downValue4;
      downValue5 = -downValue5;
    }
    if (upScroll > 0 && upScroll < 7) {
      if (basicForm1 == true) {
        if (upScroll == 1) {
          Mouse.move(0, 0, upValue1);
        }
        if (upScroll == 2) {
          Mouse.move(0, 0, upValue2);
        }
        if (upScroll == 3) {
          Mouse.move(0, 0, upValue3);
        }
        if (upScroll == 4) {
          Mouse.move(0, 0, upValue4);
        }
        if (upScroll == 5) {
          Mouse.move(0, 0, upValue5);
        }

        //      delay(100);
        customDelay(100);
        if (upScroll <= 2) {
          //        delay(40);
          customDelay(40);
        }
      }
      else {
        if (upScroll == 1) {
          Mouse.move(0, 0, upValue1);
        }
        if (upScroll == 2) {
          Mouse.move(0, 0, upValue2);
        }
        if (upScroll == 3) {
          Mouse.move(0, 0, upValue3);
        }
        if (upScroll == 4) {
          Mouse.move(0, 0, upValue4);
        }
        if (upScroll == 5) {
          Mouse.move(0, 0, upValue5);
        }

        if (upScroll == 1) {
          //        delay(150);
          customDelay(150);
        }
        else {
          //        delay(100);
          customDelay(100);
          //        delay(40);
          customDelay(40);
        }
      }
    }


    if (downScroll > 0 && downScroll < 6) {
      //    Serial.println(downScroll);
      //        Serial.println("values are the following : ");
      //    Serial.println(downValue1);
      //    Serial.println(downValue2);
      //    Serial.println(downValue3);
      //    Serial.println(downValue4);
      //    Serial.println(downValue5);
      //    Serial.println("values ended ");
      if (basicForm2 == true) {
        if (downScroll == 1) {
          Mouse.move(0, 0, downValue1);
        }
        if (downScroll == 2) {
          Mouse.move(0, 0, downValue2);
        }
        if (downScroll == 3) {
          Mouse.move(0, 0, downValue3);
        }
        if (downScroll == 4) {
          Mouse.move(0, 0, downValue4);
        }
        if (downScroll == 5) {
          Mouse.move(0, 0, downValue5);
        }

        //      delay(100);
        customDelay(100);
        if (downScroll <= 2) {
          //        delay(40);
          customDelay(40);
        }
      }
      else {
        if (downScroll == 1) {
          Mouse.move(0, 0, downValue1);
        }
        if (downScroll == 2) {
          Mouse.move(0, 0, downValue2);
        }
        if (downScroll == 3) {
          Mouse.move(0, 0, downValue3);
        }
        if (downScroll == 4) {
          Mouse.move(0, 0, downValue4);
        }
        if (downScroll == 5) {
          Mouse.move(0, 0, downValue5);
        }
        if (downScroll == 1) {
          //        delay(150);
          customDelay(150);
        }
        else {
          //        delay(100);
          customDelay(100);
          //        delay(40);
          customDelay(40);
        }
      }

    }
  }
  else{
    if(upScroll>=pressSensitivity && leftPressed == false){
      Mouse.click(MOUSE_RIGHT);
      leftPressed = true;
    }
    else if(upScroll <pressSensitivity && leftPressed == true){
      leftPressed = false;
    }
    if(downScroll>= pressSensitivity && rightPressed == false){
      Mouse.click();
      rightPressed = true;
    }
    else if(downScroll <pressSensitivity && rightPressed == true){
      rightPressed = false;
    }
  }
}
void scrollValueAdjuster() {
  if (upScroll <= 2) {
    upScroll = 1;
  }
  if (downScroll >= -2) {
    downScroll = 1;
  }
  //                //
  if (upScroll <= 4 && upScroll > 2) {
    upScroll = 2;
  }
  if (downScroll >= -4 && downScroll < -2) {
    downScroll = 2;
  }
  //                //
  if (upScroll <= 6 && upScroll > 4) {
    upScroll = 3;
  }
  if (downScroll >= -6 && downScroll < -4) {
    downScroll = 3;
  }
  //                //

  if (upScroll <= 8 && upScroll > 6) {
    upScroll = 4;
  }
  if (downScroll >= -8 && downScroll < -6) {
    downScroll = 4;
  }
  //                //

  if (upScroll <= 10 && upScroll > 8) {
    upScroll = 5;
  }
  if (downScroll >= -10 && downScroll < -8) {
    downScroll = 5;
  }
}

void mouseMoveValueAdjuster() {
  if (incomingByte > 8) {
    upValue1 = 3;
    upValue2 = 5;
    upValue3 = 3;
    upValue4 = 8;
    upValue5 = 14;
    basicForm1 = true;
  }
  if (incomingByte2 > 8) {
    downValue1 = -3;
    downValue2 = -5;
    downValue3 = -3;
    downValue4 = -8;
    downValue5 = -14;
    basicForm2 = true;
  }
  if (incomingByte == 8) {
    upValue1 = 2;
    upValue2 = 4;
    upValue3 = 2;
    upValue4 = 6;
    upValue5 = 8;
    basicForm1 = true;
  }
  if (incomingByte2 == 8) {
    downValue1 = -2;
    downValue2 = -4;
    downValue3 = -2;
    downValue4 = -6;
    downValue5 = -8;
    basicForm2 = true;
  }
  if (incomingByte == 7) {
    upValue1 = 1;
    upValue2 = 3;
    upValue3 = 1;
    upValue4 = 4;
    upValue5 = 7;
    basicForm1 = true;
  }
  if (incomingByte2 == 7) {
    downValue1 = -1;
    downValue2 = -3;
    downValue3 = -1;
    downValue4 = -4;
    downValue5 = -7;
    basicForm2 = true;
  }
  if (incomingByte == 6) {
    upValue1 = 1;
    upValue2 = 3;
    upValue3 = 1;
    upValue4 = 3;
    upValue5 = 6;
    basicForm1 = true;
  }
  if (incomingByte2 == 6) {
    downValue1 = -1;
    downValue2 = -3;
    downValue3 = -1;
    downValue4 = -3;
    downValue5 = -6;
    basicForm2 = true;
  }
  if (incomingByte == 5) {
    upValue1 = 1;
    upValue2 = 3;
    upValue3 = 1;
    upValue4 = 2;
    upValue5 = 5;
    basicForm1 = true;
  }
  if (incomingByte2 == 5) {
    downValue1 = -1;
    downValue2 = -3;
    downValue3 = -1;
    downValue4 = -2;
    downValue5 = -5;
    basicForm2 = true;
  }
  if (incomingByte == 4) {
    upValue1 = 1;
    upValue2 = 3;
    upValue3 = 1;
    upValue4 = 2;
    upValue5 = 4;
    basicForm1 = true;
  }
  if (incomingByte2 == 4) {
    downValue1 = -1;
    downValue2 = -3;
    downValue3 = -1;
    downValue4 = -2;
    downValue5 = -4;
    basicForm2 = true;
  }
  if (incomingByte == 3) {
    upValue1 = 1;
    upValue2 = 1;
    upValue3 = 3;
    upValue4 = 6;
    upValue5 = 8;
    basicForm1 = false;
  }
  if (incomingByte2 == 3) {
    downValue1 = -1;
    downValue2 = -1;
    downValue3 = -3;
    downValue4 = -6;
    downValue5 = -8;
    basicForm2 = false;
  }
  if (incomingByte == 2) {
    upValue1 = 1;
    upValue2 = 1;
    upValue3 = 2;
    upValue4 = 4;
    upValue5 = 6;
    basicForm1 = false;
  }
  if (incomingByte2 == 2) {
    downValue1 = -1;
    downValue2 = -1;
    downValue3 = -2;
    downValue4 = -4;
    downValue5 = -6;
    basicForm2 = false;
  }
  if (incomingByte == 1) {
    upValue1 = 1;
    upValue2 = 1;
    upValue3 = 2;
    upValue4 = 3;
    upValue5 = 4;
    basicForm1 = false;
  }
  if (incomingByte2 == 1) {
    downValue1 = -1;
    downValue2 = -1;
    downValue3 = -2;
    downValue4 = -3;
    downValue5 = -4;
    basicForm2 = false;
  }
}


void customDelay(long ms) {
  unsigned long time_now = millis();
  while (millis() < time_now + ms) {
    aState = digitalRead(outputA);
    if (aState != aLastState) {
      if (digitalRead(outputB) != aState) {
        counter ++;
      } else {
        counter --;
      }
      Serial.print("Position: ");
      Serial.println(counter);
    }
    aLastState = aState;
    cState = digitalRead(outputC);
    if (cState != cLastState) {
      if (digitalRead(outputD) != cState) {
        counter2 ++;
      } else {
        counter2 --;
      }
      Serial.print("Position 2: ");
      Serial.println(counter2);
    }
    cLastState = cState;
  }
}
