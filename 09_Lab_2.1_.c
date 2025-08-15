// Swap and sort using pointers. Write a function void swapPointers(int *a, int *b) that swaps two integers using pointers. Use it to sort three numbers in ascending order.

#include <stdio.h>

// Swap function
void swapPointers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y, z;

    // Input three numbers
    printf("Enter three integers:\n");
    scanf("%d %d %d", &x, &y, &z);

    // Sort using swapPointers
    if (x > y) swapPointers(&x, &y);
    if (y > z) swapPointers(&y, &z);
    if (x > y) swapPointers(&x, &y);  // Final check

    // Output sorted numbers
    printf("Sorted in ascending order: %d %d %d\n", x, y, z);

    return 0;
}
