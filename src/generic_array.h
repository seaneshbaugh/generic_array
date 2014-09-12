#include "generic.h"

typedef struct {
    __GENERIC_ARRAY_TYPE__ *values;
    size_t capacity;
    size_t length;
} __GENERIC_ARRAY_NAME__;

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Initialize, __GENERIC_ARRAY_NAME__ *array);
MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, InitializeFromPointer, __GENERIC_ARRAY_NAME__ *array, __GENERIC_ARRAY_TYPE__ *values, size_t length);
MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Deinitialize, __GENERIC_ARRAY_NAME__ *array);
MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, At, __GENERIC_ARRAY_NAME__ *array, ssize_t index, __GENERIC_ARRAY_TYPE__ *result);
MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Clear, __GENERIC_ARRAY_NAME__ *array);
MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Concat, __GENERIC_ARRAY_NAME__ *array, __GENERIC_ARRAY_NAME__ *otherArray);
MAKE_FUNCTION(size_t, __GENERIC_ARRAY_NAME__, Count, __GENERIC_ARRAY_NAME__ *array);
MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Delete, __GENERIC_ARRAY_NAME__ *array, __GENERIC_ARRAY_TYPE__ value);
MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, DeleteAt, __GENERIC_ARRAY_NAME__ *array, ssize_t index);
MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Drop, __GENERIC_ARRAY_NAME__ *array, size_t n);
MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Find, __GENERIC_ARRAY_NAME__ *array, __GENERIC_ARRAY_TYPE__ value, ssize_t *result);
MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, IsEmpty, __GENERIC_ARRAY_NAME__ *array);
MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Overlap, __GENERIC_ARRAY_NAME__ *array, __GENERIC_ARRAY_NAME__ *otherArray);
MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Set, __GENERIC_ARRAY_NAME__ *array, ssize_t index, __GENERIC_ARRAY_TYPE__ value);
MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, ToString, __GENERIC_ARRAY_NAME__ *array, char **result);
MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Push, __GENERIC_ARRAY_NAME__ *array, __GENERIC_ARRAY_TYPE__ value);
MAKE_FUNCTION(void, __GENERIC_ARRAY_NAME__, Sort, __GENERIC_ARRAY_NAME__ *array, int (*comparisonFunction)(const void*, const void*));

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Initialize, __GENERIC_ARRAY_NAME__ *array) {
    array->values = calloc(GA_INITIAL_CAPACITY, sizeof(__GENERIC_ARRAY_TYPE__));

    array->length = 0;

    if (array->values) {
        array->capacity = GA_INITIAL_CAPACITY;

        return GA_SUCCESS;
    } else {
        array->capacity = 0;

        return GA_ERROR_ALLOC_FAILED;
    }
}

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, InitializeFromPointer, __GENERIC_ARRAY_NAME__ *array, __GENERIC_ARRAY_TYPE__ *values, size_t length) {
    int result = CALL_FUNCTION(__GENERIC_ARRAY_NAME__, Initialize, array);

    if (result != GA_SUCCESS) {
        return result;
    }

    for (size_t i = 0; i < length; i++) {
        result = CALL_FUNCTION(__GENERIC_ARRAY_NAME__, Push, array, values[i]);

        if (result != GA_SUCCESS) {
            return result;
        }
    }

    return GA_SUCCESS;
}

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Deinitialize, __GENERIC_ARRAY_NAME__ *array) {
    free(array->values);

    array->values = 0;

    array->capacity = 0;

    array->length = 0;

    return GA_SUCCESS;
}

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, At, __GENERIC_ARRAY_NAME__ *array, ssize_t index, __GENERIC_ARRAY_TYPE__ *result) {
    if (array->length == 0) {
        return GA_ERROR_INDEX_OUT_OF_BOUNDS;
    }

    if (index < 0) {
        index += array->length;
    }

    if (index < 0 || index >= array->length) {
        return GA_ERROR_INDEX_OUT_OF_BOUNDS;
    }

    *result = array->values[index];

    return GA_SUCCESS;
}

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Clear, __GENERIC_ARRAY_NAME__ *array) {
    array->length = 0;

    memset(array->values, 0, array->capacity);

    return GA_SUCCESS;
}

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Concat, __GENERIC_ARRAY_NAME__ *array, __GENERIC_ARRAY_NAME__ *otherArray) {
    if (array->length + otherArray->length > array->capacity) {
        size_t newCapacity = nextPowerOf2(array->capacity);

        array->values = realloc(array->values, sizeof(__GENERIC_ARRAY_TYPE__) * newCapacity);

        if (array->values) {
            array->capacity = newCapacity;
        } else {
            return GA_ERROR_REALLOC_FAILED;
        }
    }

    memcpy(array->values + array->length, otherArray->values, sizeof(__GENERIC_ARRAY_TYPE__) * otherArray->length);

    array->length += otherArray->length;

    return GA_SUCCESS;
}

