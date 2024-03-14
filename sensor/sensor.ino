#define PIN_TRACKING_LEFT  A1
#define PIN_TRACKING_CENTER A2
#define PIN_TRACKING_RIGHT  A3

// Define an array to store sensor values
u8 sensorValue[4];

void setup() {
  // Initialize serial communication with a baud rate of 9600
  Serial.begin(9600);

  // Set sensor pins as inputs
  pinMode(PIN_TRACKING_LEFT, INPUT);
  pinMode(PIN_TRACKING_RIGHT, INPUT);
  pinMode(PIN_TRACKING_CENTER, INPUT);
}

void loop() {
  // Read sensor values
  sensorValue[0] = digitalRead(PIN_TRACKING_LEFT);
  sensorValue[1] = digitalRead(PIN_TRACKING_CENTER);
  sensorValue[2] = digitalRead(PIN_TRACKING_RIGHT);

  // Combine sensor values into a single value
  sensorValue[3] = sensorValue[0] << 2 | sensorValue[1] << 1 | sensorValue[2];

  // Print sensor values
  Serial.print("Sensor Values (Left / Center / Right / Combined) : ");
  Serial.print(sensorValue[0]);
  Serial.print(" / ");
  Serial.print(sensorValue[1]);
  Serial.print(" / ");
  Serial.print(sensorValue[2]);
  Serial.print(" / ");
  Serial.println(sensorValue[3]);

  // Delay for 500 milliseconds
  delay(500);
}

