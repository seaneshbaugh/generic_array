#include "double_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(DoubleArrayTests);

DoubleArray doubleArray;
DoubleArray otherDoubleArray;

TEST_SETUP(DoubleArrayTests) {
    DoubleArrayInitialize(&doubleArray);

    DoubleArrayInitialize(&otherDoubleArray);
}

TEST_TEAR_DOWN(DoubleArrayTests) {
    DoubleArrayDeinitialize(&doubleArray);

    DoubleArrayDeinitialize(&otherDoubleArray);
}

TEST(DoubleArrayTests, DoubleArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, doubleArray.length);
}

TEST(DoubleArrayTests, DoubleArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, doubleArray.capacity);
}

TEST(DoubleArrayTests, DoubleArrayPushOneElement) {
    int result = DoubleArrayPush(&doubleArray, 1.0);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, doubleArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, doubleArray.capacity);
}

TEST(DoubleArrayTests, DoubleArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = DoubleArrayPush(&doubleArray, (double)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, doubleArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, doubleArray.capacity);
}

TEST(DoubleArrayTests, DoubleArrayAtZeroLength) {
    double x;

    int result = DoubleArrayAt(&doubleArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(DoubleArrayTests, DoubleArrayAtExistingElement) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    double x;

    int result = DoubleArrayAt(&doubleArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3.0, x);
}

TEST(DoubleArrayTests, DoubleArrayAtLessThanZeroIndex) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    double x;

    int result = DoubleArrayAt(&doubleArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4.0, x);
}

TEST(DoubleArrayTests, DoubleArrayAtGreaterThanLengthIndex) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    double x;

    int result = DoubleArrayAt(&doubleArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(DoubleArrayTests, DoubleArrayAtLessThanNegativeLengthIndex) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    double x;

    int result = DoubleArrayAt(&doubleArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(DoubleArrayTests, DoubleArrayClear) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    int result = DoubleArrayClear(&doubleArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, doubleArray.length);
}

TEST(DoubleArrayTests, DoubleArrayConcatEmptyArrays) {
    int result = DoubleArrayConcat(&doubleArray, &otherDoubleArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, doubleArray.length);
}

TEST(DoubleArrayTests, DoubleArrayConcatEmptyArrayToNonEmptyArray) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    int result = DoubleArrayConcat(&doubleArray, &otherDoubleArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, doubleArray.length);

    double x;

    DoubleArrayAt(&doubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0, x);

    DoubleArrayAt(&doubleArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0, x);
}

TEST(DoubleArrayTests, DoubleArrayConcatNonEmptyArrayToEmptyArray) {
    DoubleArrayPush(&otherDoubleArray, 1.0);

    DoubleArrayPush(&otherDoubleArray, 2.0);

    int result = DoubleArrayConcat(&doubleArray, &otherDoubleArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, doubleArray.length);

    double x;

    DoubleArrayAt(&doubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0, x);

    DoubleArrayAt(&doubleArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0, x);
}

TEST(DoubleArrayTests, DoubleArrayConcatNonEmptyArrayToNonEmptyArray) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&otherDoubleArray, 3.0);

    DoubleArrayPush(&otherDoubleArray, 4.0);

    int result = DoubleArrayConcat(&doubleArray, &otherDoubleArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, doubleArray.length);

    double x;

    DoubleArrayAt(&doubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0, x);

    DoubleArrayAt(&doubleArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0, x);

    DoubleArrayAt(&doubleArray, 2, &x);

    TEST_ASSERT_EQUAL(3.0, x);

    DoubleArrayAt(&doubleArray, 3, &x);

    TEST_ASSERT_EQUAL(4.0, x);
}

TEST(DoubleArrayTests, DoubleArrayCountEmptyArray) {
    size_t result = DoubleArrayCount(&doubleArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(DoubleArrayTests, DoubleArrayCountNonEmptyArray) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    size_t result = DoubleArrayCount(&doubleArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(DoubleArrayTests, DoubleArrayDeleteFromEmptyArray) {
    int result = DoubleArrayDelete(&doubleArray, 1.0);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, doubleArray.length);
}

TEST(DoubleArrayTests, DoubleArrayDeleteNonExistingElement) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    int result = DoubleArrayDelete(&doubleArray, 3.0);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, doubleArray.length);
}

TEST(DoubleArrayTests, DoubleArrayDeleteExistingElement) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    int result = DoubleArrayDelete(&doubleArray, 2.0);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, doubleArray.length);
}

