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

    LongIntArrayDeinitialize(&otherLongIntArray);
}

TEST(LongIntArrayTests, LongIntArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, longIntArray.length);
}

TEST(LongIntArrayTests, LongIntArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longIntArray.capacity);
}

TEST(LongIntArrayTests, LongIntArrayInitializeFromEmptyPointer) {
    long int values[] = { };

    int result = LongIntArrayInitializeFromPointer(&longIntArray, values, 0);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, LongIntArrayCount(&longIntArray));
}

TEST(LongIntArrayTests, LongIntArrayInitializeFromPointer) {
    long int values[5] = { 1L, 2, 3, 4, 5 };

    int result = LongIntArrayInitializeFromPointer(&longIntArray, values, 5);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, LongIntArrayCount(&longIntArray));
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

TEST(LongIntArrayTests, LongIntArrayEmptyArrayIsEmpty) {
    int result = LongIntArrayIsEmpty(&longIntArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(LongIntArrayTests, LongIntArrayNonEmptyArrayIsNotEmpty) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    int result = LongIntArrayIsEmpty(&longIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(LongIntArrayTests, LongIntArrayPush) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    TEST_ASSERT_EQUAL(5, longIntArray.length);

    long int x;

    int result = LongIntArrayAt(&longIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1L, x);

    result = LongIntArrayAt(&longIntArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, x);

    result = LongIntArrayAt(&longIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);

    result = LongIntArrayAt(&longIntArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);

    result = LongIntArrayAt(&longIntArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongIntArrayTests, LongIntArrayMultipleElementArrayToString) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    char* asString;

    int result = LongIntArrayToString(&longIntArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[1, 2, 3, 4, 5]", asString);

    free(asString);
}

TEST(LongIntArrayTests, LongIntArraySetZeroLength) {
    int result = LongIntArraySet(&longIntArray, 2, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongIntArrayTests, LongIntArraySetExistingElement) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    int result = LongIntArraySet(&longIntArray, 2, 5);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    long int x;

    result = LongIntArrayAt(&longIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongIntArrayTests, LongIntArraySetLessThanZeroIndex) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    int result = LongIntArraySet(&longIntArray, -2, 5);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    long int x;

    result = LongIntArrayAt(&longIntArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongIntArrayTests, LongIntArraySetGreaterThanLengthIndex) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    int result = LongIntArraySet(&longIntArray, 4, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(LongIntArrayTests, LongIntArraySetLessThanNegativeLengthIndex) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    int result = LongIntArraySet(&longIntArray, -5, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

int LongIntAscendingCompare(const void *a, const void *b) {
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

int LongIntDescendingCompare(const void *a, const void *b) {
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

TEST(LongIntArrayTests, LongIntArraySortEmptyArray) {
    LongIntArraySort(&longIntArray, LongIntAscendingCompare);

    TEST_ASSERT_EQUAL(0, LongIntArrayCount(&longIntArray));
}

TEST(LongIntArrayTests, LongIntArraySortAscending) {
    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    LongIntArrayPush(&longIntArray, 1L);

    LongIntArraySort(&longIntArray, LongIntAscendingCompare);

    long int x;

    LongIntArrayAt(&longIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongIntArrayAt(&longIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongIntArrayAt(&longIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongIntArrayAt(&longIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongIntArrayAt(&longIntArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongIntArrayTests, LongIntArraySortDescending) {
    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    LongIntArrayPush(&longIntArray, 1L);

    LongIntArraySort(&longIntArray, LongIntDescendingCompare);

    long int x;

    LongIntArrayAt(&longIntArray, 0, &x);

    TEST_ASSERT_EQUAL(5, x);

    LongIntArrayAt(&longIntArray, 1, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongIntArrayAt(&longIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongIntArrayAt(&longIntArray, 3, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongIntArrayAt(&longIntArray, 4, &x);

    TEST_ASSERT_EQUAL(1L, x);
}

TEST(LongIntArrayTests, LongIntArrayOverlapEmptyArrays) {
    int result = LongIntArrayOverlap(&longIntArray, &otherLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, LongIntArrayCount(&longIntArray));

    TEST_ASSERT_EQUAL(0, LongIntArrayCount(&otherLongIntArray));
}

TEST(LongIntArrayTests, LongIntArrayOverlapNonEmptyArrayWithEmptyArray) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 2);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    int result = LongIntArrayOverlap(&longIntArray, &otherLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, LongIntArrayCount(&longIntArray));

    TEST_ASSERT_EQUAL(0, LongIntArrayCount(&otherLongIntArray));

    LongIntArraySort(&longIntArray, LongIntAscendingCompare);

    long int x;

    LongIntArrayAt(&longIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongIntArrayAt(&longIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongIntArrayAt(&longIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongIntArrayAt(&longIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongIntArrayAt(&longIntArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongIntArrayTests, LongIntArrayOverlapEmptyArrayWithNonEmptyArray) {
    LongIntArrayPush(&otherLongIntArray, 1L);

    LongIntArrayPush(&otherLongIntArray, 2);

    LongIntArrayPush(&otherLongIntArray, 3);

    LongIntArrayPush(&otherLongIntArray, 4);

    LongIntArrayPush(&otherLongIntArray, 5);

    int result = LongIntArrayOverlap(&longIntArray, &otherLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, LongIntArrayCount(&longIntArray));

    TEST_ASSERT_EQUAL(5, LongIntArrayCount(&otherLongIntArray));

    LongIntArraySort(&longIntArray, LongIntAscendingCompare);

    long int x;

    LongIntArrayAt(&longIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongIntArrayAt(&longIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongIntArrayAt(&longIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongIntArrayAt(&longIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongIntArrayAt(&longIntArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(LongIntArrayTests, LongIntArrayOverlapNonEmptyArrays) {
    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 1L);

    LongIntArrayPush(&longIntArray, 3);

    LongIntArrayPush(&longIntArray, 4);

    LongIntArrayPush(&longIntArray, 5);

    LongIntArrayPush(&longIntArray, 5);

    LongIntArrayPush(&otherLongIntArray, 1L);

    LongIntArrayPush(&otherLongIntArray, 2);

    LongIntArrayPush(&otherLongIntArray, 3);

    LongIntArrayPush(&otherLongIntArray, 4);

    LongIntArrayPush(&otherLongIntArray, 4);

    LongIntArrayPush(&otherLongIntArray, 5);

    LongIntArrayPush(&otherLongIntArray, 5);

    LongIntArrayPush(&otherLongIntArray, 5);

    int result = LongIntArrayOverlap(&longIntArray, &otherLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(10, LongIntArrayCount(&longIntArray));

    TEST_ASSERT_EQUAL(8, LongIntArrayCount(&otherLongIntArray));

    LongIntArraySort(&longIntArray, LongIntAscendingCompare);

    long int x;

    LongIntArrayAt(&longIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongIntArrayAt(&longIntArray, 1, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongIntArrayAt(&longIntArray, 2, &x);

    TEST_ASSERT_EQUAL(1L, x);

    LongIntArrayAt(&longIntArray, 3, &x);

    TEST_ASSERT_EQUAL(2, x);

    LongIntArrayAt(&longIntArray, 4, &x);

    TEST_ASSERT_EQUAL(3, x);

    LongIntArrayAt(&longIntArray, 5, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongIntArrayAt(&longIntArray, 6, &x);

    TEST_ASSERT_EQUAL(4, x);

    LongIntArrayAt(&longIntArray, 7, &x);

    TEST_ASSERT_EQUAL(5, x);

    LongIntArrayAt(&longIntArray, 8, &x);

    TEST_ASSERT_EQUAL(5, x);

    LongIntArrayAt(&longIntArray, 9, &x);

    TEST_ASSERT_EQUAL(5, x);
}
