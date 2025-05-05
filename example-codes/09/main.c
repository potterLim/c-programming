/*
 * Example code from: 09-arrays-and-multidimensional-arrays
 * Purpose          : Demonstrates array declaration, initialization, iteration, function passing, common pitfalls, and multidimensional arrays in C
 */

#include <stdio.h>
#include "array.h"

int main(void)
{
    // 1. Declare and initialize a 1D array (int)
    int scores[5] = {85, 90, 78, 92, 88};
    printf("[Original Scores (int)]\n");
    print_array(scores, 5);

    // 2. Calculate average
    float avg = get_average(scores, 5);
    printf("Average Score: %.2f\n\n", avg);

    // 3. Modify array through a function
    printf("[Zero-filled Scores]\n");
    fill_with_zero(scores, 5);
    print_array(scores, 5);

    // 4. Declare and print a 2D array (int)
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    printf("\n[2D Matrix (Direct Print)]\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
        }
    }

    printf("\n[2D Matrix (Function Print)]\n");
    print_matrix(2, 3, matrix);

    // 5. Different types of arrays
    float pi_values[3] = {3.14f, 3.141f, 3.1415f};
    char grades[4] = {'A', 'B', 'C', 'D'};

    printf("\n[Float Array]\n");
    for (int i = 0; i < 3; ++i) {
        printf("pi_values[%d] = %.4f\n", i, pi_values[i]);
    }

    printf("\n[Char Array (Grades)]\n");
    for (int i = 0; i < 4; ++i) {
        printf("grades[%d] = %c\n", i, grades[i]);
    }

    // 6. Partial array initialization
    int partial[5] = {10, 20};
    printf("\n[Partially Initialized Array]\n");
    print_array(partial, 5);

    // 7. Inferred size
    int inferred[] = {7, 14, 21, 28};
    printf("\n[Inferred Size Array]\n");
    print_array(inferred, sizeof(inferred) / sizeof(inferred[0]));

    // 8. Common mistakes (commented out)
    /*
    scores = {1, 2, 3};            // Error: Cannot assign to array
    scores[5] = 100;               // Error: Out of bounds
    scores[-1] = 0;                // Error: Negative index
    */

    // 9. Valid access of the last element
    printf("\nLast element in inferred array: %d\n", inferred[3]);

    return 0;
}
