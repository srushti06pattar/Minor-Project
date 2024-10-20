#include<stdio.h>
#include<stdlib.h>
#define N 10
int top=-1;
char stack[N];
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
int check(char a[])
{
    char val,result;
    int i,j;
    for(i=0;a[i]!='\0';i++)
    {
        val=a[i];
        if(val=='c' || val=='C')
        {
            break;
        }
        else
        {
            push(a[i]);
        }
    }
    for(j=i+1;a[j]!='\0';j++)
    {
        result=pop();
        if(result!=a[j])
        {
            return 0;
            printf("%d\n",a[j]);
        }
    
    }
        if(top==-1)
            return 1;
        else
        {
            return 0;
        }
}
int main()
{
    char string[20];
    int val;
    printf("enter string\n");
    scanf("%s",string);
    val=check(string);
    if(val)
    {
        printf("string is in xcy form\n");
    }
    else
        printf("expression is not in xcy form");
}