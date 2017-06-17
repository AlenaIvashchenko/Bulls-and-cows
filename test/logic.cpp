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

