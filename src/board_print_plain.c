#include "board_print_plain.h"
#include <stdio.h>

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

int pr_x()
{
    if (y11 != y2)
        return 0;
    int z1 = x1, z2 = x2, i;
    if (x1 > x2) {
        z2 = x1;
        z1 = x2;
    }
    for (i = z1 + 1; i < z2; i++)
        if ((board[i][y11] < 91 && board[i][y11] > 64)
            || (board[i][y11] < 123 && board[i][y11] > 96))
            return 0;
    return 1;
}

int check1()
{
    if (board[x2][y2] < 123 && board[x2][y2] > 96) {
        return 0; //не можна рубати себе
    }
    switch (board[x1][y11]) {
    case 'p':
        if (board[x2][y2] < 91 && board[x2][y2] > 64
            && ((y11 - y2) == 1 || (y2 - y11) == 1) && (x1 - x2 == 1)) {
            return 1; //рубати
        }
        if ((board[x2][y2] == (char)219 || board[x2][y2] == ' ') && (x1 == 6)
            && (y11 == y2) && (x1 - x2 > 0) && (x1 - x2 < 3) && (pr_x())) {
            return 1; //ходи по пуствм клітинам з початкової позиції
        }
        if ((board[x2][y2] == (char)219 || board[x2][y2] == ' ') && (y11 == y2)
            && (x1 - x2) == 1) {
            return 1; //ходи по порожніх клітин
        }
        break;
    }
    return 0;
}

int check2()
{
    if (board[x2][y2] < 91 && board[x2][y2] > 64) {
        return 0; //не можна рубати себе
    }
    switch (board[x1][y11]) {
    case 'P':
        if (board[x2][y2] < 123 && board[x2][y2] > 96
            && (y11 - y2 == 1 || y11 - y2 == -1) && (x2 - x1 == 1)) {
            return 1; //рубати
        }
        if ((board[x2][y2] == (char)219 || board[x2][y2] == ' ') && x1 == 1
            && y11 == y2 && x2 - x1 > 0 && x2 - x1 < 3 && (pr_x())) {
            return 1; //ходи по пуствм клітинам з початкової позиції
        }
        if ((board[x2][y2] == (char)219 || board[x2][y2] == ' ') && y11 == y2
            && x2 - x1 == 1) {
            return 1; //ходи по порожніх клітин
        }       
        break;
        }
return 0;
}