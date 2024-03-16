#define PIN_DIRECTION_LEFT  4
#define PIN_DIRECTION_RIGHT 3
#define PIN_MOTOR_PWM_LEFT  6
#define PIN_MOTOR_PWM_RIGHT 5
#define MOTOR_DIRECTION     0
#define TK_FORWARD_SPEED 90
#define TK_STOP_SPEED 0
#define TK_TURN_SPEED_LV4 160 
#define TK_TURN_SPEED_LV3 130 
#define TK_TURN_SPEED_LV2 -120 
#define TK_TURN_SPEED_LV1 -140
#define PIN_TRACKING_LEFT A1
#define PIN_TRACKING_CENTER A2
#define PIN_TRACKING_RIGHT  A3

void setup() {
  pinsSetup();
  getTrackingSensorVal();
}

void loop() {
  u8 trackingSensorVal = getTrackingSensorVal();
  switch (trackingSensorVal) {
    // All sensors detect white surface
      // Move forward at forward speed
    case 0:   //000
      motorRun(TK_FORWARD_SPEED, TK_FORWARD_SPEED);
      break;
      // All sensors detect black surface
      // Stop the car
    case 7:   //111
      motorRun(TK_STOP_SPEED, TK_STOP_SPEED);
      break;
      // Left sensor detects black surface
      // Turn left at LV1 turn speed
    case 1:   //001
      motorRun(TK_TURN_SPEED_LV4, TK_TURN_SPEED_LV1);
      break;
      // Center and left sensors detect black surface
      // Turn left at LV2 turn speed
    case 3:   //011
      motorRun(TK_TURN_SPEED_LV3, TK_TURN_SPEED_LV2);
      break;

    case 2:   //010 Center sensor detects black surface
    case 5:   //101 Center and right sensors detect black surface
      // Move forward at forward speed
      motorRun(TK_FORWARD_SPEED, TK_FORWARD_SPEED);
      break;
      // Right and center sensors detect black surface
      // Turn right at LV3 turn speed
    case 6:   //110
      motorRun(TK_TURN_SPEED_LV2, TK_TURN_SPEED_LV3);
      break;
       // Right sensor detects black surface
      // Turn right at LV4 turn speed
    case 4:   //100
      motorRun(TK_TURN_SPEED_LV1, TK_TURN_SPEED_LV4);
      break;
    default:
      break;
  }
}

void pinsSetup() {
  pinMode(PIN_DIRECTION_LEFT, OUTPUT);
  pinMode(PIN_MOTOR_PWM_LEFT, OUTPUT);
  pinMode(PIN_DIRECTION_RIGHT, OUTPUT);
  pinMode(PIN_MOTOR_PWM_RIGHT, OUTPUT);
  pinMode(PIN_TRACKING_LEFT, INPUT);
  pinMode(PIN_TRACKING_RIGHT, INPUT);
  pinMode(PIN_TRACKING_CENTER, INPUT);
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

//when black line on one side is detected, the value of the side will be 0, or the value is 1
u8 getTrackingSensorVal() {
  u8 trackingSensorVal = 0;
  trackingSensorVal = (digitalRead(PIN_TRACKING_LEFT) == 1 ? 1 : 0) << 2 | (digitalRead(PIN_TRACKING_CENTER) == 1 ? 1 : 0) << 1 | (digitalRead(PIN_TRACKING_RIGHT) == 1 ? 1 : 0) << 0;
  return trackingSensorVal;
}


