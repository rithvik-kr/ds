#include<stdio.h>

int a[10]={1,2,3,4,5,6,7,8,9,10};
int lo=1,hi=10,mid=0;

void bs(int ar[], int l, int h, int item)
{
	if(l>h)
		printf("Item NF\n");
	else
	{
		mid=(l+h)/2;
		if(ar[mid]==item)
			printf("Item found at Position %d\n",mid+1);
		else if(ar[mid]>item)
			bs(ar, l, mid-1, item);
		else
			bs(ar, mid+1, h, item);
	}
}

void main()
{
	for(int i=0;i<10;i++)
		printf("%d\t",a[i]);
	printf("\nEnter the Element to be Searched:\n");
	int item;
	scanf("%d",&item);
	bs(a,0,9,item);
}