// Duplicate String, Write: char* duplicateString(const char* str) Returns pointer to a new dynamically allocated copy of the string.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Duplicates a string using dynamic memory
char* duplicateString(const char* str) {
    if (str == NULL) return NULL;

    size_t len = strlen(str) + 1;  // +1 for null terminator
    char* copy = (char*)malloc(len);
    if (copy == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(copy, str);  // Copy the string
    return copy;
}

int main() {
    const char* original = "Hello, world!";
    char* duplicated = duplicateString(original);

    printf("Original:  %s\n", original);
    printf("Duplicated: %s\n", duplicated);

    // Free memory
    free(duplicated);

    return 0;
}
