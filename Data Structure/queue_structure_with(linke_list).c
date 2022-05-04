#include <stdio.h>
#include <stdlib.h>

typedef struct queue_data {
    int data;
}queue_data;

typedef struct node{
    queue_data data;
    struct node *next ;
}node_type, *Node;

typedef struct queue{
    Node head,tail;
}queue_type, *Queue;


int empty(Queue queue){
    return (queue->head == NULL);
}

Queue initQueue () {
    Queue queue = (Queue) malloc (sizeof(Queue));
    queue->head = NULL ;
    queue->tail = NULL ;
    return queue;
}

void enqueue (Queue queue, queue_data num){
    Node node = (Node) malloc (sizeof(Node));
    node->data = num ;
    node->next = NULL ;

    if (empty(queue)){
        queue->head = node ;
        queue->tail = node ;
    }else {
        queue->tail->next = node;
        queue->tail = node;
    }
}

queue_data dequeue (Queue queue){
    if (empty(queue)){
        printf ("Queue is full...");
        exit(1);
    }

    queue_data hold = queue->head->data ;
    Node temp = queue->head;
    queue->head = queue->head->next;

    if (queue->head == NULL){
        queue->tail = NULL ;
    }

    free(temp);
    return hold;
}

int main (){
    int num ;
    queue_data temp;
    Queue queue = initQueue();

    printf("Enter a positive num:> ");
    scanf("%d ", &num);
    while (num > 0){
        temp.data = num ;
        enqueue (queue, temp);
        scanf("%d ", &num);
    }

    printf("data : ");
    while (!(empty(queue))){
        printf("%d ",dequeue(queue).data);
    }

    return 0;
}
