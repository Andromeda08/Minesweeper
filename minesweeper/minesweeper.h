#ifndef MINESWEEPER_MINESWEEPER_H
#define MINESWEEPER_MINESWEEPER_H
#include <time.h>
#include <stdbool.h>
//Data structures
//Idő adattípus
typedef struct gameTime {
    int min, sec;
} gameTime;

//Játékmenet sadatstruktúrája
typedef struct GameField {
    char **field;
    char **visible;
    char **opened;
    int size_X, size_Y, mine_C;
    gameTime timer;
} GameField;

//Koordináta adattípus
typedef struct Coordinate {
    int x, y;
} Coordinate;

//Játékmenet
void gameLoop(GameField gf);
//Játékos lépésének feldolgozása
void guessing(GameField gf, Coordinate guess, int cmd);
//Win eset ellenőrzése
bool checkWin(GameField gf);
//Win-Lose eset feldolgozása
void endScreen(GameField gf, bool win);

//Egy mező környetzetében megszámolja az aknákat
char adjacentMines(GameField gf, int x, int y);
//Megállapítja, hogy az adott mezőn van-e akna
bool isMine(GameField gf, Coordinate c);
//A flood fill rekuzív algoritmus implementációja automatikus mező felderítéshez
void floodFill(GameField gf, int x, int y);

#endif //MINESWEEPER_MINESWEEPER_H
