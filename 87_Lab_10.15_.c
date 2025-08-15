// Read and return an employee record.

#include <stdio.h>

// Define Employee structure
struct Employee {
    int id;
    char name[50];
    float salary;
};

// Function to read and return an Employee record
struct Employee readEmployee() {
    struct Employee emp;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp.name);

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    return emp;
}

int main() {
    // Read employee record
    struct Employee e = readEmployee();

    // Display employee details
    printf("\n--- Employee Record ---\n");
    printf("ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Salary: ₹%.2f\n", e.salary);

    return 0;
}
