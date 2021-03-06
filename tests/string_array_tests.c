#include "string_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(StringArrayTests);

StringArray stringArray;
StringArray otherStringArray;

TEST_SETUP(StringArrayTests) {
    StringArrayInitialize(&stringArray);

    StringArrayInitialize(&otherStringArray);
}

TEST_TEAR_DOWN(StringArrayTests) {
    StringArrayDeinitialize(&stringArray);

    StringArrayDeinitialize(&otherStringArray);
}

TEST(StringArrayTests, StringArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, stringArray.length);
}

TEST(StringArrayTests, StringArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, stringArray.capacity);
}

TEST(StringArrayTests, StringArrayInitializeFromEmptyPointer) {
    char* values[] = { };

    int result = StringArrayInitializeFromPointer(&stringArray, values, 0);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, StringArrayCount(&stringArray));
}

TEST(StringArrayTests, StringArrayInitializeFromPointer) {
    char* values[5] = { "test 1", "test 2", "test 3", "test 4", "test 5" };

    int result = StringArrayInitializeFromPointer(&stringArray, values, 5);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, StringArrayCount(&stringArray));
}

TEST(StringArrayTests, StringArrayPushOneElement) {
    int result = StringArrayPush(&stringArray, "test 1");

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, stringArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, stringArray.capacity);
}

TEST(StringArrayTests, StringArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = StringArrayPush(&stringArray, (char*)"test");

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, stringArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, stringArray.capacity);
}

TEST(StringArrayTests, StringArrayAtZeroLength) {
    char* x;

    int result = StringArrayAt(&stringArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(StringArrayTests, StringArrayAtExistingElement) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    char* x;

    int result = StringArrayAt(&stringArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL("test 3", x);
}

TEST(StringArrayTests, StringArrayAtLessThanZeroIndex) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    char* x;

    int result = StringArrayAt(&stringArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL("test 4", x);
}

TEST(StringArrayTests, StringArrayAtGreaterThanLengthIndex) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    char* x;

    int result = StringArrayAt(&stringArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(StringArrayTests, StringArrayAtLessThanNegativeLengthIndex) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    char* x;

    int result = StringArrayAt(&stringArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(StringArrayTests, StringArrayClear) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    int result = StringArrayClear(&stringArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, stringArray.length);
}

TEST(StringArrayTests, StringArrayConcatEmptyArrays) {
    int result = StringArrayConcat(&stringArray, &otherStringArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, stringArray.length);
}

TEST(StringArrayTests, StringArrayConcatEmptyArrayToNonEmptyArray) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    int result = StringArrayConcat(&stringArray, &otherStringArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, stringArray.length);

    char* x;

    StringArrayAt(&stringArray, 0, &x);

    TEST_ASSERT_EQUAL("test 1", x);

    StringArrayAt(&stringArray, 1, &x);

    TEST_ASSERT_EQUAL("test 2", x);
}

TEST(StringArrayTests, StringArrayConcatNonEmptyArrayToEmptyArray) {
    StringArrayPush(&otherStringArray, "test 1");

    StringArrayPush(&otherStringArray, "test 2");

    int result = StringArrayConcat(&stringArray, &otherStringArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, stringArray.length);

    char* x;

    StringArrayAt(&stringArray, 0, &x);

    TEST_ASSERT_EQUAL("test 1", x);

    StringArrayAt(&stringArray, 1, &x);

    TEST_ASSERT_EQUAL("test 2", x);
}

TEST(StringArrayTests, StringArrayConcatNonEmptyArrayToNonEmptyArray) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&otherStringArray, "test 3");

    StringArrayPush(&otherStringArray, "test 4");

    int result = StringArrayConcat(&stringArray, &otherStringArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, stringArray.length);

    char* x;

    StringArrayAt(&stringArray, 0, &x);

    TEST_ASSERT_EQUAL("test 1", x);

    StringArrayAt(&stringArray, 1, &x);

    TEST_ASSERT_EQUAL("test 2", x);

    StringArrayAt(&stringArray, 2, &x);

    TEST_ASSERT_EQUAL("test 3", x);

    StringArrayAt(&stringArray, 3, &x);

    TEST_ASSERT_EQUAL("test 4", x);
}

