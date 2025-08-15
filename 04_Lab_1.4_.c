// Reverse an array using pointer arithmatics.

#include <stdio.h>

void reverseArray(int *arr, int size) {
    int *start = arr;           // Pointer to first element
    int *end = arr + size - 1;  // Pointer to last element
    int temp;

    while (start < end) {
        // Swap values using pointers
        temp = *start;
        *start = *end;
        *end = temp;

        // Move pointers
        start++;
        end--;
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }

    reverseArray(arr, size);

    printf("\nReversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }

    return 0;
}
