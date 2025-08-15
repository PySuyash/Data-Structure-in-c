// Cube a number using pass by reference.

#include <stdio.h>

// Function to cube a number using pass-by-reference
void cubeByReference(int *num) {
    *num = (*num) * (*num) * (*num);
}

int main() {
    int value = 3;

    printf("Original value: %d\n", value);
    cubeByReference(&value);
    printf("Cubed value (after pass-by-reference): %d\n", value);

    return 0;
}
