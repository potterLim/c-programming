#include <assert.h>
#include <limits.h>
#include <stdio.h>

#include "array.h"

static int s_numbers[20] = {-1, 4, -5, 3, 10, 7, 4, 6, 5, -10};

int main(void)
{
    printf("🔍 Testing get_index()...\n");
    if (get_index(s_numbers, 10, 4) != 1) {
        printf("get_index() failed: expected 1\n");
        assert(0);
    }

    printf("🔍 Testing get_last_index()...\n");
    if (get_last_index(s_numbers, 10, 4) != 6) {
        printf("get_last_index() failed: expected 6\n");
        assert(0);
    }

    printf("🔍 Testing get_max_index()...\n");
    if (get_max_index(s_numbers, 10) != 4) {
        printf("get_max_index() failed: expected 4\n");
        assert(0);
    }

    printf("🔍 Testing get_min_index()...\n");
    if (get_min_index(s_numbers, 10) != 9) {
        printf("get_min_index() failed: expected 9\n");
        assert(0);
    }

    printf("🔍 Testing insert_at()...\n");
    int expected_insert[12] = { -21, -1, 4, -5, 3, 10, 7, 4, 6, 5, -10, -22 };
    if (insert_at(s_numbers, 10, -21, 0) != TRUE) {
        printf("insert_at() failed at position 0\n");
        assert(0);
    }
    if (insert_at(s_numbers, 11, -22, 11) != TRUE) {
        printf("insert_at() failed at position 11\n");
        assert(0);
    }
    for (int i = 0; i < 12; i++) {
        if (s_numbers[i] != expected_insert[i]) {
            printf("insert_at() result mismatch at index %d\n", i);
            assert(0);
        }
    }

    printf("🔍 Testing remove_at()...\n");
    int expected_remove[10] = { -1, 4, -5, 3, 10, 7, 4, 6, 5, -10 };
    if (get_index(s_numbers, 10, -21) != 0) {
        printf("index check failed before remove for -21\n");
        assert(0);
    }
    if (get_index(s_numbers, 12, -22) != 11) {
        printf("index check failed before remove for -22\n");
        assert(0);
    }
    if (remove_at(s_numbers, 12, 0) != TRUE) {
        printf("remove_at() failed at index 0\n");
        assert(0);
    }
    if (remove_at(s_numbers, 11, 10) != TRUE) {
        printf("remove_at() failed at index 10\n");
        assert(0);
    }
    if (get_index(s_numbers, 10, -21) != -1 || get_index(s_numbers, 10, -22) != -1) {
        printf("remove_at() did not correctly remove values\n");
        assert(0);
    }
    for (int i = 0; i < 10; i++) {
        if (s_numbers[i] != expected_remove[i]) {
            printf("remove_at() result mismatch at index %d\n", i);
            assert(0);
        }
    }

    printf("🔍 Testing get_index() for non-existent value...\n");
    if (get_index(s_numbers, 10, 999) != -1) {
        printf("get_index() failed for non-existent value\n");
        assert(0);
    }

    printf("🔍 Testing get_last_index() for last element...\n");
    if (get_last_index(s_numbers, 10, -10) != 9) {
        printf("get_last_index() failed for last element\n");
        assert(0);
    }

    int all_same[5] = {42, 42, 42, 42, 42};

    printf("🔍 Testing get_max_index() when all elements are the same...\n");
    if (get_max_index(all_same, 5) != 0) {
        printf("get_max_index() failed when all values are the same\n");
        assert(0);
    }

    printf("🔍 Testing get_min_index() when all elements are the same...\n");
    if (get_min_index(all_same, 5) != 0) {
        printf("get_min_index() failed when all values are the same\n");
        assert(0);
    }

    printf("🔍 Testing get_max_index() with empty array...\n");
    if (get_max_index(all_same, 0) != -1) {
        printf("get_max_index() failed on empty array\n");
        assert(0);
    }

    printf("🔍 Testing get_min_index() with empty array...\n");
    if (get_min_index(all_same, 0) != -1) {
        printf("get_min_index() failed on empty array\n");
        assert(0);
    }

    int with_zero[] = {1, 2, 0, 3};
    int without_zero[] = {-1, -2, -3, -4};

    printf("🔍 Testing has_zero() with zero inside...\n");
    if (has_zero(with_zero, 4) != TRUE) {
        printf("has_zero() failed to detect 0\n");
        assert(0);
    }

    printf("🔍 Testing has_zero() with no zero...\n");
    if (has_zero(without_zero, 4) != FALSE) {
        printf("has_zero() incorrectly detected 0\n");
        assert(0);
    }

    printf("🔍 Testing has_zero() with empty array...\n");
    if (has_zero(with_zero, 0) != FALSE) {
        printf("has_zero() failed on empty array\n");
        assert(0);
    }

    int arr[20] = {1, 2, 3};

    printf("🔍 Testing insert_at() with invalid index (-1)...\n");
    if (insert_at(arr, 3, 99, -1) != FALSE) {
        printf("insert_at() should fail with negative index\n");
        assert(0);
    }

    printf("🔍 Testing insert_at() with index beyond count...\n");
    if (insert_at(arr, 3, 99, 4) != FALSE) {
        printf("insert_at() should fail with index > count\n");
        assert(0);
    }

    printf("🔍 Testing insert_at() to preserve order...\n");
    if (insert_at(arr, 3, 99, 1) != TRUE) {
        printf("insert_at() failed at valid index 1\n");
        assert(0);
    }
    if (arr[0] != 1 || arr[1] != 99 || arr[2] != 2 || arr[3] != 3) {
        printf("insert_at() did not preserve order after insert\n");
        assert(0);
    }

    int arr2[20] = {1, 2, 3, 4};

    printf("🔍 Testing remove_at() with invalid index (-1)...\n");
    if (remove_at(arr2, 4, -1) != FALSE) {
        printf("remove_at() should fail with negative index\n");
        assert(0);
    }

    printf("🔍 Testing remove_at() with index equal to count...\n");
    if (remove_at(arr2, 4, 4) != FALSE) {
        printf("remove_at() should fail with index == count\n");
        assert(0);
    }

    printf("🔍 Testing remove_at() to preserve order...\n");
    if (remove_at(arr2, 4, 1) != TRUE) {
        printf("remove_at() failed at valid index 1\n");
        assert(0);
    }
    if (arr2[0] != 1 || arr2[1] != 3 || arr2[2] != 4) {
        printf("remove_at() did not preserve order after remove\n");
        assert(0);
    }

    printf("✅ 모든 테스트를 통과했습니다.\n");
    return 0;
}
