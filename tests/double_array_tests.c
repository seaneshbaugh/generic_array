#include "double_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(DoubleArrayTests);

DoubleArray doubleArray;

TEST_SETUP(DoubleArrayTests) {
  DoubleArrayInitialize(&doubleArray);
}

TEST_TEAR_DOWN(DoubleArrayTests) {
  DoubleArrayDeinitialize(&doubleArray);
}

TEST(DoubleArrayTests, DoubleArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, doubleArray.length);
}

TEST(DoubleArrayTests, DoubleArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, doubleArray.capacity);
}

TEST(DoubleArrayTests, DoubleArrayPushOneElement) {
  int result = DoubleArrayPush(&doubleArray, 1.0);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, doubleArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, doubleArray.capacity);
}

TEST(DoubleArrayTests, DoubleArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = DoubleArrayPush(&doubleArray, (double)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, doubleArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, doubleArray.capacity);
}
