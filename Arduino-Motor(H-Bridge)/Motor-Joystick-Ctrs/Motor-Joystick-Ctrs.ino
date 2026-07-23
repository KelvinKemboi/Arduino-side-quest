const int xpin = A0;
const int ypin = A1;
const int buttonpin = 2;
const int ENA = 9; 
const int forwardPin = 8;  
const int backwardPin = 12; 

const int center = 512; // joystick resting value
const int deadzone = 60; // ignore small wobbles near center

int xval;
int yval;
int buttonstate;

void setup() {
  Serial.begin(9600);
  pinMode(buttonpin, INPUT_PULLUP);

  pinMode(ENA, OUTPUT);
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);
}

void loop() {
  xval = analogRead(xpin);
  yval = analogRead(ypin);
  buttonstate = digitalRead(buttonpin);

  int offset = yval-center;

  if (abs(offset) < deadzone) {
    // stick at rest - stop  motor
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, LOW);
    analogWrite(ENA, 0);
  }
  else {
    // direction
    if (offset>0) {// forward
      digitalWrite(forwardPin, HIGH);
      digitalWrite(backwardPin, LOW);
    } else { // backward
      digitalWrite(forwardPin, LOW);
      digitalWrite(backwardPin, HIGH);
    }
    int speed = map(abs(offset), deadzone, 512, 0, 255);
    speed = constrain(speed, 0, 255);
    analogWrite(ENA, speed);
  }

  Serial.print("y: ");     
  Serial.println(yval);
  Serial.print("btn: "); 
  Serial.println(buttonstate);

  delay(20); 
}