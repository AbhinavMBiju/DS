#include <stdio.h>
#define size 100
char s[size];
int top=0;
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
	
void push(char value)
{
	if(isfull())
		printf("\n Stack is full");
	else
		s[top++]=value;
}
	
char pop()
{
	if(isempty())
		printf("Stack is empty");
	else
	{
		
		return(s[--top]);
	}
}
	
char peek()
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
		printf("%c",s[i]);
}

int instackp(char c)
{
	switch(c)
	{
		case'+':
		case'-':
			return(2);
			break;
		case'*':
		case'/':
			return(4);
			break;
		case'^':
			return(5);
			break;
		case'(':
			return(0);
		default: return(-1);
	}
}

int inputp(char c)
{
	switch(c)
	{
		case'+':
		case'-':
			return(1);
			break;
		case'*':
		case'/':
			return(3);
			break;
		case'^':
			return(6);
			break;
		default:return(-1);	
	}
}						

int main()
{
	char in[100],post[100],token,c;
	int i=0,j=0;
	printf("Enter an infix expression:");
	scanf("%s",in);
	while(in[i]!='\0')
	{
		token=in[i];
		switch(in[i])
		{
			case'(':
				push(in[i]);
				break;
			case'+':
			case'-':
			case'*':
			case'/':
			case'^':
				while(!isempty()&&instackp(peek())>inputp(token))
				{
					post[j++]=pop();
				}	
				push(token);
				break;
			case')':
				while((c=pop())!='(')
					post[j++]=c;
				break;
			default:post[j++]=token;
		}
		printf("\n Token=%c",token);
		display();
		i++;
	}
	while(!isempty())
		post[j++]=pop();
	post[j]='\0';
	printf("\nPostfix:%s",post);
}
