#include "unsigned_long_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedLongIntArrayTests);

UnsignedLongIntArray unsignedLongIntArray;
UnsignedLongIntArray otherUnsignedLongIntArray;

TEST_SETUP(UnsignedLongIntArrayTests) {
    UnsignedLongIntArrayInitialize(&unsignedLongIntArray);

    UnsignedLongIntArrayInitialize(&otherUnsignedLongIntArray);
}

TEST_TEAR_DOWN(UnsignedLongIntArrayTests) {
    UnsignedLongIntArrayDeinitialize(&unsignedLongIntArray);

    UnsignedLongIntArrayDeinitialize(&otherUnsignedLongIntArray);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, unsignedLongIntArray.length);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongIntArray.capacity);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayPushOneElement) {
    int result = UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedLongIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongIntArray.capacity);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = UnsignedLongIntArrayPush(&unsignedLongIntArray, (unsigned long int)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedLongIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedLongIntArray.capacity);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayAtZeroLength) {
    unsigned long int x;

    int result = UnsignedLongIntArrayAt(&unsignedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayAtExistingElement) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    unsigned long int x;

    int result = UnsignedLongIntArrayAt(&unsignedLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3UL, x);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayAtLessThanZeroIndex) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    unsigned long int x;

    int result = UnsignedLongIntArrayAt(&unsignedLongIntArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4UL, x);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayAtGreaterThanLengthIndex) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    unsigned long int x;

    int result = UnsignedLongIntArrayAt(&unsignedLongIntArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayAtLessThanNegativeLengthIndex) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    unsigned long int x;

    int result = UnsignedLongIntArrayAt(&unsignedLongIntArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayClear) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    int result = UnsignedLongIntArrayClear(&unsignedLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongIntArray.length);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayConcatEmptyArrays) {
    int result = UnsignedLongIntArrayConcat(&unsignedLongIntArray, &otherUnsignedLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongIntArray.length);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayConcatEmptyArrayToNonEmptyArray) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    int result = UnsignedLongIntArrayConcat(&unsignedLongIntArray, &otherUnsignedLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongIntArray.length);

    unsigned long int x;

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2UL, x);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayConcatNonEmptyArrayToEmptyArray) {
    UnsignedLongIntArrayPush(&otherUnsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&otherUnsignedLongIntArray, 2UL);

    int result = UnsignedLongIntArrayConcat(&unsignedLongIntArray, &otherUnsignedLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongIntArray.length);

    unsigned long int x;

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2UL, x);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayConcatNonEmptyArrayToNonEmptyArray) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&otherUnsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&otherUnsignedLongIntArray, 4UL);

    int result = UnsignedLongIntArrayConcat(&unsignedLongIntArray, &otherUnsignedLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedLongIntArray.length);

    unsigned long int x;

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4UL, x);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayCountEmptyArray) {
    size_t result = UnsignedLongIntArrayCount(&unsignedLongIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayCountNonEmptyArray) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    size_t result = UnsignedLongIntArrayCount(&unsignedLongIntArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteFromEmptyArray) {
    int result = UnsignedLongIntArrayDelete(&unsignedLongIntArray, 1UL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongIntArray.length);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteNonExistingElement) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    int result = UnsignedLongIntArrayDelete(&unsignedLongIntArray, 3UL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongIntArray.length);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteExistingElement) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    int result = UnsignedLongIntArrayDelete(&unsignedLongIntArray, 2UL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedLongIntArray.length);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteAtZeroLength) {
    int result = UnsignedLongIntArrayDeleteAt(&unsignedLongIntArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteAtExistingElement) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    int result = UnsignedLongIntArrayDeleteAt(&unsignedLongIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedLongIntArray.length);

    unsigned long int x;

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(4UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5UL, x);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteAtLessThanZeroIndex) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    int result = UnsignedLongIntArrayDeleteAt(&unsignedLongIntArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedLongIntArray.length);

    unsigned long int x;

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5UL, x);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteAtGreaterThanLengthIndex) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    int result = UnsignedLongIntArrayDeleteAt(&unsignedLongIntArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteAtLessThanNegativeLengthIndex) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    int result = UnsignedLongIntArrayDeleteAt(&unsignedLongIntArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayDropOneEmptyArray) {
    int result = UnsignedLongIntArrayDrop(&unsignedLongIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongIntArray.length);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayDropManyEmptyArray) {
    int result = UnsignedLongIntArrayDrop(&unsignedLongIntArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongIntArray.length);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayDropLessThanArrayLength) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    int result = UnsignedLongIntArrayDrop(&unsignedLongIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongIntArray.length);

    unsigned long int x;

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(4UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(5UL, x);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayDropGreaterThanArrayLength) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    int result = UnsignedLongIntArrayDrop(&unsignedLongIntArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongIntArray.length);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayEmptyArrayIsEmpty) {
    int result = UnsignedLongIntArrayIsEmpty(&unsignedLongIntArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayNonEmptyArrayIsNotEmpty) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    int result = UnsignedLongIntArrayIsEmpty(&unsignedLongIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayPush) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    TEST_ASSERT_EQUAL(5, unsignedLongIntArray.length);

    unsigned long int x;

    int result = UnsignedLongIntArrayAt(&unsignedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1UL, x);

    result = UnsignedLongIntArrayAt(&unsignedLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2UL, x);

    result = UnsignedLongIntArrayAt(&unsignedLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3UL, x);

    result = UnsignedLongIntArrayAt(&unsignedLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4UL, x);

    result = UnsignedLongIntArrayAt(&unsignedLongIntArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5UL, x);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayMultipleElementArrayToString) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    char* asString;

    int result = UnsignedLongIntArrayToString(&unsignedLongIntArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[1, 2, 3, 4, 5]", asString);

    free(asString);
}

int UnsignedLongIntAscendingCompare(const void *a, const void *b) {
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

int UnsignedLongIntDescendingCompare(const void *a, const void *b) {
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

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArraySortAscending) {
    UnsignedLongIntArrayPush(&unsignedLongIntArray, 3UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 2UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 4UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 5UL);

    UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

    UnsignedLongIntArraySort(&unsignedLongIntArray, UnsignedLongIntAscendingCompare);

    unsigned long int x;

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4UL, x);

    UnsignedLongIntArrayAt(&unsignedLongIntArray, 4, &x);

    TEST_ASSERT_EQUAL(5UL, x);
}
