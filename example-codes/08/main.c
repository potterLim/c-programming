/*
 * Example code from: 08-recursion-and-applications
 * Purpose          : Demonstrates recursive thinking via binary conversion and sum of digits
 */

#include <stdio.h>
#include "recursion.h"

int main(void)
{
    int number = 13;
    int digit_sum = get_digit_sum(number);

    printf("Decimal: %d\n", number);
    printf("Binary: ");
    print_binary(number);
    printf("\n");
    printf("Sum of digits: %d\n", digit_sum);

    return 0;
}
