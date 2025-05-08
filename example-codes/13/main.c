/*
 * Example code for: 13-Dynamic Memory Allocation
 * Purpose         : Interacts with user input to create, store, and print student data using dynamic memory
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"

int main(void)
{
    int student_count;

    printf("How many students? ");
    scanf("%d", &student_count);
    getchar(); /* consume trailing '\n' */

    if (student_count <= 0) {
        printf("Invalid count.\n");
        return 1;
    }

    student_t* pa_students = create_students(student_count);
    if (pa_students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < student_count; ++i) {
        char name_buf[256];
        int score_count;

        /* Read full line for the name (allows spaces) */
        printf("\nStudent %d name: ", i + 1);
        fgets(name_buf, sizeof(name_buf), stdin);

        /* Strip newline using the common strcspn idiom */
        name_buf[strcspn(name_buf, "\n")] = '\0';

        printf("  How many scores for \"%s\"? ", name_buf);
        scanf("%d", &score_count);
        getchar(); /* consume trailing '\n' */

        if (score_count <= 0 ||
            init_student(&pa_students[i], name_buf, score_count) != 0) {
            printf("  Allocation failed.\n");

            /* Free everything allocated so far before exiting */
            for (int k = 0; k <= i; ++k) {
                free(pa_students[k].name);
                pa_students[k].name = NULL;
                free(pa_students[k].scores);
                pa_students[k].scores = NULL;
            }
            free(pa_students);
            pa_students = NULL;
            return 1;
        }

        printf("  Enter %d score(s): ", score_count);
        for (int j = 0; j < score_count; ++j) {
            scanf("%d", &pa_students[i].scores[j]);
        }
        getchar(); /* consume trailing '\n' */
    }

    printf("\n===== Student Report =====\n");
    for (int i = 0; i < student_count; ++i) {
        print_student(&pa_students[i]);
    }

    /* Explicit cleanup in main */
    for (int i = 0; i < student_count; ++i) {
        free(pa_students[i].name);
        pa_students[i].name = NULL;
        free(pa_students[i].scores);
        pa_students[i].scores = NULL;
    }
    free(pa_students);
    pa_students = NULL;

    return 0;
}
