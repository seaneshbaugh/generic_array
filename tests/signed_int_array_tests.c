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

TEST(SignedIntArrayTests, SignedIntArrayInitializeFromEmptyPointer) {
    signed int values[] = { };

    int result = SignedIntArrayInitializeFromPointer(&signedIntArray, values, 0);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, SignedIntArrayCount(&signedIntArray));
}

TEST(SignedIntArrayTests, SignedIntArrayInitializeFromPointer) {
    signed int values[5] = { 1, 2, 3, 4, 5 };

    int result = SignedIntArrayInitializeFromPointer(&signedIntArray, values, 5);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, SignedIntArrayCount(&signedIntArray));
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

TEST(SignedIntArrayTests, SignedIntArraySetZeroLength) {
    int result = SignedIntArraySet(&signedIntArray, 2, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedIntArrayTests, SignedIntArraySetExistingElement) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    int result = SignedIntArraySet(&signedIntArray, 2, 5);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    signed int x;

    result = SignedIntArrayAt(&signedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedIntArrayTests, SignedIntArraySetLessThanZeroIndex) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    int result = SignedIntArraySet(&signedIntArray, -2, 5);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    signed int x;

    result = SignedIntArrayAt(&signedIntArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedIntArrayTests, SignedIntArraySetGreaterThanLengthIndex) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    int result = SignedIntArraySet(&signedIntArray, 4, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedIntArrayTests, SignedIntArraySetLessThanNegativeLengthIndex) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    int result = SignedIntArraySet(&signedIntArray, -5, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

int SignedIntAscendingCompare(const void *a, const void *b) {
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

int SignedIntDescendingCompare(const void *a, const void *b) {
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

TEST(SignedIntArrayTests, SignedIntArraySortEmptyArray) {
    SignedIntArraySort(&signedIntArray, SignedIntAscendingCompare);

    TEST_ASSERT_EQUAL(0, SignedIntArrayCount(&signedIntArray));
}

TEST(SignedIntArrayTests, SignedIntArraySortAscending) {
    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArraySort(&signedIntArray, SignedIntAscendingCompare);

    signed int x;

    SignedIntArrayAt(&signedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedIntArrayAt(&signedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedIntArrayAt(&signedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedIntArrayAt(&signedIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedIntArrayAt(&signedIntArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedIntArrayTests, SignedIntArraySortDescending) {
    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArraySort(&signedIntArray, SignedIntDescendingCompare);

    signed int x;

    SignedIntArrayAt(&signedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(5, x);

    SignedIntArrayAt(&signedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedIntArrayAt(&signedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedIntArrayAt(&signedIntArray, 3, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedIntArrayAt(&signedIntArray, 4, &x);

    TEST_ASSERT_EQUAL(1, x);
}

TEST(SignedIntArrayTests, SignedIntArrayOverlapEmptyArrays) {
    int result = SignedIntArrayOverlap(&signedIntArray, &otherSignedIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, SignedIntArrayCount(&signedIntArray));

    TEST_ASSERT_EQUAL(0, SignedIntArrayCount(&otherSignedIntArray));
}

TEST(SignedIntArrayTests, SignedIntArrayOverlapNonEmptyArrayWithEmptyArray) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 2);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    int result = SignedIntArrayOverlap(&signedIntArray, &otherSignedIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, SignedIntArrayCount(&signedIntArray));

    TEST_ASSERT_EQUAL(0, SignedIntArrayCount(&otherSignedIntArray));

    SignedIntArraySort(&signedIntArray, SignedIntAscendingCompare);

    signed int x;

    SignedIntArrayAt(&signedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedIntArrayAt(&signedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedIntArrayAt(&signedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedIntArrayAt(&signedIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedIntArrayAt(&signedIntArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedIntArrayTests, SignedIntArrayOverlapEmptyArrayWithNonEmptyArray) {
    SignedIntArrayPush(&otherSignedIntArray, 1);

    SignedIntArrayPush(&otherSignedIntArray, 2);

    SignedIntArrayPush(&otherSignedIntArray, 3);

    SignedIntArrayPush(&otherSignedIntArray, 4);

    SignedIntArrayPush(&otherSignedIntArray, 5);

    int result = SignedIntArrayOverlap(&signedIntArray, &otherSignedIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, SignedIntArrayCount(&signedIntArray));

    TEST_ASSERT_EQUAL(5, SignedIntArrayCount(&otherSignedIntArray));

    SignedIntArraySort(&signedIntArray, SignedIntAscendingCompare);

    signed int x;

    SignedIntArrayAt(&signedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedIntArrayAt(&signedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedIntArrayAt(&signedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedIntArrayAt(&signedIntArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedIntArrayAt(&signedIntArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedIntArrayTests, SignedIntArrayOverlapNonEmptyArrays) {
    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 1);

    SignedIntArrayPush(&signedIntArray, 3);

    SignedIntArrayPush(&signedIntArray, 4);

    SignedIntArrayPush(&signedIntArray, 5);

    SignedIntArrayPush(&signedIntArray, 5);

    SignedIntArrayPush(&otherSignedIntArray, 1);

    SignedIntArrayPush(&otherSignedIntArray, 2);

    SignedIntArrayPush(&otherSignedIntArray, 3);

    SignedIntArrayPush(&otherSignedIntArray, 4);

    SignedIntArrayPush(&otherSignedIntArray, 4);

    SignedIntArrayPush(&otherSignedIntArray, 5);

    SignedIntArrayPush(&otherSignedIntArray, 5);

    SignedIntArrayPush(&otherSignedIntArray, 5);

    int result = SignedIntArrayOverlap(&signedIntArray, &otherSignedIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(10, SignedIntArrayCount(&signedIntArray));

    TEST_ASSERT_EQUAL(8, SignedIntArrayCount(&otherSignedIntArray));

    SignedIntArraySort(&signedIntArray, SignedIntAscendingCompare);

    signed int x;

    SignedIntArrayAt(&signedIntArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedIntArrayAt(&signedIntArray, 1, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedIntArrayAt(&signedIntArray, 2, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedIntArrayAt(&signedIntArray, 3, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedIntArrayAt(&signedIntArray, 4, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedIntArrayAt(&signedIntArray, 5, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedIntArrayAt(&signedIntArray, 6, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedIntArrayAt(&signedIntArray, 7, &x);

    TEST_ASSERT_EQUAL(5, x);

    SignedIntArrayAt(&signedIntArray, 8, &x);

    TEST_ASSERT_EQUAL(5, x);

    SignedIntArrayAt(&signedIntArray, 9, &x);

    TEST_ASSERT_EQUAL(5, x);
}
