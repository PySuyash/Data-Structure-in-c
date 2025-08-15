// Swap and double, Write void swapAndDouble(int *a, int *b) that swaps the values and doubles both. Also write int maxOfTwo(int a, int b) (pass by value) to return the larger.

#include <stdio.h>

// Swap and double using pass-by-reference
void swapAndDouble(int *a, int *b) {
    // Swap
    int temp = *a;
    *a = *b;
    *b = temp;

    // Double both
    *a *= 2;
    *b *= 2;
}

// Return max using pass-by-value
int maxOfTwo(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 3, y = 5;

    printf("Before swapAndDouble:\n");
    printf("x = %d, y = %d\n", x, y);

    swapAndDouble(&x, &y);

    printf("\nAfter swapAndDouble:\n");
    printf("x = %d, y = %d\n", x, y);

    int max = maxOfTwo(x, y);
    printf("\nMaximum of x and y: %d\n", max);

    return 0;
}
