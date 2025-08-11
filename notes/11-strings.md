# 11. 문자열 (Strings)

문자열(string)은 문자들이 연속해서 모여 있는 것이다.  
C언어에서는 문자열을 특별히 문자형(`char`) 배열로 취급하며, 끝에 반드시 `'\0'`이라는 널 문자(null character)가 붙는다.

널 문자는 문자열이 어디에서 끝나는지를 알려주는 역할을 한다.  
문자열을 다룰 때 C 언어의 모든 문자열 함수는 이 `'\0'`을 기준으로 작동한다.

```c
char str[] = "cat";
```

이 코드는 다음과 같이 저장된다:

| 인덱스 | 값     |
| :----: | :----: |
| 0      | `'c'`  |
| 1      | `'a'`  |
| 2      | `'t'`  |
| 3      | `'\0'` |

## 문자열과 다른 배열의 차이

문자형 배열은 그 자체가 문자열이지만 다른 자료형 배열은 널 문자로 끝나지 않는다.  
즉, C에서 문자열은 단순히 '문자의 나열'이 아니라 '널 문자로 끝나는 문자 배열'을 뜻한다.

## 문자열 선언과 초기화

```c
char str1[] = "apple";                 // 문자열 리터럴 사용
char str2[6] = "apple";                // 널 문자까지 포함
char str3[] = {'a', 'p', 'p', 'l', 'e', '\0'};  // 수동 초기화
```

다음 코드는 컴파일은 되지만 문자열로서 동작하지 않는다.

```c
char broken[5] = "apple";  // '\0'이 들어갈 공간이 없음 (위험)
```

## 문자열 출력

### `printf()`

```c
int printf(const char* format, ...);
```

- 문자열은 `%s` 서식자를 사용한다.

```c
char name[] = "Alice";
printf("이름: %s\n", name);
```

## 문자열 입력

### `scanf()`

```c
int scanf(const char* format, ...);
```

- 문자열을 공백 전까지 입력받을 수 있다.
- `scanf("%s", input);` 형태로 사용한다.
- 문자열 변수 이름에는 `&`를 붙이지 않는다. 배열 이름이 곧 주소이기 때문이다.

```c
char input[100];
scanf("%s", input);  // 공백 이전까지만 입력됨
```

### `fgets()`

```c
char* fgets(char* str, int n, FILE* stream);
```

> 여기서 `FILE* stream`은 파일 입출력에서 사용하는 개념이지만 지금은 아직 파일을 배우지 않았으므로 표준 입력을 의미하는 `stdin`을 사용하면 된다.  
>`stdin`은 키보드 입력을 의미하며, 대부분의 사용자 입력은 `stdin`을 통해 받는다.

- 한 줄 전체를 입력받을 수 있고, 공백 포함 가능하다.
- 최대 입력 길이를 제한할 수 있어 안전하다.
- 단점: 줄바꿈 문자(`'\n'`)가 포함될 수 있다.

```c
char input[100];
fgets(input, sizeof(input), stdin);
```
줄바꿈 문자가 실제로 어떻게 저장되는지 아래 예시를 통해 확인해보자.

예: 사용자가 `hello`를 입력하고 Enter를 누르면 `fgets()`는 다음과 같이 저장한다:

| 인덱스 | 값     |
| :----: | :----: |
| 0      | `'h'`  |
| 1      | `'e'`  |
| 2      | `'l'`  |
| 3      | `'l'`  |
| 4      | `'o'`  |
| 5      | `'\n'` |
| 6      | `'\0'` |

마지막에 `\n`(줄바꿈 문자)이 포함되므로, 이후 문자열 비교나 출력 시 예상치 못한 동작이 발생할 수 있다. 
따라서 `strcspn()` 함수를 이용해 이 줄바꿈 문자를 제거해주는 것이 일반적이다.


#### 줄바꿈 제거 예시:
```c
#include <string.h>
input[strcspn(input, "\n")] = '\0';
```

## 문자열 관련 함수

### `strlen()`

```c
size_t strlen(const char* str);
```

- 문자열의 길이를 반환한다. `'\0'`은 포함되지 않는다.

```c
char msg[] = "banana";
size_t len = strlen(msg);  // 결과: 6
```

### `strcpy()` / `strncpy()`

```c
char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, size_t n);
```

- 문자열을 복사한다.
- `strcpy()`는 널 문자 포함 전체 복사, `strncpy()`는 최대 `n`개의 문자만 복사

