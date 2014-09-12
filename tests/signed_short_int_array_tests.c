#include "signed_short_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedShortIntArrayTests);

SignedShortIntArray signedShortIntArray;
SignedShortIntArray otherSignedShortIntArray;

TEST_SETUP(SignedShortIntArrayTests) {
    SignedShortIntArrayInitialize(&signedShortIntArray);

    SignedShortIntArrayInitialize(&otherSignedShortIntArray);
}

TEST_TEAR_DOWN(SignedShortIntArrayTests) {
    SignedShortIntArrayDeinitialize(&signedShortIntArray);

    SignedShortIntArrayDeinitialize(&otherSignedShortIntArray);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, signedShortIntArray.length);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedShortIntArray.capacity);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayInitializeFromEmptyPointer) {
    signed short int values[] = { };

    int result = SignedShortIntArrayInitializeFromPointer(&signedShortIntArray, values, 0);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, SignedShortIntArrayCount(&signedShortIntArray));
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayInitializeFromPointer) {
    signed short int values[5] = { 1, 2, 3, 4, 5 };

    int result = SignedShortIntArrayInitializeFromPointer(&signedShortIntArray, values, 5);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, SignedShortIntArrayCount(&signedShortIntArray));
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayPushOneElement) {
    int result = SignedShortIntArrayPush(&signedShortIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedShortIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedShortIntArray.capacity);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = SignedShortIntArrayPush(&signedShortIntArray, (signed short int)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedShortIntArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedShortIntArray.capacity);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayAtZeroLength) {
    signed short int x;

    int result = SignedShortIntArrayAt(&signedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayAtExistingElement) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    signed short int x;

    int result = SignedShortIntArrayAt(&signedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayAtLessThanZeroIndex) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    signed short int x;

    int result = SignedShortIntArrayAt(&signedShortIntArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayAtGreaterThanLengthIndex) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    signed short int x;

    int result = SignedShortIntArrayAt(&signedShortIntArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayAtLessThanNegativeLengthIndex) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    signed short int x;

    int result = SignedShortIntArrayAt(&signedShortIntArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayClear) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    int result = SignedShortIntArrayClear(&signedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedShortIntArray.length);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayConcatEmptyArrays) {
    int result = SignedShortIntArrayConcat(&signedShortIntArray, &otherSignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedShortIntArray.length);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayConcatEmptyArrayToNonEmptyArray) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    int result = SignedShortIntArrayConcat(&signedShortIntArray, &otherSignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedShortIntArray.length);

    signed short int x;

    SignedShortIntArrayAt(&signedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortIntArrayAt(&signedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayConcatNonEmptyArrayToEmptyArray) {
    SignedShortIntArrayPush(&otherSignedShortIntArray, 1);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 2);

    int result = SignedShortIntArrayConcat(&signedShortIntArray, &otherSignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedShortIntArray.length);

    signed short int x;

    SignedShortIntArrayAt(&signedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortIntArrayAt(&signedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayConcatNonEmptyArrayToNonEmptyArray) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 3);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 4);

    int result = SignedShortIntArrayConcat(&signedShortIntArray, &otherSignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedShortIntArray.length);

    signed short int x;

    SignedShortIntArrayAt(&signedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortIntArrayAt(&signedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortIntArrayAt(&signedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedShortIntArrayAt(&signedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayCountEmptyArray) {
    size_t result = SignedShortIntArrayCount(&signedShortIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayCountNonEmptyArray) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    size_t result = SignedShortIntArrayCount(&signedShortIntArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayDeleteFromEmptyArray) {
    int result = SignedShortIntArrayDelete(&signedShortIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedShortIntArray.length);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayDeleteNonExistingElement) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    int result = SignedShortIntArrayDelete(&signedShortIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedShortIntArray.length);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayDeleteExistingElement) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    int result = SignedShortIntArrayDelete(&signedShortIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedShortIntArray.length);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayDeleteAtZeroLength) {
    int result = SignedShortIntArrayDeleteAt(&signedShortIntArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayDeleteAtExistingElement) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    int result = SignedShortIntArrayDeleteAt(&signedShortIntArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedShortIntArray.length);

    signed short int x;

    SignedShortIntArrayAt(&signedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortIntArrayAt(&signedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortIntArrayAt(&signedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortIntArrayAt(&signedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayDeleteAtLessThanZeroIndex) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    int result = SignedShortIntArrayDeleteAt(&signedShortIntArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedShortIntArray.length);

    signed short int x;

    SignedShortIntArrayAt(&signedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortIntArrayAt(&signedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortIntArrayAt(&signedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedShortIntArrayAt(&signedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayDeleteAtGreaterThanLengthIndex) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    int result = SignedShortIntArrayDeleteAt(&signedShortIntArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayDeleteAtLessThanNegativeLengthIndex) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    int result = SignedShortIntArrayDeleteAt(&signedShortIntArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayDropOneEmptyArray) {
    int result = SignedShortIntArrayDrop(&signedShortIntArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedShortIntArray.length);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayDropManyEmptyArray) {
    int result = SignedShortIntArrayDrop(&signedShortIntArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedShortIntArray.length);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayDropLessThanArrayLength) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    int result = SignedShortIntArrayDrop(&signedShortIntArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedShortIntArray.length);

    signed short int x;

    SignedShortIntArrayAt(&signedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortIntArrayAt(&signedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayDropGreaterThanArrayLength) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    int result = SignedShortIntArrayDrop(&signedShortIntArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedShortIntArray.length);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayEmptyArrayIsEmpty) {
    int result = SignedShortIntArrayIsEmpty(&signedShortIntArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayNonEmptyArrayIsNotEmpty) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    int result = SignedShortIntArrayIsEmpty(&signedShortIntArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayPush) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    TEST_ASSERT_EQUAL(5, signedShortIntArray.length);

    signed short int x;

    int result = SignedShortIntArrayAt(&signedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, x);

    result = SignedShortIntArrayAt(&signedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, x);

    result = SignedShortIntArrayAt(&signedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);

    result = SignedShortIntArrayAt(&signedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);

    result = SignedShortIntArrayAt(&signedShortIntArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayMultipleElementArrayToString) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    char* asString;

    int result = SignedShortIntArrayToString(&signedShortIntArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[1, 2, 3, 4, 5]", asString);

    free(asString);
}

TEST(SignedShortIntArrayTests, SignedShortIntArraySetZeroLength) {
    int result = SignedShortIntArraySet(&signedShortIntArray, 2, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedShortIntArrayTests, SignedShortIntArraySetExistingElement) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    int result = SignedShortIntArraySet(&signedShortIntArray, 2, 5);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    signed short int x;

    result = SignedShortIntArrayAt(&signedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArraySetLessThanZeroIndex) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    int result = SignedShortIntArraySet(&signedShortIntArray, -2, 5);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    signed short int x;

    result = SignedShortIntArrayAt(&signedShortIntArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArraySetGreaterThanLengthIndex) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    int result = SignedShortIntArraySet(&signedShortIntArray, 4, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedShortIntArrayTests, SignedShortIntArraySetLessThanNegativeLengthIndex) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    int result = SignedShortIntArraySet(&signedShortIntArray, -5, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

int SignedShortIntAscendingCompare(const void *a, const void *b) {
    __GENERIC_ARRAY_TYPE__ f = *((__GENERIC_ARRAY_TYPE__*)a);
    __GENERIC_ARRAY_TYPE__ s = *((__GENERIC_ARRAY_TYPE__*)b);

    if (GENERIC_ARRAY_VALUES_GREATER_THAN(f, s)) {
        return 1;
    }

    if (GENERIC_ARRAY_VALUES_LESS_THAN(f, s)) {
        return -1;
    }

    return 0;
}

int SignedShortIntDescendingCompare(const void *a, const void *b) {
    __GENERIC_ARRAY_TYPE__ f = *((__GENERIC_ARRAY_TYPE__*)a);
    __GENERIC_ARRAY_TYPE__ s = *((__GENERIC_ARRAY_TYPE__*)b);

    if (GENERIC_ARRAY_VALUES_LESS_THAN(f, s)) {
        return 1;
    }

    if (GENERIC_ARRAY_VALUES_GREATER_THAN(f, s)) {
        return -1;
    }

    return 0;
}

TEST(SignedShortIntArrayTests, SignedShortIntArraySortEmptyArray) {
    SignedShortIntArraySort(&signedShortIntArray, SignedShortIntAscendingCompare);

    TEST_ASSERT_EQUAL(0, SignedShortIntArrayCount(&signedShortIntArray));
}

TEST(SignedShortIntArrayTests, SignedShortIntArraySortAscending) {
    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArraySort(&signedShortIntArray, SignedShortIntAscendingCompare);

    signed short int x;

    SignedShortIntArrayAt(&signedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortIntArrayAt(&signedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortIntArrayAt(&signedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedShortIntArrayAt(&signedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortIntArrayAt(&signedShortIntArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArraySortDescending) {
    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArraySort(&signedShortIntArray, SignedShortIntDescendingCompare);

    signed short int x;

    SignedShortIntArrayAt(&signedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(5, x);

    SignedShortIntArrayAt(&signedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortIntArrayAt(&signedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedShortIntArrayAt(&signedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortIntArrayAt(&signedShortIntArray, 4, &x);

    TEST_ASSERT_EQUAL(1, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayOverlapEmptyArrays) {
    int result = SignedShortIntArrayOverlap(&signedShortIntArray, &otherSignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, SignedShortIntArrayCount(&signedShortIntArray));

    TEST_ASSERT_EQUAL(0, SignedShortIntArrayCount(&otherSignedShortIntArray));
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayOverlapNonEmptyArrayWithEmptyArray) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 2);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    int result = SignedShortIntArrayOverlap(&signedShortIntArray, &otherSignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, SignedShortIntArrayCount(&signedShortIntArray));

    TEST_ASSERT_EQUAL(0, SignedShortIntArrayCount(&otherSignedShortIntArray));

    SignedShortIntArraySort(&signedShortIntArray, SignedShortIntAscendingCompare);

    signed short int x;

    SignedShortIntArrayAt(&signedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortIntArrayAt(&signedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortIntArrayAt(&signedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedShortIntArrayAt(&signedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortIntArrayAt(&signedShortIntArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayOverlapEmptyArrayWithNonEmptyArray) {
    SignedShortIntArrayPush(&otherSignedShortIntArray, 1);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 2);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 3);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 4);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 5);

    int result = SignedShortIntArrayOverlap(&signedShortIntArray, &otherSignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, SignedShortIntArrayCount(&signedShortIntArray));

    TEST_ASSERT_EQUAL(5, SignedShortIntArrayCount(&otherSignedShortIntArray));

    SignedShortIntArraySort(&signedShortIntArray, SignedShortIntAscendingCompare);

    signed short int x;

    SignedShortIntArrayAt(&signedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortIntArrayAt(&signedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortIntArrayAt(&signedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedShortIntArrayAt(&signedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortIntArrayAt(&signedShortIntArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayOverlapNonEmptyArrays) {
    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 1);

    SignedShortIntArrayPush(&signedShortIntArray, 3);

    SignedShortIntArrayPush(&signedShortIntArray, 4);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    SignedShortIntArrayPush(&signedShortIntArray, 5);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 1);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 2);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 3);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 4);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 4);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 5);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 5);

    SignedShortIntArrayPush(&otherSignedShortIntArray, 5);

    int result = SignedShortIntArrayOverlap(&signedShortIntArray, &otherSignedShortIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(10, SignedShortIntArrayCount(&signedShortIntArray));

    TEST_ASSERT_EQUAL(8, SignedShortIntArrayCount(&otherSignedShortIntArray));

    SignedShortIntArraySort(&signedShortIntArray, SignedShortIntAscendingCompare);

    signed short int x;

    SignedShortIntArrayAt(&signedShortIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortIntArrayAt(&signedShortIntArray, 1, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortIntArrayAt(&signedShortIntArray, 2, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortIntArrayAt(&signedShortIntArray, 3, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortIntArrayAt(&signedShortIntArray, 4, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedShortIntArrayAt(&signedShortIntArray, 5, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortIntArrayAt(&signedShortIntArray, 6, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortIntArrayAt(&signedShortIntArray, 7, &x);

    TEST_ASSERT_EQUAL(5, x);

    SignedShortIntArrayAt(&signedShortIntArray, 8, &x);

    TEST_ASSERT_EQUAL(5, x);

    SignedShortIntArrayAt(&signedShortIntArray, 9, &x);

    TEST_ASSERT_EQUAL(5, x);
}
