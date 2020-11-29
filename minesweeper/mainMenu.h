#ifndef MINESWEEPER_MAINMENU_H
#define MINESWEEPER_MAINMENU_H

#include "minesweeper.h"

//Main menu
//Main menu kiírás és vezérlése
void mainMenu();
//Új játékmenet létrehozása
void newGame(GameField mf);

//Dinamikus memória kezelés
//Memória foglalása
char **allocateMemory(char **array, GameField gf);
//Memória felszabadtása
void freeMemory(GameField gf);

#endif //MINESWEEPER_MAINMENU_H
