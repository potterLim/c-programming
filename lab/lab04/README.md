# LAB04: 배열 유틸리티 (Array Utilities)

## 🧾 과제 개요

이번 과제에서는 정수 배열을 기반으로 다양한 통계 및 조작 기능을 구현합니다.  
배열 내에서 특정 숫자의 위치를 찾거나 최대/최솟값의 인덱스를 구하고,  
배열에 원소를 삽입하거나 삭제하는 등의 기능을 함수 단위로 구현합니다.

- 특정 숫자의 첫 번째 등장 위치 찾기
- 특정 숫자의 마지막 등장 위치 찾기
- 배열의 최댓값 위치 찾기
- 배열의 최솟값 위치 찾기
- 배열 내 요소의 0 존재 여부 확인
- 특정 위치에 숫자 삽입
- 특정 위치에서 숫자 제거

## 🎯 과제 목표

- 배열과 반복문을 자유롭게 다룰 수 있어야 합니다.
- 조건문을 활용한 탐색 및 판별 코드를 작성할 수 있어야 합니다.
- 배열의 순서를 보존하며 안전하게 삽입/삭제하는 로직을 구현할 수 있어야 합니다.

## 📁 제공 파일

| 파일명     | 설명                                         |
|------------|----------------------------------------------|
| `array.h`  | 함수 원형 정의 (수정 금지)                   |
| `array.c`  | 여러분이 직접 작성할 파일                    |
| `main.c`   | 자동 채점용 테스트 코드 (수정 금지)         |

## 🧩 구현할 함수 목록

```c
int get_index(const int arr[], int count, int num);
int get_last_index(const int arr[], int count, int num);
int get_max_index(const int arr[], int count);
int get_min_index(const int arr[], int count);
int has_zero(const int arr[], int count);
int insert_at(int arr[], int count, int value, int index);
int remove_at(int arr[], int count, int index);
```

## 💡 구현 시 유의사항

- `count`는 현재 배열에서 사용 중인 요소의 개수입니다.  
  배열의 크기보다 작을 수 있으며, 배열 뒤쪽의 남은 공간은 무시해도 됩니다.
- 언제나 올바른 'count'가 전달된다고 가정해도 좋습니다.
- `TRUE`와 `FALSE`는 `array.h` 헤더 파일에서 다음과 같이 정의되어 있습니다.
    ```c
    #define TRUE (1)
    #define FALSE (0)
    ```

## 📌 함수별 구현 조건

- `get_max_index()`  
  - 동일한 최댓값이 여러 개 있다면 가장 앞쪽 인덱스를 반환합니다.  
  - `count`가 0이면 `-1`을 반환해야 합니다.

- `get_min_index()`  
  - 동일한 최솟값이 여러 개 있다면 가장 앞쪽 인덱스를 반환합니다.  
  - `count`가 0이면 `-1`을 반환해야 합니다.

- `get_index()` / `get_last_index()`  
  - 찾는 값이 없으면 `-1`을 반환합니다.

- `has_zero()`  
  - 배열 안에 `0`이 하나라도 있으면 `TRUE`, 없으면 `FALSE`를 반환합니다.

- `insert_at()`  
  - `index`가 유효하지 않으면 `FALSE`를 반환합니다.  
  - 요소 삽입 시 기존의 요소는 순서를 유지해야 합니다.  
  - 배열이 꽉 찬 경우는 호출되지 않는다고 가정해도 됩니다.

- `remove_at()`  
  - `index`가 유효하지 않으면 `FALSE`를 반환합니다.  
  - 삭제 후에는 남은 요소는 기존 순서를 유지해야 합니다.


## ⚙️ 빌드 및 실행 방법

```bash
gcc -o lab04.exe array.c main.c
./lab04.exe
```

> `✅ 모든 테스트를 통과했습니다.` 메시지가 출력되어야 합니다.

## 🧭 마무리 안내

- `array.h`, `main.c` 파일은 수정하지 마세요.
- 함수별로 코드를 정확하게 작성하고, 주어진 기능을 구현하세요.