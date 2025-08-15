// Count even and odd numbers in an array using pointers.

#include <stdio.h>

void countEvenOdd(int *arr, int size, int *evenCount, int *oddCount) {
    int *ptr = arr;  // Pointer to start of array

    *evenCount = 0;
    *oddCount = 0;

    for (int i = 0; i < size; i++) {
        if (*(ptr + i) % 2 == 0)
            (*evenCount)++;
        else
            (*oddCount)++;
    }
}

int main() {
    int arr[] = {12, 7, 9, 20, 33, 18, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int even, odd;

    countEvenOdd(arr, size, &even, &odd);

    printf("Even numbers: %d\n", even);
    printf("Odd numbers: %d\n", odd);

    return 0;
}
