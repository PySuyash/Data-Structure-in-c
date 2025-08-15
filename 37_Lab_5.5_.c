// Modify and Copy Grades, void modifyGrades(int *arr, int n) - adds 5 to each grade, int* copyGrades(const int* src, int n) - returns new dynamically allocated array. Compare original and copy.

#include <stdio.h>
#include <stdlib.h>

// Adds 5 to each grade (in-place modification)
void modifyGrades(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] += 5;
    }
}

// Returns a new copy of the array (dynamically allocated)
int* copyGrades(const int *src, int n) {
    int *copy = (int *)malloc(n * sizeof(int));
    if (copy == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        copy[i] = src[i];
    }

    return copy;
}

int main() {
    int grades[] = {70, 82, 65, 90};
    int n = sizeof(grades) / sizeof(grades[0]);

    // Create a copy before modification
    int *originalCopy = copyGrades(grades, n);

    // Modify original grades
    modifyGrades(grades, n);

    // Display comparison
    printf("Original grades after modification:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", grades[i]);
    }

    printf("\nCopied grades (before modification):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", originalCopy[i]);
    }
    printf("\n");

    // Free memory
    free(originalCopy);

    return 0;
}
