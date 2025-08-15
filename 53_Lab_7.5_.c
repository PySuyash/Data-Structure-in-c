// Returns address of the largest element in array.

#include <stdio.h>

// Returns address of the largest element in the array
int* findLargestAddress(int *arr, int n) {
    if (arr == NULL || n <= 0) return NULL;

    int *maxPtr = arr;
    for (int i = 1; i < n; i++) {
        if (arr[i] > *maxPtr) {
            maxPtr = &arr[i];
        }
    }
    return maxPtr;
}

int main() {
    int data[] = {12, 45, 7, 89, 33};
    int size = sizeof(data) / sizeof(data[0]);

    int *largest = findLargestAddress(data, size);
    if (largest != NULL) {
        printf("Largest value: %d\n", *largest);
        printf("Address of largest: %p\n", (void*)largest);
    } else {
        printf("Invalid array.\n");
    }

    return 0;
}
