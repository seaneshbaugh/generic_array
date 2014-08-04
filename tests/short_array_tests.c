#include "short_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(ShortArrayTests);

ShortArray shortArray;
ShortArray otherShortArray;

TEST_SETUP(ShortArrayTests) {
    ShortArrayInitialize(&shortArray);

    ShortArrayInitialize(&otherShortArray);
}

TEST_TEAR_DOWN(ShortArrayTests) {
    ShortArrayDeinitialize(&shortArray);

    ShortArrayDeinitialize(&otherShortArray);
}

TEST(ShortArrayTests, ShortArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, shortArray.capacity);
}

TEST(ShortArrayTests, ShortArrayPushOneElement) {
    int result = ShortArrayPush(&shortArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, shortArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, shortArray.capacity);
}

TEST(ShortArrayTests, ShortArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = ShortArrayPush(&shortArray, (short)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, shortArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, shortArray.capacity);
}

TEST(ShortArrayTests, ShortArrayAtZeroLength) {
    short x;

    int result = ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortArrayTests, ShortArrayAtExistingElement) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    short x;

    int result = ShortArrayAt(&shortArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);
}

TEST(ShortArrayTests, ShortArrayAtLessThanZeroIndex) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    short x;

    int result = ShortArrayAt(&shortArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(ShortArrayTests, ShortArrayAtGreaterThanLengthIndex) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    short x;

    int result = ShortArrayAt(&shortArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortArrayTests, ShortArrayAtLessThanNegativeLengthIndex) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    short x;

    int result = ShortArrayAt(&shortArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortArrayTests, ShortArrayClear) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayClear(&shortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayConcatEmptyArrays) {
    int result = ShortArrayConcat(&shortArray, &otherShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayConcatEmptyArrayToNonEmptyArray) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    int result = ShortArrayConcat(&shortArray, &otherShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, shortArray.length);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(ShortArrayTests, ShortArrayConcatNonEmptyArrayToEmptyArray) {
    ShortArrayPush(&otherShortArray, 1);

    ShortArrayPush(&otherShortArray, 2);

    int result = ShortArrayConcat(&shortArray, &otherShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, shortArray.length);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);
}

TEST(ShortArrayTests, ShortArrayConcatNonEmptyArrayToNonEmptyArray) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&otherShortArray, 3);

    ShortArrayPush(&otherShortArray, 4);

    int result = ShortArrayConcat(&shortArray, &otherShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, shortArray.length);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    ShortArrayAt(&shortArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    ShortArrayAt(&shortArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);
}

