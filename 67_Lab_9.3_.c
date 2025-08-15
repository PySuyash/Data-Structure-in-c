// Update salary via pointer. Write: void updateSalary(struct Employee *emp, double raise). Modifies salary via pointer to struct.

#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    double salary;
};

// Function to update salary using pointer
void updateSalary(struct Employee *emp, double raise) {
    if (emp != NULL) {
        emp->salary += raise;
        printf("Salary updated by ₹%.2lf for %s.\n", raise, emp->name);
    }
}

int main() {
    struct Employee e;

    // Input employee details
    printf("Enter Employee ID: ");
    scanf("%d", &e.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", e.name);

    printf("Enter Current Salary: ");
    scanf("%lf", &e.salary);

    // Input raise amount
    double raise;
    printf("Enter Raise Amount: ");
    scanf("%lf", &raise);

    // Update salary
    updateSalary(&e, raise);

    // Display updated details
    printf("\n--- Updated Employee Info ---\n");
    printf("ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Updated Salary: ₹%.2lf\n", e.salary);

    return 0;
}
