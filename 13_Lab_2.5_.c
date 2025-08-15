// Compute string length using pointers.

#include <stdio.h>

int main() {
    char str[100];
    char *ptr;
    int length = 0;

    // Input string (single word only)
    printf("Enter a string: ");
    scanf("%s", str);  // Reads until whitespace

    // Initialize pointer
    ptr = str;

    // Traverse using pointer
    while (*ptr != '\0') {
        length++;
        ptr++;
    }

    // Output result
    printf("Length of the string: %d\n", length);

    return 0;
}
