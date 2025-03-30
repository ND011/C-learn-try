#include <stdio.h>
#include <stdlib.h>

void insert();
void delete();
void display();

int *queue;
int max, rear = -1, front = -1, data;

int main(void) {
    int ch;
    char endSerialization;

    printf("Enter the maximum size of the queue: ");
    scanf("%d", &max);

    queue = (int *)malloc(max * sizeof(int));

    do {
        printf("\n\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                do {
                    insert();
                    printf("Do you want to enter more values? (Enter '.' to stop): ");
                    scanf(" %c", &endSerialization);
                } while (endSerialization != '.');
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                free(queue);
                break;
            default:
                printf("Invalid entry. Please try again...\n");
        }
    } while (ch != 4);

    return 0;
}

void insert() {
    if (rear == max - 1)
        printf("Queue is full.\n");
    else {
        printf("Enter data: ");
        scanf("%d", &data);

        if (rear == -1 && front == -1) {
            rear = 0;
            front = 0;
        } else
            rear++;

        queue[rear] = data;
        printf("Data inserted: %d\n", data);
    }
}

void delete() {
    if (front == -1)
        printf("Queue is empty.\n");
    else {
        data = queue[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        } else
            front++;

        printf("Data deleted: %d\n", data);
    }
}

void display() {
    if (front == -1)
        printf("Queue is empty.\n");
    else {
        int choice;
        printf("\nDisplay Options:\n");
        printf("1. Display in order\n");
        printf("2. Display in reverse order\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nQueue elements in order: ");
                for (int i = front; i <= rear; i++)
                    printf("%d ", queue[i]);
                printf("\n");
                break;
            case 2:
                printf("\nQueue elements in reverse order: ");
                for (int i = rear; i >= front; i--)
                    printf("%d ", queue[i]);
                printf("\n");
                break;
            default:
                printf("Invalid choice. Please try again...\n");
        }
    }
}