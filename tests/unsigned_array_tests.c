#include "unsigned_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedArrayTests);

UnsignedArray unsignedArray;

TEST_SETUP(UnsignedArrayTests) {
  UnsignedArrayInitialize(&unsignedArray);
}

TEST_TEAR_DOWN(UnsignedArrayTests) {
  UnsignedArrayDeinitialize(&unsignedArray);
}

TEST(UnsignedArrayTests, UnsignedArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, unsignedArray.length);
}

TEST(UnsignedArrayTests, UnsignedArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedArray.capacity);
}

TEST(UnsignedArrayTests, UnsignedArrayPushOneElement) {
  int result = UnsignedArrayPush(&unsignedArray, 1U);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, unsignedArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedArray.capacity);
}

TEST(UnsignedArrayTests, UnsignedArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = UnsignedArrayPush(&unsignedArray, (unsigned)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedArray.capacity);
}
