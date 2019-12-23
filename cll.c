#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};
typedef struct node NODE;
NODE *last=NULL, *newnode, *ptr;

NODE* getnode()
{
	newnode=(NODE*)malloc(sizeof(NODE));
	printf("Enter the Value: ");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	return newnode;
}

void insert_beg()
{
	newnode=getnode();
	if(!last)
	{
		last=newnode;
		last->link=newnode;
	}
	else
	{
		newnode->link=last->link;
		last->link=newnode;
	}
}

void insert_end()
{
	newnode=getnode();
	if(!last)
	{
		last=newnode;
		last->link=newnode;
	}
	else
	{
		newnode->link=last->link;
		last->link=newnode;
		last=newnode;
	}
}

void insert_pos()
{
	int pos, count=0;
	printf("Enter the Position\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		newnode=getnode();
		if(!last)
			last=newnode;
		newnode->link=last->link;
		last->link=newnode;
		return;
	}
	else if(pos>1 && last==NULL)
	{
		printf("Out Of Range\n");
		return;
	}
	ptr=last->link;
	while(ptr!=last)
	{
		ptr=ptr->link;
		count++;
	}
	count++;
	printf("Count: %d \n",count);
	if(pos>1 && pos<=count)
	{
		newnode=getnode();
		ptr=last->link;
		for(int i=1;i<pos-1;i++)
			ptr=ptr->link;
		newnode->link=ptr->link;
		ptr->link=newnode;
	}
	else if(pos==count+1)
	{
		newnode=getnode();
		newnode->link=last->link;
		last->link=newnode;
		last=newnode;
	}
	else
		printf("Position Out Of Range\n");
}

void display()
{
	if(last==NULL)
		printf("List Empty\n");
	else
	{
		for(ptr=last->link;ptr!=last;ptr=ptr->link)
			printf("%d\t",ptr->data);
		printf("%d",last->data);
	}
}

void delete_beg()
{
	if(last)
	{
		if(last->link==last)
		{
			free(last);
			last=NULL;
			return;
		}
		ptr=last->link;
		last->link=ptr->link;
		free(ptr);
	}
	else
	{
		printf("List Empty\n");
	}
}

void delete_end()
{
	if(last)
	{
		if(last->link==last)
		{
			free(last);
			last=NULL;
			return;
		}
		ptr=last->link;
		while(ptr->link!=last)
			ptr=ptr->link;
		ptr->link=last->link;
		free(last);
		last=ptr;
	}
	else
		printf("List Empty\n");
}

void delete_pos()
{
	int pos, count=0;
	if(!last)
	{
		printf("List Empty\n");
		return;
	}
	printf("Enter the Position : ");
	scanf("%d",&pos);
	ptr=last->link;
	while(ptr!=last)
	{
		ptr=ptr->link;
		count++;
	}
	count++;
	if(pos==1)
	{
		if(last->link==last)
		{
			free(last);
			last=NULL;
			return;
		}
		ptr=last->link;
		last->link=ptr->link;
		free(ptr);
		return;
	}
	if(pos>1 && pos<=count)
	{
		ptr=last->link;
		NODE* prev=NULL;
		for(int i=1;i<pos;i++)
		{
			prev=ptr;
			ptr=ptr->link;
		}
		prev->link=ptr->link;
		free(ptr);
		if(pos==count)
			last=prev;
	}
}

int main()
{
	int ch;
	printf("\nOperations on circular ->linked list");
	printf("\n1: Insert at Beginning");
	printf("\n2: Insert at End");
	printf("\n3: Insert at Given Position");
	printf("\n4: Delete first node");
	printf("\n5: Delete Last node");
	printf("\n6: Delete node given its position");
	printf("\n7: Display the list");
	printf("\n8: To search for an element");
	printf("\n9: Reverse");
	printf("\n10: Palindrome");
	printf("\n11: Exit");
	
	while(1)
	{
		printf("\n\n\nEnter the choice\n");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: insert_beg(); break;
			case 2: insert_end(); break;
			case 3: insert_pos(); break;
			case 4: delete_beg(); break;
			case 5: delete_end(); break;
			case 6: delete_pos(); break;
			case 7: display(); break;
			//case 8: search(); break;
			//case 9: reversal(); break;
			//case 10:palindrome(); break;
			case 11: exit(0);
			default: printf("\n Invalid Choice"); break;
		}
        fflush(stdin);
	}return 0;
}