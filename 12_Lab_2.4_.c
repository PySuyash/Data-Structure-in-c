// Swap two numbers using pointers without using the third variables.

#include <stdio.h>

void swapArithmetic(int *x, int *y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

int main() {
    int a, b;

    // Input two numbers
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Swap using arithmetic
    printf("\nBefore swap (Arithmetic): a = %d, b = %d\n", a, b);
    swapArithmetic(&a, &b);
    printf("After swap (Arithmetic):  a = %d, b = %d\n", a, b);

    return 0;
}
