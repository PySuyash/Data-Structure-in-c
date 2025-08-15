// Update date structure to next day (pass by address).

#include <stdio.h>

// Define Date structure
struct Date {
    int day;
    int month;
    int year;
};

// Function to check for leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get number of days in a month
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 2: return isLeapYear(year) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}

// Function to update date to next day (pass by address)
void updateToNextDay(struct Date *d) {
    d->day++;

    int daysInMonth = getDaysInMonth(d->month, d->year);
    if (d->day > daysInMonth) {
        d->day = 1;
        d->month++;
        if (d->month > 12) {
            d->month = 1;
            d->year++;
        }
    }
}

int main() {
    struct Date today;

    // Input date
    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &today.day, &today.month, &today.year);

    // Update to next day
    updateToNextDay(&today);

    // Display updated date
    printf("\n--- Next Day ---\n");
    printf("%02d-%02d-%04d\n", today.day, today.month, today.year);

    return 0;
}
