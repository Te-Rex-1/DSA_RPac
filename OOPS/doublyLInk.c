#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to print the doubly linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to get the length of the list
int length(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Insert at head
void insAtHead(Node** head, Node** tail, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Insert at tail
void insAtTail(Node** head, Node** tail, int data) {
    Node* newNode = createNode(data);
    if (*tail == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

// Insert at a specific position
void insAtPos(Node** head, Node** tail, int data, int position) {
    if (position <= 1) {
        insAtHead(head, tail, data);
        return;
    }
    
    Node* temp = *head;
    Node* newNode = createNode(data);
    int count = 1;

    while (count < position - 1 && temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL) {
        insAtTail(head, tail, data);
    } else {
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Delete a node at a specific position
void deleteNode(Node** head, int pos) {
    if (*head == NULL) return;
    
    Node* temp = *head;
    
    if (pos == 1) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    
    int count = 1;
    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) return;

    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    
    free(temp);
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    printf("Inserting at head:\n");
    insAtHead(&head, &tail, 10);
    insAtHead(&head, &tail, 12);
    insAtHead(&head, &tail, 13);
    print(head);
    printf("Length: %d\n", length(head));

    printf("\nInserting at tail:\n");
    insAtTail(&head, &tail, 45);
    insAtTail(&head, &tail, 46);
    insAtTail(&head, &tail, 47);
    print(head);
    printf("Length: %d\n", length(head));

    printf("\nInserting at position 5:\n");
    insAtPos(&head, &tail, 982, 5);
    print(head);
    printf("Length: %d\n", length(head));

    printf("\nDeleting at position 4:\n");
    deleteNode(&head, 4);
    print(head);
    printf("Length: %d\n", length(head));

    printf("\nDeleting at position 6:\n");
    deleteNode(&head, 6);
    print(head);
    printf("Length: %d\n", length(head));

    return 0;
}