TEST(StringArrayTests, StringArrayCountEmptyArray) {
    size_t result = StringArrayCount(&stringArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(StringArrayTests, StringArrayCountNonEmptyArray) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    size_t result = StringArrayCount(&stringArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(StringArrayTests, StringArrayDeleteFromEmptyArray) {
    int result = StringArrayDelete(&stringArray, "test 1");

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, stringArray.length);
}

TEST(StringArrayTests, StringArrayDeleteNonExistingElement) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    int result = StringArrayDelete(&stringArray, "test 3");

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, stringArray.length);
}

TEST(StringArrayTests, StringArrayDeleteExistingElement) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    int result = StringArrayDelete(&stringArray, "test 2");

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, stringArray.length);
}

TEST(StringArrayTests, StringArrayDeleteAtZeroLength) {
    int result = StringArrayDeleteAt(&stringArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(StringArrayTests, StringArrayDeleteAtExistingElement) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    int result = StringArrayDeleteAt(&stringArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, stringArray.length);

    char* x;

    StringArrayAt(&stringArray, 0, &x);

    TEST_ASSERT_EQUAL("test 1", x);

    StringArrayAt(&stringArray, 1, &x);

    TEST_ASSERT_EQUAL("test 2", x);

    StringArrayAt(&stringArray, 2, &x);

    TEST_ASSERT_EQUAL("test 4", x);

    StringArrayAt(&stringArray, 3, &x);

    TEST_ASSERT_EQUAL("test 5", x);
}

TEST(StringArrayTests, StringArrayDeleteAtLessThanZeroIndex) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    int result = StringArrayDeleteAt(&stringArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, stringArray.length);

    char* x;

    StringArrayAt(&stringArray, 0, &x);

    TEST_ASSERT_EQUAL("test 1", x);

    StringArrayAt(&stringArray, 1, &x);

    TEST_ASSERT_EQUAL("test 2", x);

    StringArrayAt(&stringArray, 2, &x);

    TEST_ASSERT_EQUAL("test 3", x);

    StringArrayAt(&stringArray, 3, &x);

    TEST_ASSERT_EQUAL("test 5", x);
}

TEST(StringArrayTests, StringArrayDeleteAtGreaterThanLengthIndex) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    int result = StringArrayDeleteAt(&stringArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(StringArrayTests, StringArrayDeleteAtLessThanNegativeLengthIndex) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    int result = StringArrayDeleteAt(&stringArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(StringArrayTests, StringArrayDropOneEmptyArray) {
    int result = StringArrayDrop(&stringArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, stringArray.length);
}

TEST(StringArrayTests, StringArrayDropManyEmptyArray) {
    int result = StringArrayDrop(&stringArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, stringArray.length);
}

TEST(StringArrayTests, StringArrayDropLessThanArrayLength) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    int result = StringArrayDrop(&stringArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, stringArray.length);

    char* x;

    StringArrayAt(&stringArray, 0, &x);

    TEST_ASSERT_EQUAL("test 4", x);

    StringArrayAt(&stringArray, 1, &x);

    TEST_ASSERT_EQUAL("test 5", x);
}

TEST(StringArrayTests, StringArrayDropGreaterThanArrayLength) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    int result = StringArrayDrop(&stringArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, stringArray.length);
}

