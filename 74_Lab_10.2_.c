// Point: Midpoint and shift struct Point midpoint(struct Point a, struct Point b) - returns midpoint. void shiftPoint(struct Point *p, int dx, int dy)- modifies via pointer.

#include <stdio.h>

// Define the Point structure
struct Point {
    int x;
    int y;
};

// Function to calculate midpoint (pass by value)
struct Point midpoint(struct Point a, struct Point b) {
    struct Point mid;
    mid.x = (a.x + b.x) / 2;
    mid.y = (a.y + b.y) / 2;
    return mid;
}

// Function to shift a point (pass by address)
void shiftPoint(struct Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

int main() {
    struct Point p1, p2;

    // Input two points
    printf("Enter coordinates of Point 1 (x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Enter coordinates of Point 2 (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    // Calculate and display midpoint
    struct Point mid = midpoint(p1, p2);
    printf("\nMidpoint: (%d, %d)\n", mid.x, mid.y);

    // Shift Point 1
    int dx, dy;
    printf("\nEnter shift values dx and dy: ");
    scanf("%d %d", &dx, &dy);

    shiftPoint(&p1, dx, dy);
    printf("Shifted Point 1: (%d, %d)\n", p1.x, p1.y);

    return 0;
}
