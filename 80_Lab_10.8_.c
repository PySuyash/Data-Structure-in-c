// Add two time structures and returns total.

#include <stdio.h>

// Define Time structure
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function to add two Time structures
struct Time addTime(struct Time t1, struct Time t2) {
    struct Time total;

    total.seconds = t1.seconds + t2.seconds;
    total.minutes = t1.minutes + t2.minutes + total.seconds / 60;
    total.seconds %= 60;

    total.hours = t1.hours + t2.hours + total.minutes / 60;
    total.minutes %= 60;

    return total;
}

int main() {
    struct Time time1, time2, result;

    // Input first time
    printf("Enter Time 1 (hh mm ss): ");
    scanf("%d %d %d", &time1.hours, &time1.minutes, &time1.seconds);

    // Input second time
    printf("Enter Time 2 (hh mm ss): ");
    scanf("%d %d %d", &time2.hours, &time2.minutes, &time2.seconds);

    // Add times
    result = addTime(time1, time2);

    // Display result
    printf("\n--- Total Time ---\n");
    printf("%02d:%02d:%02d\n", result.hours, result.minutes, result.seconds);

    return 0;
}
