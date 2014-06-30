#include "long_long_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(LongLongIntArrayTests);

LongLongIntArray longLongLongLongIntArray;

TEST_SETUP(LongLongIntArrayTests) {
  LongLongIntArrayInitialize(&longLongLongLongIntArray);
}

TEST_TEAR_DOWN(LongLongIntArrayTests) {
  LongLongIntArrayDeinitialize(&longLongLongLongIntArray);
}

TEST(LongLongIntArrayTests, LongLongIntArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, longLongLongLongIntArray.length);
}

TEST(LongLongIntArrayTests, LongLongIntArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longLongLongLongIntArray.capacity);
}

TEST(LongLongIntArrayTests, LongLongIntArrayPushOneElement) {
  int result = LongLongIntArrayPush(&longLongLongLongIntArray, 1LL);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, longLongLongLongIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, longLongLongLongIntArray.capacity);
}

TEST(LongLongIntArrayTests, LongLongIntArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = LongLongIntArrayPush(&longLongLongLongIntArray, (long long int)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, longLongLongLongIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, longLongLongLongIntArray.capacity);
}
