# C-Programming

이 저장소는 프로그래밍을 처음 접하는 입문자들을 위한 C 언어 기초 학습 자료를 제공합니다.

한동대학교는 모든 학생이 무전공으로 입학하기 때문에, 컴퓨터공학을 전공하게 되더라도 1학년 때 C 언어 수업을 수강하지 않은 채 전공 공부를 시작하는 경우가 많습니다.  
이러한 상황을 고려하여 이 저장소는 전공 수업을 듣기 전 C 언어의 핵심 개념과 문법을 간략히 훑을 수 있도록 정리된 노트 모음으로 구성되어 있습니다.

하지만 전공 수업을 제대로 이해하고 따라가기 위해서는 **C 언어에 대한 정확하고 꼼꼼한 기초 지식**이 필수적입니다.  
이 노트는 어디까지나 핵심 문법과 개념을 빠르게 정리한 것이므로 이 저장소를 통해 공부하고 난 뒤에라도  
_K. N. King_ 저의 『C Programming: A Modern Approach』를 정독할 것을 강력히 추천합니다.

## 개발 환경 구축

C 언어를 학습하고 실습 예제를 실행하려면 코드를 작성하고 컴파일할 수 있는 개발 환경이 필요합니다.  
이 저장소에서는 Windows 사용자 기준으로 Visual Studio Code와 gcc를 이용한 개발 환경 설정을 권장합니다.

설치 방법과 테스트 컴파일까지의 과정을 자세히 설명한 [개발 환경 구축 가이드(pdf)](./setup-guide/c_programming_setup_guide.pdf)를 통해  
Visual Studio Code에서 `.c` 파일을 바로 작성하고 컴파일, 실행할 수 있는 환경을 손쉽게 구축할 수 있습니다.

> macOS 또는 Linux 환경에서도 동일한 실습이 가능하며 해당 운영체제를 위한 개발 환경 구축 가이드는 추후 제공될 예정입니다.

## 목차 및 노트

각 장별 학습 노트는 [`notes/`](./notes) 디렉토리에, 예제 코드는 [`example-codes/`](./example-codes) 디렉토리에 정리되어 있으며, 다음과 같은 주제를 다룹니다:

| 번호 | 주제                 | 노트                                                                            | 예제 코드                  |
| ---- | ---------------------| ------------------------------------------------------------------------------- | -------------------------- |
| 01   | 프로그램의 시작      | [01-started-with-programming](notes/01-started-with-programming.md)             | [01.c](example-codes/01.c) |
| 02   | 변수와 상수          | [02-variables-and-constants](notes/02-variables-and-constants.md)               | [02.c](example-codes/02.c) |
| 03   | 자료형과 형 변환     | [03-data-types-and-type-conversion](notes/03-data-types-and-type-conversion.md) | [03.c](example-codes/03.c) |
| 04   | 연산자               | [04-operators](notes/04-operators.md)                                           | [04.c](example-codes/04.c) |
| 05   | 조건문               | [05-conditional-statements](notes/05-conditional-statements.md)                 | [05.c](example-codes/05.c) |
| 06   | 반복문               | [06-loops](notes/06-loops.md)                                                   | [06.c](example-codes/06.c) |
| 07   | 함수와 전처리 지시문 | [07-functions-and-preprocessor](notes/07-functions-and-preprocessor.md)         | [./07](example-codes/07)   |
| 08   | 재귀 함수와 응용     | [08-recursion-and-applications](notes/08-recursion-and-applications.md)         | [./08](example-codes/08)   |
| 09   | 배열과 다차원 배열   | [09-arrays-and-multidimensional](notes/09-arrays-and-multidimensional.md)       | [./09](example-codes/09)   |
| 10   | 포인터               | [10-pointers](notes/10-pointers.md)                                             | [./10](example-codes/10)   |
| 11   | 문자열               | [11-strings](notes/11-strings.md)                                               | [11.c](example-codes/11.c) |
| 12   | 구조체와 typedef     | [12-struct-typedef](notes/12-struct-typedef.md)                                 | [./12](example-codes/12)   |
| 13   | 동적 메모리 할당     | [13-dynamic-memory-allocation](notes/13-dynamic-memory-allocation.md)           | [./13](example-codes/13)   |
| 14   | 파일 입출력          | [14-file-io](notes/14-file-io.md)                                               | [./14](example-codes/14)   |
| 15   | 컴퓨터에서의 수 체계 | [15-number-systems-in-computers](notes/15-number-systems-in-computers.md)       | [./15](example-codes/15)   |
| 16   | 비트 연산자          | [16-bitwise-operators](notes/16-bitwise-operators.md)                           | [16.c](example-codes/16.c) |

## 실습(Lab)

이 저장소는 개념 이해를 넘어 직접 C 언어를 다뤄보며 연습할 수 있도록 실습 문제도 함께 제공합니다.  
각 실습은 2~3개의 주제를 묶어 실제 프로그램을 작성해보는 방식으로 구성되어 있으며 [`lab/`](./lab) 디렉토리에 위치합니다.

| 실습 번호 | 포함된 주제 |          실습 제목           |     과제 경로      |
|-----------|-------------|------------------------------|--------------------|
|     01    |   02 ~ 03   | 정밀 건강 점수 계산기        | [lab01](lab/lab01) |
|     02    |   04 ~ 06   | 약수 분석기                  | [lab02](lab/lab02) |
|     03    |   07 ~ 08   | 숫자 분석기                  | [lab03](lab/lab03) |
|     04    |     09      | 배열 유틸리티                | [lab04](lab/lab04) |
|     05    |   10 ~ 11   | 문자열 정보 분석기           | [lab05](lab/lab05) |
|     06    |   12 ~ 13   | 학생 목록 필터기             | [lab06](lab/lab06) |
|     07    |     14      | 단어 통계 리포트 생성기      | [lab07](lab/lab07) |


모든 실습은 이전 실습에서 다룬 내용을 포함합니다.  
즉, 실습이 진행될수록 더 많은 개념을 통합적으로 사용하는 방식으로 구성되어 있습니다.

## 점검용 평가(Checkpoints)

이 저장소는 기초 개념을 학습한 후 스스로 학습 내용을 점검해보고 싶은 분들을 위해 점검용 평가 문서를 제공합니다.  
각 점검용 평가는 스스로 학습 내용을 정리하고 점검할 수 있도록 구성되어 있으며 [`checkpoint/`](./checkpoint) 디렉토리에 위치합니다.

| 점검 이름         | 포함된 주제 | 경로                                                       |
|-------------------|-------------|------------------------------------------------------------|
| Midway Checkpoint | 01 ~ 08     | [midway-checkpoint.md](./checkpoint/midway-checkpoint.md)  |
| Final Checkpoint  | 09 ~ 15     | [final-checkpoint.md](./checkpoint/final-checkpoint.md)    |

## 부정확한 내용에 대한 기여

정보가 부정확하거나 누락된 부분이 있을 수 있습니다.  
오류를 발견하시거나 추가하고 싶은 내용이 있으시면 Pull Request 또는 Issue를 통해 알려주세요.

여러분의 피드백은 더 나은 자료를 만드는 데 큰 도움이 됩니다.

## 문의

이 저장소를 통해 공부하시다가 내용, 실습, 설명 등에 대해 궁금한 점이 생기면 언제든지 potterLim0808@gmail.com 으로 문의 주시면 성실히 답변드리겠습니다.

> 최종 수정일: 2025-07-07
