#include<stdio.h>
#define N 5
int f=-1,r=-1;
int q[N];
void cque(int x)
{
        if((r+1)%N==f)
        {
                printf("queue is full\n");
        }
        else if(f==-1 && r==-1)
        {
                r++;f=0;
                q[r]=x;
        }
        else
        {
                r=(r+1)%N;
                q[r]=x;
        }
}
void dcque()
{
        if(f==-1 && r==-1)
        {
                printf("queue is empty\n");
        }
        else if(f==r)
        {
                printf("deletd element is %d\n",q[f]);
                f=-1,r=-1;
        }
        else
        {
                printf("deleted element is %d\n",q[f]);
                f=(f+1)%N;
        }
}
void display()
{
        int i=f;
        if(f==-1 && r==-1)
        {
                printf("queue is empty\n");
        }
        else
        {
                printf("queue is \n");
                while(i!=r)
                {
                        printf("%d\t",q[i]);
                        i=(i+1)%N;
                }
        printf("%d\n",q[r]);
        }
}
main()
{
        int ch,x;
        do
        {
                printf("enter choices\n1:cque\n2:dcque\n3:display\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:printf("enter element to insert in queue\n");
                                scanf("%d",&x);
                                cque(x);
                                break;
                        case 2:
                                dcque();
                                break;
                        case 3: display();
                                break;
                        default: printf("invalid choice\n");
                }
        } while(ch!=0);
}