# 13. 동적 메모리 할당 (Dynamic Memory Allocation)

지금까지는 배열을 선언할 때 크기를 항상 고정된 상수값으로 정해주었다. 예를 들어:

```c
int scores[100];
```

이렇게 하면 최대 100개의 점수를 저장할 수 있지만, 실제로는 10개만 필요할 수도 있고 1000개가 필요할 수도 있다. 배열의 크기를 컴파일 타임에 미리 정해야 하다 보니 공간 낭비나 공간 부족 문제가 생긴다.

또한 사용자로부터 입력받은 값을 기준으로 배열 크기를 지정하고 싶을 때는 기존 방식으로는 불가능하다.

이러한 문제를 해결하기 위해 C에서는 프로그램이 실행 중일 때(runtime) 메모리를 확보할 수 있는 기능, 즉 동적 메모리 할당을 제공한다. 이 기능은 특히 다음과 같은 상황에서 유용하다:

* 사용자로부터 입력받은 값에 따라 크기가 달라지는 배열이 필요한 경우
* 크기가 정해지지 않은 데이터 구조(예: 연결 리스트, 트리)를 구현할 때
* 메모리를 재사용하거나 해제하여 자원을 절약하고 싶을 때

예시:

```c
int* pa_scores = (int*)malloc(sizeof(int) * user_input_count);
```

이처럼 메모리 크기를 실행 중에 정할 수 있다는 점이 동적 메모리의 핵심이다.

## 동적 메모리 할당 함수들

C 표준 라이브러리는 `stdlib.h` 헤더 파일을 통해 다양한 메모리 관리 함수를 제공한다.

### `malloc`: 초기화되지 않은 메모리 할당

```c
void* malloc(size_t size);
```

* `size` 바이트만큼의 메모리를 할당한다.
* 성공하면 해당 메모리의 시작 주소를 반환하고, 실패하면 `NULL`을 반환한다.
* 반환형이 `void*`이므로 사용할 자료형에 맞게 형변환(type casting) 해야 한다.

예시:

```c
int* pa_numbers = (int*)malloc(sizeof(int) * 5);
if (pa_numbers == NULL)
{
    // 실패 처리
}
```

### `calloc`: 0으로 초기화된 메모리 할당

```c
void* calloc(size_t num, size_t size);
```

* `num`개의 요소를 각각 `size` 바이트 크기로 할당한다.
* `malloc`과 다르게, 할당된 모든 메모리를 0으로 초기화한다.

예시:

```c
float* pa_scores = (float*)calloc(3, sizeof(float));
if (pa_scores == NULL)
{
    // 실패 처리
}
```

### `realloc`: 메모리 크기 재조정

```c
void* realloc(void* ptr, size_t new_size);
```

* 기존에 `malloc`이나 `calloc`으로 할당한 메모리를 새로운 크기로 재조정한다.
* 메모리 재배치가 필요한 경우, 새로운 위치에 데이터를 복사하고 이전 메모리를 해제한다.

예시:

```c
int* pa_values = (int*)malloc(sizeof(int) * 3);
if (pa_values == NULL)
{
    // 실패 처리
}

int* pa_temp = (int*)realloc(pa_values, sizeof(int) * 6);
if (pa_temp != NULL)
{
    pa_values = pa_temp;
}
```

### `free`: 메모리 해제

```c
void free(void* ptr);
```

* `malloc`, `calloc`, `realloc`으로 할당한 메모리를 해제한다.
* `free`된 메모리 영역은 더 이상 접근하면 안 된다.

## 메모리 해제와 관리 (free의 중요성)

동적 메모리 할당은 매우 유용하지만, 사용자가 직접 메모리를 해제해줘야 한다는 점이 가장 중요하다. `malloc`이나 `calloc`, `realloc`으로 확보한 메모리는 자동으로 해제되지 않는다.

즉, 사용이 끝난 뒤 `free()` 함수를 호출하지 않으면 해당 메모리가 계속 점유된 상태로 남아 있게 된다. 이것을 메모리 누수(memory leak) 라고 한다.

