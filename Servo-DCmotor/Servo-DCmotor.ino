#include <Servo.h>

const int ledpin = 13;

const int xpin = A0;
const int ypin = A1;
const int buttonpin = 2;

const int xservopin = 8;

const int ENA = 5;
const int forwardPin = 7;
const int backwardPin = 12;

const int deadzone = 60;
const int minspeed = 70; 

int center = 512;   

int xval;
int yval;
int buttonstate;
int xservopos;

Servo xservo;

void setup() {
  Serial.begin(9600);

  pinMode(ledpin, OUTPUT);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(buttonpin, INPUT_PULLUP);

  pinMode(ENA, OUTPUT);
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);

  xservo.attach(xservopin);
  long sum = 0;
  for (int i = 0; i < 32; i++) {
    sum += analogRead(ypin);
    delay(10);
  }
  center = sum / 32;

  Serial.print("Y center measured at: ");
  Serial.println(center);
}

void loop() {
  xval = analogRead(xpin);
  yval = analogRead(ypin);
  buttonstate = digitalRead(buttonpin);
  xservopos = map(xval, 0, 1023, 0, 180);

  if (buttonstate == LOW) {
    xservopos = 90;
    digitalWrite(ledpin, HIGH);
  } else {
    digitalWrite(ledpin, LOW);
  }

  xservo.write(xservopos);
  int offset = yval - center;

  if (abs(offset) < deadzone) {
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, LOW);
    analogWrite(ENA, 0);
  } else {
    int range;

    if (offset > 0) {// forward
      digitalWrite(forwardPin, HIGH);
      digitalWrite(backwardPin, LOW);
      range = 1023 - center; 
    } else { // backward
      digitalWrite(forwardPin, LOW);
      digitalWrite(backwardPin, HIGH);
      range = center;           
    }

    int speed = map(abs(offset), deadzone, range, minspeed, 255);
    speed = constrain(speed, minspeed, 255);
    analogWrite(ENA, speed);
  }

  Serial.print("X: ");
  Serial.println(xservopos);
  Serial.print("Yraw: ");
  Serial.println(yval);
  Serial.print("Off: ");
  Serial.println(offset);
  Serial.print("Btn: ");
  Serial.println(buttonstate);

  delay(20);
}