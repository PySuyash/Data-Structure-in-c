// Apply discount on books priced over INR 500.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BOOKS 3
#define MAX_TITLE_LEN 100
#define DISCOUNT_RATE 0.10  // 10% discount

struct Book {
    int id;
    char *title;     // Dynamically allocated
    double price;
};

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

        printf("Price (INR): ");
        scanf("%lf", &books[i].price);
    }

    // Apply discount
    for (int i = 0; i < NUM_BOOKS; i++) {
        if (books[i].price > 500.0) {
            double discount = books[i].price * DISCOUNT_RATE;
            books[i].price -= discount;
            printf("\nDiscount of ₹%.2lf applied to \"%s\"\n", discount, books[i].title);
        }
    }

    // Display updated book details
    printf("\n--- Updated Book List ---\n");
    for (int i = 0; i < NUM_BOOKS; i++) {
        printf("Book %d:\n", i + 1);
        printf("ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Price: ₹%.2lf\n", books[i].price);
    }

    // Free allocated memory
    for (int i = 0; i < NUM_BOOKS; i++) {
        free(books[i].title);
    }

    return 0;
}
