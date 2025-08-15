// Return student structure with entered details.

#include <stdio.h>

// Define Student structure
struct Student {
    int rollNo;
    char name[50];
    float marks;
};

// Function to create and return a Student structure
struct Student getStudentDetails() {
    struct Student s;

    printf("Enter Roll No: ");
    scanf("%d", &s.rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    return s;
}

int main() {
    // Get student details
    struct Student student = getStudentDetails();

    // Display student info
    printf("\n--- Student Details ---\n");
    printf("Roll No: %d\n", student.rollNo);
    printf("Name: %s\n", student.name);
    printf("Marks: %.2f\n", student.marks);

    return 0;
}
