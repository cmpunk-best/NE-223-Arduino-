#include "mainMotor.h"
void setup()
 {
  Serial.begin(9600);
  pinMode(resetPin,INPUT_PULLUP);
  pinMode(pushButtonPin,INPUT_PULLUP);
  pinMode(hbridgeBackwardPin,OUTPUT);
  pinMode(hbridgeForwardPin,OUTPUT);
  pinMode(catchSensorPin,INPUT);
  pinMode(interruptPin,INPUT);
  pinMode(encoderPin,INPUT_PULLUP);
  pinMode(LEDPin,OUTPUT);
  pinMode(readyPin,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin),InterruptforTarget,RISING);
  attachInterrupt(digitalPinToInterrupt(encoderPin),encoderforMotor,CHANGE);
  digitalWrite(enablePin,HIGH);
}

void loop() {
  int resetValue=digitalRead(resetPin); 
  bool catchValue=rabbitMotor.getcatchValue();
  //part1 for reseting the motor to position middle at starting or after catching the ball
  if((resetValue==LOW) || (catchValue==1) || (flagstart==0))
  {
    flagstart=1;
    digitalWrite(readyPin,LOW);
    byte pushbuttonReached=reachInitialState(pushButtonPin,&rabbitMotor);
    if(pushbuttonReached==1)
    {
      int inittargetPos=15*30;
      currentPos=rabbitMotor.ticksbyEncoder>>2;
      bool targetReached=moveToTarget(currentPos,inittargetPos,&rabbitMotor);
      ready=targetReached?1:0;
      if(ready)
      {
        rabbitMotor.setcatchValue(0);
        digitalWrite(readyPin,HIGH);
        digitalWrite(LEDPin,HIGH);
        delay(500);
        initialTime=millis();
      }
    }
  }
  
  //part2 for moving the motor to the real target position
  if(digitalRead(readyPin) && (resetValue==HIGH))
  {
    digitalWrite(LEDPin,LOW);
    targetPos=targetMultiple*30;
    bool targetReached=moveToTarget(currentPos,targetPos,&rabbitMotor);
    currentPos=rabbitMotor.ticksbyEncoder>>2;
    if(targetReached)
    {
      realTime=millis();
      if(digitalRead(catchSensorPin) || ((realTime-initialTime)>10000))
      {
        rabbitMotor.setcatchValue(1);
        digitalWrite(readyPin,LOW);
      }
    }
  }
}

void InterruptforTarget ()
{
  Serial.setTimeout(100);
  if (Serial.available())
    targetMultiple=Serial.read();
}

void encoderforMotor()
{
  if(digitalRead(hbridgeBackwardPin)==HIGH)
    rabbitMotor.ticksbyEncoder-=1;
  else
    rabbitMotor.ticksbyEncoder+=1;
}