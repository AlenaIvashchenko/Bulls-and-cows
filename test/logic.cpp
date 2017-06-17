#include "ctest.h"
#include "logic.h"

CTEST(logic_suite, making_number) {
    int number[4] = {};
    makeNumber(number);
    ASSERT_TRUE(number[0]);

    bool spentNum[10];
    for (int i = 0; i < 10; i++) spentNum[i] = false;
    bool similarNum = false;
    for (int i = 1; i < 4; i++) {
        if (spentNum[number[i]]) similarNum = true;
        spentNum[number[i]] = true;
    }
    ASSERT_FALSE(similarNum);
}

CTEST(logic_suite, converting_number) {
    int number = 1234;
    int convNum[4] = {};
    convertNumber(number, convNum);
    int expNum[4] = {1, 2, 3, 4};
    ASSERT_DATA((unsigned char*)expNum, 4,
                (unsigned char*)convNum, 4);

    number = 1122;
    ASSERT_FALSE(convertNumber(number, convNum));
    number = 123;
    ASSERT_FALSE(convertNumber(number, convNum));
    number = 12345;
    ASSERT_FALSE(convertNumber(number, convNum));
    number = 0123;
    ASSERT_FALSE(convertNumber(number, convNum));
}

CTEST(logic_suite, bulls_counting) {
    int compNum[4]   = {1, 2, 3, 4};
    int playerNum[4] = {1, 2, 4, 3};
    ASSERT_EQUAL(2, countBulls(compNum, playerNum));

    playerNum[0] = 5;
    playerNum[1] = 6;
    playerNum[2] = 7;
    playerNum[3] = 8;
    ASSERT_EQUAL(0, countBulls(compNum, playerNum));

    playerNum[0] = compNum[0];
    playerNum[1] = compNum[1];
    playerNum[2] = compNum[2];
    playerNum[3] = compNum[3];
    ASSERT_EQUAL(4, countBulls(compNum, playerNum));
}

CTEST(logic_suite, cows_counting) {
    int compNum[4]   = {1, 2, 3, 4};
    int playerNum[4] = {3, 0, 1, 5};
    ASSERT_EQUAL(2, countCows(compNum, playerNum));

    playerNum[0] = 5;
    playerNum[1] = 6;
    playerNum[2] = 7;
    playerNum[3] = 8;
    ASSERT_EQUAL(0, countCows(compNum, playerNum));

    playerNum[0] = compNum[3];
    playerNum[1] = compNum[2];
    playerNum[2] = compNum[1];
    playerNum[3] = compNum[0];
    ASSERT_EQUAL(4, countCows(compNum, playerNum));
}

CTEST(logic_suite, beasts_checking) {
    int compNum[4] = {1, 2, 3, 4};

    int step = 0;
    int inputNum = 4321;
    ASSERT_FALSE(checkBeasts(compNum, inputNum, step));
    ASSERT_EQUAL(1, step);

    inputNum = 0000; step = 0;
    ASSERT_FALSE(checkBeasts(compNum, inputNum, step));
    ASSERT_EQUAL(0, step);

    inputNum = 1234; step = 0;
    ASSERT_TRUE(checkBeasts(compNum, inputNum, step));
    ASSERT_EQUAL(1, step);
}
