// Double one variable and triple another using pass by reference.

#include <stdio.h>

// Function to double one variable and triple another
void doubleAndTriple(int *a, int *b) {
    *a = (*a) * 2;
    *b = (*b) * 3;
}

int main() {
    int x = 4;
    int y = 5;

    printf("Before:\n");
    printf("x = %d, y = %d\n", x, y);

    doubleAndTriple(&x, &y);

    printf("\nAfter doubleAndTriple:\n");
    printf("x (doubled) = %d\n", x);
    printf("y (tripled) = %d\n", y);

    return 0;
}
