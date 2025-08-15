// Find and return address of first vowel in string.

#include <stdio.h>
#include <ctype.h>

// Returns address of the first vowel in the string
char* findFirstVowel(char *str) {
    if (str == NULL) return NULL;

    while (*str != '\0') {
        char ch = tolower(*str);  // Case-insensitive check
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return str;
        }
        str++;
    }
    return NULL;  // No vowel found
}
