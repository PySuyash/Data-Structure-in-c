// Return second largest element in an array.

#include <stdio.h>
#include <limits.h>

// Function to find second largest element
int findSecondLargest(int *arr, int size) {
    if (size < 2) {
        printf("Array must have at least two elements.\n");
        return INT_MIN;
    }

    int largest = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < size; i++) {
        int value = *(arr + i);

        if (value > largest) {
            second = largest;
            largest = value;
        } else if (value > second && value < largest) {
            second = value;
        }
    }

    return second;
}

int main() {
    int data[] = {12, 45, 7, 89, 45, 89, 33};
    int size = sizeof(data) / sizeof(data[0]);

    int secondLargest = findSecondLargest(data, size);
    if (secondLargest != INT_MIN) {
        printf("Second largest element: %d\n", secondLargest);
    }

    return 0;
}
