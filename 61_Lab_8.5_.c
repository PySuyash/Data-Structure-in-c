// Array of Block structure with dynamics title allocation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BLOCKS 3
#define MAX_TITLE_LEN 100

struct Block {
    int id;
    char *title;  // Dynamically allocated
    float size;
};

int main() {
    struct Block blocks[NUM_BLOCKS];

    // Input block details
    for (int i = 0; i < NUM_BLOCKS; i++) {
        printf("Enter details for Block %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &blocks[i].id);

        // Allocate memory for title
        blocks[i].title = (char*)malloc(MAX_TITLE_LEN * sizeof(char));
        if (blocks[i].title == NULL) {
            printf("Memory allocation failed for title.\n");
            return 1;
        }

        printf("Title: ");
        scanf(" %[^\n]", blocks[i].title);  // Read full title with spaces

        printf("Size: ");
        scanf("%f", &blocks[i].size);
    }

    // Display block details
    printf("\n--- Block Information ---\n");
    for (int i = 0; i < NUM_BLOCKS; i++) {
        printf("Block %d:\n", i + 1);
        printf("ID: %d\n", blocks[i].id);
        printf("Title: %s\n", blocks[i].title);
        printf("Size: %.2f\n", blocks[i].size);
    }

    // Free allocated memory
    for (int i = 0; i < NUM_BLOCKS; i++) {
        free(blocks[i].title);
    }

    return 0;
}
