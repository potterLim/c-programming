#include <stdio.h>

#include "array.h"

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

float get_average(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / (float)size;
}

void fill_with_zero(int arr[], int size)
{
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}

void print_matrix(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
        }
    }
}
