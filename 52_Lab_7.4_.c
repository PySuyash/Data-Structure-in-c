// Static counter function. Write: int* counter() Returns address of a static counter (incremented each call). Demonstrate persistence.

#include <stdio.h>

// Returns address of a static counter that increments each call
int* counter() {
    static int count = 0;  // Static variable retains value across calls
    count++;
    return &count;
}

int main() {
    int *c1 = counter();
    printf("Call 1: %d\n", *c1);

    int *c2 = counter();
    printf("Call 2: %d\n", *c2);

    int *c3 = counter();
    printf("Call 3: %d\n", *c3);

    // All pointers point to the same static variable
    printf("Same address? %s\n", (c1 == c2 && c2 == c3) ? "Yes" : "No");

    return 0;
}
