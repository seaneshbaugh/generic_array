#include "long_double_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(LongDoubleArrayTests);

LongDoubleArray longDoubleArray;
LongDoubleArray otherLongDoubleArray;

TEST_SETUP(LongDoubleArrayTests) {
    LongDoubleArrayInitialize(&longDoubleArray);

    LongDoubleArrayInitialize(&otherLongDoubleArray);
}

TEST_TEAR_DOWN(LongDoubleArrayTests) {
    LongDoubleArrayDeinitialize(&longDoubleArray);

    LongDoubleArrayDeinitialize(&otherLongDoubleArray);
}

TEST(LongDoubleArrayTests, LongDoubleArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, longDoubleArray.length);
}

TEST(LongDoubleArrayTests, LongDoubleArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longDoubleArray.capacity);
}

TEST(LongDoubleArrayTests, LongDoubleArrayPushOneElement) {
    int result = LongDoubleArrayPush(&longDoubleArray, 1.0L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, longDoubleArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longDoubleArray.capacity);
}

TEST(LongDoubleArrayTests, LongDoubleArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = LongDoubleArrayPush(&longDoubleArray, (long double)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, longDoubleArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, longDoubleArray.capacity);
}

TEST(LongDoubleArrayTests, LongDoubleArrayAtZeroLength) {
    long double x;

    int result = LongDoubleArrayAt(&longDoubleArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongDoubleArrayTests, LongDoubleArrayAtExistingElement) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    long double x;

    int result = LongDoubleArrayAt(&longDoubleArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3.0L, x);
}

TEST(LongDoubleArrayTests, LongDoubleArrayAtLessThanZeroIndex) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    long double x;

    int result = LongDoubleArrayAt(&longDoubleArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4.0L, x);
}

TEST(LongDoubleArrayTests, LongDoubleArrayAtGreaterThanLengthIndex) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    long double x;

    int result = LongDoubleArrayAt(&longDoubleArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongDoubleArrayTests, LongDoubleArrayAtLessThanNegativeLengthIndex) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    long double x;

    int result = LongDoubleArrayAt(&longDoubleArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongDoubleArrayTests, LongDoubleArrayClear) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    int result = LongDoubleArrayClear(&longDoubleArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longDoubleArray.length);
}

TEST(LongDoubleArrayTests, LongDoubleArrayConcatEmptyArrays) {
    int result = LongDoubleArrayConcat(&longDoubleArray, &otherLongDoubleArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longDoubleArray.length);
}

TEST(LongDoubleArrayTests, LongDoubleArrayConcatEmptyArrayToNonEmptyArray) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    int result = LongDoubleArrayConcat(&longDoubleArray, &otherLongDoubleArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longDoubleArray.length);

    long double x;

    LongDoubleArrayAt(&longDoubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0L, x);
}

TEST(LongDoubleArrayTests, LongDoubleArrayConcatNonEmptyArrayToEmptyArray) {
    LongDoubleArrayPush(&otherLongDoubleArray, 1.0L);

    LongDoubleArrayPush(&otherLongDoubleArray, 2.0L);

    int result = LongDoubleArrayConcat(&longDoubleArray, &otherLongDoubleArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longDoubleArray.length);

    long double x;

    LongDoubleArrayAt(&longDoubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0L, x);
}

TEST(LongDoubleArrayTests, LongDoubleArrayConcatNonEmptyArrayToNonEmptyArray) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&otherLongDoubleArray, 3.0L);

    LongDoubleArrayPush(&otherLongDoubleArray, 4.0L);

    int result = LongDoubleArrayConcat(&longDoubleArray, &otherLongDoubleArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longDoubleArray.length);

    long double x;

    LongDoubleArrayAt(&longDoubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 2, &x);

    TEST_ASSERT_EQUAL(3.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 3, &x);

    TEST_ASSERT_EQUAL(4.0L, x);
}

TEST(LongDoubleArrayTests, LongDoubleArrayCountEmptyArray) {
    size_t result = LongDoubleArrayCount(&longDoubleArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(LongDoubleArrayTests, LongDoubleArrayCountNonEmptyArray) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    size_t result = LongDoubleArrayCount(&longDoubleArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(LongDoubleArrayTests, LongDoubleArrayDeleteFromEmptyArray) {
    int result = LongDoubleArrayDelete(&longDoubleArray, 1.0L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longDoubleArray.length);
}

TEST(LongDoubleArrayTests, LongDoubleArrayDeleteNonExistingElement) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    int result = LongDoubleArrayDelete(&longDoubleArray, 3.0L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longDoubleArray.length);
}

TEST(LongDoubleArrayTests, LongDoubleArrayDeleteExistingElement) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    int result = LongDoubleArrayDelete(&longDoubleArray, 2.0L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, longDoubleArray.length);
}

TEST(LongDoubleArrayTests, LongDoubleArrayDeleteAtZeroLength) {
    int result = LongDoubleArrayDeleteAt(&longDoubleArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongDoubleArrayTests, LongDoubleArrayDeleteAtExistingElement) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    int result = LongDoubleArrayDeleteAt(&longDoubleArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longDoubleArray.length);

    long double x;

    LongDoubleArrayAt(&longDoubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 2, &x);

    TEST_ASSERT_EQUAL(4.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 3, &x);

    TEST_ASSERT_EQUAL(5.0L, x);
}

TEST(LongDoubleArrayTests, LongDoubleArrayDeleteAtLessThanZeroIndex) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    int result = LongDoubleArrayDeleteAt(&longDoubleArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, longDoubleArray.length);

    long double x;

    LongDoubleArrayAt(&longDoubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 2, &x);

    TEST_ASSERT_EQUAL(3.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 3, &x);

    TEST_ASSERT_EQUAL(5.0L, x);
}

