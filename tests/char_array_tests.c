#include "char_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(CharArrayTests);

CharArray charArray;

TEST_SETUP(CharArrayTests) {
  CharArrayInitialize(&charArray);
}

TEST_TEAR_DOWN(CharArrayTests) {
  CharArrayDeinitialize(&charArray);
}

TEST(CharArrayTests, CharArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, charArray.length);
}

TEST(CharArrayTests, CharArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, charArray.capacity);
}

TEST(CharArrayTests, CharArrayPushOneElement) {
  int result = CharArrayPush(&charArray, 'A');

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, charArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, charArray.capacity);
}

TEST(CharArrayTests, CharArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = CharArrayPush(&charArray, (char)(i % 255));

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, charArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, charArray.capacity);
}
