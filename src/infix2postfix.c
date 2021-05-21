#include<string.h>
#include "stack.h"
#include "stack_app.h"
#include "utils.h"

/**
 * This is very important
 * 
 * 
 */
char* infix2postfix(char* infix)
{
    stack_t* stack = create_stack();
    char token;
	char* output = (char*) calloc((strlen(infix)+1), sizeof(char));
    //Till reach end of string
	int count = 0;
    while((token = *infix) != '\0') 
    {
        if(isalnum(token))
        {
            //printf("%c",token);
			*(output + count) = token;
            count++;
        }
        else if(token == '(')
        {
            char* temp = (char*) malloc(sizeof(char));
            *temp = token;
            push(stack, temp);
        }
        else if(token == ')')
        {
            char* temp = (char*) pop(stack);
            while(!isempty(stack) && *temp != '(')
            {
                //printf("%c",*temp);
				*(output+ count) = *temp;
				count++;
                temp = (char*) pop(stack);
            }
        }
        else if(is_operator(token)) {
            char* t = (char*) top(stack);
            while(t!=NULL && (priority(*t) >= priority(token)))
            {
                char* data = (char*) pop(stack);
                //printf("%c",*data);
				*(output+ count) = *data;
				count++;
                t = (char*) top(stack);
            }
            t = (char*) malloc(sizeof(char));
            *t = token;
            push(stack, t);
        }
        infix++;
    }
    
    if(!isempty(stack))
    {
        char* temp = (char*) top(stack);
        while(temp != NULL && !isempty(stack))
        {
            temp = (char*) pop(stack);
            *(output + count) = *temp;
            count++;
        }
        
    }
    
   if(!isempty(stack))
    {
        printf("stack is not empty yet");
        char* t = (char*) top(stack);
        printf("value = %c\n", *t);
    }
    printf("\n");
	return output;
}