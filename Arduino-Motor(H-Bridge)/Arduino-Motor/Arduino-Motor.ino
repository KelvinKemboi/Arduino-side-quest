const int forwardPin  = 8; 
const int backwardPin = 12;  

const int but1pin = 2; // hold for forward
const int but2pin = 3; // hold for backward

int but1;
int but2;

void setup() {
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);
  pinMode(but1pin, INPUT_PULLUP);
  pinMode(but2pin, INPUT_PULLUP);
}

void loop() {
  but1 = digitalRead(but1pin);
  but2 = digitalRead(but2pin);

  // Button 1 held - drive forward
  if (but1 == HIGH) {
    digitalWrite(forwardPin, LOW); 
  } else {
    digitalWrite(forwardPin, HIGH);   
  }
  // Button 2 held - drive backward
  if (but2 == HIGH) {
    digitalWrite(backwardPin, LOW);
  } else {
    digitalWrite(backwardPin, HIGH); 
  }
}