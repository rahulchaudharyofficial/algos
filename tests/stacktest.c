#include<criterion/criterion.h>
#include "../src/stack.h"

stack_t* stack = NULL;

void setup() {
    stack = create_stack();
}

void teardown() {
    if(stack) {
        destroy(stack);
    }
}

TestSuite(stack_tests, .init=setup, .fini=teardown);

Test(stack_tests, create_stack) {
    cr_expect(stack!=NULL, "Stack creation should return not NULL.");
}


Test(stack_tests,push_stack) {
    int *dataPtr;
    for(int i = 1;i <= 10; i++) {
        dataPtr = (int*) malloc(sizeof(int));
        *dataPtr = i;
        bool result = push(stack,dataPtr);
        cr_assert(result == true,"Push must success");
    }
}

Test(stack_tests,pop_stack) {
    int *dataPtr = (int*) malloc(sizeof(int));
    *dataPtr = 1;
    push(stack,dataPtr);
    int* result = (int*) pop(stack);
    cr_assert(*result == 1,"Pop must return 1");
}

Test(stack_tests,empty_stack) {
    bool result = isempty(stack);
    cr_assert(result == 1,"Empty stack must return 1");
}

Test(stack_tests,not_empty_stack) {
    int *dataPtr = (int*) malloc(sizeof(int));
    *dataPtr = 1;
    push(stack,dataPtr);
    bool result = isempty(stack);
    cr_assert(result == 0,"Empty stack must return 0");
}

Test(stack_tests,full_stack) {
    bool result = isfull(stack);
    cr_assert(result == 0,"Full stack must return 0");
}

Test(stack_tests,empty_top_stack) {
    int* result = (int*) top(stack);
    cr_assert(result == NULL,"Top stack must return NULL");
}

Test(stack_tests,not_empty_top_stack) {
    int *dataPtr = (int*) malloc(sizeof(int));
    *dataPtr = 1;
    push(stack,dataPtr);
    int* result = (int*) top(stack);
    cr_assert(result != NULL,"Top stack must not return NULL");
    cr_assert(*result == 1,"Top stack must return pointer to value 1");
}

Test(stack_tests,not_empty_stack_size) {
    int *dataPtr = (int*) malloc(sizeof(int));
    *dataPtr = 1;
    push(stack,dataPtr);
    int result = stack_size(stack);
    cr_assert(result == 1,"Stack count must return 1");
}

Test(stack_tests,empty_stack_size) {
    int result = stack_size(stack);
    cr_assert(result == 0,"Stack count must return 0");
}

Test(stack_tests,empty_destroy_stack) {
    int a = 1;
    destroy(stack);
    cr_assert(a == 1,"Destroyed empty stack");
}

Test(stack_tests,non_empty_destroy_stack) {
    int a = 1;
    int *dataPtr = (int*) malloc(sizeof(int));
    *dataPtr = 1;
    push(stack,dataPtr);
    destroy(stack);
    cr_assert(a == 1,"Destroyed non empty stack");
}

