#include "board_print_plain.h"
#include <stdio.h>

extern int game;
extern char board[8][8];
extern int x1, y11, x2, y2;


void showboard()
{
    int i, j;
    printf("\n");
    for (i = 7; i >= 0; i--) {
        printf("%d|", i + 1);
        for (j = 0; j < 8; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
    printf("   _______________\n");
    printf("   A B C D E F G H\n");
}