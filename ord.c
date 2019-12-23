#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link;
};
typedef struct node NODE;
NODE *start=NULL, *newnode, *ptr;

void insert()
{
	newnode=(NODE*)malloc(sizeof(NODE));
	printf("Enter the Value\n");
	scanf("%d",&newnode->data);
	ptr=start;
	NODE* prev=NULL;
	while(ptr && newnode->data>ptr->data)
	{
		prev=ptr;
		ptr=ptr->link;
	}
	if(!prev)
	{
		newnode->link=start;
		start=newnode;
	}
	else
	{
		newnode->link=prev->link;
		prev->link=newnode;
	}
}

void display(NODE* start)
{
	if(start)
	{
		printf("%d\t",start->data);
		display(start->link);
	}
}

void main()
{
	int ch;
	do
	{
		printf("\n1. Insert\n2. Display\n3. Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: insert();
					break;
			case 2: display(start);
					break;
		}
	}while(ch!=3);
}