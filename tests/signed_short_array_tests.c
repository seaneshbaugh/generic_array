#include "signed_short_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedShortArrayTests);

SignedShortArray signedShortArray;
SignedShortArray otherSignedShortArray;

TEST_SETUP(SignedShortArrayTests) {
    SignedShortArrayInitialize(&signedShortArray);

    SignedShortArrayInitialize(&otherSignedShortArray);
}

TEST_TEAR_DOWN(SignedShortArrayTests) {
    SignedShortArrayDeinitialize(&signedShortArray);

    SignedShortArrayDeinitialize(&otherSignedShortArray);
}

TEST(SignedShortArrayTests, SignedShortArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, signedShortArray.length);
}

TEST(SignedShortArrayTests, SignedShortArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedShortArray.capacity);
}

TEST(SignedShortArrayTests, SignedShortArrayPushOneElement) {
    int result = SignedShortArrayPush(&signedShortArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedShortArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedShortArray.capacity);
}

TEST(SignedShortArrayTests, SignedShortArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = SignedShortArrayPush(&signedShortArray, (signed short)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedShortArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedShortArray.capacity);
}

TEST(SignedShortArrayTests, SignedShortArrayAtZeroLength) {
    signed short x;

    int result = SignedShortArrayAt(&signedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedShortArrayTests, SignedShortArrayAtExistingElement) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    signed short x;

    int result = SignedShortArrayAt(&signedShortArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);
}

TEST(SignedShortArrayTests, SignedShortArrayAtLessThanZeroIndex) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    signed short x;

    int result = SignedShortArrayAt(&signedShortArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(SignedShortArrayTests, SignedShortArrayAtGreaterThanLengthIndex) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    signed short x;

    int result = SignedShortArrayAt(&signedShortArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedShortArrayTests, SignedShortArrayAtLessThanNegativeLengthIndex) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    signed short x;

    int result = SignedShortArrayAt(&signedShortArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedShortArrayTests, SignedShortArrayClear) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    int result = SignedShortArrayClear(&signedShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedShortArray.length);
}

TEST(SignedShortArrayTests, SignedShortArrayConcatEmptyArrays) {
    int result = SignedShortArrayConcat(&signedShortArray, &otherSignedShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedShortArray.length);
}

