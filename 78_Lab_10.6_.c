// Pass Employee structure and display.

#include <stdio.h>

// Define Employee structure
struct Employee {
    int id;
    char name[50];
    float salary;
};

// Function to display Employee details (pass by value)
void displayEmployee(struct Employee emp) {
    printf("\n--- Employee Details ---\n");
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Salary: ₹%.2f\n", emp.salary);
}

int main() {
    struct Employee e;

    // Input employee details
    printf("Enter Employee ID: ");
    scanf("%d", &e.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", e.name);

    printf("Enter Salary: ");
    scanf("%f", &e.salary);

    // Pass structure to function
    displayEmployee(e);

    return 0;
}
