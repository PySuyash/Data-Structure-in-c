// Dynamically allocate and modify a string using a double pointer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to allocate and modify the string
void modifyString(char **str) {
    *str = (char *)malloc(50 * sizeof(char));  // Allocate memory
    if (*str == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(*str, "Hello from inside the function!");
}

int main() {
    char *myString = NULL;

    modifyString(&myString);  // Pass address of pointer

    if (myString != NULL) {
        printf("Modified string: %s\n", myString);
        free(myString);  // Free allocated memory
    }

    return 0;
}
