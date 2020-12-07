#include "MotorClass.h"

Motor:: Motor(uint8_t forwardPin,uint8_t backwardPin)
{
   fbPins[0]=forwardPin;
   fbPins[1]=backwardPin;
}

 Motor::~ Motor()
{
}
void Motor::moveBackward()
{
    digitalWrite(this->fbPins[1],HIGH);
    digitalWrite(this->fbPins[0],LOW);
}
void Motor::moveForward()
{
    digitalWrite(this->fbPins[1],LOW);
    digitalWrite(this->fbPins[0],HIGH);
}
void Motor::stop()
{
    digitalWrite(this->fbPins[1],LOW);
    digitalWrite(this->fbPins[0],LOW);
    
}
void Motor::followTarget(int currentPos,int targetPos)
{
    if((currentPos>(targetPos-10))&&(currentPos<(targetPos+10)))
    {
        stop();
    }
    else if(targetPos>currentPos)
    {
        moveForward();
    }
    else if(targetPos<currentPos)
    {
        moveBackward();
    }
    
}


bool Motor::getcatchValue()
{
    return caught;
}
void Motor::setcatchValue(bool cValue)
{
    caught=cValue;
}



