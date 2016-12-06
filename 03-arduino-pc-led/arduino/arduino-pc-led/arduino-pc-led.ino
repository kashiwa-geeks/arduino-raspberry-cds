int ledRed = 11;
int ledGreen = 9;
int ledBlue = 10;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // データ受信したとき
  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('.');

    if (str == "r1"){
      digitalWrite(ledRed, HIGH);
    }
    else if (str == "r0"){
      digitalWrite(ledRed,LOW);
    }
    else if (str == "b1"){
      digitalWrite(ledBlue, HIGH);
    }
    else if (str == "b0"){
      digitalWrite(ledBlue,LOW);
    }
    else if (str == "g1"){
      digitalWrite(ledGreen, HIGH);
    }
    else if (str == "g0"){
      digitalWrite(ledGreen,LOW);
    }

  }
}
