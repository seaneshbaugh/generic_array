#include "int_array.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(IntArrayTests);

IntArray intArray;

TEST_SETUP(IntArrayTests) {
  IntArrayInitialize(&intArray);
}

TEST_TEAR_DOWN(IntArrayTests) {
  IntArrayDeinitialize(&intArray);
}

TEST(IntArrayTests, IntArrayInitialLength) {
  TEST_ASSERT_EQUAL(0, intArray.length);
}

TEST(IntArrayTests, IntArrayInitialCapacity) {
  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, intArray.capacity);
}

TEST(IntArrayTests, IntArrayPushOneElement) {
  int result = IntArrayPush(&intArray, 1);

  TEST_ASSERT_EQUAL(GA_SUCCESS, result);

  TEST_ASSERT_EQUAL(1, intArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY, intArray.capacity);
}

TEST(IntArrayTests, IntArrayPushCapacityPlusOneElements) {
  int result;

  for (size_t i = 0; i < GA_INITIAL_CAPACITY + 1; i++) {
    result = IntArrayPush(&intArray, (int)i);

    TEST_ASSERT_EQUAL(GA_SUCCESS, result);
  }

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY + 1, intArray.length);

  TEST_ASSERT_EQUAL(GA_INITIAL_CAPACITY * GA_CAPACITY_MULTIPLIER, intArray.capacity);
}
