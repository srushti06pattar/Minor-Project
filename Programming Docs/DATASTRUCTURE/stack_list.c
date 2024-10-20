#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *temp, *tail, *newnode;
void push(int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    if (tail == NULL)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}
void insert_end(int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    if (tail == NULL)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}
void pop()
{
    temp = tail->next;
    if (tail == NULL)
    {
        printf("list is empty\n");
    }
    else if (temp->next == temp)
    {
        printf("delted data is :%d\n", temp->data);
        tail = NULL;
        free(temp);
    }
    else
    {
        printf(" deleted data is:%d\n", temp->data);
        tail->next = temp->next;
        free(temp);
    }
}
void peek(int x)
{
    switch (x)
    {
    case 1:
        if (tail == NULL)
        {
            printf("stack is empty\n");
        }
        else
        {
            printf("top element of stack is :%d\n", tail->next->data);
        }
        break;
    case 2:
        if (tail == NULL)
        {
            printf("queue is empty\n");
        }
        else
        {
            printf("front element of queue is %d\n", tail->next->data);
        }
        break;
    default:
        printf("invalid choice\n");
    }
}
void display()
{
    if (tail == NULL)
        printf("list empty\n");
    else
    {
        temp = tail->next;
        printf("list elemnts are:\n");
        while (temp->next != tail->next)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}
main()
{
    int ch, x, y;
    do{
    printf("enter 1:stack\n 2:queue\n 3: exit\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        while (1)
        {
            printf("enter operations \n1:push\n 2:pop\n 3: peek\n 4:display\n");
            scanf("%d", &x);
            switch (x)
            {
            case 1:
                printf("enter element to insert\n");
                scanf("%d", &y);
                push(y);
                break;
            case 2:
                if (tail == NULL)
                {
                    printf("stack empty\n");
                }
                else
                {
                    pop();
                }
                break;
            case 3:
                peek(1);
                break;
            case 4:
                display();
                break;
            default:
                printf("invalid choice\n");
                break;
            }
        }
    case 2:
        while (1)
        {
            printf("enter\n 1:enqueue \n 2:dequeue\n 3:peek \n 4:display\n");
            scanf("%d", &x);
            switch (x)
            {
            case 1:
                printf("enter element to insert\n");
                scanf("%d", &y);
                insert_end(y);
                break;
            case 2:
                if (tail == NULL)
                    printf("queue empty\n");
                else
                {
                    pop();
                }
                break;
            case 3:
                peek(1);
                break;
            case 4:
                display();
                break;
            default:
                printf("invalid choice\n");
                break;
            }
        }
    case 3:
        exit(0);
        break;
    default:
        printf("invalid choice\n");
        break;
    }
    }while(ch!=0);
}