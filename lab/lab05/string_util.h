#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#define TRUE (1)
#define FALSE (0)

int count_uppercase(const char* str);
int count_lowercase(const char* str);
int count_digits(const char* str);
int count_spaces(const char* str);
int count_special_characters(const char* str);
int is_valid_password(const char* str);

#endif /* STRING_UTIL_H */
