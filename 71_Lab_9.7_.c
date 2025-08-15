// Display movies with rating > 8 using structure pointer.

#include <stdio.h>
#include <stdlib.h>

struct Movie {
    char title[100];
    char director[50];
    float rating;
};

int main() {
    int n;
    printf("Enter number of movies: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n movies
    struct Movie *m = (struct Movie*)malloc(n * sizeof(struct Movie));
    if (m == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input movie details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Movie %d:\n", i + 1);
        printf("Title: ");
        scanf(" %[^\n]", m[i].title);
        printf("Director: ");
        scanf(" %[^\n]", m[i].director);
        printf("Rating (out of 10): ");
        scanf("%f", &m[i].rating);
    }

    // Display movies with rating > 8
    printf("\n--- Movies with Rating > 8 ---\n");
    for (int i = 0; i < n; i++) {
        struct Movie *ptr = &m[i];
        if (ptr->rating > 8.0) {
            printf("Title: %s\n", ptr->title);
            printf("Director: %s\n", ptr->director);
            printf("Rating: %.1f\n\n", ptr->rating);
        }
    }

    // Free allocated memory
    free(m);

    return 0;
}
