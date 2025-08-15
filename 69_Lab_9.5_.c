// Input and display student info using pointer to structure.

#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollNo;
    char name[50];
    int age;
    float marks;
};

int main() {
    // Create pointer to Student and allocate memory
    struct Student *s = (struct Student*)malloc(sizeof(struct Student));
    if (s == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input using pointer
    printf("Enter Roll Number: ");
    scanf("%d", &s->rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", s->name);

    printf("Enter Age: ");
    scanf("%d", &s->age);

    printf("Enter Marks: ");
    scanf("%f", &s->marks);

    // Display using pointer
    printf("\n--- Student Information ---\n");
    printf("Roll No: %d\n", s->rollNo);
    printf("Name: %s\n", s->name);
    printf("Age: %d\n", s->age);
    printf("Marks: %.2f\n", s->marks);

    // Free allocated memory
    free(s);

    return 0;
}
