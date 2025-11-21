#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert() {
    int item;

    if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front)) {
        printf("Queue is Full (Overflow)\n");
        return;
    }

    printf("Enter the element: ");
    scanf("%d", &item);

    if (front == -1) { 
        front = rear = 0;
    } else if (rear == SIZE - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }

    queue[rear] = item;
    printf("%d inserted .\n", item);
}

void delete() {
    if (front == -1) {
        printf("Queue is Empty (Underflow)\n");
        return;
    }

    int item = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }

    printf("Deleted element: %d\n", item);
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < SIZE; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

void countElements() {
    int count = 0;

    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    if (rear >= front) {
        count = rear - front + 1;
    } else {
        count = (SIZE - front) + (rear + 1);
    }

    printf("Total elements: %d\n", count);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Count Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
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
            countElements();
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice!!!!.\n");
        }
    }

    return 0;
}
