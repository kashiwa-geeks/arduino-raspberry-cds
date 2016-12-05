char input[30];   // 文字列格納用
int i = 0;  // 文字数のカウンタ
   
void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}
   
void loop() {
  
  // データ受信したとき
  if (Serial.available()) {
    input[i] = Serial.read();
     // 文字数が30以上 or 末尾文字
    if (i > 30 || input[i] == '.') {
      // 末尾に終端文字の挿入
      input[i] = '\0';
      // 受信文字列を送信
      if (String(input)=="r1"){
        digitalWrite(11, HIGH);
      }
      else if (String(input)=="r0"){
        digitalWrite(11,LOW);
      }
      else if (String(input)=="b1"){
        digitalWrite(10, HIGH);
      }
      else if (String(input)=="b0"){
        digitalWrite(10,LOW);
      }
      else if (String(input)=="g1"){
        digitalWrite(9, HIGH);
      }
      else if (String(input)=="g0"){
        digitalWrite(9,LOW);
      }
      
      // カウンタの初期化
      i = 0;
    }
    else { i++; }
  }
}
