#include "signed_long_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedLongArrayTests);

SignedLongArray signedLongArray;

TEST_SETUP(SignedLongArrayTests) {
  SignedLongArrayInitialize(&signedLongArray);
}

TEST_TEAR_DOWN(SignedLongArrayTests) {
  SignedLongArrayDeinitialize(&signedLongArray);
}

TEST(SignedLongArrayTests, SignedLongArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, signedLongArray.length);
}

TEST(SignedLongArrayTests, SignedLongArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongArray.capacity);
}

TEST(SignedLongArrayTests, SignedLongArrayPushOneElement) {
  int result = SignedLongArrayPush(&signedLongArray, 1L);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, signedLongArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongArray.capacity);
}

TEST(SignedLongArrayTests, SignedLongArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = SignedLongArrayPush(&signedLongArray, (signed long)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedLongArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedLongArray.capacity);
}