MAKE_FUNCTION(size_t, __GENERIC_ARRAY_NAME__, Count, __GENERIC_ARRAY_NAME__ *array) {
    return array->length;
}

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Delete, __GENERIC_ARRAY_NAME__ *array, __GENERIC_ARRAY_TYPE__ value) {
    int i1, i2;

    for (i1 = i2 = 0; i1 < array->length; i1++) {
        if (GENERIC_ARRAY_VALUES_EQUAL(array->values[i1], value)) {
            continue;
        }

        if (i1 != i2) {
            array->values[i2] = array->values[i1];
        }

        i2++;
    }

    if (i2 < array->length) {
        memset(array->values + (i2 * sizeof(__GENERIC_ARRAY_TYPE__)), 0, (array->capacity - i2 - sizeof(__GENERIC_ARRAY_TYPE__)) * sizeof(__GENERIC_ARRAY_TYPE__));

        array->length = i2;
    }

    return GA_SUCCESS;
}

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, DeleteAt, __GENERIC_ARRAY_NAME__ *array, ssize_t index) {
    if (array->length == 0) {
        return GA_ERROR_INDEX_OUT_OF_BOUNDS;
    }

    if (index < 0) {
        index += array->length;
    }

    if (index < 0 || index >= array->length) {
        return GA_ERROR_INDEX_OUT_OF_BOUNDS;
    }

    memmove(array->values + index, array->values + index + 1, (array->length - index - 1) * sizeof(__GENERIC_ARRAY_TYPE__));

    memset(array->values + array->length - 1, 0, sizeof(__GENERIC_ARRAY_TYPE__));

    array->length--;

    return GA_SUCCESS;
}

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Drop, __GENERIC_ARRAY_NAME__ *array, size_t n) {
    if (n > array->length) {
        n = array->length;
    }

    if (n > 0) {
        memmove(array->values, array->values + n, (array->length - n) * sizeof(__GENERIC_ARRAY_TYPE__));

        memset(array->values + array->length - n, 0, sizeof(__GENERIC_ARRAY_TYPE__));

        array->length -= n;
    }

    return GA_SUCCESS;
}

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Find, __GENERIC_ARRAY_NAME__ *array, __GENERIC_ARRAY_TYPE__ value, ssize_t *result) {
    for (ssize_t i = 0; i < array->length; i++) {
        if (GENERIC_ARRAY_VALUES_EQUAL(array->values[i], value)) {
            *result = i;

            return GA_SUCCESS;
        }
    }

    *result = -1;

    return GA_SUCCESS;
}

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, IsEmpty, __GENERIC_ARRAY_NAME__ *array) {
    return array->length == 0;
}

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Overlap, __GENERIC_ARRAY_NAME__ *array, __GENERIC_ARRAY_NAME__ *otherArray) {
    for (ssize_t i = 0; i < otherArray->length; i++) {
        ssize_t index;

        int result = CALL_FUNCTION(__GENERIC_ARRAY_NAME__, Find, array, otherArray->values[i], &index);

        if (result != GA_SUCCESS) {
            return result;
        }

        if (index != -1) {
            CALL_FUNCTION(__GENERIC_ARRAY_NAME__, DeleteAt, array, index);
        }
    }

    CALL_FUNCTION(__GENERIC_ARRAY_NAME__, Concat, array, otherArray);

    return GA_SUCCESS;
}

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Push, __GENERIC_ARRAY_NAME__ *array, __GENERIC_ARRAY_TYPE__ value) {
    if (array->length + 1 > array->capacity) {
        array->values = realloc(array->values, sizeof(__GENERIC_ARRAY_TYPE__) * array->capacity * 2);

        if (array->values) {
            array->capacity *= GA_CAPACITY_MULTIPLIER;
        } else {
            return GA_ERROR_REALLOC_FAILED;
        }
    }

    array->values[array->length] = value;

    array->length += 1;

    return GA_SUCCESS;
}

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Set, __GENERIC_ARRAY_NAME__ *array, ssize_t index, __GENERIC_ARRAY_TYPE__ value) {
    if (array->length == 0) {
        return GA_ERROR_INDEX_OUT_OF_BOUNDS;
    }

    if (index < 0) {
        index += array->length;
    }

    if (index < 0 || index >= array->length) {
        return GA_ERROR_INDEX_OUT_OF_BOUNDS;
    }

    array->values[index] = value;

    return GA_SUCCESS;
}

