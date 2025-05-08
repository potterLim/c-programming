// report.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "report.h"

#define MAX_LINE 1024

static int is_word_char(char ch)
{
    return isalpha((unsigned char)ch);
}

void generate_report(const char* input_filename, const char* output_filename)
{
    FILE* in = fopen(input_filename, "r");
    if (in == NULL) {
        fprintf(stderr, "입력 파일을 열 수 없습니다.\n");
        exit(1);
    }

    FILE* out = fopen(output_filename, "w");
    if (out == NULL) {
        fprintf(stderr, "출력 파일을 생성할 수 없습니다.\n");
        fclose(in);
        exit(1);
    }

    int total_words = 0;
    int total_length = 0;
    int line_count = 0;
    int alphabet[26] = {0};
    char line[MAX_LINE];

    while (fgets(line, sizeof(line), in) != NULL) {
        ++line_count;
        char* p = line;

        while (*p) {
            // skip non-alphabet
            while (*p && !is_word_char(*p)) {
                ++p;
            }

            if (!*p) break;

            char word[64];
            int i = 0;
            while (*p && is_word_char(*p) && i < 63) {
                word[i++] = (char)tolower((unsigned char)*p);
                ++p;
            }
            word[i] = '\0';

            ++total_words;
            total_length += i;

            for (int j = 0; j < i; ++j) {
                alphabet[word[j] - 'a']++;
            }
        }
    }

    fprintf(out, "[Word Statistics Report]\n\n");
    fprintf(out, "1. Total number of words: %d\n\n", total_words);

    fprintf(out, "3. Alphabet frequency:\n");
    for (int i = 0; i < 26; ++i) {
        fprintf(out, "%c: %d\n", 'a' + i, alphabet[i]);
    }

    fprintf(out, "\n4. Number of lines: %d\n", line_count);
    fprintf(out, "\n5. Average word length: %.2f\n", total_words ? (double)total_length / total_words : 0.0);

    fclose(in);
    fclose(out);
}