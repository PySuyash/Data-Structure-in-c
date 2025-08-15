// Convert lowercase to uppercase character using pass by value.

#include <stdio.h>

// Function to convert lowercase to uppercase using pass-by-value
char toUpperCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - ('a' - 'A');  // or simply: return ch - 32;
    }
    return ch;  // Return unchanged if not lowercase
}

int main() {
    char letter = 'g';

    char upper = toUpperCase(letter);

    printf("Original character: %c\n", letter);     // Unchanged
    printf("Uppercase version: %c\n", upper);       // Converted

    return 0;
}
