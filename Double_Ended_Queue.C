#include<stdio.h>
#include<stdlib.h>

struct DEQueue{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct DEQueue* q){
    if(q->r == q->f){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct DEQueue* q){
    if(q->r == q->size - 1){
        return 1;
    }else{
        return 0;
    }
}

//Enqueue at rear

void EnQueueR(struct DEQueue* q, int val){
    if(isFull(q)){
        printf("Queue is full\n");
    }else{
        q->r++;
        q->arr[q->r] = val;
    }
}

//Enqueue at front

void EnQueueF(struct DEQueue* q, int val){
    if(isFull(q) || q->f == -1){
        printf("Queue is full\n");
    }else{
        q->f--;
        q->arr[q->f] = val;
    }
}

//Deletion at rear end

int DeQueueR(struct DEQueue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }else{
       int val;
       val = q->arr[q->r];
       q->r--;
       return val;  
    }
}

//Deletion at front

int DeQueueF(struct DEQueue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }else{
        int val;
        val = q->arr[q->f];
        q->f++;
        return val;
    }
}

// Displaying the DEQueue element

void Display(struct DEQueue *q)
{
    int i = 0;
    while(i <= (q->r))
    {
        printf("Element:%d\n",q->arr[i]);
        i++;
    }
}

int main()
{
struct DEQueue *q=(struct DEQueue *) malloc(sizeof(struct DEQueue));
q->size=5;
q->f = q->r = -1;
q->arr = (int *)malloc(q->size * sizeof(int));

EnQueueR(q,15);
EnQueueR(q,19);
EnQueueR(q,25);
EnQueueR(q,95);
EnQueueR(q,55);
EnQueueR(q,59);



Display(q);
printf("Element is DeQueued at the front:%d\n",DeQueueF(q));
Display(q);
printf("Element is DeQueued at the rear:%d\n",DeQueueR(q));
Display(q);

return 0;
}