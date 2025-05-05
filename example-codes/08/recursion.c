#include <stdio.h>
#include "recursion.h"

// Recursively prints binary representation of n
void print_binary(int n)
{
    if (n < 2) {
        printf("%d", n);
        return;
    }

    print_binary(n / 2);
    printf("%d", n % 2);
}

// Recursively calculates the sum of digits of n
int get_digit_sum(int n)
{
    if (n < 10) {
        return n;
    }

    return (n % 10) + get_digit_sum(n / 10);
}