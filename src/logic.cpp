#include "logic.h"
#include "display.h"
#include <stdlib.h>
#include <stdio.h>

void makeNumber(int number[]) {
    bool spentNum[10];    // Массив для отметки использованных цифр
    for (int i = 0; i < 10; i++) spentNum[i] = false;

    number[0] = rand() % 9 + 1;    // Первая цифра не ноль
    spentNum[number[0]] = true;

    for (int i = 1; i < 4; i++) {
        number[i] = rand() % 10;
        // Проверка на повторяющиеся цифры
        while (spentNum[number[i]]) number[i] = rand() % 10;
        spentNum[number[i]] = true;
    }
}

