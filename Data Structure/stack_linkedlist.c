// Structure with linked list 
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data ;
    struct node* next;
}*Node , node_type;

typedef struct stack {
    Node top;
}*Stack , stack_type;

Stack initStack () {
    Stack stack = (Stack) malloc (sizeof(stack_type));
    stack->top = NULL;
    return stack;
}

int empty (Stack stack){
    return (stack->top == NULL);
}

void push (Stack stack, int num){
    Node node = (Node) malloc (sizeof(node_type));
    node->data = num;
    node->next = stack->top;
    stack->top = node;
}

int pop (Stack stack) {
    if (empty(stack)){
        printf("Stack is Empty");
    }
    int hold = stack->top->data;
    Node temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return hold;
}

int main (){
	Stack stack = initStack();
    int num = 0;

    printf("Enter a Stack data : ");
    scanf("%d", &num);
    while (num > -1){
        push(stack, num);
        scanf("%d", &num);
    }

    printf("Stack Data (LIFO) : ");
    while (!empty(stack)){
        printf("%d ", pop(stack));
    }

	return 0;
}