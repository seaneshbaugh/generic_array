#include "unsigned_short_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedShortIntArrayTests);

UnsignedShortIntArray unsignedShortUnsignedShortIntArray;

TEST_SETUP(UnsignedShortIntArrayTests) {
  UnsignedShortIntArrayInitialize(&unsignedShortUnsignedShortIntArray);
}

TEST_TEAR_DOWN(UnsignedShortIntArrayTests) {
  UnsignedShortIntArrayDeinitialize(&unsignedShortUnsignedShortIntArray);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, unsignedShortUnsignedShortIntArray.length);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedShortUnsignedShortIntArray.capacity);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayPushOneElement) {
  int result = UnsignedShortIntArrayPush(&unsignedShortUnsignedShortIntArray, 1U);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, unsignedShortUnsignedShortIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedShortUnsignedShortIntArray.capacity);
}

TEST(UnsignedShortIntArrayTests, UnsignedShortIntArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = UnsignedShortIntArrayPush(&unsignedShortUnsignedShortIntArray, (unsigned short int)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedShortUnsignedShortIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedShortUnsignedShortIntArray.capacity);
}
