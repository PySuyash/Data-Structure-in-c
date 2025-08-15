// Calculate average using array passed by reference.

#include <stdio.h>

// Function to calculate average of array elements
float calculateAverage(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (float)sum / size;
}

int main() {
    int marks[] = {85, 90, 78, 92, 88};
    int size = sizeof(marks) / sizeof(marks[0]);

    float average = calculateAverage(marks, size);
    printf("Average marks: %.2f\n", average);

    return 0;
}
