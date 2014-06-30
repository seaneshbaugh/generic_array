#include "signed_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedIntArrayTests);

SignedIntArray signedSignedIntArray;

TEST_SETUP(SignedIntArrayTests) {
  SignedIntArrayInitialize(&signedSignedIntArray);
}

TEST_TEAR_DOWN(SignedIntArrayTests) {
  SignedIntArrayDeinitialize(&signedSignedIntArray);
}

TEST(SignedIntArrayTests, SignedIntArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, signedSignedIntArray.length);
}

TEST(SignedIntArrayTests, SignedIntArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedSignedIntArray.capacity);
}

TEST(SignedIntArrayTests, SignedIntArrayPushOneElement) {
  int result = SignedIntArrayPush(&signedSignedIntArray, 1);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, signedSignedIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedSignedIntArray.capacity);
}

TEST(SignedIntArrayTests, SignedIntArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = SignedIntArrayPush(&signedSignedIntArray, (signed int)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedSignedIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedSignedIntArray.capacity);
}
