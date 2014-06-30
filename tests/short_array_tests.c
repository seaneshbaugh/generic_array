#include "short_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(ShortArrayTests);

ShortArray shortArray;

TEST_SETUP(ShortArrayTests) {
  ShortArrayInitialize(&shortArray);
}

TEST_TEAR_DOWN(ShortArrayTests) {
  ShortArrayDeinitialize(&shortArray);
}

TEST(ShortArrayTests, ShortArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, shortArray.length);
}

TEST(ShortArrayTests, ShortArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, shortArray.capacity);
}

TEST(ShortArrayTests, ShortArrayPushOneElement) {
  int result = ShortArrayPush(&shortArray, 1);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, shortArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, shortArray.capacity);
}

TEST(ShortArrayTests, ShortArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = ShortArrayPush(&shortArray, (short)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, shortArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, shortArray.capacity);
}
