# 9. 배열과 다차원 배열 (Arrays and Multidimensional Arrays)

## 배열이란?

프로그래밍에서는 같은 종류의 데이터를 여러 개 저장하고 싶을 때가 있다.  
그럴 때 사용하는 것이 바로 배열(array) 이다.

배열 안에 저장된 각각의 값을 요소(element) 라고 부른다.  
각 요소는 배열에서의 위치를 나타내는 번호 즉, 인덱스(index) 를 사용해 접근한다.  
인덱스는 0부터 시작한다는 점에 주의해야 한다.

```c
int scores[5];  // 정수 5개를 저장할 수 있는 배열
```

```c
scores[0] = 90;  // 첫 번째 요소
scores[1] = 85;  // 두 번째 요소
```

- `scores`라는 배열은 5개의 요소를 가진다.
- 각 요소는 `scores[0]`, `scores[1]`, ..., `scores[4]`처럼 인덱스를 통해 접근한다.
- `scores[0] = 90;`은 첫 번째 요소에 90을 저장한다는 의미이다.

## 배열 선언과 초기화

### 1. 선언만 하기

```c
int numbers[3];  // 정수 3개를 담을 수 있는 배열
```

### 2. 선언과 동시에 초기화

```c
int numbers[3] = {10, 20, 30};
```

`{...}` 안에 초기값을 넣을 수 있으며, 초기값 개수는 배열 크기보다 작거나 같아야 함

### 3. 크기 생략

```c
int numbers[] = {10, 20, 30};  // 컴파일러가 크기를 자동 계산함
```

## 배열의 값 출력

배열의 모든 요소를 출력하려면 반복문과 함께 사용하는 것이 일반적이다.

```c
#include <stdio.h>

int main(void)
{
    int scores[5] = {95, 88, 76, 64, 100};

    for (int i = 0; i < 5; ++i) {
        printf("%d번째 점수: %d\n", i + 1, scores[i]);
    }

    return 0;
}
```

## 배열의 특징

- 같은 자료형만 저장 가능
- 크기는 고정 (선언 시 정해진 크기 이상으로 추가 불가)
- 인덱스는 항상 0부터 시작

## 자주 하는 실수들

- 배열 전체를 `=`으로 대입하려고 시도 (`scores = {1,2,3}`는 컴파일 오류)
- 배열의 마지막 요소(예: 5개의 요소일 경우)를 `scores[5]`라고 잘못 접근함 (정확한 마지막 인덱스는 4)
- 배열의 첫 번째 요소가 `scores[1]`이라고 착각함 (정확한 첫 번째 인덱스는 0)

## 다차원 배열 (Multidimensional Arrays)

### 2차원 배열

행(row)과 열(column)을 가지는 표 형태의 배열이다.

```c
int matrix[2][3];  // 2행 3열 배열
```

### 초기화

```c
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

인덱스 접근은 `matrix[행][열]` 방식

```c
int value = matrix[1][2];  // 2행 3열의 값 (6)
```

### 2차원 배열 출력 예시

```c
#include <stdio.h>

int main(void)
{
    int table[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("table[%d][%d] = %d\n", i, j, table[i][j]);
        }
    }

    return 0;
}
```

### 배열과 반복문의 결합

배열을 사용할 땐 반복문을 거의 항상 같이 쓴다.  
특히 다차원 배열은 중첩 반복문을 사용해야 한다.

```c
int arr[5] = {1, 2, 3, 4, 5};        // 1차원 배열
int matrix[2][3] = {                 // 2차원 배열
    {1, 2, 3}, 
    {4, 5, 6}
};  

for (int i = 0; i < 5; ++i) {
    printf("arr[%d]: %d\n", i, arr[i]); // 1차원 배열 출력
}

for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
        printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]); // 2차원 배열 출력
    }
}
```

### 배열을 함수에 전달하기

배열도 함수의 매개변수로 전달할 수 있다.  
예를 들어 배열의 평균을 계산하는 함수를 만들 수 있다:

```c
float get_average(int scores[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += scores[i];
    }

    return sum / (float)size;
}
```

#### 사용 예시:

```c
int main(void)
{
    int scores[5] = {85, 90, 78, 92, 88};
    float avg = get_average(scores, 5);

    printf("평균 점수: %.2f\n", avg);
    return 0;
}
```

### 배열을 함수에 전달하면 원본 배열도 바뀐다

C언어에서 함수의 매개변수는 값이 복사되어 전달된다고 배웠다.  
하지만 배열을 매개변수로 전달받아 함수에서 값을 바꾸면 원본의 값이 바뀐다.

```c
void fill_zero(int arr[], int size)
{
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}
```

```c
int main(void)
{
    int numbers[3] = {1, 2, 3};
    fill_zero(numbers, 3);

    for (int i = 0; i < 3; ++i) {
        printf("%d ", numbers[i]);  // 출력: 0 0 0
    }

    return 0;
}
```

함수 안에서 `arr[i]`를 바꾸면 `main()`의 `numbers[i]`도 바뀐다.

## 정리

* 배열은 동일한 자료형 데이터를 순차적으로 저장하는 공간이다.
* 인덱스는 0부터 시작하며, 선언된 크기를 초과해 접근하면 오류가 발생한다.
* 2차원 배열은 행과 열로 구성되며, 중첩 반복문을 사용해 처리한다.
* 배열은 함수로 전달 시 원본에 영향을 미친다 (주소 전달).
* 함수에서 배열 값을 변경하면 호출한 쪽의 데이터도 바뀐다.