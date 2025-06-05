# LAB05: 문자열 정보 분석기 (String Inspector)

## 🧾 과제 개요

이 과제에서는 C언어에서 포인터와 문자열 함수들을 활용하여  
입력된 문자열에 대해 다양한 정보를 분석하는 프로그램을 작성합니다.

- 포인터를 이용해 문자열을 순회하며 직접 분석
- 문자열 함수들을 조합하여 기능 구현
- 대소문자, 숫자, 특수문자, 공백 등 다양한 조건을 구분하여 판단

## 🎯 과제 목표

- 문자열을 포인터 기반으로 처리하는 능력 기르기
- 다양한 `string.h` 함수의 기능과 차이점 익히기

## 📁 제공 파일

| 파일명            | 설명                                      |
|-------------------|-------------------------------------------|
| `string_util.c`   | 구현할 함수 정의 파일                     |
| `string_util.h`   | 함수 원형 및 상수 정의 (수정 금지)        |
| `main.c`          | 테스트용 자동 채점 코드 (수정 금지)       |

> 💡 **구현 시 유의사항**  

- 배열이 아닌 포인터 연산을 사용하여 문자열을 탐색하세요.  
예시:
  ```c
  const char str[] = "Hello World\n";
  const char* p = str;

  while (*p != '\0') {
      printf("%c", *p);
      p++;
  }
  // 출력: Hello World
  ```
- `string.h`의 함수는 자유롭게 사용해도 됩니다.
- `TRUE`와 `FALSE`는 string_util.h 헤더 파일에서 다음과 같이 정의되어 있습니다.

```c
#define TRUE (1)
#define FALSE (0)
```

## 🔧 구현해야 할 함수

```c
int count_uppercase(const char* str);
int count_lowercase(const char* str);
int count_digits(const char* str);
int count_spaces(const char* str);
int count_special_characters(const char* str);
int is_valid_password(const char* str);
```

### 각 함수 설명

- `count_uppercase`: 대문자의 개수를 반환
- `count_lowercase`: 소문자의 개수를 반환
- `count_digits`: 숫자의 개수를 반환
- `count_spaces`: 공백(스페이스)의 개수를 반환
- `count_special_characters`: 알파벳/숫자/공백을 제외한 문자 개수를 반환
- `is_valid_password`: 다음 조건을 모두 만족하면 `TRUE(1)`, 아니면 `FALSE(0)`을 반환
  - 길이가 8자 이상
  - 대문자 1개 이상
  - 소문자 1개 이상
  - 숫자 1개 이상
  - 특수문자 1개 이상(공백은 특수문자로 간주하지 않는다.)

## ⚙️ 빌드 및 실행 방법

```bash
gcc -o lab05.exe string_util.c main.c
./lab05.exe
```

> `✅ 모든 테스트를 통과했습니다.` 메시지가 출력되어야 합니다.

## 🧭 마무리 안내

- `string_util.h`, `main.c` 파일은 수정하지 마세요.
- 함수별로 코드를 정확하게 작성하고, 주어진 기능을 구현하세요.