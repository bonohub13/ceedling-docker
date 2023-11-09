#include <unity.h>

#include "add.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_add_int32__normal(void) {
    int32_t numbers[2] = {169, 169 * 13};
    int32_t ret;

    ret = add_int32(numbers, 2);

    TEST_ASSERT_EQUAL_INT(2366, ret);
}

void test_add_int32__overflow(void) {
    int32_t numbers[2] = {0xFFFFFFFF, 0xF};
    int32_t ret;

    ret = add_int32(numbers, 2);

    TEST_ASSERT_EQUAL_INT(0xE, ret);
}
