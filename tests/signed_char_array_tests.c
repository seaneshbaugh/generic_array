#include "signed_char_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedCharArrayTests);

SignedCharArray signedCharArray;
SignedCharArray otherSignedCharArray;

TEST_SETUP(SignedCharArrayTests) {
    SignedCharArrayInitialize(&signedCharArray);

    SignedCharArrayInitialize(&otherSignedCharArray);
}

TEST_TEAR_DOWN(SignedCharArrayTests) {
    SignedCharArrayDeinitialize(&signedCharArray);

    SignedCharArrayDeinitialize(&otherSignedCharArray);
}

TEST(SignedCharArrayTests, SignedCharArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, signedCharArray.length);
}

TEST(SignedCharArrayTests, SignedCharArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedCharArray.capacity);
}

TEST(SignedCharArrayTests, SignedCharArrayPushOneElement) {
    int result = SignedCharArrayPush(&signedCharArray, 'A');

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedCharArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedCharArray.capacity);
}

TEST(SignedCharArrayTests, SignedCharArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = SignedCharArrayPush(&signedCharArray, (signed char)(i % 255));

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedCharArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedCharArray.capacity);
}

TEST(SignedCharArrayTests, SignedCharArrayAtZeroLength) {
    signed char x;

    int result = SignedCharArrayAt(&signedCharArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedCharArrayTests, SignedCharArrayAtExistingElement) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    signed char x;

    int result = SignedCharArrayAt(&signedCharArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('C', x);
}

TEST(SignedCharArrayTests, SignedCharArrayAtLessThanZeroIndex) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    signed char x;

    int result = SignedCharArrayAt(&signedCharArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('D', x);
}

TEST(SignedCharArrayTests, SignedCharArrayAtGreaterThanLengthIndex) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    signed char x;

    int result = SignedCharArrayAt(&signedCharArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedCharArrayTests, SignedCharArrayAtLessThanNegativeLengthIndex) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    signed char x;

    int result = SignedCharArrayAt(&signedCharArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedCharArrayTests, SignedCharArrayClear) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    int result = SignedCharArrayClear(&signedCharArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedCharArray.length);
}

TEST(SignedCharArrayTests, SignedCharArrayConcatEmptyArrays) {
    int result = SignedCharArrayConcat(&signedCharArray, &otherSignedCharArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedCharArray.length);
}

TEST(SignedCharArrayTests, SignedCharArrayConcatEmptyArrayToNonEmptyArray) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    int result = SignedCharArrayConcat(&signedCharArray, &otherSignedCharArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedCharArray.length);

    signed char x;

    SignedCharArrayAt(&signedCharArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    SignedCharArrayAt(&signedCharArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);
}

TEST(SignedCharArrayTests, SignedCharArrayConcatNonEmptyArrayToEmptyArray) {
    SignedCharArrayPush(&otherSignedCharArray, 'A');

    SignedCharArrayPush(&otherSignedCharArray, 'B');

    int result = SignedCharArrayConcat(&signedCharArray, &otherSignedCharArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedCharArray.length);

    signed char x;

    SignedCharArrayAt(&signedCharArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    SignedCharArrayAt(&signedCharArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);
}

TEST(SignedCharArrayTests, SignedCharArrayConcatNonEmptyArrayToNonEmptyArray) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&otherSignedCharArray, 'C');

    SignedCharArrayPush(&otherSignedCharArray, 'D');

    int result = SignedCharArrayConcat(&signedCharArray, &otherSignedCharArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedCharArray.length);

    signed char x;

    SignedCharArrayAt(&signedCharArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    SignedCharArrayAt(&signedCharArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);

    SignedCharArrayAt(&signedCharArray, 2, &x);

    TEST_ASSERT_EQUAL('C', x);

    SignedCharArrayAt(&signedCharArray, 3, &x);

    TEST_ASSERT_EQUAL('D', x);
}

TEST(SignedCharArrayTests, SignedCharArrayCountEmptyArray) {
    size_t result = SignedCharArrayCount(&signedCharArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(SignedCharArrayTests, SignedCharArrayCountNonEmptyArray) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    size_t result = SignedCharArrayCount(&signedCharArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(SignedCharArrayTests, SignedCharArrayDeleteFromEmptyArray) {
    int result = SignedCharArrayDelete(&signedCharArray, 'A');

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedCharArray.length);
}

TEST(SignedCharArrayTests, SignedCharArrayDeleteNonExistingElement) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    int result = SignedCharArrayDelete(&signedCharArray, 'C');

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedCharArray.length);
}

TEST(SignedCharArrayTests, SignedCharArrayDeleteExistingElement) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    int result = SignedCharArrayDelete(&signedCharArray, 'B');

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedCharArray.length);
}

