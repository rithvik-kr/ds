#include<stdio.h>
#include<stdlib.h>
#define size 5
int q[5], f=-1, r=-1;

void enqueue(int x)
{
	if(f==-1)
	{
		q[++f]=x;
		r++;
	}
	else if(r==size-1)
	{
		printf("Overflow\n");
	}
	else
	{
		printf("F:%d\n",f);
		for(int i=f;i<=r;i++)
		{
			if(x<q[i])
			{
				for(int j=r;j>=i;j--)
					q[j+1]=q[j];
				q[i]=x;
				r++;
				return;
			}
		}
		q[++r]=x;
	}
}

void dequeue()
{
	if(f==-1)
		printf("Underflow\n");
	else
	{
		printf("The Removed Element: %d\n",q[f++]);
	}
}

void display()
{
	for(int i=f;i<=r;i++)
		printf("%d\t",q[i]);
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