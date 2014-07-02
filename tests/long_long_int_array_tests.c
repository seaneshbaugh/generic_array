#include "long_long_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(LongLongIntArrayTests);

LongLongIntArray longLongIntArray;
LongLongIntArray otherLongLongIntArray;

TEST_SETUP(LongLongIntArrayTests) {
    LongLongIntArrayInitialize(&longLongIntArray);

    LongLongIntArrayInitialize(&otherLongLongIntArray);
}

TEST_TEAR_DOWN(LongLongIntArrayTests) {
    LongLongIntArrayDeinitialize(&longLongIntArray);

    LongLongIntArrayDeinitialize(&otherLongLongIntArray);
}

TEST(LongLongIntArrayTests, LongLongIntArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, longLongIntArray.length);
}

TEST(LongLongIntArrayTests, LongLongIntArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longLongIntArray.capacity);
}

TEST(LongLongIntArrayTests, LongLongIntArrayPushOneElement) {
    int result = LongLongIntArrayPush(&longLongIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, longLongIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longLongIntArray.capacity);
}

TEST(LongLongIntArrayTests, LongLongIntArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = LongLongIntArrayPush(&longLongIntArray, (long long int)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, longLongIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, longLongIntArray.capacity);
}

TEST(LongLongIntArrayTests, LongLongIntArrayAtZeroLength) {
    long long int x;

    int result = LongLongIntArrayAt(&longLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongLongIntArrayTests, LongLongIntArrayAtExistingElement) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    LongLongIntArrayPush(&longLongIntArray, 3);

    LongLongIntArrayPush(&longLongIntArray, 4);

    LongLongIntArrayPush(&longLongIntArray, 5);

    long long int x;

    int result = LongLongIntArrayAt(&longLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);
}

TEST(LongLongIntArrayTests, LongLongIntArrayAtLessThanZeroIndex) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    LongLongIntArrayPush(&longLongIntArray, 3);

    LongLongIntArrayPush(&longLongIntArray, 4);

    LongLongIntArrayPush(&longLongIntArray, 5);

    long long int x;

    int result = LongLongIntArrayAt(&longLongIntArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(LongLongIntArrayTests, LongLongIntArrayAtGreaterThanLengthIndex) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    LongLongIntArrayPush(&longLongIntArray, 3);

    LongLongIntArrayPush(&longLongIntArray, 4);

    LongLongIntArrayPush(&longLongIntArray, 5);

    long long int x;

    int result = LongLongIntArrayAt(&longLongIntArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongLongIntArrayTests, LongLongIntArrayAtLessThanNegativeLengthIndex) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    LongLongIntArrayPush(&longLongIntArray, 3);

    LongLongIntArrayPush(&longLongIntArray, 4);

    LongLongIntArrayPush(&longLongIntArray, 5);

    long long int x;

    int result = LongLongIntArrayAt(&longLongIntArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongLongIntArrayTests, LongLongIntArrayClear) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    LongLongIntArrayPush(&longLongIntArray, 3);

    LongLongIntArrayPush(&longLongIntArray, 4);

    LongLongIntArrayPush(&longLongIntArray, 5);

    int result = LongLongIntArrayClear(&longLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longLongIntArray.length);
}

TEST(LongLongIntArrayTests, LongLongIntArrayConcatEmptyArrays) {
    int result = LongLongIntArrayConcat(&longLongIntArray, &otherLongLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longLongIntArray.length);
}

