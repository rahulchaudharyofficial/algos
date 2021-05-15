#include<criterion/criterion.h>
#include "../src/stack.h"
#include "../src/utils.h"
#include<string.h>

stack_t* stack = NULL;

void setup() {
    stack = create_stack();
}

void teardown() {
    destroy(stack);
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
    while(!isempty(stack)) {
        char* c = (char*) pop(stack);
        output[i] = *c;
        i++;
    }

    output[i] = '\0';
    cr_assert(strcmp(output,expected_output)==0,"Must be equal");
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
    while(!isempty(stack)) {
        int* c = (int*) pop(stack);
        output[i] = *c;
        i++;
    }
    cr_assert(array_eq(output,expected_output)==0,"Must be equal");
}


Test(stack_app_test, valid_parsing_test) {
    char* expr1 = "((a+b)/c)";
    char* c = NULL;
    while(*expr1!='\0') {
        c = (char*) malloc(sizeof(int));
        *c = *expr1;
        if(*c=='(' || *c=='{' || *c=='[') {
            push(stack, c);
        }
        else if(!isempty(stack) && (*c == ')' || *c == '}' || *c == ']')) {
            char *t = (char*) pop(stack);
            free(t);
            t = NULL;
        }
        expr1++;
    }
    cr_assert(isempty(stack)==true,"Stack must be empty");
}

Test(stack_app_test, invalid_parsing_test) {
    char* expr1 = "((a+b)/c";
    char* c = NULL;
    while(*expr1!='\0') {
        c = (char*) malloc(sizeof(int));
        *c = *expr1;
        if(*c=='(' || *c=='{' || *c=='[') {
            push(stack, c);
        }
        else if(!isempty(stack) && (*c == ')' || *c == '}' || *c == ']')) {
            char *t = (char*) pop(stack);
            free(t);
            t = NULL;
        }
        expr1++;
    }
    cr_assert(isempty(stack)==false,"Stack must not be empty");
}

Test(stack_app_test, sourcefile_parsing_test) {
    char token;
    char* dataPtr;
    char *fileId = "src/stack.c";
    FILE* fpIn = fopen(fileId, "r");
    int lineCount = 1;
    if(fpIn) {
        while((token = fgetc(fpIn)) != EOF) {
            if(token == '\n')
                lineCount++;
            if(token == '(' || token == '{' || token == '[') {
                dataPtr = (char*) malloc(sizeof(char));
                *dataPtr = token;
                push(stack, dataPtr);
            }
            else {
                if(token == ')' || token == '}' || token == ']') {
                    pop(stack);
                }
            }
        }
        printf("Total line count = %d\n", lineCount);
        cr_assert(isempty(stack) == true, "Stack must be empty");
        destroy(stack);
    }
    else {
        printf("FileNotFoundError: Unable to locate source %s\n",fileId);
    }
}

Test(stack_app_test, test_data_file_parsing_test) {
    char token;
    char* dataPtr;
    char *fileId = "tests/data/parse_test_data.txt";
    FILE* fpIn = fopen(fileId, "r");
    int lineCount = 1;
    if(fpIn) {
        while((token = fgetc(fpIn)) != EOF) {
            if(token == '\n')
                lineCount++;
            if(token == '(' || token == '{' || token == '[') {
                dataPtr = (char*) malloc(sizeof(char));
                *dataPtr = token;
                push(stack, dataPtr);
            }
            else {
                if(token == ')' || token == '}' || token == ']') {
                    pop(stack);
                }
            }
        }
        printf("Total line count = %d\n", lineCount);
        cr_assert(isempty(stack) == true, "Stack must be empty");
        destroy(stack);
    }
    else {
        printf("FileNotFoundError: Unable to locate source %s\n",fileId);
    }
}