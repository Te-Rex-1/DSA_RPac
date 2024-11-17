#include <stdio.h>
#include <stdlib.h>

// Definition of a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert at the head of the list
void insAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert at the back of the list
void insAtBack(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert at a specific position
void insAtPost(struct Node** head, int elem, int pos) {
    struct Node* temp = *head;
    struct Node* insertNode = createNode(elem);
    int count = 1;

    if (pos <= 1) {
        insertNode->next = *head;
        *head = insertNode;
        return;
    }

    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(insertNode);  // Clean up the allocated memory
        return;
    }

    insertNode->next = temp->next;
    temp->next = insertNode;
}

// Function to delete a node at a specific position
void deleteNode(struct Node** head, int position) {
    // Deleting the first node
    if (position == 1) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        // Deleting a middle or last node
        struct Node* curr = *head;
        struct Node* prev = NULL;
        int cnt = 1;

        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        free(curr);
    }
}

// Main function
int main() {
    struct Node* head = createNode(23);
    insAtHead(&head, 232);
    insAtHead(&head, 12);
    print(head);
    insAtPost(&head, 69, 3);
    print(head);

    deleteNode(&head, 3);
    print(head);

    return 0;
}
