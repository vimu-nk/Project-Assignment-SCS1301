#ifndef TYPES_H
#define TYPES_H

struct players
{
    char colour[7];
    char letter;
    short diceVal;
    short piece1;
    short piece1Dir;
    short piece2;
    short piece2Dir;
    short piece3;
    short piece3Dir;
    short piece4;
    short piece4Dir;
};

short diceRoll();
short coinToss();

void callingOrder(short order[], short *y, short *b, short *r, short *g);

#endif