
#include "FindLine.h"

int findXLine(byte xLineT1, byte xLineT2, byte xLineB1, byte xLineB2)
{
    int xLine = 0;

    switch (xLineT1)
    {
    case 0x80:
        xLine = 1;
        break;
    case 0x40:
        xLine = 2;
        break;
    case 0x20:
        xLine = 3;
        break;
    case 0x10:
        xLine = 4;
        break;
    case 0x08:
        xLine = 5;
        break;
    case 0x04:
        xLine = 6;
        break;
    case 0x02:
        xLine = 7;
        break;
    case 0x01:
        xLine = 8;
        break;                            
    
    default:
        break;
    }

    switch (xLineT2)
    {
    case 0x80:
        xLine = 9;
        break;
    case 0x40:
        xLine = 10;
        break;
    case 0x20:
        xLine = 11;
        break;
    case 0x10:
        xLine = 12;
        break;
    case 0x08:
        xLine = 13;
        break;
    case 0x04:
        xLine = 14;
        break;
    case 0x02:
        xLine = 15;
        break;
    case 0x01:
        xLine = 16;
        break;        
    
    default:
        break;
    }

    switch (xLineB1)
    {
    case 0x80:
        xLine = 17;
        break;
    case 0x40:
        xLine = 18;
        break;
    case 0x20:
        xLine = 19;
        break;
    case 0x10:
        xLine = 20;
        break;
    case 0x08:
        xLine = 21;
        break;
    case 0x04:
        xLine = 22;
        break;
    case 0x02:
        xLine = 23;
        break;
    case 0x01:
        xLine = 24;
        break;        
    
    default:
        break;
    }

    switch (xLineB2)
    {
    case 0x80:
        xLine = 25;
        break;
    case 0x40:
        xLine = 26;
        break;
    case 0x20:
        xLine = 27;
        break;
    case 0x10:
        xLine = 28;
        break;
    case 0x08:
        xLine = 29;
        break;
    case 0x04:
        xLine = 30;
        break;
    case 0x02:
        xLine = 31;
        break;
    case 0x01:
        xLine = 32;
        break;        
    
    default:
        break;
    }    

    return xLine;
}

int findYLine(byte yLineT1, byte yLineT2, byte yLineB1, byte yLineB2)
{
    int yLine = 0;

    switch (yLineT1)
    {
    case 0x80:
        yLine = 1;
        break;
    case 0x40:
        yLine = 2;
        break;
    case 0x20:
        yLine = 3;
        break;
    case 0x10:
        yLine = 4;
        break;
    case 0x08:
        yLine = 5;
        break;
    case 0x04:
        yLine = 6;
        break;
    case 0x02:
        yLine = 7;
        break;
    case 0x01:
        yLine = 8;
        break;                            
    
    default:
        break;
    } 

    switch (yLineT2)
    {
    case 0x80:
        yLine = 9;
        break;
    case 0x40:
        yLine = 10;
        break;
    case 0x20:
        yLine = 11;
        break;
    case 0x10:
        yLine = 12;
        break;
    case 0x08:
        yLine = 13;
        break;
    case 0x04:
        yLine = 14;
        break;
    case 0x02:
        yLine = 15;
        break;
    case 0x01:
        yLine = 16;
        break;        
    
    default:
        break;
    }

    switch (yLineB1)
    {
    case 0x80:
        yLine = 17;
        break;
    case 0x40:
        yLine = 18;
        break;
    case 0x20:
        yLine = 19;
        break;
    case 0x10:
        yLine = 20;
        break;
    case 0x08:
        yLine = 21;
        break;
    case 0x04:
        yLine = 22;
        break;
    case 0x02:
        yLine = 23;
        break;
    case 0x01:
        yLine = 24;
        break;        
    
    default:
        break;
    }

    switch (yLineB2)
    {
    case 0x80:
        yLine = 25;
        break;
    case 0x40:
        yLine = 26;
        break;
    case 0x20:
        yLine = 27;
        break;
    case 0x10:
        yLine = 28;
        break;
    case 0x08:
        yLine = 29;
        break;
    case 0x04:
        yLine = 30;
        break;
    case 0x02:
        yLine = 31;
        break;
    case 0x01:
        yLine = 32;
        break;        
    
    default:
        break;
    }   
    return yLine;
}

byte isLinePresent(byte xLineT1, byte xLineT2, byte xLineB1, byte xLineB2, byte yLineT1, byte yLineT2, byte yLineB1, byte yLineB2)
{
    return (xLineT1 | xLineT2 | xLineB1 | xLineB2 | yLineT1 | yLineT2 | yLineB1 | yLineB2);
}