#include <stdio.h>
#include <stdlib.h>
#define N 5
int q[N];
int front = -1;
int rear = -1;
void en_front(int x)
{
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) // queue full condition
    {
        printf("Stack overflow\n");
    }
    else if (front == -1 && rear == -1) // queue empty condition
    {
        front = rear = 0; // Initializing f and r to 0
        q[front] = x;
    }
    else if (front == 0) // If an element already exists at zeroth index
    {
        front = N - 1; // Initialising front to last element
        q[front] = x;
    }
    else
    {
        front--;  // Decrementing front before inserting elements
        q[front] = x;
    }
}
void en_rear(int x)
{
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) // queue full condition
    {
        printf("queue overflow\n");
    }
    else if (front == -1 && rear == -1) // queue empty condition
    {
        front = rear = 0; // initializing front and rear to 0 
        q[rear] = x;
    }
    else if (rear == N - 1) // If rear is already pointing to last element
    {
        rear = 0; // Initialize it to zeroth index
        q[rear] = x;
    }
    else
    {
        rear++;
        q[rear] = x;
    }
}
void de_front()
{
    if ((front == -1 && rear == -1)) // queue empty condition
    {
        printf("queue underflow\n");
    }
    else if (front == rear) // if queue contains only one element
    {
        printf("the deleted element : %d\n", q[front]);
        front = rear = -1; // initializing front and rear to -1 after deleting element
    }
    else if (front == N - 1) // if front poniting to last index
    {
        printf("deleted element is: %d\n", q[front]);
        front = 0; // initilizing to first index
    }
    else
    {
        printf("deleted element : %d\n", q[front]);
        front++; 
    }
}
void deleterear()
{
	if(front==-1 && rear==-1)
	{
		printf("empty\n");
	}
	else if(front==rear)
	{
		printf("deleted element %d\n",q[rear]);
		rear=-1;front=-1;
	}
	else if(rear==N-1)
	{
		rear=0;
		printf("deleted element %d\n",q[rear]);
	}
	else
	{
		printf("deleted element %d\n",q[rear]);
		rear--;
	}
}


void display()
{

    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack contains: ");
        while (i != rear) //  continuing loop till front is not equal to rear
        {
            printf("%d ", q[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", q[rear]);
    }
}

int main()
{
    int ch,x;
    printf("\nStack implementation\n");
    do
    {
    printf("1:push\n2:pop\n3:dislpay\n");
    printf("Enter the choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
         case 1:
                printf("enter the element to push: ");
                scanf("%d", &x);
                en_front(x);
                break;
        case 2:
                de_front();
                break;
        case 3:
                display();
                break;
        default:
                printf("Invalid choice try again \n");
                break;            
 
    }
    }while(ch!=0);          
               
}