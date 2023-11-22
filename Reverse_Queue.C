#include <stdio.h>

#define MAX_SIZE 100

// Structure for the queue
struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

// Function to initialize a new queue
void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue a new element to the queue
void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", data);
        return;
    }

    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->arr[queue->rear] = data;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }

    int data = queue->arr[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return data;
}

// Function to reverse a queue
void reverseQueue(struct Queue* queue) {
    int stack[MAX_SIZE];
    int top = -1;

    // Push all elements of the queue onto the stack
    while (!isEmpty(queue)) {
        stack[++top] = dequeue(queue);
    }

    // Pop elements from the stack and enqueue them back to the queue
    while (top >= 0) {
        enqueue(queue, stack[top--]);
    }
}

// Function to print the elements of a queue
void printQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = queue->front;
    do {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);

    printf("\n");
}

// Main function
int main() {
    struct Queue queue;
    initQueue(&queue);

    // Enqueue elements to the queue
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);

    printf("Original Queue: ");
    printQueue(&queue);

    // Reverse the queue
    reverseQueue(&queue);

    printf("Reversed Queue: ");
    printQueue(&queue);

    return 0;
}
