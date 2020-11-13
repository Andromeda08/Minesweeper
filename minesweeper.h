#ifndef MINESWEEPER_MINESWEEPER_H
#define MINESWEEPER_MINESWEEPER_H
#include <time.h>
#include <stdbool.h>
//Data structures
typedef struct gTime {
    int min, sec;
} gTime;

typedef struct GameField {
    char **field;
    char **visible;
    char **opened;
    int size_X, size_Y, mine_C;
    gTime timer;
} GameField;

typedef struct Coordinate {
    int x, y;
} Coordinate;


void gameLoop(GameField gf);
void guessing(GameField gf, Coordinate guess, int cmd);
bool checkWin(GameField gf);
void endScreen(GameField gf, bool win);

void timer(GameField gf);
char adjacentMines(GameField gf, int x, int y);
bool isMine(GameField gf, Coordinate c);
void floodFill(GameField gf, int x, int y);

#endif //MINESWEEPER_MINESWEEPER_H