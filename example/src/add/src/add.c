#include "add.h"

#include <stdio.h>

int32_t add_int32(int32_t numbers[], size_t size) {
    int32_t ret = 0;
    size_t idx;

    for(idx=0; idx<size; idx++) {
        ret += numbers[idx];
    }

    return ret;
}
