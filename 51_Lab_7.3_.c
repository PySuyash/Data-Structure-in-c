// Find Max Address. Write: int* findMaxAddress(int *arr, int n) Returns the address of the maximum element in the array.


#include <stdio.h>

// Returns the address of the maximum element in the array
int* findMaxAddress(int *arr, int n) {
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
    int data[] = {3, 17, 5, 9, 21, 4};
    int size = sizeof(data) / sizeof(data[0]);

    int *maxAddress = findMaxAddress(data, size);
    if (maxAddress != NULL) {
        printf("Maximum value: %d\n", *maxAddress);
        printf("Address of max: %p\n", (void*)maxAddress);
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}
