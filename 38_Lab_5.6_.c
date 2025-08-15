// Compute Avergae and Scale float computeAverage(const int *arr, int n) - read-only access, void scaleGrades(int *arr, int n, float factor) - multiplies each grade. Use both on same data.

#include <stdio.h>

// Computes average of grades (read-only access)
float computeAverage(const int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (float)sum / n;
}

// Scales grades by a factor (in-place modification)
void scaleGrades(int *arr, int n, float factor) {
    for (int i = 0; i < n; i++) {
        arr[i] = (int)(arr[i] * factor);
    }
}

int main() {
    int grades[] = {70, 82, 65, 90};
    int n = sizeof(grades) / sizeof(grades[0]);

    // Compute average before scaling
    float avgBefore = computeAverage(grades, n);
    printf("Average before scaling: %.2f\n", avgBefore);

    // Scale grades by factor (e.g., 1.1 for 10% boost)
    float factor = 1.1f;
    scaleGrades(grades, n, factor);

    // Compute average after scaling
    float avgAfter = computeAverage(grades, n);
    printf("Average after scaling: %.2f\n", avgAfter);

    // Display scaled grades
    printf("Scaled grades:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", grades[i]);
    }
    printf("\n");

    return 0;
}
