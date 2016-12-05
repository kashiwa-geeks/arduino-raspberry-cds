int led = 10;           // the PWM pin the LED is attached to

// the setup routine runs once when you press reset:
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int val = analogRead(0);

  // set the brightness of pin 9:
  analogWrite(led, 255 - val / 4);

  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
