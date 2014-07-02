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
