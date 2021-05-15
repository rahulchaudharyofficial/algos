#include<string.h>
#include <criterion/criterion.h>
#include "../src/stack_app.h"

stack_t* stack = NULL;

void setup() {
    stack = create_stack();
}

void teardown() {
    if(stack) {
        destroy(stack);
    }
}

TestSuite(infix2postfix_test, .init=setup, .fini=teardown);

Test(infix2postfix_test, infix_to_postfix_conversion_test1) {
    char* infix = "((A+B)*C)";
    char* expected_output = "AB+C*";

    char* actual_output = infix2postfix(infix);
    //printf("output = %s\n", actual_output);
    cr_assert(strcmp(actual_output,expected_output) == 0, "Must be equals");
}

Test(infix2postfix_test, infix_to_postfix_conversion_test2) {
    char* infix = "((A+B)*(C+D))";
    char* expected_output = "AB+CD+*";

    char* actual_output = infix2postfix(infix);
    //printf("output = %s\n", actual_output);
    cr_assert(strcmp(actual_output,expected_output) == 0, "Must be equals");
}