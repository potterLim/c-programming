/*
 * Example code from: 05-conditional-statements
 * Purpose          : Demonstrates various conditional statements including common mistakes
 */

#include <stdio.h>

int main(void)
{
    int age = 20;
    int score = 85;
    int menu = 3;
    char grade = 'B';

    // if statement
    if (age >= 18) {
        printf("You are an adult.\n");
    }

    // Bad if statement example: missing braces
    /*
    if (age >= 18)
        printf("You are an adult.\n");
        printf("This line runs unconditionally! (logic bug)\n");  // common mistake
    */

    // if - else statement
    if (score >= 90) {
        printf("You got an A.\n");
    } else {
        printf("You did not get an A.\n");
    }

    // if - else if - else statement
    if (score >= 90) {
        printf("Grade: A\n");
    } else if (score >= 80) {
        printf("Grade: B\n");
    } else if (score >= 70) {
        printf("Grade: C\n");
    } else {
        printf("Grade: F\n");
    }

    // Bad condition order example
    /*
    if (score >= 70) {
        printf("Grade: C or higher\n");  // runs too early
    } else if (score >= 80) {
        printf("Grade: B\n");  // unreachable!
    }
    */

    // Nested if example
    if (age >= 18) {
        if (score >= 80) {
            printf("Adult with a B or higher grade.\n");
        }
    }

    // switch statement example
    switch (menu) {
        case 1:
            printf("Menu: Chicken\n");
            break;
        case 2:
            printf("Menu: Pizza\n");
            break;
        case 3:
            printf("Menu: Burger\n");
            break;
        default:
            printf("Invalid menu selection.\n");
            break;
    }

    // Intentional fall-through example
    switch (grade) {
        case 'A':
            printf("Excellent grade.\n");
            break;
        case 'B':
            printf("Good grade.\n");
            /* intentional fallthrough */
        case 'C':
            printf("Please schedule an academic advising.\n");
            break;
        default:
            printf("Invalid grade.\n");
            break;
    }

    // Bad switch example: missing break
    /*
    switch (menu) {
        case 1:
            printf("Chicken\n");
        case 2:
            printf("Pizza\n");
        case 3:
            printf("Burger\n");
    }
    // All items are printed due to missing breaks (unintentional fall-through)
    */

    return 0;
}
