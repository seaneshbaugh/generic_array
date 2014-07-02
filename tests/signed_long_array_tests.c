#include "signed_long_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedLongArrayTests);

SignedLongArray signedLongArray;
SignedLongArray otherSignedLongArray;

TEST_SETUP(SignedLongArrayTests) {
    SignedLongArrayInitialize(&signedLongArray);

    SignedLongArrayInitialize(&otherSignedLongArray);
}

TEST_TEAR_DOWN(SignedLongArrayTests) {
    SignedLongArrayDeinitialize(&signedLongArray);

    SignedLongArrayDeinitialize(&otherSignedLongArray);
}

TEST(SignedLongArrayTests, SignedLongArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, signedLongArray.length);
}

TEST(SignedLongArrayTests, SignedLongArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongArray.capacity);
}

TEST(SignedLongArrayTests, SignedLongArrayPushOneElement) {
    int result = SignedLongArrayPush(&signedLongArray, 1L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedLongArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongArray.capacity);
}

TEST(SignedLongArrayTests, SignedLongArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = SignedLongArrayPush(&signedLongArray, (signed long)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedLongArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedLongArray.capacity);
}

TEST(SignedLongArrayTests, SignedLongArrayAtZeroLength) {
    signed long x;

    int result = SignedLongArrayAt(&signedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongArrayTests, SignedLongArrayAtExistingElement) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    SignedLongArrayPush(&signedLongArray, 3L);

    SignedLongArrayPush(&signedLongArray, 4L);

    SignedLongArrayPush(&signedLongArray, 5L);

    signed long x;

    int result = SignedLongArrayAt(&signedLongArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3L, x);
}

TEST(SignedLongArrayTests, SignedLongArrayAtLessThanZeroIndex) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    SignedLongArrayPush(&signedLongArray, 3L);

    SignedLongArrayPush(&signedLongArray, 4L);

    SignedLongArrayPush(&signedLongArray, 5L);

    signed long x;

    int result = SignedLongArrayAt(&signedLongArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4L, x);
}

TEST(SignedLongArrayTests, SignedLongArrayAtGreaterThanLengthIndex) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    SignedLongArrayPush(&signedLongArray, 3L);

    SignedLongArrayPush(&signedLongArray, 4L);

    SignedLongArrayPush(&signedLongArray, 5L);

    signed long x;

    int result = SignedLongArrayAt(&signedLongArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongArrayTests, SignedLongArrayAtLessThanNegativeLengthIndex) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    SignedLongArrayPush(&signedLongArray, 3L);

    SignedLongArrayPush(&signedLongArray, 4L);

    SignedLongArrayPush(&signedLongArray, 5L);

    signed long x;

    int result = SignedLongArrayAt(&signedLongArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongArrayTests, SignedLongArrayClear) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    SignedLongArrayPush(&signedLongArray, 3L);

    SignedLongArrayPush(&signedLongArray, 4L);

    SignedLongArrayPush(&signedLongArray, 5L);

    int result = SignedLongArrayClear(&signedLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongArray.length);
}

TEST(SignedLongArrayTests, SignedLongArrayConcatEmptyArrays) {
    int result = SignedLongArrayConcat(&signedLongArray, &otherSignedLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongArray.length);
}

TEST(SignedLongArrayTests, SignedLongArrayConcatEmptyArrayToNonEmptyArray) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    int result = SignedLongArrayConcat(&signedLongArray, &otherSignedLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongArray.length);

    signed long x;

    SignedLongArrayAt(&signedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    SignedLongArrayAt(&signedLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);
}

