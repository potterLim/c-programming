## 14. 파일 입출력 (File I/O)

지금까지는 사용자 입력을 `scanf`로 받고, 출력을 `printf`로 했기 때문에 프로그램이 종료되면 모든 데이터가 사라졌다. 하지만 프로그램 실행과는 독립적으로 데이터를 영구 저장하려면 파일 입출력이 필요하다. 다음과 같은 경우에 파일이 유용하다:

* 사용자 입력을 저장해야 할 때
* 많은 데이터를 반복해서 읽고 써야 할 때
* 데이터를 다른 프로그램과 공유해야 할 때

파일은 하드디스크나 SSD에 저장되기 때문에, 프로그램이 종료된 후에도 데이터가 유지된다.

## 파일 입출력 준비: `FILE*`과 `fopen`

파일을 열기 위해선 `FILE` 포인터를 사용한다. 이 포인터는 C 표준 라이브러리에서 제공하는 구조체로, 파일 스트림(stream)을 가리킨다.

### `FILE* fopen(const char* filename, const char* mode);`

* `filename`: 열고자 하는 파일 이름 또는 경로
* `mode`: 파일을 어떤 방식으로 열지 지정하는 문자열

| 모드 | 설명                                             |
| ---- | ------------------------------------------------ |
| "r"  | 읽기 전용 (파일이 존재해야 함)                   |
| "w"  | 쓰기 전용 (파일이 없으면 생성, 있으면 내용 삭제) |
| "a"  | 추가 전용 (파일 끝에 이어씀, 없으면 생성)        |
| "r+" | 읽기 + 쓰기 (파일 존재해야 함)                   |
| "w+" | 읽기 + 쓰기 (기존 내용 삭제)                     |
| "a+" | 읽기 + 추가 (파일 끝에 이어씀, 없으면 생성)      |

> 텍스트 파일은 "r", "w", "a" / 바이너리 파일은 "rb", "wb", "ab"

### 파일 열기 실패 예시

```c
FILE* fp = fopen("data.txt", "r");
if (fp == NULL)
{
    printf("파일 열기 실패\n");
    return 1;
}
```

## 파일에 쓰기

### 형식 지정 출력: `fprintf`

파일에 형식을 지정해서 데이터를 출력할 때는 `fprintf` 함수를 사용한다.  
형식 지정자(`%d`, `%s` 등)를 활용할 수 있어 다양한 데이터 출력을 처리할 수 있다.

```c
int fprintf(FILE* stream, const char* format, ...);
```

```c
FILE* fp = fopen("scores.txt", "w");

int score1 = 95;
int score2 = 88;

fprintf(fp, "%d\n", score1);
fprintf(fp, "%d\n", score2);
```

### 문자열 출력: `fputs`

문자열 전체를 그대로 출력할 때는 `fputs`를 사용한다.  
자동으로 개행되지 않기 때문에 줄바꿈이 필요하면 `\n`을 문자열에 포함해야 한다.

```c
int fputs(const char* str, FILE* stream);
```

```c
fputs("End of scores.\n", fp);
```

### 문자 출력: `fputc`

문자 하나를 출력할 때는 `fputc`를 사용한다.  
문자 리터럴 또는 ASCII 값을 입력받아 해당 문자를 출력한다.

```c
int fputc(int character, FILE* stream);
```

```c
fputc('!', fp);
```

### 결과 (`scores.txt` 파일 내용)

```
95
88
End of scores.
!
```

## 파일에서 읽기

### 값 단위 읽기: `fscanf`

`fscanf`는 `scanf`처럼 형식을 지정하여 파일에서 값을 읽어오는 함수이다.  
공백이나 줄바꿈을 기준으로 데이터를 분리해 읽는다.

```c
int fscanf(FILE* stream, const char* format, ...);
```

```c
FILE* fp = fopen("scores.txt", "r");

int score = 0;
fscanf(fp, "%d", &score);
printf("첫 번째 점수: %d\n", score);
```

여러 값을 반복해서 읽는 경우는 반환값을 조건으로 사용한다:

```c
int score = 0;
while (fscanf(fp, "%d", &score) == 1)
{
    printf("읽은 점수: %d\n", score);
}
```

> 파일 끝에 도달하거나 읽기에 실패하면 반환값이 1이 아닌 값이 된다. 이 값을 검사해야 무한 루프를 방지할 수 있다.

### 줄 단위 읽기: `fgets`

`fgets`는 한 줄 전체를 문자열로 읽는 함수이다.  
개행 문자(`\n`)까지 포함해서 저장되며, 줄 단위로 텍스트를 처리할 때 적합하다.

```c
char* fgets(char* str, int n, FILE* stream);
```

```c
char buffer[100];
fgets(buffer, sizeof(buffer), fp);
```

> 문자열 비교나 출력 전에는 개행 문자를 제거해야 할 수 있다.

```c
buffer[strcspn(buffer, "\n")] = '\0';
```

줄 단위로 반복해서 읽기:

```c
char buffer[100];
while (fgets(buffer, sizeof(buffer), fp) != NULL)
{
    printf("줄 내용: %s\n", buffer);
}
```

### 문자 단위 읽기: `fgetc`

`fgetc`는 파일에서 문자 하나를 읽는 함수이다.  
`EOF`(파일 끝)까지 한 글자씩 읽을 수 있어, 문자 단위 분석이 가능하다.

```c
int fgetc(FILE* stream);
```

```c
int ch = fgetc(fp);
if (ch != EOF)
{
    printf("읽은 문자: %c\n", ch);
}
```

> 반복문으로 `fgetc`를 사용하는 경우, 반드시 `EOF`를 검사하여 종료 조건을 설정해야 한다.


## 파일 닫기: `fclose`

파일 작업이 끝나면 반드시 닫아야 한다.

### `int fclose(FILE* stream);`

* `stream`은 `fopen`으로 연 파일 포인터
* 성공하면 0, 실패하면 EOF 반환

```c
fclose(fp); // 파일을 다 썼으면 꼭 닫아야 함
```

위의 예제들에서는 `fclose`에 대해 설명하기 전이므로 `fclose()` 호출을 생략했다.  
하지만 실제 프로그램에서는 항상 파일을 닫아야 한다는 점을 명심하자.


> 마치 동적 메모리를 `malloc`하면 반드시 `free`로 해제해야 하듯, 파일을 `fopen`하면 반드시 `fclose`로 닫아야 한다. 가능하면 파일을 열자마자 `fclose()`를 미리 작성해두는 습관을 들이자.

## 자주 하는 실수들

* `fopen()` 실패 체크 누락 → NULL 접근 오류 발생
* `fclose()` 호출 누락 → 디스크 기록 누락, 리소스 누수
* 모드 오용 → 읽기로 열었는데 파일 없음 등
* `fgets()` 사용 후 `\n` 제거 안함 → 문자열 비교 실패
* `fscanf()` 반복 사용 시 반환값 확인 안함 → 무한 루프 발생

## 정리

* 파일 작업은 `FILE*`, `fopen`, `fclose`를 기본으로 한다.
* `fprintf`, `fscanf`, `fgets`, `fputc` 등을 사용하여 파일을 읽고 쓴다.
* 파일을 열었으면 반드시 닫고(`fclose`), 실패 시 NULL 체크가 필수다.
* 줄 입력 후 개행 제거(`\n`)를 꼭 고려해야 한다.