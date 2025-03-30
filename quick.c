#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int choosePivot(int arr[], int low, int high) {
    // Choose the median of three values as pivot
    int mid = low + (high - low) / 2;
    int a = arr[low];
    int b = arr[mid];
    int c = arr[high];
    if ((a - b) * (c - a) >= 0)
        return low;
    else if ((b - a) * (c - b) >= 0)
        return mid;
    else
        return high;
}

int partition(int arr[], int low, int high) {
    int pivotIndex = choosePivot(arr, low, high);
    int pivot = arr[pivotIndex];
    printf("Pivot values: %d and %d\n", arr[low], arr[high]);
    printf("Chosen Pivot: %d\n", pivot);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        printf("After partitioning, pivot index: %d\n", pi);
        printf("Left sub-array: ");
        for (int i = low; i < pi; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Right sub-array: ");
        for (int i = pi + 1; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting:\n");
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
