#include "unsigned_long_long_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedLongLongIntArrayTests);

UnsignedLongLongIntArray unsignedLongLongIntArray;

TEST_SETUP(UnsignedLongLongIntArrayTests) {
  UnsignedLongLongIntArrayInitialize(&unsignedLongLongIntArray);
}

TEST_TEAR_DOWN(UnsignedLongLongIntArrayTests) {
  UnsignedLongLongIntArrayDeinitialize(&unsignedLongLongIntArray);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, unsignedLongLongIntArray.length);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongLongIntArray.capacity);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayPushOneElement) {
  int result = UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, 1ULL);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, unsignedLongLongIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedLongLongIntArray.capacity);
}

TEST(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = UnsignedLongLongIntArrayPush(&unsignedLongLongIntArray, (unsigned long long int)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedLongLongIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedLongLongIntArray.capacity);
}
