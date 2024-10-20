#include<stdio.h>
#include<stdlib.h>
#define N 2
int cq1[N];
int cq2[N];
int cq3[N];
int f1=-1,f2=-1,f3=-1,r1=-1,r2=-1,r3=-1;
void cenque(int x)
{
        if(f1==(r1+1)%N)
        {
                if(f2==(r2+1)%N)
                {
                        if(f3==(r3+1)%N)
                        {
                                printf("queue is overflow\n");
                        }
                        else
                        {
                                if(f3==-1&&r3==-1)
                                {
                                        r3++;
                                        f3++;
                                        cq3[r3]=x;
                                }
                                else
		                        {
                                        r3=(r3+1)%N;
                                        cq3[r3]=x;
                                }
                        }
                }
                else
                {
                        if(f2==-1&& r2==-1)
                        {
                                r2++;f2++;
                                cq2[r2]=x;
                        }
                        else
                        {
                                r2=(r2+1)%N;
                                cq2[r2]=x;
                        }
                }
        }
        else
        {
                if(f1==-1&&r1==-1)
                {
                        r1++;f1++;cq1[r1]=x;
                }
                else
	{
                        r1=(r1+1)%N;
                        cq1[r1]=x;
                }
        }
}
void pdqueue()
{
        if(f1==-1&&r1==-1)
        {
                if(f2==-1&&r2==-1)
                {
                        if(f3==-1&&r3==-1)
                        {
                                printf("stack underflow\n");
                        }
                        else
                        {
                                if(f3==r3)
                                {
                                        printf("deleted element is %d\n",cq3[f3]);
                                        f3=r3=-1;
                                }
                                else
                                {
                                        printf("deleted element is %d\n",cq3[f3]);
                                        f3=(f3+1)%N;
                                }
                        }
                }
                else
	{
                        if(f2==r2)
                        {
                                printf("deleted element is %d\n",cq2[f2]);
                                f2=r2=-1;
                        }
                        else
                        {
                                printf("deleted element is %d\n",cq2[f2]);
                                f2=(f2+1)%N;
                        }
                }
        }
        else
        {
                if(f1==r1)
                {
                        printf("deleted element is %d\n",cq1[f1]);
                        f1=r1=-1;
                }
                else
                {
                        printf("deleted element is %d\n",cq1[f1]);
                        f1=(f1+1)%N;
                }
        }
}
void display()
{
        int i;
        if(f1==-1&&r1==-1)
        {
                printf("queue underflow\n");
        }
        else
        {
                printf("queue 1 contents are:\n");
                for(i=f1;i!=r1;i=(i+1)%N)
                {
                        printf("%d\n",cq1[i]);
                }
        printf("%d\n",cq1[r1]);
        }
        if(f2==-1&&r2==-1)
        {
                printf("queue 2 underflow\n");
        }
        else
        {
                printf("queue 2 contents are:\n");
                for(i=f2;i!=r2;i=(i+1)%N)
                {
                        printf("%d\n",cq2[i]);
                }
}
        if(f3==-1&&r3==-1)
        {
                printf("queue 3 underflow\n");
        }
        else
        {
                printf("queue 3 contents are: \n");
                for(i=f3;i!=r3;i=(i+1)%N)
                {
                        printf("%d\n",cq3[i]);
                }
                printf("%d\n",cq3[r3]);
        }
}
int main()
{
        int ch,x;
        do
        {
                printf("enter ur choice\n 1:insert element\n 2:delete element\n 3:display\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:printf("enter element to insert into queue\n");
                                scanf("%d",&x);
                                cenque(x);
                                break;
                        case 2:pdqueue();
                                break;
                        case 3:display();
                                break;
                        default:printf("invalid choice\n");
                                break;
                }
        }
        while(ch!=0);}