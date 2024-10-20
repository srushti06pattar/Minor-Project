#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

void infixToPostfix(char* infix) {
    struct Stack stack;
    stack.top = -1;

    printf("Postfix Expression: ");
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            printf("%c", infix[i]);
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (stack.top != -1 && stack.array[stack.top] != '(') {
                printf("%c", pop(&stack));
            }
            pop(&stack);  // Pop '('
        } else if (isOperator(infix[i])) {
            while (stack.top != -1 && precedence(stack.array[stack.top]) >= precedence(infix[i])) {
                printf("%c", pop(&stack));
            }
            push(&stack, infix[i]);
        }
    }

    while (stack.top != -1) {
        printf("%c", pop(&stack));
    }
}

int main() {
    char infix[MAX_SIZE];

    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix);

    return 0;
}