#include <stdio.h>
#include <stdlib.h>
#define MaxQ 10

typedef struct queue{
    int head,tail;
    int que_arr[MaxQ];

}queue_type, *Queue;

Queue initQueq(){
    Queue queue = (Queue)malloc(sizeof(queue_type));
    queue->head = queue->tail = 0;
    return queue;
}

int empty(Queue queue){
    return (queue->head == queue->tail);
}

void enqueue(Queue queue, int num){
    if (queue->tail == MaxQ - 1){
        queue->tail = 0;
    }else {
        ++(queue->tail);
    }
    if (queue->tail == queue->head){
        printf("\n Queue is full !!! \n");
        exit(1);
    }
    queue->que_arr[(queue->tail) -1] = num;
}

int dequeue (Queue queue){
     if (queue->head == MaxQ - 1){
        queue->head = 0;
    }else {
        ++(queue->head);
    }
    int hold = queue->que_arr[(queue->head) -1];
    return hold;
}

int main(){
    Queue initQueq();
    Queue queue = initQueq();
    int num = 0;

    printf("Enter a positive num or -1 to exit:> ");
    scanf("%d ", &num);
    while (num > -1){
        enqueue(queue, num);
        scanf("%d ", &num);
    }
    
    printf("Queue data (FIFO) : ");
    while (!(empty(queue))){
        printf("%d ",dequeue(queue));
    }

    return 0;
}
