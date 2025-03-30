#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> // For directory listing
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void listFiles();
void runProgramWithData(char *filename);
void createFile();
void showData();
void deleteFile();
void editAndSave();

int main()
{
    int choice;
    char filename[MAX_FILENAME_LENGTH];

    do {
        printf("\nMenu:\n");
        printf("1. See the datafile names\n");
        printf("2. Use file data and run program on it\n");
        printf("3. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listFiles();
                int main() {
                    int choice;

                    while (1)   {
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
                                {
                                char fileName[100];
                                char content[1000];

                                printf("Enter file name: ");
                                scanf("%s", fileName);

                                printf("Enter content: ");
                                scanf(" %[^\n]s", content);

                                FILE *file = fopen(fileName, "w");
                                if (file == NULL) {
                                    printf("Error opening file!\n");
                                    return 0;
                                }

                                fprintf(file, "%s", content);
                                fclose(file);
                                printf("File saved successfully!\n");
                                }

                            int main() 
                            {
                                int choice;
                                while (1) 
                                {
                                    printf("\nMenu:\n");
                                    printf("1. Edit and write to file\n");
                                    printf("2. Exit\n");
                                    printf("Enter your choice: ");
                                    scanf("%d", &choice);

                                    switch (choice) 
                                    {
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

                void createFile()
                {
                    char filename[MAX_FILENAME_LENGTH];
                    FILE *file;

                    printf("Enter the filename to create: ");
                    scanf("%s", filename);

                    file = fopen(filename, "w");
                    if (file == NULL) 
                    {
                        printf("Error creating file.\n");
                        return;
                    }

                    printf("File created successfully.\n");
                    fclose(file);
                }

                void showData()
                {
                    char filename[MAX_FILENAME_LENGTH];
                    FILE *file;
                    char ch;

                    printf("Enter the filename to show data: ");
                    scanf("%s", filename);

                    file = fopen(filename, "r");
                    if (file == NULL) 
                    {
                        printf("Error opening file.\n");
                        return;
                    }

                    printf("\nData in file %s:\n", filename);
                    while ((ch = fgetc(file)) != EOF)
                    {
                        putchar(ch);
                    }

                    fclose(file);
                }

                void deleteFile() 
                {
                    char filename[MAX_FILENAME_LENGTH];

                    printf("Enter the filename to delete: ");
                    scanf("%s", filename);

                    if (remove(filename) == 0) 
                    {
                        printf("File deleted successfully.\n");
                    } 
                    else 
                    {
                        printf("Error deleting file.\n");
                    }
                }

                break;
            case 2:
                printf("Enter the filename to run the program on: ");
                scanf("%s", filename);
                runProgramWithData(filename);
            
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void listFiles() {
    DIR *directory;
    struct dirent *entry;

    printf("\nDatafile names in the current directory:\n");
    directory = opendir(".");
    if (directory != NULL) {
        while ((entry = readdir(directory)) != NULL) {
            if (entry->d_type == DT_REG) { // Regular file
                printf("%s\n", entry->d_name);  
            }
        }
        closedir(directory);
    } 
    else
    {
        perror("Error opening directory");
    }
}

void runProgramWithData(char *filename) {
    char command[512];
    sprintf(command, "./a.out < %s", filename);
    system(command);
}
