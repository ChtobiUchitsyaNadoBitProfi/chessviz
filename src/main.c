#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>
#include <string.h>
//#include "board_read.h"
int game = 0;
int x1, y11, x2, y2;
char board[8][8] = {"rhbqkbhr",
                    "pppppppp",
                    "........",
                    "........",
                    "........",
                    "........",
                    "PPPPPPPP",
                    "RHBQKBHR"};

int main()
{
    showboard(board);
    printf("Input example : a2-a3\n");
    while (1) {
        printf("player 1-not caps:");
        scanh(1);
        muve();
        printf("\033[2J");   /* Clear the entire screen. */
        printf("\033[0;0f"); /* Move cursor to the top left hand corner */
        showboard();
        printf("player 2-caps:");
        scanh(2);
        muve();
        printf("\033[2J");   /* Clear the entire screen. */
        printf("\033[0;0f"); /* Move cursor to the top left hand corner */
        showboard();
    }
    return 0;
};