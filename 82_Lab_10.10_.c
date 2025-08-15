// Update students marks via address passing.

#include <stdio.h>

// Define Student structure
struct Student {
    int rollNo;
    char name[50];
    float marks;
};

// Function to update marks (pass by address)
void updateMarks(struct Student *s, float newMarks) {
    s->marks = newMarks;
}

int main() {
    struct Student st;

    // Input student details
    printf("Enter Roll No: ");
    scanf("%d", &st.rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", st.name);

    printf("Enter Current Marks: ");
    scanf("%f", &st.marks);

    // Display before update
    printf("\n--- Before Update ---\n");
    printf("Roll No: %d\n", st.rollNo);
    printf("Name: %s\n", st.name);
    printf("Marks: %.2f\n", st.marks);

    // Update marks
    float newMarks;
    printf("\nEnter New Marks: ");
    scanf("%f", &newMarks);
    updateMarks(&st, newMarks);

    // Display after update
    printf("\n--- After Update ---\n");
    printf("Roll No: %d\n", st.rollNo);
    printf("Name: %s\n", st.name);
    printf("Marks: %.2f\n", st.marks);

    return 0;
}
