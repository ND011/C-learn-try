#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a; // Pointer for dynamic array
    int i, x, n;

    // Step 1: Read the number of elements
    printf("How many elements?");
    scanf("%d", &n);

    // Step 2: Dynamically allocate memory for the array
    a = (int *)malloc(n * sizeof(int));

    // Step 3: Read array elements
    printf("Enter array elements:\n");
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    // Step 4: Enter element to search
    printf("\nEnter element to search:");
    scanf("%d", &x);

    // Step 5: Linear search
    for (i = 0; i < n; ++i) {
        if (a[i] == x)
            break;
    }

    // Step 6: If the last element in the list is also not matched, then display "Element not found!!!"
    if (i < n)
        printf("Element found at index %d", i);
    else
        printf("Element not found");

    // Step 7: Free dynamically allocated memory
    free(a);

    return 0;
}
