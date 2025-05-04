#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "lab01.h"

int float_equal(float a, float b)
{
    float diff = a - b;
    if (diff < 0.0f) {
        diff = -diff;
    }

    return diff < 0.01f;
}

int main(void)
{
    const char* expected_lines[] = {
        "Name: potterLim",
        "Age: 20",
        "Height: 172.5 cm (1.73 m)",
        "Weight: 65.0 kg",
        "BMI: 21.88",
        "Health Score: 86.18",
        "Rounded Health Score: 86"
    };

    solve_lab01();

    for (int i = 0; i < 7; ++i) {
        const char* actual = get_output_line(i);
        const char* expected = expected_lines[i];

        if (strcmp(actual, expected) != 0) {
            fprintf(stderr, "[출력 오류] 줄 %d | 예상: \"%s\" | 실제: \"%s\"\n", i + 1, expected, actual);
            assert(0);
        }
    }

    if (CURRENT_YEAR != 2025) {
        fprintf(stderr, "[상수 오류] CURRENT_YEAR: %d | 기대값: 2025\n", CURRENT_YEAR);
        assert(0);
    }

    if (g_age != 20) {
        fprintf(stderr, "[값 오류] g_age: %d | 기대값: 20\n", g_age);
        assert(0);
    }

    if (!float_equal(g_height_cm, 172.5f)) {
        fprintf(stderr, "[값 오류] g_height_cm: %.2f | 기대값: 172.5\n", g_height_cm);
        assert(0);
    }

    if (!float_equal(g_weight_kg, 65.0f)) {
        fprintf(stderr, "[값 오류] g_weight_kg: %.2f | 기대값: 65.0\n", g_weight_kg);
        assert(0);
    }

    const float expected_height_m = g_height_cm / 100.0f;
    if (!float_equal(g_height_m, expected_height_m)) {
        fprintf(stderr, "[계산 오류] g_height_m: %.3f | 기대값: %.3f\n", g_height_m, expected_height_m);
        assert(0);
    }

    const float expected_bmi = g_weight_kg / (g_height_m * g_height_m);
    if (!float_equal(g_bmi, expected_bmi)) {
        fprintf(stderr, "[계산 오류] g_bmi: %.3f | 기대값: %.3f\n", g_bmi, expected_bmi);
        assert(0);
    }

    const float expected_score = 100.0f - (g_age * 0.7f) + (g_bmi - 22.0f) * 1.5f;
    if (!float_equal(g_health_score, expected_score)) {
        fprintf(stderr, "[계산 오류] g_health_score: %.2f | 기대값: %.2f\n", g_health_score, expected_score);
        assert(0);
    }

    const int expected_rounded = (int)(g_health_score + 0.5f);
    if (g_rounded_health_score != expected_rounded) {
        fprintf(stderr, "[반올림 오류] g_rounded_health_score: %d | 기대값: %d\n", g_rounded_health_score, expected_rounded);
        assert(0);
    }

    return 0;
}
