#include <stdio.h>
#include "pointers.h"

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_array_with_pointer(int* arr, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("arr[%d] = %d\n", i, *(arr + i));
    }
}

void increment_all(int* arr, int size)
{
    for (int i = 0; i < size; ++i) {
        *(arr + i) += 1;
    }
}

int* find_max(int* arr, int size)
{
    if (size <= 0) {
        return NULL;
    }

    int* max_ptr = arr;
    for (int i = 1; i < size; ++i) {
        if (*(arr + i) > *max_ptr) {
            max_ptr = arr + i;
        }
    }
    return max_ptr;
}

void print_matrix_by_pointer(int* matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("matrix[%d][%d] = %d\n", i, j, *(matrix + i * cols + j));
        }
    }
}