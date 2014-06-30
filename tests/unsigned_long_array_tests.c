#include "unsigned_long_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedLongArrayTests);

UnsignedLongArray unsignedLongArray;

TEST_SETUP(UnsignedLongArrayTests) {
  UnsignedLongArrayInitialize(&unsignedLongArray);
}

TEST_TEAR_DOWN(UnsignedLongArrayTests) {
  UnsignedLongArrayDeinitialize(&unsignedLongArray);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, unsignedLongArray.length);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongArray.capacity);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayPushOneElement) {
  int result = UnsignedLongArrayPush(&unsignedLongArray, 1UL);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, unsignedLongArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongArray.capacity);
}

TEST(UnsignedLongArrayTests, UnsignedLongArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = UnsignedLongArrayPush(&unsignedLongArray, (unsigned long)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedLongArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedLongArray.capacity);
}