TEST(SignedLongArrayTests, SignedLongArrayConcatNonEmptyArrayToEmptyArray) {
    SignedLongArrayPush(&otherSignedLongArray, 1L);

    SignedLongArrayPush(&otherSignedLongArray, 2L);

    int result = SignedLongArrayConcat(&signedLongArray, &otherSignedLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongArray.length);

    signed long x;

    SignedLongArrayAt(&signedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    SignedLongArrayAt(&signedLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);
}

TEST(SignedLongArrayTests, SignedLongArrayConcatNonEmptyArrayToNonEmptyArray) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    SignedLongArrayPush(&otherSignedLongArray, 3L);

    SignedLongArrayPush(&otherSignedLongArray, 4L);

    int result = SignedLongArrayConcat(&signedLongArray, &otherSignedLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedLongArray.length);

    signed long x;

    SignedLongArrayAt(&signedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    SignedLongArrayAt(&signedLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);

    SignedLongArrayAt(&signedLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3L, x);

    SignedLongArrayAt(&signedLongArray, 3, &x);

    TEST_ASSERT_EQUAL(4L, x);
}

TEST(SignedLongArrayTests, SignedLongArrayCountEmptyArray) {
    size_t result = SignedLongArrayCount(&signedLongArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(SignedLongArrayTests, SignedLongArrayCountNonEmptyArray) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    size_t result = SignedLongArrayCount(&signedLongArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(SignedLongArrayTests, SignedLongArrayDeleteFromEmptyArray) {
    int result = SignedLongArrayDelete(&signedLongArray, 1L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongArray.length);
}

TEST(SignedLongArrayTests, SignedLongArrayDeleteNonExistingElement) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    int result = SignedLongArrayDelete(&signedLongArray, 3L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongArray.length);
}

TEST(SignedLongArrayTests, SignedLongArrayDeleteExistingElement) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    int result = SignedLongArrayDelete(&signedLongArray, 2L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedLongArray.length);
}

TEST(SignedLongArrayTests, SignedLongArrayDeleteAtZeroLength) {
    int result = SignedLongArrayDeleteAt(&signedLongArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongArrayTests, SignedLongArrayDeleteAtExistingElement) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    SignedLongArrayPush(&signedLongArray, 3L);

    SignedLongArrayPush(&signedLongArray, 4L);

    SignedLongArrayPush(&signedLongArray, 5L);

    int result = SignedLongArrayDeleteAt(&signedLongArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedLongArray.length);

    signed long x;

    SignedLongArrayAt(&signedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    SignedLongArrayAt(&signedLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);

    SignedLongArrayAt(&signedLongArray, 2, &x);

    TEST_ASSERT_EQUAL(4L, x);

    SignedLongArrayAt(&signedLongArray, 3, &x);

    TEST_ASSERT_EQUAL(5L, x);
}

TEST(SignedLongArrayTests, SignedLongArrayDeleteAtLessThanZeroIndex) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    SignedLongArrayPush(&signedLongArray, 3L);

    SignedLongArrayPush(&signedLongArray, 4L);

    SignedLongArrayPush(&signedLongArray, 5L);

    int result = SignedLongArrayDeleteAt(&signedLongArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedLongArray.length);

    signed long x;

    SignedLongArrayAt(&signedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    SignedLongArrayAt(&signedLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);

    SignedLongArrayAt(&signedLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3L, x);

    SignedLongArrayAt(&signedLongArray, 3, &x);

    TEST_ASSERT_EQUAL(5L, x);
}

TEST(SignedLongArrayTests, SignedLongArrayDeleteAtGreaterThanLengthIndex) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    SignedLongArrayPush(&signedLongArray, 3L);

    SignedLongArrayPush(&signedLongArray, 4L);

    SignedLongArrayPush(&signedLongArray, 5L);

    int result = SignedLongArrayDeleteAt(&signedLongArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongArrayTests, SignedLongArrayDeleteAtLessThanNegativeLengthIndex) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    SignedLongArrayPush(&signedLongArray, 3L);

    SignedLongArrayPush(&signedLongArray, 4L);

    SignedLongArrayPush(&signedLongArray, 5L);

    int result = SignedLongArrayDeleteAt(&signedLongArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongArrayTests, SignedLongArrayDropOneEmptyArray) {
    int result = SignedLongArrayDrop(&signedLongArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongArray.length);
}

TEST(SignedLongArrayTests, SignedLongArrayDropManyEmptyArray) {
    int result = SignedLongArrayDrop(&signedLongArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongArray.length);
}

TEST(SignedLongArrayTests, SignedLongArrayDropLessThanArrayLength) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    SignedLongArrayPush(&signedLongArray, 3L);

    SignedLongArrayPush(&signedLongArray, 4L);

    SignedLongArrayPush(&signedLongArray, 5L);

    int result = SignedLongArrayDrop(&signedLongArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongArray.length);

    signed long x;

    SignedLongArrayAt(&signedLongArray, 0, &x);

    TEST_ASSERT_EQUAL(4L, x);

    SignedLongArrayAt(&signedLongArray, 1, &x);

    TEST_ASSERT_EQUAL(5L, x);
}

TEST(SignedLongArrayTests, SignedLongArrayDropGreaterThanArrayLength) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    SignedLongArrayPush(&signedLongArray, 3L);

    SignedLongArrayPush(&signedLongArray, 4L);

    SignedLongArrayPush(&signedLongArray, 5L);

    int result = SignedLongArrayDrop(&signedLongArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongArray.length);
}

TEST(SignedLongArrayTests, SignedLongArrayEmptyArrayIsEmpty) {
    int result = SignedLongArrayIsEmpty(&signedLongArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(SignedLongArrayTests, SignedLongArrayNonEmptyArrayIsNotEmpty) {
    SignedLongArrayPush(&signedLongArray, 1L);

    SignedLongArrayPush(&signedLongArray, 2L);

    SignedLongArrayPush(&signedLongArray, 3L);

    SignedLongArrayPush(&signedLongArray, 4L);

    SignedLongArrayPush(&signedLongArray, 5L);

    int result = SignedLongArrayIsEmpty(&signedLongArray);

    TEST_ASSERT_EQUAL(0, result);
}
