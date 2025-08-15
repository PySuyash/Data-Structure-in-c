// Increment and Log. Write: void incrementAndLog(int *value, int by) - increases value and prints old/new int logOnly(int value) - returns value + by without modifying original demonstrate difference.

#include <stdio.h>

// Modifies original value and logs change
void incrementAndLog(int *value, int by) {
    int old = *value;
    *value += by;
    printf("incrementAndLog: Old value = %d, New value = %d\n", old, *value);
}

// Returns incremented value without modifying original
int logOnly(int value, int by) {
    int result = value + by;
    printf("logOnly: Original = %d, Result = %d\n", value, result);
    return result;
}

int main() {
    int num = 10;
    int by = 5;

    // Using logOnly
    int result = logOnly(num, by);
    printf("After logOnly:\n");
    printf("Returned result: %d\n", result);
    printf("Original variable: %d\n\n", num);  // Unchanged

    // Using incrementAndLog
    incrementAndLog(&num, by);
    printf("After incrementAndLog:\n");
    printf("Modified variable: %d\n", num);  // Changed

    return 0;
}
