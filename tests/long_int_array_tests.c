#include "long_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(LongIntArrayTests);

LongIntArray longLongIntArray;

TEST_SETUP(LongIntArrayTests) {
  LongIntArrayInitialize(&longLongIntArray);
}

TEST_TEAR_DOWN(LongIntArrayTests) {
  LongIntArrayDeinitialize(&longLongIntArray);
}

TEST(LongIntArrayTests, LongIntArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, longLongIntArray.length);
}

TEST(LongIntArrayTests, LongIntArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longLongIntArray.capacity);
}

TEST(LongIntArrayTests, LongIntArrayPushOneElement) {
  int result = LongIntArrayPush(&longLongIntArray, 1L);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, longLongIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longLongIntArray.capacity);
}

TEST(LongIntArrayTests, LongIntArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = LongIntArrayPush(&longLongIntArray, (long int)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, longLongIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, longLongIntArray.capacity);
}
