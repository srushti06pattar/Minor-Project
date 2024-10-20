#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data; 
    struct node *next;
    
};
struct node *head,*newnode,*temp;
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
void insert_pos()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    int pos,i=1;
    temp=head;
    printf("enter postion to insert\n");
    scanf("%d",&pos);
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    printf("enter element to insert\n");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next=newnode;
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
    insert_pos();
    display();
}
