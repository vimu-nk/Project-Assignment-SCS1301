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
    short firstHigh = -1;

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



    // for(short x = 6; x > 0; x--)
    // {
    //     for(short y = 0; y < 4; y++)
    //     {
    //         if(x == rollVals[y])
    //         {
    //             firstHigh = y;
    //             break;
    //         }
    //     }

    //     if(firstHigh != -1)
    //     {
    //         break;
    //     }
    // }

    // for(short i = 0; i < 4; i++)
    // {
    //     if(firstHigh == 3)
    //     {
    //         order[i] = firstHigh;
    //         firstHigh = 0;
    //     }
    //     else
    //     {
    //         order[i] = firstHigh;
    //         firstHigh++;
    //     }
    // }
}