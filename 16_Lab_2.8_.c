// Dynamic Integer creator. Write a function int* createAndInit(int value) that dynamically creates an integer, assigns value, and returns its address. In main, use it for three values, print them, then free memory.

#include <stdio.h>
#include <stdlib.h>

// Function to dynamically create and initialize an integer
int* createAndInit(int value) {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);  // Exit if allocation fails
    }
    *ptr = value;
    return ptr;
}

int main() {
    // Create three dynamically allocated integers
    int *a = createAndInit(10);
    int *b = createAndInit(20);
    int *c = createAndInit(30);

    // Print the values
    printf("a = %d\n", *a);
    printf("b = %d\n", *b);
    printf("c = %d\n", *c);

    // Free the allocated memory
    free(a);
    free(b);
    free(c);

    return 0;
}
