#include "unsigned_short_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedShortIntArrayTests);

UnsignedShortIntArray unsignedShortIntArray;
UnsignedShortIntArray otherUnsignedShortIntArray;

TEST_SETUP(UnsignedShortIntArrayTests) {
    UnsignedShortIntArrayInitialize(&unsignedShortIntArray);

    UnsignedShortIntArrayInitialize(&otherUnsignedShortIntArray);
}

TEST_TEAR_DOWN(UnsignedShortIntArrayTests) {
    UnsignedShortIntArrayDeinitialize(&unsignedShortIntArray);

    UnsignedShortIntArrayDeinitialize(&otherUnsignedShortIntArray);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, unsignedShortIntArray.length);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedShortIntArray.capacity);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayPushOneElement) {
    int result = UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedShortIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedShortIntArray.capacity);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = UnsignedShortIntArrayPush(&unsignedShortIntArray, (unsigned short int)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedShortIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedShortIntArray.capacity);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayAtZeroLength) {
    unsigned short int x;

    int result = UnsignedShortIntArrayAt(&unsignedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayAtExistingElement) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    unsigned short int x;

    int result = UnsignedShortIntArrayAt(&unsignedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3U, x);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayAtLessThanZeroIndex) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    unsigned short int x;

    int result = UnsignedShortIntArrayAt(&unsignedShortIntArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4U, x);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayAtGreaterThanLengthIndex) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    unsigned short int x;

    int result = UnsignedShortIntArrayAt(&unsignedShortIntArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayAtLessThanNegativeLengthIndex) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    unsigned short int x;

    int result = UnsignedShortIntArrayAt(&unsignedShortIntArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayClear) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    int result = UnsignedShortIntArrayClear(&unsignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedShortIntArray.length);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayConcatEmptyArrays) {
    int result = UnsignedShortIntArrayConcat(&unsignedShortIntArray, &otherUnsignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedShortIntArray.length);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayConcatEmptyArrayToNonEmptyArray) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    int result = UnsignedShortIntArrayConcat(&unsignedShortIntArray, &otherUnsignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedShortIntArray.length);

    unsigned short int x;

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayConcatNonEmptyArrayToEmptyArray) {
    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 2U);

    int result = UnsignedShortIntArrayConcat(&unsignedShortIntArray, &otherUnsignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedShortIntArray.length);

    unsigned short int x;

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayConcatNonEmptyArrayToNonEmptyArray) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 4U);

    int result = UnsignedShortIntArrayConcat(&unsignedShortIntArray, &otherUnsignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedShortIntArray.length);

    unsigned short int x;

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4U, x);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayCountEmptyArray) {
    size_t result = UnsignedShortIntArrayCount(&unsignedShortIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayCountNonEmptyArray) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    size_t result = UnsignedShortIntArrayCount(&unsignedShortIntArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteFromEmptyArray) {
    int result = UnsignedShortIntArrayDelete(&unsignedShortIntArray, 1U);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedShortIntArray.length);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteNonExistingElement) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    int result = UnsignedShortIntArrayDelete(&unsignedShortIntArray, 3U);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedShortIntArray.length);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteExistingElement) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    int result = UnsignedShortIntArrayDelete(&unsignedShortIntArray, 2U);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedShortIntArray.length);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteAtZeroLength) {
    int result = UnsignedShortIntArrayDeleteAt(&unsignedShortIntArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteAtExistingElement) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    int result = UnsignedShortIntArrayDeleteAt(&unsignedShortIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedShortIntArray.length);

    unsigned short int x;

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(4U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5U, x);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteAtLessThanZeroIndex) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    int result = UnsignedShortIntArrayDeleteAt(&unsignedShortIntArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedShortIntArray.length);

    unsigned short int x;

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5U, x);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteAtGreaterThanLengthIndex) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    int result = UnsignedShortIntArrayDeleteAt(&unsignedShortIntArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteAtLessThanNegativeLengthIndex) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    int result = UnsignedShortIntArrayDeleteAt(&unsignedShortIntArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayDropOneEmptyArray) {
    int result = UnsignedShortIntArrayDrop(&unsignedShortIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedShortIntArray.length);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayDropManyEmptyArray) {
    int result = UnsignedShortIntArrayDrop(&unsignedShortIntArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedShortIntArray.length);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayDropLessThanArrayLength) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    int result = UnsignedShortIntArrayDrop(&unsignedShortIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedShortIntArray.length);

    unsigned short int x;

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(4U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(5U, x);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayDropGreaterThanArrayLength) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    int result = UnsignedShortIntArrayDrop(&unsignedShortIntArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedShortIntArray.length);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayEmptyArrayIsEmpty) {
    int result = UnsignedShortIntArrayIsEmpty(&unsignedShortIntArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayNonEmptyArrayIsNotEmpty) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    int result = UnsignedShortIntArrayIsEmpty(&unsignedShortIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayPush) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    TEST_ASSERT_EQUAL(5, unsignedShortIntArray.length);

    unsigned short int x;

    int result = UnsignedShortIntArrayAt(&unsignedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1U, x);

    result = UnsignedShortIntArrayAt(&unsignedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2U, x);

    result = UnsignedShortIntArrayAt(&unsignedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3U, x);

    result = UnsignedShortIntArrayAt(&unsignedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4U, x);

    result = UnsignedShortIntArrayAt(&unsignedShortIntArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5U, x);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayMultipleElementArrayToString) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    char* asString;

    int result = UnsignedShortIntArrayToString(&unsignedShortIntArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[1, 2, 3, 4, 5]", asString);

    free(asString);
}

