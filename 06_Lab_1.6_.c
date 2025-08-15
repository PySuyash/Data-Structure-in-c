// Copy one array to another using only pointers.


#include <stdio.h>

void copyArray(int *source, int *destination, int size) {
    for (int i = 0; i < size; i++) {
        *(destination + i) = *(source + i);
    }
}

int main() {
    int source[] = {5, 10, 15, 20, 25};
    int size = sizeof(source) / sizeof(source[0]);
    int destination[size];

    copyArray(source, destination, size);

    printf("Copied array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(destination + i));
    }

    return 0;
}
