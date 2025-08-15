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
