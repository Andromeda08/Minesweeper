#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mainMenu.h"
#include "minesweeper.h"
#include "render.h"

bool loop = true;
GameField mf;

void mainMenu() {
    int menuOption;

    do {
        econio_textcolor(COL_RESET);
        printf("╔═════════════╦══════════════════════╗\n"
               "║ \033[0;36mMinesweeper \033[0;0m║      \033[0;34mMain Menu       \033[0;0m║\n"
               "╚═════════════╩══════════════════════╝\n"
               "(1) \033[0;36mNew Game\n"
               "\033[0;0m(2) \033[0;36mExit\n"
               "\033[0;0m> ");
        scanf("%d", &menuOption);

        switch (menuOption) {
            case 1:
                loop = false;
                newGame(mf);
                break;
            case 2:
                loop = false;
                break;
        }
    }while(loop);
}

void newGame(GameField mf) {
    clearScreen();
    //get input
    printf("╔═════════════╦══════════════════════╗\n"
           "║ \033[0;36mMinesweeper \033[0;0m║   \033[0;34mCreate New Game    \033[0;0m║\n"
           "╚═════════════╩══════════════════════╝\n"
           "How big should the minefield be? <x> <y>\n> ");
    scanf("%d %d", &mf.size_X, &mf.size_Y);
    printf("How many mines should it contain? <n>\n> ");
    scanf("%d", &mf.mine_C);
    //Allocate memory
    mf.field = allocateMemory(mf.field, mf);
    mf.visible = allocateMemory(mf.visible, mf);
    mf.opened = allocateMemory(mf.opened, mf);
    //Create hidden field
    for(int y = 0; y < mf.size_Y; y++)
        for(int x = 0; x < mf.size_X; x++)
            mf.field[y][x] = '0';
    //Fill with mine_C mines
    for(int i = 0; i < mf.mine_C; i++) {
        int mine_X = rand() % mf.size_X;
        int mine_Y = rand() % mf.size_Y;
        if(mf.field[mine_Y][mine_X] == 'x') {
            i--;
        } else {
            mf.field[mine_Y][mine_X] = 'x';
        }

    }
    //Add mine counts
    for(int y = 0; y < mf.size_Y; y++)
        for(int x = 0; x < mf.size_X; x++)
            mf.field[y][x] = adjacentMines(mf, x, y);
    //Create visible field
    for(int y = 0; y < mf.size_Y; y++) {
        for(int x = 0; x < mf.size_X; x++) {
            mf.visible[y][x] = '-';
        }
    }

    //debug render
    for(int y = 0; y < mf.size_Y; y++) {
        for(int x = 0; x < mf.size_X; x++) {
            printf(" %c ", mf.field[y][x]);
        }
        printf("\n");
    }
    game(mf);
}

char **allocateMemory(char **array, GameField gf) {
    array = (char**) malloc(gf.size_Y * sizeof(char*));
    for(int y = 0; y < gf.size_Y; y++) {
        array[y] = (char*) malloc(gf.size_X * sizeof(char));
    }
    return array;
}
void freeMemory(GameField gf) {
    free(gf.field);
    free(gf.visible);
}