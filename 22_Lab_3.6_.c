// Secure password update system using pointer to pointer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to securely update the password
void updatePassword(char **password) {
    char temp[100];

    printf("Enter new password: ");
    scanf("%s", temp);  // Reads until whitespace

    // Free old password if it exists
    if (*password != NULL) {
        free(*password);
    }

    // Allocate new memory and copy password
    *password = (char *)malloc(strlen(temp) + 1);
    if (*password == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(*password, temp);
    printf("Password updated successfully.\n");
}

int main() {
    char *password = NULL;

    // Initial password setup
    updatePassword(&password);

    // Simulate password update
    printf("\nUpdating password again...\n");
    updatePassword(&password);

    // Display final password (for demo purposes only)
    printf("\nFinal password: %s\n", password);

    // Free memory
    free(password);

    return 0;
}
