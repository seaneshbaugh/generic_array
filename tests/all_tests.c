#include "unity_fixture.h"

TEST_GROUP_RUNNER(CharArrayTests) {
  RUN_TEST_CASE(CharArrayTests, CharArrayInitialLength);
  RUN_TEST_CASE(CharArrayTests, CharArrayInitialCapacity);
  RUN_TEST_CASE(CharArrayTests, CharArrayPushOneElement);
  RUN_TEST_CASE(CharArrayTests, CharArrayPushCapacityPlusOneElements);
  RUN_TEST_CASE(CharArrayTests, CharArrayAtZeroLength);
  RUN_TEST_CASE(CharArrayTests, CharArrayAtExistingElement);
  RUN_TEST_CASE(CharArrayTests, CharArrayAtLessThanZeroIndex);
  RUN_TEST_CASE(CharArrayTests, CharArrayAtGreaterThanLengthIndex);
  RUN_TEST_CASE(CharArrayTests, CharArrayAtLessThanNegativeLengthIndex);
  RUN_TEST_CASE(CharArrayTests, CharArrayClear);
  RUN_TEST_CASE(CharArrayTests, CharArrayConcatEmptyArrays);
  RUN_TEST_CASE(CharArrayTests, CharArrayConcatEmptyArrayToNonEmptyArray);
  RUN_TEST_CASE(CharArrayTests, CharArrayConcatNonEmptyArrayToEmptyArray);
  RUN_TEST_CASE(CharArrayTests, CharArrayConcatNonEmptyArrayToNonEmptyArray);
  RUN_TEST_CASE(CharArrayTests, CharArrayCountEmptyArray);
  RUN_TEST_CASE(CharArrayTests, CharArrayCountNonEmptyArray);
  RUN_TEST_CASE(CharArrayTests, CharArrayDeleteFromEmptyArray);
  RUN_TEST_CASE(CharArrayTests, CharArrayDeleteNonExistingElement);
  RUN_TEST_CASE(CharArrayTests, CharArrayDeleteExistingElement);
}

TEST_GROUP_RUNNER(DoubleArrayTests) {
  RUN_TEST_CASE(DoubleArrayTests, DoubleArrayInitialLength);
  RUN_TEST_CASE(DoubleArrayTests, DoubleArrayInitialCapacity);
  RUN_TEST_CASE(DoubleArrayTests, DoubleArrayPushOneElement);
  RUN_TEST_CASE(DoubleArrayTests, DoubleArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(FloatArrayTests) {
  RUN_TEST_CASE(FloatArrayTests, FloatArrayInitialLength);
  RUN_TEST_CASE(FloatArrayTests, FloatArrayInitialCapacity);
  RUN_TEST_CASE(FloatArrayTests, FloatArrayPushOneElement);
  RUN_TEST_CASE(FloatArrayTests, FloatArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(IntArrayTests) {
  RUN_TEST_CASE(IntArrayTests, IntArrayInitialLength);
  RUN_TEST_CASE(IntArrayTests, IntArrayInitialCapacity);
  RUN_TEST_CASE(IntArrayTests, IntArrayPushOneElement);
  RUN_TEST_CASE(IntArrayTests, IntArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(LongArrayTests) {
  RUN_TEST_CASE(LongArrayTests, LongArrayInitialLength);
  RUN_TEST_CASE(LongArrayTests, LongArrayInitialCapacity);
  RUN_TEST_CASE(LongArrayTests, LongArrayPushOneElement);
  RUN_TEST_CASE(LongArrayTests, LongArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(LongDoubleArrayTests) {
  RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayInitialLength);
  RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayInitialCapacity);
  RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayPushOneElement);
  RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(LongIntArrayTests) {
  RUN_TEST_CASE(LongIntArrayTests, LongIntArrayInitialLength);
  RUN_TEST_CASE(LongIntArrayTests, LongIntArrayInitialCapacity);
  RUN_TEST_CASE(LongIntArrayTests, LongIntArrayPushOneElement);
  RUN_TEST_CASE(LongIntArrayTests, LongIntArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(LongLongArrayTests) {
  RUN_TEST_CASE(LongLongArrayTests, LongLongArrayInitialLength);
  RUN_TEST_CASE(LongLongArrayTests, LongLongArrayInitialCapacity);
  RUN_TEST_CASE(LongLongArrayTests, LongLongArrayPushOneElement);
  RUN_TEST_CASE(LongLongArrayTests, LongLongArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(LongLongIntArrayTests) {
  RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayInitialLength);
  RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayInitialCapacity);
  RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayPushOneElement);
  RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(ShortArrayTests) {
  RUN_TEST_CASE(ShortArrayTests, ShortArrayInitialLength);
  RUN_TEST_CASE(ShortArrayTests, ShortArrayInitialCapacity);
  RUN_TEST_CASE(ShortArrayTests, ShortArrayPushOneElement);
  RUN_TEST_CASE(ShortArrayTests, ShortArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(ShortIntArrayTests) {
  RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayInitialLength);
  RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayInitialCapacity);
  RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayPushOneElement);
  RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(SignedCharArrayTests) {
  RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayInitialLength);
  RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayInitialCapacity);
  RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayPushOneElement);
  RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(SignedIntArrayTests) {
  RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayInitialLength);
  RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayInitialCapacity);
  RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayPushOneElement);
  RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(SignedLongArrayTests) {
  RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayInitialLength);
  RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayInitialCapacity);
  RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayPushOneElement);
  RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(SignedLongIntArrayTests) {
  RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayInitialLength);
  RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayInitialCapacity);
  RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayPushOneElement);
  RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(SignedLongLongArrayTests) {
  RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayInitialLength);
  RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayInitialCapacity);
  RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayPushOneElement);
  RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(SignedLongLongIntArrayTests) {
  RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayInitialLength);
  RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayInitialCapacity);
  RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayPushOneElement);
  RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(SignedShortArrayTests) {
  RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayInitialLength);
  RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayInitialCapacity);
  RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayPushOneElement);
  RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(SignedShortIntArrayTests) {
  RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayInitialLength);
  RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayInitialCapacity);
  RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayPushOneElement);
  RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(StringArrayTests) {
  RUN_TEST_CASE(StringArrayTests, StringArrayInitialLength);
  RUN_TEST_CASE(StringArrayTests, StringArrayInitialCapacity);
  RUN_TEST_CASE(StringArrayTests, StringArrayPushOneElement);
  RUN_TEST_CASE(StringArrayTests, StringArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(UnsignedArrayTests) {
  RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayInitialLength);
  RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayInitialCapacity);
  RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayPushOneElement);
  RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(UnsignedIntArrayTests) {
  RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayInitialLength);
  RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayInitialCapacity);
  RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayPushOneElement);
  RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(UnsignedLongArrayTests) {
  RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayInitialLength);
  RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayInitialCapacity);
  RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayPushOneElement);
  RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(UnsignedLongIntArrayTests) {
  RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayInitialLength);
  RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayInitialCapacity);
  RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayPushOneElement);
  RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(UnsignedLongLongArrayTests) {
  RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayInitialLength);
  RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayInitialCapacity);
  RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayPushOneElement);
  RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(UnsignedLongLongIntArrayTests) {
  RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayInitialLength);
  RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayInitialCapacity);
  RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayPushOneElement);
  RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(UnsignedShortArrayTests) {
  RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayInitialLength);
  RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayInitialCapacity);
  RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayPushOneElement);
  RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayPushCapacityPlusOneElements);
}

