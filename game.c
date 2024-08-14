#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "types.h"

int main()
{
    struct player yellow;
    struct player blue;
    struct player red;
    struct player green;

    short playOrder[4] = {0, 1, 2, 3};

    srand(time(NULL));

    strcpy(yellow.colour, "Yellow");
    strcpy(blue.colour, "Blue");
    strcpy(red.colour, "Red");
    strcpy(green.colour, "Green");

    callingOrder(playOrder, &yellow.diceVal, &blue.diceVal, &red.diceVal, &green.diceVal);

    printf("Yellow 1 : %d\n", yellow.diceVal);
    printf("Blue 1 : %d\n", blue.diceVal);
    printf("Red 1 : %d\n", red.diceVal);
    printf("Green 1 : %d\n\n", green.diceVal);

    for(short a = 0; a < 4; a++)
    {
        printf("%d\n", playOrder[a]);
    }

    return 0;
}