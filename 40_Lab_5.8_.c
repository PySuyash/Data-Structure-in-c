// sort and Print Array. void sortAray(int *arr, int n) - sorts in ascending order (modifies), void prntArray(const int *arr, int n) - prints without modifying.

#include <stdio.h>

// Sorts array in ascending order (in-place)
void sortArray(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Prints array (read-only)
void printArray(const int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int grades[] = {88, 72, 95, 60, 83};
    int n = sizeof(grades) / sizeof(grades[0]);

    printf("Original array:\n");
    printArray(grades, n);

    sortArray(grades, n);

    printf("Sorted array:\n");
    printArray(grades, n);

    return 0;
}
