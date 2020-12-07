#include "ShiftIn.h"

byte get_sensor_data(int myDataPin, int myClockPin)
{
    int bitCounter;
    int temp = 0;
    byte myDataIn = 0;

    pinMode(myClockPin, OUTPUT);
    pinMode(myDataPin, INPUT);

    for(bitCounter = 7; bitCounter >= 0; bitCounter-- )
    {
        digitalWrite(myClockPin, 0);
        delayMicroseconds(1);
        
        temp = digitalRead(myDataPin);

        if(temp)
        {
            myDataIn = myDataIn | (1 << bitCounter);
        }

        digitalWrite(myClockPin, 1);   
    }

    return myDataIn;
}