MAKE_FUNCTION(void, __GENERIC_ARRAY_NAME__, Sort, __GENERIC_ARRAY_NAME__ *array, int (*comparisonFunction)(const void*, const void*)) {
    qsort(array->values, array->length, sizeof(__GENERIC_ARRAY_TYPE__), comparisonFunction);
}

MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, ToString, __GENERIC_ARRAY_NAME__ *array, char **result) {
    int i;

    int elementLength;

    int stringLength = 3;

    for (i = 0; i < array->length; i++) {
        int bufferSize = GENERIC_ARRAY_ELEMENT_TO_STRING_BUFFER_SIZE(array->values[i]);

        char *buffer = calloc(bufferSize, sizeof(char));

        if (i < array->length - 1) {
            elementLength = GENERIC_ARRAY_ELEMENT_TO_STRING_LENGTH(buffer, bufferSize, array->values[i]);
        } else {
            elementLength = GENERIC_ARRAY_ELEMENT_TO_STRING_LAST_LENGTH(buffer, bufferSize, array->values[i]);
        }

        stringLength += elementLength;

        free(buffer);
    }

    *result = calloc(stringLength, sizeof(char));

    char *p = *result;

    *p = '[';

    p++;

    for (i = 0; i < array->length; i++) {
        int bufferSize = GENERIC_ARRAY_ELEMENT_TO_STRING_BUFFER_SIZE(array->values[i]);

        char *buffer = calloc(bufferSize, sizeof(char));

        if (i < array->length - 1) {
            elementLength = GENERIC_ARRAY_ELEMENT_TO_STRING(p, bufferSize, array->values[i]);
        } else {
            elementLength = GENERIC_ARRAY_ELEMENT_TO_STRING_LAST(p, bufferSize, array->values[i]);
        }

        p += elementLength;

        free(buffer);
    }

    *p = ']';

    p++;

    *p = '\0';

    return GA_SUCCESS;
}

// MAKE_FUNCTION(int, __GENERIC_ARRAY_NAME__, Debug, __GENERIC_ARRAY_NAME__ *array) {
//     printf("Capacity: %lu\n", array->capacity);
//
//     printf("Length: %lu\n", array->length);
//
//     printf("Values: [");
//
//     unsigned char *p;
//
//     for (int i = 0; i < array->capacity; i++) {
//         p = (unsigned char*)&array->values[i];
//
//         for (int j = 0; j < sizeof(__GENERIC_ARRAY_TYPE__); j++) {
//             printf("%02x", *p);
//
//             p++;
//         }
//
//         if (i < array->capacity - 1) {
//             printf(", ");
//         } else {
//             printf("]\n");
//         }
//     }
//
//     return GA_SUCCESS;
// }
