#include "unsigned_long_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedLongArrayTests);

UnsignedLongArray unsignedLongArray;
UnsignedLongArray otherUnsignedLongArray;

TEST_SETUP(UnsignedLongArrayTests) {
    UnsignedLongArrayInitialize(&unsignedLongArray);

    UnsignedLongArrayInitialize(&otherUnsignedLongArray);
}

TEST_TEAR_DOWN(UnsignedLongArrayTests) {
    UnsignedLongArrayDeinitialize(&unsignedLongArray);

    UnsignedLongArrayDeinitialize(&otherUnsignedLongArray);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, unsignedLongArray.length);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongArray.capacity);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayPushOneElement) {
    int result = UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedLongArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongArray.capacity);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = UnsignedLongArrayPush(&unsignedLongArray, (unsigned long)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedLongArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedLongArray.capacity);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayAtZeroLength) {
    unsigned long x;

    int result = UnsignedLongArrayAt(&unsignedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayAtExistingElement) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&unsignedLongArray, 3UL);

    UnsignedLongArrayPush(&unsignedLongArray, 4UL);

    UnsignedLongArrayPush(&unsignedLongArray, 5UL);

    unsigned long x;

    int result = UnsignedLongArrayAt(&unsignedLongArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3UL, x);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayAtLessThanZeroIndex) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&unsignedLongArray, 3UL);

    UnsignedLongArrayPush(&unsignedLongArray, 4UL);

    UnsignedLongArrayPush(&unsignedLongArray, 5UL);

    unsigned long x;

    int result = UnsignedLongArrayAt(&unsignedLongArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4UL, x);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayAtGreaterThanLengthIndex) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&unsignedLongArray, 3UL);

    UnsignedLongArrayPush(&unsignedLongArray, 4UL);

    UnsignedLongArrayPush(&unsignedLongArray, 5UL);

    unsigned long x;

    int result = UnsignedLongArrayAt(&unsignedLongArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayAtLessThanNegativeLengthIndex) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&unsignedLongArray, 3UL);

    UnsignedLongArrayPush(&unsignedLongArray, 4UL);

    UnsignedLongArrayPush(&unsignedLongArray, 5UL);

    unsigned long x;

    int result = UnsignedLongArrayAt(&unsignedLongArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayClear) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&unsignedLongArray, 3UL);

    UnsignedLongArrayPush(&unsignedLongArray, 4UL);

    UnsignedLongArrayPush(&unsignedLongArray, 5UL);

    int result = UnsignedLongArrayClear(&unsignedLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongArray.length);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayConcatEmptyArrays) {
    int result = UnsignedLongArrayConcat(&unsignedLongArray, &otherUnsignedLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongArray.length);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayConcatEmptyArrayToNonEmptyArray) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    int result = UnsignedLongArrayConcat(&unsignedLongArray, &otherUnsignedLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongArray.length);

    unsigned long x;

    UnsignedLongArrayAt(&unsignedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1UL, x);

    UnsignedLongArrayAt(&unsignedLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2UL, x);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayConcatNonEmptyArrayToEmptyArray) {
    UnsignedLongArrayPush(&otherUnsignedLongArray, 1UL);

    UnsignedLongArrayPush(&otherUnsignedLongArray, 2UL);

    int result = UnsignedLongArrayConcat(&unsignedLongArray, &otherUnsignedLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongArray.length);

    unsigned long x;

    UnsignedLongArrayAt(&unsignedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1UL, x);

    UnsignedLongArrayAt(&unsignedLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2UL, x);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayConcatNonEmptyArrayToNonEmptyArray) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&otherUnsignedLongArray, 3UL);

    UnsignedLongArrayPush(&otherUnsignedLongArray, 4UL);

    int result = UnsignedLongArrayConcat(&unsignedLongArray, &otherUnsignedLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedLongArray.length);

    unsigned long x;

    UnsignedLongArrayAt(&unsignedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1UL, x);

    UnsignedLongArrayAt(&unsignedLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2UL, x);

    UnsignedLongArrayAt(&unsignedLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3UL, x);

    UnsignedLongArrayAt(&unsignedLongArray, 3, &x);

    TEST_ASSERT_EQUAL(4UL, x);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayCountEmptyArray) {
    size_t result = UnsignedLongArrayCount(&unsignedLongArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayCountNonEmptyArray) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    size_t result = UnsignedLongArrayCount(&unsignedLongArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayDeleteFromEmptyArray) {
    int result = UnsignedLongArrayDelete(&unsignedLongArray, 1UL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongArray.length);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayDeleteNonExistingElement) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    int result = UnsignedLongArrayDelete(&unsignedLongArray, 3UL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongArray.length);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayDeleteExistingElement) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    int result = UnsignedLongArrayDelete(&unsignedLongArray, 2UL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedLongArray.length);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayDeleteAtZeroLength) {
    int result = UnsignedLongArrayDeleteAt(&unsignedLongArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayDeleteAtExistingElement) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&unsignedLongArray, 3UL);

    UnsignedLongArrayPush(&unsignedLongArray, 4UL);

    UnsignedLongArrayPush(&unsignedLongArray, 5UL);

    int result = UnsignedLongArrayDeleteAt(&unsignedLongArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedLongArray.length);

    unsigned long x;

    UnsignedLongArrayAt(&unsignedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1UL, x);

    UnsignedLongArrayAt(&unsignedLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2UL, x);

    UnsignedLongArrayAt(&unsignedLongArray, 2, &x);

    TEST_ASSERT_EQUAL(4UL, x);

    UnsignedLongArrayAt(&unsignedLongArray, 3, &x);

    TEST_ASSERT_EQUAL(5UL, x);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayDeleteAtLessThanZeroIndex) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&unsignedLongArray, 3UL);

    UnsignedLongArrayPush(&unsignedLongArray, 4UL);

    UnsignedLongArrayPush(&unsignedLongArray, 5UL);

    int result = UnsignedLongArrayDeleteAt(&unsignedLongArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedLongArray.length);

    unsigned long x;

    UnsignedLongArrayAt(&unsignedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1UL, x);

    UnsignedLongArrayAt(&unsignedLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2UL, x);

    UnsignedLongArrayAt(&unsignedLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3UL, x);

    UnsignedLongArrayAt(&unsignedLongArray, 3, &x);

    TEST_ASSERT_EQUAL(5UL, x);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayDeleteAtGreaterThanLengthIndex) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&unsignedLongArray, 3UL);

    UnsignedLongArrayPush(&unsignedLongArray, 4UL);

    UnsignedLongArrayPush(&unsignedLongArray, 5UL);

    int result = UnsignedLongArrayDeleteAt(&unsignedLongArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayDeleteAtLessThanNegativeLengthIndex) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&unsignedLongArray, 3UL);

    UnsignedLongArrayPush(&unsignedLongArray, 4UL);

    UnsignedLongArrayPush(&unsignedLongArray, 5UL);

    int result = UnsignedLongArrayDeleteAt(&unsignedLongArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayDropOneEmptyArray) {
    int result = UnsignedLongArrayDrop(&unsignedLongArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongArray.length);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayDropManyEmptyArray) {
    int result = UnsignedLongArrayDrop(&unsignedLongArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongArray.length);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayDropLessThanArrayLength) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&unsignedLongArray, 3UL);

    UnsignedLongArrayPush(&unsignedLongArray, 4UL);

    UnsignedLongArrayPush(&unsignedLongArray, 5UL);

    int result = UnsignedLongArrayDrop(&unsignedLongArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongArray.length);

    unsigned long x;

    UnsignedLongArrayAt(&unsignedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(4UL, x);

    UnsignedLongArrayAt(&unsignedLongArray, 1, &x);

    TEST_ASSERT_EQUAL(5UL, x);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayDropGreaterThanArrayLength) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&unsignedLongArray, 3UL);

    UnsignedLongArrayPush(&unsignedLongArray, 4UL);

    UnsignedLongArrayPush(&unsignedLongArray, 5UL);

    int result = UnsignedLongArrayDrop(&unsignedLongArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongArray.length);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayEmptyArrayIsEmpty) {
    int result = UnsignedLongArrayIsEmpty(&unsignedLongArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayNonEmptyArrayIsNotEmpty) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&unsignedLongArray, 3UL);

    UnsignedLongArrayPush(&unsignedLongArray, 4UL);

    UnsignedLongArrayPush(&unsignedLongArray, 5UL);

    int result = UnsignedLongArrayIsEmpty(&unsignedLongArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayPush) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&unsignedLongArray, 3UL);

    UnsignedLongArrayPush(&unsignedLongArray, 4UL);

    UnsignedLongArrayPush(&unsignedLongArray, 5UL);

    TEST_ASSERT_EQUAL(5, unsignedLongArray.length);

    unsigned long x;

    int result = UnsignedLongArrayAt(&unsignedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1UL, x);

    result = UnsignedLongArrayAt(&unsignedLongArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2UL, x);

    result = UnsignedLongArrayAt(&unsignedLongArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3UL, x);

    result = UnsignedLongArrayAt(&unsignedLongArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4UL, x);

    result = UnsignedLongArrayAt(&unsignedLongArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5UL, x);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayMultipleElementArrayToString) {
    UnsignedLongArrayPush(&unsignedLongArray, 1UL);

    UnsignedLongArrayPush(&unsignedLongArray, 2UL);

    UnsignedLongArrayPush(&unsignedLongArray, 3UL);

    UnsignedLongArrayPush(&unsignedLongArray, 4UL);

    UnsignedLongArrayPush(&unsignedLongArray, 5UL);

    char* asString;

    int result = UnsignedLongArrayToString(&unsignedLongArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[1, 2, 3, 4, 5]", asString);

    free(asString);
}
