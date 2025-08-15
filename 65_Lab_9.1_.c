// Input Student via Pointer. Define struct Book {id, title, author, pages}. Create pointers, use -> to input and display.

#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100

struct Book {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;
};

int main() {
    // Create a pointer to Book and allocate memory
    struct Book *b = (struct Book*)malloc(sizeof(struct Book));
    if (b == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input using -> operator
    printf("Enter Book ID: ");
    scanf("%d", &b->id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", b->title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b->author);

    printf("Enter Number of Pages: ");
    scanf("%d", &b->pages);

    // Display using -> operator
    printf("\n--- Book Details ---\n");
    printf("ID: %d\n", b->id);
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("Pages: %d\n", b->pages);

    // Free allocated memory
    free(b);

    return 0;
}
