#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define stack structure
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Stack operations
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // '$' denotes an empty value
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to get the precedence of an operator
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix expression to postfix expression
void conversion_infix_to_postfix(struct Stack* stack, char infix[]) {
    int i, k;

    // Traverse the infix expression
    for (i = 0, k = -1; infix[i]; ++i) {
        // If the current character is an operand, add it to the output
        if (isalnum(infix[i]))
            infix[++k] = infix[i];
        
        // If the current character is an '(', push it onto the stack
        else if (infix[i] == '(')
            push(stack, infix[i]);
        
        // If the current character is an ')', pop and output operators until '(' is encountered
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                infix[++k] = pop(stack);
            pop(stack); // Pop '(' from the stack
        }
        
        // If the current character is an operator
        else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
                infix[++k] = pop(stack);
            push(stack, infix[i]);
        }
    }

    // Pop all the remaining operators from the stack
    while (!isEmpty(stack))
        infix[++k] = pop(stack);

    // Null-terminate the postfix expression
    infix[++k] = '\0';

    // Print the postfix expression
    printf("Postfix Expression: %s\n", infix);
}

int main() {
    struct Stack* stack = createStack(100);
    char infix1[] = "A + B * ( C - ( D / E ) ^ G )";
    char infix2[] = "F - ( K / ( H * S ) ^ J ) + X";

    conversion_infix_to_postfix(stack, infix1);
    conversion_infix_to_postfix(stack, infix2);

    return 0;
}
