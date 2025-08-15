// Find first Negative. int*findFirstNegative(int *arr, int n) - returns pointer to first negative or NULL, int countPositives(const int *arr, int n) - counts positives without modification.

#include <stdio.h>

// Returns pointer to first negative value or NULL
int* findFirstNegative(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            return &arr[i];
        }
    }
    return NULL;
}

// Counts positive values (read-only access)
int countPositives(const int *arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int grades[] = {75, -10, 88, 0, -5, 92};
    int n = sizeof(grades) / sizeof(grades[0]);

    // Find first negative
    int *negPtr = findFirstNegative(grades, n);
    if (negPtr != NULL) {
        printf("First negative grade: %d\n", *negPtr);
    } else {
        printf("No negative grades found.\n");
    }

    // Count positives
    int positiveCount = countPositives(grades, n);
    printf("Number of positive grades: %d\n", positiveCount);

    return 0;
}
