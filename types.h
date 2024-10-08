#ifndef TYPES_H
#define TYPES_H

#define MAX_PLAYERS 4
#define MAX_PIECES_PER_PLAYER 4

struct playerPieces
{
    short index;
    short position;
    short pieceDir;
    short preValue;
};

struct players
{
    char colour[7];
    char letter;
    short diceVal;
    struct playerPieces pieces[4];
    short piecesBase;
    short piecesHome;
    short piecesStdIndexes[4];
    short piecesHomeIndexes[4];
};

void gameLoop();

short diceRoll();

short coinToss();

void callingOrder(short order[], struct players *player);

short standardNotEmpty(struct players *player);

void setCellX(short index, struct players *player);

void printCellX(short index, struct players *player);

void printStatus(struct players *player);

void printPieceMove(short index, short pieceID, short previous, struct players *player);

short winCheck(struct players *player);

short yellowBehaviour(short index, struct players *player);

short blueBehaviour(short index, struct players *player);

short redBehaviour(short index, struct players *player);

short greenBehaviour(short index, struct players *player);

void pieceMove(short index, struct players *player);

#endif