// Student: Print, Update, Create void printStudent(struct Student s) - pass by value. void updateGPA(struct student *s, float gpa) - pass by address. struct Student createStudent() -returns structure.

#include <stdio.h>
#include <string.h>

// Define the Student structure
struct Student {
    int rollNo;
    char name[50];
    float gpa;
};

// Function to print student details (pass by value)
void printStudent(struct Student s) {
    printf("\n--- Student Info ---\n");
    printf("Roll No: %d\n", s.rollNo);
    printf("Name: %s\n", s.name);
    printf("GPA: %.2f\n", s.gpa);
}

// Function to update GPA (pass by address)
void updateGPA(struct Student *s, float gpa) {
    s->gpa = gpa;
}

// Function to create and return a Student structure
struct Student createStudent() {
    struct Student s;
    printf("Enter Roll No: ");
    scanf("%d", &s.rollNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter GPA: ");
    scanf("%f", &s.gpa);
    return s;
}

int main() {
    // Create a student using createStudent
    struct Student student1 = createStudent();

    // Print student info
    printStudent(student1);

    // Update GPA
    float newGPA;
    printf("\nEnter new GPA to update: ");
    scanf("%f", &newGPA);
    updateGPA(&student1, newGPA);

    // Print updated student info
    printStudent(student1);

    return 0;
}
