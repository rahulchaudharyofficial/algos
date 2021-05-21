#include<criterion/criterion.h>
#include "../src/stack_app.h"
#include "../src/utils.h"

stack_t* stack = NULL;

void setup() {
    stack = create_stack();
}

void teardown() {
    destroy(stack);
}

TestSuite(postfix_expression_evaluation_test, .init=setup, .fini=teardown);

Test(postfix_expression_evaluation_test, reverse_number_app) {
    int result1 = postfix_evaluation("12+3*");
    cr_assert(result1 == 9, "Must equals to 9");
    int result2 = postfix_evaluation("12+34+*");
    cr_assert(result2 == 21,"Must equal to 21");
}