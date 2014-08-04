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

    LongLongArrayDeinitialize(&otherLongLongArray);
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

TEST(LongLongArrayTests, LongLongArrayEmptyArrayIsEmpty) {
    int result = LongLongArrayIsEmpty(&longLongArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(LongLongArrayTests, LongLongArrayNonEmptyArrayIsNotEmpty) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    int result = LongLongArrayIsEmpty(&longLongArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(LongLongArrayTests, LongLongArrayPush) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    TEST_ASSERT_EQUAL(5, longLongArray.length);

    long long x;

    int result = LongLongArrayAt(&longLongArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, x);

    result = LongLongArrayAt(&longLongArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, x);

    result = LongLongArrayAt(&longLongArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);

    result = LongLongArrayAt(&longLongArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);

    result = LongLongArrayAt(&longLongArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongLongArrayTests, LongLongArrayMultipleElementArrayToString) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    char* asString;

    int result = LongLongArrayToString(&longLongArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[1, 2, 3, 4, 5]", asString);

    free(asString);
}

int LongLongAscendingCompare(const void *a, const void *b) {
    __GENERIC_ARRAY_TYPE__ f = *((__GENERIC_ARRAY_TYPE__*)a);
    __GENERIC_ARRAY_TYPE__ s = *((__GENERIC_ARRAY_TYPE__*)b);

    if (GENERIC_ARRAY_VALUES_GREATER_THAN(f, s)) {
        return 1;
    }

    if (GENERIC_ARRAY_VALUES_LESS_THAN(f, s)) {
        return -1;
    }

    return 0;
}

int LongLongDescendingCompare(const void *a, const void *b) {
    __GENERIC_ARRAY_TYPE__ f = *((__GENERIC_ARRAY_TYPE__*)a);
    __GENERIC_ARRAY_TYPE__ s = *((__GENERIC_ARRAY_TYPE__*)b);

    if (GENERIC_ARRAY_VALUES_LESS_THAN(f, s)) {
        return 1;
    }

    if (GENERIC_ARRAY_VALUES_GREATER_THAN(f, s)) {
        return -1;
    }

    return 0;
}

TEST(LongLongArrayTests, LongLongArraySortEmptyArray) {
    LongLongArraySort(&longLongArray, LongLongAscendingCompare);

    TEST_ASSERT_EQUAL(0, LongLongArrayCount(&longLongArray));
}

TEST(LongLongArrayTests, LongLongArraySortAscending) {
    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    LongLongArrayPush(&longLongArray, 1);

    LongLongArraySort(&longLongArray, LongLongAscendingCompare);

    long long x;

    LongLongArrayAt(&longLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongArrayAt(&longLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongLongArrayAt(&longLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongLongArrayAt(&longLongArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongLongArrayAt(&longLongArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongLongArrayTests, LongLongArraySortDescending) {
    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    LongLongArrayPush(&longLongArray, 1);

    LongLongArraySort(&longLongArray, LongLongDescendingCompare);

    long long x;

    LongLongArrayAt(&longLongArray, 0, &x);

    TEST_ASSERT_EQUAL(5, x);

    LongLongArrayAt(&longLongArray, 1, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongLongArrayAt(&longLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongLongArrayAt(&longLongArray, 3, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongLongArrayAt(&longLongArray, 4, &x);

    TEST_ASSERT_EQUAL(1, x);
}

TEST(LongLongArrayTests, LongLongArrayOverlapEmptyArrays) {
    int result = LongLongArrayOverlap(&longLongArray, &otherLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, LongLongArrayCount(&longLongArray));

    TEST_ASSERT_EQUAL(0, LongLongArrayCount(&otherLongLongArray));
}

TEST(LongLongArrayTests, LongLongArrayOverlapNonEmptyArrayWithEmptyArray) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 2);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    int result = LongLongArrayOverlap(&longLongArray, &otherLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, LongLongArrayCount(&longLongArray));

    TEST_ASSERT_EQUAL(0, LongLongArrayCount(&otherLongLongArray));

    LongLongArraySort(&longLongArray, LongLongAscendingCompare);

    long long x;

    LongLongArrayAt(&longLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongArrayAt(&longLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongLongArrayAt(&longLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongLongArrayAt(&longLongArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongLongArrayAt(&longLongArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongLongArrayTests, LongLongArrayOverlapEmptyArrayWithNonEmptyArray) {
    LongLongArrayPush(&otherLongLongArray, 1);

    LongLongArrayPush(&otherLongLongArray, 2);

    LongLongArrayPush(&otherLongLongArray, 3);

    LongLongArrayPush(&otherLongLongArray, 4);

    LongLongArrayPush(&otherLongLongArray, 5);

    int result = LongLongArrayOverlap(&longLongArray, &otherLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, LongLongArrayCount(&longLongArray));

    TEST_ASSERT_EQUAL(5, LongLongArrayCount(&otherLongLongArray));

    LongLongArraySort(&longLongArray, LongLongAscendingCompare);

    long long x;

    LongLongArrayAt(&longLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongArrayAt(&longLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongLongArrayAt(&longLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongLongArrayAt(&longLongArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongLongArrayAt(&longLongArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongLongArrayTests, LongLongArrayOverlapNonEmptyArrays) {
    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 1);

    LongLongArrayPush(&longLongArray, 3);

    LongLongArrayPush(&longLongArray, 4);

    LongLongArrayPush(&longLongArray, 5);

    LongLongArrayPush(&longLongArray, 5);

    LongLongArrayPush(&otherLongLongArray, 1);

    LongLongArrayPush(&otherLongLongArray, 2);

    LongLongArrayPush(&otherLongLongArray, 3);

    LongLongArrayPush(&otherLongLongArray, 4);

    LongLongArrayPush(&otherLongLongArray, 4);

    LongLongArrayPush(&otherLongLongArray, 5);

    LongLongArrayPush(&otherLongLongArray, 5);

    LongLongArrayPush(&otherLongLongArray, 5);

    int result = LongLongArrayOverlap(&longLongArray, &otherLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(10, LongLongArrayCount(&longLongArray));

    TEST_ASSERT_EQUAL(8, LongLongArrayCount(&otherLongLongArray));

    LongLongArraySort(&longLongArray, LongLongAscendingCompare);

    long long x;

    LongLongArrayAt(&longLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongArrayAt(&longLongArray, 1, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongArrayAt(&longLongArray, 2, &x);

    TEST_ASSERT_EQUAL(1, x);

    LongLongArrayAt(&longLongArray, 3, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongLongArrayAt(&longLongArray, 4, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongLongArrayAt(&longLongArray, 5, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongLongArrayAt(&longLongArray, 6, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongLongArrayAt(&longLongArray, 7, &x);

    TEST_ASSERT_EQUAL(5, x);

    LongLongArrayAt(&longLongArray, 8, &x);

    TEST_ASSERT_EQUAL(5, x);

    LongLongArrayAt(&longLongArray, 9, &x);

    TEST_ASSERT_EQUAL(5, x);
}
