#include "float_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(FloatArrayTests);

FloatArray floatArray;

TEST_SETUP(FloatArrayTests) {
  FloatArrayInitialize(&floatArray);
}

TEST_TEAR_DOWN(FloatArrayTests) {
  FloatArrayDeinitialize(&floatArray);
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
