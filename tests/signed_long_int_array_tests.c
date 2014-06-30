#include "signed_long_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedLongIntArrayTests);

SignedLongIntArray signedLongSignedLongIntArray;

TEST_SETUP(SignedLongIntArrayTests) {
  SignedLongIntArrayInitialize(&signedLongSignedLongIntArray);
}

TEST_TEAR_DOWN(SignedLongIntArrayTests) {
  SignedLongIntArrayDeinitialize(&signedLongSignedLongIntArray);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, signedLongSignedLongIntArray.length);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongSignedLongIntArray.capacity);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayPushOneElement) {
  int result = SignedLongIntArrayPush(&signedLongSignedLongIntArray, 1L);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, signedLongSignedLongIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongSignedLongIntArray.capacity);
}

TEST(SignedLongIntArrayTests, SignedLongIntArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = SignedLongIntArrayPush(&signedLongSignedLongIntArray, (signed long int)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedLongSignedLongIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedLongSignedLongIntArray.capacity);
}