### 왜 free가 중요한가?

* 컴퓨터의 메모리는 유한하다. 프로그램이 메모리를 계속 사용하면서도 반환하지 않으면 언젠가는 시스템 자원이 고갈된다.
* 반복적으로 동적 할당을 하면서 `free`를 하지 않으면 점점 프로그램이 느려지고, 결국 강제 종료될 수 있다.
* 시스템 자원을 효율적으로 사용하고, 예측 가능한 프로그램을 만들기 위해서는 꼭 사용한 메모리를 직접 해제해야 한다.

> free는 항상 호출자의 책임이다.
> 어떤 함수가 동적 메모리를 할당해서 반환했다면, 그 메모리를 마지막으로 사용하는 쪽(호출자)이 반드시 `free()`를 명시적으로 호출해야 한다.
> 내부에서 할당하고 내부에서 해제해버리면 호출자가 해당 메모리를 사용할 수 없거나 실수로 이중 해제를 하게 될 수 있다.

### 좋은 습관 1: free를 먼저 작성하자

동적 할당을 사용할 때는 `malloc`을 작성한 뒤 잊지 않고 `free()`까지 작성하는 것이 핵심이다. 그런데 초보자일수록 `malloc`만 쓰고 해제를 잊기 쉽다. 이를 방지하는 좋은 방법은 할당할 포인터를 선언하자마자 가장 아래에 `free()`를 먼저 써두는 습관이다.

```c
int* pa_data = (int*)malloc(sizeof(int) * 10);

// 그 다음에 본격적으로 동적 메모리 사용 코드를 작성

free(pa_data); // <- 먼저 free 구문을 작성
```

이렇게 하면 메모리를 할당할 때마다 해제도 함께 고려하게 되고 실수로 빠뜨릴 위험이 줄어든다.

### 좋은 습관 2: free 후 NULL 대입하기

메모리를 해제한 뒤에도 포인터 변수는 원래의 주소를 그대로 기억하고 있기 때문에 실수로 접근하게 되면 정의되지 않은 동작(undefined behavior) 이 발생한다.

그래서 다음과 같이 `NULL`을 대입해주는 것이 안전하다:

```c
free(pa_data);
pa_data = NULL;
```

이렇게 하면 나중에 해당 포인터를 실수로 다시 접근하거나 이중 해제하는 것을 막을 수 있다.

### 좋은 습관 3: 명명 규칙을 통해 실수를 줄이기

* 동적 메모리로 할당된 포인터 변수에는 `pa_`접두사를 붙여서 Pointer to Allocated의 의미를 명확히 표현하자.
* `malloc`, `calloc`, `realloc`을 사용하는 함수라면 함수 이름 뒤에 `_malloc`접미사를 붙여서 내부에서 동적 메모리를 사용하는 함수임을 명확히 하자.

이는 각각 `free`할 책임이 있는 사용자가 `free()`를 빼먹는 일이 줄어들고 코드 가독성과 유지 보수성을 높이기 위함이다.

## 자주 하는 실수들

* `malloc` 후 반환값을 확인하지 않음 (`NULL` 체크 누락)
* `free`를 하지 않음 → 메모리 누수(leak) 발생
* 이미 `free`한 메모리를 또 사용하거나 해제함 → 정의되지 않은 동작(undefined behavior)
* 타입 크기를 고려하지 않고 `malloc(n)`처럼 작성함 → 반드시 `sizeof(type) * n`
* `realloc` 후 반환된 주소를 바로 같은 포인터에 덮어씀 → 실패 시 메모리 손실

## 정리

* `malloc`, `calloc`, `realloc`, `free`로 런타임에 메모리를 관리한다.
* `free`는 반드시 호출하고, 그 후에는 포인터를 `NULL`로 초기화하자.
* 동적 변수는 `pa_` 접두사로 명확하게 구분하자.
* 메모리 누수, 이중 해제, NULL 체크 누락은 치명적인 버그로 이어진다.
* 메모리를 쓰기 전에 항상 할당 여부를 확인하자.