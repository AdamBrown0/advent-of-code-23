#include <stdio.h>
#include <stdlib.h>
#include "array_helper.h"

void print_array(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int *copy_array(int *arr, int size) {
    int *copy = (int *) calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        copy[i] = arr[i];
    }
    return copy;
}