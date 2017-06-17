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

