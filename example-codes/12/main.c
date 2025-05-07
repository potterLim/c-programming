/*
 * Example code from: 12-struct-typedef
 * Purpose          : Demonstrates various usages of struct and typedef
 */

#include <stdio.h>
#include "student.h"

int main(void)
{
    student_t alice = create_student("Alice", 20, 4.3f);
    student_t bob = create_student("Bob", 22, 3.7f);

    print_student(&alice);
    printf("\n");
    print_student(&bob);

    update_gpa(&bob, 3.9f);
    printf("\nAfter GPA Update:\n");
    print_student(&bob);

    printf("\nClass List:\n");
    student_t class_members[3];
    class_members[0] = alice;
    class_members[1] = bob;
    class_members[2] = create_student("Charlie", 19, 3.5f);

    for (int i = 0; i < 3; ++i) {
        printf("\nStudent #%d\n", i + 1);
        print_student(&class_members[i]);
    }

    return 0;
}
