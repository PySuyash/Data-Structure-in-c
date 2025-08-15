// Node: Copy and Initilize. struct Node copyNode(struct Node n) - returns copy. void initNode(struct Node *node, int id) - initilizes via pointer. Include char *name as pointer member.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Node structure
struct Node {
    int id;
    char *name;
};

// Function to initialize a Node via pointer
void initNode(struct Node *node, int id) {
    node->id = id;

    char temp[100];
    printf("Enter name for Node %d: ", id);
    scanf(" %[^\n]", temp);

    // Allocate memory and copy name
    node->name = (char *)malloc(strlen(temp) + 1);
    if (node->name != NULL) {
        strcpy(node->name, temp);
    }
}

// Function to copy a Node (deep copy)
struct Node copyNode(struct Node n) {
    struct Node newNode;
    newNode.id = n.id;

    // Allocate memory and copy name
    newNode.name = (char *)malloc(strlen(n.name) + 1);
    if (newNode.name != NULL) {
        strcpy(newNode.name, n.name);
    }

    return newNode;
}

int main() {
    struct Node original;

    // Initialize original node
    initNode(&original, 101);

    // Copy the node
    struct Node duplicate = copyNode(original);

    // Display both nodes
    printf("\n--- Original Node ---\n");
    printf("ID: %d\n", original.id);
    printf("Name: %s\n", original.name);

    printf("\n--- Copied Node ---\n");
    printf("ID: %d\n", duplicate.id);
    printf("Name: %s\n", duplicate.name);

    // Free allocated memory
    free(original.name);
    free(duplicate.name);

    return 0;
}
