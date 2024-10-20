#include <stdio.h>
#include<stdlib.h>
#define N 10
int q[N],item,f=0,r=-1;

void pqinsert()
{
    int i;
    if(r==N-1)
    {
        printf("Queue overflow\n");
    }
    i=r;
    while((i>=0)&&(item<q[i]))   
    {
        q[i+1]=q[i];
        i--;
    }
    
    q[i+1]=item;
    r=r+1;
    
}

void pqdelete()
{
    if(f==0 && r==-1)
    {
      printf("Queue underflow\n");
    }
    else if(f==r)
    {
        printf("delted elemt is %d\n",q[f]);
        f=(f+1)%N;
        f=0,r=-1;
    }
    else
    {
        printf("Deleted item is %d\n",q[f]);
        f=(f+1)%N;
    }
}

void display()
{
    int i;
    if(f==0 && r==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Contents of queue\n");
    for(i=f;i<=r;i++)
        printf("%d\t",q[i]);
        printf("\n");
           
}
int main()
{
    int choice;
    for(;;)
    {
    	printf("Enter the choice\n 1:insertion\n 2:deletion\n 3:display\n");
	    scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the element to be inserted\n");
                   scanf("%d",&item);
                   pqinsert(item);
                   break;
            case 2:pqdelete();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
        }
}   
    return 0;
}