TEST(ShortArrayTests, ShortArrayCountEmptyArray) {
    size_t result = ShortArrayCount(&shortArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(ShortArrayTests, ShortArrayCountNonEmptyArray) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    size_t result = ShortArrayCount(&shortArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(ShortArrayTests, ShortArrayDeleteFromEmptyArray) {
    int result = ShortArrayDelete(&shortArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayDeleteNonExistingElement) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    int result = ShortArrayDelete(&shortArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayDeleteExistingElement) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    int result = ShortArrayDelete(&shortArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayDeleteAtZeroLength) {
    int result = ShortArrayDeleteAt(&shortArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortArrayTests, ShortArrayDeleteAtExistingElement) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayDeleteAt(&shortArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, shortArray.length);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    ShortArrayAt(&shortArray, 2, &x);

    TEST_ASSERT_EQUAL(4, x);

    ShortArrayAt(&shortArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(ShortArrayTests, ShortArrayDeleteAtLessThanZeroIndex) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayDeleteAt(&shortArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, shortArray.length);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    ShortArrayAt(&shortArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    ShortArrayAt(&shortArray, 3, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(ShortArrayTests, ShortArrayDeleteAtGreaterThanLengthIndex) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayDeleteAt(&shortArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortArrayTests, ShortArrayDeleteAtLessThanNegativeLengthIndex) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayDeleteAt(&shortArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(ShortArrayTests, ShortArrayDropOneEmptyArray) {
    int result = ShortArrayDrop(&shortArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayDropManyEmptyArray) {
    int result = ShortArrayDrop(&shortArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayDropLessThanArrayLength) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayDrop(&shortArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, shortArray.length);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(4, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(ShortArrayTests, ShortArrayDropGreaterThanArrayLength) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayDrop(&shortArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayEmptyArrayIsEmpty) {
    int result = ShortArrayIsEmpty(&shortArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(ShortArrayTests, ShortArrayNonEmptyArrayIsNotEmpty) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayIsEmpty(&shortArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(ShortArrayTests, ShortArrayPush) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    TEST_ASSERT_EQUAL(5, shortArray.length);

    short x;

    int result = ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, x);

    result = ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, x);

    result = ShortArrayAt(&shortArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3, x);

    result = ShortArrayAt(&shortArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, x);

    result = ShortArrayAt(&shortArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(ShortArrayTests, ShortArrayMultipleElementArrayToString) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    char* asString;

    int result = ShortArrayToString(&shortArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[1, 2, 3, 4, 5]", asString);

    free(asString);
}

int ShortAscendingCompare(const void *a, const void *b) {
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

int ShortDescendingCompare(const void *a, const void *b) {
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

TEST(ShortArrayTests, ShortArraySortEmptyArray) {
    ShortArraySort(&shortArray, ShortAscendingCompare);

    TEST_ASSERT_EQUAL(0, ShortArrayCount(&shortArray));
}

TEST(ShortArrayTests, ShortArraySortAscending) {
    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    ShortArrayPush(&shortArray, 1);

    ShortArraySort(&shortArray, ShortAscendingCompare);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    ShortArrayAt(&shortArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    ShortArrayAt(&shortArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    ShortArrayAt(&shortArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(ShortArrayTests, ShortArraySortDescending) {
    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    ShortArrayPush(&shortArray, 1);

    ShortArraySort(&shortArray, ShortDescendingCompare);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(5, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(4, x);

    ShortArrayAt(&shortArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    ShortArrayAt(&shortArray, 3, &x);

    TEST_ASSERT_EQUAL(2, x);

    ShortArrayAt(&shortArray, 4, &x);

    TEST_ASSERT_EQUAL(1, x);
}

TEST(ShortArrayTests, ShortArrayOverlapEmptyArrays) {
    int result = ShortArrayOverlap(&shortArray, &otherShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, ShortArrayCount(&shortArray));

    TEST_ASSERT_EQUAL(0, ShortArrayCount(&otherShortArray));
}

TEST(ShortArrayTests, ShortArrayOverlapNonEmptyArrayWithEmptyArray) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 2);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    int result = ShortArrayOverlap(&shortArray, &otherShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, ShortArrayCount(&shortArray));

    TEST_ASSERT_EQUAL(0, ShortArrayCount(&otherShortArray));

    ShortArraySort(&shortArray, ShortAscendingCompare);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    ShortArrayAt(&shortArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    ShortArrayAt(&shortArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    ShortArrayAt(&shortArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(ShortArrayTests, ShortArrayOverlapEmptyArrayWithNonEmptyArray) {
    ShortArrayPush(&otherShortArray, 1);

    ShortArrayPush(&otherShortArray, 2);

    ShortArrayPush(&otherShortArray, 3);

    ShortArrayPush(&otherShortArray, 4);

    ShortArrayPush(&otherShortArray, 5);

    int result = ShortArrayOverlap(&shortArray, &otherShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, ShortArrayCount(&shortArray));

    TEST_ASSERT_EQUAL(5, ShortArrayCount(&otherShortArray));

    ShortArraySort(&shortArray, ShortAscendingCompare);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(2, x);

    ShortArrayAt(&shortArray, 2, &x);

    TEST_ASSERT_EQUAL(3, x);

    ShortArrayAt(&shortArray, 3, &x);

    TEST_ASSERT_EQUAL(4, x);

    ShortArrayAt(&shortArray, 4, &x);

    TEST_ASSERT_EQUAL(5, x);
}

TEST(ShortArrayTests, ShortArrayOverlapNonEmptyArrays) {
    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 1);

    ShortArrayPush(&shortArray, 3);

    ShortArrayPush(&shortArray, 4);

    ShortArrayPush(&shortArray, 5);

    ShortArrayPush(&shortArray, 5);

    ShortArrayPush(&otherShortArray, 1);

    ShortArrayPush(&otherShortArray, 2);

    ShortArrayPush(&otherShortArray, 3);

    ShortArrayPush(&otherShortArray, 4);

    ShortArrayPush(&otherShortArray, 4);

    ShortArrayPush(&otherShortArray, 5);

    ShortArrayPush(&otherShortArray, 5);

    ShortArrayPush(&otherShortArray, 5);

    int result = ShortArrayOverlap(&shortArray, &otherShortArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(10, ShortArrayCount(&shortArray));

    TEST_ASSERT_EQUAL(8, ShortArrayCount(&otherShortArray));

    ShortArraySort(&shortArray, ShortAscendingCompare);

    short x;

    ShortArrayAt(&shortArray, 0, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 1, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 2, &x);

    TEST_ASSERT_EQUAL(1, x);

    ShortArrayAt(&shortArray, 3, &x);

    TEST_ASSERT_EQUAL(2, x);

    ShortArrayAt(&shortArray, 4, &x);

    TEST_ASSERT_EQUAL(3, x);

    ShortArrayAt(&shortArray, 5, &x);

    TEST_ASSERT_EQUAL(4, x);

    ShortArrayAt(&shortArray, 6, &x);

    TEST_ASSERT_EQUAL(4, x);

    ShortArrayAt(&shortArray, 7, &x);

    TEST_ASSERT_EQUAL(5, x);

    ShortArrayAt(&shortArray, 8, &x);

    TEST_ASSERT_EQUAL(5, x);

    ShortArrayAt(&shortArray, 9, &x);

    TEST_ASSERT_EQUAL(5, x);
}
