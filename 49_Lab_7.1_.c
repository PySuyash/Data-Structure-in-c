// Create Dynamic Array. Write: int* createArray(int size) , Returns pointer to Zero-initilized dynamically allocated integer array.

#include <stdio.h>
#include <stdlib.h>

// Creates and returns a zero-initialized dynamic array
int* createArray(int size) {
    int *arr = (int *)calloc(size, sizeof(int));  // calloc initializes to 0
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return arr;
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int *array = createArray(size);

    printf("Zero-initialized array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free memory
    free(array);

    return 0;
}
