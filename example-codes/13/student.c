#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"

student_t* create_students(int count)
{
    student_t* pa_students = malloc(sizeof(student_t) * count);
    if (pa_students == NULL) {
        return NULL;
    }

    for (int i = 0; i < count; ++i) {
        pa_students[i].name       = NULL;
        pa_students[i].scores     = NULL;
        pa_students[i].num_scores = 0;
    }
    return pa_students;
}

int init_student(student_t* student, const char* name, int num_scores)
{
    size_t name_len = strlen(name) + 1U;

    student->name = malloc(name_len);
    if (student->name == NULL) {
        return -1;
    }
    memcpy(student->name, name, name_len);

    student->scores = malloc(sizeof(int) * num_scores);
    if (student->scores == NULL) {
        free(student->name);
        student->name = NULL;
        return -1;
    }

    student->num_scores = num_scores;
    return 0;
}

void print_student(const student_t* student)
{
    printf("Name: %s | Scores:", student->name);

    long total = 0;
    for (int i = 0; i < student->num_scores; ++i) {
        printf(" %d", student->scores[i]);
        total += student->scores[i];
    }

    assert(student->num_scores > 0);
    double avg = total / (double)student->num_scores;

    printf(" | Avg: %.2f\n", avg);
}
