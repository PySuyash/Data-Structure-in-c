// Convert structure string to uppercase using pointer.

#include <stdio.h>
#include <ctype.h>

// Define structure with a string member
struct Person {
    char name[100];
};

// Function to convert name to uppercase (pass by address)
void toUppercase(struct Person *p) {
    for (int i = 0; p->name[i] != '\0'; i++) {
        p->name[i] = toupper(p->name[i]);
    }
}

int main() {
    struct Person person;

    // Input name
    printf("Enter name: ");
    scanf(" %[^\n]", person.name);

    // Convert to uppercase
    toUppercase(&person);

    // Display result
    printf("\nUppercase Name: %s\n", person.name);

    return 0;
}
