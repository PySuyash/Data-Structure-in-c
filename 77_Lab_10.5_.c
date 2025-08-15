// Calculate distance between two Point structures.

#include <stdio.h>
#include <math.h>

// Define Point structure
struct Point {
    float x;
    float y;
};

// Function to calculate distance between two points
float calculateDistance(struct Point a, struct Point b) {
    float dx = b.x - a.x;
    float dy = b.y - a.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    struct Point p1, p2;

    // Input coordinates
    printf("Enter coordinates of Point 1 (x y): ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Enter coordinates of Point 2 (x y): ");
    scanf("%f %f", &p2.x, &p2.y);

    // Calculate and display distance
    float distance = calculateDistance(p1, p2);
    printf("\nDistance between points: %.2f units\n", distance);

    return 0;
}
