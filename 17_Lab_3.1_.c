// Dynamic student Names. Use char **names to dynamically store 4 student names. Allocates each string dynamically. Input and display all names using double pointer access.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int count = 4;
    char **names;

    // Allocate memory for 4 pointers to strings
    names = (char **)malloc(count * sizeof(char *));
    if (names == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input each name
    for (int i = 0; i < count; i++) {
        char temp[100];
        printf("Enter name %d: ", i + 1);
        scanf("%s", temp);  // Reads one word

        // Allocate memory for the actual name
        *(names + i) = (char *)malloc(strlen(temp) + 1);
        if (*(names + i) == NULL) {
            printf("Memory allocation failed for name %d.\n", i + 1);
            return 1;
        }

        // Copy name into allocated space
        strcpy(*(names + i), temp);
    }

    // Display all names
    printf("\nStudent Names:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", *(names + i));
    }

    // Free all allocated memory
    for (int i = 0; i < count; i++) {
        free(*(names + i));
    }
    free(names);

    return 0;
}
