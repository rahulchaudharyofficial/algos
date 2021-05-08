#include<stdio.h>
#include<stdlib.h>

#include "stack.h"
#include "color.h"

struct Node {
	void *dataPtr;
	struct Node *link;
};

struct Stack {
	int count;
	struct Node *top;
};

stack_t* create_stack() {
	stack_t *stack = (stack_t*) malloc(sizeof(stack_t));
	if(stack)
	{
		printf("%sStack successfully created!%s\n",GRN,NRM);
		return stack;
	}
	else {
		printf("%sMemoryOverflowError: Failed to create stack%s\n",RED,NRM);
	}
}

stack_t* push(stack_t* stack, void* dataPtr) {

}

stack_t* pop(stack_t* stack) {

}

bool_t empty_stack(stack_t* stack) {

}

bool_t full_stack(stack_t* stack) {

}

stack_t* destroy_stack(stack_t* stack) {

}


int main(int argc, char **argv) {
	create_stack();
	return 0;
}
