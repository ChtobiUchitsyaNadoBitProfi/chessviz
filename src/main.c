#include <stdio.h>
#include <string.h>
#include "board_print_plain.h"
//#include "board.h"
//#include "board_read.h"
char board[8][8] = {
        "rhbqkbhr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RHBQKBHR" };

int main()
{
    showboard(board);
    return 0;
};