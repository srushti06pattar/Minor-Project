#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void sort_insert(int x)
{
    struct node *temp=head,*prev,*new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=x;
    if(head==NULL)
    {
        head=new;
        new->next=NULL;
        return;
    }
    if(x<=temp->data)
    {
        new->next=head;
        head=new;
    }
    if(x>temp->data)
    {
        while(temp!=NULL && x>temp->data)
        {
            prev=temp;
            temp=temp->next;
        }
        new->next=prev->next;
        prev->next=new;
    }
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
main()
{
    sort_insert(4);
    sort_insert(3);
    sort_insert(5);
    sort_insert(7);
    sort_insert(6);
    display();
    
}