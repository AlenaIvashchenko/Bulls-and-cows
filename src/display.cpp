#include "display.h"
#include "logic.h"
#include <stdlib.h>
#include <stdio.h>

void clearScreen() {
    system("CLS");
    printf("\
 The number must be positive, four-digit, do not have \n\
 duplicate digits, and do not start from zero.        \n\
 -----------------------------------------------------\n\n");
}

void printNumber(const int number[]) {
    for (int i = 0; i < 4; i++)
        printf("%d", number[i]);
}

void printBeasts(const int bulls, const int cows, const int step) {
    printf(" Bulls: %d", bulls);
    if (bulls == 4) printf("   You won!!!");
    else printf(" Cows: %d", cows);
    printf(" Step: %d", step);
    printf("\n\n");
}
