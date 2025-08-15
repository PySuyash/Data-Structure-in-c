// Update employee salary using pointer to structure.

#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    // Create pointer to Employee and allocate memory
    struct Employee *emp = (struct Employee*)malloc(sizeof(struct Employee));
    if (emp == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input employee details
    printf("Enter Employee ID: ");
    scanf("%d", &emp->id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp->name);

    printf("Enter Current Salary: ");
    scanf("%f", &emp->salary);

    // Display current salary
    printf("\nCurrent Salary of %s (ID: %d): ₹%.2f\n", emp->name, emp->id, emp->salary);

    // Update salary
    float increment;
    printf("Enter Salary Increment Amount: ");
    scanf("%f", &increment);

    emp->salary += increment;

    // Display updated salary
    printf("\nUpdated Salary of %s (ID: %d): ₹%.2f\n", emp->name, emp->id, emp->salary);

    // Free allocated memory
    free(emp);

    return 0;
}
