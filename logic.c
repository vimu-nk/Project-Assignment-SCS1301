#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"

void gameLoop()
{
    struct players player[MAX_PLAYERS] =  //0 - Yellow, 1 - Blue, 2 - Red, 3 - Green
    {
        {"Yellow", 'Y', 0, {{1, -1, 0, -1}, {2, -1, 0, -1}, {3, -1, 0, -1}, {4, -1, 0, -1}}, 4, 0, {-1, -1, -1, -1}, {-1, -1, -1, -1}, 0},
        {"Blue", 'B', 0, {{1, -1, 0, -1}, {2, -1, 0, -1}, {3, -1, 0, -1}, {4, -1, 0, -1}}, 4, 0, {-1, -1, -1, -1}, {-1, -1, -1, -1}, 0},
        {"Red", 'R', 0, {{1, -1, 0, -1}, {2, -1, 0, -1}, {3, -1, 0, -1}, {4, -1, 0, -1}}, 4, 0, {-1, -1, -1, -1}, {-1, -1, -1, -1}, 0},
        {"Green", 'G', 0, {{1, -1, 0, -1}, {2, -1, 0, -1}, {3, -1, 0, -1}, {4, -1, 0, -1}}, 4, 0, {-1, -1, -1, -1}, {-1, -1, -1, -1}, 0}
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

    for(int x = 0; x < 1000; x++)
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
}

short diceRoll()
{
    return (rand() % 6) + 1;
}

short coinToss()
{
    return rand() % 2;
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

short searchPieceX(short index, struct players *player)
{
    for(short i = 0; i < MAX_PIECES_PER_PLAYER; i++)
    {
        if(player[index].pieces[i].position == -1)
        {
            return i;
        }
    }
}

void setCellX(short index, struct players *player) //Setting a piece to respective cell X
{
    short pieceID = searchPieceX(index, player);

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

    player[index].piecesStdIndexes[MAX_PIECES_PER_PLAYER - player[index].piecesBase] = pieceID;
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
    printf("\n\033[0;33m%s\033[0m\t\t\t\033[0;34m%s\t\t\t\033[0m\033[0;31m%s\t\t\t\033[0;32m%s\033[0m\n",
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

short yellowBehaviour(short index, struct players *player)
{
    short ID = -1;

    if(player[index].piecesBase > 0 && player[index].diceVal == 6)
    {
        setCellX(index, player);
        printCellX(index, player);
    }
    else if(player[index].piecesHome != 4)
    {
        while(1)
        {
            short x = rand() % 4;
            if(player[index].piecesStdIndexes[x] != -1 && (player[index].pieces[player[index].piecesStdIndexes[x]].position != 106 || ((player[index].pieces[x].position + player[index].diceVal) <= 106)))
            {
                short y = player[index].piecesStdIndexes[x];
                if(player[index].pieces[y].position > 100)
                {
                    if((player[index].pieces[y].position + player[index].diceVal) <= 106)
                    {
                        ID = y;
                        break;
                    }
                    else
                    {
                        return ID;
                    }
                }
                else
                {
                    ID = y;
                    break;
                }
            }
        }
    }

    return ID;
}

short blueBehaviour(short index, struct players *player)
{
    short ID = -1;

    if(player[index].piecesBase > 0 && player[index].diceVal == 6 && coinToss == 0)
    {
        setCellX(index, player);
        printCellX(index, player);
    }
    else if(player[index].piecesHome != 4)
    {
        while(1)
        {
            short x = player[index].prevPieceID % 4;
            if(player[index].piecesStdIndexes[x] != -1 && (player[index].pieces[player[index].piecesStdIndexes[x]].position != 106 || ((player[index].pieces[x].position + player[index].diceVal) <= 106)))
            {
                short y = player[index].piecesStdIndexes[x];
                if(player[index].pieces[y].position > 100)
                {
                    if((player[index].pieces[y].position + player[index].diceVal) <= 106)
                    {
                        ID = y;
                        break;
                    }
                    else
                    {
                        return ID;
                    }
                }
                else
                {
                    ID = y;
                    break;
                }
            }

            player[index].prevPieceID++;
        }
    }

    return ID;
}

void pieceMove(short index, struct players *player)
{
    short pieceID = -1;

    player[index].diceVal = diceRoll();
    printf("%s rolls %d\n", player[index].colour, player[index].diceVal);

    switch(index)
    {
        case 0:
            if(player[index].piecesBase != 4 || player[index].diceVal == 6)
            {
                pieceID = yellowBehaviour(index, player);
            }

            player[index].pieces[pieceID].preValue = player[index].pieces[pieceID].position;

            printf("\nYellow Piece ID : %d\n", pieceID); //Remove this after debugging

            if(pieceID >= 0 && pieceID <= 3)
            {
                if(player[index].pieces[pieceID].preValue >= 0 && player[index].pieces[pieceID].preValue <= 51)
                {
                    if(player[index].pieces[pieceID].preValue == 0)
                    {
                        player[index].pieces[pieceID].position = 100 + player[index].diceVal;
                        if(player[index].pieces[pieceID].position == 106)
                        {
                            player[index].piecesHomeIndexes[player[index].piecesHome] = pieceID;
                            player[index].piecesHome++;
                            player[index].piecesStdIndexes[pieceID] = -2;
                            printf("\n" YELLOW "%s piece %c%d entered home." RESET "\n",
                            player[index].colour,
                            player[index].letter,
                            pieceID + 1);
                        }
                    }
                    else if(player[index].pieces[pieceID].preValue < 52 && ((player[index].pieces[pieceID].preValue + player[index].diceVal) > 52))
                    {
                        player[index].pieces[pieceID].position = 100 + (player[index].diceVal - (52 - player[index].pieces[pieceID].preValue));
                    }
                    else
                    {
                        player[index].pieces[pieceID].position = (player[index].pieces[pieceID].preValue + player[index].diceVal) % 52;
                    }
                }
                else
                {
                    player[index].pieces[pieceID].position += player[index].diceVal;
                    if(player[index].pieces[pieceID].position == 106)
                    {
                        player[index].piecesHomeIndexes[player[index].piecesHome] = pieceID;
                        player[index].piecesHome++;
                        player[index].piecesStdIndexes[pieceID] = -2;
                        printf("\n" YELLOW "%s piece %c%d entered home." RESET "\n",
                        player[index].colour,
                        player[index].letter,
                        pieceID + 1);
                    }
                }

                printPieceMove(index, pieceID, player[index].pieces[pieceID].preValue, player);

                break;
            }
            else
            {
                break;
            }

        case 1:
            if(player[index].piecesBase != 4 || player[index].diceVal == 6)
            {
                pieceID = blueBehaviour(index, player);
            }

            player[index].pieces[pieceID].preValue = player[index].pieces[pieceID].position;

            printf("\nBlue Piece ID : %d\n", pieceID); //Remove this after debugging

            if(pieceID >= 0 && pieceID <= 3)
            {
                if(player[index].pieces[pieceID].preValue >= 0 && player[index].pieces[pieceID].preValue <= 51)
                {
                    if(player[index].pieces[pieceID].preValue == 13)
                    {
                        player[index].pieces[pieceID].position = 100 + player[index].diceVal;
                        if(player[index].pieces[pieceID].position == 106)
                        {
                            player[index].piecesHomeIndexes[player[index].piecesHome] = pieceID;
                            player[index].piecesHome++;
                            printf("\n" YELLOW "%s piece %c%d entered home." RESET "\n",
                            player[index].colour,
                            player[index].letter,
                            pieceID + 1);
                        }
                    }
                    else if(player[index].pieces[pieceID].preValue < 13 && ((player[index].pieces[pieceID].preValue + player[index].diceVal) > 13))
                    {
                        player[index].pieces[pieceID].position = 100 + (player[index].diceVal - (13 - player[index].pieces[pieceID].preValue));
                    }
                    else
                    {
                        player[index].pieces[pieceID].position = (player[index].pieces[pieceID].preValue + player[index].diceVal) % 52;
                    }
                }
                else
                {
                    player[index].pieces[pieceID].position += player[index].diceVal;
                    if(player[index].pieces[pieceID].position == 106)
                    {
                        player[index].piecesHomeIndexes[player[index].piecesHome] = pieceID;
                        player[index].piecesHome++;
                        printf("\n" BLUE "%s piece %c%d entered home." RESET "\n",
                        player[index].colour,
                        player[index].letter,
                        pieceID + 1);
                    }
                }

                printPieceMove(index, pieceID, player[index].pieces[pieceID].preValue, player);

                break;
            }
            else
            {
                break;
            }

        /*case 2:
            if(previous >= 0 && previous <= 51)
            {
                if(previous == 26)
                {
                    player[index].pieces[pieceID].position = 100 + player[index].diceVal;
                    if(player[index].pieces[pieceID].position == 106)
                    {
                        player[index].piecesHomeIndexes[player[index].piecesHome] = pieceID;
                        player[index].piecesHome++;
                        printf("\n" YELLOW "%s piece %c%d entered home." RESET "\n",
                        player[index].colour,
                        player[index].letter,
                        pieceID + 1);
                    }
                }
                else if(previous < 26 && ((previous + player[index].diceVal) > 26))
                {
                    player[index].pieces[pieceID].position = 100 + (player[index].diceVal - (26 - previous));
                }
                else
                {
                    player[index].pieces[pieceID].position = (previous + player[index].diceVal) % 52;
                }
            }
            else
            {
                player[index].pieces[pieceID].position += player[index].diceVal;
                if(player[index].pieces[pieceID].position == 106)
                {
                    player[index].piecesHomeIndexes[player[index].piecesHome] = pieceID;
                    player[index].piecesHome++;
                    printf("\n" RED "%s piece %c%d entered home." RESET "\n",
                    player[index].colour,
                    player[index].letter,
                    pieceID + 1);
                }
            }

            printPieceMove(index, pieceID, previous, player);

            break;

        case 3:
            if(previous >= 0 && previous <= 51)
            {
                if(previous == 39)
                {
                    player[index].pieces[pieceID].position = 100 + player[index].diceVal;
                    if(player[index].pieces[pieceID].position == 106)
                    {
                        player[index].piecesHomeIndexes[player[index].piecesHome] = pieceID;
                        player[index].piecesHome++;
                        printf("\n" YELLOW "%s piece %c%d entered home." RESET "\n",
                        player[index].colour,
                        player[index].letter,
                        pieceID + 1);
                    }
                }
                else if(previous < 39 && ((previous + player[index].diceVal) > 39))
                {
                    player[index].pieces[pieceID].position = 100 + (player[index].diceVal - (39 - previous));
                }
                else
                {
                    player[index].pieces[pieceID].position = (previous + player[index].diceVal) % 52;
                }
            }
            else
            {
                player[index].pieces[pieceID].position += player[index].diceVal;
                if(player[index].pieces[pieceID].position == 106)
                {
                    player[index].piecesHomeIndexes[player[index].piecesHome] = pieceID;
                    player[index].piecesHome++;
                    printf("\n" BLUE "%s piece %c%d entered home." RESET "\n",
                    player[index].colour,
                    player[index].letter,
                    pieceID + 1);
                }
            }

            printPieceMove(index, pieceID, previous, player);

            break;*/
    }
}


