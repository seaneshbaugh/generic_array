#include "signed_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedIntArrayTests);

SignedIntArray signedIntArray;
SignedIntArray otherSignedIntArray;

TEST_SETUP(SignedIntArrayTests) {
    SignedIntArrayInitialize(&signedIntArray);

    SignedIntArrayInitialize(&otherSignedIntArray);
}

TEST_TEAR_DOWN(SignedIntArrayTests) {
    SignedIntArrayDeinitialize(&signedIntArray);

    SignedIntArrayDeinitialize(&otherSignedIntArray);
}

TEST(SignedIntArrayTests, SignedIntArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, signedIntArray.length);
}

TEST(SignedIntArrayTests, SignedIntArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedIntArray.capacity);
}

TEST(SignedIntArrayTests, SignedIntArrayPushOneElement) {
    int result = SignedIntArrayPush(&signedIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedIntArray.capacity);
}

TEST(SignedIntArrayTests, SignedIntArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = SignedIntArrayPush(&signedIntArray, (signed int)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedIntArray.capacity);
}

TEST(SignedIntArrayTests, SignedIntArrayAtZeroLength) {
    signed int x;

    int result = SignedIntArrayAt(&signedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedIntArrayTests, SignedIntArrayAtExistingElement) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    signed int x;

    int result = SignedIntArrayAt(&signedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);
}

TEST(SignedIntArrayTests, SignedIntArrayAtLessThanZeroIndex) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    signed int x;

    int result = SignedIntArrayAt(&signedIntArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(SignedIntArrayTests, SignedIntArrayAtGreaterThanLengthIndex) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    signed int x;

    int result = SignedIntArrayAt(&signedIntArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedIntArrayTests, SignedIntArrayAtLessThanNegativeLengthIndex) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    signed int x;

    int result = SignedIntArrayAt(&signedIntArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedIntArrayTests, SignedIntArrayClear) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    int result = SignedIntArrayClear(&signedIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedIntArray.length);
}

TEST(SignedIntArrayTests, SignedIntArrayConcatEmptyArrays) {
    int result = SignedIntArrayConcat(&signedIntArray, &otherSignedIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedIntArray.length);
}

TEST(SignedIntArrayTests, SignedIntArrayConcatEmptyArrayToNonEmptyArray) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    int result = SignedIntArrayConcat(&signedIntArray, &otherSignedIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedIntArray.length);

    signed int x;

    SignedIntArrayAt(&signedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedIntArrayAt(&signedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(SignedIntArrayTests, SignedIntArrayConcatNonEmptyArrayToEmptyArray) {
    SignedIntArrayPush(&otherSignedIntArray, 1);

    SignedIntArrayPush(&otherSignedIntArray, 2);

    int result = SignedIntArrayConcat(&signedIntArray, &otherSignedIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedIntArray.length);

    signed int x;

    SignedIntArrayAt(&signedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedIntArrayAt(&signedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(SignedIntArrayTests, SignedIntArrayConcatNonEmptyArrayToNonEmptyArray) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&otherSignedIntArray, 3);

    SignedIntArrayPush(&otherSignedIntArray, 4);

    int result = SignedIntArrayConcat(&signedIntArray, &otherSignedIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedIntArray.length);

    signed int x;

    SignedIntArrayAt(&signedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedIntArrayAt(&signedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedIntArrayAt(&signedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedIntArrayAt(&signedIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(SignedIntArrayTests, SignedIntArrayCountEmptyArray) {
    size_t result = SignedIntArrayCount(&signedIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(SignedIntArrayTests, SignedIntArrayCountNonEmptyArray) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    size_t result = SignedIntArrayCount(&signedIntArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(SignedIntArrayTests, SignedIntArrayDeleteFromEmptyArray) {
    int result = SignedIntArrayDelete(&signedIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedIntArray.length);
}

TEST(SignedIntArrayTests, SignedIntArrayDeleteNonExistingElement) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    int result = SignedIntArrayDelete(&signedIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedIntArray.length);
}

TEST(SignedIntArrayTests, SignedIntArrayDeleteExistingElement) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    int result = SignedIntArrayDelete(&signedIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedIntArray.length);
}

TEST(SignedIntArrayTests, SignedIntArrayDeleteAtZeroLength) {
    int result = SignedIntArrayDeleteAt(&signedIntArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedIntArrayTests, SignedIntArrayDeleteAtExistingElement) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    int result = SignedIntArrayDeleteAt(&signedIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedIntArray.length);

    signed int x;

    SignedIntArrayAt(&signedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedIntArrayAt(&signedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedIntArrayAt(&signedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedIntArrayAt(&signedIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedIntArrayTests, SignedIntArrayDeleteAtLessThanZeroIndex) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    int result = SignedIntArrayDeleteAt(&signedIntArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedIntArray.length);

    signed int x;

    SignedIntArrayAt(&signedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedIntArrayAt(&signedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedIntArrayAt(&signedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedIntArrayAt(&signedIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedIntArrayTests, SignedIntArrayDeleteAtGreaterThanLengthIndex) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    int result = SignedIntArrayDeleteAt(&signedIntArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedIntArrayTests, SignedIntArrayDeleteAtLessThanNegativeLengthIndex) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    int result = SignedIntArrayDeleteAt(&signedIntArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedIntArrayTests, SignedIntArrayDropOneEmptyArray) {
    int result = SignedIntArrayDrop(&signedIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedIntArray.length);
}

TEST(SignedIntArrayTests, SignedIntArrayDropManyEmptyArray) {
    int result = SignedIntArrayDrop(&signedIntArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedIntArray.length);
}

TEST(SignedIntArrayTests, SignedIntArrayDropLessThanArrayLength) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    int result = SignedIntArrayDrop(&signedIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedIntArray.length);

    signed int x;

    SignedIntArrayAt(&signedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedIntArrayAt(&signedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedIntArrayTests, SignedIntArrayDropGreaterThanArrayLength) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    int result = SignedIntArrayDrop(&signedIntArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedIntArray.length);
}

TEST(SignedIntArrayTests, SignedIntArrayEmptyArrayIsEmpty) {
    int result = SignedIntArrayIsEmpty(&signedIntArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(SignedIntArrayTests, SignedIntArrayNonEmptyArrayIsNotEmpty) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    int result = SignedIntArrayIsEmpty(&signedIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(SignedIntArrayTests, SignedIntArrayPush) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    TEST_ASSERT_EQUAL(5, signedIntArray.length);

    signed int x;

    int result = SignedIntArrayAt(&signedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, x);

    result = SignedIntArrayAt(&signedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, x);

    result = SignedIntArrayAt(&signedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);

    result = SignedIntArrayAt(&signedIntArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);

    result = SignedIntArrayAt(&signedIntArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedIntArrayTests, SignedIntArrayMultipleElementArrayToString) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    char* asString;

    int result = SignedIntArrayToString(&signedIntArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[1, 2, 3, 4, 5]", asString);

    free(asString);
}
