#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
} *top = NULL;

int data;

void push() {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("\nMemory allocation failed. Stack overflow.\n");
        return;
    }

    printf("\nEnter Data: ");
    scanf("%d", &data);

    ptr->info = data;
    ptr->link = top;
    top = ptr;

    printf("Data inserted: %d\n", data);
}

void pop() {
    struct node *ptr;

    if (top == NULL) {
        printf("\nStack is empty\n");
    } else {
        ptr = top;
        data = top->info;
        top = top->link;
        free(ptr);
        printf("Data deleted: %d\n", data);
    }
}

void display() {
    struct node *ptr;

    if (top == NULL) {
        printf("\nStack is empty\n");
    } else {
        ptr = top;
        while (ptr != NULL) {
            printf("%d ", ptr->info);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

int main(void) {
    int ch;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid entry. Please try again...\n");
        }
    } while(ch != 4);

    return 0;
}