```c
char a[10];
strcpy(a, "hi");

char b[10];
strncpy(b, "hello", 3);
b[3] = '\0';  // 주의: strncpy는 널 문자를 자동으로 넣지 않을 수 있음
```

`strncpy()`는 `src`의 길이가 `n`보다 작을 때는 `'\0'`을 복사하지만, 그렇지 않으면 복사하지 않는다.  
따라서 문자열이 항상 `'\0'`으로 끝나도록 하려면 직접 마지막에 `'\0'`을 넣어주는 것이 안전하다.


### `strcat()` / `strncat()`

```c
char* strcat(char* dest, const char* src);
char* strncat(char* dest, const char* src, size_t n);
```

- 문자열을 이어 붙이는 함수
- `strcat()`은 대상 문자열 끝에 원본 문자열을 붙인다
- `strncat()`은 최대 `n`개까지만 붙인다

```c
char buffer[20] = "Good ";
strcat(buffer, "morning");  // 결과: "Good morning"
```

버퍼란?

- 문자열이 저장되는 메모리 공간을 뜻한다.
- 예: `char buffer[20]`은 최대 19자와 `'\0'` 1자를 저장할 수 있다.
- `strcat()`은 버퍼의 크기를 넘을 경우 프로그램이 이상 동작할 수 있다.

```c
char small[10] = "abc";
strcat(small, "123456789");  // 위험: 공간 부족
```

### `strcmp()` / `strncmp()`

```c
int strcmp(const char* s1, const char* s2);
int strncmp(const char* s1, const char* s2, size_t n);
```

- 두 문자열을 비교한다.
- 같으면 0, 사전순으로 앞서면 음수, 뒤면 양수를 반환

```c
char pw1[] = "abcd";
char pw2[] = "abcd";

if (strcmp(pw1, pw2) == 0) {
    printf("문자열이 같습니다.\n");
}
```

### `strchr()` / `strstr()`

```c
char* strchr(const char* str, int c);
char* strstr(const char* haystack, const char* needle);
```

- `strchr()`는 특정 문자의 위치를 찾는다.
- `strstr()`는 특정 문자열을 포함하는 위치를 찾는다.

```c
char text[] = "hello world";
char* p1 = strchr(text, 'w');
char* p2 = strstr(text, "world");
```

> 이 정도가 자주 사용하는 대표적인 문자열 관련 함수들이다.  
> 이 함수들은 정확하게 이해하고, 자주 사용하면서 익히는 것이 중요하다.  
> 이 외에도 문자열 관련 함수는 많지만 필요할 때마다 문서를 참고해 사용하는 습관을 들이면 충분하다.

## 문자열과 포인터

```c
char* msg = "hi";
printf("%c\n", msg[0]);      // 'h'
printf("%c\n", *(msg + 1));  // 'i'
```

여기서 "hi"는 문자열 리터럴이다.  
문자열 리터럴은 프로그램 실행 중 변경할 수 없는 읽기 전용 메모리 영역에 저장되며 대부분의 시스템에서 수정하려고 하면 오류(또는 정의되지 않은 동작)가 발생한다.

```c
char* str = "hi";
str[0] = 'b';   // 위험: 문자열 리터럴 수정 시 오류 가능성
```

만약 문자열 내용을 바꾸고 싶다면 문자 배열로 복사해서 사용해야 한다:

```c
char str[] = "hi";
str[0] = 'b';  // 안전: 복사된 배열이므로 수정 가능
```

## 문자열은 왜 중요한가?

문자열은 사용자 입력, 메시지 처리, 파일 이름, 오류 로그 등 거의 모든 프로그램에서 필수적으로 사용된다.  
또한 배열과 포인터 개념이 종합적으로 담겨 있어 프로그래밍 실력을 키우는 데 매우 중요하다.

C 언어는 다양한 문자열 함수를 제공하지만 직접 문자열 함수를 구현해보는 것은 배열과 포인터를 심화 학습할 수 있는 좋은 훈련이 된다.

## 정리

* 문자열은 `char` 배열이며, 반드시 `\0`으로 끝난다.
* `scanf`는 공백 전까지, `fgets`는 한 줄 전체를 입력받을 수 있다.
* 문자열 비교는 `strcmp`, 복사는 `strcpy`, 연결은 `strcat`을 사용한다.
* 입력 시 개행 문자 제거(`\n`)에 주의해야 한다.
* 문자열은 포인터처럼 다루지만 수정 가능 여부를 고려해야 한다.