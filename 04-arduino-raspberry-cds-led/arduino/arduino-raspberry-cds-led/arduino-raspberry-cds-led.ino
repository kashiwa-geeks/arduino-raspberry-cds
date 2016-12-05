char input[30];   // 文字列格納用
int i = 0;  // 文字数のカウンタ

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
  if (Serial.available()) {
    while (1) {
      input[i] = Serial.read();
      if (i < 30 && input[i] != '.') {
        i++;
      } else { // 文字数が30以上 or 末尾文字
        // 末尾に終端文字の挿入
        input[i] = '\0';
        // カウンタの初期化
        i = 0;
        break;
      }
    }

    if (String(input) == "r"){
      ledRedFlag ^= true; //Flag反転
    }
    if (String(input) == "r1"){
      ledRedFlag = true;
    }
    else if (String(input) == "r0"){
      ledRedFlag = false;
    }
    else if (String(input) == "g"){
      ledGreenFlag ^= true; //Flag反転
    }
    else if (String(input) == "g1"){
      ledGreenFlag = true;
    }
    else if (String(input) == "g0"){
      ledGreenFlag = false;
    }
    else if (String(input) == "b"){
      ledBlueFlag ^= true; //Flag反転
    }
    else if (String(input) == "b1"){
      ledBlueFlag = true;
    }
    else if (String(input) == "b0"){
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
