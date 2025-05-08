/*
 * Example code for: 15-bitwise-operators
 * Purpose         : Demonstrates practical usage of bitwise operators in C
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int num = 5;
    printf("[1] Odd/Even Check for %d: %s\n", num, (num & 1) ? "Odd" : "Even");

    num = 8;
    printf("[2] Power of 2 Check for %d: %s\n", num, ((num > 0) && ((num & (num - 1)) == 0)) ? "Yes" : "No");

    unsigned char flags = 0x00;
    printf("[3] Initial flags: 0x%02X\n", flags);

    // Set 2nd bit
    flags |= (1 << 2);
    printf("    Set 2nd bit: 0x%02X\n", flags);

    // Toggle 3rd bit
    flags ^= (1 << 3);
    printf("    Toggle 3rd bit: 0x%02X\n", flags);

    // Clear 2nd bit
    flags &= ~(1 << 2);
    printf("    Clear 2nd bit: 0x%02X\n", flags);

    // Check if 1st bit is set
    if (flags & (1 << 1)) {
        printf("    1st bit is ON\n");
    } else {
        printf("    1st bit is OFF\n");
    }

    // Character case manipulation
    char upper = 'A';
    char lower = upper | 0x20;
    char back = lower & ~0x20;
    printf("[4] '%c' to lowercase: %c\n", upper, lower);
    printf("    '%c' back to uppercase: %c\n", lower, back);

    // Left and right shift
    int value = 6;
    printf("[5] %d << 1 = %d\n", value, value << 1);
    printf("    %d >> 1 = %d\n", value, value >> 1);

    // Swap two integers without temporary variable
    int a = 10;
    int b = 20;
    printf("[6] Before swap: a = %d, b = %d\n", a, b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("    After swap:  a = %d, b = %d\n", a, b);

    return 0;
}
