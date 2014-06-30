#include "string_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(StringArrayTests);

StringArray stringArray;

TEST_SETUP(StringArrayTests) {
  StringArrayInitialize(&stringArray);
}

TEST_TEAR_DOWN(StringArrayTests) {
  StringArrayDeinitialize(&stringArray);
}

TEST(StringArrayTests, StringArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, stringArray.length);
}

TEST(StringArrayTests, StringArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, stringArray.capacity);
}

TEST(StringArrayTests, StringArrayPushOneElement) {
  int result = StringArrayPush(&stringArray, "test");

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, stringArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, stringArray.capacity);
}

TEST(StringArrayTests, StringArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = StringArrayPush(&stringArray, "test");

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, stringArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, stringArray.capacity);
}
