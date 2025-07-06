/*
 * Example code for: 15-Number Systems in Computers
 * Purpose         : Demonstrates how integers are represented using 2's complement.
 *                   Shows binary output, manual 2's complement calculation,
 *                   and overflow/underflow behavior in fixed-width integers.
 */

#include <stdio.h>
#include "twos_complement.h"

#define BIT_COUNT (8)

void print_bits(int bits[])
{
    for (int i = 0; i < BIT_COUNT; ++i)
    {
        printf("%d", bits[i]);
    }
}

void print_line(void)
{
    printf("--------------------------------------------------\n");
}

int main(void)
{
    int ones[BIT_COUNT];
    int twos[BIT_COUNT];
    int test_values[] = {0, 1, 5, 10, -1, -5, -10, 127, -128};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    printf("=== Two's Complement Representation (8-bit) ===\n\n");
    printf("Value\tBinary\t\tDecimal\n");
    printf("------\t--------\t--------\n");

    for (int i = 0; i < num_tests; ++i)
    {
        int val = test_values[i];
        printf("%4d\t", val);
        print_binary_decimal(val);
        printf("\t%7d\n", val);
    }

    printf("\n=== Manual Two's Complement of Positive Numbers ===\n\n");
    printf("Original\t1's Comp.\t+1\t= 2's Comp.\n");
    printf("--------\t----------\t---\t-------------\n");

    for (int i = 0; i < 4; ++i) // Only non-negative values
    {
        int val = test_values[i];
        int j;

        print_binary_decimal(val);
        printf("\t");

        compute_ones_complement(val, ones);
        print_bits(ones);
        printf("\t");

        compute_twos_complement(ones, twos);
        printf("+1\t");
        print_bits(twos);
        printf(" (%d)\n", -val);
    }

    printf("\n=== Overflow and Underflow Examples ===\n\n");

    int overflow_result = (127 + 1) & 0xFF;
    int underflow_result = (-128 - 1) & 0xFF;

    printf("127 + 1 = %d\tBinary: ", (char)(127 + 1));
    print_binary_decimal((char)(127 + 1));
    printf("\t[Overflow]\n");

    printf("-128 - 1 = %d\tBinary: ", (char)(-128 - 1));
    print_binary_decimal((char)(-128 - 1));
    printf("\t[Underflow]\n");

    return 0;
}
