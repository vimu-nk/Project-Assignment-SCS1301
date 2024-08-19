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

short standardNotEmpty(short *y, short *b, short *r, short *g) //Check if the standard path has at least one piece
{
    return (*y != 4) || (*b != 4) || (*r != 4) || (*g != 4);
}

void setCellX(short index, struct players *player) //Setting a piece to respective cell X
{
    short pieceID = 4 - player -> piecesBase;

    switch(index)
    {
        case 0:
            player -> pieces[pieceID].position = 2;
            break;

        case 1:
            player -> pieces[pieceID].position = 15;
            break;

        case 2:
            player -> pieces[pieceID].position = 28;
            break;

        case 3:
            player -> pieces[pieceID].position = 41;
            break;
    }

    player -> piecesBase -= 1;
}

void printCellX(struct players *player)
{
    printf("%s player moves piece %c%d to the starting point.\n",
    player -> colour,
    player -> letter,
    4 - player -> piecesBase);
    printf("%s player now has %d/4 pieces on the board and %d/4 pieces on the base.\n\n",
    player -> colour,
    4 - player -> piecesBase,
    player -> piecesBase);
}

