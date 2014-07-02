#include "unsigned_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedIntArrayTests);

UnsignedIntArray unsignedIntArray;
UnsignedIntArray otherUnsignedIntArray;

TEST_SETUP(UnsignedIntArrayTests) {
    UnsignedIntArrayInitialize(&unsignedIntArray);

    UnsignedIntArrayInitialize(&otherUnsignedIntArray);
}

TEST_TEAR_DOWN(UnsignedIntArrayTests) {
    UnsignedIntArrayDeinitialize(&unsignedIntArray);

    UnsignedIntArrayDeinitialize(&otherUnsignedIntArray);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, unsignedIntArray.length);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedIntArray.capacity);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayPushOneElement) {
    int result = UnsignedIntArrayPush(&unsignedIntArray, 1U);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedIntArray.capacity);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = UnsignedIntArrayPush(&unsignedIntArray, (unsigned int)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedIntArray.capacity);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayAtZeroLength) {
    unsigned int x;

    int result = UnsignedIntArrayAt(&unsignedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayAtExistingElement) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    UnsignedIntArrayPush(&unsignedIntArray, 3U);

    UnsignedIntArrayPush(&unsignedIntArray, 4U);

    UnsignedIntArrayPush(&unsignedIntArray, 5U);

    unsigned int x;

    int result = UnsignedIntArrayAt(&unsignedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3U, x);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayAtLessThanZeroIndex) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    UnsignedIntArrayPush(&unsignedIntArray, 3U);

    UnsignedIntArrayPush(&unsignedIntArray, 4U);

    UnsignedIntArrayPush(&unsignedIntArray, 5U);

    unsigned int x;

    int result = UnsignedIntArrayAt(&unsignedIntArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4U, x);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayAtGreaterThanLengthIndex) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    UnsignedIntArrayPush(&unsignedIntArray, 3U);

    UnsignedIntArrayPush(&unsignedIntArray, 4U);

    UnsignedIntArrayPush(&unsignedIntArray, 5U);

    unsigned int x;

    int result = UnsignedIntArrayAt(&unsignedIntArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayAtLessThanNegativeLengthIndex) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    UnsignedIntArrayPush(&unsignedIntArray, 3U);

    UnsignedIntArrayPush(&unsignedIntArray, 4U);

    UnsignedIntArrayPush(&unsignedIntArray, 5U);

    unsigned int x;

    int result = UnsignedIntArrayAt(&unsignedIntArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayClear) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    UnsignedIntArrayPush(&unsignedIntArray, 3U);

    UnsignedIntArrayPush(&unsignedIntArray, 4U);

    UnsignedIntArrayPush(&unsignedIntArray, 5U);

    int result = UnsignedIntArrayClear(&unsignedIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedIntArray.length);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayConcatEmptyArrays) {
    int result = UnsignedIntArrayConcat(&unsignedIntArray, &otherUnsignedIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedIntArray.length);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayConcatEmptyArrayToNonEmptyArray) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    int result = UnsignedIntArrayConcat(&unsignedIntArray, &otherUnsignedIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedIntArray.length);

    unsigned int x;

    UnsignedIntArrayAt(&unsignedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedIntArrayAt(&unsignedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayConcatNonEmptyArrayToEmptyArray) {
    UnsignedIntArrayPush(&otherUnsignedIntArray, 1U);

    UnsignedIntArrayPush(&otherUnsignedIntArray, 2U);

    int result = UnsignedIntArrayConcat(&unsignedIntArray, &otherUnsignedIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedIntArray.length);

    unsigned int x;

    UnsignedIntArrayAt(&unsignedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedIntArrayAt(&unsignedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayConcatNonEmptyArrayToNonEmptyArray) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    UnsignedIntArrayPush(&otherUnsignedIntArray, 3U);

    UnsignedIntArrayPush(&otherUnsignedIntArray, 4U);

    int result = UnsignedIntArrayConcat(&unsignedIntArray, &otherUnsignedIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedIntArray.length);

    unsigned int x;

    UnsignedIntArrayAt(&unsignedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedIntArrayAt(&unsignedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);

    UnsignedIntArrayAt(&unsignedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3U, x);

    UnsignedIntArrayAt(&unsignedIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4U, x);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayCountEmptyArray) {
    size_t result = UnsignedIntArrayCount(&unsignedIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayCountNonEmptyArray) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    size_t result = UnsignedIntArrayCount(&unsignedIntArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayDeleteFromEmptyArray) {
    int result = UnsignedIntArrayDelete(&unsignedIntArray, 1U);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedIntArray.length);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayDeleteNonExistingElement) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    int result = UnsignedIntArrayDelete(&unsignedIntArray, 3U);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedIntArray.length);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayDeleteExistingElement) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    int result = UnsignedIntArrayDelete(&unsignedIntArray, 2U);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedIntArray.length);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayDeleteAtZeroLength) {
    int result = UnsignedIntArrayDeleteAt(&unsignedIntArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayDeleteAtExistingElement) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    UnsignedIntArrayPush(&unsignedIntArray, 3U);

    UnsignedIntArrayPush(&unsignedIntArray, 4U);

    UnsignedIntArrayPush(&unsignedIntArray, 5U);

    int result = UnsignedIntArrayDeleteAt(&unsignedIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedIntArray.length);

    unsigned int x;

    UnsignedIntArrayAt(&unsignedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedIntArrayAt(&unsignedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);

    UnsignedIntArrayAt(&unsignedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(4U, x);

    UnsignedIntArrayAt(&unsignedIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5U, x);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayDeleteAtLessThanZeroIndex) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    UnsignedIntArrayPush(&unsignedIntArray, 3U);

    UnsignedIntArrayPush(&unsignedIntArray, 4U);

    UnsignedIntArrayPush(&unsignedIntArray, 5U);

    int result = UnsignedIntArrayDeleteAt(&unsignedIntArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedIntArray.length);

    unsigned int x;

    UnsignedIntArrayAt(&unsignedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedIntArrayAt(&unsignedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);

    UnsignedIntArrayAt(&unsignedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3U, x);

    UnsignedIntArrayAt(&unsignedIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5U, x);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayDeleteAtGreaterThanLengthIndex) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    UnsignedIntArrayPush(&unsignedIntArray, 3U);

    UnsignedIntArrayPush(&unsignedIntArray, 4U);

    UnsignedIntArrayPush(&unsignedIntArray, 5U);

    int result = UnsignedIntArrayDeleteAt(&unsignedIntArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayDeleteAtLessThanNegativeLengthIndex) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    UnsignedIntArrayPush(&unsignedIntArray, 3U);

    UnsignedIntArrayPush(&unsignedIntArray, 4U);

    UnsignedIntArrayPush(&unsignedIntArray, 5U);

    int result = UnsignedIntArrayDeleteAt(&unsignedIntArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayDropOneEmptyArray) {
    int result = UnsignedIntArrayDrop(&unsignedIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedIntArray.length);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayDropManyEmptyArray) {
    int result = UnsignedIntArrayDrop(&unsignedIntArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedIntArray.length);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayDropLessThanArrayLength) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    UnsignedIntArrayPush(&unsignedIntArray, 3U);

    UnsignedIntArrayPush(&unsignedIntArray, 4U);

    UnsignedIntArrayPush(&unsignedIntArray, 5U);

    int result = UnsignedIntArrayDrop(&unsignedIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedIntArray.length);

    unsigned int x;

    UnsignedIntArrayAt(&unsignedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(4U, x);

    UnsignedIntArrayAt(&unsignedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(5U, x);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayDropGreaterThanArrayLength) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    UnsignedIntArrayPush(&unsignedIntArray, 3U);

    UnsignedIntArrayPush(&unsignedIntArray, 4U);

    UnsignedIntArrayPush(&unsignedIntArray, 5U);

    int result = UnsignedIntArrayDrop(&unsignedIntArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedIntArray.length);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayEmptyArrayIsEmpty) {
    int result = UnsignedIntArrayIsEmpty(&unsignedIntArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayNonEmptyArrayIsNotEmpty) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    UnsignedIntArrayPush(&unsignedIntArray, 3U);

    UnsignedIntArrayPush(&unsignedIntArray, 4U);

    UnsignedIntArrayPush(&unsignedIntArray, 5U);

    int result = UnsignedIntArrayIsEmpty(&unsignedIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayPush) {
    UnsignedIntArrayPush(&unsignedIntArray, 1U);

    UnsignedIntArrayPush(&unsignedIntArray, 2U);

    UnsignedIntArrayPush(&unsignedIntArray, 3U);

    UnsignedIntArrayPush(&unsignedIntArray, 4U);

    UnsignedIntArrayPush(&unsignedIntArray, 5U);

    TEST_ASSERT_EQUAL(5, unsignedIntArray.length);

    unsigned int x;

    int result = UnsignedIntArrayAt(&unsignedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1U, x);

    result = UnsignedIntArrayAt(&unsignedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2U, x);

    result = UnsignedIntArrayAt(&unsignedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3U, x);

    result = UnsignedIntArrayAt(&unsignedIntArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4U, x);

    result = UnsignedIntArrayAt(&unsignedIntArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5U, x);
}
