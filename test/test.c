#include "../src/board.h"
#include "../src/board_print_plain.h"
#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <string.h>

CTEST(inputdata, inter)
{
    strcpy(input, "E2fE4"); // Ввод неправильного формата
    int c1 = inter(input);

    strcpy(input, "E2-E4"); // Обычный ход
    int c2 = inter(input);

    strcpy(input, "E2-E9"); // Ход за пределы поля
    int c3 = inter(input);

    strcpy(input, "hello!"); // Ввод мусора
    int c4 = inter(input);

    const int exp1 = 0;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}