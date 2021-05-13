#include "stack.h"
#include<string.h>
#include<ctype.h>


int priority(char token)
{
    if (token == '^')
		return 3;
	else if (token == '/' || token == '*')
		return 2;
	else if (token == '+' || token == '-')
		return 1;
	else
		return 0;
}

void infix2postfix(stack_t* stack,char* infix)
{	
	char token;
	char *ptr = NULL;
	if(infix!=NULL && strlen(infix)>0)
	{
		while((token = *infix) != '\0')
		{
			//If token is alphanumeric then print it
			if(isalnum(token))
			{
				printf("%c",token);
			}
			else if(token == '(') //If token is open brackit then push it to stack
			{
				ptr = (char*) malloc(sizeof(char));
				push(stack,ptr);
			}
			else if(token == ')') //If token is closing bracket then keep poping from stack and print till open bracket comes
			{
				char* data = (char*) pop(stack);
				while(*data != '(')
				{
					printf("%c", *data);
					data = (char*) pop(stack);
				}
			}
			else 
			{
				char* top = stack_top(stack);
				while(priority(*top) >= priority(token))
				{
					char* data = (char*) pop(stack);
					printf("%c",*data);
				}
				char *temp = (char*) malloc(sizeof(char));
				*temp = token;
				push(stack,temp);
			}
			infix++;
		}
	}
}
