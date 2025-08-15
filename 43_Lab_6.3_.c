// Resize Integer Array, Write: void resizeArray(int **arr, int oldSize, int newSize). Uses realloc via double pointer. Test with grow and shrink.

#include <stdio.h>
#include <stdlib.h>

// Resizes array using realloc via double pointer
void resizeArray(int **arr, int oldSize, int newSize) {
    int *temp = (int *)realloc(*arr, newSize * sizeof(int));
    if (temp == NULL) {
        printf("Reallocation failed.\n");
        exit(1);
    }

    // If growing, initialize new elements to 0
    if (newSize > oldSize) {
        for (int i = oldSize; i < newSize; i++) {
            temp[i] = 0;
        }
    }

    *arr = temp;
}

void printArray(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int oldSize = 5;
    int *array = (int *)malloc(oldSize * sizeof(int));
    if (array == NULL) {
        printf("Initial allocation failed.\n");
        return 1;
    }

    // Initialize array
    for (int i = 0; i < oldSize; i++) {
        array[i] = i + 1;
    }

    printf("Original array:\n");
    printArray(array, oldSize);

    // Grow array
    int newSize = 8;
    resizeArray(&array, oldSize, newSize);
    printf("Array after growing to size %d:\n", newSize);
    printArray(array, newSize);

    // Shrink array
    oldSize = newSize;
    newSize = 3;
    resizeArray(&array, oldSize, newSize);
    printf("Array after shrinking to size %d:\n", newSize);
    printArray(array, newSize);

    // Free memory
    free(array);

    return 0;
}
