#include "long_long_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(LongLongArrayTests);

LongLongArray longLongArray;
LongLongArray otherLongLongArray;

TEST_SETUP(LongLongArrayTests) {
    LongLongArrayInitialize(&longLongArray);

    LongLongArrayInitialize(&otherLongLongArray);
}

TEST_TEAR_DOWN(LongLongArrayTests) {
    LongLongArrayDeinitialize(&longLongArray);
}

TEST(LongLongArrayTests, LongLongArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, longLongArray.length);
}

TEST(LongLongArrayTests, LongLongArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longLongArray.capacity);
}

TEST(LongLongArrayTests, LongLongArrayPushOneElement) {
    int result = LongLongArrayPush(&longLongArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, longLongArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longLongArray.capacity);
}

TEST(LongLongArrayTests, LongLongArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = LongLongArrayPush(&longLongArray, (long long)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, longLongArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, longLongArray.capacity);
}

TEST(LongLongArrayTests, LongLongArrayAtZeroLength) {
    long long x;

    int result = LongLongArrayAt(&longLongArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongLongArrayTests, LongLongArrayAtExistingElement) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    long long x;

    int result = LongLongArrayAt(&longLongArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);
}

TEST(LongLongArrayTests, LongLongArrayAtLessThanZeroIndex) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    long long x;

    int result = LongLongArrayAt(&longLongArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(LongLongArrayTests, LongLongArrayAtGreaterThanLengthIndex) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    long long x;

    int result = LongLongArrayAt(&longLongArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongLongArrayTests, LongLongArrayAtLessThanNegativeLengthIndex) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    long long x;

    int result = LongLongArrayAt(&longLongArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongLongArrayTests, LongLongArrayClear) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    int result = LongLongArrayClear(&longLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longLongArray.length);
}

TEST(LongLongArrayTests, LongLongArrayConcatEmptyArrays) {
    int result = LongLongArrayConcat(&longLongArray, &otherLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longLongArray.length);
}

TEST(LongLongArrayTests, LongLongArrayConcatEmptyArrayToNonEmptyArray) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    int result = LongLongArrayConcat(&longLongArray, &otherLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longLongArray.length);

    long long x;

    LongLongArrayAt(&longLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongArrayAt(&longLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(LongLongArrayTests, LongLongArrayConcatNonEmptyArrayToEmptyArray) {
    LongLongArrayPush(&otherLongLongArray, 1);

    LongLongArrayPush(&otherLongLongArray, 2);

    int result = LongLongArrayConcat(&longLongArray, &otherLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longLongArray.length);

    long long x;

    LongLongArrayAt(&longLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongArrayAt(&longLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(LongLongArrayTests, LongLongArrayConcatNonEmptyArrayToNonEmptyArray) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&otherLongLongArray, 3);

    LongLongArrayPush(&otherLongLongArray, 4);

    int result = LongLongArrayConcat(&longLongArray, &otherLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longLongArray.length);

    long long x;

    LongLongArrayAt(&longLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongArrayAt(&longLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongLongArrayAt(&longLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongLongArrayAt(&longLongArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(LongLongArrayTests, LongLongArrayCountEmptyArray) {
    size_t result = LongLongArrayCount(&longLongArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(LongLongArrayTests, LongLongArrayCountNonEmptyArray) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    size_t result = LongLongArrayCount(&longLongArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(LongLongArrayTests, LongLongArrayDeleteFromEmptyArray) {
    int result = LongLongArrayDelete(&longLongArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longLongArray.length);
}

TEST(LongLongArrayTests, LongLongArrayDeleteNonExistingElement) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    int result = LongLongArrayDelete(&longLongArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longLongArray.length);
}

TEST(LongLongArrayTests, LongLongArrayDeleteExistingElement) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    int result = LongLongArrayDelete(&longLongArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, longLongArray.length);
}

TEST(LongLongArrayTests, LongLongArrayDeleteAtZeroLength) {
    int result = LongLongArrayDeleteAt(&longLongArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongLongArrayTests, LongLongArrayDeleteAtExistingElement) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    int result = LongLongArrayDeleteAt(&longLongArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longLongArray.length);

    long long x;

    LongLongArrayAt(&longLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongArrayAt(&longLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongLongArrayAt(&longLongArray, 2, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongLongArrayAt(&longLongArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongLongArrayTests, LongLongArrayDeleteAtLessThanZeroIndex) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    int result = LongLongArrayDeleteAt(&longLongArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longLongArray.length);

    long long x;

    LongLongArrayAt(&longLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongArrayAt(&longLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongLongArrayAt(&longLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongLongArrayAt(&longLongArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongLongArrayTests, LongLongArrayDeleteAtGreaterThanLengthIndex) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    int result = LongLongArrayDeleteAt(&longLongArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongLongArrayTests, LongLongArrayDeleteAtLessThanNegativeLengthIndex) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    int result = LongLongArrayDeleteAt(&longLongArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongLongArrayTests, LongLongArrayDropOneEmptyArray) {
    int result = LongLongArrayDrop(&longLongArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longLongArray.length);
}

TEST(LongLongArrayTests, LongLongArrayDropManyEmptyArray) {
    int result = LongLongArrayDrop(&longLongArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longLongArray.length);
}

TEST(LongLongArrayTests, LongLongArrayDropLessThanArrayLength) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    int result = LongLongArrayDrop(&longLongArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longLongArray.length);

    long long x;

    LongLongArrayAt(&longLongArray, 0, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongLongArrayAt(&longLongArray, 1, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongLongArrayTests, LongLongArrayDropGreaterThanArrayLength) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    int result = LongLongArrayDrop(&longLongArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longLongArray.length);
}
