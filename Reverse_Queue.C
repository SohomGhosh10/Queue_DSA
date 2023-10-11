#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Function to create a new queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue)
        return NULL;

    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (!queue->array)
        return NULL;

    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Function to reverse a queue using a stack
void reverseQueue(struct Queue* queue) {
    if (isEmpty(queue))
        return;

    int* stack = (int*)malloc(queue->size * sizeof(int));
    int top = -1;

    // Push all elements from the queue to the stack
    while (!isEmpty(queue)) {
        stack[++top] = dequeue(queue);
    }

    // Pop elements from the stack and enqueue them back to the queue
    while (top >= 0) {
        enqueue(queue, stack[top--]);
    }

    free(stack);
}

// Function to print the elements in the queue
void printQueue(struct Queue* queue) {
    int i;
    for (i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(MAX_SIZE);
    int i;

    // Enqueue elements to the queue
    for (i = 1; i <= 5; i++) {
        enqueue(queue, i);
    }

    printf("Original Queue: ");
    printQueue(queue);

    reverseQueue(queue);

    printf("Reversed Queue: ");
    printQueue(queue);

    return 0;
}