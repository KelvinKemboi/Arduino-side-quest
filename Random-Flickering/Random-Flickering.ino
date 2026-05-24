const int pins[]={6, 9, 11};
const int on=300;
const int off=500;
int len=3;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<len;i++){
    int p=pins[i];
    pinMode(p, OUTPUT);
  }
  randomSeed(analogRead(A0)); //makes it ocmpletely random
}

void loop() {
  // put your main code here, to run repeatedly:
  int choice=random(0, len);

  digitalWrite(pins[choice], HIGH);
  delay(on);
  digitalWrite(pins[choice], LOW);
  delay(off);
}
