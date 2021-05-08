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
		stack->count = 0;
		stack->top = NULL;
		success_print("Stack successfully created");
		return stack;
	}
	else {
		error_print("MemoryOverflowError: Failed to create stack");
		return NULL;
	}
}

bool_t push(stack_t* stack, void* dataPtr) {
	if(stack) {
		if(!full_stack(stack)) {
			node_t *node = (node_t*) malloc(sizeof(node_t));
			node->dataPtr = dataPtr;
			node->link = stack->top;
			stack->top = node;
			(stack->count)++;
			return true;
		}
		else {
			error_print("StackOverFlowError: Can not push another node");
			return false;
		}
	}
	else {
		error_print("StackError: Stack is NULL, push is not allowed");
		return false;
	}
}

void* pop(stack_t* stack) {
	return NULL;
}

bool_t empty_stack(stack_t* stack) {
	if(stack->count == 0)
		return true;
	return false;
}

/**
 * Try creating a node if fail then throw StackOverflowError
 */ 
bool_t full_stack(stack_t* stack) {
	node_t *node = (node_t*) malloc(sizeof(node_t));
	if(node)
	{
		free(node);
		node = NULL;
		return false;
	}
	return true;
}

stack_t* destroy_stack(stack_t* stack) {
	return NULL;
}


int main(int argc, char **argv) {
	//stack_t *stack = create_stack();

	return 0;
}
