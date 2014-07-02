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
    RUN_TEST_CASE(CharArrayTests, CharArrayDeleteAtZeroLength);
    RUN_TEST_CASE(CharArrayTests, CharArrayDeleteAtExistingElement);
    RUN_TEST_CASE(CharArrayTests, CharArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(CharArrayTests, CharArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(CharArrayTests, CharArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(CharArrayTests, CharArrayDropOneEmptyArray);
    RUN_TEST_CASE(CharArrayTests, CharArrayDropManyEmptyArray);
    RUN_TEST_CASE(CharArrayTests, CharArrayDropLessThanArrayLength);
    RUN_TEST_CASE(CharArrayTests, CharArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(DoubleArrayTests) {
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayInitialLength);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayInitialCapacity);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayPushOneElement);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayAtZeroLength);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayAtExistingElement);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayClear);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayConcatEmptyArrays);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayCountEmptyArray);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayCountNonEmptyArray);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayDeleteNonExistingElement);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayDeleteExistingElement);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayDeleteAtZeroLength);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayDeleteAtExistingElement);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayDropOneEmptyArray);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayDropManyEmptyArray);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayDropLessThanArrayLength);
    RUN_TEST_CASE(DoubleArrayTests, DoubleArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(FloatArrayTests) {
    RUN_TEST_CASE(FloatArrayTests, FloatArrayInitialLength);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayInitialCapacity);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayPushOneElement);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayAtZeroLength);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayAtExistingElement);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayClear);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayConcatEmptyArrays);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayCountEmptyArray);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayCountNonEmptyArray);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayDeleteNonExistingElement);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayDeleteExistingElement);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayDeleteAtZeroLength);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayDeleteAtExistingElement);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayDropOneEmptyArray);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayDropManyEmptyArray);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayDropLessThanArrayLength);
    RUN_TEST_CASE(FloatArrayTests, FloatArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(IntArrayTests) {
    RUN_TEST_CASE(IntArrayTests, IntArrayInitialLength);
    RUN_TEST_CASE(IntArrayTests, IntArrayInitialCapacity);
    RUN_TEST_CASE(IntArrayTests, IntArrayPushOneElement);
    RUN_TEST_CASE(IntArrayTests, IntArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(IntArrayTests, IntArrayAtZeroLength);
    RUN_TEST_CASE(IntArrayTests, IntArrayAtExistingElement);
    RUN_TEST_CASE(IntArrayTests, IntArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(IntArrayTests, IntArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(IntArrayTests, IntArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(IntArrayTests, IntArrayClear);
    RUN_TEST_CASE(IntArrayTests, IntArrayConcatEmptyArrays);
    RUN_TEST_CASE(IntArrayTests, IntArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(IntArrayTests, IntArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(IntArrayTests, IntArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(IntArrayTests, IntArrayCountEmptyArray);
    RUN_TEST_CASE(IntArrayTests, IntArrayCountNonEmptyArray);
    RUN_TEST_CASE(IntArrayTests, IntArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(IntArrayTests, IntArrayDeleteNonExistingElement);
    RUN_TEST_CASE(IntArrayTests, IntArrayDeleteExistingElement);
    RUN_TEST_CASE(IntArrayTests, IntArrayDeleteAtZeroLength);
    RUN_TEST_CASE(IntArrayTests, IntArrayDeleteAtExistingElement);
    RUN_TEST_CASE(IntArrayTests, IntArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(IntArrayTests, IntArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(IntArrayTests, IntArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(IntArrayTests, IntArrayDropOneEmptyArray);
    RUN_TEST_CASE(IntArrayTests, IntArrayDropManyEmptyArray);
    RUN_TEST_CASE(IntArrayTests, IntArrayDropLessThanArrayLength);
    RUN_TEST_CASE(IntArrayTests, IntArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(LongArrayTests) {
    RUN_TEST_CASE(LongArrayTests, LongArrayInitialLength);
    RUN_TEST_CASE(LongArrayTests, LongArrayInitialCapacity);
    RUN_TEST_CASE(LongArrayTests, LongArrayPushOneElement);
    RUN_TEST_CASE(LongArrayTests, LongArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(LongArrayTests, LongArrayAtZeroLength);
    RUN_TEST_CASE(LongArrayTests, LongArrayAtExistingElement);
    RUN_TEST_CASE(LongArrayTests, LongArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(LongArrayTests, LongArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(LongArrayTests, LongArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(LongArrayTests, LongArrayClear);
    RUN_TEST_CASE(LongArrayTests, LongArrayConcatEmptyArrays);
    RUN_TEST_CASE(LongArrayTests, LongArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(LongArrayTests, LongArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(LongArrayTests, LongArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(LongArrayTests, LongArrayCountEmptyArray);
    RUN_TEST_CASE(LongArrayTests, LongArrayCountNonEmptyArray);
    RUN_TEST_CASE(LongArrayTests, LongArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(LongArrayTests, LongArrayDeleteNonExistingElement);
    RUN_TEST_CASE(LongArrayTests, LongArrayDeleteExistingElement);
    RUN_TEST_CASE(LongArrayTests, LongArrayDeleteAtZeroLength);
    RUN_TEST_CASE(LongArrayTests, LongArrayDeleteAtExistingElement);
    RUN_TEST_CASE(LongArrayTests, LongArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(LongArrayTests, LongArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(LongArrayTests, LongArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(LongArrayTests, LongArrayDropOneEmptyArray);
    RUN_TEST_CASE(LongArrayTests, LongArrayDropManyEmptyArray);
    RUN_TEST_CASE(LongArrayTests, LongArrayDropLessThanArrayLength);
    RUN_TEST_CASE(LongArrayTests, LongArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(LongDoubleArrayTests) {
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayInitialLength);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayInitialCapacity);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayPushOneElement);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayAtZeroLength);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayAtExistingElement);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayClear);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayConcatEmptyArrays);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayCountEmptyArray);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayCountNonEmptyArray);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayDeleteNonExistingElement);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayDeleteExistingElement);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayDeleteAtZeroLength);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayDeleteAtExistingElement);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayDropOneEmptyArray);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayDropManyEmptyArray);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayDropLessThanArrayLength);
    RUN_TEST_CASE(LongDoubleArrayTests, LongDoubleArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(LongIntArrayTests) {
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayInitialLength);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayInitialCapacity);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayPushOneElement);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayAtZeroLength);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayAtExistingElement);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayClear);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayConcatEmptyArrays);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayCountEmptyArray);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayCountNonEmptyArray);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayDeleteNonExistingElement);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayDeleteExistingElement);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayDeleteAtZeroLength);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayDeleteAtExistingElement);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayDropOneEmptyArray);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayDropManyEmptyArray);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayDropLessThanArrayLength);
    RUN_TEST_CASE(LongIntArrayTests, LongIntArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(LongLongArrayTests) {
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayInitialLength);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayInitialCapacity);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayPushOneElement);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayAtZeroLength);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayAtExistingElement);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayClear);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayConcatEmptyArrays);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayCountEmptyArray);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayCountNonEmptyArray);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayDeleteNonExistingElement);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayDeleteExistingElement);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayDeleteAtZeroLength);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayDeleteAtExistingElement);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayDropOneEmptyArray);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayDropManyEmptyArray);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayDropLessThanArrayLength);
    RUN_TEST_CASE(LongLongArrayTests, LongLongArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(LongLongIntArrayTests) {
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayInitialLength);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayInitialCapacity);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayPushOneElement);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayAtZeroLength);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayAtExistingElement);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayClear);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayConcatEmptyArrays);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayCountEmptyArray);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayCountNonEmptyArray);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayDeleteNonExistingElement);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayDeleteExistingElement);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayDeleteAtZeroLength);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayDeleteAtExistingElement);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayDropOneEmptyArray);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayDropManyEmptyArray);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayDropLessThanArrayLength);
    RUN_TEST_CASE(LongLongIntArrayTests, LongLongIntArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(ShortArrayTests) {
    RUN_TEST_CASE(ShortArrayTests, ShortArrayInitialLength);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayInitialCapacity);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayPushOneElement);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayAtZeroLength);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayAtExistingElement);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayClear);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayConcatEmptyArrays);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayCountEmptyArray);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayCountNonEmptyArray);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayDeleteNonExistingElement);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayDeleteExistingElement);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayDeleteAtZeroLength);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayDeleteAtExistingElement);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayDropOneEmptyArray);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayDropManyEmptyArray);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayDropLessThanArrayLength);
    RUN_TEST_CASE(ShortArrayTests, ShortArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(ShortIntArrayTests) {
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayInitialLength);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayInitialCapacity);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayPushOneElement);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayAtZeroLength);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayAtExistingElement);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayClear);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayConcatEmptyArrays);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayCountEmptyArray);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayCountNonEmptyArray);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayDeleteNonExistingElement);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayDeleteExistingElement);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayDeleteAtZeroLength);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayDeleteAtExistingElement);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayDropOneEmptyArray);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayDropManyEmptyArray);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayDropLessThanArrayLength);
    RUN_TEST_CASE(ShortIntArrayTests, ShortIntArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(SignedCharArrayTests) {
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayInitialLength);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayInitialCapacity);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayPushOneElement);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayAtZeroLength);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayAtExistingElement);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayClear);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayConcatEmptyArrays);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayCountEmptyArray);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayCountNonEmptyArray);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayDeleteNonExistingElement);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayDeleteExistingElement);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayDeleteAtZeroLength);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayDeleteAtExistingElement);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayDropOneEmptyArray);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayDropManyEmptyArray);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayDropLessThanArrayLength);
    RUN_TEST_CASE(SignedCharArrayTests, SignedCharArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(SignedIntArrayTests) {
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayInitialLength);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayInitialCapacity);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayPushOneElement);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayAtZeroLength);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayAtExistingElement);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayClear);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayConcatEmptyArrays);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayCountEmptyArray);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayCountNonEmptyArray);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayDeleteNonExistingElement);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayDeleteExistingElement);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayDeleteAtZeroLength);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayDeleteAtExistingElement);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayDropOneEmptyArray);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayDropManyEmptyArray);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayDropLessThanArrayLength);
    RUN_TEST_CASE(SignedIntArrayTests, SignedIntArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(SignedLongArrayTests) {
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayInitialLength);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayInitialCapacity);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayPushOneElement);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayAtZeroLength);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayAtExistingElement);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayClear);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayConcatEmptyArrays);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayCountEmptyArray);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayCountNonEmptyArray);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayDeleteNonExistingElement);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayDeleteExistingElement);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayDeleteAtZeroLength);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayDeleteAtExistingElement);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayDropOneEmptyArray);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayDropManyEmptyArray);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayDropLessThanArrayLength);
    RUN_TEST_CASE(SignedLongArrayTests, SignedLongArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(SignedLongIntArrayTests) {
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayInitialLength);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayInitialCapacity);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayPushOneElement);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayAtZeroLength);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayAtExistingElement);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayClear);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayConcatEmptyArrays);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayCountEmptyArray);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayCountNonEmptyArray);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayDeleteNonExistingElement);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayDeleteExistingElement);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayDeleteAtZeroLength);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayDeleteAtExistingElement);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayDropOneEmptyArray);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayDropManyEmptyArray);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayDropLessThanArrayLength);
    RUN_TEST_CASE(SignedLongIntArrayTests, SignedLongIntArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(SignedLongLongArrayTests) {
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayInitialLength);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayInitialCapacity);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayPushOneElement);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayAtZeroLength);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayAtExistingElement);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayClear);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayConcatEmptyArrays);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayCountEmptyArray);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayCountNonEmptyArray);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayDeleteNonExistingElement);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayDeleteExistingElement);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayDeleteAtZeroLength);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayDeleteAtExistingElement);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayDropOneEmptyArray);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayDropManyEmptyArray);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayDropLessThanArrayLength);
    RUN_TEST_CASE(SignedLongLongArrayTests, SignedLongLongArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(SignedLongLongIntArrayTests) {
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayInitialLength);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayInitialCapacity);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayPushOneElement);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayAtZeroLength);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayAtExistingElement);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayClear);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayConcatEmptyArrays);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayCountEmptyArray);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayCountNonEmptyArray);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteNonExistingElement);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteExistingElement);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteAtZeroLength);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteAtExistingElement);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayDropOneEmptyArray);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayDropManyEmptyArray);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayDropLessThanArrayLength);
    RUN_TEST_CASE(SignedLongLongIntArrayTests, SignedLongLongIntArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(SignedShortArrayTests) {
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayInitialLength);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayInitialCapacity);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayPushOneElement);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayAtZeroLength);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayAtExistingElement);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayClear);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayConcatEmptyArrays);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayCountEmptyArray);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayCountNonEmptyArray);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayDeleteNonExistingElement);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayDeleteExistingElement);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayDeleteAtZeroLength);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayDeleteAtExistingElement);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayDropOneEmptyArray);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayDropManyEmptyArray);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayDropLessThanArrayLength);
    RUN_TEST_CASE(SignedShortArrayTests, SignedShortArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(SignedShortIntArrayTests) {
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayInitialLength);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayInitialCapacity);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayPushOneElement);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayAtZeroLength);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayAtExistingElement);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayClear);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayConcatEmptyArrays);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayCountEmptyArray);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayCountNonEmptyArray);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayDeleteNonExistingElement);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayDeleteExistingElement);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayDeleteAtZeroLength);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayDeleteAtExistingElement);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayDropOneEmptyArray);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayDropManyEmptyArray);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayDropLessThanArrayLength);
    RUN_TEST_CASE(SignedShortIntArrayTests, SignedShortIntArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(StringArrayTests) {
    RUN_TEST_CASE(StringArrayTests, StringArrayInitialLength);
    RUN_TEST_CASE(StringArrayTests, StringArrayInitialCapacity);
    RUN_TEST_CASE(StringArrayTests, StringArrayPushOneElement);
    RUN_TEST_CASE(StringArrayTests, StringArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(StringArrayTests, StringArrayAtZeroLength);
    RUN_TEST_CASE(StringArrayTests, StringArrayAtExistingElement);
    RUN_TEST_CASE(StringArrayTests, StringArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(StringArrayTests, StringArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(StringArrayTests, StringArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(StringArrayTests, StringArrayClear);
    RUN_TEST_CASE(StringArrayTests, StringArrayConcatEmptyArrays);
    RUN_TEST_CASE(StringArrayTests, StringArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(StringArrayTests, StringArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(StringArrayTests, StringArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(StringArrayTests, StringArrayCountEmptyArray);
    RUN_TEST_CASE(StringArrayTests, StringArrayCountNonEmptyArray);
    RUN_TEST_CASE(StringArrayTests, StringArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(StringArrayTests, StringArrayDeleteNonExistingElement);
    RUN_TEST_CASE(StringArrayTests, StringArrayDeleteExistingElement);
    RUN_TEST_CASE(StringArrayTests, StringArrayDeleteAtZeroLength);
    RUN_TEST_CASE(StringArrayTests, StringArrayDeleteAtExistingElement);
    RUN_TEST_CASE(StringArrayTests, StringArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(StringArrayTests, StringArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(StringArrayTests, StringArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(StringArrayTests, StringArrayDropOneEmptyArray);
    RUN_TEST_CASE(StringArrayTests, StringArrayDropManyEmptyArray);
    RUN_TEST_CASE(StringArrayTests, StringArrayDropLessThanArrayLength);
    RUN_TEST_CASE(StringArrayTests, StringArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(UnsignedArrayTests) {
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayInitialLength);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayInitialCapacity);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayPushOneElement);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayAtZeroLength);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayAtExistingElement);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayClear);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayConcatEmptyArrays);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayCountEmptyArray);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayCountNonEmptyArray);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayDeleteNonExistingElement);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayDeleteExistingElement);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayDeleteAtZeroLength);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayDeleteAtExistingElement);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayDropOneEmptyArray);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayDropManyEmptyArray);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayDropLessThanArrayLength);
    RUN_TEST_CASE(UnsignedArrayTests, UnsignedArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(UnsignedCharArrayTests) {
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayInitialLength);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayInitialCapacity);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayPushOneElement);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayAtZeroLength);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayAtExistingElement);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayClear);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayConcatEmptyArrays);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayCountEmptyArray);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayCountNonEmptyArray);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayDeleteNonExistingElement);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayDeleteExistingElement);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayDeleteAtZeroLength);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayDeleteAtExistingElement);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayDropOneEmptyArray);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayDropManyEmptyArray);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayDropLessThanArrayLength);
    RUN_TEST_CASE(UnsignedCharArrayTests, UnsignedCharArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(UnsignedIntArrayTests) {
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayInitialLength);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayInitialCapacity);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayPushOneElement);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayAtZeroLength);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayAtExistingElement);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayClear);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayConcatEmptyArrays);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayCountEmptyArray);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayCountNonEmptyArray);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayDeleteNonExistingElement);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayDeleteExistingElement);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayDeleteAtZeroLength);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayDeleteAtExistingElement);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayDropOneEmptyArray);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayDropManyEmptyArray);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayDropLessThanArrayLength);
    RUN_TEST_CASE(UnsignedIntArrayTests, UnsignedIntArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(UnsignedLongArrayTests) {
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayInitialLength);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayInitialCapacity);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayPushOneElement);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayAtZeroLength);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayAtExistingElement);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayClear);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayConcatEmptyArrays);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayCountEmptyArray);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayCountNonEmptyArray);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayDeleteNonExistingElement);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayDeleteExistingElement);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayDeleteAtZeroLength);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayDeleteAtExistingElement);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayDropOneEmptyArray);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayDropManyEmptyArray);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayDropLessThanArrayLength);
    RUN_TEST_CASE(UnsignedLongArrayTests, UnsignedLongArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(UnsignedLongIntArrayTests) {
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayInitialLength);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayInitialCapacity);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayPushOneElement);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayAtZeroLength);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayAtExistingElement);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayClear);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayConcatEmptyArrays);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayCountEmptyArray);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayCountNonEmptyArray);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteNonExistingElement);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteExistingElement);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteAtZeroLength);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteAtExistingElement);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayDropOneEmptyArray);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayDropManyEmptyArray);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayDropLessThanArrayLength);
    RUN_TEST_CASE(UnsignedLongIntArrayTests, UnsignedLongIntArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(UnsignedLongLongArrayTests) {
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayInitialLength);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayInitialCapacity);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayPushOneElement);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayAtZeroLength);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayAtExistingElement);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayClear);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayConcatEmptyArrays);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayCountEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayCountNonEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteNonExistingElement);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteExistingElement);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteAtZeroLength);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteAtExistingElement);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayDropOneEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayDropManyEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayDropLessThanArrayLength);
    RUN_TEST_CASE(UnsignedLongLongArrayTests, UnsignedLongLongArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(UnsignedLongLongIntArrayTests) {
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayInitialLength);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayInitialCapacity);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayPushOneElement);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayAtZeroLength);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayAtExistingElement);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayClear);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayConcatEmptyArrays);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayCountEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayCountNonEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteNonExistingElement);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteExistingElement);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteAtZeroLength);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteAtExistingElement);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDropOneEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDropManyEmptyArray);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDropLessThanArrayLength);
    RUN_TEST_CASE(UnsignedLongLongIntArrayTests, UnsignedLongLongIntArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(UnsignedShortArrayTests) {
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayInitialLength);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayInitialCapacity);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayPushOneElement);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayAtZeroLength);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayAtExistingElement);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayClear);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayConcatEmptyArrays);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayCountEmptyArray);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayCountNonEmptyArray);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayDeleteNonExistingElement);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayDeleteExistingElement);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayDeleteAtZeroLength);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayDeleteAtExistingElement);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayDropOneEmptyArray);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayDropManyEmptyArray);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayDropLessThanArrayLength);
    RUN_TEST_CASE(UnsignedShortArrayTests, UnsignedShortArrayDropGreaterThanArrayLength);
}

