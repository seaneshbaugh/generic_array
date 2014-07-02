#include "long_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(LongArrayTests);

LongArray longArray;
LongArray otherLongArray;

TEST_SETUP(LongArrayTests) {
    LongArrayInitialize(&longArray);

    LongArrayInitialize(&otherLongArray);
}

TEST_TEAR_DOWN(LongArrayTests) {
    LongArrayDeinitialize(&longArray);

    LongArrayDeinitialize(&otherLongArray);
}

TEST(LongArrayTests, LongArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, longArray.length);
}

TEST(LongArrayTests, LongArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longArray.capacity);
}

TEST(LongArrayTests, LongArrayPushOneElement) {
    int result = LongArrayPush(&longArray, 1L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, longArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longArray.capacity);
}

TEST(LongArrayTests, LongArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = LongArrayPush(&longArray, (long)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, longArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, longArray.capacity);
}

TEST(LongArrayTests, LongArrayAtZeroLength) {
    long x;

    int result = LongArrayAt(&longArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongArrayTests, LongArrayAtExistingElement) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    LongArrayPush(&longArray, 3L);

    LongArrayPush(&longArray, 4L);

    LongArrayPush(&longArray, 5L);

    long x;

    int result = LongArrayAt(&longArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3L, x);
}

TEST(LongArrayTests, LongArrayAtLessThanZeroIndex) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    LongArrayPush(&longArray, 3L);

    LongArrayPush(&longArray, 4L);

    LongArrayPush(&longArray, 5L);

    long x;

    int result = LongArrayAt(&longArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4L, x);
}

TEST(LongArrayTests, LongArrayAtGreaterThanLengthIndex) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    LongArrayPush(&longArray, 3L);

    LongArrayPush(&longArray, 4L);

    LongArrayPush(&longArray, 5L);

    long x;

    int result = LongArrayAt(&longArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongArrayTests, LongArrayAtLessThanNegativeLengthIndex) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    LongArrayPush(&longArray, 3L);

    LongArrayPush(&longArray, 4L);

    LongArrayPush(&longArray, 5L);

    long x;

    int result = LongArrayAt(&longArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongArrayTests, LongArrayClear) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    LongArrayPush(&longArray, 3L);

    LongArrayPush(&longArray, 4L);

    LongArrayPush(&longArray, 5L);

    int result = LongArrayClear(&longArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longArray.length);
}

TEST(LongArrayTests, LongArrayConcatEmptyArrays) {
    int result = LongArrayConcat(&longArray, &otherLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longArray.length);
}

TEST(LongArrayTests, LongArrayConcatEmptyArrayToNonEmptyArray) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    int result = LongArrayConcat(&longArray, &otherLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longArray.length);

    long x;

    LongArrayAt(&longArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongArrayAt(&longArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);
}

