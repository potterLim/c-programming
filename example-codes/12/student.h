#ifndef STUDENT_H
#define STUDENT_H

typedef struct student
{
    char name[20];
    int age;
    float gpa;
} student_t;

student_t create_student(const char* name, int age, float gpa);
void print_student(const student_t* student);
void update_gpa(student_t* student, float new_gpa);

#endif /* STUDENT_H */
