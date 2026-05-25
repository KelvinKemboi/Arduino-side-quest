const int echoPin=5;
const int trigPin=6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration;
  float distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration=pulseIn(echoPin, HIGH, 30000);
  Serial.print("Debug: "); //if 0, error
  Serial.println(duration);

  distance=(duration*0.0343)/2;
  Serial.println(distance);
  delay(100);
}
