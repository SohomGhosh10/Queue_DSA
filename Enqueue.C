#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f; // Front pointer
    int r; // Rear pointer
    int* arr; // Array size
};

int isEmpty(struct queue* q){
    if(q->f == q->r){ // Queue empty condition
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct queue* q){ // Checking for full
    if(q->r == q->size - 1){ // Queue full condition
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct queue* q, int val){ // Enqueue operation
    if(isFull(q)){
        printf("Queue Overflow\n");
    }else{
        q->r++;
        q->arr[q->r] = val; // pushing elements
    }
}

int main(){
    struct queue q;
    // initialize

    q.size = 10;
    q.f = -1; 
    q.r = -1;
    q.arr = (int*)malloc(q.size * sizeof(int)); // Created array

    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    // Enqueue few elements

    enqueue(&q,12);
    enqueue(&q,15);
    if(isEmpty(&q)){ // for empty
        printf("Queue is empty\n");
    }

    if(isFull(&q)){ // for full
        printf("Queue is full\n");
    }
    
    return 0;

}
