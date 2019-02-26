#include <stdio.h>

void showboard(char board[8][8])
{
    int i,j;
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

int main()
{
	char board[8][8] = {
 		"rhbqkbhr",
 		"pppppppp",
 		"........",
 		"........",
 		"........",
 		"........",
 		"PPPPPPPP",
 		"RHBQKBHR" };
    showboard(board);
    return 0;
};