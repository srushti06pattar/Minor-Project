#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *pre;
    struct node *next;
};
struct node *temp, *head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL;
void insert_end(int x)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d", &new->data);
    switch (x)
    {
    case 1:
        if (head1 == NULL)
        {
            head1 = tail1 = new;
            new->pre = NULL;
            new->next = NULL;
        }
        else
        {
            tail1->next = new;
            new->pre = tail1;
            new->next = NULL;
            tail1 = new;
        }
        break;
    case 2:
        if (head2 == NULL)
        {
            head2 = tail2 = new;
            new->pre = NULL;
            new->next = NULL;
        }
        else
        {
            tail2->next = new;
            new->pre = tail2;
            new->next = NULL;
            tail2 = new;
        }
        break;
    default:
        printf("invalid choice\n");
    }
}
void display(int x)
    {
            struct node *temp;
            switch (x)
            {
            case 1:
                temp = head1;
                if (head1 == NULL)
                {
                    printf("list1 is empty\n");
                }
                else
                {
                    while (temp != NULL)
                    {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                }
                printf("\n");
                break;
            case 2:
                temp = head2;
                if (head2 == NULL)
                {
                    printf("list2 is empty\n");
                }
                else
                {
                    while (temp != NULL)
                    {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                }
                printf("\n");
                break;
            default:
                printf("Error\n");
                break;
            }
        }
        void concatenate()
        {
                if (head1 == NULL && head2 == NULL)
            {
                printf("concatenated list is empty\n");
                exit(0);
            }
            else if (head1 == NULL)
            {
                head1 = head2;
                tail1 = tail2;
            }
            else if (head2 == NULL)
            {
                return;
            }
            else
            {
                tail1->next = head2;
                head2->pre = tail1; // head1=head2
                tail1 = tail2;
            }
        }
        main()
        {
            int x;
            while (1)
            {
                printf("enter\n1:insert in link list 1\n2:insert in link list2\n3:concatenate\n");
                scanf("%d", &x);
                switch (x)
                {
                case 1:
                    insert_end(1);
                    break;
                case 2:
                    insert_end(2);
                    break;
                case 3:
                    printf("list 1 is:\n");
                    display(1);
                    printf("list 2 is:\n");
                    display(2);
                    concatenate();
                    printf("list after concatenation:\n");
                    display(1);
                    exit(0);
                default:
                    printf("invalid input\n");
                    break;
                }
            }
        }