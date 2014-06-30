#include "unsigned_char_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(UnsignedCharArrayTests);

UnsignedCharArray unsignedCharArray;

TEST_SETUP(UnsignedCharArrayTests) {
  UnsignedCharArrayInitialize(&unsignedCharArray);
}

TEST_TEAR_DOWN(UnsignedCharArrayTests) {
  UnsignedCharArrayDeinitialize(&unsignedCharArray);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, unsignedCharArray.length);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedCharArray.capacity);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayPushOneElement) {
  int result = UnsignedCharArrayPush(&unsignedCharArray, 'A');

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, unsignedCharArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, unsignedCharArray.capacity);
}

TEST(UnsignedCharArrayTests, UnsignedCharArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = UnsignedCharArrayPush(&unsignedCharArray, (unsigned char)(i % 255));

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, unsignedCharArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, unsignedCharArray.capacity);
}
