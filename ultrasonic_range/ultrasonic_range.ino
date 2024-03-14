#include "Servo.h"             // Include servo library

#define PIN_SERVO      2       // Define servo pin

#define PIN_SONIC_TRIG    7    // Define Trig pin for ultrasonic sensor
#define PIN_SONIC_ECHO    8    // Define Echo pin for ultrasonic sensor

#define MAX_DISTANCE    1000   // Maximum distance (cm)
#define SONIC_TIMEOUT   (MAX_DISTANCE * 60) // Calculate timeout 
#define SOUND_VELOCITY  340    // Sound velocity: 340 m/s

Servo servo;                 // Create servo object
byte servoOffset = 0;        // Change the value for servo calibration
float distance[4];           // Define an array for distances

void setup() {
  Serial.begin(9600);
  pinMode(PIN_SONIC_TRIG, OUTPUT); // Set Trig pin as output
  pinMode(PIN_SONIC_ECHO, INPUT);  // Set Echo pin as input
  servo.attach(PIN_SERVO);         // Initialize servo motor
  servo.write(90 + servoOffset);   // Change offset for servo calibration
}

void loop() {
  moveServo(45);          // Rotate servo to 45 degrees
  delay(1000);
  distance[0] = getDistance(); // Get distance and save it into array

  moveServo(90);          // Rotate servo to 90 degrees
  delay(1000);
  distance[1] = getDistance();

  moveServo(135);         // Rotate servo to 135 degrees
  delay(1000);
  distance[2] = getDistance();

  moveServo(90);          // Rotate servo back to 90 degrees
  delay(1000);
  distance[3] = getDistance();
  
Serial.print("Distance: Left=");
Serial.print(distance[0]);
Serial.print("cm, Middle=");
Serial.print(distance[1]);
Serial.print("cm, Right=");
Serial.print(distance[2]);
Serial.print("cm, Middle2=");
Serial.print(distance[3]);
Serial.println("cm"); // Print a new line for the next output

}

void moveServo(int angle) {
  servo.write(angle); // Set servo motor to specific angle
}

float getDistance() {
  unsigned long pingTime;
  float distance;
  
  digitalWrite(PIN_SONIC_TRIG, HIGH); // Activate HC-SR04
  delayMicroseconds(10);
  digitalWrite(PIN_SONIC_TRIG, LOW);
  pingTime = pulseIn(PIN_SONIC_ECHO, HIGH, SONIC_TIMEOUT); // Measure echo time
  if (pingTime != 0)
    distance = (float)pingTime * SOUND_VELOCITY / 2 / 10000; // Calculate distance
  else
    distance = MAX_DISTANCE;
  return distance; // Return distance
}

