#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char array[MAX_SIZE];
};

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

int isPair(char opening, char closing) {
    return (opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']');
}

int Balance_infix_expression(struct Stack *s, char infix[]) {
    s->top = -1;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[') {
            push(s, infix[i]);
        } else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']') {
            if (s->top == -1 || !isPair(pop(s), infix[i])) {
                return 0;  // Not balanced
            }
        }
    }

    return (s->top == -1);  // If the stack is empty, the expression is balanced
}

int main() {
    char infix[MAX_SIZE];
    struct Stack stack;

    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    if (Balance_infix_expression(&stack, infix)) {
        printf("The infix expression is balanced.\n");
    } else {
        printf("The infix expression is not balanced.\n");
    }

    return 0;
}
