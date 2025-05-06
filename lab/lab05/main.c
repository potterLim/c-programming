#include <assert.h>
#include <stdio.h>
#include "string_util.h"

static void test_count_functions(const char* str, int expected_upper, int expected_lower, int expected_digits, int expected_spaces, int expected_special);
static void test_is_valid_password(const char* str, int expected);

int main(void)
{
    test_count_functions("Hello123!", 1, 4, 3, 0, 1);
    test_count_functions("A B C", 3, 0, 0, 2, 0);
    test_count_functions("abc123!!", 0, 3, 3, 0, 2);
    test_count_functions("      ", 0, 0, 0, 6, 0);
    test_count_functions("", 0, 0, 0, 0, 0);
    test_count_functions("HeLLo W0RLD!", 7, 2, 1, 1, 1);
    test_count_functions("12345\n67890\t", 0, 0, 10, 0, 2);
    test_count_functions("AbcDef", 2, 4, 0, 0, 0);
    test_count_functions("     !", 0, 0, 0, 5, 1);

    test_is_valid_password("Hello123!", TRUE);
    test_is_valid_password("Short7!", FALSE);
    test_is_valid_password("password", FALSE);
    test_is_valid_password("ABC123@xyz", TRUE);
    test_is_valid_password("NoSpecialChar123", FALSE);
    test_is_valid_password("with space123!", FALSE);
    test_is_valid_password("With space123!", TRUE);
    test_is_valid_password("!@#$%^&*", FALSE);
    test_is_valid_password("12345678", FALSE);
    test_is_valid_password("ABcd12#$", TRUE);
    test_is_valid_password("Short1!", FALSE);

    printf("✅ 모든 테스트를 통과했습니다.");
    return 0;
}

static void test_count_functions(const char* str, int expected_upper, int expected_lower, int expected_digits, int expected_spaces, int expected_special)
{
    int actual_upper = count_uppercase(str);
    int actual_lower = count_lowercase(str);
    int actual_digits = count_digits(str);
    int actual_spaces = count_spaces(str);
    int actual_special = count_special_characters(str);

    if (actual_upper != expected_upper) {
        printf("실패 [대문자]: \"%s\" → 예상: %d, 실제: %d\n", str, expected_upper, actual_upper);
        assert(0);
    }
    if (actual_lower != expected_lower) {
        printf("실패 [소문자]: \"%s\" → 예상: %d, 실제: %d\n", str, expected_lower, actual_lower);
        assert(0);
    }
    if (actual_digits != expected_digits) {
        printf("실패 [숫자]: \"%s\" → 예상: %d, 실제: %d\n", str, expected_digits, actual_digits);
        assert(0);
    }
    if (actual_spaces != expected_spaces) {
        printf("실패 [공백]: \"%s\" → 예상: %d, 실제: %d\n", str, expected_spaces, actual_spaces);
        assert(0);
    }
    if (actual_special != expected_special) {
        printf("실패 [특수문자]: \"%s\" → 예상: %d, 실제: %d\n", str, expected_special, actual_special);
        assert(0);
    }
}

static void test_is_valid_password(const char* str, int expected)
{
    int actual = is_valid_password(str);
    const char* expected_str = expected == TRUE ? "TRUE" : "FALSE";
    const char* actual_str = actual == TRUE ? "TRUE" : "FALSE";

    if (actual != expected) {
        printf("실패 [비밀번호]: \"%s\" → 예상: %s, 실제: %s\n", str, expected_str, actual_str);
        assert(0);
    }
}

