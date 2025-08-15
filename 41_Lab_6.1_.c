// Allocates Names list, Write: void allocateNames(char ***list, int n) .It allocates n string pointers. In main, allocate each string and input names.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

// Allocates memory for n string pointers
void allocateNames(char ***list, int n) {
    *list = (char **)malloc(n * sizeof(char *));
    if (*list == NULL) {
        printf("Memory allocation for name list failed.\n");
        exit(1);
    }
}

int main() {
    int n;
    printf("Enter number of names: ");
    scanf("%d", &n);

    char **names;
    allocateNames(&names, n);

    // Allocate each string and input names
    for (int i = 0; i < n; i++) {
        names[i] = (char *)malloc(MAX_NAME_LEN * sizeof(char));
        if (names[i] == NULL) {
            printf("Memory allocation for name %d failed.\n", i + 1);
            exit(1);
        }

        printf("Enter name %d: ", i + 1);
        scanf(" %99[^\n]", names[i]);  // Read up to 99 characters including spaces
    }

    // Print names
    printf("\nNames entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(names[i]);
    }
    free(names);

    return 0;
}
