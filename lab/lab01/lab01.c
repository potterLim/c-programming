#include <stdio.h>
#include "lab01.h"

#define NAME ()

const int CURRENT_YEAR

// 전역 변수 (출력 검증 및 수치 검증용) 해당 변수를 수정하지 마세요.
int g_age;
float g_height_cm;
float g_weight_kg;
float g_height_m;
float g_bmi;
float g_health_score;
int g_rounded_health_score;

// 내부 출력 문자열 버퍼 (출력 줄 수 만큼) 해당 변수를 수정하지 마세요.
static char s_line1[64];
static char s_line2[64];
static char s_line3[64];
static char s_line4[64];
static char s_line5[64];
static char s_line6[64];
static char s_line7[64];

void solve_lab01(void)
{
    /*
     * TODO: 과제를 해결하기 위한 코드를 작성하세요.
     */


    // 출력 문자열 구성
    sprintf(s_line1, );
    sprintf(s_line2, );
    sprintf(s_line3, );
    sprintf(s_line4, );
    sprintf(s_line5, );
    sprintf(s_line6, );
    sprintf(s_line7, );
}


// 해당 함수는 출력 검증용입니다. 해당 함수를 수정하지 마세요.
const char* get_output_line(const int index)
{
    switch (index) {
    case 0:
        return s_line1;
    case 1:
        return s_line2;
    case 2:
        return s_line3;
    case 3:
        return s_line4;
    case 4:
        return s_line5;
    case 5:
        return s_line6;
    case 6:
        return s_line7;
    default:
        return "";
    }
}
