#include "CalculatePosition.h"

int* findNewPosition(int currentXLine, int prevXLine, int currentYLine, int prevYLine, int* prevPosition, int* targetPosition)
{
    

    //case for ball not yet dropped on the plank
    //no interrupt should be generated
    if((currentXLine == 0)&&(prevXLine == 0)&&(currentYLine == 0)&&(prevYLine == 0))
    {
        targetPosition[0] = -1;
        targetPosition[1] = -1;
    }

    //case for ball first crossing an x line
    if((currentXLine != 0)&&(prevXLine == 0)&&(currentYLine == 0)&&(prevYLine == 0))
    {
        if(currentXLine <= 14)
        {
            targetPosition[0] = 2*currentXLine + 1;
            targetPosition[1] = 30;
        }
        else
        {
            targetPosition[0] = 30;
            targetPosition[1] = 29 - 2*(currentXLine - 15);
        }
        
    }

    //case for ball first crossing a y line
    if((currentXLine == 0)&&(prevXLine == 0)&&(currentYLine != 0)&&(prevYLine == 0))
    {
        if(currentYLine <= 14)
        {
            targetPosition[0] = 29 - 2*currentYLine;
            targetPosition[1] = 30;
        }
        else
        {
            targetPosition[0] = 0;
            targetPosition[1] = 29 - 2*(currentYLine - 15);
        }
        
    }

    //case for ball first crossing an intersection
    if((currentXLine != 0)&&(currentYLine != 0))
    {
        //formula for point of intersecton : x = c2-c1 and y = c2 + c1
        targetPosition[0] = (30 - currentYLine + currentXLine - 15);
        targetPosition[1] = (30 - currentYLine - currentXLine + 15);
    }

    // case for ball crossing y line after it has crossed x line previously

    if((currentXLine == 0)&&(prevXLine != 0)&&(currentYLine != 0))
    {
        targetPosition[0] = (30 - currentYLine + prevXLine - 15);
        targetPosition[1] = (30 - currentYLine - prevXLine + 15);
    }

    //case for ball crossing x line after it has crossed y line previously
    if((currentXLine != 0)&&(currentYLine == 0)&&(prevYLine != 0))
    {
        targetPosition[0] = (30 - prevYLine + currentXLine - 15);
        targetPosition[1] = (30 - prevYLine - currentXLine + 15);        
    }

    //case for ball crossing two consecutive x lines
    if((currentXLine != 0)&&(prevXLine != 0)&&(currentYLine == 0)&&(prevYLine == 0))
    {
        targetPosition[0] = prevPosition[0]++;
        targetPosition[1] = prevPosition[1]--;
    }

    //case for ball crossing two consecutive y lines
    if((currentXLine == 0)&&(prevXLine == 0)&&(currentYLine != 0)&&(prevYLine != 0))
    {
        targetPosition[0] = prevPosition[0]--;
        targetPosition[1] = prevPosition[1]--;
    }

    return targetPosition;

}