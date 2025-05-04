## 6. 반복문 (Loops)

### 반복문의 개념과 필요성

프로그래밍에서 반복문은 특정 코드 블록을 여러 번 실행할 때 사용한다.  
같은 작업을 여러 번 반복할 수 있도록 하여 코드의 효율성과 가독성을 높여준다.

반복문이 없으면 동일한 코드를 여러 줄 복사해서 써야 하므로 유지보수에 불리하다.  
C 언어는 대표적으로 `while`, `do - while`, `for` 세 가지 반복문을 제공한다.

### while 문

`while` 문은 조건이 참인 동안 반복해서 실행된다.

```c
while (조건식) {
    // 조건이 참일 때 반복 실행
}
```

#### 예시: 비밀번호가 맞을 때까지 계속 입력 받기

```c
#include <stdio.h>

int main(void) {
    int password = 1234;
    int input = 0;

    while (input != password) {
        printf("비밀번호를 입력하세요: ");
        scanf("%d", &input);
    }

    printf("접속 성공!\n");

    return 0;
}
```

조건을 먼저 검사하므로 처음부터 조건이 거짓이면 한 번도 실행되지 않는다.

#### 예시:
```c
int count = 0;

while (count < 3) {
    printf("반복 중입니다: %d\n", count);
    ++count;
}
```

### do - while 문

`do - while` 문은 조건을 나중에 검사하므로 무조건 한 번은 실행된다.

```c
do {
    // 실행할 코드
} while (조건식);
```

#### 예시: 최소 한 번은 숫자를 입력받고, 양수를 입력할 때까지 반복

```c
#include <stdio.h>

int main(void) {
    int number;

    do {
        printf("양수를 입력하세요: ");
        scanf("%d", &number);
    } while (number <= 0);

    printf("입력한 양수: %d\n", number);

    return 0;
}
```

### for 문

`for` 문은 반복 횟수가 명확히 정해져 있을 때 사용하기 좋다.  
초기식, 조건식, 증감식 세 부분으로 구성된다.

```c
for (초기식; 조건식; 증감식) {
    // 반복할 코드
}
```

#### 예시: 출석 체크를 5명에게 반복적으로 하기

```c
#include <stdio.h>

int main(void) {
    int student_number;

    for (int i = 0; i < 5; ++i) {
        printf("%d번째 학생 출석번호를 입력하세요: ", i + 1);
        scanf("%d", &student_number);
        printf("출석 체크 완료: %d번 학생\n", student_number);
    }

    return 0;
}
```

> 실행 문장이 한 줄뿐일 경우 중괄호 `{}`를 사용하지 않아도 프로그램 동작에는 문제가 없지만 반드시 중괄호 `{}`를 사용할 것. 중괄호 생략은 실수로 인한 버그를 유발할 수 있음.

### Tip: 반복문 선택 기준

- while 문: 반복 횟수를 알 수 없고, 실행 중에 조건이 정해지는 경우  
  → 예: 사용자 입력을 검사해서 종료할지 결정할 때

- do - while 문: 최소 한 번은 실행되어야 하는 경우  
  → 예: 메뉴를 한 번은 보여주고 종료 조건을 확인할 때

- for 문: 반복 횟수가 명확할 때  
  → 예: “5번 반복”, “10명 입력받기” 등
 
> 반복 횟수를 실행 전에 알고 있다면 `for` 문을, 사용자의 행동에 따라 종료 조건이 바뀌는 경우에는 `while` 또는 `do - while` 문을 사용하는 것이 가독성과 유지보수 측면에서 유리하다.


### 반복 제어 키워드: break, continue

- `break`: 반복문을 즉시 종료
- `continue`: 아래 코드를 건너뛰고 다음 반복으로 이동

#### 예시: 0이 입력되면 반복 종료

```c
#include <stdio.h>

int main(void) {
    int input;

    while (1) {
        printf("숫자를 입력하세요 (0을 입력하면 종료): ");
        scanf("%d", &input);

        if (input == 0) {
            break;
        }

        printf("입력한 숫자: %d\n", input);
    }

    return 0;
}
```

#### 예시: 홀수만 출력

```c
#include <stdio.h>

int main(void) {
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            continue;
        }

        printf("홀수: %d\n", i);
    }

    return 0;
}
```

### 중첩 반복문

반복문 안에 또 다른 반복문이 들어갈 수 있다. 이를 중첩 반복문이라고 하며 주로 표 형식의 출력이나 이중 입력 처리 등에 사용된다.

#### 예시: 1~3행, 1~2열 위치 출력

```c
#include <stdio.h>

int main(void) {
    for (int row = 1; row <= 3; ++row) {
        for (int col = 1; col <= 2; ++col) {
            printf("(%d행, %d열)\n", row, col);
        }
    }

    return 0;
}
```

### 자주 하는 실수들

- 조건을 잘못 작성해 무한 루프 발생
- `while` 또는 `for`에서 변수 증가/감소를 빼먹음
- `do - while`에서 `;`를 빼먹는 문법 오류
- `break`와 `continue`의 의미를 혼동
- 중첩 반복문에서 `중괄호 생략`으로 의도하지 않은 흐름 발생

반복문은 조건에 따라 코드를 반복 실행할 수 있게 해주는 중요한 도구다.  
`while`, `do - while`, `for` 문과 반복 제어 키워드의 특징을 정확히 이해하고 활용하자