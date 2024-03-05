#define PIN_BUZZER      A0

void setup() {
  pinMode(PIN_BUZZER, OUTPUT);
  digitalWrite(PIN_BUZZER, HIGH);  //turn on buzzler
  delay(100);
  digitalWrite(PIN_BUZZER, LOW); //turn off buzzler
}

void loop() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(PIN_BUZZER, HIGH); 
    delay(1000);
    digitalWrite(PIN_BUZZER, LOW);  
    delay(100);
  }
  delay(3000);
}
