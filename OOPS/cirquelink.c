    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>

    // Structure of a Node
    struct Node {
        int data;
        struct Node* link;
    };

    // Structure of a Queue
    struct Queue {
        struct Node *front, *rear;
        
    };

    // Function to create Circular queue
    void enQueue(struct Queue* q, int value) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = value;
        temp->link = NULL;

        if (q->front == NULL) {
            // First element to be enqueued
            q->front = temp;
        } else {
            // Link the new node to the last node
            q->rear->link = temp;
        }

        // Make the new node the rear of the queue
        q->rear = temp;
        // Link rear to front to make it circular
        q->rear->link = q->front;
    }

    // Function to delete element from Circular Queue
    int deQueue(struct Queue* q) {
        if (q->front == NULL) {
            printf("Queue is empty\n");
            return INT_MIN;
        }

        int value;
        if (q->front == q->rear) {
            // Only one node in the queue
            value = q->front->data;
            free(q->front);
            q->front = q->rear = NULL;
        } else {
            // More than one node in the queue
            struct Node* temp = q->front;
            value = temp->data;
            q->front = q->front->link;
            q->rear->link = q->front;
            free(temp);
        }

        return value;
    }

    // Function displaying the elements of Circular Queue
    void displayQueue(struct Queue* q) {
        if (q->front == NULL) {
            printf("Queue is empty\n");
            return;
        }

        struct Node* temp = q->front;
        printf("\nElements in Circular Queue are: ");
        while (temp->link != q->front) { 
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("%d\n", temp->data);
    }

    // Driver of the program
    int main() {
        // Create a queue and initialize front and rear
        struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
        q->front = q->rear = NULL;

        // Inserting elements in Circular Queue
        enQueue(q, 14);
        enQueue(q, 22);
        enQueue(q, 6);

        // Display elements present in Circular Queue
        displayQueue(q);

        // Deleting elements from Circular Queue
        printf("\nDeleted value = %d", deQueue(q));
        printf("\nDeleted value = %d", deQueue(q));

        // Remaining elements in Circular Queue
        displayQueue(q);

        enQueue(q, 9);
        enQueue(q, 20);
        displayQueue(q);

        // Freeing the queue
        free(q);

        return 0;
    }
