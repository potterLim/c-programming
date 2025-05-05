#include <assert.h>
#include <stdio.h>

#include "digit_analysis.h"

int main(void)
{
    int n, result;

    // Test 1
    n = 70342;
    result = count_digits_recursive(n);
    if (result != 5) {
        fprintf(stderr, "[오류] count_digits_recursive(%d): %d (예상값: 5)\n", n, result);
        assert(0);
    }

    result = get_digit_sum_recursive(n);
    if (result != 16) {
        fprintf(stderr, "[오류] get_digit_sum_recursive(%d): %d (예상값: 16)\n", n, result);
        assert(0);
    }

    result = get_first_digit_recursive(n);
    if (result != 7) {
        fprintf(stderr, "[오류] get_first_digit_recursive(%d): %d (예상값: 7)\n", n, result);
        assert(0);
    }

    result = get_last_digit(n);
    if (result != 2) {
        fprintf(stderr, "[오류] get_last_digit(%d): %d (예상값: 2)\n", n, result);
        assert(0);
    }

    result = count_even_digits_recursive(n);
    if (result != 2) {
        fprintf(stderr, "[오류] count_even_digits_recursive(%d): %d (예상값: 2)\n", n, result);
        assert(0);
    }

    result = count_odd_digits_recursive(n);
    if (result != 3) {
        fprintf(stderr, "[오류] count_odd_digits_recursive(%d): %d (예상값: 3)\n", n, result);
        assert(0);
    }

    // Test 2
    n = 1;
    result = count_digits_recursive(n);
    if (result != 1) {
        fprintf(stderr, "[오류] count_digits_recursive(%d): %d (예상값: 1)\n", n, result);
        assert(0);
    }

    result = get_digit_sum_recursive(n);
    if (result != 1) {
        fprintf(stderr, "[오류] get_digit_sum_recursive(%d): %d (예상값: 1)\n", n, result);
        assert(0);
    }

    result = get_first_digit_recursive(n);
    if (result != 1) {
        fprintf(stderr, "[오류] get_first_digit_recursive(%d): %d (예상값: 1)\n", n, result);
        assert(0);
    }

    result = get_last_digit(n);
    if (result != 1) {
        fprintf(stderr, "[오류] get_last_digit(%d): %d (예상값: 1)\n", n, result);
        assert(0);
    }

    result = count_even_digits_recursive(n);
    if (result != 0) {
        fprintf(stderr, "[오류] count_even_digits_recursive(%d): %d (예상값: 0)\n", n, result);
        assert(0);
    }

    result = count_odd_digits_recursive(n);
    if (result != 1) {
        fprintf(stderr, "[오류] count_odd_digits_recursive(%d): %d (예상값: 1)\n", n, result);
        assert(0);
    }

    // Test 3
    n = 8000;
    result = count_digits_recursive(n);
    if (result != 4) {
        fprintf(stderr, "[오류] count_digits_recursive(%d): %d (예상값: 4)\n", n, result);
        assert(0);
    }

    result = get_digit_sum_recursive(n);
    if (result != 8) {
        fprintf(stderr, "[오류] get_digit_sum_recursive(%d): %d (예상값: 8)\n", n, result);
        assert(0);
    }

    result = get_first_digit_recursive(n);
    if (result != 8) {
        fprintf(stderr, "[오류] get_first_digit_recursive(%d): %d (예상값: 8)\n", n, result);
        assert(0);
    }

    result = get_last_digit(n);
    if (result != 0) {
        fprintf(stderr, "[오류] get_last_digit(%d): %d (예상값: 0)\n", n, result);
        assert(0);
    }

    result = count_even_digits_recursive(n);
    if (result != 4) {
        fprintf(stderr, "[오류] count_even_digits_recursive(%d): %d (예상값: 4)\n", n, result);
        assert(0);
    }

    result = count_odd_digits_recursive(n);
    if (result != 0) {
        fprintf(stderr, "[오류] count_odd_digits_recursive(%d): %d (예상값: 0)\n", n, result);
        assert(0);
    }

    printf("✅ 모든 테스트를 통과했습니다.\n");
    return 0;
}
