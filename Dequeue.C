#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct queue* q){
    if(q->f == q->r){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct queue* q){ // Checking for full
    if(q->r == q->size - 1){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct queue* q, int val){
    if(isFull(q)){
        printf("Queue Overflow\n");
    }else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue* q){ // Dequeue operation
    int a = -1;
    if(isEmpty(q)){
        printf("Queue underflow\n");
    }else{
        q->f++; // incrementing front pointer
        a = q->arr[q->f]; // storing elements in front index
    }
    return a;
}

int main(){
    struct queue q;
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

    printf("Dequeuing elements %d\n",dequeue(&q)); // 12
    printf("Dequeuing elements %d\n",dequeue(&q)); // 15

    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }

    if(isFull(&q)){
        printf("Queue is full\n");
    }
    
    return 0;

}
