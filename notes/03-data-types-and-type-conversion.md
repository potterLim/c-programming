# 3. 자료형과 형 변환
## 출력 서식자 (Format Specifiers)

앞에서 `printf()`를 이용해 값을 출력한 적이 있다.  
이때 사용하는 `%d`, `%f` 같은 기호를 서식자(format specifier)라고 한다.  
서식자는 변수의 자료형에 맞게 선택해야 한다.

| 자료형   | 서식자 | 예시                   |
| -------- | ------ | ---------------------- |
| `int`    | `%d`   | `printf("%d\n", a);`   |
| `float`  | `%f`   | `printf("%f\n", b);`   |
| `double` | `%lf`  | `printf("%lf\n", pi);` |
| `char`   | `%c`   | `printf("%c\n", ch);`  |

실수형은 소수점 자리수를 지정할 수도 있다.

```c
float pi = 3.14159f;

printf("%.2f\n", pi);   // 3.14
```

> 이 외의 다양한 서식자가 궁금하다면 Microsoft에서 제공하는 공식 문서를 참고하자:
> [바로가기](https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170)

서식자를 잘못 쓰면 경고가 뜨거나 엉뚱한 값이 출력될 수 있으니 꼭 자료형에 맞게 써야 한다.


## 자료형의 종류

C언어에서 대표적으로 자주 쓰이는 자료형은 앞서 소개했다. 이제는 C언어의 모든 기본 자료형을 전체적으로 정리해 보자.

### 정수형 (Integer Types)

| 자료형                        | 부호 가능 여부        | 설명            |
| ----------------------------- | --------------------- | --------------- |
| `char`                        | ✅ signed / unsigned | 문자, 작은 정수 |
| `short` / `short int`         | ✅ signed / unsigned | 작은 정수       |
| `int`                         | ✅ signed / unsigned | 기본 정수형     |
| `long` / `long int`           | ✅ signed / unsigned | 큰 정수         |
| `long long` / `long long int` | ✅ signed / unsigned | 더 큰 정수      |

> 정수형의 기본 부호는 signed이며 `signed`는 생략 가능하다.

### 부호 없는 정수형 (Unsigned Integer Types)

| 자료형               | 설명                   |
| -------------------- | ---------------------- |
| `unsigned char`      | 부호 없는 8비트 정수   |
| `unsigned short`     | 부호 없는 16비트 정수  |
| `unsigned int`       | 부호 없는 32비트 정수  |
| `unsigned long`      | 큰 부호 없는 정수      |
| `unsigned long long` | 매우 큰 부호 없는 정수 |


### 실수형 (Floating-Point Types)

| 자료형        | 설명                                |
| ------------- | ----------------------------------- |
| `float`       | 낮은 정밀도의 부동소수점            |
| `double`      | 상대적으로 높은 정밀도의 부동소수점 |
| `long double` | 매우 높은 정밀도의 부동소수점       |

## 형 변환 (Type Conversion)
### 암시적 형 변환 (Implicit Type Conversion)

암시적 형 변환이란, 자료형이 서로 다른 값끼리 연산을 할 때 C언어가 자동으로 형을 변환하는 것이다.  

예를 들어 `int`와 `float`을 더하면, C언어는 자동으로 `int`를 `float`으로 바꿔서 계산한다.

```c
int count = 3;
float average = 1.5f;

float result = count + average;  // count는 자동으로 float으로 변환됨
```

하지만 아무 때나 자동으로 형을 바꿔주는 건 아니다.  
자료형의 크기나 정밀도에 따라 손실 없이 바뀔 수 있을 때만 자동으로 일어난다.

예를 들어:
- `int` → `float`: 정수에 소수점만 붙으므로 안전
- `float` → `double`: 정밀도만 높아지고 값 손실이 없으므로 안전
- `char` → `int`: 더 넓은 범위를 표현할 수 있어 문제 없음

하지만 반대로,
- `float` → `int`: 소수점 이하가 잘릴 수 있음
- `double` → `float`: 정밀도가 낮아지며 일부 소수점 정보가 사라질 수 있음
- `int` → `char`: 큰 값이 잘릴 수 있음

이런 경우엔 자동 변환이 일어나지 않고, 프로그래머가 직접(명시적으로) 형변환을 해줘야 한다.

> 정확히 말하면 C언어 자체가 형을 바꾸는 게 아니라 컴파일러가 자동으로 형 변환을 수행한다.  
> 하지만 지금은 "C언어가 바꿔준다"고 이해해도 괜찮다.

### 명시적 형 변환 (Explicit Type Conversion)

명시적 형 변환은 프로그래머가 직접 자료형을 변환하도록 명령하는 것이다.  
이 과정을 캐스팅(casting)이라고 한다.

형태는 `(자료형)`을 값 앞에 붙인다.

```c
double pi = 3.14159;
int truncated = (int)pi;  // 소수점 이하 잘리고 3만 저장됨
```

이렇게 하면 자료형이 강제로 바뀌고 경우에 따라 소수점이 잘리거나 값이 손실될 수 있다.  
그렇기 때문에 명시적 형 변환은 쓸 때 항상 조심해야 한다.


### 형 변환의 주의점

형 변환은 편리하지만 다음과 같은 점을 주의해야 한다.

- 정밀도 손실  
    float → int로 바꾸면 소수점 이하가 잘린다  
    double → int도 마찬가지다.

    ```c
    float pi = 3.14f;
    int truncated = (int)pi;  // 소수점 이하 잘리고 3만 저장됨
    ```

- 자료 손실  
    작은 자료형에 큰 값을 넣으면 값이 망가질 수 있다.  

    ```c
    int big = 100000;
    char small = (char)big;  // small에는 의도와 다른 값이 들어감
    ```

- 혼합 연산에서 예상치 못한 결과:  
    `int` 끼리 먼저 연산된 결과를 `float`에 넣으면 이미 정수 결과가 들어간다.

    ```c
    int total_score = 3;
    int number_of_students = 2;
    float average = total_score / number_of_students;  // 결과는 1.0
    ```

    이런 경우엔 아래처럼 미리 형 변환을 하는 것이 정확하다.

    ```c
    float average = total_score / (float)number_of_students;  // 결과는 1.5
    ```

## 정리

* 자료형마다 출력 서식자(`%d`, `%f`, `%c`)를 정확히 맞춰야 한다.
* 암시적 형 변환은 자동으로, 명시적 형 변환은 `(type)`을 사용해 직접 수행한다.
* 크기가 큰 자료형으로의 변환은 안전하지만, 작은 자료형으로 바꾸면 값이 손실될 수 있다.
* `float/int` 혼합 연산 시 형 변환이 누락되면 의도치 않은 결과가 나온다.
* 형 변환은 오류의 원인이 될 수 있으므로 항상 주의해야 한다.