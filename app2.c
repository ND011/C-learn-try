#include <stdio.h>
#include <stdlib.h>

void editAndSave() {
    char fileName[100];
    char content[1000];

    printf("Enter file name: ");
    scanf("%s", fileName);

    printf("Enter content: ");
    scanf(" %[^\n]s", content);

    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%s", content);
    fclose(file);
    printf("File saved successfully!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Edit and write to file\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                editAndSave();
                break;
            case 2:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter 1 or 2.\n");
        }
    }
    return 0;
}