TEST(SignedShortArrayTests, SignedShortArrayConcatEmptyArrayToNonEmptyArray) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    int result = SignedShortArrayConcat(&signedShortArray, &otherSignedShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedShortArray.length);

    signed short x;

    SignedShortArrayAt(&signedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortArrayAt(&signedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(SignedShortArrayTests, SignedShortArrayConcatNonEmptyArrayToEmptyArray) {
    SignedShortArrayPush(&otherSignedShortArray, 1);

    SignedShortArrayPush(&otherSignedShortArray, 2);

    int result = SignedShortArrayConcat(&signedShortArray, &otherSignedShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedShortArray.length);

    signed short x;

    SignedShortArrayAt(&signedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortArrayAt(&signedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(SignedShortArrayTests, SignedShortArrayConcatNonEmptyArrayToNonEmptyArray) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&otherSignedShortArray, 3);

    SignedShortArrayPush(&otherSignedShortArray, 4);

    int result = SignedShortArrayConcat(&signedShortArray, &otherSignedShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedShortArray.length);

    signed short x;

    SignedShortArrayAt(&signedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortArrayAt(&signedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortArrayAt(&signedShortArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedShortArrayAt(&signedShortArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(SignedShortArrayTests, SignedShortArrayCountEmptyArray) {
    size_t result = SignedShortArrayCount(&signedShortArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(SignedShortArrayTests, SignedShortArrayCountNonEmptyArray) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    size_t result = SignedShortArrayCount(&signedShortArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(SignedShortArrayTests, SignedShortArrayDeleteFromEmptyArray) {
    int result = SignedShortArrayDelete(&signedShortArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedShortArray.length);
}

TEST(SignedShortArrayTests, SignedShortArrayDeleteNonExistingElement) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    int result = SignedShortArrayDelete(&signedShortArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedShortArray.length);
}

TEST(SignedShortArrayTests, SignedShortArrayDeleteExistingElement) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    int result = SignedShortArrayDelete(&signedShortArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, signedShortArray.length);
}

TEST(SignedShortArrayTests, SignedShortArrayDeleteAtZeroLength) {
    int result = SignedShortArrayDeleteAt(&signedShortArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedShortArrayTests, SignedShortArrayDeleteAtExistingElement) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    int result = SignedShortArrayDeleteAt(&signedShortArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedShortArray.length);

    signed short x;

    SignedShortArrayAt(&signedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortArrayAt(&signedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortArrayAt(&signedShortArray, 2, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortArrayAt(&signedShortArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortArrayTests, SignedShortArrayDeleteAtLessThanZeroIndex) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    int result = SignedShortArrayDeleteAt(&signedShortArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, signedShortArray.length);

    signed short x;

    SignedShortArrayAt(&signedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortArrayAt(&signedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortArrayAt(&signedShortArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedShortArrayAt(&signedShortArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortArrayTests, SignedShortArrayDeleteAtGreaterThanLengthIndex) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    int result = SignedShortArrayDeleteAt(&signedShortArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedShortArrayTests, SignedShortArrayDeleteAtLessThanNegativeLengthIndex) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    int result = SignedShortArrayDeleteAt(&signedShortArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(SignedShortArrayTests, SignedShortArrayDropOneEmptyArray) {
    int result = SignedShortArrayDrop(&signedShortArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedShortArray.length);
}

TEST(SignedShortArrayTests, SignedShortArrayDropManyEmptyArray) {
    int result = SignedShortArrayDrop(&signedShortArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedShortArray.length);
}

TEST(SignedShortArrayTests, SignedShortArrayDropLessThanArrayLength) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    int result = SignedShortArrayDrop(&signedShortArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, signedShortArray.length);

    signed short x;

    SignedShortArrayAt(&signedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortArrayAt(&signedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortArrayTests, SignedShortArrayDropGreaterThanArrayLength) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    int result = SignedShortArrayDrop(&signedShortArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, signedShortArray.length);
}

TEST(SignedShortArrayTests, SignedShortArrayEmptyArrayIsEmpty) {
    int result = SignedShortArrayIsEmpty(&signedShortArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(SignedShortArrayTests, SignedShortArrayNonEmptyArrayIsNotEmpty) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    int result = SignedShortArrayIsEmpty(&signedShortArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(SignedShortArrayTests, SignedShortArrayPush) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    TEST_ASSERT_EQUAL(5, signedShortArray.length);

    signed short x;

    int result = SignedShortArrayAt(&signedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, x);

    result = SignedShortArrayAt(&signedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, x);

    result = SignedShortArrayAt(&signedShortArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);

    result = SignedShortArrayAt(&signedShortArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);

    result = SignedShortArrayAt(&signedShortArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortArrayTests, SignedShortArrayMultipleElementArrayToString) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    char* asString;

    int result = SignedShortArrayToString(&signedShortArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[1, 2, 3, 4, 5]", asString);

    free(asString);
}

int SignedShortAscendingCompare(const void *a, const void *b) {
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

int SignedShortDescendingCompare(const void *a, const void *b) {
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

TEST(SignedShortArrayTests, SignedShortArraySortEmptyArray) {
    SignedShortArraySort(&signedShortArray, SignedShortAscendingCompare);

    TEST_ASSERT_EQUAL(0, SignedShortArrayCount(&signedShortArray));
}

TEST(SignedShortArrayTests, SignedShortArraySortAscending) {
    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArraySort(&signedShortArray, SignedShortAscendingCompare);

    signed short x;

    SignedShortArrayAt(&signedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortArrayAt(&signedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortArrayAt(&signedShortArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedShortArrayAt(&signedShortArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortArrayAt(&signedShortArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortArrayTests, SignedShortArraySortDescending) {
    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArraySort(&signedShortArray, SignedShortDescendingCompare);

    signed short x;

    SignedShortArrayAt(&signedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(5, x);

    SignedShortArrayAt(&signedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortArrayAt(&signedShortArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedShortArrayAt(&signedShortArray, 3, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortArrayAt(&signedShortArray, 4, &x);

    TEST_ASSERT_EQUAL(1, x);
}

TEST(SignedShortArrayTests, SignedShortArrayOverlapEmptyArrays) {
    int result = SignedShortArrayOverlap(&signedShortArray, &otherSignedShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, SignedShortArrayCount(&signedShortArray));

    TEST_ASSERT_EQUAL(0, SignedShortArrayCount(&otherSignedShortArray));
}

TEST(SignedShortArrayTests, SignedShortArrayOverlapNonEmptyArrayWithEmptyArray) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 2);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    int result = SignedShortArrayOverlap(&signedShortArray, &otherSignedShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, SignedShortArrayCount(&signedShortArray));

    TEST_ASSERT_EQUAL(0, SignedShortArrayCount(&otherSignedShortArray));

    SignedShortArraySort(&signedShortArray, SignedShortAscendingCompare);

    signed short x;

    SignedShortArrayAt(&signedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortArrayAt(&signedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortArrayAt(&signedShortArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedShortArrayAt(&signedShortArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortArrayAt(&signedShortArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortArrayTests, SignedShortArrayOverlapEmptyArrayWithNonEmptyArray) {
    SignedShortArrayPush(&otherSignedShortArray, 1);

    SignedShortArrayPush(&otherSignedShortArray, 2);

    SignedShortArrayPush(&otherSignedShortArray, 3);

    SignedShortArrayPush(&otherSignedShortArray, 4);

    SignedShortArrayPush(&otherSignedShortArray, 5);

    int result = SignedShortArrayOverlap(&signedShortArray, &otherSignedShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, SignedShortArrayCount(&signedShortArray));

    TEST_ASSERT_EQUAL(5, SignedShortArrayCount(&otherSignedShortArray));

    SignedShortArraySort(&signedShortArray, SignedShortAscendingCompare);

    signed short x;

    SignedShortArrayAt(&signedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortArrayAt(&signedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortArrayAt(&signedShortArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedShortArrayAt(&signedShortArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortArrayAt(&signedShortArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(SignedShortArrayTests, SignedShortArrayOverlapNonEmptyArrays) {
    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 1);

    SignedShortArrayPush(&signedShortArray, 3);

    SignedShortArrayPush(&signedShortArray, 4);

    SignedShortArrayPush(&signedShortArray, 5);

    SignedShortArrayPush(&signedShortArray, 5);

    SignedShortArrayPush(&otherSignedShortArray, 1);

    SignedShortArrayPush(&otherSignedShortArray, 2);

    SignedShortArrayPush(&otherSignedShortArray, 3);

    SignedShortArrayPush(&otherSignedShortArray, 4);

    SignedShortArrayPush(&otherSignedShortArray, 4);

    SignedShortArrayPush(&otherSignedShortArray, 5);

    SignedShortArrayPush(&otherSignedShortArray, 5);

    SignedShortArrayPush(&otherSignedShortArray, 5);

    int result = SignedShortArrayOverlap(&signedShortArray, &otherSignedShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(10, SignedShortArrayCount(&signedShortArray));

    TEST_ASSERT_EQUAL(8, SignedShortArrayCount(&otherSignedShortArray));

    SignedShortArraySort(&signedShortArray, SignedShortAscendingCompare);

    signed short x;

    SignedShortArrayAt(&signedShortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortArrayAt(&signedShortArray, 1, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortArrayAt(&signedShortArray, 2, &x);

    TEST_ASSERT_EQUAL(1, x);

    SignedShortArrayAt(&signedShortArray, 3, &x);

    TEST_ASSERT_EQUAL(2, x);

    SignedShortArrayAt(&signedShortArray, 4, &x);

    TEST_ASSERT_EQUAL(3, x);

    SignedShortArrayAt(&signedShortArray, 5, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortArrayAt(&signedShortArray, 6, &x);

    TEST_ASSERT_EQUAL(4, x);

    SignedShortArrayAt(&signedShortArray, 7, &x);

    TEST_ASSERT_EQUAL(5, x);

    SignedShortArrayAt(&signedShortArray, 8, &x);

    TEST_ASSERT_EQUAL(5, x);

    SignedShortArrayAt(&signedShortArray, 9, &x);

    TEST_ASSERT_EQUAL(5, x);
}
