#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct queue* q){
    if(q->r == q->f){
        printf("Queue empty\n");
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct queue* q){
    if((q->r + 1) % q->size == q->f){ // (q->r == q->size - 1) in linear queue.
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct queue* q, int val){
    if(isFull(q)){
        printf("Queue overflow\n");
    }else{
        q->r = (q->r + 1) % q->size; // (q->r++) in linear queue.
        q->arr[q->r] = val;
        printf("Enqueued value: %d\n",val);
    }
}

int dequeue(struct queue* q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue underflow\n");
    }else{
        q->f = (q->f + 1) % q->size; // (q->f++) in linear queue.
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 4;
    q.f = 0;
    q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int)); // Created array
    
    // Enqueue few elements

    enqueue(&q , 12);
    enqueue(&q , 15);
    enqueue(&q , 1);

    //Dequeue elements

    printf("Dequeuing elements %d\n",dequeue(&q));
    printf("Dequeuing elements %d\n",dequeue(&q));
    printf("Dequeuing elements %d\n",dequeue(&q));

    // Enqueue elements again

    enqueue(&q , 45);
    enqueue(&q , 45);
    enqueue(&q , 45);


    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }

    if(isFull(&q)){
        printf("Queue is full\n");
    }
    
    return 0;

}
