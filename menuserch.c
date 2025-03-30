#include <stdio.h>
#include <stdlib.h>

const int MAX_SIZE = 100;

struct Array {
    int *arr;
    int size;
    int id;
};

struct Dictionary {
    struct Array *arrays;
    int numArrays;
};

struct Dictionary dictionary;

void createArray();
void displayArray(int arrayId);
void searchArray(int element);
void displayMenu();

int main() {
    int choice;

    dictionary.arrays = (struct Array *)malloc(MAX_SIZE * sizeof(struct Array));
    dictionary.numArrays = 0;

    while (1) {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createArray();
            break;
        case 2:
            printf("Enter the array id to display: ");
            int displayId;
            scanf("%d", &displayId);
            displayArray(displayId);
            break;
        case 3:
            printf("Enter the element to search: ");
            int searchElement;
            scanf("%d", &searchElement);
            searchArray(searchElement);
            break;
        case 4:
            printf("Exiting program...\n");
            for (int i = 0; i < dictionary.numArrays; ++i) {
                free(dictionary.arrays[i].arr);
            }
            free(dictionary.arrays);
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void createArray() {
    if (dictionary.numArrays == MAX_SIZE) {
        printf("Cannot create more arrays. Maximum limit reached.\n");
        return;
    }

    printf("Enter the size of the array: ");
    scanf("%d", &dictionary.arrays[dictionary.numArrays].size);

    dictionary.arrays[dictionary.numArrays].arr =
        (int *)malloc(dictionary.arrays[dictionary.numArrays].size * sizeof(int));

    printf("Enter array elements:\n");
    for (int i = 0; i < dictionary.arrays[dictionary.numArrays].size; ++i)
        scanf("%d", &dictionary.arrays[dictionary.numArrays].arr[i]);

    dictionary.arrays[dictionary.numArrays].id = dictionary.numArrays + 1;

    printf("Array %d created successfully!\n", dictionary.arrays[dictionary.numArrays].id);

    ++dictionary.numArrays;
}

void displayArray(int arrayId) {
    int index = -1;
    for (int i = 0; i < dictionary.numArrays; ++i) {
        if (dictionary.arrays[i].id == arrayId) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Array %d elements: ", dictionary.arrays[index].id);
        for (int i = 0; i < dictionary.arrays[index].size; ++i)
            printf("%d ", dictionary.arrays[index].arr[i]);
        printf("\n");
    } else {
        printf("Array with id %d not found.\n", arrayId);
    }
}

void searchArray(int element) {
    for (int i = 0; i < dictionary.numArrays; ++i) {
        for (int j = 0; j < dictionary.arrays[i].size; ++j) {
            if (dictionary.arrays[i].arr[j] == element) {
                printf("Element %d found at index %d in Array %d\n", element, j, dictionary.arrays[i].id);
                return;
            }
        }
    }
    printf("Element %d not found in any array.\n", element);
}

void displayMenu() {
    printf("\n*** Array Operations ***\n");
    printf("1. Create Array\n");
    printf("2. Display Array\n");
    printf("3. Search Array\n");
    printf("4. Exit\n");
}
