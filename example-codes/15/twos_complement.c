#include <stdio.h>

#define BIT_COUNT 8

/* Print decimal and binary */
void print_binary_decimal(int value)
{
    int bits[BIT_COUNT];
    int abs_value = value;

    if (value < 0)
    {
        abs_value = 256 + value;  /* for 8-bit simulation */
    }

    for (int i = BIT_COUNT - 1; i >= 0; --i)
    {
        bits[i] = abs_value % 2;
        abs_value /= 2;
    }

    for (int i = 0; i < BIT_COUNT; ++i)
    {
        printf("%d", bits[i]);
    }
}

/* Flip bits manually (1's complement) */
void compute_ones_complement(int value, int result[])
{
    int bits[BIT_COUNT];

    for (int i = BIT_COUNT - 1; i >= 0; --i)
    {
        bits[i] = value % 2;
        value /= 2;
    }

    for (int i = 0; i < BIT_COUNT; ++i)
    {
        result[i] = bits[i] ? 0 : 1;
    }
}

/* Add 1 to 1's complement to get 2's complement */
void compute_twos_complement(int ones[], int result[])
{
    int carry = 1;

    for (int i = BIT_COUNT - 1; i >= 0; --i)
    {
        if (ones[i] == 1 && carry == 1)
        {
            result[i] = 0;
            carry = 1;
        }
        else if (ones[i] == 0 && carry == 1)
        {
            result[i] = 1;
            carry = 0;
        }
        else
        {
            result[i] = ones[i];
        }
    }
}
