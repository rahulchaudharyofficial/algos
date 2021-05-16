#include "stack.h"
#include "color.h"

struct Node
{
    void *data;
    struct Node *link;
};

struct Stack
{
    int size;
    struct Node *top;
};

//Create stack
stack_t* create_stack()
{
    stack_t *st = NULL;

    if ((st = (stack_t *)malloc(sizeof(stack_t))) != NULL)
    {
        st->size = 0;
        st->top = NULL;
    }
    return st;
}

node_t* create_node()
{
    node_t* node = NULL;
    if((node = (node_t*) malloc(sizeof(node_t))) != NULL)
    {
        node->data = NULL;
        node->link = NULL;
    }
    return node;
}

//Push item to stack
bool push(stack_t *st, void *data)
{
    bool result = false;
    //Sanity check
    assert(st != NULL);
    assert(data != NULL);

    if(!isfull(st))
    {
        node_t* node = create_node();
        assert(node != NULL);
        node->data = data;
        node->link = st->top;
        st->top = node;
        st->size += 1;
        result = true;
    }
    return result;
}
void* pop(stack_t* st)
{
    void* result = NULL;
    assert(st != NULL);
    if(!isempty(st))
    {
        node_t* temp = st->top;
        result = temp->data;
        st->top = temp->link;
        free(temp);
        temp = NULL;
        st->size -= 1;
    }
    return result;
}

void* top(stack_t* st)
{
    void* result = NULL;
    if(st && !isempty(st))
    {
        result = st->top->data;
    }

    return result;
}
void destroy(stack_t* st)
{
    node_t *temp = NULL;
    while(!isempty(st))
    {
        temp = pop(st);
        free(temp);
    }
    free(st);
}

bool isfull(stack_t *stack)
{
    bool result = false;
    node_t *node = (node_t*) malloc(sizeof(node_t));
    if(node == NULL)
    {
        result = true;
    }
    else {
        free(node);
    }
    return result;
}

bool isempty(stack_t *st)
{
    assert(st != NULL);
    bool result = false;
    if(st->size == 0 && st->top == NULL)
    {
        result = true;
    }
    return result;   
}

int stack_size(stack_t* stack)
{
	assert(stack != NULL);
	return stack->size;
}
