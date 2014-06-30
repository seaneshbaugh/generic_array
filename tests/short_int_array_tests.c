#include "short_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(ShortIntArrayTests);

ShortIntArray shortShortIntArray;

TEST_SETUP(ShortIntArrayTests) {
  ShortIntArrayInitialize(&shortShortIntArray);
}

TEST_TEAR_DOWN(ShortIntArrayTests) {
  ShortIntArrayDeinitialize(&shortShortIntArray);
}

TEST(ShortIntArrayTests, ShortIntArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, shortShortIntArray.length);
}

TEST(ShortIntArrayTests, ShortIntArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, shortShortIntArray.capacity);
}

TEST(ShortIntArrayTests, ShortIntArrayPushOneElement) {
  int result = ShortIntArrayPush(&shortShortIntArray, 1);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, shortShortIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, shortShortIntArray.capacity);
}

TEST(ShortIntArrayTests, ShortIntArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = ShortIntArrayPush(&shortShortIntArray, (short int)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, shortShortIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, shortShortIntArray.capacity);
}
