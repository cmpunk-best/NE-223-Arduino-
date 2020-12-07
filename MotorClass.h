#ifndef MotorClass_h
#define MotorClass_h

#include <Arduino.h>
class  Motor
{
private:
    bool caught=0;
    uint8_t fbPins[2];
   
public:
    Motor(uint8_t,uint8_t);
    ~ Motor();
    volatile unsigned long ticksbyEncoder;
    void moveForward();
    void moveBackward();
    void stop();
    void followTarget(int,int);
    uint8_t getcurrentPos();
    bool getcatchValue();
    void setcatchValue(bool);
};
#endif