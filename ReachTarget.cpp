#include "ReachTarget.h"

bool moveToTarget(int currentPos,float targetPos,Motor* rabbitMotor)
{
    bool reached=0;
    rabbitMotor->followTarget(currentPos,targetPos);
    if(currentPos==targetPos)
    {
        reached=1;
    }
    return reached;
}