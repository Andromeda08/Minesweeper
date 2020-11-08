#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "render.h"

void render(GameField gf, bool reveal) {
    clearScreen();
    econio_textcolor(COL_RESET);
    if(reveal) {
        printf("╔═════════════╦════════════╦═════════╗\n"
               "║ \033[0;36mMinesweeper \033[0;0m║ Mines: \033[0;31m%3d \033[0;0m║ \033[0;36mmin\033[0;0m:\033[0;36msec \033[0;0m║\n"
               "╚═════════════╩════════════╩═════════╝\n", gf.mine_C);
        for (int y = 0; y < gf.size_Y; y++) {
            for (int x = 0; x < gf.size_X; x++) {
                printf("\033[0;0m║");

                if (gf.field[y][x] == 'x')
                    econio_textcolor(COL_RED);
                else
                    econio_textcolor(COL_CYAN);

                printf(" %c ", gf.field[y][x]);
            }
            printf("\033[0;0m║\n");
        }
    } else {
        printf("╔═════════════╦════════════╦═════════╗\n"
               "║ \033[0;36mMinesweeper \033[0;0m║ Mines: \033[0;31m%3d \033[0;0m║ \033[0;36mmin\033[0;0m:\033[0;36msec \033[0;0m║\n"
               "╚═════════════╩════════════╩═════════╝\n", gf.mine_C);
        for (int y = 0; y < gf.size_Y; y++) {
            for (int x = 0; x < gf.size_X; x++) {
                printf("\033[0;0m║");
                if(gf.visible[y][x] == '-')
                    printf(" \033[0;36m%c ", gf.visible[y][x]);
                else if(gf.visible[y][x] == '?')
                    printf(" \033[0;35m%c ", gf.visible[y][x]);
                else
                    printf(" \033[0;33m%c ", gf.visible[y][x]);
            }
            printf("\033[0;0m║\n");
        }
    }
}

void clearScreen() {
#ifdef WINDOWS
    system("cls");
#else
    system ("clear");
#endif
}