TEST(LongLongIntArrayTests, LongLongIntArrayConcatEmptyArrayToNonEmptyArray) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    int result = LongLongIntArrayConcat(&longLongIntArray, &otherLongLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longLongIntArray.length);

    long long int x;

    LongLongIntArrayAt(&longLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongIntArrayAt(&longLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(LongLongIntArrayTests, LongLongIntArrayConcatNonEmptyArrayToEmptyArray) {
    LongLongIntArrayPush(&otherLongLongIntArray, 1);

    LongLongIntArrayPush(&otherLongLongIntArray, 2);

    int result = LongLongIntArrayConcat(&longLongIntArray, &otherLongLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longLongIntArray.length);

    long long int x;

    LongLongIntArrayAt(&longLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongIntArrayAt(&longLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(LongLongIntArrayTests, LongLongIntArrayConcatNonEmptyArrayToNonEmptyArray) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    LongLongIntArrayPush(&otherLongLongIntArray, 3);

    LongLongIntArrayPush(&otherLongLongIntArray, 4);

    int result = LongLongIntArrayConcat(&longLongIntArray, &otherLongLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longLongIntArray.length);

    long long int x;

    LongLongIntArrayAt(&longLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongIntArrayAt(&longLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongLongIntArrayAt(&longLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongLongIntArrayAt(&longLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(LongLongIntArrayTests, LongLongIntArrayCountEmptyArray) {
    size_t result = LongLongIntArrayCount(&longLongIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(LongLongIntArrayTests, LongLongIntArrayCountNonEmptyArray) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    size_t result = LongLongIntArrayCount(&longLongIntArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(LongLongIntArrayTests, LongLongIntArrayDeleteFromEmptyArray) {
    int result = LongLongIntArrayDelete(&longLongIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longLongIntArray.length);
}

TEST(LongLongIntArrayTests, LongLongIntArrayDeleteNonExistingElement) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    int result = LongLongIntArrayDelete(&longLongIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longLongIntArray.length);
}

TEST(LongLongIntArrayTests, LongLongIntArrayDeleteExistingElement) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    int result = LongLongIntArrayDelete(&longLongIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, longLongIntArray.length);
}

TEST(LongLongIntArrayTests, LongLongIntArrayDeleteAtZeroLength) {
    int result = LongLongIntArrayDeleteAt(&longLongIntArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongLongIntArrayTests, LongLongIntArrayDeleteAtExistingElement) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    LongLongIntArrayPush(&longLongIntArray, 3);

    LongLongIntArrayPush(&longLongIntArray, 4);

    LongLongIntArrayPush(&longLongIntArray, 5);

    int result = LongLongIntArrayDeleteAt(&longLongIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longLongIntArray.length);

    long long int x;

    LongLongIntArrayAt(&longLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongIntArrayAt(&longLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongLongIntArrayAt(&longLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongLongIntArrayAt(&longLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongLongIntArrayTests, LongLongIntArrayDeleteAtLessThanZeroIndex) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    LongLongIntArrayPush(&longLongIntArray, 3);

    LongLongIntArrayPush(&longLongIntArray, 4);

    LongLongIntArrayPush(&longLongIntArray, 5);

    int result = LongLongIntArrayDeleteAt(&longLongIntArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longLongIntArray.length);

    long long int x;

    LongLongIntArrayAt(&longLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongIntArrayAt(&longLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongLongIntArrayAt(&longLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongLongIntArrayAt(&longLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongLongIntArrayTests, LongLongIntArrayDeleteAtGreaterThanLengthIndex) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    LongLongIntArrayPush(&longLongIntArray, 3);

    LongLongIntArrayPush(&longLongIntArray, 4);

    LongLongIntArrayPush(&longLongIntArray, 5);

    int result = LongLongIntArrayDeleteAt(&longLongIntArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongLongIntArrayTests, LongLongIntArrayDeleteAtLessThanNegativeLengthIndex) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    LongLongIntArrayPush(&longLongIntArray, 3);

    LongLongIntArrayPush(&longLongIntArray, 4);

    LongLongIntArrayPush(&longLongIntArray, 5);

    int result = LongLongIntArrayDeleteAt(&longLongIntArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongLongIntArrayTests, LongLongIntArrayDropOneEmptyArray) {
    int result = LongLongIntArrayDrop(&longLongIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longLongIntArray.length);
}

TEST(LongLongIntArrayTests, LongLongIntArrayDropManyEmptyArray) {
    int result = LongLongIntArrayDrop(&longLongIntArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longLongIntArray.length);
}

TEST(LongLongIntArrayTests, LongLongIntArrayDropLessThanArrayLength) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    LongLongIntArrayPush(&longLongIntArray, 3);

    LongLongIntArrayPush(&longLongIntArray, 4);

    LongLongIntArrayPush(&longLongIntArray, 5);

    int result = LongLongIntArrayDrop(&longLongIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longLongIntArray.length);

    long long int x;

    LongLongIntArrayAt(&longLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongLongIntArrayAt(&longLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongLongIntArrayTests, LongLongIntArrayDropGreaterThanArrayLength) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    LongLongIntArrayPush(&longLongIntArray, 3);

    LongLongIntArrayPush(&longLongIntArray, 4);

    LongLongIntArrayPush(&longLongIntArray, 5);

    int result = LongLongIntArrayDrop(&longLongIntArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longLongIntArray.length);
}

TEST(LongLongIntArrayTests, LongLongIntArrayEmptyArrayIsEmpty) {
    int result = LongLongIntArrayIsEmpty(&longLongIntArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(LongLongIntArrayTests, LongLongIntArrayNonEmptyArrayIsNotEmpty) {
    LongLongIntArrayPush(&longLongIntArray, 1);

    LongLongIntArrayPush(&longLongIntArray, 2);

    LongLongIntArrayPush(&longLongIntArray, 3);

    LongLongIntArrayPush(&longLongIntArray, 4);

    LongLongIntArrayPush(&longLongIntArray, 5);

    int result = LongLongIntArrayIsEmpty(&longLongIntArray);

    TEST_ASSERT_EQUAL(0, result);
}
