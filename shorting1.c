#include <stdio.h>
#include <stdlib.h> // For dynamic memory allocation
void bubble_sort(long [], long);
int main() 
{
    long *array; 
    long n, c; 
    printf("Enter number of elements: ");
    scanf("%ld", &n);
    array = (long *)malloc(n * sizeof(long));
    if (array == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1; 
    }
    printf("Enter %ld integers:\n", n);
    for (c = 0; c < n; c++)
        scanf("%ld", &array[c]);
    printf("Original array:\n");
    for (c = 0; c < n; c++)
        printf("%ld ", array[c]);
    printf("\n\n");

    bubble_sort(array, n);
    
    printf("Sorted list in ascending order:\n");
    for (c = 0; c < n; c++)
        printf("%ld\n", array[c]);
    free(array);   
    return 0;
}
void bubble_sort(long list[], long n) {
    long c, d, t;
    printf("Sorting Process:\n");
    for (c = 0; c < (n - 1); c++) {
        printf("Pass %ld:\n", c + 1);
        for (d = 0; d < n - c - 1; d++) {
            if (list[d] > list[d+1]) 
            {
                 t = list[d];
                list[d] = list[d+1];
                list[d+1] = t;
            }
                printf("  ");
            for (long i = 0; i < n; i++)
                printf("%ld ", list[i]);
            printf("\n");
        }
        printf("\n");
    }
}
