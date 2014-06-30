#include "long_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(LongArrayTests);

LongArray longArray;

TEST_SETUP(LongArrayTests) {
  LongArrayInitialize(&longArray);
}

TEST_TEAR_DOWN(LongArrayTests) {
  LongArrayDeinitialize(&longArray);
}

TEST(LongArrayTests, LongArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, longArray.length);
}

TEST(LongArrayTests, LongArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longArray.capacity);
}

TEST(LongArrayTests, LongArrayPushOneElement) {
  int result = LongArrayPush(&longArray, 1L);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, longArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longArray.capacity);
}

TEST(LongArrayTests, LongArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = LongArrayPush(&longArray, (long)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, longArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, longArray.capacity);
}
