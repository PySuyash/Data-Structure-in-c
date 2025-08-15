// Split Number into Digits, Write: void splitNumber(int num, int **digits, int *count), Breaks num into digits, stores in dynamically allocate array via **digits, sets *count.

#include <stdio.h>
#include <stdlib.h>

// Splits number into digits and stores in dynamically allocated array
void splitNumber(int num, int **digits, int *count) {
    int temp = num;
    int digitCount = 0;

    // Count digits
    do {
        digitCount++;
        temp /= 10;
    } while (temp != 0);

    // Allocate memory for digits
    *digits = (int *)malloc(digitCount * sizeof(int));
    if (*digits == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Fill digits array (from last to first)
    temp = num;
    for (int i = digitCount - 1; i >= 0; i--) {
        (*digits)[i] = temp % 10;
        temp /= 10;
    }

    *count = digitCount;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int *digitArray = NULL;
    int digitCount = 0;

    splitNumber(number, &digitArray, &digitCount);

    printf("Digits:\n");
    for (int i = 0; i < digitCount; i++) {
        printf("%d ", digitArray[i]);
    }
    printf("\n");

    // Free memory
    free(digitArray);

    return 0;
}
