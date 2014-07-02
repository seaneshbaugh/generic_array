#include "long_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(LongIntArrayTests);

LongIntArray longIntArray;
LongIntArray otherLongIntArray;

TEST_SETUP(LongIntArrayTests) {
    LongIntArrayInitialize(&longIntArray);

    LongIntArrayInitialize(&otherLongIntArray);
}

TEST_TEAR_DOWN(LongIntArrayTests) {
    LongIntArrayDeinitialize(&longIntArray);
}

TEST(LongIntArrayTests, LongIntArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, longIntArray.length);
}

TEST(LongIntArrayTests, LongIntArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longIntArray.capacity);
}

TEST(LongIntArrayTests, LongIntArrayPushOneElement) {
    int result = LongIntArrayPush(&longIntArray, 1L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, longIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longIntArray.capacity);
}

TEST(LongIntArrayTests, LongIntArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = LongIntArrayPush(&longIntArray, (long int)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, longIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, longIntArray.capacity);
}

TEST(LongIntArrayTests, LongIntArrayAtZeroLength) {
    long int x;

    int result = LongIntArrayAt(&longIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongIntArrayTests, LongIntArrayAtExistingElement) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    long int x;

    int result = LongIntArrayAt(&longIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);
}

TEST(LongIntArrayTests, LongIntArrayAtLessThanZeroIndex) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    long int x;

    int result = LongIntArrayAt(&longIntArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(LongIntArrayTests, LongIntArrayAtGreaterThanLengthIndex) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    long int x;

    int result = LongIntArrayAt(&longIntArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongIntArrayTests, LongIntArrayAtLessThanNegativeLengthIndex) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    long int x;

    int result = LongIntArrayAt(&longIntArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongIntArrayTests, LongIntArrayClear) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    int result = LongIntArrayClear(&longIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longIntArray.length);
}

TEST(LongIntArrayTests, LongIntArrayConcatEmptyArrays) {
    int result = LongIntArrayConcat(&longIntArray, &otherLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longIntArray.length);
}

TEST(LongIntArrayTests, LongIntArrayConcatEmptyArrayToNonEmptyArray) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    int result = LongIntArrayConcat(&longIntArray, &otherLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longIntArray.length);

    long int x;

    LongIntArrayAt(&longIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongIntArrayAt(&longIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(LongIntArrayTests, LongIntArrayConcatNonEmptyArrayToEmptyArray) {
    LongIntArrayPush(&otherLongIntArray, 1L);

    LongIntArrayPush(&otherLongIntArray, 2);

    int result = LongIntArrayConcat(&longIntArray, &otherLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longIntArray.length);

    long int x;

    LongIntArrayAt(&longIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongIntArrayAt(&longIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(LongIntArrayTests, LongIntArrayConcatNonEmptyArrayToNonEmptyArray) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&otherLongIntArray, 3);

    LongIntArrayPush(&otherLongIntArray, 4);

    int result = LongIntArrayConcat(&longIntArray, &otherLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longIntArray.length);

    long int x;

    LongIntArrayAt(&longIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongIntArrayAt(&longIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongIntArrayAt(&longIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongIntArrayAt(&longIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(LongIntArrayTests, LongIntArrayCountEmptyArray) {
    size_t result = LongIntArrayCount(&longIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(LongIntArrayTests, LongIntArrayCountNonEmptyArray) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    size_t result = LongIntArrayCount(&longIntArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(LongIntArrayTests, LongIntArrayDeleteFromEmptyArray) {
    int result = LongIntArrayDelete(&longIntArray, 1L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longIntArray.length);
}

TEST(LongIntArrayTests, LongIntArrayDeleteNonExistingElement) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    int result = LongIntArrayDelete(&longIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longIntArray.length);
}

TEST(LongIntArrayTests, LongIntArrayDeleteExistingElement) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    int result = LongIntArrayDelete(&longIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, longIntArray.length);
}

TEST(LongIntArrayTests, LongIntArrayDeleteAtZeroLength) {
    int result = LongIntArrayDeleteAt(&longIntArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongIntArrayTests, LongIntArrayDeleteAtExistingElement) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    int result = LongIntArrayDeleteAt(&longIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longIntArray.length);

    long int x;

    LongIntArrayAt(&longIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongIntArrayAt(&longIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongIntArrayAt(&longIntArray, 2, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongIntArrayAt(&longIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongIntArrayTests, LongIntArrayDeleteAtLessThanZeroIndex) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    int result = LongIntArrayDeleteAt(&longIntArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longIntArray.length);

    long int x;

    LongIntArrayAt(&longIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongIntArrayAt(&longIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongIntArrayAt(&longIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongIntArrayAt(&longIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongIntArrayTests, LongIntArrayDeleteAtGreaterThanLengthIndex) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    int result = LongIntArrayDeleteAt(&longIntArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongIntArrayTests, LongIntArrayDeleteAtLessThanNegativeLengthIndex) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    int result = LongIntArrayDeleteAt(&longIntArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongIntArrayTests, LongIntArrayDropOneEmptyArray) {
    int result = LongIntArrayDrop(&longIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longIntArray.length);
}

TEST(LongIntArrayTests, LongIntArrayDropManyEmptyArray) {
    int result = LongIntArrayDrop(&longIntArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longIntArray.length);
}

TEST(LongIntArrayTests, LongIntArrayDropLessThanArrayLength) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    int result = LongIntArrayDrop(&longIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longIntArray.length);

    long int x;

    LongIntArrayAt(&longIntArray, 0, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongIntArrayAt(&longIntArray, 1, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongIntArrayTests, LongIntArrayDropGreaterThanArrayLength) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    int result = LongIntArrayDrop(&longIntArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longIntArray.length);
}
