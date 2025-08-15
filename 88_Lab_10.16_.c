// Return rectangle with largest area among three.

#include <stdio.h>

// Define Rectangle structure
struct Rectangle {
    int length;
    int width;
};

// Function to calculate area
int area(struct Rectangle r) {
    return r.length * r.width;
}

// Function to return rectangle with largest area
struct Rectangle getLargestRectangle(struct Rectangle r1, struct Rectangle r2, struct Rectangle r3) {
    struct Rectangle largest = r1;

    if (area(r2) > area(largest)) {
        largest = r2;
    }
    if (area(r3) > area(largest)) {
        largest = r3;
    }

    return largest;
}

int main() {
    struct Rectangle rect1, rect2, rect3;

    // Input rectangles
    printf("Enter length and width of Rectangle 1: ");
    scanf("%d %d", &rect1.length, &rect1.width);

    printf("Enter length and width of Rectangle 2: ");
    scanf("%d %d", &rect2.length, &rect2.width);

    printf("Enter length and width of Rectangle 3: ");
    scanf("%d %d", &rect3.length, &rect3.width);

    // Get largest rectangle
    struct Rectangle largest = getLargestRectangle(rect1, rect2, rect3);

    // Display result
    printf("\n--- Largest Rectangle ---\n");
    printf("Length: %d\n", largest.length);
    printf("Width: %d\n", largest.width);
    printf("Area: %d\n", area(largest));

    return 0;
}
