#include "Servo.h"      //servo library

#define PIN_SERVO  2    // servo pin

Servo servo;            //servo object to control a servo
byte servoOffset = 0;   
void setup() {
  servo.attach(PIN_SERVO);        //initialize servo 
  servo.write(90 + servoOffset);  //Calibrate servo
}

void loop() {
  servo.write(45);      //servo rotate 45°
  delay(1000);          //delay 1000ms

  servo.write(120);      //servo rotate 120°
  delay(1000);

  servo.write(130);    //servo rotate 130°
  delay(1000);

  servo.write(40);      //servo rotate 40°
  delay(1000);
}