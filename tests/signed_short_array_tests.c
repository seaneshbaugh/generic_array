#include "signed_short_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedShortArrayTests);

SignedShortArray signedShortArray;

TEST_SETUP(SignedShortArrayTests) {
  SignedShortArrayInitialize(&signedShortArray);
}

TEST_TEAR_DOWN(SignedShortArrayTests) {
  SignedShortArrayDeinitialize(&signedShortArray);
}

TEST(SignedShortArrayTests, SignedShortArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, signedShortArray.length);
}

TEST(SignedShortArrayTests, SignedShortArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedShortArray.capacity);
}

TEST(SignedShortArrayTests, SignedShortArrayPushOneElement) {
  int result = SignedShortArrayPush(&signedShortArray, 1);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, signedShortArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedShortArray.capacity);
}

TEST(SignedShortArrayTests, SignedShortArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = SignedShortArrayPush(&signedShortArray, (signed short)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedShortArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedShortArray.capacity);
}
