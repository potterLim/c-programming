## 15. 비트 연산자 (Bitwise Operators)

프로그래밍을 처음 배우는 입장에서는 숫자가 이진수로 저장된다는 것부터 낯설 수 있다.  
하지만 컴퓨터는 기본적으로 0과 1만으로 데이터를 처리하기 때문에 비트 단위 연산을 이해하면 내부 동작을 깊이 있게 이해할 수 있고 성능이 중요한 영역에서는 효율적인 프로그래밍까지 가능해진다.

이 문서에서는 C 언어에서 제공하는 비트 연산자(bitwise operators)를 통해 숫자를 비트 수준에서 어떻게 조작할 수 있는지를 살펴본다.

## 비트란 무엇인가?

- 비트(bit): 컴퓨터가 다룰 수 있는 가장 작은 단위. 값은 0 또는 1.
- 바이트(byte): 8비트로 구성됨. 일반적인 문자 하나(char)가 1바이트를 차지함.

> 예: 10진수 `5`는 2진수로 `00000101` (8비트로 표현 시)

## 비트 연산자가 필요한 이유

- 하드웨어 제어 (핀, 센서, 스위치 등)
- 플래그 저장 (여러 개의 상태를 1바이트에 저장)
- 계산 최적화 (곱셈·나눗셈보다 시프트 연산이 빠름)
- 데이터 압축, 보안, 그래픽 처리 등에도 사용됨

## C의 비트 연산자 종류

| 연산자 | 설명 | 예시 |
| ------ | ------------------------- | -----------------|
| `&`    | AND: 둘 다 1일 때 1       | `a & b`          |
| `\|`   | OR: 하나라도 1이면 1      | `a \| b`         |
| `^`    | XOR: 서로 다를 때 1       | `a ^ b`          |
| `~`    | NOT: 비트 반전            | `~a`             |
| `<<`   | 왼쪽 시프트 (2배 곱하기)  | `a << 1` (a * 2) |
| `>>`   | 오른쪽 시프트 (2로 나누기)| `a >> 1` (a / 2) |

## 비트 연산 예제 (8비트 기준 시각화)

### AND (`&`)
```c
int a = 5;  // 00000101
int b = 3;  // 00000011
int c = a & b;  // 00000001 => 1
```

### OR (`|`)
```c
int c = a | b;  // 00000111 => 7
```

### XOR (`^`)
```c
int c = a ^ b;  // 00000110 => 6
```

### NOT (`~`)
```c
int a = 5;       // 00000101
int c = ~a;      // 11111010 => -6 (2의 보수 방식)
```

### Shift (`<<`, `>>`)
```c
int a = 4;       // 00000100
int b = a << 1;  // 00001000 => 8 (곱하기 2)
int c = a >> 1;  // 00000010 => 2 (나누기 2)
```
## 주의사항 및 팁

- `>>` 연산은 음수에서 구현마다 결과가 다를 수 있음
- 괄호 필수: 연산자 우선순위가 낮기 때문에 `if ((x & 1) == 1)`처럼 괄호로 명확히 표현해야 함
- `unsigned` 정수형으로 비트 연산하는 것이 안전함

## 마무리 정리

비트 연산자는 처음에는 낯설지만, 다음과 같은 상황에서 매우 유용하다:

- 속도가 중요한 경우
- 하드웨어 상태를 다룰 때
- 여러 상태를 하나의 값으로 표현하고 싶을 때 (플래그)

비트라는 개념은 처음에는 낯설 수 있다. 하지만 그 원리를 이해하고, 필요할 때마다 차근차근 활용해보며 반복적으로 고민하다 보면 점점 더 익숙해지고 자연스러워질 것이다.