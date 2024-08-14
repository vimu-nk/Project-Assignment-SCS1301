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

    *y = diceRoll();
    rollVals[0] = *y;
    printf("%d\n", *y);

    *b = diceRoll();
    rollVals[1] = *b;
    printf("%d\n", *b);

    *r = diceRoll();
    rollVals[2] = *r;
    printf("%d\n", *r);
    
    *g = diceRoll();
    rollVals[3] = *g;
    printf("%d\n\n", *g);

    for(short i = 0; i < 3; i++)
    {
        for(short j = 0; j < 3 - i; j++)
        {
            if(rollVals[j] < rollVals[j + 1])
            {
                short temp = rollVals[j + 1];
                short tempI = order[j + 1];
                rollVals[j + 1] = rollVals[j];
                order[j + 1] = order[j];
                rollVals[j] = temp;
                order[j] = tempI;
            }
        }
    }
}