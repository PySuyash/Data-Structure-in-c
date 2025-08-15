// Sort books by price using the pointer to title.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BOOKS 3
#define MAX_TITLE_LEN 100

struct Book {
    int id;
    char *title;     // Dynamically allocated
    int pages;
    double price;
};

// Swap two Book structures
void swap(struct Book *a, struct Book *b) {
    struct Book temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    struct Book books[NUM_BOOKS];

    // Input book details
    for (int i = 0; i < NUM_BOOKS; i++) {
        printf("Enter details for Book %d:\n", i + 1);

        books[i].title = (char*)malloc(MAX_TITLE_LEN * sizeof(char));
        if (books[i].title == NULL) {
            printf("Memory allocation failed for title.\n");
            return 1;
        }

        printf("ID: ");
        scanf("%d", &books[i].id);

        printf("Title: ");
        scanf(" %[^\n]", books[i].title);

        printf("Pages: ");
        scanf("%d", &books[i].pages);

        printf("Price (INR): ");
        scanf("%lf", &books[i].price);
    }

    // Sort books by price (ascending)
    for (int i = 0; i < NUM_BOOKS - 1; i++) {
        for (int j = i + 1; j < NUM_BOOKS; j++) {
            if (books[i].price > books[j].price) {
                swap(&books[i], &books[j]);
            }
        }
    }

    // Display sorted books
    printf("\n--- Books Sorted by Price ---\n");
    for (int i = 0; i < NUM_BOOKS; i++) {
        printf("Book %d:\n", i + 1);
        printf("ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);  // Access via pointer
        printf("Pages: %d\n", books[i].pages);
        printf("Price: ₹%.2lf\n", books[i].price);
    }

    // Free allocated memory
    for (int i = 0; i < NUM_BOOKS; i++) {
        free(books[i].title);
    }

    return 0;
}
