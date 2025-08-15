// Modify multiple pointer values using pointer to pointer.

#include <stdio.h>
#include <stdlib.h>

// Function to modify multiple pointer values
void modifyPointers(int **p1, int **p2) {
    // Allocate memory and assign new values
    *p1 = (int *)malloc(sizeof(int));
    *p2 = (int *)malloc(sizeof(int));

    if (*p1 == NULL || *p2 == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    **p1 = 100;
    **p2 = 200;
}

int main() {
    int *a = NULL;
    int *b = NULL;

    modifyPointers(&a, &b);  // Pass addresses of pointers

    if (a != NULL && b != NULL) {
        printf("Modified value a: %d\n", *a);
        printf("Modified value b: %d\n", *b);
    }

    // Free allocated memory
    free(a);
    free(b);

    return 0;
}
