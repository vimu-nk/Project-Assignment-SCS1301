#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"

short diceRoll()
{
    return (rand() % 6) + 1;
}

short coinToss()
{
    return rand() % 2;
}

void callingOrder(short order[], short *y, short *b, short *r, short *g)
{
    short rollVals[4];
    short rollIDs[4] = {0, 1, 2, 3};

    *y = diceRoll();
    rollVals[0] = *y;

    *b = diceRoll();
    rollVals[1] = *b;

    *r = diceRoll();
    rollVals[2] = *r;
    
    *g = diceRoll();
    rollVals[3] = *g;

    for(short i = 0; i < 3; i++)
    {
        for(short j = 0; j < 3 - i; j++)
        {
            if(rollVals[j] < rollVals[j + 1])
            {
                short temp = rollVals[j + 1];
                short tempI = rollIDs[j + 1];
                rollVals[j + 1] = rollVals[j];
                rollIDs[j + 1] = rollIDs[j];
                rollVals[j] = temp;
                rollIDs[j] = tempI;
            }
        }
    }

    short firstPlayer = rollIDs[0];
    short temp = firstPlayer;

    for(short x = 0; x < 4; x++)
    {
        if(temp == 3)
        {
            order[x] = temp;
            temp = 0;
        }
        else
        {
            order[x] = temp;
            temp++;
        }
    }
}



