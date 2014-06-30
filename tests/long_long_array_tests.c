#include "long_long_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(LongLongArrayTests);

LongLongArray longLongArray;

TEST_SETUP(LongLongArrayTests) {
  LongLongArrayInitialize(&longLongArray);
}

TEST_TEAR_DOWN(LongLongArrayTests) {
  LongLongArrayDeinitialize(&longLongArray);
}

TEST(LongLongArrayTests, LongLongArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, longLongArray.length);
}

TEST(LongLongArrayTests, LongLongArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longLongArray.capacity);
}

TEST(LongLongArrayTests, LongLongArrayPushOneElement) {
  int result = LongLongArrayPush(&longLongArray, 1LL);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, longLongArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longLongArray.capacity);
}

TEST(LongLongArrayTests, LongLongArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = LongLongArrayPush(&longLongArray, (long long)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, longLongArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, longLongArray.capacity);
}
