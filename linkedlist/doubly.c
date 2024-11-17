#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// For creating a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// For printing and traversing the linked list
void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); // Indicating the end of the list
}

// For calculating the length of the linked list
int length(struct Node* head) {
    int length = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// For inserting at the head
void insAtHead(struct Node** head, struct Node** tail, int data) {
    struct Node* temp = createNode(data);

    // Empty list
    if (*head == NULL) {
        *head = *tail = temp;
    } else {
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    }
}

// For inserting at the tail
void insAtTail(struct Node** head, struct Node** tail, int data) {
    struct Node* temp = createNode(data);

    if (*tail == NULL) {
        *head = *tail = temp; // When the list is empty
    } else {
        (*tail)->next = temp;
        temp->prev = *tail;
        *tail = temp;
    }
}

// For inserting at a specific position
void insAtPos(struct Node** head, struct Node** tail, int data, int position) {
    if (position <= 1) {
        insAtHead(head, tail, data);
        return;
    }

    struct Node* temp = *head;
    struct Node* nodeToInsert = createNode(data);
    int count = 1;

    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL) {
        insAtTail(head, tail, data);
        return;
    }

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

// For deleting a node at a specific position
void del(struct Node** head, int pos) {
    if (pos <= 1) {
        struct Node* temp = *head;
        if (temp == NULL) return;
        
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    struct Node* curr = *head;
    struct Node* prevs = NULL;
    int count = 1;

    while (curr != NULL && count < pos) {
        prevs = curr;
        curr = curr->next;
        count++;
    }

    if (curr == NULL) return; // Position is greater than the length of the list

    if (curr->next != NULL) {
        curr->next->prev = prevs;
    }
    prevs->next = curr->next;
    free(curr);
}

// Main function
int main() {
    struct Node* head = createNode(10);
    struct Node* tail = head;

    printf("Printing linked list:\n");
    print(head);

    // Inserting at head
    insAtHead(&head, &tail, 12);
    insAtHead(&head, &tail, 13);
    printf("Printing linked list after insert at head:\n");
    print(head);
    printf("Length of linked list: %d\n", length(head));

    // Inserting at tail
    printf("Inserting at tail:\n");
    insAtTail(&head, &tail, 45);
    insAtTail(&head, &tail, 46);
    insAtTail(&head, &tail, 47);
    insAtTail(&head, &tail, 48);
    printf("Printing linked list after insert at tail:\n");
    print(head);
    printf("Length of linked list: %d\n", length(head));

    // Inserting at position
    printf("Inserting at position 5:\n");
    insAtPos(&head, &tail, 982, 6);
    printf("Printing linked list after inserting at position 5:\n");
    print(head);
    printf("Length of linked list: %d\n", length(head));

    // Deleting nodes
    printf("Performing deletion at position 4:\n");
    del(&head, 4);
    printf("Printing linked list after deletion:\n");
    print(head);
    printf("Length of linked list: %d\n", length(head));

    printf("Performing deletion at position 6:\n");
    del(&head, 6);
    printf("Printing linked list after deletion:\n");
    print(head);
    printf("Length of linked list: %d\n", length(head));

    return 0;
}
