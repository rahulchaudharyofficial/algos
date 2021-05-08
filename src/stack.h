#ifndef _STACK_H_
#define _STACK_H_
	typedef struct Stack stack_t;
	typedef struct Node node_t;
	typedef enum Boolean {false, true} bool_t;

	stack_t* create_stack();
	bool_t push(stack_t*, void*);
	void* pop(stack_t*);
	bool_t empty_stack(stack_t*);
	bool_t full_stack(stack_t*);
	stack_t* destroy_stack(stack_t*);
#endif
