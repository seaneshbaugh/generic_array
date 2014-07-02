#include "short_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(ShortArrayTests);

ShortArray shortArray;
ShortArray otherShortArray;

TEST_SETUP(ShortArrayTests) {
    ShortArrayInitialize(&shortArray);

    ShortArrayInitialize(&otherShortArray);
}

TEST_TEAR_DOWN(ShortArrayTests) {
    ShortArrayDeinitialize(&shortArray);

    ShortArrayDeinitialize(&otherShortArray);
}

TEST(ShortArrayTests, ShortArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, shortArray.capacity);
}

TEST(ShortArrayTests, ShortArrayPushOneElement) {
    int result = ShortArrayPush(&shortArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, shortArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, shortArray.capacity);
}

TEST(ShortArrayTests, ShortArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = ShortArrayPush(&shortArray, (short)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, shortArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, shortArray.capacity);
}

TEST(ShortArrayTests, ShortArrayAtZeroLength) {
    short x;

    int result = ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortArrayTests, ShortArrayAtExistingElement) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    short x;

    int result = ShortArrayAt(&shortArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);
}

TEST(ShortArrayTests, ShortArrayAtLessThanZeroIndex) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    short x;

    int result = ShortArrayAt(&shortArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(ShortArrayTests, ShortArrayAtGreaterThanLengthIndex) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    short x;

    int result = ShortArrayAt(&shortArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortArrayTests, ShortArrayAtLessThanNegativeLengthIndex) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    short x;

    int result = ShortArrayAt(&shortArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortArrayTests, ShortArrayClear) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayClear(&shortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayConcatEmptyArrays) {
    int result = ShortArrayConcat(&shortArray, &otherShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayConcatEmptyArrayToNonEmptyArray) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    int result = ShortArrayConcat(&shortArray, &otherShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, shortArray.length);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(ShortArrayTests, ShortArrayConcatNonEmptyArrayToEmptyArray) {
    ShortArrayPush(&otherShortArray, 1);

    ShortArrayPush(&otherShortArray, 2);

    int result = ShortArrayConcat(&shortArray, &otherShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, shortArray.length);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(ShortArrayTests, ShortArrayConcatNonEmptyArrayToNonEmptyArray) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&otherShortArray, 3);

    ShortArrayPush(&otherShortArray, 4);

    int result = ShortArrayConcat(&shortArray, &otherShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, shortArray.length);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    ShortArrayAt(&shortArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    ShortArrayAt(&shortArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(ShortArrayTests, ShortArrayCountEmptyArray) {
    size_t result = ShortArrayCount(&shortArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(ShortArrayTests, ShortArrayCountNonEmptyArray) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    size_t result = ShortArrayCount(&shortArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(ShortArrayTests, ShortArrayDeleteFromEmptyArray) {
    int result = ShortArrayDelete(&shortArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayDeleteNonExistingElement) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    int result = ShortArrayDelete(&shortArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayDeleteExistingElement) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    int result = ShortArrayDelete(&shortArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayDeleteAtZeroLength) {
    int result = ShortArrayDeleteAt(&shortArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortArrayTests, ShortArrayDeleteAtExistingElement) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayDeleteAt(&shortArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, shortArray.length);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    ShortArrayAt(&shortArray, 2, &x);

    TEST_ASSERT_EQUAL(4, x);

    ShortArrayAt(&shortArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(ShortArrayTests, ShortArrayDeleteAtLessThanZeroIndex) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayDeleteAt(&shortArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, shortArray.length);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    ShortArrayAt(&shortArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    ShortArrayAt(&shortArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(ShortArrayTests, ShortArrayDeleteAtGreaterThanLengthIndex) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayDeleteAt(&shortArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortArrayTests, ShortArrayDeleteAtLessThanNegativeLengthIndex) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayDeleteAt(&shortArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortArrayTests, ShortArrayDropOneEmptyArray) {
    int result = ShortArrayDrop(&shortArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayDropManyEmptyArray) {
    int result = ShortArrayDrop(&shortArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayDropLessThanArrayLength) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayDrop(&shortArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, shortArray.length);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(4, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(ShortArrayTests, ShortArrayDropGreaterThanArrayLength) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayDrop(&shortArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortArray.length);
}
