#ifndef DIVISOR_ANALYZER_H
#define DIVISOR_ANALYZER_H

int is_prime(int number);              // number가 소수인지 아닌지 판별한다.
int count_divisors(int number);        // number의 약수 개수를 센다.
int sum_divisors(int number);          // number의 모든 약수를 더한다.
int count_odd_divisors(int number);    // number의 약수 중에서 홀수인 것의 개수를 센다.
int count_even_divisors(int number);   // number의 약수 중에서 짝수인 것의 개수를 센다.
int count_prime_divisors(int number);  // number의 약수 중에서 소수인 것의 개수를 센다.

#endif /* DIVISOR_ANALYZER_H */
