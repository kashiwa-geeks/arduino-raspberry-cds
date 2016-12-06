void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // データ受信したとき
  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('.');

    if (str == "r1"){
      digitalWrite(11, HIGH);
    }
    else if (str == "r0"){
      digitalWrite(11,LOW);
    }
    else if (str == "b1"){
      digitalWrite(10, HIGH);
    }
    else if (str == "b0"){
      digitalWrite(10,LOW);
    }
    else if (str == "g1"){
      digitalWrite(9, HIGH);
    }
    else if (str == "g0"){
      digitalWrite(9,LOW);
    }

  }
}
