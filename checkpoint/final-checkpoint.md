# C언어 최종점검

> ⚠️ **안내사항**  
> - 본 문서는 실습 문제를 포함한 최종 점검용 학습 자료입니다.  
> - **제한 시간은 100분입니다.**  
> - **모든 문제는 손으로 직접 풀어볼 것을 권장하며**, 특히 코드 작성도 실제로 써보는 것이 중요합니다.  
> - **총 15문제 중 10문제(70점) 이상을 정확히 해결했다면 매우 훌륭한 기초 프로그래밍 역량을 갖춘 것입니다.**  
> - 자신이 어느 부분에서 약한지를 파악하고 보완의 기회로 삼으세요.

## 문제 1.

C 언어에서 배열과 포인터는 밀접한 관련이 있다. 배열과 포인터의 공통점과 차이점을 설명하시오. 필요하다면 예시를 들어 설명하시오.

## 문제 2.

2차원 배열의 메모리 구조에 대해 설명하시오. `int arr[2][3]`이라는 배열이 메모리상에서 어떻게 저장되는지 서술하고, `arr[1][2]`는 어떤 위치를 의미하는지 설명하시오.

## 문제 3.

동적 메모리 할당이 필요한 이유를 실제 프로그래밍 상황 예시와 함께 설명하시오. `malloc`과 `free` 함수의 역할과 주의할 점도 함께 서술하시오.

## 문제 4.

다음 구조체 정의를 분석하고, `typedef`가 하는 역할과 구조체 변수 선언 및 초기화 방법을 예시와 함께 설명하시오.
```c
typedef struct person {
    char name[20];
    int age;
} person_t;
```

## 문제 5.

다음 프로그램의 빈칸에 들어갈 코드를 작성하고, 해당 프로그램이 어떤 기능을 수행하는지 서술하시오. (코드를 보고 의도를 분석하시오)
```c
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int n;
    int sum = 0;
    scanf("%d", &n);

    int* scores = ___________;

    /* TODO
    
    */

    printf("Average: %d\n", sum / n);

    ___________;
    return 0;
}
```

## 문제 6.

파일 입출력에서 `fgets`, `fputs`, `fscanf` 함수는 각각 어떤 상황에서 적절하게 사용되는지 비교하여 설명하시오. 또한 `fgets`와 `scanf`로 문자열을 입력받을 때 주의해야 할 차이점을 예시와 함께 설명하시오.

## 문제 7.

다음은 변수 a와 b의 8비트 이진 표현이다.
```
a = 0b10110101  
b = 0b01010101
```
비트 패턴이 위와 같다고 가정했을 때, 다음 연산에 대한 결과를 이진수 형태로 작성하시오. 결과는 공백 없이 8비트 이진수로 표기할 것.
- `a & b`의 결과
- `a | b`의 결과
- `a ^ b`의 결과

## 문제 8.

컴퓨터에서 음수를 표현하기 위해 사용하는 2의 보수(two's complement) 표현 방식에 대해 단계별로 설명하시오.
1. 어떤 절차를 거쳐 양수를 2의 보수 표현으로 바꾸는지 단계별로 설명하시오.
2. 8비트 정수형에서 -18을 2의 보수 방식으로 8비트 이진수로 쓰시오.
3. 8비트 정수형에서 표현 가능한 최댓값과 최솟값을 각각 2의 보수 방식으로 8비트 이진수로 쓰시오.
4. 2의 보수가 컴퓨터 시스템에서 가장 널리 쓰이게 된 이유를 설명하시오.

## 문제 9.

다음 배열을 매개변수로 받아 평균을 계산하는 함수를 작성하시오. 평균은 실수형으로 반환되어야 한다.
```c
int arr[5] = {10, 20, 30, 40, 50};
```

## 문제 10.

2차원 배열 `matrix[2][3]`을 다음과 같이 출력하는 프로그램을 배열 선언부터 출력까지 작성하시오:
```
10 20 30
40 50 60
```

## 문제 11.

오버플로우(Overflow) / 언더플로우(Underflow) 현상에 대해 설명하시오. 필요하다면 예시를 들어 설명하시오.

## 문제 12.

```c
#include <stdio.h>

void swap(int num1, int num2)
{
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}

int main(void)
{
    int num1 = 5;
    int num2 = 10;

    swap(num1, num2);

    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);

    return 0;
}

```

1. 위 코드를 실행했을 때 출력되는 값을 작성하시오.  
2. 위 코드에 오류가 있다면 수정하고, 그 이유를 설명하시오. 오류가 없다면 수정하지 말고 그대로 두시오.

## 문제 13.

아래 문자열에서 널 문자를 만날 때까지 길이를 계산하는 함수를 구현하시오.
```c
int my_strlen(const char* str)
{

}
```

## 문제 14.

구조체가 아래와 같이 정의되어 있다:

```c
typedef struct user {
    char name[20];
    int age;
} user_t;
```

사용자에게 3명의 이름과 나이를 입력받아 구조체 배열에 저장한 후 출력하는 프로그램을 작성하시오.

---

> 🎉 **수고하셨습니다!**  
> 이번 점검을 통해 부족한 개념을 발견하셨다면, 꼭 복습하시고 다시 도전해보세요.  
> 손으로 직접 풀어낸 경험은 결코 헛되지 않습니다.

> 💡 **Tip**  
> 스스로 점검해보는 것이 가장 좋으며,  
> 충분히 고민한 끝에 스스로 답을 찾을 수 있다면 더욱 이상적입니다.  
> 그러나 아무리 고민해도 해결이 되지 않는 경우에는, **이 저장소의 작성자에게 문의주셔도 괜찮습니다.**  