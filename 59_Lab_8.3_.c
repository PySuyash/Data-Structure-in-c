//  Sensor with Dynamic Readings.
/*
struct Sensor {
int id;
float *readings;
int count;
char location[25];
};
Allocate readings for 5 values. Compute average.*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_READINGS 5

struct Sensor {
    int id;
    float *readings;     // Dynamically allocated array
    int count;           // Number of readings
    char location[25];
};

int main() {
    struct Sensor sensor;

    // Input sensor details
    printf("Enter Sensor ID: ");
    scanf("%d", &sensor.id);

    printf("Enter Sensor Location: ");
    scanf(" %[^\n]", sensor.location);

    sensor.count = NUM_READINGS;

    // Allocate memory for readings
    sensor.readings = (float*)malloc(sensor.count * sizeof(float));
    if (sensor.readings == NULL) {
        printf("Memory allocation failed for readings.\n");
        return 1;
    }

    // Input readings
    printf("Enter %d readings:\n", sensor.count);
    for (int i = 0; i < sensor.count; i++) {
        printf("Reading %d: ", i + 1);
        scanf("%f", &sensor.readings[i]);
    }

    // Compute average
    float sum = 0.0;
    for (int i = 0; i < sensor.count; i++) {
        sum += sensor.readings[i];
    }
    float average = sum / sensor.count;

    // Display sensor info and average
    printf("\n--- Sensor Report ---\n");
    printf("ID: %d\n", sensor.id);
    printf("Location: %s\n", sensor.location);
    printf("Average Reading: %.2f\n", average);

    // Free allocated memory
    free(sensor.readings);

    return 0;
}