TEST_GROUP_RUNNER(UnsignedShortIntArrayTests) {
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayInitialLength);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayInitialCapacity);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayPushOneElement);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayPushCapacityPlusOneElements);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayAtZeroLength);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayAtExistingElement);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayClear);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayConcatEmptyArrays);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayConcatEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayConcatNonEmptyArrayToEmptyArray);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayConcatNonEmptyArrayToNonEmptyArray);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayCountEmptyArray);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayCountNonEmptyArray);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteFromEmptyArray);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteNonExistingElement);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteExistingElement);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteAtZeroLength);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteAtExistingElement);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteAtLessThanZeroIndex);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteAtGreaterThanLengthIndex);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayDeleteAtLessThanNegativeLengthIndex);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayDropOneEmptyArray);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayDropManyEmptyArray);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayDropLessThanArrayLength);
    RUN_TEST_CASE(UnsignedShortIntArrayTests, UnsignedShortIntArrayDropGreaterThanArrayLength);
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
    RUN_TEST_GROUP(SignedCharArrayTests);
    RUN_TEST_GROUP(SignedIntArrayTests);
    RUN_TEST_GROUP(SignedLongArrayTests);
    RUN_TEST_GROUP(SignedLongIntArrayTests);
    RUN_TEST_GROUP(SignedLongLongArrayTests);
    RUN_TEST_GROUP(SignedLongLongIntArrayTests);
    RUN_TEST_GROUP(SignedShortArrayTests);
    RUN_TEST_GROUP(SignedShortIntArrayTests);
    RUN_TEST_GROUP(StringArrayTests);
    RUN_TEST_GROUP(UnsignedArrayTests);
    RUN_TEST_GROUP(UnsignedCharArrayTests);
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
