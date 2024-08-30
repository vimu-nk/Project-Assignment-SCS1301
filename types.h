#ifndef TYPES_H
#define TYPES_H

#define MAX_PLAYERS 4
#define MAX_PIECES_PER_PLAYER 4

struct playerPieces
{
    short index;
    short position;
    short pieceDir;
};

struct players
{
    char colour[7];
    char letter;
    short diceVal;
    struct playerPieces pieces[4];
    short piecesBase;
    short piecesHome;
};

short diceRoll();

short coinToss();

short choosePiece(short x);

void callingOrder(short order[], struct players *player);

short standardNotEmpty(struct players *player);

void setCellX(short index, struct players *player);

void printCellX(short index, struct players *player);

void printStatus(struct players *player);

void pieceMove(short index, struct players *player);

#endif