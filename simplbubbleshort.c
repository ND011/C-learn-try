#include <stdio.h>
#include <stdlib.h> // Required for dynamic memory allocation

int main() {
    int *a, i, j, temp, n;

    printf("\nEnter the number of elements to sort: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    a = (int *)malloc(n * sizeof(int));

    if (a == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Bubble sort
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(a);

    return 0;
}
