#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node * head,*temp,*newnode;
void insertion(int x)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
int search(int key)
{
    temp=head;int i=1;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return i;
        }
        i++;
        temp=temp->next;
    }
    return 0;
}
int main()
{
    int k,x,y,val;
    while(1)
    {
        printf("enter\n1:insertion\n 2:search\n 3:exit\n");
        scanf("%d",&x);
        switch (x)
        {
        case 1:printf("enter element to insert\n");
                scanf("%d",&y);
                insertion(y);
                break;
        case 2:printf("enter element to search\n");
                scanf("%d",&k);
                val=search(k);
                if(val!=0)
                {
                    printf("search is successful\n");
                    printf("element %d is found at %d postion in the list\n",k,val);

                }
                else
                {
                        printf("search is unsuccessful\n");
                        printf("insert %d to the list\n",k);
                        insertion(k);
                }
        case 3:exit(0);
                break;
        
        default:printf("invalid choice\n");
            break;
        }
    }
}