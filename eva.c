#include<stdio.h>
#include<math.h>
int stack[20];
int top =-1;

void push(int x)
{
	stack[++top]=x;
}

int pop()
{
	return stack[top--];
}

void main()
{
	char exp[20];
	char *e, x;
	int n1,n2,n3,num;
	printf("Enter the Expression :: ");
	scanf("%s",exp);
	e=exp;
	while(*e !='\0')
	{
		if(isdigit(*e))
		{
			num=*e-'0';
			push(num);
		}
		else
		{
			n1=pop();
			n2=pop();
			switch(*e)
			{
				case '+': n3=n2+n1; break;
				case '-': n3=n2-n1; break;
				case '*': n3=n2*n1; break;
				case '/': n3=n2/n1; break;
				case '^': n3=pow(n2,n1); break;
			}
			push(n3);
		}
		e++;
	}
	printf("\nThe Result : %d",pop());
}