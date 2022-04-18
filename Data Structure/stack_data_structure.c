#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10
#define ROUGE_VALUE -9595

typedef struct {
	int top;
	int stack_arr[STACK_SIZE];

} stack_type, *Stack;

Stack initStack(){
	//memory allowlocat
	Stack stack_pointer = (Stack)malloc(sizeof(stack_type ));
	stack_pointer->top = -1;
	return stack_pointer;
}

int empty (Stack stack){
    return (stack->top == -1);
}

void push (Stack stack, int num){
    if (stack->top == STACK_SIZE - 1){
        printf("\n Stack Overflow \n");
        exit (-1);
    }

    ++(stack->top);
    stack->stack_arr[stack->top] = num;
}

int pop (Stack stack) {
	if(empty(stack)){
		return ROUGE_VALUE;
	}
	int hold = stack->stack_arr[stack->top] ;
	--(stack->top);
	return hold;
}

int main (){
	Stack initStack();
	int empty(Stack);
	void push (Stack, int);

	int num;
	Stack stack = initStack();
	printf("Press 0 to exit and press any key to push data :> ");
    scanf("%d",&num);
	while (num != 0){
        push(stack, num);
		scanf("%d",&num);
	}

	while (!(empty(stack))){
		printf("%d ",pop(stack));
	}

	return 0;
}
