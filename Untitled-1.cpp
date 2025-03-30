#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

void insert_end();
void delete_first();
void display();

struct node *start = NULL;

int main(void) {
    int ch;

    do {
        printf("\n\n\n1. Insert at End\n2. Delete from Beginning\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert_end();
                break;
            case 2:
                delete_first();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("\n\nInvalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}

void insert_end() {
    int data;
    struct node *current, *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }

    printf("\n\nEnter item: ");
    scanf("%d", &data);

    new_node->info = data;
    new_node->link = NULL;

    if (start == NULL) {
        // If the list is empty, make the new node the first node
        start = new_node;
    } else {
        // Traverse to the end of the list
        current = start;
        while (current->link != NULL) {
            current = current->link;
        }

        // Append the new node at the end
        current->link = new_node;
    }

    printf("Item %d inserted at the end.\n", data);
}

void delete_first() {
    int data;
    struct node *current;

    if (start == NULL) {
        printf("\n\nLinked list is empty.\n");
    } else {
        current = start;
        data = start->info;
        start = start->link;
        free(current);
        printf("\n\nItem deleted: %d", data);
    }
}

void display() {
    struct node *current;

    if (start == NULL) {
        printf("\n\nLinked list is empty.\n");
    } else {
        printf("\n\nLinked List Elements: ");
        current = start;
        while (current != NULL) {
            printf("%d ", current->info);
            current = current->link;
        }
        printf("\n");
    }
}

