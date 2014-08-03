#include "float_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(FloatArrayTests);

FloatArray floatArray;
FloatArray otherFloatArray;

TEST_SETUP(FloatArrayTests) {
    FloatArrayInitialize(&floatArray);

    FloatArrayInitialize(&otherFloatArray);
}

TEST_TEAR_DOWN(FloatArrayTests) {
    FloatArrayDeinitialize(&floatArray);

    FloatArrayDeinitialize(&otherFloatArray);
}

TEST(FloatArrayTests, FloatArrayInitialLength) {
    TEST_ASSERT_EQUAL(0, floatArray.length);
}

TEST(FloatArrayTests, FloatArrayInitialCapacity) {
    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, floatArray.capacity);
}

TEST(FloatArrayTests, FloatArrayPushOneElement) {
    int result = FloatArrayPush(&floatArray, 1.0F);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, floatArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, floatArray.capacity);
}

TEST(FloatArrayTests, FloatArrayPushCapacityPlusOneElements) {
    int result;

    for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
        result = FloatArrayPush(&floatArray, (float)i);

        TEST_ASSERT_EQUAL(GA_SUCCESS, result);
    }

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, floatArray.length);

    TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, floatArray.capacity);
}

TEST(FloatArrayTests, FloatArrayAtZeroLength) {
    float x;

    int result = FloatArrayAt(&floatArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(FloatArrayTests, FloatArrayAtExistingElement) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&floatArray, 3.0F);

    FloatArrayPush(&floatArray, 4.0F);

    FloatArrayPush(&floatArray, 5.0F);

    float x;

    int result = FloatArrayAt(&floatArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3.0F, x);
}

TEST(FloatArrayTests, FloatArrayAtLessThanZeroIndex) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&floatArray, 3.0F);

    FloatArrayPush(&floatArray, 4.0F);

    FloatArrayPush(&floatArray, 5.0F);

    float x;

    int result = FloatArrayAt(&floatArray, -2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4.0F, x);
}

TEST(FloatArrayTests, FloatArrayAtGreaterThanLengthIndex) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&floatArray, 3.0F);

    FloatArrayPush(&floatArray, 4.0F);

    FloatArrayPush(&floatArray, 5.0F);

    float x;

    int result = FloatArrayAt(&floatArray, 5, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(FloatArrayTests, FloatArrayAtLessThanNegativeLengthIndex) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&floatArray, 3.0F);

    FloatArrayPush(&floatArray, 4.0F);

    FloatArrayPush(&floatArray, 5.0F);

    float x;

    int result = FloatArrayAt(&floatArray, -6, &x);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(FloatArrayTests, FloatArrayClear) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&floatArray, 3.0F);

    FloatArrayPush(&floatArray, 4.0F);

    FloatArrayPush(&floatArray, 5.0F);

    int result = FloatArrayClear(&floatArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, floatArray.length);
}

TEST(FloatArrayTests, FloatArrayConcatEmptyArrays) {
    int result = FloatArrayConcat(&floatArray, &otherFloatArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, floatArray.length);
}

TEST(FloatArrayTests, FloatArrayConcatEmptyArrayToNonEmptyArray) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    int result = FloatArrayConcat(&floatArray, &otherFloatArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, floatArray.length);

    float x;

    FloatArrayAt(&floatArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0F, x);

    FloatArrayAt(&floatArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0F, x);
}

TEST(FloatArrayTests, FloatArrayConcatNonEmptyArrayToEmptyArray) {
    FloatArrayPush(&otherFloatArray, 1.0F);

    FloatArrayPush(&otherFloatArray, 2.0F);

    int result = FloatArrayConcat(&floatArray, &otherFloatArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, floatArray.length);

    float x;

    FloatArrayAt(&floatArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0F, x);

    FloatArrayAt(&floatArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0F, x);
}

TEST(FloatArrayTests, FloatArrayConcatNonEmptyArrayToNonEmptyArray) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&otherFloatArray, 3.0F);

    FloatArrayPush(&otherFloatArray, 4.0F);

    int result = FloatArrayConcat(&floatArray, &otherFloatArray);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, floatArray.length);

    float x;

    FloatArrayAt(&floatArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0F, x);

    FloatArrayAt(&floatArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0F, x);

    FloatArrayAt(&floatArray, 2, &x);

    TEST_ASSERT_EQUAL(3.0F, x);

    FloatArrayAt(&floatArray, 3, &x);

    TEST_ASSERT_EQUAL(4.0F, x);
}

TEST(FloatArrayTests, FloatArrayCountEmptyArray) {
    size_t result = FloatArrayCount(&floatArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(FloatArrayTests, FloatArrayCountNonEmptyArray) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    size_t result = FloatArrayCount(&floatArray);

    TEST_ASSERT_EQUAL(2, result);
}

TEST(FloatArrayTests, FloatArrayDeleteFromEmptyArray) {
    int result = FloatArrayDelete(&floatArray, 1.0F);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, floatArray.length);
}

TEST(FloatArrayTests, FloatArrayDeleteNonExistingElement) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    int result = FloatArrayDelete(&floatArray, 3.0F);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, floatArray.length);
}

TEST(FloatArrayTests, FloatArrayDeleteExistingElement) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    int result = FloatArrayDelete(&floatArray, 2.0F);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1, floatArray.length);
}

