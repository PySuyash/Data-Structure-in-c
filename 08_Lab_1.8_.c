// Input 7 integers. Use a pointer to find and swap the first and last even numbers in the array. If fewer than two even numbers exist, print an error.

#include <stdio.h>

int main() {
    int arr[7];
    int *ptr = arr;
    int *firstEven = NULL, *lastEven = NULL;

    // Input 7 integers
    printf("Enter 7 integers:\n");
    for (int i = 0; i < 7; i++) {
        scanf("%d", ptr + i);
    }

    // Find first even number
    for (int i = 0; i < 7; i++) {
        if (*(ptr + i) % 2 == 0) {
            firstEven = ptr + i;
            break;
        }
    }

    // Find last even number
    for (int i = 6; i >= 0; i--) {
        if (*(ptr + i) % 2 == 0) {
            lastEven = ptr + i;
            break;
        }
    }

    // Check if both even numbers are found and not the same
    if (firstEven == NULL || lastEven == NULL || firstEven == lastEven) {
        printf("Error: Fewer than two even numbers found.\n");
    } else {
        // Swap the values
        int temp = *firstEven;
        *firstEven = *lastEven;
        *lastEven = temp;

        // Print the modified array
        printf("Modified array:\n");
        for (int i = 0; i < 7; i++) {
            printf("%d ", *(ptr + i));
        }
        printf("\n");
    }

    return 0;
}
