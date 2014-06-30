#include "unsigned_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedIntArrayTests);

UnsignedIntArray unsignedIntArray;

TEST_SETUP(UnsignedIntArrayTests) {
  UnsignedIntArrayInitialize(&unsignedIntArray);
}

TEST_TEAR_DOWN(UnsignedIntArrayTests) {
  UnsignedIntArrayDeinitialize(&unsignedIntArray);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, unsignedIntArray.length);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedIntArray.capacity);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayPushOneElement) {
  int result = UnsignedIntArrayPush(&unsignedIntArray, 1U);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, unsignedIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedIntArray.capacity);
}

TEST(UnsignedIntArrayTests, UnsignedIntArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = UnsignedIntArrayPush(&unsignedIntArray, (unsigned int)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedIntArray.capacity);
}
