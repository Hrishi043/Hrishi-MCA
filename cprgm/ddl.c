#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    if (head) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    printf("%d inserted at the beginning.\n", value);
}

void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (!head) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at the end.\n", value);
}

void deleteAtBeginning() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    printf("%d deleted from the beginning.\n", temp->data);
    free(temp);
}

void deleteAtEnd() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next) temp = temp->next;
    if (temp->prev) temp->prev->next = NULL;
    else head = NULL;
    printf("%d deleted from the end.\n", temp->data);
    free(temp);
}

void displayList(int reverse) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = reverse ? head;
    while (temp->next) temp = temp->next;
    printf("Double linked list from %s: ", reverse ? "end" : "beginning");
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = reverse ? temp->prev : temp->next;
    }
    printf("NULL.\n");
}

void count() {
    int c = 0;
    struct Node *temp = head;
    while (temp) {
        c++;
        temp = temp->next;
    }
    printf("Total number of elements: %d\n", c);
}

int main() {
    int choice, value;
    while (1) {
        printf("\n---Menu---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete from Beginning\n4. Delete from End\n5. Display from Beginning\n6. Display from End\n7. Count Elements\n8. Exit\n");
        scanf("%d", &choice); 
        switch (choice) {  
            case 1: case 2: 
                printf("Enter Value: ");
                scanf("%d", &value);  
                choice == 1 ? insertAtBeginning(value) : insertAtEnd(value);
                break;
            case 3: deleteAtBeginning(); break;
            case 4: deleteAtEnd(); break;
            case 5: displayList(0); break;
            case 6: displayList(1); break;
            case 7: count(); break;
            case 8: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
    return 0;
}
