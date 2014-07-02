#include "unsigned_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedArrayTests);

UnsignedArray unsignedArray;
UnsignedArray otherUnsignedArray;

TEST_SETUP(UnsignedArrayTests) {
    UnsignedArrayInitialize(&unsignedArray);

    UnsignedArrayInitialize(&otherUnsignedArray);
}

TEST_TEAR_DOWN(UnsignedArrayTests) {
    UnsignedArrayDeinitialize(&unsignedArray);
}

TEST(UnsignedArrayTests, UnsignedArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, unsignedArray.length);
}

TEST(UnsignedArrayTests, UnsignedArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedArray.capacity);
}

TEST(UnsignedArrayTests, UnsignedArrayPushOneElement) {
    int result = UnsignedArrayPush(&unsignedArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedArray.capacity);
}

TEST(UnsignedArrayTests, UnsignedArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = UnsignedArrayPush(&unsignedArray, (unsigned)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedArray.capacity);
}

TEST(UnsignedArrayTests, UnsignedArrayAtZeroLength) {
    unsigned x;

    int result = UnsignedArrayAt(&unsignedArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedArrayTests, UnsignedArrayAtExistingElement) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    UnsignedArrayPush(&unsignedArray, 3);

    UnsignedArrayPush(&unsignedArray, 4);

    UnsignedArrayPush(&unsignedArray, 5);

    unsigned x;

    int result = UnsignedArrayAt(&unsignedArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);
}

TEST(UnsignedArrayTests, UnsignedArrayAtLessThanZeroIndex) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    UnsignedArrayPush(&unsignedArray, 3);

    UnsignedArrayPush(&unsignedArray, 4);

    UnsignedArrayPush(&unsignedArray, 5);

    unsigned x;

    int result = UnsignedArrayAt(&unsignedArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(UnsignedArrayTests, UnsignedArrayAtGreaterThanLengthIndex) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    UnsignedArrayPush(&unsignedArray, 3);

    UnsignedArrayPush(&unsignedArray, 4);

    UnsignedArrayPush(&unsignedArray, 5);

    unsigned x;

    int result = UnsignedArrayAt(&unsignedArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedArrayTests, UnsignedArrayAtLessThanNegativeLengthIndex) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    UnsignedArrayPush(&unsignedArray, 3);

    UnsignedArrayPush(&unsignedArray, 4);

    UnsignedArrayPush(&unsignedArray, 5);

    unsigned x;

    int result = UnsignedArrayAt(&unsignedArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedArrayTests, UnsignedArrayClear) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    UnsignedArrayPush(&unsignedArray, 3);

    UnsignedArrayPush(&unsignedArray, 4);

    UnsignedArrayPush(&unsignedArray, 5);

    int result = UnsignedArrayClear(&unsignedArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedArray.length);
}

TEST(UnsignedArrayTests, UnsignedArrayConcatEmptyArrays) {
    int result = UnsignedArrayConcat(&unsignedArray, &otherUnsignedArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedArray.length);
}

