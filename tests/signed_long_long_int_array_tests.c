#include "signed_long_long_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedLongLongIntArrayTests);

SignedLongLongIntArray signedLongLongIntArray;
SignedLongLongIntArray otherSignedLongLongIntArray;

TEST_SETUP(SignedLongLongIntArrayTests) {
    SignedLongLongIntArrayInitialize(&signedLongLongIntArray);

    SignedLongLongIntArrayInitialize(&otherSignedLongLongIntArray);
}

TEST_TEAR_DOWN(SignedLongLongIntArrayTests) {
    SignedLongLongIntArrayDeinitialize(&signedLongLongIntArray);

    SignedLongLongIntArrayDeinitialize(&otherSignedLongLongIntArray);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, signedLongLongIntArray.length);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongLongIntArray.capacity);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayPushOneElement) {
    int result = SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedLongLongIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongLongIntArray.capacity);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = SignedLongLongIntArrayPush(&signedLongLongIntArray, (signed long long int)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedLongLongIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedLongLongIntArray.capacity);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayAtZeroLength) {
    signed long long int x;

    int result = SignedLongLongIntArrayAt(&signedLongLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayAtExistingElement) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 3LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 4LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 5LL);

    signed long long int x;

    int result = SignedLongLongIntArrayAt(&signedLongLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3LL, x);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayAtLessThanZeroIndex) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 3LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 4LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 5LL);

    signed long long int x;

    int result = SignedLongLongIntArrayAt(&signedLongLongIntArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4LL, x);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayAtGreaterThanLengthIndex) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 3LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 4LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 5LL);

    signed long long int x;

    int result = SignedLongLongIntArrayAt(&signedLongLongIntArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayAtLessThanNegativeLengthIndex) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 3LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 4LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 5LL);

    signed long long int x;

    int result = SignedLongLongIntArrayAt(&signedLongLongIntArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayClear) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 3LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 4LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 5LL);

    int result = SignedLongLongIntArrayClear(&signedLongLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongLongIntArray.length);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayConcatEmptyArrays) {
    int result = SignedLongLongIntArrayConcat(&signedLongLongIntArray, &otherSignedLongLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongLongIntArray.length);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayConcatEmptyArrayToNonEmptyArray) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    int result = SignedLongLongIntArrayConcat(&signedLongLongIntArray, &otherSignedLongLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongLongIntArray.length);

    signed long long int x;

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1LL, x);

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2LL, x);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayConcatNonEmptyArrayToEmptyArray) {
    SignedLongLongIntArrayPush(&otherSignedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&otherSignedLongLongIntArray, 2LL);

    int result = SignedLongLongIntArrayConcat(&signedLongLongIntArray, &otherSignedLongLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongLongIntArray.length);

    signed long long int x;

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1LL, x);

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2LL, x);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayConcatNonEmptyArrayToNonEmptyArray) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    SignedLongLongIntArrayPush(&otherSignedLongLongIntArray, 3LL);

    SignedLongLongIntArrayPush(&otherSignedLongLongIntArray, 4LL);

    int result = SignedLongLongIntArrayConcat(&signedLongLongIntArray, &otherSignedLongLongIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedLongLongIntArray.length);

    signed long long int x;

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1LL, x);

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2LL, x);

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3LL, x);

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4LL, x);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayCountEmptyArray) {
    size_t result = SignedLongLongIntArrayCount(&signedLongLongIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayCountNonEmptyArray) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    size_t result = SignedLongLongIntArrayCount(&signedLongLongIntArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteFromEmptyArray) {
    int result = SignedLongLongIntArrayDelete(&signedLongLongIntArray, 1LL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongLongIntArray.length);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteNonExistingElement) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    int result = SignedLongLongIntArrayDelete(&signedLongLongIntArray, 3LL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongLongIntArray.length);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteExistingElement) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    int result = SignedLongLongIntArrayDelete(&signedLongLongIntArray, 2LL);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedLongLongIntArray.length);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteAtZeroLength) {
    int result = SignedLongLongIntArrayDeleteAt(&signedLongLongIntArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteAtExistingElement) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 3LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 4LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 5LL);

    int result = SignedLongLongIntArrayDeleteAt(&signedLongLongIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedLongLongIntArray.length);

    signed long long int x;

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1LL, x);

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2LL, x);

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(4LL, x);

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5LL, x);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteAtLessThanZeroIndex) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 3LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 4LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 5LL);

    int result = SignedLongLongIntArrayDeleteAt(&signedLongLongIntArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedLongLongIntArray.length);

    signed long long int x;

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1LL, x);

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2LL, x);

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3LL, x);

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5LL, x);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteAtGreaterThanLengthIndex) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 3LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 4LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 5LL);

    int result = SignedLongLongIntArrayDeleteAt(&signedLongLongIntArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteAtLessThanNegativeLengthIndex) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 3LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 4LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 5LL);

    int result = SignedLongLongIntArrayDeleteAt(&signedLongLongIntArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayDropOneEmptyArray) {
    int result = SignedLongLongIntArrayDrop(&signedLongLongIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongLongIntArray.length);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayDropManyEmptyArray) {
    int result = SignedLongLongIntArrayDrop(&signedLongLongIntArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongLongIntArray.length);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayDropLessThanArrayLength) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 3LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 4LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 5LL);

    int result = SignedLongLongIntArrayDrop(&signedLongLongIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedLongLongIntArray.length);

    signed long long int x;

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 0, &x);

    TEST_ASSERT_EQUAL(4LL, x);

    SignedLongLongIntArrayAt(&signedLongLongIntArray, 1, &x);

    TEST_ASSERT_EQUAL(5LL, x);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayDropGreaterThanArrayLength) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 3LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 4LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 5LL);

    int result = SignedLongLongIntArrayDrop(&signedLongLongIntArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedLongLongIntArray.length);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayEmptyArrayIsEmpty) {
    int result = SignedLongLongIntArrayIsEmpty(&signedLongLongIntArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayNonEmptyArrayIsNotEmpty) {
    SignedLongLongIntArrayPush(&signedLongLongIntArray, 1LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 2LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 3LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 4LL);

    SignedLongLongIntArrayPush(&signedLongLongIntArray, 5LL);

    int result = SignedLongLongIntArrayIsEmpty(&signedLongLongIntArray);

    TEST_ASSERT_EQUAL(0, result);
}
