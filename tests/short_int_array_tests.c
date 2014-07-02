#include "short_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(ShortIntArrayTests);

ShortIntArray shortIntArray;
ShortIntArray otherShortIntArray;

TEST_SETUP(ShortIntArrayTests) {
    ShortIntArrayInitialize(&shortIntArray);

    ShortIntArrayInitialize(&otherShortIntArray);
}

TEST_TEAR_DOWN(ShortIntArrayTests) {
    ShortIntArrayDeinitialize(&shortIntArray);
}

TEST(ShortIntArrayTests, ShortIntArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, shortIntArray.length);
}

TEST(ShortIntArrayTests, ShortIntArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, shortIntArray.capacity);
}

TEST(ShortIntArrayTests, ShortIntArrayPushOneElement) {
    int result = ShortIntArrayPush(&shortIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, shortIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, shortIntArray.capacity);
}

TEST(ShortIntArrayTests, ShortIntArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = ShortIntArrayPush(&shortIntArray, (short int)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, shortIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, shortIntArray.capacity);
}

TEST(ShortIntArrayTests, ShortIntArrayAtZeroLength) {
    short int x;

    int result = ShortIntArrayAt(&shortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortIntArrayTests, ShortIntArrayAtExistingElement) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    ShortIntArrayPush(&shortIntArray, 3);

    ShortIntArrayPush(&shortIntArray, 4);

    ShortIntArrayPush(&shortIntArray, 5);

    short int x;

    int result = ShortIntArrayAt(&shortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);
}

TEST(ShortIntArrayTests, ShortIntArrayAtLessThanZeroIndex) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    ShortIntArrayPush(&shortIntArray, 3);

    ShortIntArrayPush(&shortIntArray, 4);

    ShortIntArrayPush(&shortIntArray, 5);

    short int x;

    int result = ShortIntArrayAt(&shortIntArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(ShortIntArrayTests, ShortIntArrayAtGreaterThanLengthIndex) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    ShortIntArrayPush(&shortIntArray, 3);

    ShortIntArrayPush(&shortIntArray, 4);

    ShortIntArrayPush(&shortIntArray, 5);

    short int x;

    int result = ShortIntArrayAt(&shortIntArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortIntArrayTests, ShortIntArrayAtLessThanNegativeLengthIndex) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    ShortIntArrayPush(&shortIntArray, 3);

    ShortIntArrayPush(&shortIntArray, 4);

    ShortIntArrayPush(&shortIntArray, 5);

    short int x;

    int result = ShortIntArrayAt(&shortIntArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortIntArrayTests, ShortIntArrayClear) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    ShortIntArrayPush(&shortIntArray, 3);

    ShortIntArrayPush(&shortIntArray, 4);

    ShortIntArrayPush(&shortIntArray, 5);

    int result = ShortIntArrayClear(&shortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortIntArray.length);
}

TEST(ShortIntArrayTests, ShortIntArrayConcatEmptyArrays) {
    int result = ShortIntArrayConcat(&shortIntArray, &otherShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortIntArray.length);
}

