#include "display.h"
#include "logic.h"
#include <stdlib.h>
#include <stdio.h>

void clearScreen() {
    system("CLS");
    printf("\
 ����� ������ ���� �������������,��������������,�� ������ \n\
 ����������, � ����� �� ������ ���������� � ����        \n\
 -----------------------------------------------------\n\n");
}

void printNumber(const int number[]) {
    for (int i = 0; i < 4; i++)
        printf("%d", number[i]);
}

void printBeasts(const int bulls, const int cows, const int step) {
    printf(" ����: %d", bulls);
    if (bulls == 4) printf("   �� ��������!!!");
    else printf(" ������: %d", cows);
    printf(" ���: %d", step);
    printf("\n\n");
}
