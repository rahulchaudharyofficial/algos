#include<criterion/criterion.h>
#include "../src/stack.h"
#include<string.h>

stack_t* stack = NULL;

void setup() {
    stack = create_stack();
}

void teardown() {
    destroy_stack(stack);
}

TestSuite(stack_app_test, .init=setup, .fini=teardown);

Test(stack_app_test, reverse_number_app) {
    char* input = "Rahul Chaudhary";
    int size = strlen(input)+1;
    char* output = (char*) malloc(size);
    
    char* expected_output = "yrahduahC luhaR";

    char* c = NULL;
    while(*input != '\0') {
        c = (char*) malloc(sizeof(char));
        *c = *input;
        push(stack, c);
        input++;
    }

    int i=0;
    while(!empty_stack(stack)) {
        char* c = (char*) pop(stack);
        output[i] = *c;
        i++;
    }

    output[i] = '\0';
    cr_assert(strcmp(output,expected_output)==0,"Must be equal");
}