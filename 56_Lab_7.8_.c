// Returns pointer to first non-repeating character.

#include <stdio.h>
#include <string.h>

#define CHAR_RANGE 256  // Covers all ASCII characters

// Returns pointer to first non-repeating character
char* firstNonRepeatingChar(char *str) {
    if (str == NULL) return NULL;

    int freq[CHAR_RANGE] = {0};

    // First pass: count frequencies
    for (char *p = str; *p != '\0'; p++) {
        freq[(unsigned char)*p]++;
    }

    // Second pass: find first non-repeating
    for (char *p = str; *p != '\0'; p++) {
        if (freq[(unsigned char)*p] == 1) {
            return p;
        }
    }

    return NULL;  // No non-repeating character found
}

int main() {
    char text[] = "swiss";
    char *uniquePtr = firstNonRepeatingChar(text);

    if (uniquePtr != NULL) {
        printf("First non-repeating character: %c\n", *uniquePtr);
        printf("Address: %p\n", (void*)uniquePtr);
    } else {
        printf("No non-repeating character found.\n");
    }

    return 0;
}
