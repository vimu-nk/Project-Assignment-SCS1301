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

short choosePiece(short x)
{
    return (rand() % x);
}

void callingOrder(short order[], struct players *player)
{
    short rollVals[MAX_PLAYERS];
    short rollIDs[MAX_PLAYERS] = {0, 1, 2, 3};

    player[0].diceVal = diceRoll();
    rollVals[0] = player[0].diceVal;

    player[1].diceVal = diceRoll();
    rollVals[1] = player[1].diceVal;

    player[2].diceVal = diceRoll();
    rollVals[2] = player[2].diceVal;
    
    player[3].diceVal = diceRoll();
    rollVals[3] = player[3].diceVal;

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

short standardNotEmpty(struct players *player) //Check if the standard path has at least one piece
{
    return (player[0].piecesBase != MAX_PIECES_PER_PLAYER) || (player[1].piecesBase != MAX_PIECES_PER_PLAYER) || (player[2].piecesBase != MAX_PIECES_PER_PLAYER) || (player[3].piecesBase != MAX_PIECES_PER_PLAYER);
}

void setCellX(short index, struct players *player) //Setting a piece to respective cell X
{
    short pieceID = MAX_PIECES_PER_PLAYER - player[index].piecesBase;

    switch(index)
    {
        case 0:
            player[index].pieces[pieceID].position = 2;
            break;

        case 1:
            player[index].pieces[pieceID].position = 15;
            break;

        case 2:
            player[index].pieces[pieceID].position = 28;
            break;

        case 3:
            player[index].pieces[pieceID].position = 41;
            break;
    }

    player[index].piecesBase--;
}

void printCellX(short index, struct players *player) //Printng the ststus when a piece go to the X
{
    printf("%s player moves piece %c%d to the starting point.\n",
    player[index].colour,
    player[index].letter,
    MAX_PIECES_PER_PLAYER - player[index].piecesBase);
    printf("%s player now has %d/4 pieces on the board and %d/4 pieces on the base.\n",
    player[index].colour,
    MAX_PIECES_PER_PLAYER - player[index].piecesBase,
    player[index].piecesBase);
}

void printStatus(struct players *player)
{
    printf("\033[0;33m%s\033[0m\t\t\t\033[0;34m%s\t\t\t\033[0m\033[0;31m%s\t\t\t\033[0;32m%s\033[0m\n",
    player[0].colour,
    player[1].colour,
    player[2].colour,
    player[3].colour);

    printf("\033[0;33mPiece 1 : %d\033[0m\t\t\033[0;34mPiece 1 : %d\033[0m\t\t\033[0m\033[0;31mPiece 1 : %d\t\t\033[0;32mPiece 1 : %d\033[0m\n",
    player[0].pieces[0].position,
    player[1].pieces[0].position,
    player[2].pieces[0].position,
    player[3].pieces[0].position);

    printf("\033[0;33mPiece 1 : %d\033[0m\t\t\033[0;34mPiece 1 : %d\033[0m\t\t\033[0m\033[0;31mPiece 1 : %d\t\t\033[0;32mPiece 1 : %d\033[0m\n",
    player[0].pieces[1].position,
    player[1].pieces[1].position,
    player[2].pieces[1].position,
    player[3].pieces[1].position);

    printf("\033[0;33mPiece 1 : %d\033[0m\t\t\033[0;34mPiece 1 : %d\033[0m\t\t\033[0m\033[0;31mPiece 1 : %d\t\t\033[0;32mPiece 1 : %d\033[0m\n",
    player[0].pieces[2].position,
    player[1].pieces[2].position,
    player[2].pieces[2].position,
    player[3].pieces[2].position);

    printf("\033[0;33mPiece 1 : %d\033[0m\t\t\033[0;34mPiece 1 : %d\033[0m\t\t\033[0m\033[0;31mPiece 1 : %d\t\t\033[0;32mPiece 1 : %d\033[0m\n",
    player[0].pieces[3].position,
    player[1].pieces[3].position,
    player[2].pieces[3].position,
    player[3].pieces[3].position);

    printf("\033[0;33mBase : %d\033[0m\t\t\033[0;34mBase : %d\033[0m\t\t\033[0;31mBase : %d\033[0m\t\t\033[0;32mBase : %d\033[0m\n",
    player[0].piecesBase,
    player[1].piecesBase,
    player[2].piecesBase,
    player[3].piecesBase);
}

void printPieceMove(short index, short pieceID, short previous, struct players *player)
{
    printf("%s moves %c%d from location L%d to L%d by %d units in %s.\n",
    player[index].colour,
    player[index].letter,
    pieceID + 1,
    previous,
    player[index].pieces[pieceID].position,
    player[index].diceVal,
    player[index].pieces[pieceID].pieceDir == 0 ? "clockwise" : "counter-clockwise");
}

void pieceMove(short index, struct players *player)
{
    short pieceID;

    player[index].diceVal = diceRoll();
    printf("%s rolls %d\n", player[index].colour, player[index].diceVal);
    
    if(player[index].piecesBase != 4 || player[index].piecesHome != 4)
    {
        do
        {
            pieceID = choosePiece(MAX_PIECES_PER_PLAYER - player[index].piecesBase); //Randomly choosing a piece to move
        } while (106 - player[index].pieces[pieceID].position <= player[index].diceVal); //Checking if the piece of the given ID is on the home path and can be movable with the respective player's dice value and if it is not, the process will looping until a movable piece is found.
    }
    
    short previous = player[index].pieces[pieceID].position; //Storing previous cell value of the respective piece

    if((player[index].diceVal == 6 && coinToss() == 0) || (player[index].diceVal == 6 && player[index].piecesBase == 4))
    {
        setCellX(index, player);
        printCellX(index, player);
    }
    else if(player[index].piecesBase != 4)
    {
        switch(index)
        {
            case 0:
                if(previous == 0)
                {
                    player[index].pieces[pieceID].position = 100 + player[index].diceVal;
                }
                else if(51 - previous < player[index].diceVal)
                {
                    player[index].pieces[pieceID].position = 100 + player[index].diceVal - (51 - previous);
                }
                else
                {
                    player[index].pieces[pieceID].position = (previous + player[index].diceVal) % 51;
                }

                printPieceMove(0, pieceID, previous, player);

                break;
            
            case 1:
                if(previous == 13)
                {
                    player[index].pieces[pieceID].position = 100 + player[index].diceVal;
                }
                else if(51 - previous < player[index].diceVal)
                {
                    player[index].pieces[pieceID].position = player[index].diceVal - (51 - previous);
                }
                else
                {
                    player[index].pieces[pieceID].position = (previous + player[index].diceVal) % 51;
                }
                
                printPieceMove(1, pieceID, previous, player);

                break;

            case 2:
                if(previous == 26)
                {
                    player[index].pieces[pieceID].position = 100 + player[index].diceVal;
                }
                else if(51 - previous < player[index].diceVal)
                {
                    player[index].pieces[pieceID].position = player[index].diceVal - (51 - previous);
                }
                else
                {
                    player[index].pieces[pieceID].position = (previous + player[index].diceVal) % 51;
                }

                printPieceMove(2, pieceID, previous, player);

                break;
            
            case 3:
                if(previous == 39)
                {
                    player[index].pieces[pieceID].position = 100 + player[index].diceVal;
                }
                else if(51 - previous < player[index].diceVal)
                {
                    player[index].pieces[pieceID].position = player[index].diceVal - (51 - previous);
                }
                else
                {
                    player[index].pieces[pieceID].position = (previous + player[index].diceVal) % 51;
                }

                printPieceMove(3, pieceID, previous, player);

                break;
        }
    }
}


