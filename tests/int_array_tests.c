#include "int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(IntArrayTests);

IntArray intArray;
IntArray otherIntArray;

TEST_SETUP(IntArrayTests) {
    IntArrayInitialize(&intArray);

    IntArrayInitialize(&otherIntArray);
}

TEST_TEAR_DOWN(IntArrayTests) {
    IntArrayDeinitialize(&intArray);

    IntArrayDeinitialize(&otherIntArray);
}

TEST(IntArrayTests, IntArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, intArray.length);
}

TEST(IntArrayTests, IntArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, intArray.capacity);
}

TEST(IntArrayTests, IntArrayPushOneElement) {
    int result = IntArrayPush(&intArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, intArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, intArray.capacity);
}

TEST(IntArrayTests, IntArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = IntArrayPush(&intArray, (int)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, intArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, intArray.capacity);
}

TEST(IntArrayTests, IntArrayAtZeroLength) {
    int x;

    int result = IntArrayAt(&intArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(IntArrayTests, IntArrayAtExistingElement) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    int x;

    int result = IntArrayAt(&intArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);
}

TEST(IntArrayTests, IntArrayAtLessThanZeroIndex) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    int x;

    int result = IntArrayAt(&intArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(IntArrayTests, IntArrayAtGreaterThanLengthIndex) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    int x;

    int result = IntArrayAt(&intArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(IntArrayTests, IntArrayAtLessThanNegativeLengthIndex) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    int x;

    int result = IntArrayAt(&intArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(IntArrayTests, IntArrayClear) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    int result = IntArrayClear(&intArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, intArray.length);
}

TEST(IntArrayTests, IntArrayConcatEmptyArrays) {
    int result = IntArrayConcat(&intArray, &otherIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, intArray.length);
}

TEST(IntArrayTests, IntArrayConcatEmptyArrayToNonEmptyArray) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    int result = IntArrayConcat(&intArray, &otherIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, intArray.length);

    int x;

    IntArrayAt(&intArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    IntArrayAt(&intArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(IntArrayTests, IntArrayConcatNonEmptyArrayToEmptyArray) {
    IntArrayPush(&otherIntArray, 1);

    IntArrayPush(&otherIntArray, 2);

    int result = IntArrayConcat(&intArray, &otherIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, intArray.length);

    int x;

    IntArrayAt(&intArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    IntArrayAt(&intArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(IntArrayTests, IntArrayConcatNonEmptyArrayToNonEmptyArray) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&otherIntArray, 3);

    IntArrayPush(&otherIntArray, 4);

    int result = IntArrayConcat(&intArray, &otherIntArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, intArray.length);

    int x;

    IntArrayAt(&intArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    IntArrayAt(&intArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    IntArrayAt(&intArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    IntArrayAt(&intArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(IntArrayTests, IntArrayCountEmptyArray) {
    size_t result = IntArrayCount(&intArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(IntArrayTests, IntArrayCountNonEmptyArray) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    size_t result = IntArrayCount(&intArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(IntArrayTests, IntArrayDeleteFromEmptyArray) {
    int result = IntArrayDelete(&intArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, intArray.length);
}

TEST(IntArrayTests, IntArrayDeleteNonExistingElement) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    int result = IntArrayDelete(&intArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, intArray.length);
}

TEST(IntArrayTests, IntArrayDeleteExistingElement) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    int result = IntArrayDelete(&intArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, intArray.length);
}

TEST(IntArrayTests, IntArrayDeleteAtZeroLength) {
    int result = IntArrayDeleteAt(&intArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(IntArrayTests, IntArrayDeleteAtExistingElement) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    int result = IntArrayDeleteAt(&intArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, intArray.length);

    int x;

    IntArrayAt(&intArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    IntArrayAt(&intArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    IntArrayAt(&intArray, 2, &x);

    TEST_ASSERT_EQUAL(4, x);

    IntArrayAt(&intArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(IntArrayTests, IntArrayDeleteAtLessThanZeroIndex) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    int result = IntArrayDeleteAt(&intArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, intArray.length);

    int x;

    IntArrayAt(&intArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    IntArrayAt(&intArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    IntArrayAt(&intArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    IntArrayAt(&intArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(IntArrayTests, IntArrayDeleteAtGreaterThanLengthIndex) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    int result = IntArrayDeleteAt(&intArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(IntArrayTests, IntArrayDeleteAtLessThanNegativeLengthIndex) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    int result = IntArrayDeleteAt(&intArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(IntArrayTests, IntArrayDropOneEmptyArray) {
    int result = IntArrayDrop(&intArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, intArray.length);
}

TEST(IntArrayTests, IntArrayDropManyEmptyArray) {
    int result = IntArrayDrop(&intArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, intArray.length);
}

TEST(IntArrayTests, IntArrayDropLessThanArrayLength) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    int result = IntArrayDrop(&intArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, intArray.length);

    int x;

    IntArrayAt(&intArray, 0, &x);

    TEST_ASSERT_EQUAL(4, x);

    IntArrayAt(&intArray, 1, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(IntArrayTests, IntArrayDropGreaterThanArrayLength) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    int result = IntArrayDrop(&intArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, intArray.length);
}

TEST(IntArrayTests, IntArrayEmptyArrayIsEmpty) {
    int result = IntArrayIsEmpty(&intArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(IntArrayTests, IntArrayNonEmptyArrayIsNotEmpty) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    int result = IntArrayIsEmpty(&intArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(IntArrayTests, IntArrayPush) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    TEST_ASSERT_EQUAL(5, intArray.length);

    int x;

    int result = IntArrayAt(&intArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, x);

    result = IntArrayAt(&intArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, x);

    result = IntArrayAt(&intArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);

    result = IntArrayAt(&intArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);

    result = IntArrayAt(&intArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(IntArrayTests, IntArrayMultipleElementArrayToString) {
    IntArrayPush(&intArray, 1);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    char* asString;

    int result = IntArrayToString(&intArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[1, 2, 3, 4, 5]", asString);

    free(asString);
}

int IntAscendingCompare(const void *a, const void *b) {
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

int IntDescendingCompare(const void *a, const void *b) {
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

TEST(IntArrayTests, IntArraySortAscending) {
    IntArrayPush(&intArray, 3);

    IntArrayPush(&intArray, 2);

    IntArrayPush(&intArray, 4);

    IntArrayPush(&intArray, 5);

    IntArrayPush(&intArray, 1);

    IntArraySort(&intArray, IntAscendingCompare);

    int x;

    IntArrayAt(&intArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    IntArrayAt(&intArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    IntArrayAt(&intArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    IntArrayAt(&intArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    IntArrayAt(&intArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}
