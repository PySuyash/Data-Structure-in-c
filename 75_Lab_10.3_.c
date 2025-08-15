// Process Input Data. Write: struct Result processData(const struct Input *input). computes and returns result without modifying input.

#include <stdio.h>

// Define Input structure
struct Input {
    int scores[5];
};

// Define Result structure
struct Result {
    int total;
    float average;
};

// Function to process input and return result
struct Result processData(const struct Input *input) {
    struct Result res;
    res.total = 0;

    for (int i = 0; i < 5; i++) {
        res.total += input->scores[i];
    }

    res.average = res.total / 5.0f;
    return res;
}

int main() {
    struct Input data;

    // Input scores
    printf("Enter 5 scores:\n");
    for (int i = 0; i < 5; i++) {
        printf("Score %d: ", i + 1);
        scanf("%d", &data.scores[i]);
    }

    // Process data
    struct Result result = processData(&data);

    // Display result
    printf("\n--- Result ---\n");
    printf("Total: %d\n", result.total);
    printf("Average: %.2f\n", result.average);

    return 0;
}
