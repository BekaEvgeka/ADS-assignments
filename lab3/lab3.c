#include <stdio.h>
#include <stdbool.h>

#define max_size 100

typedef struct {
    int front;
    int rear;
    int elements[max_size];    
    int item_count;
}queue;

bool isempty  (queue * Q);
bool isfull   (queue * Q);
void enqueue  (queue * Q, int to_insert);
int dequeue   (queue * Q);
void show     (queue * Q);
int peek      (queue * Q);
int main(){
    queue *queue1Ptr, q1;
    queue *queue2Ptr, q2;
    queue *queue3Ptr, q3;
    queue1Ptr = &q1;
    queue2Ptr = &q2;
    queue3Ptr = &q3;

    queue1Ptr->front = -1;
    queue1Ptr->rear = -1;
    queue1Ptr->item_count = 0;

    queue2Ptr->front = -1;
    queue2Ptr->rear = -1;
    queue2Ptr->item_count = 0;

    queue3Ptr->front = -1;
    queue3Ptr->rear = -1;
    queue3Ptr->item_count = 0;


    enqueue(queue2Ptr, 1);
    enqueue(queue1Ptr, 5);
    enqueue(queue1Ptr, 111);
    enqueue(queue1Ptr, 222);
    enqueue(queue1Ptr, 333);
    enqueue(queue1Ptr, 444);
    enqueue(queue1Ptr, 555);
    enqueue(queue1Ptr, 666);
    
    enqueue(queue2Ptr, 100);
    enqueue(queue2Ptr, 200);
    enqueue(queue2Ptr, 400);
    enqueue(queue2Ptr, 500);

    // show   (queue1Ptr);
    // dequeue(queue1Ptr);
    show   (queue2Ptr);


    // printf("Queue 1 front: %d, rear: %d, elements: %d\n",queue1Ptr->front, queue1Ptr->rear, queue1Ptr->item_count);

    int element_to_queue;
    while(!isempty(queue1Ptr) || !isempty(queue2Ptr)){
        if ((peek(queue1Ptr) < peek(queue2Ptr)) || isempty(queue2Ptr)){
            element_to_queue = dequeue(queue1Ptr);
            
        }

        else if ((peek(queue1Ptr) > peek(queue2Ptr)) || isempty(queue1Ptr)){
            element_to_queue = dequeue(queue2Ptr);
        }
        enqueue(queue3Ptr, element_to_queue);
    }
    int element = (peek(queue2Ptr));
    printf("%d",element);
    show(queue3Ptr);
}

bool isfull(queue * Q){
    return (Q->item_count == max_size);
    }
bool isempty(queue * Q){

    return (Q->front > Q->rear);
}

int peek(queue * Q){
    return Q->elements[Q->front];
}
void enqueue(queue * Q, int to_insert){
    
    if (isfull(Q)){
         printf("Queue is Full!!\n");
    }     
    else {
         if (Q->front == -1)
        {
            Q->front = 0;
        }   
        Q->rear = Q->rear + 1;        
        Q->elements[Q->rear] = to_insert;
        printf("Inserted -> %d\n", Q->elements[Q->rear]);
        Q->item_count++;
    }
}
int dequeue(queue * Q){
    if (isempty(Q)){
        printf("Underflow \n");
        return 0;
    }
    else 
    {
        printf("Deleted -> %d\n", Q->elements[Q->front]);
        int dequeued_int = Q->elements[Q->front];
        Q->front = Q->front + 1;
        Q->item_count--;
        return dequeued_int;
    }
    
}
void show(queue * Q)
{
    
    if (Q->rear == -1)
        printf("\nQueue is Empty!!!");
    else {
        int i;
        printf("\nQueue elements are:\n");
        for (i = Q->front; i <= Q->rear; i++){
            printf("%d  ", Q->elements[i]);
        }
        
    }
    printf("\n");
}
