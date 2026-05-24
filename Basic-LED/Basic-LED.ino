#include <ctype.h>

const int LED_PIN1=9;
const int LED_PIN2=5;
int onTime=500;
int offTime=500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //activate the serial port- BAUD RATE- how fast the coe will communicate with the ciruit board
  pinMode(LED_PIN1, OUTPUT); //sends a signal out
  pinMode(LED_PIN2, OUTPUT);
  Serial.println("Type 0, 1, 2 or 3...");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    char val=Serial.read();
    int state1=digitalRead(LED_PIN1);
    int state2=digitalRead(LED_PIN2);
    //for turning both off
    if(tolower(val)=='n'){
      digitalWrite(LED_PIN1, LOW);
      digitalWrite(LED_PIN2, LOW);
      //Serial.print("Both are off");
    }else if(tolower(val)=='r'){ //turning red LED on
      if(state1==1){
        digitalWrite(LED_PIN1, LOW);
      }else{
       digitalWrite(LED_PIN1, HIGH); 
      }
      //Serial.print("LED 1 is on");
    }else if(tolower(val)=='b'){ //turning Blue LED on
      if(state2==1){
        digitalWrite(LED_PIN2, LOW);
      }else{
       digitalWrite(LED_PIN2, HIGH); 
      }
      //Serial.print("LED 2 is on");
    }else if(tolower(val)=='a'){ //Turhing both on
      digitalWrite(LED_PIN1, HIGH);
      digitalWrite(LED_PIN2, HIGH);
     // Serial.print("Both are on");
    }
  }
}
