#include "utils.h"

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

bool is_operator(char token)
{
    if(token == '+' || token == '-' || token == '*' || token == '/' || token == '^')
        return true;
    else
        return false;
}

int calculate(int operand1, int oper, int operand2)
{
    int result;
    switch (oper)
    {
    case '+':
        result = operand1 + operand2;
        break;
    case '-':
        result = operand1 - operand2;
        break;
    case '*':
        result = operand1 * operand2;
        break;
    case '/':
        result = operand1 / operand2;
        break;
    default:
        result = 0; //make it fail
        break;
    }
    return result;
}