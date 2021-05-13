#ifndef _STACK_H_
#define _STACK_H_
	#include<stdio.h>
	#include<stdlib.h>
	#include<stdbool.h>

	typedef struct Stack stack_t;
	typedef struct Node node_t;

	stack_t* create_stack();
	bool push(stack_t*, void*);
	void* pop(stack_t*);
	bool empty_stack(stack_t*);
	bool full_stack(stack_t*);
	void destroy_stack(stack_t*);
	void* stack_top(stack_t*);
	int stack_count(stack_t*);
#endif