TEST(SignedCharArrayTests, SignedCharArrayDeleteAtZeroLength) {
    int result = SignedCharArrayDeleteAt(&signedCharArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedCharArrayTests, SignedCharArrayDeleteAtExistingElement) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    int result = SignedCharArrayDeleteAt(&signedCharArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedCharArray.length);

    signed char x;

    SignedCharArrayAt(&signedCharArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    SignedCharArrayAt(&signedCharArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);

    SignedCharArrayAt(&signedCharArray, 2, &x);

    TEST_ASSERT_EQUAL('D', x);

    SignedCharArrayAt(&signedCharArray, 3, &x);

    TEST_ASSERT_EQUAL('E', x);
}

TEST(SignedCharArrayTests, SignedCharArrayDeleteAtLessThanZeroIndex) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    int result = SignedCharArrayDeleteAt(&signedCharArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedCharArray.length);

    signed char x;

    SignedCharArrayAt(&signedCharArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    SignedCharArrayAt(&signedCharArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);

    SignedCharArrayAt(&signedCharArray, 2, &x);

    TEST_ASSERT_EQUAL('C', x);

    SignedCharArrayAt(&signedCharArray, 3, &x);

    TEST_ASSERT_EQUAL('E', x);
}

TEST(SignedCharArrayTests, SignedCharArrayDeleteAtGreaterThanLengthIndex) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    int result = SignedCharArrayDeleteAt(&signedCharArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedCharArrayTests, SignedCharArrayDeleteAtLessThanNegativeLengthIndex) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    int result = SignedCharArrayDeleteAt(&signedCharArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedCharArrayTests, SignedCharArrayDropOneEmptyArray) {
    int result = SignedCharArrayDrop(&signedCharArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedCharArray.length);
}

TEST(SignedCharArrayTests, SignedCharArrayDropManyEmptyArray) {
    int result = SignedCharArrayDrop(&signedCharArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedCharArray.length);
}

TEST(SignedCharArrayTests, SignedCharArrayDropLessThanArrayLength) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    int result = SignedCharArrayDrop(&signedCharArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedCharArray.length);

    signed char x;

    SignedCharArrayAt(&signedCharArray, 0, &x);

    TEST_ASSERT_EQUAL('D', x);

    SignedCharArrayAt(&signedCharArray, 1, &x);

    TEST_ASSERT_EQUAL('E', x);
}

TEST(SignedCharArrayTests, SignedCharArrayDropGreaterThanArrayLength) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    int result = SignedCharArrayDrop(&signedCharArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedCharArray.length);
}

TEST(SignedCharArrayTests, SignedCharArrayEmptyArrayIsEmpty) {
    int result = SignedCharArrayIsEmpty(&signedCharArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(SignedCharArrayTests, SignedCharArrayNonEmptyArrayIsNotEmpty) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    int result = SignedCharArrayIsEmpty(&signedCharArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(SignedCharArrayTests, SignedCharArrayPush) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    TEST_ASSERT_EQUAL(5, signedCharArray.length);

    signed char x;

    int result = SignedCharArrayAt(&signedCharArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('A', x);

    result = SignedCharArrayAt(&signedCharArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('B', x);

    result = SignedCharArrayAt(&signedCharArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('C', x);

    result = SignedCharArrayAt(&signedCharArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('D', x);

    result = SignedCharArrayAt(&signedCharArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('E', x);
}

TEST(SignedCharArrayTests, SignedCharArrayMultipleElementArrayToString) {
    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    char* asString;

    int result = SignedCharArrayToString(&signedCharArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("['A', 'B', 'C', 'D', 'E']", asString);

    free(asString);
}

int SignedCharAscendingCompare(const void *a, const void *b) {
    __GENERIC_ARRAY_TYPE__ f = *((__GENERIC_ARRAY_TYPE__*)a);
    __GENERIC_ARRAY_TYPE__ s = *((__GENERIC_ARRAY_TYPE__*)b);

    if (GENERIC_ARRAY_VALUES_GREATER_THAN(f, s)) {
      return  1;
    }

    if (GENERIC_ARRAY_VALUES_LESS_THAN(f, s)) {
      return -1;
    }

    return 0;
}

int SignedCharDescendingCompare(const void *a, const void *b) {
    __GENERIC_ARRAY_TYPE__ f = *((__GENERIC_ARRAY_TYPE__*)a);
    __GENERIC_ARRAY_TYPE__ s = *((__GENERIC_ARRAY_TYPE__*)b);

    if (GENERIC_ARRAY_VALUES_LESS_THAN(f, s)) {
      return  1;
    }

    if (GENERIC_ARRAY_VALUES_GREATER_THAN(f, s)) {
      return -1;
    }

    return 0;
}

TEST(SignedCharArrayTests, SignedCharArraySortAscending) {
    SignedCharArrayPush(&signedCharArray, 'C');

    SignedCharArrayPush(&signedCharArray, 'B');

    SignedCharArrayPush(&signedCharArray, 'D');

    SignedCharArrayPush(&signedCharArray, 'E');

    SignedCharArrayPush(&signedCharArray, 'A');

    SignedCharArraySort(&signedCharArray, SignedCharAscendingCompare);

    signed char x;

    SignedCharArrayAt(&signedCharArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    SignedCharArrayAt(&signedCharArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);

    SignedCharArrayAt(&signedCharArray, 2, &x);

    TEST_ASSERT_EQUAL('C', x);

    SignedCharArrayAt(&signedCharArray, 3, &x);

    TEST_ASSERT_EQUAL('D', x);

    SignedCharArrayAt(&signedCharArray, 4, &x);

    TEST_ASSERT_EQUAL('E', x);
}
