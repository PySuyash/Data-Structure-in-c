// Product with Dynamic Price
/*
struct Product {
int code;
char name[40];
double price;
int stock;
};
Allocate price, input 2 products, display.*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_PRODUCTS 2

struct Product {
    int code;
    char name[40];
    double *price;  // Dynamically allocated
    int stock;
};

int main() {
    struct Product products[NUM_PRODUCTS];

    // Input product details
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        printf("Enter details for product %d:\n", i + 1);

        printf("Code: ");
        scanf("%d", &products[i].code);

        printf("Name: ");
        scanf(" %[^\n]", products[i].name);

        // Allocate memory for price
        products[i].price = (double*)malloc(sizeof(double));
        if (products[i].price == NULL) {
            printf("Memory allocation failed for price.\n");
            return 1;
        }

        printf("Price: ");
        scanf("%lf", products[i].price);

        printf("Stock: ");
        scanf("%d", &products[i].stock);
    }

    // Display product details
    printf("\n--- Product Details ---\n");
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        printf("Product %d:\n", i + 1);
        printf("Code: %d\n", products[i].code);
        printf("Name: %s\n", products[i].name);
        printf("Price: %.2lf\n", *(products[i].price));
        printf("Stock: %d\n", products[i].stock);
    }

    // Free allocated memory
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        free(products[i].price);
    }

    return 0;
}
