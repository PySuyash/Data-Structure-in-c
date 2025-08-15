// Find fctorial using pass by value.

#include <stdio.h>

// Function to compute factorial using pass-by-value
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num = 5;

    int fact = factorial(num);
    printf("Factorial of %d is %d\n", num, fact);
    printf("Original variable after function call: %d\n", num);  // Unchanged

    return 0;
}
