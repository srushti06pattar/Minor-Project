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
void delete_pos()
{
    int pos,i=1;
    temp=head;
    printf("postion to delete elemenet\n");
    scanf("%d",&pos);
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode=temp->next;
    temp->next=newnode->next;
    free(newnode);
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
    delete_pos();
    display();
}
