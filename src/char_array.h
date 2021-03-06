#pragma once

#ifdef __GENERIC_ARRAY_TYPE__
#undef __GENERIC_ARRAY_TYPE__
#endif

#ifdef __GENERIC_ARRAY_NAME__
#undef __GENERIC_ARRAY_NAME__
#endif

#ifdef GENERIC_ARRAY_VALUES_EQUAL
#undef GENERIC_ARRAY_VALUES_EQUAL
#endif

#ifdef GENERIC_ARRAY_VALUES_NOT_EQUAL
#undef GENERIC_ARRAY_VALUES_NOT_EQUAL
#endif

#ifdef GENERIC_ARRAY_VALUES_GREATER_THAN
#undef GENERIC_ARRAY_VALUES_GREATER_THAN
#endif

#ifdef GENERIC_ARRAY_VALUES_GREATER_THAN_OR_EQUAL
#undef GENERIC_ARRAY_VALUES_GREATER_THAN_OR_EQUAL
#endif

#ifdef GENERIC_ARRAY_VALUES_LESS_THAN
#undef GENERIC_ARRAY_VALUES_LESS_THAN
#endif

#ifdef GENERIC_ARRAY_VALUES_LESS_THAN_OR_EQUAL
#undef GENERIC_ARRAY_VALUES_LESS_THAN_OR_EQUAL
#endif

#ifdef GENERIC_ARRAY_COMPARE_VALUES
#undef GENERIC_ARRAY_COMPARE_VALUES
#endif

#ifdef GENERIC_ARRAY_ELEMENT_TO_STRING_BUFFER_SIZE
#undef GENERIC_ARRAY_ELEMENT_TO_STRING_BUFFER_SIZE
#endif

#ifdef GENERIC_ARRAY_ELEMENT_TO_STRING_LENGTH
#undef GENERIC_ARRAY_ELEMENT_TO_STRING_LENGTH
#endif

#ifdef GENERIC_ARRAY_ELEMENT_TO_STRING_LAST_LENGTH
#undef GENERIC_ARRAY_ELEMENT_TO_STRING_LAST_LENGTH
#endif

#ifdef GENERIC_ARRAY_ELEMENT_TO_STRING
#undef GENERIC_ARRAY_ELEMENT_TO_STRING
#endif

#ifdef GENERIC_ARRAY_ELEMENT_TO_STRING_LAST
#undef GENERIC_ARRAY_ELEMENT_TO_STRING_LAST
#endif

#define __GENERIC_ARRAY_TYPE__ char

#define __GENERIC_ARRAY_NAME__ CharArray

#define GENERIC_ARRAY_VALUES_EQUAL(a, b) a == b

#define GENERIC_ARRAY_VALUES_NOT_EQUAL(a, b) a != b

#define GENERIC_ARRAY_VALUES_GREATER_THAN(a, b) a > b

#define GENERIC_ARRAY_VALUES_GREATER_THAN_OR_EQUAL(a, b) a >= b

#define GENERIC_ARRAY_VALUES_LESS_THAN(a, b) a < b

#define GENERIC_ARRAY_VALUES_LESS_THAN_OR_EQUAL(a, b) a <= b

#define GENERIC_ARRAY_COMPARE_VALUES(a, b) a < b ? -1 : a == b ? 0 : 1

#define GENERIC_ARRAY_ELEMENT_TO_STRING_BUFFER_SIZE(element) 32

#define GENERIC_ARRAY_ELEMENT_TO_STRING_LENGTH(buffer, bufferSize, element) snprintf(buffer, bufferSize, "'%c', ", element)

#define GENERIC_ARRAY_ELEMENT_TO_STRING_LAST_LENGTH(buffer, bufferSize, element) snprintf(buffer, bufferSize, "'%c'", element)

#define GENERIC_ARRAY_ELEMENT_TO_STRING(buffer, bufferSize, element) snprintf(buffer, bufferSize, "'%c', ", element)

#define GENERIC_ARRAY_ELEMENT_TO_STRING_LAST(buffer, bufferSize, element) snprintf(buffer, bufferSize, "'%c'", element)

#include "generic_array.h"