TEST(UnsignedArrayTests, UnsignedArrayConcatEmptyArrayToNonEmptyArray) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    int result = UnsignedArrayConcat(&unsignedArray, &otherUnsignedArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedArray.length);

    unsigned x;

    UnsignedArrayAt(&unsignedArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    UnsignedArrayAt(&unsignedArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(UnsignedArrayTests, UnsignedArrayConcatNonEmptyArrayToEmptyArray) {
    UnsignedArrayPush(&otherUnsignedArray, 1);

    UnsignedArrayPush(&otherUnsignedArray, 2);

    int result = UnsignedArrayConcat(&unsignedArray, &otherUnsignedArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedArray.length);

    unsigned x;

    UnsignedArrayAt(&unsignedArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    UnsignedArrayAt(&unsignedArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(UnsignedArrayTests, UnsignedArrayConcatNonEmptyArrayToNonEmptyArray) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    UnsignedArrayPush(&otherUnsignedArray, 3);

    UnsignedArrayPush(&otherUnsignedArray, 4);

    int result = UnsignedArrayConcat(&unsignedArray, &otherUnsignedArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedArray.length);

    unsigned x;

    UnsignedArrayAt(&unsignedArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    UnsignedArrayAt(&unsignedArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    UnsignedArrayAt(&unsignedArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    UnsignedArrayAt(&unsignedArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(UnsignedArrayTests, UnsignedArrayCountEmptyArray) {
    size_t result = UnsignedArrayCount(&unsignedArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedArrayTests, UnsignedArrayCountNonEmptyArray) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    size_t result = UnsignedArrayCount(&unsignedArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(UnsignedArrayTests, UnsignedArrayDeleteFromEmptyArray) {
    int result = UnsignedArrayDelete(&unsignedArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedArray.length);
}

TEST(UnsignedArrayTests, UnsignedArrayDeleteNonExistingElement) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    int result = UnsignedArrayDelete(&unsignedArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedArray.length);
}

TEST(UnsignedArrayTests, UnsignedArrayDeleteExistingElement) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    int result = UnsignedArrayDelete(&unsignedArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedArray.length);
}

TEST(UnsignedArrayTests, UnsignedArrayDeleteAtZeroLength) {
    int result = UnsignedArrayDeleteAt(&unsignedArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedArrayTests, UnsignedArrayDeleteAtExistingElement) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    UnsignedArrayPush(&unsignedArray, 3);

    UnsignedArrayPush(&unsignedArray, 4);

    UnsignedArrayPush(&unsignedArray, 5);

    int result = UnsignedArrayDeleteAt(&unsignedArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedArray.length);

    unsigned x;

    UnsignedArrayAt(&unsignedArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    UnsignedArrayAt(&unsignedArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    UnsignedArrayAt(&unsignedArray, 2, &x);

    TEST_ASSERT_EQUAL(4, x);

    UnsignedArrayAt(&unsignedArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(UnsignedArrayTests, UnsignedArrayDeleteAtLessThanZeroIndex) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    UnsignedArrayPush(&unsignedArray, 3);

    UnsignedArrayPush(&unsignedArray, 4);

    UnsignedArrayPush(&unsignedArray, 5);

    int result = UnsignedArrayDeleteAt(&unsignedArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedArray.length);

    unsigned x;

    UnsignedArrayAt(&unsignedArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    UnsignedArrayAt(&unsignedArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    UnsignedArrayAt(&unsignedArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    UnsignedArrayAt(&unsignedArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(UnsignedArrayTests, UnsignedArrayDeleteAtGreaterThanLengthIndex) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    UnsignedArrayPush(&unsignedArray, 3);

    UnsignedArrayPush(&unsignedArray, 4);

    UnsignedArrayPush(&unsignedArray, 5);

    int result = UnsignedArrayDeleteAt(&unsignedArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedArrayTests, UnsignedArrayDeleteAtLessThanNegativeLengthIndex) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    UnsignedArrayPush(&unsignedArray, 3);

    UnsignedArrayPush(&unsignedArray, 4);

    UnsignedArrayPush(&unsignedArray, 5);

    int result = UnsignedArrayDeleteAt(&unsignedArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedArrayTests, UnsignedArrayDropOneEmptyArray) {
    int result = UnsignedArrayDrop(&unsignedArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedArray.length);
}

TEST(UnsignedArrayTests, UnsignedArrayDropManyEmptyArray) {
    int result = UnsignedArrayDrop(&unsignedArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedArray.length);
}

TEST(UnsignedArrayTests, UnsignedArrayDropLessThanArrayLength) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    UnsignedArrayPush(&unsignedArray, 3);

    UnsignedArrayPush(&unsignedArray, 4);

    UnsignedArrayPush(&unsignedArray, 5);

    int result = UnsignedArrayDrop(&unsignedArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedArray.length);

    unsigned x;

    UnsignedArrayAt(&unsignedArray, 0, &x);

    TEST_ASSERT_EQUAL(4, x);

    UnsignedArrayAt(&unsignedArray, 1, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(UnsignedArrayTests, UnsignedArrayDropGreaterThanArrayLength) {
    UnsignedArrayPush(&unsignedArray, 1);

    UnsignedArrayPush(&unsignedArray, 2);

    UnsignedArrayPush(&unsignedArray, 3);

    UnsignedArrayPush(&unsignedArray, 4);

    UnsignedArrayPush(&unsignedArray, 5);

    int result = UnsignedArrayDrop(&unsignedArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedArray.length);
}
