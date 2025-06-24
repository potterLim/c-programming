#ifndef DIGIT_ANALYSIS_H
#define DIGIT_ANALYSIS_H

int count_digits_recursive(int n);        // n의 자릿수 개수를 재귀적으로 센다 (예: 70342 → 5)
int get_digit_sum_recursive(int n);       // n의 모든 자릿수의 합을 재귀적으로 구한다 (예: 70342 → 16)
int get_first_digit_recursive(int n);     // n의 가장 앞자릿수를 재귀적으로 구한다 (예: 70342 → 7)
int get_last_digit(int n);                // n의 가장 끝자릿수를 반환한다 (예: 70342 → 2)
int count_even_digits_recursive(int n);   // n의 자릿수 중 짝수의 개수를 재귀적으로 센다
int count_odd_digits_recursive(int n);    // n의 자릿수 중 홀수의 개수를 재귀적으로 센다

#endif /* DIGIT_ANALYSIS_H */
