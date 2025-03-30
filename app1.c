#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void createFile();
void showData();
void deleteFile();

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create file\n");
        printf("2. Show data of the file\n");
        printf("3. Delete file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                showData();
                break;
            case 3:
                deleteFile();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void createFile() {
    char filename[MAX_FILENAME_LENGTH];
    FILE *file;

    printf("Enter the filename to create: ");
    scanf("%s", filename);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }

    printf("File created successfully.\n");
    fclose(file);
}

void showData() {
    char filename[MAX_FILENAME_LENGTH];
    FILE *file;
    char ch;

    printf("Enter the filename to show data: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nData in file %s:\n", filename);
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void deleteFile() {
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter the filename to delete: ");
    scanf("%s", filename);

    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error deleting file.\n");
    }
}
