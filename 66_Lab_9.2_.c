// Traverse Employee Array Use array of struct Employee and a pointer to traverse and display all using pointer arithmatics: ptr++.


#include <stdio.h>
#include <string.h>

#define NUM_EMPLOYEES 3

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee emp[NUM_EMPLOYEES];

    // Input employee details
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        printf("Enter details for Employee %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &emp[i].id);

        printf("Name: ");
        scanf(" %[^\n]", emp[i].name);

        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    // Pointer to Employee
    struct Employee *ptr = emp;

    // Traverse and display using pointer arithmetic
    printf("\n--- Employee Details ---\n");
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: %d\n", ptr->id);
        printf("Name: %s\n", ptr->name);
        printf("Salary: %.2f\n", ptr->salary);
        ptr++;  // Move to next employee
    }

    return 0;
}
