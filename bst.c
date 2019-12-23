#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};
typedef struct node NODE;
NODE *root, *newnode;

NODE* maketree(int n)
{
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->data=n;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

void insert()
{
	int n;
	printf("Enter the Value\n");
	scanf("%d",&n);
	newnode=maketree(n);
	NODE *p=root;
	NODE* q=p;
	while(q && newnode->data!=p->data)
	{
		p=q;
		if(newnode->data>p->data)
			q=p->right;
		else
			q=p->left;
	}
	if(newnode->data>p->data)
		p->right=newnode;
	else if(newnode->data<p->data)
		p->left=newnode;
	else
		printf("Duplicate\n");
}

void display(NODE* root)
{
	if(root)
	{
		display(root->left);
		printf("%d\t",root->data);
		display(root->right);
	}
}

void main()
{
	printf("Enter the Value of Root Node\n");
	int n, ch;
	scanf("%d",&n);
	root=maketree(n);
	do
	{
		printf("\n 1. Enter New Value\n 2. Display\n 3. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
					insert();
					break;
			case 2: 
					display(root);
					break;
			default:
					printf("\n Invalid Choice\n");
		}
	}while(ch!=3);
}