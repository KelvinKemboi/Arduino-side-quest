const int pin=11;
void dot(){
  digitalWrite(pin, HIGH);
  delay(200);
  digitalWrite(pin, LOW);
  delay(200);
}
void dash(){
  digitalWrite(pin, HIGH);
  delay(600);
  digitalWrite(pin, LOW);
  delay(200);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  dot(); dot(); dot();
  delay(400);
  dash(); dash(); dash(); 
  delay(400);
  dot(); dot(); dot();
  delay(1000);
}
