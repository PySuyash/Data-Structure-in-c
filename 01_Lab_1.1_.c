// Write a program to input 10 integers into an array and use to reverse the array in place (Withour the second array). Display the reversed array using pointers.

#include <stdio.h>
#include <stdlib.h>

int main() {
    const int SIZE = 10;

    int* arr = (int *)malloc(SIZE*sizeof(int));
    int* ptr = arr;

    printf("\nEnter the elements of array\n");
    for (int i=0; i<SIZE; i++) {
        scanf("%d", ptr+i);
    }

    printf("\n== Actual Array ==\n"); 
    for (int i=0; i<SIZE; i++) {
        printf("%d\t", *(ptr+i));
    }

    int* start = arr;
    int* end = arr + SIZE - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        ++start;
        --end;
    }

    printf("\n== Reversed Array ==\n");
    for (int i=0; i<SIZE; i++) {
        printf("%d\t", *(ptr+i));
    }

    return 0;
}