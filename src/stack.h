#ifndef _STACK_H_
#define _STACK_H_
	#include<stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    #include<assert.h>
	#include<ctype.h>

    typedef struct Node node_t;
    typedef struct Stack stack_t;

    stack_t* create_stack();
    node_t* create_node();
    bool push(stack_t*, void*);
    void* pop(stack_t*);
    void* top(stack_t*);
    void destroy(stack_t*);
    bool isfull(stack_t*);
    bool isempty(stack_t*);
	int stack_size(stack_t*);
#endif
