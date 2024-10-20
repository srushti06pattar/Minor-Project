#include <stdio.h>
#include<ctype.h>
#include<string.h>
#define N 10
char stack[N];
int top=-1;
void push(int x)
{
    if(top==N-1)
        printf("stack is full\n");
    else
        {
            top++;
            stack[top]=x;
        }
}
char pop()
{
    if(top==-1)
        printf("stack is empty\n");
    else
        return stack[top--];
}
int priority(char x)
{
    if(x== '(')
        return 0;
    if(x== '+'|| x== '-')
        return 1;
    if(x== '*'|| x== '/')
        return 2;
    if(x== '$')
        return 3;
}
int main()
{
    char exp[20];
    char *symb,x;
    printf("enter infix expression\n");
    scanf("%s",exp);
    symb=exp;
    while(*symb!='\0')
    {
        if(isalpha(*symb)||isdigit(*symb))
            printf("%c",*symb);
        else if(*symb=='(')
            push(*symb);
        else if(*symb==')')
        {
                while((x=pop())!='(')
                printf("%c",x);

        }
        else
        {
            while(priority(stack[top])>=priority(*symb))
            {
                printf("%c",pop());
            }
            push(*symb);
        }symb++;
    }
    while(top!=-1)
    {
            printf("%c",pop());
    }
}
