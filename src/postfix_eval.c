#include "stack.h"
#include "utils.h"
#include "stack_app.h"

#define NUMERIC_START 48
#define NUMERIC_END 57


int postfix_evaluation(char* postfix_expression)
{
    //sanity Check
    assert(postfix_expression != NULL);

    //If all well then start evaluation process
    stack_t* stack = create_stack();
    int result = -1;

    while(*postfix_expression != '\0')
    {
        if(isalnum(*postfix_expression) && ((int)*postfix_expression >= NUMERIC_START && (int)*postfix_expression <= NUMERIC_END))
        {
            int token = (((int)*postfix_expression) - NUMERIC_START);
            int* data = (int*)malloc(sizeof(int));
            *data = token;
            push(stack, data);
        }
        else if(is_operator(*postfix_expression))
        {
            int* d1 = (int*)pop(stack);
            int* d2 = (int*)pop(stack);

            int res = calculate(*d1, *postfix_expression, *d2);
            int* result_ptr = (int*)malloc(sizeof(int));
            *result_ptr = res;
            push(stack, result_ptr);
        }
        postfix_expression++;
    }
    int* final_result = (int*)pop(stack);
    result = *final_result;
    destroy(stack);
    return result;
}