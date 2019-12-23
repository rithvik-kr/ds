#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int coef;
	int pow;
	struct node *link;
};
typedef struct node NODE;
NODE *newnode, *start=NULL, *temp;

void insert()
{
	newnode=(NODE*)malloc(sizeof(NODE));
	printf("Enter the Coefficient\n");
	scanf("%d",&newnode->coef);
	printf("Enter the pow\n");
	scanf("%d",&newnode->pow);
	newnode->link=NULL;
	NODE *ptr=start;
	NODE *prev=NULL;
	while(ptr!=NULL && ptr->pow>newnode->pow)
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

/*void insert()
{
	temp=(NODE*)malloc(sizeof(NODE));
	temp->link=NULL;
	printf("Enter the Coefficient of the Polynomial\n");
	scanf("%d",&temp->coef);
	printf("Enter the pow of the Polynomial\n");
	scanf("%d",&temp->pow);
	NODE* prev = NULL;
	NODE* cur = start;
	while(cur && cur -> pow > temp -> pow){
		prev = cur;
		cur = cur -> link;
	}
	if(!prev){
		temp -> link = start;
		start = temp;
	}
	else {
		prev -> link = temp;
		temp -> link = cur;
	}
}*/

void display(NODE* start)
{
	if(start)
	{
		printf("%dx^%d\t",start->coef,start->pow);
		display(start->link);
	}
}

void evaluate()
{
	int x, result=0;
	printf("Enter the Value of X\n");
	scanf("%d",&x);
	NODE *ptr=start;
	while(ptr)
	{
		result= result + (ptr->coef*pow(x,ptr->pow));
		ptr=ptr->link;
	}
	printf("The Result is: %d",result);
}

void main()
{
	int ch;
	do
	{
		printf(" 1. Insert\n 2. Display\n 3. Evaluate\n 4. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
					insert();
					break;
			case 2: 
					display(start);
					break;
			case 3:
					evaluate();
					break;
		}
	}while(ch!=4);
}