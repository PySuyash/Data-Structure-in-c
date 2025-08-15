// Find the maximum and minimum values in an array using a pointer.

#include <stdio.h>

void findMaxMin(int *arr, int size, int *max, int *min) {
    *max = *arr;  // Initialize with first element
    *min = *arr;

    for (int i = 1; i < size; i++) {
        if (*(arr + i) > *max)
            *max = *(arr + i);
        if (*(arr + i) < *min)
            *min = *(arr + i);
    }
}

int main() {
    int arr[] = {23, 45, 12, 67, 34, 89, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    findMaxMin(arr, size, &max, &min);

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}
