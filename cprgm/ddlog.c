#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));  // Fixed the type cast
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at the beginning.\n", value);
}

void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at the end.\n", value);
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("%d deleted from the beginning.\n", temp->data);
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    printf("%d deleted from the end.\n", temp->data);
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;  
    free(temp);
}

void displayFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Double linked list from beginning: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL.\n");
}

void displayFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    printf("Double linked list from end: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL.\n");
}


void count() {
    int c = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    printf("Total number of elements: %d\n", c);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n---Menu---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display from Beginning\n");
        printf("6. Display from End\n");
        printf("7. Count Elements\n");
        printf("8. Exit\n");
        scanf("%d", &choice); 
        switch (choice) {  
            case 1:
                printf("Enter Value: ");
                scanf("%d", &value);  
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter Value: ");
                scanf("%d", &value);  
                insertAtEnd(value);
                break;
            case 3:
                deleteAtBeginning();  
                break;
            case 4:
                deleteAtEnd(); 
                break;
            case 5:
                displayFromBeginning();  
                break;
            case 6:
                displayFromEnd();  
                break;
            case 7:
                count();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
