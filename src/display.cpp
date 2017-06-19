#include "display.h"
#include "logic.h"
#include <stdlib.h>
#include <stdio.h>

void clearScreen() {
    system("CLS");
    printf("\
 Число должно быть положительным,четырехзначным, не должно \n\
 быть повторений,также не может начинаться с нуля.       \n\
 -----------------------------------------------------\n\n");
}

void printNumber(const int number[]) {
    for (int i = 0; i < 4; i++)
        printf("%d", number[i]);
}

void printBeasts(const int bulls, const int cows, const int step) {
    printf(" Быки: %d", bulls);
    if (bulls == 4) printf("   Вы выиграли!!!");
    else printf(" Коровы: %d", cows);
    printf(" Шаг: %d", step);
    printf("\n\n");
}
