#ifndef STUDENT_H
#define STUDENT_H

typedef struct student {
    char* name;      /* dynamically allocated string */
    int* scores;     /* dynamically allocated array of ints */
    int num_scores;  /* length of scores array */
} student_t;

/* Returns NULL on allocation failure */
student_t* create_students(int count);

/* Returns 0 on success, -1 on failure (caller must free on failure) */
int init_student(student_t* student, const char* name, int num_scores);

/* Prints the student, including average score (computed inside) */
void print_student(const student_t* student);

#endif /* STUDENT_H */
