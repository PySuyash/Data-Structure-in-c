// Update all negative numbers to zero using pointer.

#include <stdio.h>

// Function to update negative numbers to zero
void sanitizeArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) < 0) {
            *(arr + i) = 0;
        }
    }
}

int main() {
    int data[] = {12, -7, 45, -3, 0, 19, -22};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }

    sanitizeArray(data, size);  // Modify array in-place

    printf("\nSanitized array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }

    return 0;
}
