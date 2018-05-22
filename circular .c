#include <stdio.h>

struct queue
{
	int que[5];
	int front;
	int rear;
};
typedef struct queue QUEUE;
QUEUE q;
int max=5;

void enqueue();
void dequeue();
void display();
void main()
{
	q.front=-1;
	q.rear=-1;
	int choice;
	while(choice!=4)
	{
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:enqueue();
			break;
			case 2:dequeue();
			break;
			case 3:display();
			break;
			case 4:
			break;

		}
	}
}
	void enqueue()
	{
		int item;
	if(((q.rear+1)%max)==q.front)
	{
		printf("Queue is full\n");
	}
	else
	{
		if(q.front==-1)
			q.front=0;
		q.rear=(q.rear+1)%max;
		printf("Enter the element to be enqueued\n");
		scanf("%d",&item);
		q.que[q.rear]=item;
	}	
	}
		void dequeue()
	{
		int item;
		if(q.front==-1)
		{
			printf("Queue is empty\n");
		}
	if(q.rear==q.front)
	{
		q.rear=q.front=-1;
	}
	else
	{
		
		item=q.que[q.front];
		printf("The element dequeued is %d\n",item);
		q.front=(q.front+1)%max;
	}	
	}

		void display()
	{
		int i;
	if(q.front==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("The Queue is\n");
		
		for(i=q.front;(i%max)!=(q.rear%max);i++)
		{
		printf("%d\n",q.que[(i%max)]);
		}
		printf("%d\n",q.que[(i%max)]);
	}	
	}