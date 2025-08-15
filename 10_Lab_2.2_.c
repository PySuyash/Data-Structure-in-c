// Dynamic memory for Int and Array Dynamically allocate memory for single integer, input a value, display it, then reallocates for n array of 5 integers and input/display them.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;

    // Step 1: Allocate memory for a single integer
    ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input and display the single integer
    printf("Enter a single integer: ");
    scanf("%d", ptr);
    printf("You entered: %d\n", *ptr);

    // Step 2: Reallocate memory for an array of 5 integers
    ptr = (int *)realloc(ptr, 5 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    // Input 5 integers
    printf("\nEnter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", ptr + i);  // Using pointer arithmetic
    }

    // Display the 5 integers
    printf("You entered: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // Free memory (optional but good practice)
    free(ptr);

    return 0;
}
