#include "unsigned_long_long_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedLongLongArrayTests);

UnsignedLongLongArray unsignedLongLongArray;

TEST_SETUP(UnsignedLongLongArrayTests) {
  UnsignedLongLongArrayInitialize(&unsignedLongLongArray);
}

TEST_TEAR_DOWN(UnsignedLongLongArrayTests) {
  UnsignedLongLongArrayDeinitialize(&unsignedLongLongArray);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, unsignedLongLongArray.length);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongLongArray.capacity);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayPushOneElement) {
  int result = UnsignedLongLongArrayPush(&unsignedLongLongArray, 1ULL);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, unsignedLongLongArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongLongArray.capacity);
}

TEST(UnsignedLongLongArrayTests, UnsignedLongLongArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = UnsignedLongLongArrayPush(&unsignedLongLongArray, (unsigned long long)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedLongLongArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedLongLongArray.capacity);
}
