#define LED_PIN 8
#define BUTTON_PIN 7

bool lastButton;
bool ledState = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  lastButton = digitalRead(BUTTON_PIN);
}

void loop() {
  bool button = digitalRead(BUTTON_PIN);

  // detect a press (HIGH -> LOW transition)
  if (lastButton==HIGH && button==LOW) {
    ledState=!ledState;  
    digitalWrite(LED_PIN, ledState);
    delay(50);
  }
  lastButton = button;
}