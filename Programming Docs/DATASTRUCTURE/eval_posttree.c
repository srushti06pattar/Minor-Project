#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 50
int top = -1, oprt(char);
struct node
{
    char data;
    struct node *left;
    struct node *right;
};
struct node *stack[N];
void push(struct node *x)
{
    if (top == N - 1)
        printf("stack overflow\n");
    else
    {
        stack[++top] = x;
    }
}
struct node *pop()
{
    if (top == -1)
        printf("stack underflow\n");
    else
    {
        return stack[top--];
    }
}
struct node *new(char ch)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ch;
    temp->left = temp->right = NULL;
    return temp;
}
struct node *exp_tree(char postfix[])
{
    int i = 0;
    char ch;
    struct node *node;
    while (postfix[i] != '\0')
    {
        ch = postfix[i];
        node = new (ch);
        if (oprt(ch))
        {
            node->right = pop();
            node->left = pop();
            push(node);
        }
        else
        {
            push(node);
        }
        i++;
    }
    return node;
}
int oprt(char ch)
{
    if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '$'))
        return 1;
    else
        return 0;
}
int evaluation(struct node *root)
{
    if (oprt(root->data))
    {
        char ch = root->data;
        int left = evaluation(root->left);
        int right = evaluation(root->right);
        switch (ch)
        {
        case '+':
            return left + right;
            break;
        case '-':
            return left - right;
            break;
        case '*':
            return left * right;
            break;
        case '/':
            return left / right;
            break;
        case '$':
            return pow(left, right);
            break;
        default:
            printf("invalid choice\n");
        }
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return (root->data - '0');
    }
}
void main()
{
    struct node *root=NULL;
    char postfix[N];
    printf("enter postfix expression\n");
    scanf("%s",postfix);
    root=exp_tree(postfix);
    int n=evaluation(root);
    printf("evaluation of postfix expression  %s: %d\n",postfix,n);
    
}