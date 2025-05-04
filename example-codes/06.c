/*
* Example code from: 06-loops
* Purpose          : Demonstrates various loop structures including common mistakes
*/
#include <stdio.h>
int main(void)
{
    int count = 0;
    int input = 0;

    // while loop: repeat until correct password entered
    int password = 1234;
    while (input != password) {
        printf("Enter password: ");
        scanf("%d", &input);
    }
    printf("Access granted!\n");

    // Bad while loop example: infinite loop due to missing update
    /*
    int x = 0;
    while (x < 5) {
        printf("This will print forever because x is never updated!\n");
    }
    */

    // do - while loop: at least one execution guaranteed
    int number;
    do {
        printf("Enter a positive number: ");
        scanf("%d", &number);
    } while (number <= 0);
    printf("Valid number entered: %d\n", number);

    // Bad do - while loop example: missing semicolon
    /*
    do {
        printf("Missing semicolon will cause compiler error.\n")
    } while (1)
    */

    // for loop: iterate 5 times
    for (int i = 0; i < 5; ++i) {
        printf("Iteration: %d\n", i);
    }

    // Bad for loop: off-by-one error
    /*
    for (int i = 1; i <= 5; ++i) {
        printf("Starts from 1 instead of 0, may cause indexing issue later.\n");
    }
    */

    // Nested loop example: grid coordinates
    for (int row = 1; row <= 2; ++row) {
        for (int col = 1; col <= 3; ++col) {
            printf("Row %d, Column %d\n", row, col);
        }
    }

    // break example
    for (int i = 0; i < 10; ++i) {
        if (i == 4) {
            printf("Breaking at i = %d\n", i);
            break;
        }
        printf("i = %d\n", i);
    }

    // continue example
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            continue;
        }
        printf("Odd number: %d\n", i);
    }

    // Bad continue usage: misunderstood flow
    /*
    for (int i = 0; i < 5; ++i) {
        continue;
        printf("This will never be printed!\n");  // unreachable code
    }
    */

    return 0;
}
