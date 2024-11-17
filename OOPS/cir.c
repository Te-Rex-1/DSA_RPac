#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int elemCount;
} Circular;

// Function to initialize the circular queue
Circular* createQueue(int n) {
    Circular *queue = (Circular *)malloc(sizeof(Circular));
    queue->size = n;
    queue->arr = (int *)malloc(queue->size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->elemCount = 0;
    return queue;
}

// Function to enqueue an element
int enQueue(Circular *queue, int data) {
    // if it is the first element to be inserted
    if (queue->front == -1) {
        queue->front = queue->rear = 0;
        queue->arr[queue->front] = data;
        queue->elemCount++;
        return 1;
    }
    // if the circular queue is full
    if (queue->rear == (queue->front - 1 + queue->size) % queue->size) {
        return 0;
    }
    // if rear is at the end and front is not at index 0
    if (queue->rear == queue->size - 1 && queue->front != 0) {
        queue->rear = 0;
        queue->arr[queue->rear] = data;
        queue->elemCount++;
        return 1;
    }
    // normal enqueue
    else {
        queue->rear++;
        queue->arr[queue->rear] = data;
        queue->elemCount++;
        return 1;
    }
    return 0;
}

// Function to dequeue an element
int deQueue(Circular *queue) {
    // if the queue is empty
    if (queue->front == -1)
        return -1;

    int top = queue->arr[queue->front];

    // if at end of queue
    if (queue->front == queue->size - 1) {
        queue->front = 0;
    }
    // single element condition
    else if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    }
    else {
        queue->front++;
    }

    queue->elemCount--;
    return top;
}

// Function to get the front element
int top(Circular *queue) {
    if (queue->front == -1)
        return -1;
    return queue->arr[queue->front];
}

// Function to display elements of the circular queue
void display(Circular *queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = queue->front;
    while (1) {
        printf("%d ", queue->arr[i]);
        if (i == queue->rear)
            break;
        i = (i + 1) % queue->size;
    }
    printf("\n");
}

// Main function
int main() {
    int size = 5;
    Circular *queue = createQueue(size);

    enQueue(queue, 10);
    enQueue(queue, 20);
    enQueue(queue, 30);
    enQueue(queue, 40);
    enQueue(queue, 50);

    printf("Queue after enQueue operations: ");
    display(queue);

    printf("Dequeue element: %d\n", deQueue(queue));
    printf("Dequeue element: %d\n", deQueue(queue));

    printf("Queue after deQueue operations: ");
    display(queue);

    enQueue(queue, 60);
    enQueue(queue, 70);

    printf("Queue after more enQueue operations: ");
    display(queue);

    printf("Front element: %d\n", top(queue));

    // Free the allocated memory
    free(queue->arr);
    free(queue);

    return 0;
}
