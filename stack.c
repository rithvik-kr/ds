#include<stdio.h>
#include<stdlib.h>
#define size 3
int stack[3], tos=-1;

void push()
{
	if(tos>=size-1)
		printf("Overflow\n");
	else 
	{
		printf("Enter the Value: ");
		scanf("%d",&stack[++tos]);
	}
}

void pop()
{
	if(tos==-1)
	{
		printf("Underflow\n");
	}
	else
	{
		printf("The Popped Element: %d\n",stack[tos--]);
	}
}

void display()
{
	if(tos==-1)
	{
		printf("Underflow\n");
	}
	else
	{
		for(int i=tos;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}

void main()
{
	int ch;
	printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
	while(1)
	{
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push(); break;
			case 2: pop(); break;
			case 3: display(); break;
			case 4: exit(0);
			default: printf("Invalid Choice\n");
		}
	}
}