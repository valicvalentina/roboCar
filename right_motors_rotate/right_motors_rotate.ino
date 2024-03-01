#define PIN_DIRECTION_RIGHT 3
#define PIN_DIRECTION_LEFT  4
#define PIN_MOTOR_PWM_RIGHT 5
#define PIN_MOTOR_PWM_LEFT  6

void setup() {
  // Setting pins as outputs
  pinMode(PIN_DIRECTION_LEFT, OUTPUT);
  pinMode(PIN_MOTOR_PWM_LEFT, OUTPUT);
  pinMode(PIN_DIRECTION_RIGHT, OUTPUT);
  pinMode(PIN_MOTOR_PWM_RIGHT, OUTPUT);
}

void loop() {
  // Start right motors forward
  rotateMotor(PIN_DIRECTION_RIGHT, PIN_MOTOR_PWM_RIGHT, HIGH, 255);
  delay(2000);
  stopMotor(PIN_MOTOR_PWM_RIGHT);
  delay(500);

  // Start right motors backward
  rotateMotor(PIN_DIRECTION_RIGHT, PIN_MOTOR_PWM_RIGHT, LOW, 255);
  delay(2000);
  stopMotor(PIN_MOTOR_PWM_RIGHT);
  delay(500);
}

// Function to rotate the motor
void rotateMotor(int pinDirection, int pinPWM, int direction, int speed) {
  digitalWrite(pinDirection, direction);
  analogWrite(pinPWM, speed);
}

// Function to stop the motor
void stopMotor(int pinPWM) {
  analogWrite(pinPWM, 0);
}