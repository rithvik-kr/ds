#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link;
};
typedef struct node NODE;
NODE *start=NULL, *newnode, *ptr;

NODE* getnode()
{
	int x;
	printf("Enter the Value to be Inserted:\n");
	scanf("%d",&x);
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->data=x;
	newnode->link=NULL;
	return newnode;
}

void insert_beg()
{
	newnode=getnode();
	newnode->link=start;
	start=newnode;
	printf("NODE INSERTED\n");
}

void insert_end()
{
	newnode=getnode();
	if(!start)
	{
		start=newnode;
	}
	else
	{
		ptr=start;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=newnode;
	}
	printf("NODE INSERTED\n");
}

void insert_pos()
{
	int pos, count=0;
	printf("Enter the Position\n");
	scanf("%d",&pos);
	ptr=start;
	while(ptr)
	{
		ptr=ptr->link;
		count++;
	}
	if((pos>count && pos!=1) || pos<0)
	{
		printf("Position Out Of Range");
		return;
	}
	newnode=getnode();
	if(pos==1)
	{
		newnode->link=start;
		start=newnode;
	}
	else
	{
		ptr=start;
		for(int i=1;i<pos-1;i++)
		{
			ptr=ptr->link;
		}
		newnode->link=ptr->link;
		ptr->link=newnode;
	}
	printf("NODE INSERTED\n");
}

void delete_beg()
{
	if(!start)
	{
		printf("List Empty\n");
		return;
	}
	if(start->link==NULL)
	{
		free(start);
		start=NULL;
	}
	else
	{
		ptr=start;
		start=start->link;
		free(ptr);
	}
}

void delete_end()
{
	if(!start)
	{
		printf("List Empty\n");
		return;
	}
	if(start->link==NULL)
	{
		free(start);
		start=NULL;
	}
	else
	{
		NODE* prev;
		ptr=start;
		while(ptr->link!=NULL)
		{
			prev=ptr;
			ptr=ptr->link;
		}
		free(ptr);
		prev->link=NULL;
	}
}

void delete_pos()
{
	int pos, count=0;
	printf("Enter the Position\n");
	scanf("%d",&pos);
	ptr=start;
	while(ptr)
	{
		ptr=ptr->link;
		count++;
	}
	if(pos>count || pos<0)
	{
		printf("Position Out Of Range\n");
		return;
	}
	if(pos==1)
	{
		if(start->link==NULL)
		{
			free(start);
			start=NULL;
		}
		else
		{
			ptr=start;
			start=start->link;
			free(start);
		}
	}
	else
	{
		ptr=start;
		NODE* prev;
		for(int i=1;i<pos;i++)
		{
			prev=ptr;
			ptr=ptr->link;
		}
		prev->link=ptr->link;
		free(ptr);
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

void reverse()
{
	NODE *prev=NULL, *next=NULL;
	ptr=start;
	while(ptr)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
}

int main()
{
	int ch;
	printf("\nOperations on singly ->linked list");
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
			case 7: display(start); break;
			//case 8: search(); break;
			case 9: reverse(); break;
			//case 10:palindrome(); break;
			case 11: exit(0);
			default: printf("\n Invalid Choice"); break;
		}
        fflush(stdin);
	}return 0;
}