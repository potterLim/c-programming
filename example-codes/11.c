/*
 * Example code from: 11-strings
 * Purpose          : Demonstrates common string operations and pitfalls
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    // 1. strlen() example
    char word[] = "hello";
    printf("Length of '%s' is %zu\n", word, strlen(word));

    // 2. strcpy() and strncpy() example
    char dest1[20];
    strcpy(dest1, "copy me");
    printf("strcpy result: %s\n", dest1);

    char dest2[10];
    strncpy(dest2, "abcdef", 4);
    dest2[4] = '\0'; // Ensure null-termination
    printf("strncpy result: %s\n", dest2);

    /*
    // Mistake: strncpy does not add '\0' when n <= strlen(src)
    char faulty[4];
    strncpy(faulty, "test", 4); // 't', 'e', 's', 't' (no '\0')
    printf("%s\n", faulty); // Undefined behavior
    */

    // 3. strcat() and strncat() example
    char greeting[50] = "Hello, ";
    strcat(greeting, "world!");
    printf("strcat result: %s\n", greeting);

    char partial[50] = "Hi, ";
    strncat(partial, "there! How are you?", 5); // Only adds "there"
    printf("strncat result: %s\n", partial);

    /*
    // Mistake: buffer overflow risk with strcat()
    char small[10] = "Hi";
    strcat(small, " this is a long string"); // Danger
    */

    // 4. strcmp() and strncmp()
    char pw1[] = "apple";
    char pw2[] = "apple";
    if (strcmp(pw1, pw2) == 0) {
        printf("Passwords match\n");
    }

    if (strncmp("application", "apple", 5) == 0) {
        printf("First 5 chars match\n");
    }

    // 5. strchr() and strstr()
    char line[] = "The quick brown fox";
    char *pos1 = strchr(line, 'q');
    char *pos2 = strstr(line, "brown");

    if (pos1 != NULL) {
        printf("'q' found at index: %ld\n", pos1 - line);
    }

    if (pos2 != NULL) {
        printf("'brown' starts at: %s\n", pos2);
    }

    // 6. fgets() + newline removal
    char input[100];
    printf("Enter a line (max 99 chars): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove newline
    printf("You entered: %s\n", input);

    /*
    // Mistake: forgetting to remove newline causes mismatch
    char check[] = "hello";
    if (strcmp(input, check) == 0) {
        printf("Matches 'hello'\n");
    } else {
        printf("Does not match due to newline?\n");
    }
    */

    // 7. strcpy() with literal
    char hello[10];
    strcpy(hello, "hi"); // OK
    printf("hello = %s\n", hello);

    /*
    // Mistake: writing to string literal
    char *danger = "hi";
    danger[0] = 'b'; // Runtime error (segmentation fault)
    */

    // 8. Pointer-style string access
    char *msg = "world";
    for (int i = 0; msg[i] != '\0'; ++i) {
        printf("%c ", *(msg + i));
    }
    printf("\n");

    return 0;
}
