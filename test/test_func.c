#include "../src/func.h"

#include <stdio.h>
#include <stdlib.h>

#include "../ctest/ctest.h"

CTEST(hamgman, hangman_good_1)
{
    int num = 0;
    int real = hangman(num);

    const int expected = 0;
    ASSERT_EQUAL(expected, real);
}

CTEST(hamgman, hangman_good_2)
{
    int num = 9;
    int real = hangman(num);
    const int expected = 0;
    ASSERT_EQUAL(expected, real);
}

CTEST(hamgman, hangman_bad_1)
{
    int num = -1;
    int real = hangman(num);
    const int expected = 1;
    ASSERT_EQUAL(expected, real);
}

CTEST(hamgman, hangman_bad_2)
{
    int num = 10;
    int real = hangman(num);
    const int expected = 1;
    ASSERT_EQUAL(expected, real);
}

CTEST(getrand, getrand_1)
{
    int num1 = 0;
    int num2 = 0;
    int real = getrand(num1, num2);
    ASSERT_INTERVAL(num1, num2, real);
}

CTEST(getrand, getrand_2)
{
    int num1 = 0;
    int num2 = 1000;
    int real = getrand(num1, num2);
    ASSERT_INTERVAL(num1, num2, real);
}

CTEST(getrand, getrand_3)
{
    int num1 = -100;
    int num2 = 100;
    int real = getrand(num1, num2);
    ASSERT_INTERVAL(num1, num2, real);
}

CTEST(length_string, length_string_1)
{
    char m[5] = "HellO";
    int real = length_string(m);
    const int expected = 5;
    ASSERT_EQUAL(expected, real);
}

CTEST(length_string, length_string_2)
{
    char m[30] = "HellO";
    int real = length_string(m);
    const int expected = 5;
    ASSERT_EQUAL(expected, real);
}

CTEST(length_string, length_string_3)
{
    char m[0] = "";
    int real = length_string(m);
    const int expected = 0;
    ASSERT_EQUAL(expected, real);
}
