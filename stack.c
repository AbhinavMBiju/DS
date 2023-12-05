#include <stdio.h>
#define size 10
int s[size],top=0;
int isfull()
{
	if(top>=size)
		return(1);
	else
		return(0);
}
	
int isempty()
{
	if(top==0)
		return(1);
	else
		return(0);
}
	
void push(int value)
{
	if(isfull())
		printf("\n Stack is full");
	else
		s[top++]=value;
}
	
int pop()
{
	if(isempty())
		printf("Stack is empty");
	else
	{
		
		return(s[--top]);
	}
}
	
int peek()
{
	if(isempty())
		printf("Empty");
	else
		return(s[top-1]);
}
	
void display()
{
	int i=top-1;
   	for(i;i>=0;i--)
		printf("%d \t",s[i]);
}
	
void main()
{
	int c,v;
	do
	{
		printf("\n 1.push \n 2.pop \n 3.peek \n 4.display \n 5.exit \n");
		printf("Enter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				if(isfull())
					printf("Stack is full");
				else
				{
					printf("Enter the value:");
					scanf("%d",&v);
					push(v);
				}
				break;
			case 2:
				if(isempty())
					printf("Stack is empty");
				else
					printf("The value is %d",pop());
				break;	
			case 3:
				if(isempty())
					printf("Empty");
				else	
					printf("The item at the top is %d",peek());
				break;	
			case 4:
				display();
				break;
			case 5:
				return 0;
				break;
			default: printf("Wrong input");
		}					
	}while(c!=5);
		
	
}
							
