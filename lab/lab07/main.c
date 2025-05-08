#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "report.h"

#define OUTPUT_FILE "output.txt"
#define MAX_LINE_LENGTH 256

const char* expected[] = {
    "[Word Statistics Report]\n",
    "\n",
    "1. Total number of words: 60\n",
    "\n",
    "3. Alphabet frequency:\n",
    "a: 21\n", "b: 2\n", "c: 1\n", "d: 2\n", "e: 24\n", "f: 10\n", "g: 9\n", "h: 14\n",
    "i: 13\n", "j: 0\n", "k: 2\n", "l: 9\n", "m: 4\n", "n: 17\n", "o: 21\n",
    "p: 5\n", "q: 0\n", "r: 9\n", "s: 12\n", "t: 22\n", "u: 5\n", "v: 1\n",
    "w: 7\n", "x: 0\n", "y: 6\n", "z: 0\n",
    "\n",
    "4. Number of lines: 5\n",
    "\n",
    "5. Average word length: 3.60\n"
};

const int expected_lines = sizeof(expected) / sizeof(expected[0]);


int main(void)
{
    generate_report("input.txt", OUTPUT_FILE);

    FILE* fp = fopen(OUTPUT_FILE, "r");
    assert(fp != NULL);

    char line[MAX_LINE_LENGTH];
    for (int i = 0; i < expected_lines; ++i) {
        if (fgets(line, sizeof(line), fp) == NULL) {
            printf("❌ 줄 %d: 출력이 예상보다 짧습니다.", i + 1);
            assert(0);
        }
        if (strcmp(line, expected[i]) != 0) {
            printf("❌ 줄 %d 불일치:", i + 1);
            printf("  [예상] %s", expected[i]);
            printf("  [실제] %s", line);
            assert(0);
        }
    }
    if (fgets(line, sizeof(line), fp) != NULL) {
        printf("❌ 출력이 예상보다 깁니다. [추가 출력] %s", line);
        assert(0);
    }

    fclose(fp);
    printf("✅ 모든 테스트를 통과했습니다.\n");
    return 0;
}
