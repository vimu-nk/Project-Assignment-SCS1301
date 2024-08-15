#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "types.h"

int main()
{
    struct players player[4]; //0 - Yellow, 1 - Blue, 2 - Red, 3 - Green

    short playOrder[4];

    srand(time(NULL));

    strcpy(player[0].colour, "Yellow");
    strcpy(player[1].colour, "Blue");
    strcpy(player[2].colour, "Red");
    strcpy(player[3].colour, "Green");

    player[0].letter = 'Y';
    player[1].letter = 'B';
    player[2].letter = 'R';
    player[3].letter = 'G';

    for(short i = 0; i < 4; i++)
    {
        printf("The %s player has four (04) pieces named %c1, %c2, %c3 and %c4.\n", player[i].colour, player[i].letter, player[i].letter, player[i].letter, player[i].letter);
    }

    printf("\n");

    callingOrder(playOrder, &player[0].diceVal, &player[1].diceVal, &player[2].diceVal, &player[3].diceVal);

    printf("Yellow 1 : %d\n", player[0].diceVal);
    printf("Blue 1 : %d\n", player[1].diceVal);
    printf("Red 1 : %d\n", player[2].diceVal);
    printf("Green 1 : %d\n\n", player[3].diceVal);

    for(short a = 0; a < 4; a++)
    {
        printf("%d\n", playOrder[a]);
    }

    return 0;
}