#include "signed_long_long_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedLongLongArrayTests);

SignedLongLongArray signedLongLongArray;

TEST_SETUP(SignedLongLongArrayTests) {
  SignedLongLongArrayInitialize(&signedLongLongArray);
}

TEST_TEAR_DOWN(SignedLongLongArrayTests) {
  SignedLongLongArrayDeinitialize(&signedLongLongArray);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, signedLongLongArray.length);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongLongArray.capacity);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayPushOneElement) {
  int result = SignedLongLongArrayPush(&signedLongLongArray, 1LL);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, signedLongLongArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongLongArray.capacity);
}

TEST(SignedLongLongArrayTests, SignedLongLongArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = SignedLongLongArrayPush(&signedLongLongArray, (signed long long)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedLongLongArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedLongLongArray.capacity);
}
