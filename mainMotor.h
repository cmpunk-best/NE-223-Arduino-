#ifndef mainMotor_h
#define mainMotor_h
#include <Arduino.h>
#include "NE223MotorLibrary/MotorClass.h"
#include "NE223MotorLibrary/MotorReset.h"
#include "NE223MotorLibrary/ReachTarget.h"

const uint8_t encoderPin=2;
const uint8_t interruptPin=3;

const uint8_t enablePin=4;
const uint8_t readyPin=7;
const uint8_t resetPin=8;
const uint8_t pushButtonPin=9;
const uint8_t catchSensorPin=10;
const uint8_t hbridgeForwardPin=11;
const uint8_t hbridgeBackwardPin=12;
const uint8_t LEDPin=13;

Motor rabbitMotor(hbridgeForwardPin,hbridgeBackwardPin);
bool ready=0;
volatile int targetMultiple=0;
int currentPos=0;
int targetPos=0;
uint8_t direction;
bool flagstart=0;
int initialTime=0;
int realTime=0;
#endif