TEST(DoubleArrayTests, DoubleArrayDeleteAtZeroLength) {
    int result = DoubleArrayDeleteAt(&doubleArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(DoubleArrayTests, DoubleArrayDeleteAtExistingElement) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    int result = DoubleArrayDeleteAt(&doubleArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, doubleArray.length);

    double x;

    DoubleArrayAt(&doubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0, x);

    DoubleArrayAt(&doubleArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0, x);

    DoubleArrayAt(&doubleArray, 2, &x);

    TEST_ASSERT_EQUAL(4.0, x);

    DoubleArrayAt(&doubleArray, 3, &x);

    TEST_ASSERT_EQUAL(5.0, x);
}

TEST(DoubleArrayTests, DoubleArrayDeleteAtLessThanZeroIndex) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    int result = DoubleArrayDeleteAt(&doubleArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, doubleArray.length);

    double x;

    DoubleArrayAt(&doubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0, x);

    DoubleArrayAt(&doubleArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0, x);

    DoubleArrayAt(&doubleArray, 2, &x);

    TEST_ASSERT_EQUAL(3.0, x);

    DoubleArrayAt(&doubleArray, 3, &x);

    TEST_ASSERT_EQUAL(5.0, x);
}

TEST(DoubleArrayTests, DoubleArrayDeleteAtGreaterThanLengthIndex) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    int result = DoubleArrayDeleteAt(&doubleArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(DoubleArrayTests, DoubleArrayDeleteAtLessThanNegativeLengthIndex) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    int result = DoubleArrayDeleteAt(&doubleArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(DoubleArrayTests, DoubleArrayDropOneEmptyArray) {
    int result = DoubleArrayDrop(&doubleArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, doubleArray.length);
}

TEST(DoubleArrayTests, DoubleArrayDropManyEmptyArray) {
    int result = DoubleArrayDrop(&doubleArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, doubleArray.length);
}

TEST(DoubleArrayTests, DoubleArrayDropLessThanArrayLength) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    int result = DoubleArrayDrop(&doubleArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, doubleArray.length);

    double x;

    DoubleArrayAt(&doubleArray, 0, &x);

    TEST_ASSERT_EQUAL(4.0, x);

    DoubleArrayAt(&doubleArray, 1, &x);

    TEST_ASSERT_EQUAL(5.0, x);
}

TEST(DoubleArrayTests, DoubleArrayDropGreaterThanArrayLength) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    int result = DoubleArrayDrop(&doubleArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, doubleArray.length);
}

