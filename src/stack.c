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
		//success_print("Stack successfully created");
		return stack;
	}
	else {
		error_print("MemoryOverflowError: Failed to create stack");
		return NULL;
	}
}

bool push(stack_t* stack, void* dataPtr) {
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
	void *output = NULL;
	if(stack) {
		if(!empty_stack(stack)) {
			node_t *temp = stack->top;
			output = temp->dataPtr;
			stack->top = temp->link;
			free(temp);
			temp = NULL;
			(stack->count)--;
		}
		else {
			error_print("StackUnderflowError : Stack is empty, nothing to pop");
		}
	}
	else {
		error_print("StackError: Stack is NULL, push is not allowed");
	}
	return output;
}

bool empty_stack(stack_t* stack) {
	if(stack->count == 0)
		return true;
	return false;
}

/**
 * Try creating a node if fail then throw StackOverflowError
 */ 
bool full_stack(stack_t* stack) {
	node_t *node = (node_t*) malloc(sizeof(node_t));
	if(node) {
		free(node);
		node = NULL;
		return false;
	}
	return true;
}

void* stack_top(stack_t* stack) {
	void* output = NULL;
	if(stack) {
		if(!empty_stack(stack)) {
			output = stack->top->dataPtr;
		}
	}
	else {
		error_print("StackError: Stack is NULL, Nothing to Top");
	}
	return output;
}

void destroy_stack(stack_t* stack) {
	if(stack)
	{
		if(!empty_stack(stack)) {
			node_t* temp;

			while(stack->top != NULL) {
				free(stack->top->dataPtr);
				temp = stack->top;
				stack->top = temp->link;
				free(temp);
			}
			free(stack);
			stack = NULL;
		}
		else {
			free(stack);
			stack = NULL;
		}
	}
	else {
		error_print("StackError: Stack is NULL, Nothing to destroy");
	}
}

int stack_count(stack_t* stack) {
	if(stack) {
		return stack->count;
	}
	else {
		error_print("StackError: Stack is NULL");
		return -1;
	}
}

/**
 * To run and print stack run make task
 * uncomment line that build bin task in makefile
 * make bin/main
 * then run the executable ./bin/main
 * 
int main(int argc, char const *argv[])
{
	warning_print("Starting to print stack");
	stack_t *stack = create_stack();
	int *dataPtr = NULL;
	int i= 1;
	while(i<=10) {
		dataPtr = (int*) malloc(sizeof(int));
    	*dataPtr = i;
    	push(stack,dataPtr);
		i++;
	}
	
	while(stack->top!=NULL) {
		node_t* temp = stack->top;
		int *data = temp->dataPtr;
		printf("%d\t",*data);
		stack->top = temp->link;
	}
	printf("\n");
	destroy_stack(stack);
	warning_print("Finished printing stack");
	return 0;
}
*/
