#include "long_double_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(LongDoubleArrayTests);

LongDoubleArray longDoubleArray;

TEST_SETUP(LongDoubleArrayTests) {
  LongDoubleArrayInitialize(&longDoubleArray);
}

TEST_TEAR_DOWN(LongDoubleArrayTests) {
  LongDoubleArrayDeinitialize(&longDoubleArray);
}

TEST(LongDoubleArrayTests, LongDoubleArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, longDoubleArray.length);
}

TEST(LongDoubleArrayTests, LongDoubleArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longDoubleArray.capacity);
}

TEST(LongDoubleArrayTests, LongDoubleArrayPushOneElement) {
  int result = LongDoubleArrayPush(&longDoubleArray, 1.0L);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, longDoubleArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longDoubleArray.capacity);
}

TEST(LongDoubleArrayTests, LongDoubleArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = LongDoubleArrayPush(&longDoubleArray, (long double)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, longDoubleArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, longDoubleArray.capacity);
}
