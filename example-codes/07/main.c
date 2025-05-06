/*
* Example code from: 07-functions-and-preprocessor
* Purpose          : Demonstrates user-defined functions, header usage, and preprocessor directives in C
*/

#include <stdio.h>
#include "functions.h"

int main(void)
{
    int a = 15;
    int b = 5;

    printf("Input values: a = %d, b = %d\n", a, b);

    printf("\n[Basic Operations]\n");
    printf("Addition        : %d + %d = %d\n", a, b, add(a, b));
    printf("Subtraction     : %d - %d = %d\n", a, b, subtract(a, b));
    printf("Multiplication  : %d * %d = %d\n", a, b, multiply(a, b));
    printf("Division        : %d / %d = %.2f\n", a, b, divide(a, b));

    printf("\n[Print Utility Functions]\n");
    print_sum(a, b);
    print_difference(a, b);

    printf("\n[Another Custom Calculation]\n");
    int x = 8, y = 12;
    print_sum(x, y);
    print_difference(x, y);

    printf("\n[Effect of Call-by-Value]\n");
    printf("Original value of a before modify(): %d\n", a);
    modify(a);
    printf("Value of a after modify(): %d (unchanged due to call-by-value)\n", a);

    return 0;
}
