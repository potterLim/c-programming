/*
 * Example code from: 04-operators
 * Purpose          : Demonstrates arithmetic, assignment, relational, logical, and increment/decrement operators in C
 */

#include <stdio.h>

int main(void)
{
    // Arithmetic Operators
    int a = 10;
    int b = 3;

    printf("Arithmetic Operators:\n");
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);  // Integer division
    printf("a %% b = %d\n\n", a % b);  // Remainder (%% to escape %)

    // Assignment Operators
    int x = 5;
    printf("Assignment Operators:\n");
    x += 3;  // x = x + 3
    printf("x += 3 → %d\n", x);
    x *= 2;  // x = x * 2
    printf("x *= 2 → %d\n\n", x);

    // Relational Operators
    int p = 7;
    int q = 10;

    printf("Relational Operators:\n");
    printf("p == q → %d\n", p == q);  // false (0)
    printf("p != q → %d\n", p != q);  // true  (1)
    printf("p > q  → %d\n", p > q);   // false (0)
    printf("p <= q → %d\n\n", p <= q); // true  (1)

    // Logical Operators
    int m = 5;
    int n = -1;

    printf("Logical Operators:\n");
    printf("m > 0 && n > 0 → %d\n", m > 0 && n > 0);  // false (0)
    printf("m > 0 || n > 0 → %d\n", m > 0 || n > 0);  // true  (1)
    printf("!(m > 0)       → %d\n\n", !(m > 0));      // false (0)

    // Increment / Decrement Operators
    int counter = 5;

    printf("Increment/Decrement Operators:\n");
    printf("++counter → %d\n", ++counter);  // Pre-increment: increment first
    printf("counter++ → %d\n", counter++);  // Post-increment: use then increment
    printf("After post-increment, counter = %d\n", counter);

    return 0;
}
