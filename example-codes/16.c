/*
 * Example code for: 16-bitwise-operators
 * Purpose         : Demonstrates practical usage of bitwise operators in C
 */

#include <stdio.h>
#include <ctype.h>

// Flag masks for status variable (8-bit)
#define FLAG_POWER        (0x01)  // 00000001
#define FLAG_CHARGING     (0x02)  // 00000010
#define FLAG_ERROR        (0x04)  // 00000100
#define FLAG_CONNECTED    (0x08)  // 00001000
#define FLAG_TRANSMITTING (0x10)  // 00010000
#define FLAG_RECEIVING    (0x20)  // 00100000
#define FLAG_SLEEP        (0x40)  // 01000000
#define FLAG_RESERVED     (0x80)  // 10000000

void print_binary(const char *label, unsigned char value)
{
    printf("    %s: 0b", label);
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
    printf("\n");
}

int main(void)
{
    int num = 5;
    printf("[1] Odd/Even Check for %d: %s\n", num, (num & 1) ? "Odd" : "Even");

    num = 8;
    printf("[2] Power of 2 Check for %d: %s\n", num, ((num > 0) && ((num & (num - 1)) == 0)) ? "Yes" : "No");

    unsigned char flags = 0x00;
    printf("[3] Bit Manipulation:\n");
    printf("    Initial flags: 0x%02X\n", flags);

    flags |= (1 << 2);  // Set 2nd bit
    printf("    Set 2nd bit: 0x%02X\n", flags);

    flags ^= (1 << 3);  // Toggle 3rd bit
    printf("    Toggle 3rd bit: 0x%02X\n", flags);

    flags &= ~(1 << 2);  // Clear 2nd bit
    printf("    Clear 2nd bit: 0x%02X\n", flags);

    if (flags & (1 << 1)) {
        printf("    1st bit is ON\n");
    } else {
        printf("    1st bit is OFF\n");
    }

    char upper = 'A';
    char lower = upper | 0x20;
    char back = lower & ~0x20;
    printf("[4] '%c' to lowercase: %c\n", upper, lower);
    printf("    '%c' back to uppercase: %c\n", lower, back);

    int value = 6;
    printf("[5] Shift Operations:\n");
    printf("    %d << 1 = %d\n", value, value << 1);
    printf("    %d >> 1 = %d\n", value, value >> 1);

    int a = 10;
    int b = 20;
    printf("[6] Swap using XOR:\n");
    printf("    Before swap: a = %d, b = %d\n", a, b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("    After swap:  a = %d, b = %d\n", a, b);

    // Additional Example: 8-bit status flag manipulation
    unsigned char status = 0;
    printf("[7] Flag-based Status Management:\n");
    print_binary("Initial status", status);

    status |= FLAG_POWER;
    status |= FLAG_CONNECTED;
    status |= FLAG_CHARGING;
    print_binary("Set POWER, CONNECTED, CHARGING", status);

    if (status & FLAG_CHARGING) {
        printf("    CHARGING is ON\n");
    }

    status &= ~FLAG_CHARGING;
    print_binary("Clear CHARGING", status);

    status ^= FLAG_ERROR;
    print_binary("Toggle ERROR (1st time)", status);

    status ^= FLAG_ERROR;
    print_binary("Toggle ERROR (2nd time)", status);

    status |= (FLAG_TRANSMITTING | FLAG_RECEIVING);
    print_binary("Set TRANSMITTING & RECEIVING", status);

    status &= FLAG_POWER;
    print_binary("Keep only POWER", status);

    return 0;
}
