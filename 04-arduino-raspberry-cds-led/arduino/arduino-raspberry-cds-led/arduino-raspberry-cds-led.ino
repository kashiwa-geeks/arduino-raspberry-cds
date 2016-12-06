int ledRed = 11; //PWMピン
int ledGreen = 9; //PWMピン
int ledBlue = 10; //PWMピン
bool ledRedFlag = true;
bool ledGreenFlag = false;
bool ledBlueFlag = false;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('.');

    if (str == "r"){
      ledRedFlag ^= true; //Flag反転
    }
    else if (str == "r1"){
      ledRedFlag = true;
    }
    else if (str == "r0"){
      ledRedFlag = false;
    }
    else if (str == "g"){
      ledGreenFlag ^= true; //Flag反転
    }
    else if (str == "g1"){
      ledGreenFlag = true;
    }
    else if (str == "g0"){
      ledGreenFlag = false;
    }
    else if (str == "b"){
      ledBlueFlag ^= true; //Flag反転
    }
    else if (str == "b1"){
      ledBlueFlag = true;
    }
    else if (str == "b0"){
      ledBlueFlag = false;
    }

  }

  int val = analogRead(0);
  //Serial.println(val);

  // set the brightness:
  analogWrite(ledRed, ledRedFlag ? (255 - val / 4) : 0);
  analogWrite(ledGreen, ledGreenFlag ? (255 - val / 4) : 0);
  analogWrite(ledBlue, ledBlueFlag ? (255 - val / 4) : 0);

  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