TEST(FloatArrayTests, FloatArrayDeleteAtZeroLength) {
    int result = FloatArrayDeleteAt(&floatArray, 0);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(FloatArrayTests, FloatArrayDeleteAtExistingElement) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&floatArray, 3.0F);

    FloatArrayPush(&floatArray, 4.0F);

    FloatArrayPush(&floatArray, 5.0F);

    int result = FloatArrayDeleteAt(&floatArray, 2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, floatArray.length);

    float x;

    FloatArrayAt(&floatArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0F, x);

    FloatArrayAt(&floatArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0F, x);

    FloatArrayAt(&floatArray, 2, &x);

    TEST_ASSERT_EQUAL(4.0F, x);

    FloatArrayAt(&floatArray, 3, &x);

    TEST_ASSERT_EQUAL(5.0F, x);
}

TEST(FloatArrayTests, FloatArrayDeleteAtLessThanZeroIndex) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&floatArray, 3.0F);

    FloatArrayPush(&floatArray, 4.0F);

    FloatArrayPush(&floatArray, 5.0F);

    int result = FloatArrayDeleteAt(&floatArray, -2);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4, floatArray.length);

    float x;

    FloatArrayAt(&floatArray, 0, &x);

    TEST_ASSERT_EQUAL(1.0F, x);

    FloatArrayAt(&floatArray, 1, &x);

    TEST_ASSERT_EQUAL(2.0F, x);

    FloatArrayAt(&floatArray, 2, &x);

    TEST_ASSERT_EQUAL(3.0F, x);

    FloatArrayAt(&floatArray, 3, &x);

    TEST_ASSERT_EQUAL(5.0F, x);
}

TEST(FloatArrayTests, FloatArrayDeleteAtGreaterThanLengthIndex) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&floatArray, 3.0F);

    FloatArrayPush(&floatArray, 4.0F);

    FloatArrayPush(&floatArray, 5.0F);

    int result = FloatArrayDeleteAt(&floatArray, 5);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(FloatArrayTests, FloatArrayDeleteAtLessThanNegativeLengthIndex) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&floatArray, 3.0F);

    FloatArrayPush(&floatArray, 4.0F);

    FloatArrayPush(&floatArray, 5.0F);

    int result = FloatArrayDeleteAt(&floatArray, -6);

    TEST_ASSERT_EQUAL(GA_ERROR_INDEX_OUT_OF_BOUNDS, result);
}

TEST(FloatArrayTests, FloatArrayDropOneEmptyArray) {
    int result = FloatArrayDrop(&floatArray, 1);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, floatArray.length);
}

TEST(FloatArrayTests, FloatArrayDropManyEmptyArray) {
    int result = FloatArrayDrop(&floatArray, 10);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, floatArray.length);
}

TEST(FloatArrayTests, FloatArrayDropLessThanArrayLength) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&floatArray, 3.0F);

    FloatArrayPush(&floatArray, 4.0F);

    FloatArrayPush(&floatArray, 5.0F);

    int result = FloatArrayDrop(&floatArray, 3);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2, floatArray.length);

    float x;

    FloatArrayAt(&floatArray, 0, &x);

    TEST_ASSERT_EQUAL(4.0F, x);

    FloatArrayAt(&floatArray, 1, &x);

    TEST_ASSERT_EQUAL(5.0F, x);
}

TEST(FloatArrayTests, FloatArrayDropGreaterThanArrayLength) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&floatArray, 3.0F);

    FloatArrayPush(&floatArray, 4.0F);

    FloatArrayPush(&floatArray, 5.0F);

    int result = FloatArrayDrop(&floatArray, 6);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(0, floatArray.length);
}

TEST(FloatArrayTests, FloatArrayEmptyArrayIsEmpty) {
    int result = FloatArrayIsEmpty(&floatArray);

    TEST_ASSERT_EQUAL(1, result);
}

TEST(FloatArrayTests, FloatArrayNonEmptyArrayIsNotEmpty) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&floatArray, 3.0F);

    FloatArrayPush(&floatArray, 4.0F);

    FloatArrayPush(&floatArray, 5.0F);

    int result = FloatArrayIsEmpty(&floatArray);

    TEST_ASSERT_EQUAL(0, result);
}

TEST(FloatArrayTests, FloatArrayPush) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&floatArray, 3.0F);

    FloatArrayPush(&floatArray, 4.0F);

    FloatArrayPush(&floatArray, 5.0F);

    TEST_ASSERT_EQUAL(5, floatArray.length);

    float x;

    int result = FloatArrayAt(&floatArray, 0, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(1.0F, x);

    result = FloatArrayAt(&floatArray, 1, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(2.0F, x);

    result = FloatArrayAt(&floatArray, 2, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(3.0F, x);

    result = FloatArrayAt(&floatArray, 3, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(4.0F, x);

    result = FloatArrayAt(&floatArray, 4, &x);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL(5.0F, x);
}

TEST(FloatArrayTests, FloatArrayMultipleElementArrayToString) {
    FloatArrayPush(&floatArray, 1.0F);

    FloatArrayPush(&floatArray, 2.0F);

    FloatArrayPush(&floatArray, 3.0F);

    FloatArrayPush(&floatArray, 4.0F);

    FloatArrayPush(&floatArray, 5.0F);

    char* asString;

    int result = FloatArrayToString(&floatArray, &asString);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);

    TEST_ASSERT_EQUAL_STRING("[1.000000, 2.000000, 3.000000, 4.000000, 5.000000]", asString);

    free(asString);
}
