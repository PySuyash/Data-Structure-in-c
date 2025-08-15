// Count books with pages > 300 and prices > INR 500.

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

int main() {
    struct Book books[NUM_BOOKS];
    int count = 0;

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

        // Count condition
        if (books[i].pages > 300 && books[i].price > 500.0) {
            count++;
        }
    }

    // Display result
    printf("\nNumber of books with >300 pages and price >₹500: %d\n", count);

    // Free allocated memory
    for (int i = 0; i < NUM_BOOKS; i++) {
        free(books[i].title);
    }

    return 0;
}
