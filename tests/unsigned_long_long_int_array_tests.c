#include "unsigned_long_long_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedLongLongIntArrayTests);

UnsignedLongLongIntArray unsignedLongLongIntArray;
UnsignedLongLongIntArray otherUnsignedLongLongIntArray;

TEST_SETUP(UnsignedLongLongIntArrayTests) {
    UnsignedLongLongIntArrayInitialize(&unsignedLongLongIntArray);

    UnsignedLongLongIntArrayInitialize(&otherUnsignedLongLongIntArray);
}

TEST_TEAR_DOWN(UnsignedLongLongIntArrayTests) {
    UnsignedLongLongIntArrayDeinitialize(&unsignedLongLongIntArray);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, unsignedLongLongIntArray.length);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongLongIntArray.capacity);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayPushOneElement) {
    int result = UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedLongLongIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongLongIntArray.capacity);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, (unsigned long long int)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedLongLongIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedLongLongIntArray.capacity);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayAtZeroLength) {
    unsigned long long int x;

    int result = UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayAtExistingElement) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 3ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 4ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 5ULL);

    unsigned long long int x;

    int result = UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3ULL, x);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayAtLessThanZeroIndex) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 3ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 4ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 5ULL);

    unsigned long long int x;

    int result = UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4ULL, x);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayAtGreaterThanLengthIndex) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 3ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 4ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 5ULL);

    unsigned long long int x;

    int result = UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayAtLessThanNegativeLengthIndex) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 3ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 4ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 5ULL);

    unsigned long long int x;

    int result = UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayClear) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 3ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 4ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 5ULL);

    int result = UnsignedLongLongIntArrayClear(&unsignedLongLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongLongIntArray.length);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayConcatEmptyArrays) {
    int result = UnsignedLongLongIntArrayConcat(&unsignedLongLongIntArray, &otherUnsignedLongLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongLongIntArray.length);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayConcatEmptyArrayToNonEmptyArray) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    int result = UnsignedLongLongIntArrayConcat(&unsignedLongLongIntArray, &otherUnsignedLongLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongLongIntArray.length);

    unsigned long long int x;

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2ULL, x);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayConcatNonEmptyArrayToEmptyArray) {
    UnsignedLongLongIntArrayPush(&otherUnsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&otherUnsignedLongLongIntArray, 2ULL);

    int result = UnsignedLongLongIntArrayConcat(&unsignedLongLongIntArray, &otherUnsignedLongLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongLongIntArray.length);

    unsigned long long int x;

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2ULL, x);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayConcatNonEmptyArrayToNonEmptyArray) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    UnsignedLongLongIntArrayPush(&otherUnsignedLongLongIntArray, 3ULL);

    UnsignedLongLongIntArrayPush(&otherUnsignedLongLongIntArray, 4ULL);

    int result = UnsignedLongLongIntArrayConcat(&unsignedLongLongIntArray, &otherUnsignedLongLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedLongLongIntArray.length);

    unsigned long long int x;

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2ULL, x);

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3ULL, x);

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4ULL, x);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayCountEmptyArray) {
    size_t result = UnsignedLongLongIntArrayCount(&unsignedLongLongIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayCountNonEmptyArray) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    size_t result = UnsignedLongLongIntArrayCount(&unsignedLongLongIntArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteFromEmptyArray) {
    int result = UnsignedLongLongIntArrayDelete(&unsignedLongLongIntArray, 1ULL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongLongIntArray.length);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteNonExistingElement) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    int result = UnsignedLongLongIntArrayDelete(&unsignedLongLongIntArray, 3ULL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongLongIntArray.length);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteExistingElement) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    int result = UnsignedLongLongIntArrayDelete(&unsignedLongLongIntArray, 2ULL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedLongLongIntArray.length);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteAtZeroLength) {
    int result = UnsignedLongLongIntArrayDeleteAt(&unsignedLongLongIntArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteAtExistingElement) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 3ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 4ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 5ULL);

    int result = UnsignedLongLongIntArrayDeleteAt(&unsignedLongLongIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedLongLongIntArray.length);

    unsigned long long int x;

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2ULL, x);

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(4ULL, x);

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5ULL, x);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteAtLessThanZeroIndex) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 3ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 4ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 5ULL);

    int result = UnsignedLongLongIntArrayDeleteAt(&unsignedLongLongIntArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedLongLongIntArray.length);

    unsigned long long int x;

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1ULL, x);

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2ULL, x);

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3ULL, x);

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5ULL, x);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteAtGreaterThanLengthIndex) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 3ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 4ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 5ULL);

    int result = UnsignedLongLongIntArrayDeleteAt(&unsignedLongLongIntArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteAtLessThanNegativeLengthIndex) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 3ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 4ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 5ULL);

    int result = UnsignedLongLongIntArrayDeleteAt(&unsignedLongLongIntArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDropOneEmptyArray) {
    int result = UnsignedLongLongIntArrayDrop(&unsignedLongLongIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongLongIntArray.length);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDropManyEmptyArray) {
    int result = UnsignedLongLongIntArrayDrop(&unsignedLongLongIntArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongLongIntArray.length);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDropLessThanArrayLength) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 3ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 4ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 5ULL);

    int result = UnsignedLongLongIntArrayDrop(&unsignedLongLongIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedLongLongIntArray.length);

    unsigned long long int x;

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(4ULL, x);

    UnsignedLongLongIntArrayAt(&unsignedLongLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(5ULL, x);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDropGreaterThanArrayLength) {
    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 2ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 3ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 4ULL);

    UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 5ULL);

    int result = UnsignedLongLongIntArrayDrop(&unsignedLongLongIntArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedLongLongIntArray.length);
}
