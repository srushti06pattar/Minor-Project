#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node * head,*temp=NULL,*newnode;
void insertbeg(int x)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
}
void deletefront()
{
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
} 
main()
{
    insertbeg(3);
    insertbeg(4);
    insertbeg(7);
    insertbeg(7);
    insertbeg(8);
    display();
    deletefront();
    deletefront();
    printf("after deletion\n");
    display();
}