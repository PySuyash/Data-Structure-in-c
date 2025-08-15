// Append one string to another using double pointer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appends src to *dest using realloc and double pointer
void appendString(char **dest, const char *src) {
    size_t lenDest = strlen(*dest);
    size_t lenSrc = strlen(src);

    // Reallocate memory to hold combined string + null terminator
    char *temp = (char *)realloc(*dest, (lenDest + lenSrc + 1) * sizeof(char));
    if (temp == NULL) {
        printf("Memory reallocation failed.\n");
        exit(1);
    }

    // Append src to the end of temp
    strcat(temp, src);

    *dest = temp;  // Update original pointer
}

int main() {
    // Initial string
    char *text = (char *)malloc(50 * sizeof(char));
    if (text == NULL) {
        printf("Initial allocation failed.\n");
        return 1;
    }

    strcpy(text, "Hello");

    // String to append
    const char *extra = " World!";

    // Append using double pointer
    appendString(&text, extra);

    printf("Appended string: %s\n", text);

    // Free memory
    free(text);

    return 0;
}
