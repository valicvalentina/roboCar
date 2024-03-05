#define PIN_BATTERY A0
#define PIN_BUZZER  A0

float batteryVoltage = 0;

void setup() {
  Serial.begin(9600); // Set baud rate
  pinMode(PIN_BUZZER, OUTPUT);

  // Buzzer initialization beep pattern
  buzz(500);
  delay(500);
  buzz(500);
}

void loop() {
  // Buzzer and battery voltage detection use A0 pin together,
  // so the buzzer must be turned off when reading battery voltage
  disableBuzzer();

  // Read and print battery voltage
  if (readBatteryVoltage()) {
    Serial.print("Battery Voltage: ");
    Serial.print(batteryVoltage);
    Serial.println(" V");
  } else {
    Serial.println("Port busy! Please turn off buzzer before reading battery voltage.");
  }
  delay(1000);
}

// Function to disable the buzzer
void disableBuzzer() {
  digitalWrite(PIN_BUZZER, LOW);
}

// Function to read battery voltage
bool readBatteryVoltage() {
  pinMode(PIN_BATTERY, INPUT);
  int batteryADC = analogRead(PIN_BATTERY);
  
  if (batteryADC < 614) { // Voltage read: <2.1V/8.4V
    batteryVoltage = batteryADC / 1023.0 * 5.0 * 4; // Calculate voltage
    return true;
  } else {
    return false;
  }
}

// Producing a beep sound
void buzz(int duration) {
  digitalWrite(PIN_BUZZER, HIGH);
  delay(duration);
  digitalWrite(PIN_BUZZER, LOW);
}
