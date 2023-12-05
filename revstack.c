#include <stdio.h>
#define size 50
int s[size],top=0;
char push(char);
char pop();
int isfull();
int isempty();
void main()
{
	char c[50];
	int i;
	printf("Enter a word to reverse:");
	gets(c);
	for(i=0;c[i]!='\0';i++)
	{
		push(c[i]);
	}
	while(!isempty())
		printf("%c",pop());	
}
char push(char value)
{
	if(isfull())
		printf("\nStack overflow");
	else
		s[top++]=value;
}
	
char pop()
{
	if(isempty())
		printf("Stack is empty");
	else
		return(s[--top]);	
}

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
			
		
