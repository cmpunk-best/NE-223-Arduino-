#ifndef MotorReset_h
#define MotorReset_h

#include <Arduino.h>
#include "MotorClass.h"
bool reachInitialState(uint8_t,Motor*);
/*

1.Reset Module
2.Target Module
3.Motor Class Module

if reset button pressed or catch==1 or arduino started:
    while the push button not pressed:
        keeps moving left(backward)
    Set targetpos =15 and ready=0

    while the currentpos!=targetpos:
        keep movingMotor()
    set currentpos=targetpos in the middle and ready=1 and catch=0
    stopmoving
    turnonLED //to give a signal that robot is ready to receive the ball

if readyPin is High.
    Set the interrupt for receiving the signal from Arduino2.
    Set the interrupt for reading the encoder values and updating the currentPos.
    if(interrupt==1 && ready==1):
        readSerialPort from Arduino2 and update the targetPos
    until the targetPos==currentPos:
        moveMotor
    if currentPos is equal to targetPos or catch =1 or eventTimedOut
        set catch value to 1 
        set readyPin to LOW






*/


#endif