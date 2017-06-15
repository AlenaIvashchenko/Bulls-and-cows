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
bool convertNumber(int number, int convNum[]) {

    // Проверка на количество символов
    if (number < 1000 || number > 9999) return false;

    // Преобразование числа в массив цифр
    for (int i = 3; i >= 0; i--) {
        convNum[i] = number % 10;
        number /= 10;
    }

    // Проверка на повторяющиеся цифры
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (convNum[i] == convNum[j])
                return false;
    return true;
}

int countBulls(const int compNum[], const int playerNum[]) {
    int bulls = 0;
    for (int i = 0; i < 4; i++) {
        if (compNum[i] == playerNum[i]) bulls++;
    }
    return bulls;
}
int countCows(const int compNum[], const int playerNum[]) {
    int beasts = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (compNum[i] == playerNum[j]) beasts++;
    int cows = beasts - countBulls(compNum, playerNum);
    return cows;
}

