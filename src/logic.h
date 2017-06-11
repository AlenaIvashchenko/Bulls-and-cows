#ifndef LOGIC_H
#define LOGIC_H

void makeNumber(int randNum[]);
bool convertNumber(int number, int convNum[]);
int countBulls(const int compNum[], const int playerNum[]);
int countCows(const int compNum[], const int playerNum[]);
bool checkBeasts(const int compNum[], const int inputNum, int &step);

#endif // LOGIC_H
