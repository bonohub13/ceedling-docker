#include <stdio.h>

#include "add.h"

int main(void) {
    int32_t numbers[10] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};

    printf("%d\n", add_int32(numbers, 10));

    return 0;
}
