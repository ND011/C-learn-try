#include <stdio.h>
#include <stdlib.h>

void displayArray(int arr[], int size) {
    printf("Your list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int arr[], int size, int target) {
    int first = 0;
    int last = size - 1;
    int middle;

    while (first <= last) {
        middle = (first + last) / 2;

        if (arr[middle] < target) {
            first = middle + 1;
        } else if (arr[middle] == target) {
            return middle;
        } else {
            last = middle - 1;
        }
    }

    return -1;
}

void sortArray(int arr[], int size, int order) {
    int temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((order == 1 && arr[j] > arr[j + 1]) || (order == 2 && arr[j] < arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
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

    printf("Enter %d integer values:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    displayArray(list, size);

    int sortChoice;
    printf("\nHow do you want to arrange the elements?\n");
    printf("1. Ascending order\n2. Descending order\nEnter your choice: ");
    scanf("%d", &sortChoice);

    sortArray(list, size, sortChoice);

    printf("Arranged list: ");
    displayArray(list, size);

    int sElement;
    printf("Enter the element to search: ");
    scanf("%d", &sElement);

    int result = binarySearch(list, size, sElement);

    if (result != -1) {
        printf("Element %d found at index %d.\n", sElement, result);
    } else {
        printf("Element %d not found in the list.\n", sElement);
    }

    free(list);

    return 0;
}
