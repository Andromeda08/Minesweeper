#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "render.h"

//#include "../vendor/debugmalloc.h"

//Render
void render(GameField gf, bool reveal) {
    clearScreen();
    printf("\033[0;0m╔═════════════╦════════════╦═════════╗\n"
           "║ \033[0;36mMinesweeper \033[0;0m║ Mines: \033[0;31m%3d \033[0;0m║ \033[0;36m%2d\033[0;0m : \033[0;36m%2d \033[0;0m║\n"
           "╚═════════════╩════════════╩═════════╝\n", gf.mine_C, gf.timer.min, gf.timer.sec);
    //Felső keret
    printf("╔═══");
    for(int i = 1; i < gf.size_X; i++)
        printf("╦═══");
    printf("╗\n");

    for (int y = 0; y < gf.size_Y; y++) {
        for (int x = 0; x < gf.size_X; x++) {
            printf("\033[0;0m║");
            if(!reveal) {
                if (gf.visible[y][x] == '-')
                    printf(" \033[0;36m%c ", gf.visible[y][x]);
                else if (gf.visible[y][x] == '?')
                    printf(" \033[0;35m%c ", gf.visible[y][x]);
                else
                    printf(" \033[0;33m%c ", gf.visible[y][x]);
            } else {
                if (gf.field[y][x] == 'x')
                    printf(" \033[0;31m%c ", gf.field[y][x]);
                else
                    printf(" \033[0;36m%c ", gf.field[y][x]);
            }
        }
        printf("\033[0;0m║ \033[0;90m%3d \033[0;0m\n", y);
    }

    //Alsó Keret
    printf("╚═══");
    for(int i = 1; i < gf.size_X; i++)
        printf("╩═══");
    printf("╝\n");

    //X Koordináták
    printf("\033[0;90m%3d", 0);
    for(int i = 1; i < gf.size_X; i++)
        printf("%4d", i);
    printf("\n");
}

void clearScreen() {
    system ("clear");
}