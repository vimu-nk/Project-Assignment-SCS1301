#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "types.h"

int main()
{
    struct players player[MAX_PLAYERS] =  //0 - Yellow, 1 - Blue, 2 - Red, 3 - Green
    {
    {"Yellow", 'Y', 0, {{1, -1, 0}, {2, -1, 0}, {3, -1, 0}, {4, -1, 0}}, 4, 0, {-1, -1, -1, -1}, {-1, -1, -1, -1}},
    {"Blue", 'B', 0, {{1, -1, 0}, {2, -1, 0}, {3, -1, 0}, {4, -1, 0}}, 4, 0, {-1, -1, -1, -1}, {-1, -1, -1, -1}},
    {"Red", 'R', 0, {{1, -1, 0}, {2, -1, 0}, {3, -1, 0}, {4, -1, 0}}, 4, 0, {-1, -1, -1, -1}, {-1, -1, -1, -1}},
    {"Green", 'G', 0, {{1, -1, 0}, {2, -1, 0}, {3, -1, 0}, {4, -1, 0}}, 4, 0, {-1, -1, -1, -1}, {-1, -1, -1, -1}}
    };

    short playOrder[MAX_PLAYERS];

    srand(time(NULL));

    for(short i = 0; i < MAX_PLAYERS; i++)
    {
        short j = 0;
        printf("The %s player has four (04) pieces named %c%d, %c%d, %c%d, and %c%d.\n",
        player[i].colour, player[i].letter,
        player[i].pieces[j].index,
        player[i].letter,
        player[i].pieces[j + 1].index,
        player[i].letter,
        player[i].pieces[j + 2].index,
        player[i].letter,
        player[i].pieces[j + 3].index);

        if(i == 3){printf("\n");}
    }

    callingOrder(playOrder, player);

    for(short i = 0; i < MAX_PLAYERS; i++)
    {
        printf("%s rolls %d\n", player[i].colour, player[i].diceVal);
        if(i == 3){printf("\n");}
    }

    printf("%s has the highest roll and will begin the game.\n", player[playOrder[0]].colour);
    printf("The order of a single round is %s, %s, %s, and %s.\n\n",
    player[playOrder[0]].colour,
    player[playOrder[1]].colour,
    player[playOrder[2]].colour,
    player[playOrder[3]].colour);

    while(!standardNotEmpty(player))
    {
        for(short i = 0; i < MAX_PLAYERS; i++)
        {
            short temp = playOrder[i];

            switch(temp)
            {
                case 0:
                    player[0].diceVal = diceRoll();
                    printf("%s rolls %d\n", player[0].colour, player[0].diceVal);
                    if(player[0].diceVal == 6)
                    {
                        setCellX(0, player);
                        printCellX(0, player);
                    }
                    break;

                case 1:
                    player[1].diceVal = diceRoll();
                    printf("%s rolls %d\n", player[1].colour, player[1].diceVal);
                    if(player[1].diceVal == 6)
                    {
                        setCellX(1, player);
                        printCellX(1, player);
                    }
                    break;

                case 2:
                    player[2].diceVal = diceRoll();
                    printf("%s rolls %d\n", player[2].colour, player[2].diceVal);
                    if(player[2].diceVal == 6)
                    {
                        setCellX(2, player);
                        printCellX(2, player);
                    }
                    break;

                case 3:
                    player[3].diceVal = diceRoll();
                    printf("%s rolls %d\n", player[3].colour, player[3].diceVal);
                    if(player[3].diceVal == 6)
                    {
                        setCellX(3, player);
                        printCellX(3, player);
                    }
                    break;
            }

            if(i == 3){printf("\n");}
        }
    }
    
    int count = 1;

    for(int x = 0; x < 100; x++)
    {
        printf("Round : %d\n\n", count);

        for(int i = 0; i < MAX_PLAYERS; i++)
        {
            short x = playOrder[i];
            pieceMove(x, player);
        }

        printStatus(player);

        count++;

        getchar();
    }

    return 0;
}