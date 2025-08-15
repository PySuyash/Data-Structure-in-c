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
