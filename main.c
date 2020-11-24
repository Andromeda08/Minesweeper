#include <stdlib.h>
#include <time.h>

#include "minesweeper/render.h"
#include "minesweeper/mainMenu.h"

int main(void) {
    srand(time(NULL));

    clearScreen();
    mainMenu();

    return 0;
}