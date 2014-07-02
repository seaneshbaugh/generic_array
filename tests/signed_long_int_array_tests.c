#include "signed_long_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedLongIntArrayTests);

SignedLongIntArray signedLongIntArray;
SignedLongIntArray otherSignedLongIntArray;

TEST_SETUP(SignedLongIntArrayTests) {
    SignedLongIntArrayInitialize(&signedLongIntArray);

    SignedLongIntArrayInitialize(&otherSignedLongIntArray);
}

TEST_TEAR_DOWN(SignedLongIntArrayTests) {
    SignedLongIntArrayDeinitialize(&signedLongIntArray);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, signedLongIntArray.length);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongIntArray.capacity);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayPushOneElement) {
    int result = SignedLongIntArrayPush(&signedLongIntArray, 1L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedLongIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongIntArray.capacity);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = SignedLongIntArrayPush(&signedLongIntArray, (signed long int)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedLongIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedLongIntArray.capacity);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayAtZeroLength) {
    signed long int x;

    int result = SignedLongIntArrayAt(&signedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayAtExistingElement) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    SignedLongIntArrayPush(&signedLongIntArray, 3L);

    SignedLongIntArrayPush(&signedLongIntArray, 4L);

    SignedLongIntArrayPush(&signedLongIntArray, 5L);

    signed long int x;

    int result = SignedLongIntArrayAt(&signedLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3L, x);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayAtLessThanZeroIndex) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    SignedLongIntArrayPush(&signedLongIntArray, 3L);

    SignedLongIntArrayPush(&signedLongIntArray, 4L);

    SignedLongIntArrayPush(&signedLongIntArray, 5L);

    signed long int x;

    int result = SignedLongIntArrayAt(&signedLongIntArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4L, x);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayAtGreaterThanLengthIndex) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    SignedLongIntArrayPush(&signedLongIntArray, 3L);

    SignedLongIntArrayPush(&signedLongIntArray, 4L);

    SignedLongIntArrayPush(&signedLongIntArray, 5L);

    signed long int x;

    int result = SignedLongIntArrayAt(&signedLongIntArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayAtLessThanNegativeLengthIndex) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    SignedLongIntArrayPush(&signedLongIntArray, 3L);

    SignedLongIntArrayPush(&signedLongIntArray, 4L);

    SignedLongIntArrayPush(&signedLongIntArray, 5L);

    signed long int x;

    int result = SignedLongIntArrayAt(&signedLongIntArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayClear) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    SignedLongIntArrayPush(&signedLongIntArray, 3L);

    SignedLongIntArrayPush(&signedLongIntArray, 4L);

    SignedLongIntArrayPush(&signedLongIntArray, 5L);

    int result = SignedLongIntArrayClear(&signedLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongIntArray.length);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayConcatEmptyArrays) {
    int result = SignedLongIntArrayConcat(&signedLongIntArray, &otherSignedLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongIntArray.length);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayConcatEmptyArrayToNonEmptyArray) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    int result = SignedLongIntArrayConcat(&signedLongIntArray, &otherSignedLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongIntArray.length);

    signed long int x;

    SignedLongIntArrayAt(&signedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    SignedLongIntArrayAt(&signedLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayConcatNonEmptyArrayToEmptyArray) {
    SignedLongIntArrayPush(&otherSignedLongIntArray, 1L);

    SignedLongIntArrayPush(&otherSignedLongIntArray, 2L);

    int result = SignedLongIntArrayConcat(&signedLongIntArray, &otherSignedLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongIntArray.length);

    signed long int x;

    SignedLongIntArrayAt(&signedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    SignedLongIntArrayAt(&signedLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayConcatNonEmptyArrayToNonEmptyArray) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    SignedLongIntArrayPush(&otherSignedLongIntArray, 3L);

    SignedLongIntArrayPush(&otherSignedLongIntArray, 4L);

    int result = SignedLongIntArrayConcat(&signedLongIntArray, &otherSignedLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedLongIntArray.length);

    signed long int x;

    SignedLongIntArrayAt(&signedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    SignedLongIntArrayAt(&signedLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);

    SignedLongIntArrayAt(&signedLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3L, x);

    SignedLongIntArrayAt(&signedLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4L, x);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayCountEmptyArray) {
    size_t result = SignedLongIntArrayCount(&signedLongIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayCountNonEmptyArray) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    size_t result = SignedLongIntArrayCount(&signedLongIntArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayDeleteFromEmptyArray) {
    int result = SignedLongIntArrayDelete(&signedLongIntArray, 1L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongIntArray.length);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayDeleteNonExistingElement) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    int result = SignedLongIntArrayDelete(&signedLongIntArray, 3L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongIntArray.length);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayDeleteExistingElement) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    int result = SignedLongIntArrayDelete(&signedLongIntArray, 2L);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedLongIntArray.length);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayDeleteAtZeroLength) {
    int result = SignedLongIntArrayDeleteAt(&signedLongIntArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayDeleteAtExistingElement) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    SignedLongIntArrayPush(&signedLongIntArray, 3L);

    SignedLongIntArrayPush(&signedLongIntArray, 4L);

    SignedLongIntArrayPush(&signedLongIntArray, 5L);

    int result = SignedLongIntArrayDeleteAt(&signedLongIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedLongIntArray.length);

    signed long int x;

    SignedLongIntArrayAt(&signedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    SignedLongIntArrayAt(&signedLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);

    SignedLongIntArrayAt(&signedLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(4L, x);

    SignedLongIntArrayAt(&signedLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5L, x);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayDeleteAtLessThanZeroIndex) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    SignedLongIntArrayPush(&signedLongIntArray, 3L);

    SignedLongIntArrayPush(&signedLongIntArray, 4L);

    SignedLongIntArrayPush(&signedLongIntArray, 5L);

    int result = SignedLongIntArrayDeleteAt(&signedLongIntArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedLongIntArray.length);

    signed long int x;

    SignedLongIntArrayAt(&signedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1L, x);

    SignedLongIntArrayAt(&signedLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2L, x);

    SignedLongIntArrayAt(&signedLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3L, x);

    SignedLongIntArrayAt(&signedLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5L, x);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayDeleteAtGreaterThanLengthIndex) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    SignedLongIntArrayPush(&signedLongIntArray, 3L);

    SignedLongIntArrayPush(&signedLongIntArray, 4L);

    SignedLongIntArrayPush(&signedLongIntArray, 5L);

    int result = SignedLongIntArrayDeleteAt(&signedLongIntArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayDeleteAtLessThanNegativeLengthIndex) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    SignedLongIntArrayPush(&signedLongIntArray, 3L);

    SignedLongIntArrayPush(&signedLongIntArray, 4L);

    SignedLongIntArrayPush(&signedLongIntArray, 5L);

    int result = SignedLongIntArrayDeleteAt(&signedLongIntArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayDropOneEmptyArray) {
    int result = SignedLongIntArrayDrop(&signedLongIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongIntArray.length);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayDropManyEmptyArray) {
    int result = SignedLongIntArrayDrop(&signedLongIntArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongIntArray.length);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayDropLessThanArrayLength) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    SignedLongIntArrayPush(&signedLongIntArray, 3L);

    SignedLongIntArrayPush(&signedLongIntArray, 4L);

    SignedLongIntArrayPush(&signedLongIntArray, 5L);

    int result = SignedLongIntArrayDrop(&signedLongIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongIntArray.length);

    signed long int x;

    SignedLongIntArrayAt(&signedLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(4L, x);

    SignedLongIntArrayAt(&signedLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(5L, x);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayDropGreaterThanArrayLength) {
    SignedLongIntArrayPush(&signedLongIntArray, 1L);

    SignedLongIntArrayPush(&signedLongIntArray, 2L);

    SignedLongIntArrayPush(&signedLongIntArray, 3L);

    SignedLongIntArrayPush(&signedLongIntArray, 4L);

    SignedLongIntArrayPush(&signedLongIntArray, 5L);

    int result = SignedLongIntArrayDrop(&signedLongIntArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongIntArray.length);
}
