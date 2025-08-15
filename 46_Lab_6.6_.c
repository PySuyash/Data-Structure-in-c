// Pass array of strings using double pointers.

#include <stdio.h>

// Prints array of strings using double pointer
void printNames(char **names, int count) {
    for (int i = 0; i < count; i++) {
        printf("Name %d: %s\n", i + 1, names[i]);
    }
}

int main() {
    // Static array of string literals
    char *names[] = {
        "Alice",
        "Bob",
        "Charlie",
        "Diana"
    };

    int count = sizeof(names) / sizeof(names[0]);

    // Pass array of strings to function
    printNames(names, count);

    return 0;
}
