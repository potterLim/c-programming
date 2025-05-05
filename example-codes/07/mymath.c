#include <stdio.h>
#include "mymath.h"

// Function definitions
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

float divide(int a, int b)
{
    if (b == 0) {
        printf("Error: Division by zero.\n");
        return 0.0f;
    }
    return (float)a / b;
}

void print_sum(int a, int b)
{
    int result = add(a, b);
    printf("The sum of %d and %d is %d.\n", a, b, result);
}

void print_difference(int a, int b)
{
    int result = subtract(a, b);
    printf("The difference between %d and %d is %d.\n", a, b, result);
}

void modify(int value)
{
    printf("Inside modify(): value was %d, now set to 0\n", value);
    value = 0;
}
