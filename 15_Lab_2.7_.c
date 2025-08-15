// Count vowel and consonants in a string using pointers.

#include <stdio.h>
#include <ctype.h>  // For tolower()

int main() {
    char str[100];
    char *ptr;
    int vowels = 0, consonants = 0;

    // Input string (single word only)
    printf("Enter a string: ");
    scanf("%s", str);  // Reads until whitespace

    // Initialize pointer
    ptr = str;

    // Traverse using pointer
    while (*ptr != '\0') {
        char ch = tolower(*ptr);  // Normalize to lowercase

        if (ch >= 'a' && ch <= 'z') {
            // Check for vowels
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
        ptr++;  // Move to next character
    }

    // Output results
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}
