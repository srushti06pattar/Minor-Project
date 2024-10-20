#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 20
int operation(int,int,char);
int stack[N],top=-1;
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
int pop()
{
    if(top==-1)
        printf("stack is empty\n");
    else
        return stack[top--];
}
int postfix(char a[])
{
    char symb;
    int op2,op1,i,result,num;
    for(i=0;a[i]!='\0';i++)
    {
            symb=a[i];
            if(symb=='+'||symb=='-'||symb=='*'||symb=='/'||symb=='$')
            {
                op2=pop();
                op1=pop();
                result=operation(op2,op1,symb);
                push(result);
            }
            else
        {
            num=symb-48;
            push(num);
    
        }
    }
    return pop();
}
int operation(int x,int y,char symb)
{
    switch(symb)
    {
        case'+':return x+y;
                break;
        case'-':return y-x;
                break;
        case'*':return x*y;
                break;
        case'/':return x/y;
                break;
        case'$':return pow(x,y);
                break;
        default:printf("invalid choice\n");
    }
}
int main()
{
    char string[10];
    int value;
    printf("enter string\n");
    scanf("%s",string);
    value=postfix(string);
    printf("value of postfix expressiom is %d\n",value);
}