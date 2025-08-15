// Find the frequency of an element using array pointer.

#include <stdio.h>

// Function to count frequency of a target element
int countFrequency(int *arr, int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int numbers[] = {4, 2, 7, 4, 9, 4, 2, 4};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target = 4;

    int frequency = countFrequency(numbers, size, target);
    printf("Frequency of %d: %d\n", target, frequency);

    return 0;
}
