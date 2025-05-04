#include <assert.h>
#include <stdio.h>

#include "lab02.h"

void test_int(const char* name, int actual, int expected)
{
    if (actual != expected) {
        fprintf(stderr, "[오류] %s: %d (예상: %d)\n", name, actual, expected);
        assert(0);
    }
}

int main(void)
{
    // Test case 1: number = 60
    int number = 60;
    test_int("count_divisors(60)", count_divisors(number), 12);
    test_int("sum_divisors(60)", sum_divisors(number), 168);
    test_int("count_odd_divisors(60)", count_odd_divisors(number), 4);
    test_int("count_even_divisors(60)", count_even_divisors(number), 8);
    test_int("count_prime_divisors(60)", count_prime_divisors(number), 3);

    // Test case 2: number = 1
    number = 1;
    test_int("count_divisors(1)", count_divisors(number), 1);
    test_int("sum_divisors(1)", sum_divisors(number), 1);
    test_int("count_odd_divisors(1)", count_odd_divisors(number), 1);
    test_int("count_even_divisors(1)", count_even_divisors(number), 0);
    test_int("count_prime_divisors(1)", count_prime_divisors(number), 0);

    // Test case 3: number = 0
    number = 0;
    test_int("count_divisors(0)", count_divisors(number), 0);
    test_int("sum_divisors(0)", sum_divisors(number), 0);
    test_int("count_odd_divisors(0)", count_odd_divisors(number), 0);
    test_int("count_even_divisors(0)", count_even_divisors(number), 0);
    test_int("count_prime_divisors(0)", count_prime_divisors(number), 0);

    // Test case 4: number = 13
    number = 13;
    test_int("count_divisors(13)", count_divisors(number), 2);
    test_int("sum_divisors(13)", sum_divisors(number), 14);
    test_int("count_odd_divisors(13)", count_odd_divisors(number), 2);
    test_int("count_even_divisors(13)", count_even_divisors(number), 0);
    test_int("count_prime_divisors(13)", count_prime_divisors(number), 1);

    // Test case 5: is_prime()
    test_int("is_prime(0)", is_prime(0), 0);
    test_int("is_prime(1)", is_prime(1), 0);
    test_int("is_prime(2)", is_prime(2), 1);
    test_int("is_prime(3)", is_prime(3), 1);
    test_int("is_prime(4)", is_prime(4), 0);
    test_int("is_prime(5)", is_prime(5), 1);
    test_int("is_prime(9)", is_prime(9), 0);
    test_int("is_prime(11)", is_prime(11), 1);
    test_int("is_prime(20)", is_prime(20), 0);

    printf("\n✅ 모든 테스트를 통과했습니다.\n");
    return 0;
}
