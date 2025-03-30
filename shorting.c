#include <stdio.h>
#include <stdlib.h> 
void bubble_sort(long [], long);
int main() {
    long *array; // Declare array pointer
    long n, c; // Declare n for the size of the array
    printf("Enter number of elements: ");
    scanf("%ld", &n);
    // Dynamically allocate memory for the array
    array = (long *)malloc(n * sizeof(long));
    if (array == NULL) { // Check if memory allocation was successful
        printf("Memory allocation failed.\n");
        return 1; // Return an error code
    }
    printf("Enter %ld integers:\n", n);
    for (c = 0; c < n; c++)
        scanf("%ld", &array[c]);
    bubble_sort(array, n);
    printf("Sorted list in ascending order:\n");
    for (c = 0; c < n; c++)
        printf("%ld\n", array[c]);   
    free(array); 
    return 0;
}
void bubble_sort(long list[], long n) {
    long c, d, t;
    for (c = 0; c < (n - 1); c++) {
        for (d = 0; d < n - c - 1; d++) {
            if (list[d] > list[d+1]) {
                // Swapping
                t = list[d];
                list[d] = list[d+1];
                list[d+1] = t;
            }
        }
    }
}
