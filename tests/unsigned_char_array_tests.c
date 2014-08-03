#include "unsigned_char_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedCharArrayTests);

UnsignedCharArray unsignedCharArray;
UnsignedCharArray otherUnsignedCharArray;

TEST_SETUP(UnsignedCharArrayTests) {
    UnsignedCharArrayInitialize(&unsignedCharArray);

    UnsignedCharArrayInitialize(&otherUnsignedCharArray);
}

TEST_TEAR_DOWN(UnsignedCharArrayTests) {
    UnsignedCharArrayDeinitialize(&unsignedCharArray);

    UnsignedCharArrayDeinitialize(&otherUnsignedCharArray);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, unsignedCharArray.length);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedCharArray.capacity);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayPushOneElement) {
    int result = UnsignedCharArrayPush(&unsignedCharArray, 'A');

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedCharArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedCharArray.capacity);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = UnsignedCharArrayPush(&unsignedCharArray, (unsigned char)(i % 255));

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedCharArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedCharArray.capacity);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayAtZeroLength) {
    unsigned char x;

    int result = UnsignedCharArrayAt(&unsignedCharArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayAtExistingElement) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    unsigned char x;

    int result = UnsignedCharArrayAt(&unsignedCharArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('C', x);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayAtLessThanZeroIndex) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    unsigned char x;

    int result = UnsignedCharArrayAt(&unsignedCharArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('D', x);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayAtGreaterThanLengthIndex) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    unsigned char x;

    int result = UnsignedCharArrayAt(&unsignedCharArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayAtLessThanNegativeLengthIndex) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    unsigned char x;

    int result = UnsignedCharArrayAt(&unsignedCharArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayClear) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    int result = UnsignedCharArrayClear(&unsignedCharArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedCharArray.length);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayConcatEmptyArrays) {
    int result = UnsignedCharArrayConcat(&unsignedCharArray, &otherUnsignedCharArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedCharArray.length);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayConcatEmptyArrayToNonEmptyArray) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    int result = UnsignedCharArrayConcat(&unsignedCharArray, &otherUnsignedCharArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedCharArray.length);

    unsigned char x;

    UnsignedCharArrayAt(&unsignedCharArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    UnsignedCharArrayAt(&unsignedCharArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayConcatNonEmptyArrayToEmptyArray) {
    UnsignedCharArrayPush(&otherUnsignedCharArray, 'A');

    UnsignedCharArrayPush(&otherUnsignedCharArray, 'B');

    int result = UnsignedCharArrayConcat(&unsignedCharArray, &otherUnsignedCharArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedCharArray.length);

    unsigned char x;

    UnsignedCharArrayAt(&unsignedCharArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    UnsignedCharArrayAt(&unsignedCharArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayConcatNonEmptyArrayToNonEmptyArray) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&otherUnsignedCharArray, 'C');

    UnsignedCharArrayPush(&otherUnsignedCharArray, 'D');

    int result = UnsignedCharArrayConcat(&unsignedCharArray, &otherUnsignedCharArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedCharArray.length);

    unsigned char x;

    UnsignedCharArrayAt(&unsignedCharArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    UnsignedCharArrayAt(&unsignedCharArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);

    UnsignedCharArrayAt(&unsignedCharArray, 2, &x);

    TEST_ASSERT_EQUAL('C', x);

    UnsignedCharArrayAt(&unsignedCharArray, 3, &x);

    TEST_ASSERT_EQUAL('D', x);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayCountEmptyArray) {
    size_t result = UnsignedCharArrayCount(&unsignedCharArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayCountNonEmptyArray) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    size_t result = UnsignedCharArrayCount(&unsignedCharArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayDeleteFromEmptyArray) {
    int result = UnsignedCharArrayDelete(&unsignedCharArray, 'A');

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedCharArray.length);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayDeleteNonExistingElement) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    int result = UnsignedCharArrayDelete(&unsignedCharArray, 'C');

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedCharArray.length);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayDeleteExistingElement) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    int result = UnsignedCharArrayDelete(&unsignedCharArray, 'B');

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, unsignedCharArray.length);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayDeleteAtZeroLength) {
    int result = UnsignedCharArrayDeleteAt(&unsignedCharArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayDeleteAtExistingElement) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    int result = UnsignedCharArrayDeleteAt(&unsignedCharArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedCharArray.length);

    unsigned char x;

    UnsignedCharArrayAt(&unsignedCharArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    UnsignedCharArrayAt(&unsignedCharArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);

    UnsignedCharArrayAt(&unsignedCharArray, 2, &x);

    TEST_ASSERT_EQUAL('D', x);

    UnsignedCharArrayAt(&unsignedCharArray, 3, &x);

    TEST_ASSERT_EQUAL('E', x);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayDeleteAtLessThanZeroIndex) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    int result = UnsignedCharArrayDeleteAt(&unsignedCharArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, unsignedCharArray.length);

    unsigned char x;

    UnsignedCharArrayAt(&unsignedCharArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    UnsignedCharArrayAt(&unsignedCharArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);

    UnsignedCharArrayAt(&unsignedCharArray, 2, &x);

    TEST_ASSERT_EQUAL('C', x);

    UnsignedCharArrayAt(&unsignedCharArray, 3, &x);

    TEST_ASSERT_EQUAL('E', x);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayDeleteAtGreaterThanLengthIndex) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    int result = UnsignedCharArrayDeleteAt(&unsignedCharArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayDeleteAtLessThanNegativeLengthIndex) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    int result = UnsignedCharArrayDeleteAt(&unsignedCharArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayDropOneEmptyArray) {
    int result = UnsignedCharArrayDrop(&unsignedCharArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedCharArray.length);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayDropManyEmptyArray) {
    int result = UnsignedCharArrayDrop(&unsignedCharArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedCharArray.length);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayDropLessThanArrayLength) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    int result = UnsignedCharArrayDrop(&unsignedCharArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, unsignedCharArray.length);

    unsigned char x;

    UnsignedCharArrayAt(&unsignedCharArray, 0, &x);

    TEST_ASSERT_EQUAL('D', x);

    UnsignedCharArrayAt(&unsignedCharArray, 1, &x);

    TEST_ASSERT_EQUAL('E', x);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayDropGreaterThanArrayLength) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    int result = UnsignedCharArrayDrop(&unsignedCharArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, unsignedCharArray.length);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayEmptyArrayIsEmpty) {
    int result = UnsignedCharArrayIsEmpty(&unsignedCharArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayNonEmptyArrayIsNotEmpty) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    int result = UnsignedCharArrayIsEmpty(&unsignedCharArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayPush) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    TEST_ASSERT_EQUAL(5, unsignedCharArray.length);

    unsigned char x;

    int result = UnsignedCharArrayAt(&unsignedCharArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('A', x);

    result = UnsignedCharArrayAt(&unsignedCharArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('B', x);

    result = UnsignedCharArrayAt(&unsignedCharArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('C', x);

    result = UnsignedCharArrayAt(&unsignedCharArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('D', x);

    result = UnsignedCharArrayAt(&unsignedCharArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL('E', x);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayMultipleElementArrayToString) {
    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    char* asString;

    int result = UnsignedCharArrayToString(&unsignedCharArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("['A', 'B', 'C', 'D', 'E']", asString);

    free(asString);
}

int UnsignedCharAscendingCompare(const void *a, const void *b) {
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

int UnsignedCharDescendingCompare(const void *a, const void *b) {
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

TEST(UnsignedCharArrayTests, UnsignedCharArraySortAscending) {
    UnsignedCharArrayPush(&unsignedCharArray, 'C');

    UnsignedCharArrayPush(&unsignedCharArray, 'B');

    UnsignedCharArrayPush(&unsignedCharArray, 'D');

    UnsignedCharArrayPush(&unsignedCharArray, 'E');

    UnsignedCharArrayPush(&unsignedCharArray, 'A');

    UnsignedCharArraySort(&unsignedCharArray, UnsignedCharAscendingCompare);

    unsigned char x;

    UnsignedCharArrayAt(&unsignedCharArray, 0, &x);

    TEST_ASSERT_EQUAL('A', x);

    UnsignedCharArrayAt(&unsignedCharArray, 1, &x);

    TEST_ASSERT_EQUAL('B', x);

    UnsignedCharArrayAt(&unsignedCharArray, 2, &x);

    TEST_ASSERT_EQUAL('C', x);

    UnsignedCharArrayAt(&unsignedCharArray, 3, &x);

    TEST_ASSERT_EQUAL('D', x);

    UnsignedCharArrayAt(&unsignedCharArray, 4, &x);

    TEST_ASSERT_EQUAL('E', x);
}
