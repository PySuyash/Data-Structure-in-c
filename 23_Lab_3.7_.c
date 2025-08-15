// Allocate array via double pointer. Write a function void allocateArray(int **ptr, int size) that alloctes memory for size integers and initilizes them to 0. Use in main and free afterwards.

#include <stdio.h>
#include <stdlib.h>

// Function to allocate and initialize array
void allocateArray(int **ptr, int size) {
    *ptr = (int *)malloc(size * sizeof(int));
    if (*ptr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Initialize all elements to 0
    for (int i = 0; i < size; i++) {
        (*ptr)[i] = 0;
    }
}

int main() {
    int *array = NULL;
    int size = 5;

    // Allocate array via double pointer
    allocateArray(&array, size);

    // Display initialized array
    if (array != NULL) {
        printf("Initialized array:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");

        // Free memory
        free(array);
    }

    return 0;
}
