# LAB06: 학생 목록 필터기 (Student Filter)

## 🧾 과제 개요

이 과제에서는 구조체와 동적 메모리 할당을 사용하여 학생 정보를 담는 프로그램을 작성합니다.  
학생 구조체에는 이름, 나이, GPA가 포함되며, 다양한 기준으로 학생 목록을 필터링하고 검색하는 함수를 구현합니다.

## 🎯 과제 목표

- 구조체의 정의와 활용 능력 향상  
- 동적 메모리 할당 학습  
- 문자열 비교 및 포인터 사용 능력 향상

## 📁 제공 파일

| 파일명         | 설명                             |
|----------------|----------------------------------|
| `student.h`    | 구조체 정의 및 함수 원형 선언     |
| `student.c`    | 함수 구현                         |
| `main.c`       | 자동 채점 및 테스트 코드          |

## 🔧 구현할 함수 목록

```c
student_t* create_students_malloc(int count); // count개의 student_t 구조체 배열을 동적 할당하고 그 포인터를 반환합니다.
int count_high_gpa(const student_t* students, int count, double threshold);
int count_name_starts_with(const student_t* students, int count, char ch);
int find_oldest_student_index(const student_t* students, int count);
int find_student_by_name(const student_t* students, int count, const char* name);
```

> 유효하지 않거나 예측할 수 없는 매개변수가 전달된 경우 함수는 -1을 반환해야 합니다.

## 📌 구현 조건

- `create_students_malloc`는 `malloc`으로 구조체 배열을 동적으로 생성해야합니다.
- `count_name_starts_with`은 문자열 첫 글자 비교시 대소문자 구분 없이 처리하세요.
- `find_student_by_name`은 정확히 일치하는 이름을 찾고 인덱스를 반환합니다. 찾지 못하면 `-1`을 반환합니다.

## ⚙️ 빌드 및 실행 방법

```bash
gcc -o lab06.exe student.c main.c
./lab06.exe
```

`✅ 모든 테스트를 통과했습니다.` 메시지가 출력되어야 합니다.

## 🧭 마무리 안내

- `student.h`, `main.c` 파일은 수정하지 마세요.
- 함수별로 코드를 정확하게 작성하고, 동적 메모리 할당과 해제를 잊지 마세요.