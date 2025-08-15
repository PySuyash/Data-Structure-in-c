// Simple calculator using function pointers (add, sub, mul, div).

#include <stdio.h>

// Function declarations
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

int main() {
    int a, b, choice;
    int (*operation)(int, int);  // Function pointer

    // Input numbers
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Menu
    printf("\nChoose operation:\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    // Assign function pointer based on choice
    switch (choice) {
        case 1: operation = add; break;
        case 2: operation = sub; break;
        case 3: operation = mul; break;
        case 4: operation = divide; break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    // Call the selected function
    int result = operation(a, b);
    printf("Result: %d\n", result);

    return 0;
}
