#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data; 
    struct node *next;
    
};
struct node *head,*prevnode,*nextnode,*currentnode,*newnode;
void insertion(int x)
{
    newnode=(struct node *)malloc(sizeof (struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void reverse()
{
    prevnode=NULL;
    currentnode=nextnode=head;
    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
}
void display()
{
    struct node * temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    
}
int main()
{
    insertion(3);
    insertion(5);
    insertion(7);
    insertion(9);
    insertion(2);
    display();
    printf("after reversing list\n");
    reverse();
    display();
}

