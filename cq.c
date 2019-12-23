#include<stdio.h>
#include<stdlib.h>
#define size 5
int cq[5], f=-1, r=-1, count=0;

void enqueue(int x)
{
	if(count>=size)
	{
		printf("Overflow\n");
		return;
	}
	if(f==-1)
	{
		cq[++f]=x;
		r++;
		count++;
	}
	else
	{
		r=(r+1)%size;
		cq[r]=x;
		count++;
	}
}

void dequeue()
{
	if(count==0)
	{
		printf("Underflow\n");
		return;
	}
	printf("The Deleted Element is: %d\n",cq[f]);
	f=(f+1)%size;
	count--;
}

void display()
{
	if(count==0)
	{
		printf("Underflow\n");
		return;
	}
	int j=f;
	for(int i=0;i<count;i++)
	{
		printf("%d\t",cq[j]);
		j=(j+1)%size;
	}
	printf("\n");
}

void main()
{
	int ch;
	printf("\n1. enqueue\n2. dequeue\n3. Display\n4. Exit\n");
	while(1)
	{
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the Value\n"); int x; scanf("%d",&x); enqueue(x); break;
			case 2: dequeue(); break;
			case 3: display(); break;
			case 4: exit(0);
			default: printf("Invalid Choice\n");
		}
	}
}
	