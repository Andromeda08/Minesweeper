#ifndef MINESWEEPER_MAINMENU_H
#define MINESWEEPER_MAINMENU_H

#include "minesweeper.h"

void mainMenu();
//Menu options
void newGame(GameField mf);
//Memory
char **allocateMemory(char **array, GameField gf);
void freeMemory(GameField gf);

#endif //MINESWEEPER_MAINMENU_H
