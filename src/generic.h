#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASTE(a, b) a##b
#define MAKE_FUNCTION(return_type, prefix, name, ...) return_type PASTE(prefix, name) (__VA_ARGS__)
#define CALL_FUNCTION(prefix, name, ...) PASTE(prefix, name)(__VA_ARGS__)

#define GA_SUCCESS                              0
#define GA_ERROR_NOT_INITIALIZED                1
#define GA_ERROR_ALLOC_FAILED                   2
#define GA_ERROR_FREE_FAILED                    3
#define GA_ERROR_REALLOC_FAILED                 4
#define GA_ERROR_INDEX_OUT_OF_BOUNDS            5

#define GA_INITIAL_CAPACITY 1024

#define GA_CAPACITY_MULTIPLIER 2

/*
** http://stackoverflow.com/a/20236171/329602
** http://graphics.stanford.edu/~seander/bithacks.html#IntegerLog
*/
#define __LOG2A(s) ((s &0xffffffff00000000) ? (32 + __LOG2B(s >> 32)) : (__LOG2B(s)))
#define __LOG2B(s) ((s &0xffff0000)         ? (16 + __LOG2C(s >> 16)) : (__LOG2C(s)))
#define __LOG2C(s) ((s &0xff00)             ? (8  + __LOG2D(s >> 8))  : (__LOG2D(s)))
#define __LOG2D(s) ((s &0xf0)               ? (4  + __LOG2E(s >> 4))  : (__LOG2E(s)))
#define __LOG2E(s) ((s &0xc)                ? (2  + __LOG2F(s >> 2))  : (__LOG2F(s)))
#define __LOG2F(s) ((s &0x2)                ? (1)                     : (0))

#define LOG2_UINT64 __LOG2A
#define LOG2_UINT32 __LOG2B
#define LOG2_UINT16 __LOG2C
#define LOG2_UINT8  __LOG2D

static inline uint64_t nextPowerOf2(uint64_t i) {
#if defined(__GNUC__)
    return 1UL << (1 + (63 - __builtin_clzl(i - 1)));
#else
    i = i - 1;

    i = LOG2_UINT64(i);

    return 1UL << (1 + i);
#endif
}
