// Definitions of motor pins and direction
#define MOTOR_DIRECTION     0 
#define PIN_DIRECTION_RIGHT 3
#define PIN_DIRECTION_LEFT  4
#define PIN_MOTOR_PWM_RIGHT 5
#define PIN_MOTOR_PWM_LEFT  6

// Function to control the motors with specified speeds for left and right motors
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

void setup() {
  // Setting pins as outputs
  pinMode(PIN_DIRECTION_LEFT, OUTPUT);
  pinMode(PIN_MOTOR_PWM_LEFT, OUTPUT);
  pinMode(PIN_DIRECTION_RIGHT, OUTPUT);
  pinMode(PIN_MOTOR_PWM_RIGHT, OUTPUT);
}

void loop() {
  // Moving forward
  motorRun(200, 200); // Moves both motors forward
  delay(1000);        // Waits for 1 second

  // Turning right
  motorRun(200, -200); // Moves left motor forward and right motor backward, simulating a right turn
  delay(500);          // Waits for 0.5 seconds

   //Move forward
  motorRun(200, 200);
  delay(1000);

 //Turn right
  motorRun(200, -200);
  delay(500);

  //Move forward
  motorRun(200, 200);
  delay(1000);

  //Turn right
  motorRun(200, -200);
  delay(500);

  //Move forward
  motorRun(200, 200);
  delay(1000);
  
  // Stopping
  motorRun(0, 0);    // Stops both motors
  delay(2000);       // Waits for 2 seconds

  // Moving backward
  motorRun(-200, -200); // Moves both motors backward
  delay(1000);           // Waits for 1 second

  // Turning left
  motorRun(-200, 200); // Moves right motor forward and left motor backward, simulating a left turn
  delay(500);          // Waits for 0.5 seconds

  //Move back
  motorRun(-200, -200);
  delay(1000);

    //Turn left
  motorRun(-200, 200);
  delay(500);

  //Move back
  motorRun(-200, -200);
  delay(1000);
  
  //Turn left
  motorRun(-200, 200);
  delay(500);

  //Move back
  motorRun(-200, -200);
  delay(1000);

  //Stop
  motorRun(0, 0);
  delay(2000);

}
