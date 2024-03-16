#include "IR_remote.h"

float batteryVoltage = 0;
bool isBuzzered = false;

void pinsSetup() {
	pinMode(PIN_DIRECTION_LEFT, OUTPUT);
	pinMode(PIN_MOTOR_PWM_LEFT, OUTPUT);
	pinMode(PIN_DIRECTION_RIGHT, OUTPUT);
	pinMode(PIN_MOTOR_PWM_RIGHT, OUTPUT);
	setBuzzer(false);
}

void motorRun(int speedl, int speedr) {
  // Determining direction for the left motor
  int dirL = (speedl >= 0) ? 0 : 1; // If speed is positive, set direction forward, otherwise set direction backward
  if (MOTOR_DIRECTION == 0) dirL = !dirL; // If direction is inverted, toggle the value

  // Determining direction for the right motor
  int dirR = (speedr >= 0) ? 1 : 0; // If speed is positive, set direction forward, otherwise set direction backward
  if (MOTOR_DIRECTION == 0) dirR = !dirR; // If direction is inverted, toggle the value

  // Setting direction for the left and right motor
  digitalWrite(PIN_DIRECTION_LEFT, dirL);
  digitalWrite(PIN_DIRECTION_RIGHT, dirR);

  // Setting speed for the left and right motor
  analogWrite(PIN_MOTOR_PWM_LEFT, abs(speedl)); // Set absolute value of speed
  analogWrite(PIN_MOTOR_PWM_RIGHT, abs(speedr)); // Set absolute value of speed
}

void setBuzzer(bool flag) {
	isBuzzered = flag;
	pinMode(PIN_BUZZER, flag);
	digitalWrite(PIN_BUZZER, flag);
}

