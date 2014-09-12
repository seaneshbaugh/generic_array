#include "unsigned_long_long_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedLongLongArrayTests);

UnsignedLongLongArray unsignedLongLongArray;
UnsignedLongLongArray otherUnsignedLongLongArray;

TEST_SETUP(UnsignedLongLongArrayTests) {
    UnsignedLongLongArrayInitialize(&unsignedLongLongArray);

    UnsignedLongLongArrayInitialize(&otherUnsignedLongLongArray);
}

TEST_TEAR_DOWN(UnsignedLongLongArrayTests) {
    UnsignedLongLongArrayDeinitialize(&unsignedLongLongArray);

    UnsignedLongLongArrayDeinitialize(&otherUnsignedLongLongArray);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, unsignedLongLongArray.length);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongLongArray.capacity);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayInitializeFromEmptyPointer) {
    unsigned long long values[] = { };

    int result = UnsignedLongLongArrayInitializeFromPointer(&unsignedLongLongArray, values, 0);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, UnsignedLongLongArrayCount(&unsignedLongLongArray));
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayInitializeFromPointer) {
    unsigned long long values[5] = { 1ULL, 2ULL, 3ULL, 4ULL, 5ULL };

    int result = UnsignedLongLongArrayInitializeFromPointer(&unsignedLongLongArray, values, 5);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, UnsignedLongLongArrayCount(&unsignedLongLongArray));
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayPushOneElement) {
    int result = UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedLongLongArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongLongArray.capacity);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = UnsignedLongLongArrayPush(&unsignedLongLongArray, (unsigned long long)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedLongLongArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedLongLongArray.capacity);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayAtZeroLength) {
    unsigned long long x;

    int result = UnsignedLongLongArrayAt(&unsignedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayAtExistingElement) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    unsigned long long x;

    int result = UnsignedLongLongArrayAt(&unsignedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayAtLessThanZeroIndex) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    unsigned long long x;

    int result = UnsignedLongLongArrayAt(&unsignedLongLongArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayAtGreaterThanLengthIndex) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    unsigned long long x;

    int result = UnsignedLongLongArrayAt(&unsignedLongLongArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayAtLessThanNegativeLengthIndex) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    unsigned long long x;

    int result = UnsignedLongLongArrayAt(&unsignedLongLongArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayClear) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    int result = UnsignedLongLongArrayClear(&unsignedLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongLongArray.length);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayConcatEmptyArrays) {
    int result = UnsignedLongLongArrayConcat(&unsignedLongLongArray, &otherUnsignedLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongLongArray.length);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayConcatEmptyArrayToNonEmptyArray) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    int result = UnsignedLongLongArrayConcat(&unsignedLongLongArray, &otherUnsignedLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongLongArray.length);

    unsigned long long x;

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayConcatNonEmptyArrayToEmptyArray) {
    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 2ULL);

    int result = UnsignedLongLongArrayConcat(&unsignedLongLongArray, &otherUnsignedLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongLongArray.length);

    unsigned long long x;

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayConcatNonEmptyArrayToNonEmptyArray) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 4ULL);

    int result = UnsignedLongLongArrayConcat(&unsignedLongLongArray, &otherUnsignedLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedLongLongArray.length);

    unsigned long long x;

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 3, &x);

    TEST_ASSERT_EQUAL(4ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayCountEmptyArray) {
    size_t result = UnsignedLongLongArrayCount(&unsignedLongLongArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayCountNonEmptyArray) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    size_t result = UnsignedLongLongArrayCount(&unsignedLongLongArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteFromEmptyArray) {
    int result = UnsignedLongLongArrayDelete(&unsignedLongLongArray, 1ULL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongLongArray.length);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteNonExistingElement) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    int result = UnsignedLongLongArrayDelete(&unsignedLongLongArray, 3ULL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongLongArray.length);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteExistingElement) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    int result = UnsignedLongLongArrayDelete(&unsignedLongLongArray, 2ULL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedLongLongArray.length);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteAtZeroLength) {
    int result = UnsignedLongLongArrayDeleteAt(&unsignedLongLongArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteAtExistingElement) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    int result = UnsignedLongLongArrayDeleteAt(&unsignedLongLongArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedLongLongArray.length);

    unsigned long long x;

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(4ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 3, &x);

    TEST_ASSERT_EQUAL(5ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteAtLessThanZeroIndex) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    int result = UnsignedLongLongArrayDeleteAt(&unsignedLongLongArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedLongLongArray.length);

    unsigned long long x;

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 3, &x);

    TEST_ASSERT_EQUAL(5ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteAtGreaterThanLengthIndex) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    int result = UnsignedLongLongArrayDeleteAt(&unsignedLongLongArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteAtLessThanNegativeLengthIndex) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    int result = UnsignedLongLongArrayDeleteAt(&unsignedLongLongArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayDropOneEmptyArray) {
    int result = UnsignedLongLongArrayDrop(&unsignedLongLongArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongLongArray.length);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayDropManyEmptyArray) {
    int result = UnsignedLongLongArrayDrop(&unsignedLongLongArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongLongArray.length);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayDropLessThanArrayLength) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    int result = UnsignedLongLongArrayDrop(&unsignedLongLongArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongLongArray.length);

    unsigned long long x;

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(4ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(5ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayDropGreaterThanArrayLength) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    int result = UnsignedLongLongArrayDrop(&unsignedLongLongArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongLongArray.length);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayEmptyArrayIsEmpty) {
    int result = UnsignedLongLongArrayIsEmpty(&unsignedLongLongArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayNonEmptyArrayIsNotEmpty) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    int result = UnsignedLongLongArrayIsEmpty(&unsignedLongLongArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayPush) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    TEST_ASSERT_EQUAL(5, unsignedLongLongArray.length);

    unsigned long long x;

    int result = UnsignedLongLongArrayAt(&unsignedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1ULL, x);

    result = UnsignedLongLongArrayAt(&unsignedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2ULL, x);

    result = UnsignedLongLongArrayAt(&unsignedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3ULL, x);

    result = UnsignedLongLongArrayAt(&unsignedLongLongArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4ULL, x);

    result = UnsignedLongLongArrayAt(&unsignedLongLongArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayMultipleElementArrayToString) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    char* asString;

    int result = UnsignedLongLongArrayToString(&unsignedLongLongArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[1, 2, 3, 4, 5]", asString);

    free(asString);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArraySetZeroLength) {
    int result = UnsignedLongLongArraySet(&unsignedLongLongArray, 2, 5ULL);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArraySetExistingElement) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    int result = UnsignedLongLongArraySet(&unsignedLongLongArray, 2, 5ULL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    unsigned long long x;

    result = UnsignedLongLongArrayAt(&unsignedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArraySetLessThanZeroIndex) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    int result = UnsignedLongLongArraySet(&unsignedLongLongArray, -2, 5ULL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    unsigned long long x;

    result = UnsignedLongLongArrayAt(&unsignedLongLongArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArraySetGreaterThanLengthIndex) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    int result = UnsignedLongLongArraySet(&unsignedLongLongArray, 4, 5ULL);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArraySetLessThanNegativeLengthIndex) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    int result = UnsignedLongLongArraySet(&unsignedLongLongArray, -5, 5ULL);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

int UnsignedLongLongAscendingCompare(const void *a, const void *b) {
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

int UnsignedLongLongDescendingCompare(const void *a, const void *b) {
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

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArraySortEmptyArray) {
    UnsignedLongLongArraySort(&unsignedLongLongArray, UnsignedLongLongAscendingCompare);

    TEST_ASSERT_EQUAL(0, UnsignedLongLongArrayCount(&unsignedLongLongArray));
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArraySortAscending) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArraySort(&unsignedLongLongArray, UnsignedLongLongAscendingCompare);

    unsigned long long x;

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 3, &x);

    TEST_ASSERT_EQUAL(4ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 4, &x);

    TEST_ASSERT_EQUAL(5ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArraySortDescending) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArraySort(&unsignedLongLongArray, UnsignedLongLongDescendingCompare);

    unsigned long long x;

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(5ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(4ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 3, &x);

    TEST_ASSERT_EQUAL(2ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 4, &x);

    TEST_ASSERT_EQUAL(1ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayOverlapEmptyArrays) {
    int result = UnsignedLongLongArrayOverlap(&unsignedLongLongArray, &otherUnsignedLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, UnsignedLongLongArrayCount(&unsignedLongLongArray));

    TEST_ASSERT_EQUAL(0, UnsignedLongLongArrayCount(&otherUnsignedLongLongArray));
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayOverlapNonEmptyArrayWithEmptyArray) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    int result = UnsignedLongLongArrayOverlap(&unsignedLongLongArray, &otherUnsignedLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, UnsignedLongLongArrayCount(&unsignedLongLongArray));

    TEST_ASSERT_EQUAL(0, UnsignedLongLongArrayCount(&otherUnsignedLongLongArray));

    UnsignedLongLongArraySort(&unsignedLongLongArray, UnsignedLongLongAscendingCompare);

    unsigned long long x;

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 3, &x);

    TEST_ASSERT_EQUAL(4ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 4, &x);

    TEST_ASSERT_EQUAL(5ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayOverlapEmptyArrayWithNonEmptyArray) {
    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 5ULL);

    int result = UnsignedLongLongArrayOverlap(&unsignedLongLongArray, &otherUnsignedLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, UnsignedLongLongArrayCount(&unsignedLongLongArray));

    TEST_ASSERT_EQUAL(5, UnsignedLongLongArrayCount(&otherUnsignedLongLongArray));

    UnsignedLongLongArraySort(&unsignedLongLongArray, UnsignedLongLongAscendingCompare);

    unsigned long long x;

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 3, &x);

    TEST_ASSERT_EQUAL(4ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 4, &x);

    TEST_ASSERT_EQUAL(5ULL, x);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayOverlapNonEmptyArrays) {
    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    UnsignedLongLongArrayPush(&unsignedLongLongArray, 5ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 1ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 2ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 3ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 4ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 5ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 5ULL);

    UnsignedLongLongArrayPush(&otherUnsignedLongLongArray, 5ULL);

    int result = UnsignedLongLongArrayOverlap(&unsignedLongLongArray, &otherUnsignedLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(10, UnsignedLongLongArrayCount(&unsignedLongLongArray));

    TEST_ASSERT_EQUAL(8, UnsignedLongLongArrayCount(&otherUnsignedLongLongArray));

    UnsignedLongLongArraySort(&unsignedLongLongArray, UnsignedLongLongAscendingCompare);

    unsigned long long x;

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 3, &x);

    TEST_ASSERT_EQUAL(2ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 4, &x);

    TEST_ASSERT_EQUAL(3ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 5, &x);

    TEST_ASSERT_EQUAL(4ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 6, &x);

    TEST_ASSERT_EQUAL(4ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 7, &x);

    TEST_ASSERT_EQUAL(5ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 8, &x);

    TEST_ASSERT_EQUAL(5ULL, x);

    UnsignedLongLongArrayAt(&unsignedLongLongArray, 9, &x);

    TEST_ASSERT_EQUAL(5ULL, x);
}
