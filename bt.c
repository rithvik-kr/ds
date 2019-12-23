#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};
typedef struct node NODE;
NODE *root, *temp;

NODE* maketree()
{
	temp=(NODE*)malloc(sizeof(NODE));
	printf("Enter the Value\n");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int lchild(NODE* root)
{
	int ch;
	printf("Do you want to create left child of %d\n1 for YES 2 for NO\n", root->data);
	scanf("%d",&ch);
	if(ch==1)
		return 1;
	else
		return 0;
}

int rchild(NODE* root)
{
	int ch;
	printf("Do you want to create right child of %d\n1 for YES 2 for NO\n", root->data);
	scanf("%d",&ch);
	if(ch==1)
		return 1;
	else
		return 0;
}

void create(NODE* root)
{
	if(lchild(root))
	{
		root->left=maketree();
		create(root->left);
	}
	if(rchild(root))
	{
		root->right=maketree();
		create(root->right);
	}
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
	printf("Create the root node\n");
	root=maketree();
	create(root);
	printf("The inorder traversal is \n");
	display(root);
}
