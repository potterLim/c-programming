#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"

static void test_int(const char* message, int actual, int expected)
{
    printf("%s → 예상: %d, 실제: %d\n", message, expected, actual);
    assert(actual == expected);
}

int main(void)
{
    student_t* students = create_students_malloc(5);
    students[0].name = malloc(strlen("Alice") + 1); 
    strcpy(students[0].name, "Alice"); 
    students[0].age = 20; 
    students[0].gpa = 3.8;

    students[1].name = malloc(strlen("Bob") + 1);   
    strcpy(students[1].name, "Bob");   
    students[1].age = 22; 
    students[1].gpa = 2.9;

    students[2].name = malloc(strlen("Carol") + 1); 
    strcpy(students[2].name, "Carol"); 
    students[2].age = 21; 
    students[2].gpa = 4.1;

    students[3].name = malloc(strlen("") + 1);      
    strcpy(students[3].name, "");       
    students[3].age = 19; 
    students[3].gpa = 3.2;

    students[4].name = NULL;                         
    students[4].age = 23; 
    students[4].gpa = 1.5;

    // 정상 동작 테스트
    test_int("[1] GPA 3.0 이상 학생 수", count_high_gpa(students, 5, 3.0), 3);
    test_int("[2] 이름 A로 시작하는 학생 수", count_name_starts_with(students, 5, 'A'), 1);
    test_int("[3] 가장 나이 많은 학생 인덱스", find_oldest_student_index(students, 5), 4);
    test_int("[4] 이름 Carol의 인덱스", find_student_by_name(students, 5, "Carol"), 2);
    test_int("[5] 존재하지 않는 이름 검색", find_student_by_name(students, 5, "Daniel"), -1);

    // 엣지 상황 테스트
    test_int("[6] count = 0일 때 oldest 인덱스", find_oldest_student_index(students, 0), -1);
    test_int("[7] GPA 필터링 (4.5 이상 없음)", count_high_gpa(students, 5, 4.5), 0);
    test_int("[8] 이름 Z로 시작하는 학생 없음", count_name_starts_with(students, 5, 'Z'), 0);
    test_int("[9] 이름이 빈 문자열일 때 검색", count_name_starts_with(students, 5, '\0'), 1);
    test_int("[10] NULL 이름이 있을 때 검색 함수 영향 없음", count_name_starts_with(students, 5, 'B'), 1);
    test_int("[11] NULL 이름 검색 (일치하는 이름 아님)", find_student_by_name(students, 5, NULL), -1);
    test_int("[12] 이름이 NULL일 때 검색 통과", find_student_by_name(students, 5, "Bob"), 1);

    // 메모리 해제
    for (int i = 0; i < 5; ++i) {
        free(students[i].name);
        students[i].name = NULL;
    }
    free(students);
    students = NULL;

    printf("✅ 모든 테스트를 통과했습니다.\n");
    return 0;
}
