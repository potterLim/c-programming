/*
 * Example code from: 02-variables-and-constants
 * Purpose          : Demonstrates variable declaration, assignment, and constants in C
 */

#include <stdio.h>

#define PI (3.1415926)
#define MAX_BUFFER_SIZE (1024)

int main(void)
{
    // Variable declaration and initialization
    int student_count = 30;
    float weight = 65.5f;
    double average_score = 87.654321;
    char grade = 'A';

    // Constant declaration using const keyword
    const int DAYS_IN_WEEK = 7;

    // Print variable values
    printf("Student count    : %d\n", student_count);
    printf("Weight           : %.1f kg\n", weight);
    printf("Average score    : %.6f\n", average_score);
    printf("Grade            : %c\n", grade);

    // Print constants
    printf("Days in a week   : %d\n", DAYS_IN_WEEK);
    printf("PI               : %.7f\n", PI);
    printf("Buffer size      : %d bytes\n", MAX_BUFFER_SIZE);

    return 0;
}
