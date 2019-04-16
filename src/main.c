#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>
#include <string.h>

int game = 0;
int x1, y11, x2, y2;
char board[9][9] = {{'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'}};

int main()
{
    showboard();
    printf("Input example : a2-a3\n");
    while (1) {
        printf("player 1 : ");
        scanh(1);
        move();
        printf("\033[2J");   /* Clear the entire screen. */
        printf("\033[0;0f"); /* Move cursor to the top left hand corner */
        showboard();
        printf("player 2 : ");
        scanh(2);
        move();
        printf("\033[2J");   /* Clear the entire screen. */
        printf("\033[0;0f"); /* Move cursor to the top left hand corner */
        showboard();
    }
    return 0;
};