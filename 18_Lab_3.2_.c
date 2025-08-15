// Jagged list sum. Simulate a jagged list using int **list. Allocate 3 sublists of length 2, 4 and 3. Input values and compute the total sum using double pointer traversal.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int **list;
    int sublist_lengths[] = {2, 4, 3};
    int total_sublists = 3;
    int total_sum = 0;

    // Allocate memory for 3 sublists
    list = (int **)malloc(total_sublists * sizeof(int *));
    if (list == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Allocate each sublist and input values
    for (int i = 0; i < total_sublists; i++) {
        *(list + i) = (int *)malloc(sublist_lengths[i] * sizeof(int));
        if (*(list + i) == NULL) {
            printf("Memory allocation failed for sublist %d.\n", i + 1);
            return 1;
        }

        printf("Enter %d values for sublist %d:\n", sublist_lengths[i], i + 1);
        for (int j = 0; j < sublist_lengths[i]; j++) {
            scanf("%d", (*(list + i) + j));
        }
    }

    // Compute total sum
    for (int i = 0; i < total_sublists; i++) {
        for (int j = 0; j < sublist_lengths[i]; j++) {
            total_sum += *(*(list + i) + j);
        }
    }

    // Display result
    printf("\nTotal sum of all elements: %d\n", total_sum);

    // Free memory
    for (int i = 0; i < total_sublists; i++) {
        free(*(list + i));
    }
    free(list);

    return 0;
}
