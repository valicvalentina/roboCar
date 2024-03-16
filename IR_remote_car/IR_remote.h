
#ifndef _IR_REMOTE_h
#define _IR_REMOTE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


#define MOTOR_DIRECTION     0 
#define PIN_DIRECTION_LEFT	4
#define PIN_DIRECTION_RIGHT	3
#define PIN_MOTOR_PWM_LEFT	6
#define PIN_MOTOR_PWM_RIGHT	5
#define MOTOR_PWM_DEAD		5
#define PIN_IRREMOTE_RECV	9
#define PIN_BUZZER			A0

extern float batteryVoltage;

void pinsSetup();
void motorRun(int speedl, int speedr);

void setBuzzer(bool flag);

#endif

