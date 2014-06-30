#include "signed_short_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedShortIntArrayTests);

SignedShortIntArray signedShortSignedShortIntArray;

TEST_SETUP(SignedShortIntArrayTests) {
  SignedShortIntArrayInitialize(&signedShortSignedShortIntArray);
}

TEST_TEAR_DOWN(SignedShortIntArrayTests) {
  SignedShortIntArrayDeinitialize(&signedShortSignedShortIntArray);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, signedShortSignedShortIntArray.length);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedShortSignedShortIntArray.capacity);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayPushOneElement) {
  int result = SignedShortIntArrayPush(&signedShortSignedShortIntArray, 1);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, signedShortSignedShortIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedShortSignedShortIntArray.capacity);
}

TEST(SignedShortIntArrayTests, SignedShortIntArrayPushCapacityPlusOneElements) {
  int result;

  for (int i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = SignedShortIntArrayPush(&signedShortSignedShortIntArray, (signed short int)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedShortSignedShortIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedShortSignedShortIntArray.capacity);
}
