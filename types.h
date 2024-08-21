#ifndef TYPES_H
#define TYPES_H

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
    short piecesFinished;
};

short diceRoll();

short coinToss();

short choosePiece(short x);

void callingOrder(short order[], short *y, short *b, short *r, short *g);

short standardNotEmpty(short *y, short *b, short *r, short *g);

void setCellX(short index, struct players *player);

void printCellX(struct players *player);

void pieceMove(short index, struct players *player);

#endif