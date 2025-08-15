// Return Dynamic Date. Write: struct Date* getCurrentDate(). return pointer to dynamically allocated struct . Date with sample values.

#include <stdio.h>
#include <stdlib.h>

struct Date {
    int day;
    int month;
    int year;
};

// Returns pointer to dynamically allocated Date with sample values
struct Date* getCurrentDate() {
    struct Date *d = (struct Date*)malloc(sizeof(struct Date));
    if (d == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Sample values
    d->day = 15;
    d->month = 8;
    d->year = 2025;

    return d;
}

int main() {
    struct Date *today = getCurrentDate();

    if (today != NULL) {
        printf("Current Date: %02d-%02d-%d\n", today->day, today->month, today->year);
        free(today);  // Free allocated memory
    }

    return 0;
}
