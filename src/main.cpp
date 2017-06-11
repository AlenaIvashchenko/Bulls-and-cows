#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include "logic.h"
#include "display.h"


#ifdef _WIN32
    #include "conio.h"
#else
    char getch() {
        return 0;
    }
#endif

int main() {
    srand(time(NULL));
    clearScreen();
    int step = 0;

    int compNum[4];
    makeNumber(compNum);

    bool exitFlag = false;
    while (exitFlag != true) {
        int inputNum = 0;
        printf(" Write your number: "); scanf("%d", &inputNum);

 
        if (checkBeasts(compNum, inputNum, step)) {
            printf(" Want to play more? (Y/N): ");
            char key = getch();
            switch (key) {
                case 'Y': case 'y':
                    step = 0; clearScreen(); break;
                case 'N': case 'n':
                    exitFlag = true; break;
                default:
                    clearScreen(); break;
            }
        }
    }
}
