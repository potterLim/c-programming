/*
 * Example code from: 10-pointers
 * Purpose          : Demonstrates various usages of pointers
 */

#include <stdio.h>
#include "pointers.h"

int main(void)
{
    int a = 5;
    int* p = &a;

    printf("[Basic Pointer Usage]\n");
    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n", (void*)&a);
    printf("p points to address: %p\n", (void*)p);
    printf("Value pointed by p: %d\n", *p);
    *p = 10;
    printf("New value of a (via *p): %d\n\n", a);

    int x = 3, y = 9;
    printf("[Before Swap] x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("[After Swap] x = %d, y = %d\n\n", x, y);

    int numbers[] = {1, 2, 3, 4, 5};
    printf("[Array Traversal Using Pointer]\n");
    print_array_with_pointer(numbers, 5);
    printf("\n");

    printf("[Increment All Elements Using Pointer]\n");
    increment_all(numbers, 5);
    print_array_with_pointer(numbers, 5);
    printf("\n");

    printf("[Find Max in Array Using Pointer]\n");
    int* max_ptr = find_max(numbers, 5);
    if (max_ptr != NULL) {
        printf("Max value: %d (at address: %p)\n\n", *max_ptr, (void*)max_ptr);
    }

    int flat_matrix[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };
    printf("[Matrix Traversal Using Flat Pointer]\n");
    print_matrix_by_pointer(&flat_matrix[0][0], 2, 3);

    return 0;
}