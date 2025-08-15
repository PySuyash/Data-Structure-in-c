// Input 8 test scores. Use a pointer to traverse the array and count how many scores are within +-10 points of the averages. Compute average using pointer traversal.

#include <stdio.h>

int main() {
    int scores[8];
    int *ptr;
    float sum = 0, average;
    int count = 0;

    // Input 8 test scores
    printf("Enter 8 test scores:\n");
    for (ptr = scores; ptr < scores + 8; ptr++) {
        scanf("%d", ptr);
    }

    // Compute the sum using pointer traversal
    for (ptr = scores; ptr < scores + 8; ptr++) {
        sum += *ptr;
    }

    average = sum / 8;

    // Count scores within ±10 of the average
    for (ptr = scores; ptr < scores + 8; ptr++) {
        if (*ptr >= average - 10 && *ptr <= average + 10) {
            count++;
        }
    }

    // Display results
    printf("\nAverage score: %.2f\n", average);
    printf("Number of scores within ±10 of average: %d\n", count);

    return 0;
}
