#include "signed_long_long_int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedLongLongIntArrayTests);

SignedLongLongIntArray signedLongLongSignedLongLongIntArray;

TEST_SETUP(SignedLongLongIntArrayTests) {
  SignedLongLongIntArrayInitialize(&signedLongLongSignedLongLongIntArray);
}

TEST_TEAR_DOWN(SignedLongLongIntArrayTests) {
  SignedLongLongIntArrayDeinitialize(&signedLongLongSignedLongLongIntArray);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, signedLongLongSignedLongLongIntArray.length);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongLongSignedLongLongIntArray.capacity);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayPushOneElement) {
  int result = SignedLongLongIntArrayPush(&signedLongLongSignedLongLongIntArray, 1LL);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, signedLongLongSignedLongLongIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedLongLongSignedLongLongIntArray.capacity);
}

TEST(SignedLongLongIntArrayTests, SignedLongLongIntArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = SignedLongLongIntArrayPush(&signedLongLongSignedLongLongIntArray, (signed long long int)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedLongLongSignedLongLongIntArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedLongLongSignedLongLongIntArray.capacity);
}