TEST(DoubleArrayTests, DoubleArrayEmptyArrayIsEmpty) {
    int result = DoubleArrayIsEmpty(&doubleArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(DoubleArrayTests, DoubleArrayNonEmptyArrayIsNotEmpty) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    int result = DoubleArrayIsEmpty(&doubleArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(DoubleArrayTests, DoubleArrayPush) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    TEST_ASSERT_EQUAL(5, doubleArray.length);

    double x;

    int result = DoubleArrayAt(&doubleArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1.0, x);

    result = DoubleArrayAt(&doubleArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2.0, x);

    result = DoubleArrayAt(&doubleArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3.0, x);

    result = DoubleArrayAt(&doubleArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4.0, x);

    result = DoubleArrayAt(&doubleArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5.0, x);
}

TEST(DoubleArrayTests, DoubleArrayMultipleElementArrayToString) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    char* asString;

    int result = DoubleArrayToString(&doubleArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[1.000000, 2.000000, 3.000000, 4.000000, 5.000000]", asString);

    free(asString);
}

int DoubleAscendingCompare(const void *a, const void *b) {
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

int DoubleDescendingCompare(const void *a, const void *b) {
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

TEST(DoubleArrayTests, DoubleArraySortEmptyArray) {
    DoubleArraySort(&doubleArray, DoubleAscendingCompare);

    TEST_ASSERT_EQUAL(0, DoubleArrayCount(&doubleArray));
}

TEST(DoubleArrayTests, DoubleArraySortAscending) {
    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArraySort(&doubleArray, DoubleAscendingCompare);

    double x;

    DoubleArrayAt(&doubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0, x);

    DoubleArrayAt(&doubleArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0, x);

    DoubleArrayAt(&doubleArray, 2, &x);

    TEST_ASSERT_EQUAL(3.0, x);

    DoubleArrayAt(&doubleArray, 3, &x);

    TEST_ASSERT_EQUAL(4.0, x);

    DoubleArrayAt(&doubleArray, 4, &x);

    TEST_ASSERT_EQUAL(5.0, x);
}

TEST(DoubleArrayTests, DoubleArraySortDescending) {
    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArraySort(&doubleArray, DoubleDescendingCompare);

    double x;

    DoubleArrayAt(&doubleArray, 0, &x);

    TEST_ASSERT_EQUAL(5.0, x);

    DoubleArrayAt(&doubleArray, 1, &x);

    TEST_ASSERT_EQUAL(4.0, x);

    DoubleArrayAt(&doubleArray, 2, &x);

    TEST_ASSERT_EQUAL(3.0, x);

    DoubleArrayAt(&doubleArray, 3, &x);

    TEST_ASSERT_EQUAL(2.0, x);

    DoubleArrayAt(&doubleArray, 4, &x);

    TEST_ASSERT_EQUAL(1.0, x);
}

TEST(DoubleArrayTests, DoubleArrayOverlapEmptyArrays) {
    int result = DoubleArrayOverlap(&doubleArray, &otherDoubleArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, DoubleArrayCount(&doubleArray));

    TEST_ASSERT_EQUAL(0, DoubleArrayCount(&otherDoubleArray));
}

TEST(DoubleArrayTests, DoubleArrayOverlapNonEmptyArrayWithEmptyArray) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 2.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    int result = DoubleArrayOverlap(&doubleArray, &otherDoubleArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, DoubleArrayCount(&doubleArray));

    TEST_ASSERT_EQUAL(0, DoubleArrayCount(&otherDoubleArray));

    DoubleArraySort(&doubleArray, DoubleAscendingCompare);

    double x;

    DoubleArrayAt(&doubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0, x);

    DoubleArrayAt(&doubleArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0, x);

    DoubleArrayAt(&doubleArray, 2, &x);

    TEST_ASSERT_EQUAL(3.0, x);

    DoubleArrayAt(&doubleArray, 3, &x);

    TEST_ASSERT_EQUAL(4.0, x);

    DoubleArrayAt(&doubleArray, 4, &x);

    TEST_ASSERT_EQUAL(5.0, x);
}

TEST(DoubleArrayTests, DoubleArrayOverlapEmptyArrayWithNonEmptyArray) {
    DoubleArrayPush(&otherDoubleArray, 1.0);

    DoubleArrayPush(&otherDoubleArray, 2.0);

    DoubleArrayPush(&otherDoubleArray, 3.0);

    DoubleArrayPush(&otherDoubleArray, 4.0);

    DoubleArrayPush(&otherDoubleArray, 5.0);

    int result = DoubleArrayOverlap(&doubleArray, &otherDoubleArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, DoubleArrayCount(&doubleArray));

    TEST_ASSERT_EQUAL(5, DoubleArrayCount(&otherDoubleArray));

    DoubleArraySort(&doubleArray, DoubleAscendingCompare);

    double x;

    DoubleArrayAt(&doubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0, x);

    DoubleArrayAt(&doubleArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0, x);

    DoubleArrayAt(&doubleArray, 2, &x);

    TEST_ASSERT_EQUAL(3.0, x);

    DoubleArrayAt(&doubleArray, 3, &x);

    TEST_ASSERT_EQUAL(4.0, x);

    DoubleArrayAt(&doubleArray, 4, &x);

    TEST_ASSERT_EQUAL(5.0, x);
}

TEST(DoubleArrayTests, DoubleArrayOverlapNonEmptyArrays) {
    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 1.0);

    DoubleArrayPush(&doubleArray, 3.0);

    DoubleArrayPush(&doubleArray, 4.0);

    DoubleArrayPush(&doubleArray, 5.0);

    DoubleArrayPush(&doubleArray, 5.0);

    DoubleArrayPush(&otherDoubleArray, 1.0);

    DoubleArrayPush(&otherDoubleArray, 2.0);

    DoubleArrayPush(&otherDoubleArray, 3.0);

    DoubleArrayPush(&otherDoubleArray, 4.0);

    DoubleArrayPush(&otherDoubleArray, 4.0);

    DoubleArrayPush(&otherDoubleArray, 5.0);

    DoubleArrayPush(&otherDoubleArray, 5.0);

    DoubleArrayPush(&otherDoubleArray, 5.0);

    int result = DoubleArrayOverlap(&doubleArray, &otherDoubleArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(10, DoubleArrayCount(&doubleArray));

    TEST_ASSERT_EQUAL(8, DoubleArrayCount(&otherDoubleArray));

    DoubleArraySort(&doubleArray, DoubleAscendingCompare);

    double x;

    DoubleArrayAt(&doubleArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0, x);

    DoubleArrayAt(&doubleArray, 1, &x);

    TEST_ASSERT_EQUAL(1.0, x);

    DoubleArrayAt(&doubleArray, 2, &x);

    TEST_ASSERT_EQUAL(1.0, x);

    DoubleArrayAt(&doubleArray, 3, &x);

    TEST_ASSERT_EQUAL(2.0, x);

    DoubleArrayAt(&doubleArray, 4, &x);

    TEST_ASSERT_EQUAL(3.0, x);

    DoubleArrayAt(&doubleArray, 5, &x);

    TEST_ASSERT_EQUAL(4.0, x);

    DoubleArrayAt(&doubleArray, 6, &x);

    TEST_ASSERT_EQUAL(4.0, x);

    DoubleArrayAt(&doubleArray, 7, &x);

    TEST_ASSERT_EQUAL(5.0, x);

    DoubleArrayAt(&doubleArray, 8, &x);

    TEST_ASSERT_EQUAL(5.0, x);

    DoubleArrayAt(&doubleArray, 9, &x);

    TEST_ASSERT_EQUAL(5.0, x);
}
