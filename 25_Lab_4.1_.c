// Square by value vs reference. Write: int squareByValue(int x) - returns x*x , void squareByReference(int *x) - modifies *x = (*x)*(*x). Compare the results after calling both on the same variable.


#include <stdio.h>
#include <stdlib.h>

int main() {
    int count = 3;
    double **data;

    // Allocate memory for 3 pointers to double
    data = (double **)malloc(count * sizeof(double *));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Allocate each double and input value
    for (int i = 0; i < count; i++) {
        *(data + i) = (double *)malloc(sizeof(double));
        if (*(data + i) == NULL) {
            printf("Memory allocation failed for value %d.\n", i + 1);
            return 1;
        }

        printf("Enter double value %d: ", i + 1);
        scanf("%lf", *(data + i));
    }

    // Display all values
    printf("\nStored double values:\n");
    for (int i = 0; i < count; i++) {
        printf("%.2lf\n", *(*(data + i)));
    }

    // Free all allocated memory
    for (int i = 0; i < count; i++) {
        free(*(data + i));
    }
    free(data);

    return 0;
}
