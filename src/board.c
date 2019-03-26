#include <stdio.h>
#include <string.h>

extern int game;
extern int x1,y11,x2,y2;
extern char board[9][9];

void muve()
{
    board[x2][y2] = board[x1][y11];
    if ((x1 + y11) % 2){
        board[x1][y11] = ' ';
    }
    else{
        board[x1][y11] = (char)219;
    }
}

void scanh(int flag)
{
    char tempxy[6] = "NULL";
    while (1) {
        while (1) {
            scanf("%s", tempxy);
            if (strcmp(tempxy, "exit") == 0 || strcmp(tempxy, "0") == 0) {
                game = -1;
                return;
            }
            if (inter(tempxy)) {
                break;
            }
            printf("Error,try gain:");
        }
        if (flag == 1) {
            if (check1() == 1) {
                break;
            } else {
                printf("Error, try again:");
            }
        }
        if (flag == 2) {
            if (check2() == 1) {
                break;
            } else
                printf("Error, try again:");
        }
    }
}

int inter(char tempxy[6])
{
    x1 = (int)tempxy[1] - 49;
    y11 = (int)tempxy[0] - 97;
    x2 = (int)tempxy[4] - 49;
    y2 = (int)tempxy[3] - 97;
    if ((strlen(tempxy) == 5) && (x2 < 8) && (x2 >= 0) && (y2 >= 0) && (y2 < 8)
        && (x1 >= 0) && (x1 < 8) && (y11 >= 0) && (y11 < 8)) {
        return 1;
    }
    return 0;
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