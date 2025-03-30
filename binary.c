#include <stdio.h>
#include <stdlib.h>
// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int first = 0;
    int last = size - 1;
    int middle;
    while (first <= last) {
        middle = (first + last) / 2;

        if (arr[middle] < target) {
            first = middle + 1;
        } else if (arr[middle] == target) {
            return middle;  // Element found, return the index
        } else {
            last = middle - 1;
        }
    }
    return -1;  // Element not found
}
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *list = (int *)malloc(size * sizeof(int));
    if (list == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }
    printf("Enter %d integer values in ascending order:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }
    int sElement;
    printf("Enter the element to search: ");
    scanf("%d", &sElement);
    int result = binarySearch(list, size, sElement);
    if (result != -1) {
        printf("Element %d found at index %d.\n", sElement, result);
    } else {
        printf("Element %d not found in the list.\n", sElement);
    }
    // Free dynamically allocated memory
    free(list);
    return 0;
}