TEST_GROUP_RUNNER(UnsignedShortIntArrayTests) {
  RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayInitialLength);
  RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayInitialCapacity);
  RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayPushOneElement);
  RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayPushCapacityPlusOneElements);
}

static void RunAllTests(void) {
  RUN_TEST_GROUP(CharArrayTests);
  RUN_TEST_GROUP(DoubleArrayTests);
  RUN_TEST_GROUP(FloatArrayTests);
  RUN_TEST_GROUP(IntArrayTests);
  RUN_TEST_GROUP(LongArrayTests);
  RUN_TEST_GROUP(LongDoubleArrayTests);
  RUN_TEST_GROUP(LongIntArrayTests);
  RUN_TEST_GROUP(LongLongArrayTests);
  RUN_TEST_GROUP(LongLongIntArrayTests);
  RUN_TEST_GROUP(ShortArrayTests);
  RUN_TEST_GROUP(ShortIntArrayTests);
  RUN_TEST_GROUP(SignedIntArrayTests);
  RUN_TEST_GROUP(SignedLongArrayTests);
  RUN_TEST_GROUP(SignedLongIntArrayTests);
  RUN_TEST_GROUP(SignedLongLongArrayTests);
  RUN_TEST_GROUP(SignedLongLongIntArrayTests);
  RUN_TEST_GROUP(SignedShortArrayTests);
  RUN_TEST_GROUP(SignedShortIntArrayTests);
  RUN_TEST_GROUP(StringArrayTests);
  RUN_TEST_GROUP(UnsignedArrayTests);
  RUN_TEST_GROUP(UnsignedIntArrayTests);
  RUN_TEST_GROUP(UnsignedLongArrayTests);
  RUN_TEST_GROUP(UnsignedLongIntArrayTests);
  RUN_TEST_GROUP(UnsignedLongLongArrayTests);
  RUN_TEST_GROUP(UnsignedLongLongIntArrayTests);
  RUN_TEST_GROUP(UnsignedShortArrayTests);
  RUN_TEST_GROUP(UnsignedShortIntArrayTests);
}

int main(int argc, char* argv[]) {
  return UnityMain(argc, argv, RunAllTests);
}
