#include "signed_char_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(SignedCharArrayTests);

SignedCharArray signedCharArray;

TEST_SETUP(SignedCharArrayTests) {
  SignedCharArrayInitialize(&signedCharArray);
}

TEST_TEAR_DOWN(SignedCharArrayTests) {
  SignedCharArrayDeinitialize(&signedCharArray);
}

TEST(SignedCharArrayTests, SignedCharArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, signedCharArray.length);
}

TEST(SignedCharArrayTests, SignedCharArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedCharArray.capacity);
}

TEST(SignedCharArrayTests, SignedCharArrayPushOneElement) {
  int result = SignedCharArrayPush(&signedCharArray, 'A');

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, signedCharArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, signedCharArray.capacity);
}

TEST(SignedCharArrayTests, SignedCharArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = SignedCharArrayPush(&signedCharArray, (signed char)(i % 255));

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, signedCharArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, signedCharArray.capacity);
}
