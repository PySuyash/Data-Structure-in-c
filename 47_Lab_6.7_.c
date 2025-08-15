// Modify dynamic array using function with double pointer.

#include <stdio.h>
#include <stdlib.h>

// Modifies dynamic array using double pointer
void modifyArray(int **arr, int size) {
    for (int i = 0; i < size; i++) {
        (*arr)[i] *= 2;  // Example: double each value
    }
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize array
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }

    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Modify array
    modifyArray(&array, size);

    printf("Modified array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free memory
    free(array);

    return 0;
}
