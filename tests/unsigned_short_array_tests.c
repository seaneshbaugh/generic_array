#include "unsigned_short_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedShortArrayTests);

UnsignedShortArray unsignedShortArray;

TEST_SETUP(UnsignedShortArrayTests) {
  UnsignedShortArrayInitialize(&unsignedShortArray);
}

TEST_TEAR_DOWN(UnsignedShortArrayTests) {
  UnsignedShortArrayDeinitialize(&unsignedShortArray);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, unsignedShortArray.length);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedShortArray.capacity);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayPushOneElement) {
  int result = UnsignedShortArrayPush(&unsignedShortArray, 1U);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, unsignedShortArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedShortArray.capacity);
}

TEST(UnsignedShortArrayTests, UnsignedShortArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = UnsignedShortArrayPush(&unsignedShortArray, (unsigned short)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedShortArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedShortArray.capacity);
}
