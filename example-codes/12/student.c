#include <stdio.h>
#include <string.h>
#include "student.h"

student_t create_student(const char* name, int age, float gpa)
{
    student_t student;
    strncpy(student.name, name, sizeof(student.name) - 1);
    student.name[sizeof(student.name) - 1] = '\0';
    student.age = age;
    student.gpa = gpa;
    return student;
}

void print_student(const student_t* student)
{
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("GPA: %.2f\n", student->gpa);
}

void update_gpa(student_t* student, float new_gpa)
{
    student->gpa = new_gpa;
}
