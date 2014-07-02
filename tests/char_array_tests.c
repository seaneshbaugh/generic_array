#include "char_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(CharArrayTests);

CharArray charArray;
CharArray otherCharArray;

TEST_SETUP(CharArrayTests) {
    CharArrayInitialize(&charArray);

    CharArrayInitialize(&otherCharArray);
}

TEST_TEAR_DOWN(CharArrayTests) {
    CharArrayDeinitialize(&charArray);

    CharArrayDeinitialize(&otherCharArray);
}

TEST(CharArrayTests, CharArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, charArray.length);
}

TEST(CharArrayTests, CharArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, charArray.capacity);
}

TEST(CharArrayTests, CharArrayPushOneElement) {
    int result = CharArrayPush(&charArray, 'A');

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, charArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, charArray.capacity);
}

TEST(CharArrayTests, CharArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = CharArrayPush(&charArray, (char)(i % 255));

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, charArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, charArray.capacity);
}

TEST(CharArrayTests, CharArrayAtZeroLength) {
    char x;

    int result = CharArrayAt(&charArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(CharArrayTests, CharArrayAtExistingElement) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    CharArrayPush(&charArray, 'C');

    CharArrayPush(&charArray, 'D');

    CharArrayPush(&charArray, 'E');

    char x;

    int result = CharArrayAt(&charArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('C', x);
}

TEST(CharArrayTests, CharArrayAtLessThanZeroIndex) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    CharArrayPush(&charArray, 'C');

    CharArrayPush(&charArray, 'D');

    CharArrayPush(&charArray, 'E');

    char x;

    int result = CharArrayAt(&charArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('D', x);
}

TEST(CharArrayTests, CharArrayAtGreaterThanLengthIndex) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    CharArrayPush(&charArray, 'C');

    CharArrayPush(&charArray, 'D');

    CharArrayPush(&charArray, 'E');

    char x;

    int result = CharArrayAt(&charArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(CharArrayTests, CharArrayAtLessThanNegativeLengthIndex) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    CharArrayPush(&charArray, 'C');

    CharArrayPush(&charArray, 'D');

    CharArrayPush(&charArray, 'E');

    char x;

    int result = CharArrayAt(&charArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(CharArrayTests, CharArrayClear) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    CharArrayPush(&charArray, 'C');

    CharArrayPush(&charArray, 'D');

    CharArrayPush(&charArray, 'E');

    int result = CharArrayClear(&charArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, charArray.length);
}

TEST(CharArrayTests, CharArrayConcatEmptyArrays) {
    int result = CharArrayConcat(&charArray, &otherCharArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, charArray.length);
}

TEST(CharArrayTests, CharArrayConcatEmptyArrayToNonEmptyArray) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    int result = CharArrayConcat(&charArray, &otherCharArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, charArray.length);

    char x;

    CharArrayAt(&charArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    CharArrayAt(&charArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);
}

TEST(CharArrayTests, CharArrayConcatNonEmptyArrayToEmptyArray) {
    CharArrayPush(&otherCharArray, 'A');

    CharArrayPush(&otherCharArray, 'B');

    int result = CharArrayConcat(&charArray, &otherCharArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, charArray.length);

    char x;

    CharArrayAt(&charArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    CharArrayAt(&charArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);
}

TEST(CharArrayTests, CharArrayConcatNonEmptyArrayToNonEmptyArray) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    CharArrayPush(&otherCharArray, 'C');

    CharArrayPush(&otherCharArray, 'D');

    int result = CharArrayConcat(&charArray, &otherCharArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, charArray.length);

    char x;

    CharArrayAt(&charArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    CharArrayAt(&charArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);

    CharArrayAt(&charArray, 2, &x);

    TEST_ASSERT_EQUAL('C', x);

    CharArrayAt(&charArray, 3, &x);

    TEST_ASSERT_EQUAL('D', x);
}

TEST(CharArrayTests, CharArrayCountEmptyArray) {
    size_t result = CharArrayCount(&charArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(CharArrayTests, CharArrayCountNonEmptyArray) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    size_t result = CharArrayCount(&charArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(CharArrayTests, CharArrayDeleteFromEmptyArray) {
    int result = CharArrayDelete(&charArray, 'A');

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, charArray.length);
}

TEST(CharArrayTests, CharArrayDeleteNonExistingElement) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    int result = CharArrayDelete(&charArray, 'C');

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, charArray.length);
}

TEST(CharArrayTests, CharArrayDeleteExistingElement) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    int result = CharArrayDelete(&charArray, 'B');

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, charArray.length);
}

TEST(CharArrayTests, CharArrayDeleteAtZeroLength) {
    int result = CharArrayDeleteAt(&charArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(CharArrayTests, CharArrayDeleteAtExistingElement) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    CharArrayPush(&charArray, 'C');

    CharArrayPush(&charArray, 'D');

    CharArrayPush(&charArray, 'E');

    int result = CharArrayDeleteAt(&charArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, charArray.length);

    char x;

    CharArrayAt(&charArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    CharArrayAt(&charArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);

    CharArrayAt(&charArray, 2, &x);

    TEST_ASSERT_EQUAL('D', x);

    CharArrayAt(&charArray, 3, &x);

    TEST_ASSERT_EQUAL('E', x);
}

TEST(CharArrayTests, CharArrayDeleteAtLessThanZeroIndex) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    CharArrayPush(&charArray, 'C');

    CharArrayPush(&charArray, 'D');

    CharArrayPush(&charArray, 'E');

    int result = CharArrayDeleteAt(&charArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, charArray.length);

    char x;

    CharArrayAt(&charArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    CharArrayAt(&charArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);

    CharArrayAt(&charArray, 2, &x);

    TEST_ASSERT_EQUAL('C', x);

    CharArrayAt(&charArray, 3, &x);

    TEST_ASSERT_EQUAL('E', x);
}

TEST(CharArrayTests, CharArrayDeleteAtGreaterThanLengthIndex) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    CharArrayPush(&charArray, 'C');

    CharArrayPush(&charArray, 'D');

    CharArrayPush(&charArray, 'E');

    int result = CharArrayDeleteAt(&charArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(CharArrayTests, CharArrayDeleteAtLessThanNegativeLengthIndex) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    CharArrayPush(&charArray, 'C');

    CharArrayPush(&charArray, 'D');

    CharArrayPush(&charArray, 'E');

    int result = CharArrayDeleteAt(&charArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(CharArrayTests, CharArrayDropOneEmptyArray) {
    int result = CharArrayDrop(&charArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, charArray.length);
}

TEST(CharArrayTests, CharArrayDropManyEmptyArray) {
    int result = CharArrayDrop(&charArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, charArray.length);
}

TEST(CharArrayTests, CharArrayDropLessThanArrayLength) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    CharArrayPush(&charArray, 'C');

    CharArrayPush(&charArray, 'D');

    CharArrayPush(&charArray, 'E');

    int result = CharArrayDrop(&charArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, charArray.length);

    char x;

    CharArrayAt(&charArray, 0, &x);

    TEST_ASSERT_EQUAL('D', x);

    CharArrayAt(&charArray, 1, &x);

    TEST_ASSERT_EQUAL('E', x);
}

TEST(CharArrayTests, CharArrayDropGreaterThanArrayLength) {
    CharArrayPush(&charArray, 'A');

    CharArrayPush(&charArray, 'B');

    CharArrayPush(&charArray, 'C');

    CharArrayPush(&charArray, 'D');

    CharArrayPush(&charArray, 'E');

    int result = CharArrayDrop(&charArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, charArray.length);
}
