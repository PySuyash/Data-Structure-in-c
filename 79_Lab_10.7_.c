// Compare prices of two products and return cheaper one.

#include <stdio.h>
#include <string.h>

// Define Product structure
struct Product {
    char name[50];
    float price;
};

// Function to compare and return the cheaper product
struct Product getCheaper(struct Product p1, struct Product p2) {
    if (p1.price < p2.price) {
        return p1;
    } else {
        return p2;
    }
}

int main() {
    struct Product prod1, prod2;

    // Input first product
    printf("Enter name of Product 1: ");
    scanf(" %[^\n]", prod1.name);
    printf("Enter price of Product 1: ");
    scanf("%f", &prod1.price);

    // Input second product
    printf("\nEnter name of Product 2: ");
    scanf(" %[^\n]", prod2.name);
    printf("Enter price of Product 2: ");
    scanf("%f", &prod2.price);

    // Compare and get cheaper product
    struct Product cheaper = getCheaper(prod1, prod2);

    // Display result
    printf("\n--- Cheaper Product ---\n");
    printf("Name: %s\n", cheaper.name);
    printf("Price: ₹%.2f\n", cheaper.price);

    return 0;
}
