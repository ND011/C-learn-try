#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void insert();
void delete();
void display();

int queue[MAX];
int rear = -1, front = -1, data;

int main(void) {
    int ch;

    do {
        printf("\n\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid entry. Please try again...\n");
        }
    } while (ch != 4);

    return 0;
}

void insert() {
    if (rear == MAX - 1)
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
        printf("\nQueue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
