#include "Freenove_WS2812B_RGBLED_Controller.h"

#define I2C_ADDRESS  0x20 //I2C address of LEDs 
#define LEDS_COUNT   10   //number of lEDs

#define MOTOR_DIRECTION     0 
#define PIN_DIRECTION_LEFT  4
#define PIN_DIRECTION_RIGHT 3
#define PIN_MOTOR_PWM_LEFT  6
#define PIN_MOTOR_PWM_RIGHT 5

#define PIN_BATTERY      A0
#define PIN_BUZZER      A0
#define MOTOR_PWM_DEAD    10
float batteryVoltage = 0;
bool isBuzzered = false;

Freenove_WS2812B_Controller strip(I2C_ADDRESS, LEDS_COUNT, TYPE_GRB); //initialization

void setup() {
  while (!strip.begin()); //if initialization is successs

  Serial.begin(9600);  //set baud rate
  pinsSetup();          //set pin mode 

  strip.setAllLedsColor(255, 255, 0); // Set all LED color to yellow
  motorRun(150, 150);   //Car move forward
  alarm(3, 1);          //4 beat, 1 repeat
  strip.setAllLedsColor(0x0000FF); // Set all LED color to blue
  delay(1000);
  resetCar();     //Stop the car and turn off the buzzer

  strip.setAllLedsColor(0x00FF00); // Set all LED color to green
  delay(1000);
  motorRun(-150, -150); //Car move back
  strip.setAllLedsColor(0xFF0000); // Set all LED color to red
  setBuzzer(true);      //turn on buzzer
  delay(1000);
  resetCar();     //Stop the car and turn off the buzzer
}

void loop() {
  if (getBatteryVoltage() == true) {
    Serial.print("Voltage: ");
    Serial.println(batteryVoltage);
  }

  int r = random(0, 255);  //a random value between 0~255
  int g = random(0, 255);  //a random value between 0~255
  int b = random(0, 255);  //a random value between 0~255
  strip.setAllLedsColor(r, g, b); //Set all LED color with current r, g, b value
  delay(1000);
}

void pinsSetup() {
  pinMode(PIN_DIRECTION_LEFT, OUTPUT);
  pinMode(PIN_MOTOR_PWM_LEFT, OUTPUT);
  pinMode(PIN_DIRECTION_RIGHT, OUTPUT);
  pinMode(PIN_MOTOR_PWM_RIGHT, OUTPUT);
  setBuzzer(false); //Turn off the Buzzer
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

bool getBatteryVoltage() {
  if (!isBuzzered) {
    pinMode(PIN_BATTERY, INPUT);
    int batteryADC = analogRead(PIN_BATTERY);
    if (batteryADC < 614)   // 3V/12V ,Voltage read: <2.1V/8.4V
    {
      batteryVoltage = batteryADC / 1023.0 * 5.0 * 4;
      return true;
    }
  }
  return false;
}

void setBuzzer(bool flag) {
  isBuzzered = flag;
  pinMode(PIN_BUZZER, flag);
  digitalWrite(PIN_BUZZER, flag);
}

void alarm(u8 beat, u8 repeat) {
  beat = constrain(beat, 1, 9);
  repeat = constrain(repeat, 1, 255);
  for (int j = 0; j < repeat; j++) {
    for (int i = 0; i < beat; i++) {
      setBuzzer(true);
      delay(150);
      setBuzzer(false);
      delay(150);
    }
    delay(500);
  }
}

void resetCar() {
  motorRun(0, 0);
  setBuzzer(false);
}

