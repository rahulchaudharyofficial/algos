#include "stack.h"
#include<string.h>

int priority(char token)
{
    if(token == '^')
        return 3;
    if(token == '*' || token == '/')
        return 2;
    if(token == '+' || token == '-')
        return 1;
    return 0;
}

char* infix2postfix(char* infix)
{
    stack_t* stack = create_stack();
    char token;
	char* output = (char*) calloc(sizeof(char) * (strlen(infix)+1));
    //Till reach end of string
	int count = 0;
    while((token = *infix) != '\0') 
    {
        if(isalnum(token))
        {
            printf("%c",token);
			*(output+ count) = token;
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
                printf("%c",*temp);
				*(output+ count) = token;
				count++;
                temp = (char*) pop(stack);
            }
        }
        else {
            char* t = (char*) top(stack);
            while(t!=NULL && (priority(*t) >= priority(token)))
            {
                char* data = (char*) pop(stack);
                printf("%c",*data);
				*(output+ count) = token;
				count++;
                t = (char*) top(stack);
            }
            t = (char*) malloc(sizeof(char));
            *t = token;
            push(stack, t);
        }
        infix++;
    } 
    printf("\n");
	return output;
}