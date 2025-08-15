// Create and fill a dynamic array using double pointer.

#include <stdio.h>
#include <stdlib.h>

// Creates and fills a dynamic array using double pointer
void createAndFillArray(int **arr, int n) {
    *arr = (int *)malloc(n * sizeof(int));
    if (*arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        (*arr)[i] = i + 1;  // Fill with sample values
    }
}

int main() {
    int *array = NULL;
    int size;

    printf("Enter size of array: ");
    scanf("%d", &size);

    createAndFillArray(&array, size);

    printf("Filled array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free memory
    free(array);

    return 0;
}