TEST(ShortIntArrayTests, ShortIntArrayConcatEmptyArrayToNonEmptyArray) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    int result = ShortIntArrayConcat(&shortIntArray, &otherShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, shortIntArray.length);

    short int x;

    ShortIntArrayAt(&shortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortIntArrayAt(&shortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(ShortIntArrayTests, ShortIntArrayConcatNonEmptyArrayToEmptyArray) {
    ShortIntArrayPush(&otherShortIntArray, 1);

    ShortIntArrayPush(&otherShortIntArray, 2);

    int result = ShortIntArrayConcat(&shortIntArray, &otherShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, shortIntArray.length);

    short int x;

    ShortIntArrayAt(&shortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortIntArrayAt(&shortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(ShortIntArrayTests, ShortIntArrayConcatNonEmptyArrayToNonEmptyArray) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    ShortIntArrayPush(&otherShortIntArray, 3);

    ShortIntArrayPush(&otherShortIntArray, 4);

    int result = ShortIntArrayConcat(&shortIntArray, &otherShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, shortIntArray.length);

    short int x;

    ShortIntArrayAt(&shortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortIntArrayAt(&shortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    ShortIntArrayAt(&shortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    ShortIntArrayAt(&shortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(ShortIntArrayTests, ShortIntArrayCountEmptyArray) {
    size_t result = ShortIntArrayCount(&shortIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(ShortIntArrayTests, ShortIntArrayCountNonEmptyArray) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    size_t result = ShortIntArrayCount(&shortIntArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(ShortIntArrayTests, ShortIntArrayDeleteFromEmptyArray) {
    int result = ShortIntArrayDelete(&shortIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortIntArray.length);
}

TEST(ShortIntArrayTests, ShortIntArrayDeleteNonExistingElement) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    int result = ShortIntArrayDelete(&shortIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, shortIntArray.length);
}

TEST(ShortIntArrayTests, ShortIntArrayDeleteExistingElement) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    int result = ShortIntArrayDelete(&shortIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, shortIntArray.length);
}

TEST(ShortIntArrayTests, ShortIntArrayDeleteAtZeroLength) {
    int result = ShortIntArrayDeleteAt(&shortIntArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortIntArrayTests, ShortIntArrayDeleteAtExistingElement) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    ShortIntArrayPush(&shortIntArray, 3);

    ShortIntArrayPush(&shortIntArray, 4);

    ShortIntArrayPush(&shortIntArray, 5);

    int result = ShortIntArrayDeleteAt(&shortIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, shortIntArray.length);

    short int x;

    ShortIntArrayAt(&shortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortIntArrayAt(&shortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    ShortIntArrayAt(&shortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(4, x);

    ShortIntArrayAt(&shortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(ShortIntArrayTests, ShortIntArrayDeleteAtLessThanZeroIndex) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    ShortIntArrayPush(&shortIntArray, 3);

    ShortIntArrayPush(&shortIntArray, 4);

    ShortIntArrayPush(&shortIntArray, 5);

    int result = ShortIntArrayDeleteAt(&shortIntArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, shortIntArray.length);

    short int x;

    ShortIntArrayAt(&shortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortIntArrayAt(&shortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    ShortIntArrayAt(&shortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    ShortIntArrayAt(&shortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(ShortIntArrayTests, ShortIntArrayDeleteAtGreaterThanLengthIndex) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    ShortIntArrayPush(&shortIntArray, 3);

    ShortIntArrayPush(&shortIntArray, 4);

    ShortIntArrayPush(&shortIntArray, 5);

    int result = ShortIntArrayDeleteAt(&shortIntArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortIntArrayTests, ShortIntArrayDeleteAtLessThanNegativeLengthIndex) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    ShortIntArrayPush(&shortIntArray, 3);

    ShortIntArrayPush(&shortIntArray, 4);

    ShortIntArrayPush(&shortIntArray, 5);

    int result = ShortIntArrayDeleteAt(&shortIntArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortIntArrayTests, ShortIntArrayDropOneEmptyArray) {
    int result = ShortIntArrayDrop(&shortIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortIntArray.length);
}

TEST(ShortIntArrayTests, ShortIntArrayDropManyEmptyArray) {
    int result = ShortIntArrayDrop(&shortIntArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortIntArray.length);
}

TEST(ShortIntArrayTests, ShortIntArrayDropLessThanArrayLength) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    ShortIntArrayPush(&shortIntArray, 3);

    ShortIntArrayPush(&shortIntArray, 4);

    ShortIntArrayPush(&shortIntArray, 5);

    int result = ShortIntArrayDrop(&shortIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, shortIntArray.length);

    short int x;

    ShortIntArrayAt(&shortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(4, x);

    ShortIntArrayAt(&shortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(ShortIntArrayTests, ShortIntArrayDropGreaterThanArrayLength) {
    ShortIntArrayPush(&shortIntArray, 1);

    ShortIntArrayPush(&shortIntArray, 2);

    ShortIntArrayPush(&shortIntArray, 3);

    ShortIntArrayPush(&shortIntArray, 4);

    ShortIntArrayPush(&shortIntArray, 5);

    int result = ShortIntArrayDrop(&shortIntArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortIntArray.length);
}