TEST(LongArrayTests, LongArrayConcatNonEmptyArrayToEmptyArray) {
    LongArrayPush(&otherLongArray, 1L);

    LongArrayPush(&otherLongArray, 2L);

    int result = LongArrayConcat(&longArray, &otherLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longArray.length);

    long x;

    LongArrayAt(&longArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongArrayAt(&longArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);
}

TEST(LongArrayTests, LongArrayConcatNonEmptyArrayToNonEmptyArray) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    LongArrayPush(&otherLongArray, 3L);

    LongArrayPush(&otherLongArray, 4L);

    int result = LongArrayConcat(&longArray, &otherLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longArray.length);

    long x;

    LongArrayAt(&longArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongArrayAt(&longArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);

    LongArrayAt(&longArray, 2, &x);

    TEST_ASSERT_EQUAL(3L, x);

    LongArrayAt(&longArray, 3, &x);

    TEST_ASSERT_EQUAL(4L, x);
}

TEST(LongArrayTests, LongArrayCountEmptyArray) {
    size_t result = LongArrayCount(&longArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(LongArrayTests, LongArrayCountNonEmptyArray) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    size_t result = LongArrayCount(&longArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(LongArrayTests, LongArrayDeleteFromEmptyArray) {
    int result = LongArrayDelete(&longArray, 1L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longArray.length);
}

TEST(LongArrayTests, LongArrayDeleteNonExistingElement) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    int result = LongArrayDelete(&longArray, 3L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longArray.length);
}

TEST(LongArrayTests, LongArrayDeleteExistingElement) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    int result = LongArrayDelete(&longArray, 2L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, longArray.length);
}

TEST(LongArrayTests, LongArrayDeleteAtZeroLength) {
    int result = LongArrayDeleteAt(&longArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongArrayTests, LongArrayDeleteAtExistingElement) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    LongArrayPush(&longArray, 3L);

    LongArrayPush(&longArray, 4L);

    LongArrayPush(&longArray, 5L);

    int result = LongArrayDeleteAt(&longArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longArray.length);

    long x;

    LongArrayAt(&longArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongArrayAt(&longArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);

    LongArrayAt(&longArray, 2, &x);

    TEST_ASSERT_EQUAL(4L, x);

    LongArrayAt(&longArray, 3, &x);

    TEST_ASSERT_EQUAL(5L, x);
}

TEST(LongArrayTests, LongArrayDeleteAtLessThanZeroIndex) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    LongArrayPush(&longArray, 3L);

    LongArrayPush(&longArray, 4L);

    LongArrayPush(&longArray, 5L);

    int result = LongArrayDeleteAt(&longArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longArray.length);

    long x;

    LongArrayAt(&longArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongArrayAt(&longArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);

    LongArrayAt(&longArray, 2, &x);

    TEST_ASSERT_EQUAL(3L, x);

    LongArrayAt(&longArray, 3, &x);

    TEST_ASSERT_EQUAL(5L, x);
}

TEST(LongArrayTests, LongArrayDeleteAtGreaterThanLengthIndex) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    LongArrayPush(&longArray, 3L);

    LongArrayPush(&longArray, 4L);

    LongArrayPush(&longArray, 5L);

    int result = LongArrayDeleteAt(&longArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongArrayTests, LongArrayDeleteAtLessThanNegativeLengthIndex) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    LongArrayPush(&longArray, 3L);

    LongArrayPush(&longArray, 4L);

    LongArrayPush(&longArray, 5L);

    int result = LongArrayDeleteAt(&longArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongArrayTests, LongArrayDropOneEmptyArray) {
    int result = LongArrayDrop(&longArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longArray.length);
}

TEST(LongArrayTests, LongArrayDropManyEmptyArray) {
    int result = LongArrayDrop(&longArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longArray.length);
}

TEST(LongArrayTests, LongArrayDropLessThanArrayLength) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    LongArrayPush(&longArray, 3L);

    LongArrayPush(&longArray, 4L);

    LongArrayPush(&longArray, 5L);

    int result = LongArrayDrop(&longArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longArray.length);

    long x;

    LongArrayAt(&longArray, 0, &x);

    TEST_ASSERT_EQUAL(4L, x);

    LongArrayAt(&longArray, 1, &x);

    TEST_ASSERT_EQUAL(5L, x);
}

TEST(LongArrayTests, LongArrayDropGreaterThanArrayLength) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    LongArrayPush(&longArray, 3L);

    LongArrayPush(&longArray, 4L);

    LongArrayPush(&longArray, 5L);

    int result = LongArrayDrop(&longArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longArray.length);
}

TEST(LongArrayTests, LongArrayEmptyArrayIsEmpty) {
    int result = LongArrayIsEmpty(&longArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(LongArrayTests, LongArrayNonEmptyArrayIsNotEmpty) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    LongArrayPush(&longArray, 3L);

    LongArrayPush(&longArray, 4L);

    LongArrayPush(&longArray, 5L);

    int result = LongArrayIsEmpty(&longArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(LongArrayTests, LongArrayPush) {
    LongArrayPush(&longArray, 1L);

    LongArrayPush(&longArray, 2L);

    LongArrayPush(&longArray, 3L);

    LongArrayPush(&longArray, 4L);

    LongArrayPush(&longArray, 5L);

    TEST_ASSERT_EQUAL(5, longArray.length);

    long x;

    int result = LongArrayAt(&longArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1L, x);

    result = LongArrayAt(&longArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2L, x);

    result = LongArrayAt(&longArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3L, x);

    result = LongArrayAt(&longArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4L, x);

    result = LongArrayAt(&longArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5L, x);
}
