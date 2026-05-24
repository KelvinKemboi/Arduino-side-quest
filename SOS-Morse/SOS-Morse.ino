const int pin=11;
const int dot_delay=200;
const int dash_delay=600;
const int gap_delay=400;
const int end_delay=1000;
void dot(){
  digitalWrite(pin, HIGH);
  delay(dot_delay);
  digitalWrite(pin, LOW);
  delay(dot_delay);
}
void dash(){
  digitalWrite(pin, HIGH);
  delay(dash_delay);
  digitalWrite(pin, LOW);
  delay(dot_delay);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  dot(); dot(); dot();
  delay(gap_delay);
  dash(); dash(); dash(); 
  delay(gap_delay);
  dot(); dot(); dot();
  delay(end_delay);
}
