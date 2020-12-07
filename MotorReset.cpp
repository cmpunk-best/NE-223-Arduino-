#include "MotorReset.h"

bool reachInitialState(uint8_t pushButtonPin,Motor* rabbitMotor)
{
    int pushButtonReached=digitalRead(pushButtonPin);
    if (pushButtonReached!=LOW)
    {
        //Move motor left
        rabbitMotor->moveBackward();
    }
    else
    {
        rabbitMotor->stop();
        rabbitMotor->ticksbyEncoder=0;
    }
    
    bool pushButtonTouched=(pushButtonReached==LOW)?1:0;
    return pushButtonTouched; 
}