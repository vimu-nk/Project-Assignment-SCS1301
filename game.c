#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "types.h"

int main()
{
    struct players player[4] =  //0 - Yellow, 1 - Blue, 2 - Red, 3 - Green
    {
        {"Yellow", 'Y', 0, -1, 0, -1, 0, -1, 0, -1, 0},
        {"Blue", 'B', 0, -1, 0, -1, 0, -1, 0, -1, 0},
        {"Red", 'R', 0, -1, 0, -1, 0, -1, 0, -1, 0},
        {"Green", 'G', 0, -1, 0, -1, 0, -1, 0, -1, 0}
    };

    short playOrder[4];

    srand(time(NULL));

    for(short i = 0; i < 4; i++)
    {
        printf("The %s player has four (04) pieces named %c1, %c2, %c3 and %c4.\n", player[i].colour, player[i].letter, player[i].letter, player[i].letter, player[i].letter);
        if(i == 3){printf("\n");}
    }

    callingOrder(playOrder, &player[0].diceVal, &player[1].diceVal, &player[2].diceVal, &player[3].diceVal);

    for(short i = 0; i < 4; i++)
    {
        printf("%s rolls %d\n", player[i].colour, player[i].diceVal);
        if(i == 3){printf("\n");}
    }

    printf("%s has the highest roll and will begin the game.\n", player[playOrder[0]].colour);
    printf("The order of a single round is %s, %s, %s, and %s.\n", player[playOrder[0]].colour, player[playOrder[1]].colour, player[playOrder[2]].colour, player[playOrder[3]].colour);

    return 0;
}