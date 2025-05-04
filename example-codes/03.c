/*
 * Example code from: 03-data-types-and-type-conversion
 * Purpose          : Demonstrates data types, format specifiers, and type conversions in C
 */

#include <stdio.h>

int main(void)
{
    // Declare and initialize primitive data types
    int integer_value = 42;
    float float_value = 3.14f;
    double double_value = 2.718281828;
    char character = 'A';

    // Format specifiers
    printf("int    : %d\n", integer_value);
    printf("float  : %f\n", float_value);
    printf("double : %lf\n", double_value);
    printf("char   : %c\n", character);
    printf("float (2 decimal places) : %.2f\n", float_value);

    // Implicit type conversion (int + float → float)
    int count = 3;
    float average_per_person = 1.5f;
    float result = count + average_per_person;  // 'count' is automatically converted to float
    printf("Implicit conversion (int + float): %.2f\n", result);

    // Explicit type conversion (double → int)
    double pi = 3.14159;
    int truncated_pi = (int)pi;  // decimal part is truncated
    printf("Explicit conversion (double → int): %d\n", truncated_pi);

    // Warning: int → char (data loss)
    int big_number = 100000;
    char small_char = (char)big_number;
    printf("Overflowed char from int 100000: %d\n", small_char);

    // Warning: int / int → float (integer division happens first)
    int total_score = 3;
    int number_of_students = 2;
    float wrong_average = total_score / number_of_students;  // result is 1.0
    float correct_average = total_score / (float)number_of_students;  // result is 1.5

    printf("Wrong average (int/int): %.1f\n", wrong_average);
    printf("Correct average (type cast): %.1f\n", correct_average);

    return 0;
}