int UnsignedShortIntAscendingCompare(const void *a, const void *b) {
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

int UnsignedShortIntDescendingCompare(const void *a, const void *b) {
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

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArraySortEmptyArray) {
    UnsignedShortIntArraySort(&unsignedShortIntArray, UnsignedShortIntAscendingCompare);

    TEST_ASSERT_EQUAL(0, UnsignedShortIntArrayCount(&unsignedShortIntArray));
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArraySortAscending) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArraySort(&unsignedShortIntArray, UnsignedShortIntAscendingCompare);

    unsigned short int x;

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 4, &x);

    TEST_ASSERT_EQUAL(5U, x);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArraySortDescending) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArraySort(&unsignedShortIntArray, UnsignedShortIntDescendingCompare);

    unsigned short int x;

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(5U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(4U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(2U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 4, &x);

    TEST_ASSERT_EQUAL(1U, x);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayOverlapEmptyArrays) {
    int result = UnsignedShortIntArrayOverlap(&unsignedShortIntArray, &otherUnsignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, UnsignedShortIntArrayCount(&unsignedShortIntArray));

    TEST_ASSERT_EQUAL(0, UnsignedShortIntArrayCount(&otherUnsignedShortIntArray));
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayOverlapNonEmptyArrayWithEmptyArray) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    int result = UnsignedShortIntArrayOverlap(&unsignedShortIntArray, &otherUnsignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, UnsignedShortIntArrayCount(&unsignedShortIntArray));

    TEST_ASSERT_EQUAL(0, UnsignedShortIntArrayCount(&otherUnsignedShortIntArray));

    UnsignedShortIntArraySort(&unsignedShortIntArray, UnsignedShortIntAscendingCompare);

    unsigned short int x;

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 4, &x);

    TEST_ASSERT_EQUAL(5U, x);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayOverlapEmptyArrayWithNonEmptyArray) {
    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 5U);

    int result = UnsignedShortIntArrayOverlap(&unsignedShortIntArray, &otherUnsignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, UnsignedShortIntArrayCount(&unsignedShortIntArray));

    TEST_ASSERT_EQUAL(5, UnsignedShortIntArrayCount(&otherUnsignedShortIntArray));

    UnsignedShortIntArraySort(&unsignedShortIntArray, UnsignedShortIntAscendingCompare);

    unsigned short int x;

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 4, &x);

    TEST_ASSERT_EQUAL(5U, x);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayOverlapNonEmptyArrays) {
    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    UnsignedShortIntArrayPush(&unsignedShortIntArray, 5U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 1U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 2U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 3U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 4U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 5U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 5U);

    UnsignedShortIntArrayPush(&otherUnsignedShortIntArray, 5U);

    int result = UnsignedShortIntArrayOverlap(&unsignedShortIntArray, &otherUnsignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(10, UnsignedShortIntArrayCount(&unsignedShortIntArray));

    TEST_ASSERT_EQUAL(8, UnsignedShortIntArrayCount(&otherUnsignedShortIntArray));

    UnsignedShortIntArraySort(&unsignedShortIntArray, UnsignedShortIntAscendingCompare);

    unsigned short int x;

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(2U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 4, &x);

    TEST_ASSERT_EQUAL(3U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 5, &x);

    TEST_ASSERT_EQUAL(4U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 6, &x);

    TEST_ASSERT_EQUAL(4U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 7, &x);

    TEST_ASSERT_EQUAL(5U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 8, &x);

    TEST_ASSERT_EQUAL(5U, x);

    UnsignedShortIntArrayAt(&unsignedShortIntArray, 9, &x);

    TEST_ASSERT_EQUAL(5U, x);
}
