const int EN_A = 10; // PWM, Motor A speed
const int IN1 = 9; // Motor A direction
const int IN2 = 8; // Motor A direction
const int EN_B = 5; // PWM, Motor B speed
const int IN3 = 7; // Motor B direction
const int IN4 = 6; // Motor B direction

const int JOY_Y = A0; // forward/backward axis
const int CENTER = 512; // joystick resting value (0–1023)
const int DEADZONE = 60; // ignore tiny movements near center
const int MIN_SPEED = 90; // lowest PWM that actually moves the motor
const int MAX_SPEED = 255; // max PWM (0–255)

void setup() {
  pinMode(EN_A, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN_B, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  int y = analogRead(JOY_Y); // read joystick, 0–1023
  int offset = y - CENTER; // distance from resting center

  if (abs(offset) < DEADZONE) {
    stopMotors(); // joystick centered-stop
  } else if (offset > 0) {
    int speed = map(offset, DEADZONE, 1023 - CENTER, MIN_SPEED, MAX_SPEED);
    forward(constrain(speed, MIN_SPEED, MAX_SPEED));
  } else {
    int speed = map(-offset, DEADZONE, CENTER, MIN_SPEED, MAX_SPEED);
    backward(constrain(speed, MIN_SPEED, MAX_SPEED));
  }
}

// Both motors forward
void forward(int speed) {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  analogWrite(EN_A, speed);
  analogWrite(EN_B, speed);
}

// Both motors backward 
void backward(int speed) {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  analogWrite(EN_A, speed);
  analogWrite(EN_B, speed);
}

// Stop both motors 
void stopMotors() {
  analogWrite(EN_A, 0);
  analogWrite(EN_B, 0);
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}