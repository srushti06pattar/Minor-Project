#include <stdio.h>
#include<string.h>
#define N 10
char stack[N],n;
int top=-1;
int check(char,char);
void push(char x)
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
int bal(void)
{
    char symb,t,string[10];
    int i,valid;
    printf("enter a string\n");
    scanf("%s",string);
    n=strlen(string);
    for(i=0;string[i]!='\0';i++)
    {
        symb=string[i];
        if (symb=='('|| symb== '['||symb=='{')
        {
            push(symb);
        }
        if(symb==')'||symb==']'||symb=='}')
        {
            if(top==-1)
                return 0;
            else
            {
                t=pop();
                valid = check(symb,t);
                if(valid)
                    return 1;
                else
                    return 0;
            }
        
        }
    }
    if(top!=-1)
        return 0;
    else
        return 1;
}
int check(char s,char t)
{
    if((t=='('&& s==')')||(t=='['&& s==']') || (t=='{'||s=='}'))
        return 1;
    else
        return 0;
}
int main()
{
    int valid;
    valid=bal();
    if(valid)
        printf("expression is balanced");
    else
        printf("expression is not balanced");
}