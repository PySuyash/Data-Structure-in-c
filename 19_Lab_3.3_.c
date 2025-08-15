// Modify a variable using a pointer to pointer passed to a function.


#include <stdio.h>

// Function that modifies the value using pointer to pointer
void modifyValue(int **ptr) {
    **ptr = 99;  // Change the value pointed to by the pointer
}

int main() {
    int num = 10;
    int *p = &num;

    printf("Before modification: %d\n", num);

    // Pass address of pointer (pointer to pointer)
    modifyValue(&p);

    printf("After modification: %d\n", num);

    return 0;
}
