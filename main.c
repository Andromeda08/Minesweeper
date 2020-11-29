#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "minesweeper/render.h"
#include "minesweeper/mainMenu.h"

//#include "vendor/debugmalloc.h"

int main(void) {
    //Random generator
    srand(time(NULL));
    //Console Title, Clear Screen
    printf("\033]0; Minesweeper\007");
    clearScreen();
    //Enter main menu
    mainMenu();

    return 0;
}