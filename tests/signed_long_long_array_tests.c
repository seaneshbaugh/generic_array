#include "signed_long_long_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedLongLongArrayTests);

SignedLongLongArray signedLongLongArray;
SignedLongLongArray otherSignedLongLongArray;

TEST_SETUP(SignedLongLongArrayTests) {
    SignedLongLongArrayInitialize(&signedLongLongArray);

    SignedLongLongArrayInitialize(&otherSignedLongLongArray);
}

TEST_TEAR_DOWN(SignedLongLongArrayTests) {
    SignedLongLongArrayDeinitialize(&signedLongLongArray);

    SignedLongLongArrayDeinitialize(&otherSignedLongLongArray);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, signedLongLongArray.length);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongLongArray.capacity);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayPushOneElement) {
    int result = SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedLongLongArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongLongArray.capacity);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = SignedLongLongArrayPush(&signedLongLongArray, (signed long long)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedLongLongArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedLongLongArray.capacity);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayAtZeroLength) {
    signed long long x;

    int result = SignedLongLongArrayAt(&signedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayAtExistingElement) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    SignedLongLongArrayPush(&signedLongLongArray, 3LL);

    SignedLongLongArrayPush(&signedLongLongArray, 4LL);

    SignedLongLongArrayPush(&signedLongLongArray, 5LL);

    signed long long x;

    int result = SignedLongLongArrayAt(&signedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3LL, x);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayAtLessThanZeroIndex) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    SignedLongLongArrayPush(&signedLongLongArray, 3LL);

    SignedLongLongArrayPush(&signedLongLongArray, 4LL);

    SignedLongLongArrayPush(&signedLongLongArray, 5LL);

    signed long long x;

    int result = SignedLongLongArrayAt(&signedLongLongArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4LL, x);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayAtGreaterThanLengthIndex) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    SignedLongLongArrayPush(&signedLongLongArray, 3LL);

    SignedLongLongArrayPush(&signedLongLongArray, 4LL);

    SignedLongLongArrayPush(&signedLongLongArray, 5LL);

    signed long long x;

    int result = SignedLongLongArrayAt(&signedLongLongArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayAtLessThanNegativeLengthIndex) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    SignedLongLongArrayPush(&signedLongLongArray, 3LL);

    SignedLongLongArrayPush(&signedLongLongArray, 4LL);

    SignedLongLongArrayPush(&signedLongLongArray, 5LL);

    signed long long x;

    int result = SignedLongLongArrayAt(&signedLongLongArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayClear) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    SignedLongLongArrayPush(&signedLongLongArray, 3LL);

    SignedLongLongArrayPush(&signedLongLongArray, 4LL);

    SignedLongLongArrayPush(&signedLongLongArray, 5LL);

    int result = SignedLongLongArrayClear(&signedLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongLongArray.length);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayConcatEmptyArrays) {
    int result = SignedLongLongArrayConcat(&signedLongLongArray, &otherSignedLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongLongArray.length);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayConcatEmptyArrayToNonEmptyArray) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    int result = SignedLongLongArrayConcat(&signedLongLongArray, &otherSignedLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongLongArray.length);

    signed long long x;

    SignedLongLongArrayAt(&signedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1LL, x);

    SignedLongLongArrayAt(&signedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2LL, x);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayConcatNonEmptyArrayToEmptyArray) {
    SignedLongLongArrayPush(&otherSignedLongLongArray, 1LL);

    SignedLongLongArrayPush(&otherSignedLongLongArray, 2LL);

    int result = SignedLongLongArrayConcat(&signedLongLongArray, &otherSignedLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongLongArray.length);

    signed long long x;

    SignedLongLongArrayAt(&signedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1LL, x);

    SignedLongLongArrayAt(&signedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2LL, x);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayConcatNonEmptyArrayToNonEmptyArray) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    SignedLongLongArrayPush(&otherSignedLongLongArray, 3LL);

    SignedLongLongArrayPush(&otherSignedLongLongArray, 4LL);

    int result = SignedLongLongArrayConcat(&signedLongLongArray, &otherSignedLongLongArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedLongLongArray.length);

    signed long long x;

    SignedLongLongArrayAt(&signedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1LL, x);

    SignedLongLongArrayAt(&signedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2LL, x);

    SignedLongLongArrayAt(&signedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3LL, x);

    SignedLongLongArrayAt(&signedLongLongArray, 3, &x);

    TEST_ASSERT_EQUAL(4LL, x);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayCountEmptyArray) {
    size_t result = SignedLongLongArrayCount(&signedLongLongArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayCountNonEmptyArray) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    size_t result = SignedLongLongArrayCount(&signedLongLongArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayDeleteFromEmptyArray) {
    int result = SignedLongLongArrayDelete(&signedLongLongArray, 1LL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongLongArray.length);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayDeleteNonExistingElement) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    int result = SignedLongLongArrayDelete(&signedLongLongArray, 3LL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongLongArray.length);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayDeleteExistingElement) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    int result = SignedLongLongArrayDelete(&signedLongLongArray, 2LL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedLongLongArray.length);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayDeleteAtZeroLength) {
    int result = SignedLongLongArrayDeleteAt(&signedLongLongArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayDeleteAtExistingElement) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    SignedLongLongArrayPush(&signedLongLongArray, 3LL);

    SignedLongLongArrayPush(&signedLongLongArray, 4LL);

    SignedLongLongArrayPush(&signedLongLongArray, 5LL);

    int result = SignedLongLongArrayDeleteAt(&signedLongLongArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedLongLongArray.length);

    signed long long x;

    SignedLongLongArrayAt(&signedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1LL, x);

    SignedLongLongArrayAt(&signedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2LL, x);

    SignedLongLongArrayAt(&signedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(4LL, x);

    SignedLongLongArrayAt(&signedLongLongArray, 3, &x);

    TEST_ASSERT_EQUAL(5LL, x);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayDeleteAtLessThanZeroIndex) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    SignedLongLongArrayPush(&signedLongLongArray, 3LL);

    SignedLongLongArrayPush(&signedLongLongArray, 4LL);

    SignedLongLongArrayPush(&signedLongLongArray, 5LL);

    int result = SignedLongLongArrayDeleteAt(&signedLongLongArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedLongLongArray.length);

    signed long long x;

    SignedLongLongArrayAt(&signedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(1LL, x);

    SignedLongLongArrayAt(&signedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(2LL, x);

    SignedLongLongArrayAt(&signedLongLongArray, 2, &x);

    TEST_ASSERT_EQUAL(3LL, x);

    SignedLongLongArrayAt(&signedLongLongArray, 3, &x);

    TEST_ASSERT_EQUAL(5LL, x);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayDeleteAtGreaterThanLengthIndex) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    SignedLongLongArrayPush(&signedLongLongArray, 3LL);

    SignedLongLongArrayPush(&signedLongLongArray, 4LL);

    SignedLongLongArrayPush(&signedLongLongArray, 5LL);

    int result = SignedLongLongArrayDeleteAt(&signedLongLongArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayDeleteAtLessThanNegativeLengthIndex) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    SignedLongLongArrayPush(&signedLongLongArray, 3LL);

    SignedLongLongArrayPush(&signedLongLongArray, 4LL);

    SignedLongLongArrayPush(&signedLongLongArray, 5LL);

    int result = SignedLongLongArrayDeleteAt(&signedLongLongArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayDropOneEmptyArray) {
    int result = SignedLongLongArrayDrop(&signedLongLongArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongLongArray.length);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayDropManyEmptyArray) {
    int result = SignedLongLongArrayDrop(&signedLongLongArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongLongArray.length);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayDropLessThanArrayLength) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    SignedLongLongArrayPush(&signedLongLongArray, 3LL);

    SignedLongLongArrayPush(&signedLongLongArray, 4LL);

    SignedLongLongArrayPush(&signedLongLongArray, 5LL);

    int result = SignedLongLongArrayDrop(&signedLongLongArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongLongArray.length);

    signed long long x;

    SignedLongLongArrayAt(&signedLongLongArray, 0, &x);

    TEST_ASSERT_EQUAL(4LL, x);

    SignedLongLongArrayAt(&signedLongLongArray, 1, &x);

    TEST_ASSERT_EQUAL(5LL, x);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayDropGreaterThanArrayLength) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    SignedLongLongArrayPush(&signedLongLongArray, 3LL);

    SignedLongLongArrayPush(&signedLongLongArray, 4LL);

    SignedLongLongArrayPush(&signedLongLongArray, 5LL);

    int result = SignedLongLongArrayDrop(&signedLongLongArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongLongArray.length);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayEmptyArrayIsEmpty) {
    int result = SignedLongLongArrayIsEmpty(&signedLongLongArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayNonEmptyArrayIsNotEmpty) {
    SignedLongLongArrayPush(&signedLongLongArray, 1LL);

    SignedLongLongArrayPush(&signedLongLongArray, 2LL);

    SignedLongLongArrayPush(&signedLongLongArray, 3LL);

    SignedLongLongArrayPush(&signedLongLongArray, 4LL);

    SignedLongLongArrayPush(&signedLongLongArray, 5LL);

    int result = SignedLongLongArrayIsEmpty(&signedLongLongArray);

    TEST_ASSERT_EQUAL(0, result);
}
