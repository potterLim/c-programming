// 📁 student.h

#ifndef STUDENT_H
#define STUDENT_H

typedef struct student {
    char* name;
    int age;
    double gpa;
} student_t;

student_t* create_students_malloc(int count);

int count_high_gpa(const student_t* students, int count, double threshold);
int count_name_starts_with(const student_t* students, int count, char ch);
int find_oldest_student_index(const student_t* students, int count);
int find_student_by_name(const student_t* students, int count, const char* name);

#endif /* STUDENT_H */