// Returns address of maximum among three integers.

#include <stdio.h>

// Returns address of the maximum among three integers
int* maxOfThree(int *a, int *b, int *c) {
    if (*a >= *b && *a >= *c)
        return a;
    else if (*b >= *a && *b >= *c)
        return b;
    else
        return c;
}

int main() {
    int x = 42, y = 17, z = 99;
    int *maxPtr = maxOfThree(&x, &y, &z);

    printf("Maximum value: %d\n", *maxPtr);
    printf("Address of maximum: %p\n", (void*)maxPtr);

    return 0;
}
