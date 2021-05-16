#include "stack.h"
#include "utils.h"

#define NUMERIC_START 48
#define NUMERIC_END 57


int postfix_evaluation(stack_t* stack, char* postfix_expression)
{
    //sanity Check
    assert(stack != NULL);
    assert(postfix_expression != NULL);

    //If all well then start evaluation process
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
    return result;
}

int main(int argc, char const *argv[])
{
    stack_t* stack = create_stack();
    int result1 = postfix_evaluation(stack, "12+3*");
    assert(result1 == 9);

    int result2 = postfix_evaluation(stack, "12+34+*");
    assert(result2 == 21);
    destroy(stack);
    return 0;
}
