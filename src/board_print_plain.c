#include "board_print_plain.h"
#include <stdio.h>

extern char board[8][8];

void printboard() {
  printf("\033[2J");
  printf("\033[0;0f");
  for (int i = 0; i < 2; ++i) {
    printf("\n");
  }
  printf("                                Визуализатор ходов\n");
  printf("\n");
  printf("\n");
  printf("                                Обычный ход: E2-E4\n");
  printf("                                Ход взятия: E2xE4\n");

  int i, j;
  printf("\n");

  for (i = 7; i >= 0; i--) {
    printf("                                ");
    printf("%d ", i + 1);
    for (j = 0; j < 8; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }

  printf("                                  ");
  for (i = 0; i < 8; i++) {
    printf("%c ", i + 97);
  }
  printf("\n");
  printf("\n");
  printf("\n");
}