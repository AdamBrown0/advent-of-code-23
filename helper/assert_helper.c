#include <stdio.h>
#include <stdlib.h>
#include "assert_helper.h"

void assert_equal_int(int expected, int actual) {
    if (actual != expected) {
        fprintf(stderr, "Assertion Error: %s\n", __func__);
        fprintf(stderr, "Expected: %d, Actual: %d\n", expected, actual);
        exit(EXIT_FAILURE);
    }
}