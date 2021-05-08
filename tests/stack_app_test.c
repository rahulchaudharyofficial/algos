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

bool array_eq(const int* a1, const int* a2) {
    
    if(sizeof(a1) == sizeof(a2)) {
        bool eq = true;
        for(int i=0; i< sizeof(a1);i++) {
            if(*(a1+i) != *(a2+i)) {
                eq = false;
                break;
            }
        }
        return eq;
    }
    else {
        return false;
    }
}

Test(stack_app_test, decimal_to_binary) {
    int num = 100;
    int* digit;
    int output[7];
    int expected_output[] = {1,1,0,0,1,0,0};
    while(num>0) {
        digit = (int*) malloc(sizeof(int));
        *digit = num % 2;
        push (stack, digit);
        num/=2;
    }

    int i=0;
    while(!empty_stack(stack)) {
        int* c = (int*) pop(stack);
        output[i] = *c;
        i++;
    }
    printf("\n");
    cr_assert(array_eq(output,expected_output)==0,"Must be equal");
}