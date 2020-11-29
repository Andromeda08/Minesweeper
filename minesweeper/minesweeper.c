#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "minesweeper.h"
#include "render.h"
#include "mainMenu.h"

//#include "../vendor/debugmalloc.h"

//Game status
bool gameover = false;

void gameLoop(GameField gf) {
    int cmd;
    Coordinate guess;
    //Timer variables
    long double total;
    time_t start, current, elapsed;
    start = time(NULL);
    //Core gameloop
    do {
        //Calculate Time
        current = time(NULL);
        elapsed = current - start;
        gf.timer.min = (int) elapsed / 60;
        gf.timer.sec = (int) (elapsed - gf.timer.min*60);
        //Render
        render(gf, false);
        //Win check
        if(checkWin(gf) == true) {
            endScreen(gf, true);
            break;
        }
        printf("\033[0:32mFormat: <x> <y> <1/2> (1: guess 2: mark)\n"
               "\033[0:0m>");
        //User input handling
        while((scanf("%d %d %d", &guess.x, &guess.y, &cmd)) != 3) {
            fflush(stdin);
            printf("Try again!\n> ");
        }
        //Act on user input
        guessing(gf, guess, cmd);

    } while (!gameover);
    //Free memory when game ends
    freeMemory(gf);
}
//Processing the players move
void guessing(GameField gf, Coordinate guess, int cmd) {
    if (guess.x >= 0 && guess.x < gf.size_X) {
        if (guess.y >= 0 && guess.y < gf.size_Y) {
            if (cmd == 1) {
                if (isMine(gf, guess)) {
                    endScreen(gf, false);
                } else {
                    floodFill(gf, guess.x, guess.y);
                }
            } else if (cmd == 2) {
                if(gf.opened[guess.y][guess.x] == '0') {
                    gf.visible[guess.y][guess.x] = '?';
                }
            } else {
                printf("\033[0;31mError: Invalid format!\033[0;0m\n");
            }
        }
    }
}
//Count adjacent mines to a cell
char adjacentMines(GameField gf, int x, int y) {
    int count = 0;
    if(gf.field[y][x] == 'x')
        return 'x';

    for(int i = -1; i <= 1; i++) {
        if((y + i < 0) || (y + i >= gf.size_Y)) {
            continue;
        }
        for(int j = -1; j <= 1; j++) {
            if((x + j < 0) || (x + j >= gf.size_X)) {
                continue;
            }
            if(gf.field[y + i][x + j] == 'x') {
                count++;
            }
        }
    }
    char c = count + '0';
    return c;
}
//Checks if a field has a mine on it
bool isMine(GameField gf, Coordinate c) {
    if(gf.field[c.y][c.x] == 'x') {
        return true;
    } else {
        return false;
    }
}
//Implementation of the flood fill algorithm for automatic field revealing
void floodFill(GameField gf, int x, int y) {
    if(y < 0 || y >= gf.size_Y || x < 0 || x >= gf.size_X)
        return;
    if(gf.field[y][x] != '0') {
        gf.opened[y][x] = '1';
        gf.visible[y][x] = gf.field[y][x];
        return;
    }
    if(gf.opened[y][x] == '1')
        return;

    gf.visible[y][x] = ' ';
    gf.opened[y][x] = '1';

    floodFill(gf, x, y+1);
    floodFill(gf, x, y-1);
    floodFill(gf, x+1, y+1);
    floodFill(gf, x+1, y);
    floodFill(gf, x+1, y-1);
    floodFill(gf, x-1, y+1);
    floodFill(gf, x-1, y);
    floodFill(gf, x-1, y-1);
}
//Checks for win condition
bool checkWin(GameField gf) {
    int count = 0;
    int toWin = gf.size_X * gf.size_Y - gf.mine_C;
    for(int y = 0; y < gf.size_Y; y++) {
        for(int x = 0; x < gf.size_X; x++) {
            if(gf.opened[y][x] == '1')
                count++;
        }
    }
    if(count == toWin) {
        return true;
    }
    return false;
}
//Handle win or lose case
void endScreen(GameField gf, bool win) {
    gameover = true;
    if(win) {
        printf("\n╔════════════════════════════════════╗\n"
               "║ \033[0;33m            You Won!               \033[0;0m║\n"
               "╚════════════════════════════════════╝\n");
    } else {
        render(gf, true);
        printf("╔════════════════════════════════════╗\n"
               "║ \033[0;31m            You Lost!              \033[0;0m║\n"
               "╚════════════════════════════════════╝\n");
    }
}