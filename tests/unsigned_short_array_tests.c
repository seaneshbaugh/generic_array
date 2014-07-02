#include "unsigned_short_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedShortArrayTests);

UnsignedShortArray unsignedShortArray;
UnsignedShortArray otherUnsignedShortArray;

TEST_SETUP(UnsignedShortArrayTests) {
    UnsignedShortArrayInitialize(&unsignedShortArray);

    UnsignedShortArrayInitialize(&otherUnsignedShortArray);
}

TEST_TEAR_DOWN(UnsignedShortArrayTests) {
    UnsignedShortArrayDeinitialize(&unsignedShortArray);

    UnsignedShortArrayDeinitialize(&otherUnsignedShortArray);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, unsignedShortArray.length);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedShortArray.capacity);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayPushOneElement) {
    int result = UnsignedShortArrayPush(&unsignedShortArray, 1U);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedShortArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedShortArray.capacity);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = UnsignedShortArrayPush(&unsignedShortArray, (unsigned short)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedShortArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedShortArray.capacity);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayAtZeroLength) {
    unsigned short x;

    int result = UnsignedShortArrayAt(&unsignedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayAtExistingElement) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    UnsignedShortArrayPush(&unsignedShortArray, 3U);

    UnsignedShortArrayPush(&unsignedShortArray, 4U);

    UnsignedShortArrayPush(&unsignedShortArray, 5U);

    unsigned short x;

    int result = UnsignedShortArrayAt(&unsignedShortArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3U, x);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayAtLessThanZeroIndex) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    UnsignedShortArrayPush(&unsignedShortArray, 3U);

    UnsignedShortArrayPush(&unsignedShortArray, 4U);

    UnsignedShortArrayPush(&unsignedShortArray, 5U);

    unsigned short x;

    int result = UnsignedShortArrayAt(&unsignedShortArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4U, x);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayAtGreaterThanLengthIndex) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    UnsignedShortArrayPush(&unsignedShortArray, 3U);

    UnsignedShortArrayPush(&unsignedShortArray, 4U);

    UnsignedShortArrayPush(&unsignedShortArray, 5U);

    unsigned short x;

    int result = UnsignedShortArrayAt(&unsignedShortArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayAtLessThanNegativeLengthIndex) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    UnsignedShortArrayPush(&unsignedShortArray, 3U);

    UnsignedShortArrayPush(&unsignedShortArray, 4U);

    UnsignedShortArrayPush(&unsignedShortArray, 5U);

    unsigned short x;

    int result = UnsignedShortArrayAt(&unsignedShortArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayClear) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    UnsignedShortArrayPush(&unsignedShortArray, 3U);

    UnsignedShortArrayPush(&unsignedShortArray, 4U);

    UnsignedShortArrayPush(&unsignedShortArray, 5U);

    int result = UnsignedShortArrayClear(&unsignedShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedShortArray.length);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayConcatEmptyArrays) {
    int result = UnsignedShortArrayConcat(&unsignedShortArray, &otherUnsignedShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedShortArray.length);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayConcatEmptyArrayToNonEmptyArray) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    int result = UnsignedShortArrayConcat(&unsignedShortArray, &otherUnsignedShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedShortArray.length);

    unsigned short x;

    UnsignedShortArrayAt(&unsignedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortArrayAt(&unsignedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayConcatNonEmptyArrayToEmptyArray) {
    UnsignedShortArrayPush(&otherUnsignedShortArray, 1U);

    UnsignedShortArrayPush(&otherUnsignedShortArray, 2U);

    int result = UnsignedShortArrayConcat(&unsignedShortArray, &otherUnsignedShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedShortArray.length);

    unsigned short x;

    UnsignedShortArrayAt(&unsignedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortArrayAt(&unsignedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayConcatNonEmptyArrayToNonEmptyArray) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    UnsignedShortArrayPush(&otherUnsignedShortArray, 3U);

    UnsignedShortArrayPush(&otherUnsignedShortArray, 4U);

    int result = UnsignedShortArrayConcat(&unsignedShortArray, &otherUnsignedShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedShortArray.length);

    unsigned short x;

    UnsignedShortArrayAt(&unsignedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortArrayAt(&unsignedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);

    UnsignedShortArrayAt(&unsignedShortArray, 2, &x);

    TEST_ASSERT_EQUAL(3U, x);

    UnsignedShortArrayAt(&unsignedShortArray, 3, &x);

    TEST_ASSERT_EQUAL(4U, x);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayCountEmptyArray) {
    size_t result = UnsignedShortArrayCount(&unsignedShortArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayCountNonEmptyArray) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    size_t result = UnsignedShortArrayCount(&unsignedShortArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayDeleteFromEmptyArray) {
    int result = UnsignedShortArrayDelete(&unsignedShortArray, 1U);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedShortArray.length);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayDeleteNonExistingElement) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    int result = UnsignedShortArrayDelete(&unsignedShortArray, 3U);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedShortArray.length);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayDeleteExistingElement) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    int result = UnsignedShortArrayDelete(&unsignedShortArray, 2U);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedShortArray.length);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayDeleteAtZeroLength) {
    int result = UnsignedShortArrayDeleteAt(&unsignedShortArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayDeleteAtExistingElement) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    UnsignedShortArrayPush(&unsignedShortArray, 3U);

    UnsignedShortArrayPush(&unsignedShortArray, 4U);

    UnsignedShortArrayPush(&unsignedShortArray, 5U);

    int result = UnsignedShortArrayDeleteAt(&unsignedShortArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedShortArray.length);

    unsigned short x;

    UnsignedShortArrayAt(&unsignedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortArrayAt(&unsignedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);

    UnsignedShortArrayAt(&unsignedShortArray, 2, &x);

    TEST_ASSERT_EQUAL(4U, x);

    UnsignedShortArrayAt(&unsignedShortArray, 3, &x);

    TEST_ASSERT_EQUAL(5U, x);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayDeleteAtLessThanZeroIndex) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    UnsignedShortArrayPush(&unsignedShortArray, 3U);

    UnsignedShortArrayPush(&unsignedShortArray, 4U);

    UnsignedShortArrayPush(&unsignedShortArray, 5U);

    int result = UnsignedShortArrayDeleteAt(&unsignedShortArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedShortArray.length);

    unsigned short x;

    UnsignedShortArrayAt(&unsignedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(1U, x);

    UnsignedShortArrayAt(&unsignedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(2U, x);

    UnsignedShortArrayAt(&unsignedShortArray, 2, &x);

    TEST_ASSERT_EQUAL(3U, x);

    UnsignedShortArrayAt(&unsignedShortArray, 3, &x);

    TEST_ASSERT_EQUAL(5U, x);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayDeleteAtGreaterThanLengthIndex) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    UnsignedShortArrayPush(&unsignedShortArray, 3U);

    UnsignedShortArrayPush(&unsignedShortArray, 4U);

    UnsignedShortArrayPush(&unsignedShortArray, 5U);

    int result = UnsignedShortArrayDeleteAt(&unsignedShortArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayDeleteAtLessThanNegativeLengthIndex) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    UnsignedShortArrayPush(&unsignedShortArray, 3U);

    UnsignedShortArrayPush(&unsignedShortArray, 4U);

    UnsignedShortArrayPush(&unsignedShortArray, 5U);

    int result = UnsignedShortArrayDeleteAt(&unsignedShortArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayDropOneEmptyArray) {
    int result = UnsignedShortArrayDrop(&unsignedShortArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedShortArray.length);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayDropManyEmptyArray) {
    int result = UnsignedShortArrayDrop(&unsignedShortArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedShortArray.length);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayDropLessThanArrayLength) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    UnsignedShortArrayPush(&unsignedShortArray, 3U);

    UnsignedShortArrayPush(&unsignedShortArray, 4U);

    UnsignedShortArrayPush(&unsignedShortArray, 5U);

    int result = UnsignedShortArrayDrop(&unsignedShortArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedShortArray.length);

    unsigned short x;

    UnsignedShortArrayAt(&unsignedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(4U, x);

    UnsignedShortArrayAt(&unsignedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(5U, x);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayDropGreaterThanArrayLength) {
    UnsignedShortArrayPush(&unsignedShortArray, 1U);

    UnsignedShortArrayPush(&unsignedShortArray, 2U);

    UnsignedShortArrayPush(&unsignedShortArray, 3U);

    UnsignedShortArrayPush(&unsignedShortArray, 4U);

    UnsignedShortArrayPush(&unsignedShortArray, 5U);

    int result = UnsignedShortArrayDrop(&unsignedShortArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedShortArray.length);
}
