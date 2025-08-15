// Given an array of 6 strings (using char arr[6][50]), use a pointer to char to search for a user given string and returns its index using pointers arithmatics.

#include <stdio.h>
#include <string.h>

int main() {
    char arr[6][50];
    char search[50];
    char *ptr;
    int i;

    // Input 6 strings
    printf("Enter 6 strings:\n");
    for (i = 0; i < 6; i++) {
        scanf("%s", arr[i]);
    }

    // Input string to search
    printf("\nEnter string to search: ");
    scanf("%s", search);

    // Search using pointer arithmetic
    for (i = 0; i < 6; i++) {
        ptr = *(arr + i);  // Pointer to the i-th string
        if (strcmp(ptr, search) == 0) {
            printf("\nString found at index %d\n", i);
            return 0;
        }
    }

    printf("\nString not found.\n");
    return 0;
}
