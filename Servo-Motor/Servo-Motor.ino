#include <Servo.h>
int ledpin = 13;

int xpin = A0;
int ypin = A1;
int buttonpin = 2;
int xval;
int yval;
int buttonstate;

int xservopin = 8;
int yservopin = 10;
int xservopos;
int yservopos;

Servo xservo;
Servo yservo;

void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(buttonpin, INPUT_PULLUP);

  xservo.attach(xservopin);
  yservo.attach(yservopin);

  Serial.begin(9600);
}

void loop() {
  xval = analogRead(xpin);
  yval = analogRead(ypin);
  buttonstate = digitalRead(buttonpin);

  // Map the 0-1023 analog range onto the servo's 0-180 degree range
  xservopos = map(xval, 0, 1023, 0, 180);
  yservopos = map(yval, 0, 1023, 0, 180);

  // Button pressed (LOW with INPUT_PULLUP) recenters both servos and lights LED
  if (buttonstate == LOW) {
    xservopos = 90;
    yservopos = 90;
    digitalWrite(ledpin, HIGH);
  } else {
    digitalWrite(ledpin, LOW);
  }

  xservo.write(xservopos);
  yservo.write(yservopos);

  Serial.print("X: ");
  Serial.println(xservopos);
  Serial.print("Y: ");
  Serial.println(yservopos);
  Serial.print("Btn: ");
  Serial.println(buttonstate);

  delay(15);  // give the servos time to reach the position
}