#include<stdio.h>
#define N 5
int q[N];
int f=-1,r=-1;
void insertfront(int x)
{
	if((r+1)%N==f)
	//if((f==r+1) && (f==0 && r==N-1))
	{
		printf("full\n");
	}
	else if(f==-1 && r==-1)
	{
		f=0;r=0;
		q[f]=x;
	}
	else if(f==0)
	{
		f=N-1;
		q[f]=x;
	}
	else
	{
		f--;
		q[f]=x;
	}
}
void deletefront()
{
	int i;
	if(f==-1 && r==-1)
	{
		printf("empty\n");
	}
	else if(f==r)
	{
		printf("deleted element %d\n",q[f]);
		f=-1,r=-1;
	}
	else if(f==0)
	{
		f=N-1;
		printf("deleted element %d\n",q[f]);
		f=-1;
	}
	else
	{
		printf("deleted element %d\n",q[f]);
		f=(f+1)%N;
	}
}
void deleterear()
{
	if(f==-1 && r==-1)
	{
		printf("empty\n");
	}
	else if(f==r)
	{
		printf("deleted element %d\n",q[r]);
		r=-1;f=-1;
	}
	else if(r==N-1)
	{
		r=0;
		printf("deleted element %d\n",q[r]);
	}
	else
	{
		printf("deleted element %d\n",q[r]);
		r--;
	}
}
void display()
{
	int i=f;
	if(r==-1 && f==-1)
	{
		printf("empty\n");
	}
	else
	{
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
		printf("enter\n1:insertfront\n2:deleterear\n3:display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter data\n");
				scanf("%d",&x);
				insertfront(x);
				break;
			case 2:deletefront();
				break;
			case 3:display();
				break;
			default:printf("invalid\n");
		}
	}while(ch!=0);
}