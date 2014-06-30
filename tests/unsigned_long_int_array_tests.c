#include "unsigned_long_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedLongIntArrayTests);

UnsignedLongIntArray unsignedLongIntArray;

TEST_SETUP(UnsignedLongIntArrayTests) {
  UnsignedLongIntArrayInitialize(&unsignedLongIntArray);
}

TEST_TEAR_DOWN(UnsignedLongIntArrayTests) {
  UnsignedLongIntArrayDeinitialize(&unsignedLongIntArray);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, unsignedLongIntArray.length);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongIntArray.capacity);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayPushOneElement) {
  int result = UnsignedLongIntArrayPush(&unsignedLongIntArray, 1UL);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, unsignedLongIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongIntArray.capacity);
}

TEST(UnsignedLongIntArrayTests, UnsignedLongIntArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = UnsignedLongIntArrayPush(&unsignedLongIntArray, (unsigned long int)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedLongIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedLongIntArray.capacity);
}
