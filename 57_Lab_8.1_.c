// Student with Dynamic GPA
/*
struct Student {
int id;
char name[30];
float *gpa;
char dept[20];
};
Dynamically allocate gpa for 3 students and input values.
*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_STUDENTS 3

struct Student {
    int id;
    char name[30];
    float *gpa;
    char dept[20];
};

int main() {
    struct Student students[NUM_STUDENTS];

    // Allocate GPA dynamically and input values
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter details for student %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf(" %[^\n]", students[i].name);  // Reads full name with spaces

        printf("Department: ");
        scanf(" %[^\n]", students[i].dept);

        // Allocate memory for GPA
        students[i].gpa = (float*)malloc(sizeof(float));
        if (students[i].gpa == NULL) {
            printf("Memory allocation failed for GPA.\n");
            return 1;
        }

        printf("GPA: ");
        scanf("%f", students[i].gpa);
    }

    // Display student data
    printf("\n--- Student Details ---\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Department: %s\n", students[i].dept);
        printf("GPA: %.2f\n", *(students[i].gpa));
    }

    // Free allocated memory
    for (int i = 0; i < NUM_STUDENTS; i++) {
        free(students[i].gpa);
    }

    return 0;
}