TEST(LongDoubleArrayTests, LongDoubleArrayDeleteAtGreaterThanLengthIndex) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    int result = LongDoubleArrayDeleteAt(&longDoubleArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongDoubleArrayTests, LongDoubleArrayDeleteAtLessThanNegativeLengthIndex) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    int result = LongDoubleArrayDeleteAt(&longDoubleArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongDoubleArrayTests, LongDoubleArrayDropOneEmptyArray) {
    int result = LongDoubleArrayDrop(&longDoubleArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longDoubleArray.length);
}

TEST(LongDoubleArrayTests, LongDoubleArrayDropManyEmptyArray) {
    int result = LongDoubleArrayDrop(&longDoubleArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longDoubleArray.length);
}

TEST(LongDoubleArrayTests, LongDoubleArrayDropLessThanArrayLength) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    int result = LongDoubleArrayDrop(&longDoubleArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, longDoubleArray.length);

    long double x;

    LongDoubleArrayAt(&longDoubleArray, 0, &x);

    TEST_ASSERT_EQUAL(4.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 1, &x);

    TEST_ASSERT_EQUAL(5.0L, x);
}

TEST(LongDoubleArrayTests, LongDoubleArrayDropGreaterThanArrayLength) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    int result = LongDoubleArrayDrop(&longDoubleArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, longDoubleArray.length);
}

TEST(LongDoubleArrayTests, LongDoubleArrayEmptyArrayIsEmpty) {
    int result = LongDoubleArrayIsEmpty(&longDoubleArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(LongDoubleArrayTests, LongDoubleArrayNonEmptyArrayIsNotEmpty) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    int result = LongDoubleArrayIsEmpty(&longDoubleArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(LongDoubleArrayTests, LongDoubleArrayPush) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    TEST_ASSERT_EQUAL(5, longDoubleArray.length);

    long double x;

    int result = LongDoubleArrayAt(&longDoubleArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1.0L, x);

    result = LongDoubleArrayAt(&longDoubleArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2.0L, x);

    result = LongDoubleArrayAt(&longDoubleArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3.0L, x);

    result = LongDoubleArrayAt(&longDoubleArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4.0L, x);

    result = LongDoubleArrayAt(&longDoubleArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5.0L, x);
}

TEST(LongDoubleArrayTests, LongDoubleArrayMultipleElementArrayToString) {
    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    char* asString;

    int result = LongDoubleArrayToString(&longDoubleArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[1.000000, 2.000000, 3.000000, 4.000000, 5.000000]", asString);

    free(asString);
}

int LongDoubleAscendingCompare(const void *a, const void *b) {
    __GENERIC_ARRAY_TYPE__ f = *((__GENERIC_ARRAY_TYPE__*)a);
    __GENERIC_ARRAY_TYPE__ s = *((__GENERIC_ARRAY_TYPE__*)b);

    if (GENERIC_ARRAY_VALUES_GREATER_THAN(f, s)) {
      return  1;
    }

    if (GENERIC_ARRAY_VALUES_LESS_THAN(f, s)) {
      return -1;
    }

    return 0;
}

int LongDoubleDescendingCompare(const void *a, const void *b) {
    __GENERIC_ARRAY_TYPE__ f = *((__GENERIC_ARRAY_TYPE__*)a);
    __GENERIC_ARRAY_TYPE__ s = *((__GENERIC_ARRAY_TYPE__*)b);

    if (GENERIC_ARRAY_VALUES_LESS_THAN(f, s)) {
      return  1;
    }

    if (GENERIC_ARRAY_VALUES_GREATER_THAN(f, s)) {
      return -1;
    }

    return 0;
}

TEST(LongDoubleArrayTests, LongDoubleArraySortAscending) {
    LongDoubleArrayPush(&longDoubleArray, 3.0L);

    LongDoubleArrayPush(&longDoubleArray, 2.0L);

    LongDoubleArrayPush(&longDoubleArray, 4.0L);

    LongDoubleArrayPush(&longDoubleArray, 5.0L);

    LongDoubleArrayPush(&longDoubleArray, 1.0L);

    LongDoubleArraySort(&longDoubleArray, LongDoubleAscendingCompare);

    long double x;

    LongDoubleArrayAt(&longDoubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 2, &x);

    TEST_ASSERT_EQUAL(3.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 3, &x);

    TEST_ASSERT_EQUAL(4.0L, x);

    LongDoubleArrayAt(&longDoubleArray, 4, &x);

    TEST_ASSERT_EQUAL(5.0L, x);
}
