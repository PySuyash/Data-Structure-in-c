// Swap two structure records using pointer.

#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

// Function to swap two Student records using pointers
void swapRecords(struct Student *a, struct Student *b) {
    struct Student temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    struct Student s1, s2;

    // Input first student
    printf("Enter details for Student 1:\n");
    printf("Roll No: ");
    scanf("%d", &s1.rollNo);
    printf("Name: ");
    scanf(" %[^\n]", s1.name);
    printf("Marks: ");
    scanf("%f", &s1.marks);

    // Input second student
    printf("\nEnter details for Student 2:\n");
    printf("Roll No: ");
    scanf("%d", &s2.rollNo);
    printf("Name: ");
    scanf(" %[^\n]", s2.name);
    printf("Marks: ");
    scanf("%f", &s2.marks);

    // Display before swap
    printf("\n--- Before Swap ---\n");
    printf("Student 1: %d, %s, %.2f\n", s1.rollNo, s1.name, s1.marks);
    printf("Student 2: %d, %s, %.2f\n", s2.rollNo, s2.name, s2.marks);

    // Swap using pointers
    swapRecords(&s1, &s2);

    // Display after swap
    printf("\n--- After Swap ---\n");
    printf("Student 1: %d, %s, %.2f\n", s1.rollNo, s1.name, s1.marks);
    printf("Student 2: %d, %s, %.2f\n", s2.rollNo, s2.name, s2.marks);

    return 0;
}
