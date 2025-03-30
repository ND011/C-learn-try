#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n, int ascending) {
    int i, j, index, temp;
    
    for (i = 0; i < n - 1; i++) {
        index = i;
        for (j = i + 1; j < n; j++) {
            if ((ascending && arr[j] < arr[index]) || (!ascending && arr[j] > arr[index])) {
                index = j;
            }
        }
        if (index != i) {
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
}

int main() {
    int n, ascending;
    
    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input elements
    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    // Input sorting order
    printf("Sort in ascending (1) or descending (0) order? ");
    scanf("%d", &ascending);

    // Perform selection sort
    selectionSort(arr, n, ascending);

    // Print sorted elements
    printf("Sorted elements:\n");
    for(int i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    return 0;
}
