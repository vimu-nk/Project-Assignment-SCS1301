#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "types.h"

int main()
{
    struct players player[4] =  //0 - Yellow, 1 - Blue, 2 - Red, 3 - Green
    {
        {"Yellow", 'Y', 0, {{1, -1, 0}, {2, -1, 0}, {3, -1, 0}, {4, -1, 0}}, 4, 0},
        {"Blue", 'B', 0, {{1, -1, 0}, {2, -1, 0}, {3, -1, 0}, {4, -1, 0}}, 4, 0},
        {"Red", 'R', 0, {{1, -1, 0}, {2, -1, 0}, {3, -1, 0}, {4, -1, 0}}, 4, 0},
        {"Green", 'G', 0, {{1, -1, 0}, {2, -1, 0}, {3, -1, 0}, {4, -1, 0}}, 4, 0}
    };

    short playOrder[4];

    srand(time(NULL));

    for(short i = 0; i < 4; i++)
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

    callingOrder(playOrder, &player[0].diceVal, &player[1].diceVal, &player[2].diceVal, &player[3].diceVal);

    for(short i = 0; i < 4; i++)
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

    while(!standardNotEmpty(&player[0].piecesBase, &player[1].piecesBase, &player[2].piecesBase, &player[3].piecesBase))
    {
        for(short i = 0; i < 4; i++)
        {
            short temp = playOrder[i];

            switch(temp)
            {
                case 0:
                    player[0].diceVal = diceRoll();
                    if(player[0].diceVal == 6)
                    {
                        setCellX(0, &player[0]);
                        printCellX(&player[0]);
                    }
                    break;

                case 1:
                    player[1].diceVal = diceRoll();
                    if(player[1].diceVal == 6)
                    {
                        setCellX(1, &player[1]);
                        printCellX(&player[1]);
                    }
                    break;

                case 2:
                    player[2].diceVal = diceRoll();
                    if(player[2].diceVal == 6)
                    {
                        setCellX(2, &player[2]);
                        printCellX(&player[2]);
                    }
                    break;

                case 3:
                    player[3].diceVal = diceRoll();
                    if(player[3].diceVal == 6)
                    {
                        setCellX(3, &player[3]);
                        printCellX(&player[3]);
                    }
                    break;
            }
        }
    }

    printf("\nColour : %s\nLetter : %c\nDice Value : %d\nPiece %d : (Pos : %d, Dir : %d)\nPiece %d : (Pos : %d, Dir : %d)\nPiece %d : (Pos : %d, Dir : %d)\nPiece %d : (Pos : %d, Dir : %d)\nBase : %d\n", player[0].colour, player[0].letter, player[0].diceVal, player[0].pieces[0].index, player[0].pieces[0].position, player[0].pieces[0].pieceDir, player[0].pieces[1].index, player[0].pieces[1].position, player[0].pieces[1].pieceDir, player[0].pieces[2].index, player[0].pieces[2].position, player[0].pieces[2].pieceDir, player[0].pieces[3].index, player[0].pieces[3].position, player[0].pieces[3].pieceDir, player[0].piecesBase);

    printf("\nColour : %s\nLetter : %c\nDice Value : %d\nPiece %d : (Pos : %d, Dir : %d)\nPiece %d : (Pos : %d, Dir : %d)\nPiece %d : (Pos : %d, Dir : %d)\nPiece %d : (Pos : %d, Dir : %d)\nBase : %d\n", player[1].colour, player[1].letter, player[1].diceVal, player[1].pieces[0].index, player[1].pieces[0].position, player[1].pieces[0].pieceDir, player[1].pieces[1].index, player[1].pieces[1].position, player[1].pieces[1].pieceDir, player[1].pieces[2].index, player[1].pieces[2].position, player[1].pieces[2].pieceDir, player[1].pieces[3].index, player[1].pieces[3].position, player[1].pieces[3].pieceDir, player[1].piecesBase);

    printf("\nColour : %s\nLetter : %c\nDice Value : %d\nPiece %d : (Pos : %d, Dir : %d)\nPiece %d : (Pos : %d, Dir : %d)\nPiece %d : (Pos : %d, Dir : %d)\nPiece %d : (Pos : %d, Dir : %d)\nBase : %d\n", player[2].colour, player[2].letter, player[2].diceVal, player[2].pieces[0].index, player[2].pieces[0].position, player[2].pieces[0].pieceDir, player[2].pieces[1].index, player[2].pieces[1].position, player[2].pieces[1].pieceDir, player[2].pieces[2].index, player[2].pieces[2].position, player[2].pieces[2].pieceDir, player[2].pieces[3].index, player[2].pieces[3].position, player[2].pieces[3].pieceDir, player[2].piecesBase);

    printf("\nColour : %s\nLetter : %c\nDice Value : %d\nPiece %d : (Pos : %d, Dir : %d)\nPiece %d : (Pos : %d, Dir : %d)\nPiece %d : (Pos : %d, Dir : %d)\nPiece %d : (Pos : %d, Dir : %d)\nBase : %d\n", player[3].colour, player[3].letter, player[3].diceVal, player[3].pieces[0].index, player[3].pieces[0].position, player[3].pieces[0].pieceDir, player[3].pieces[1].index, player[3].pieces[1].position, player[3].pieces[1].pieceDir, player[3].pieces[2].index, player[3].pieces[2].position, player[3].pieces[2].pieceDir, player[3].pieces[3].index, player[3].pieces[3].position, player[3].pieces[3].pieceDir, player[3].piecesBase);

    return 0;
}