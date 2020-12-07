#include "mainMotor.h"
void setup()
 {
  Serial.begin(9600);
  pinMode(resetPin,INPUT_PULLUP);
  pinMode(pushButtonPin,INPUT_PULLUP);
  //pinMode(enablePin,OUTPUT);
  pinMode(hbridgeBackwardPin,OUTPUT);
  pinMode(hbridgeForwardPin,OUTPUT);
  pinMode(interruptPin,INPUT);
  pinMode(encoderPin,INPUT_PULLUP);
  pinMode(LEDPin,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin),InterruptforTarget,RISING);
  attachInterrupt(digitalPinToInterrupt(encoderPin),encoderforMotor,CHANGE);
}

void loop() {
  int resetValue=digitalRead(resetPin); 
  byte catchValue=rabbitMotor.getcatchValue();
  
  //part1 for reseting the motor to position middle at starting or after catching the ball
  if(resetValue==LOW || catchValue==1)
  {
    byte pushbuttonReached=reachInitialState(pushButtonPin,&rabbitMotor);
    if(pushbuttonReached==1){
      float inittargetPos=15*6.25;//TODO
      currentPos=rabbitMotor.ticksbyEncoder*0.49;
      byte targetReached=moveToTarget(currentPos,inittargetPos,&rabbitMotor);
      //targetReached?digitalWrite(enablePin,LOW):digitalWrite(enablePin,HIGH);
      ready=targetReached>0?1:0;
      if(ready)
      {
        digitalWrite(LEDPin,HIGH);
        delay(500);
      }
      
    }
  }

  //part2 for moving the motor to the real target position
  if(ready==1 && (Serial.available()>0))
  {
    digitalWrite(LEDPin,LOW);
    targetPos=targetMultiple*6.25;//TODO
    uint8_t targetReached=moveToTarget(currentPos,targetPos,&rabbitMotor);
    currentPos=rabbitMotor.ticksbyEncoder*.49;
    if(targetReached)
    {
      rabbitMotor.setcatchValue(1);//TODO
    }
  }
}

void InterruptforTarget ()
{
  targetMultiple=Serial.read();
}

void encoderforMotor()
{
  if(digitalRead(hbridgeBackwardPin)==HIGH)
    rabbitMotor.ticksbyEncoder-=1;
  else
    rabbitMotor.ticksbyEncoder+=1;
}