TEST(StringArrayTests, StringArrayEmptyArrayIsEmpty) {
    int result = StringArrayIsEmpty(&stringArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(StringArrayTests, StringArrayNonEmptyArrayIsNotEmpty) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    int result = StringArrayIsEmpty(&stringArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(StringArrayTests, StringArrayPush) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    TEST_ASSERT_EQUAL(5, stringArray.length);

    char* x;

    int result = StringArrayAt(&stringArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL("test 1", x);

    result = StringArrayAt(&stringArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL("test 2", x);

    result = StringArrayAt(&stringArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL("test 3", x);

    result = StringArrayAt(&stringArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL("test 4", x);

    result = StringArrayAt(&stringArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL("test 5", x);
}

TEST(StringArrayTests, StringArrayMultipleElementArrayToString) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    char* asString;

    int result = StringArrayToString(&stringArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[\"test 1\", \"test 2\", \"test 3\", \"test 4\", \"test 5\"]", asString);

    free(asString);
}

TEST(StringArrayTests, StringArraySetZeroLength) {
    int result = StringArraySet(&stringArray, 2, "test 5");

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(StringArrayTests, StringArraySetExistingElement) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    int result = StringArraySet(&stringArray, 2, "test 5");

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    char* x;

    result = StringArrayAt(&stringArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL("test 5", x);
}

TEST(StringArrayTests, StringArraySetLessThanZeroIndex) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    int result = StringArraySet(&stringArray, -2, "test 5");

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    char* x;

    result = StringArrayAt(&stringArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL("test 5", x);
}

TEST(StringArrayTests, StringArraySetGreaterThanLengthIndex) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    int result = StringArraySet(&stringArray, 4, "test 5");

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(StringArrayTests, StringArraySetLessThanNegativeLengthIndex) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    int result = StringArraySet(&stringArray, -5, "test 5");

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

int StringAscendingCompare(const void *a, const void *b) {
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

int StringDescendingCompare(const void *a, const void *b) {
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

TEST(StringArrayTests, StringArraySortEmptyArray) {
    StringArraySort(&stringArray, StringAscendingCompare);

    TEST_ASSERT_EQUAL(0, StringArrayCount(&stringArray));
}

TEST(StringArrayTests, StringArraySortAscending) {
    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    StringArrayPush(&stringArray, "test 1");

    StringArraySort(&stringArray, StringAscendingCompare);

    char* x;

    StringArrayAt(&stringArray, 0, &x);

    TEST_ASSERT_EQUAL_STRING("test 1", x);

    StringArrayAt(&stringArray, 1, &x);

    TEST_ASSERT_EQUAL_STRING("test 2", x);

    StringArrayAt(&stringArray, 2, &x);

    TEST_ASSERT_EQUAL_STRING("test 3", x);

    StringArrayAt(&stringArray, 3, &x);

    TEST_ASSERT_EQUAL_STRING("test 4", x);

    StringArrayAt(&stringArray, 4, &x);

    TEST_ASSERT_EQUAL_STRING("test 5", x);
}

TEST(StringArrayTests, StringArraySortDescending) {
    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    StringArrayPush(&stringArray, "test 1");

    StringArraySort(&stringArray, StringDescendingCompare);

    char* x;

    StringArrayAt(&stringArray, 0, &x);

    TEST_ASSERT_EQUAL_STRING("test 5", x);

    StringArrayAt(&stringArray, 1, &x);

    TEST_ASSERT_EQUAL_STRING("test 4", x);

    StringArrayAt(&stringArray, 2, &x);

    TEST_ASSERT_EQUAL_STRING("test 3", x);

    StringArrayAt(&stringArray, 3, &x);

    TEST_ASSERT_EQUAL_STRING("test 2", x);

    StringArrayAt(&stringArray, 4, &x);

    TEST_ASSERT_EQUAL_STRING("test 1", x);
}

TEST(StringArrayTests, StringArrayOverlapEmptyArrays) {
    int result = StringArrayOverlap(&stringArray, &otherStringArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, StringArrayCount(&stringArray));

    TEST_ASSERT_EQUAL(0, StringArrayCount(&otherStringArray));
}

TEST(StringArrayTests, StringArrayOverlapNonEmptyArrayWithEmptyArray) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 2");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    int result = StringArrayOverlap(&stringArray, &otherStringArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, StringArrayCount(&stringArray));

    TEST_ASSERT_EQUAL(0, StringArrayCount(&otherStringArray));

    StringArraySort(&stringArray, StringAscendingCompare);

    char* x;

    StringArrayAt(&stringArray, 0, &x);

    TEST_ASSERT_EQUAL_STRING("test 1", x);

    StringArrayAt(&stringArray, 1, &x);

    TEST_ASSERT_EQUAL_STRING("test 2", x);

    StringArrayAt(&stringArray, 2, &x);

    TEST_ASSERT_EQUAL_STRING("test 3", x);

    StringArrayAt(&stringArray, 3, &x);

    TEST_ASSERT_EQUAL_STRING("test 4", x);

    StringArrayAt(&stringArray, 4, &x);

    TEST_ASSERT_EQUAL_STRING("test 5", x);
}

TEST(StringArrayTests, StringArrayOverlapEmptyArrayWithNonEmptyArray) {
    StringArrayPush(&otherStringArray, "test 1");

    StringArrayPush(&otherStringArray, "test 2");

    StringArrayPush(&otherStringArray, "test 3");

    StringArrayPush(&otherStringArray, "test 4");

    StringArrayPush(&otherStringArray, "test 5");

    int result = StringArrayOverlap(&stringArray, &otherStringArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5, StringArrayCount(&stringArray));

    TEST_ASSERT_EQUAL(5, StringArrayCount(&otherStringArray));

    StringArraySort(&stringArray, StringAscendingCompare);

    char* x;

    StringArrayAt(&stringArray, 0, &x);

    TEST_ASSERT_EQUAL_STRING("test 1", x);

    StringArrayAt(&stringArray, 1, &x);

    TEST_ASSERT_EQUAL_STRING("test 2", x);

    StringArrayAt(&stringArray, 2, &x);

    TEST_ASSERT_EQUAL_STRING("test 3", x);

    StringArrayAt(&stringArray, 3, &x);

    TEST_ASSERT_EQUAL_STRING("test 4", x);

    StringArrayAt(&stringArray, 4, &x);

    TEST_ASSERT_EQUAL_STRING("test 5", x);
}

TEST(StringArrayTests, StringArrayOverlapNonEmptyArrays) {
    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 1");

    StringArrayPush(&stringArray, "test 3");

    StringArrayPush(&stringArray, "test 4");

    StringArrayPush(&stringArray, "test 5");

    StringArrayPush(&stringArray, "test 5");

    StringArrayPush(&otherStringArray, "test 1");

    StringArrayPush(&otherStringArray, "test 2");

    StringArrayPush(&otherStringArray, "test 3");

    StringArrayPush(&otherStringArray, "test 4");

    StringArrayPush(&otherStringArray, "test 4");

    StringArrayPush(&otherStringArray, "test 5");

    StringArrayPush(&otherStringArray, "test 5");

    StringArrayPush(&otherStringArray, "test 5");

    int result = StringArrayOverlap(&stringArray, &otherStringArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(10, StringArrayCount(&stringArray));

    TEST_ASSERT_EQUAL(8, StringArrayCount(&otherStringArray));

    StringArraySort(&stringArray, StringAscendingCompare);

    char* x;

    StringArrayAt(&stringArray, 0, &x);

    TEST_ASSERT_EQUAL_STRING("test 1", x);

    StringArrayAt(&stringArray, 1, &x);

    TEST_ASSERT_EQUAL_STRING("test 1", x);

    StringArrayAt(&stringArray, 2, &x);

    TEST_ASSERT_EQUAL_STRING("test 1", x);

    StringArrayAt(&stringArray, 3, &x);

    TEST_ASSERT_EQUAL_STRING("test 2", x);

    StringArrayAt(&stringArray, 4, &x);

    TEST_ASSERT_EQUAL_STRING("test 3", x);

    StringArrayAt(&stringArray, 5, &x);

    TEST_ASSERT_EQUAL_STRING("test 4", x);

    StringArrayAt(&stringArray, 6, &x);

    TEST_ASSERT_EQUAL_STRING("test 4", x);

    StringArrayAt(&stringArray, 7, &x);

    TEST_ASSERT_EQUAL_STRING("test 5", x);

    StringArrayAt(&stringArray, 8, &x);

    TEST_ASSERT_EQUAL_STRING("test 5", x);

    StringArrayAt(&stringArray, 9, &x);

    TEST_ASSERT_EQUAL_STRING("test 5", x);
}
