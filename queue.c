#include <stdio.h>
#include <stdlib.h>
#define size 5
int q[size];
int f=-1;
int r=-1;
int isempty()
{
	if(f==-1)
		return(1);
	else
		return(0);
}

int isfull()
{
	if(f==(r+1)%size)
		return(1);
	else
		return(0);
}

void insertq(int item)
{
	if(isempty())
	{
		f=0;
		r=0;
		q[r]=item;
	}
	else
	{
		r=(r+1)%size;
		q[r]=item;
	}
}

int deleteq()
{
	int item;
	item=q[f];
	if(f==r)
	{
		f=-1;
		r=-1;
	}
	else
	{
		f=(f+1)%size;
	}
	return(item);		 				
	
}

void display()
{
	int i,s;
	s=(f<=r)?r:(r+size);
	for(i=f;i<=s;i++)
	{
		printf("%d \t",q[i%size]);
	}
}

void main()
{
	int c,item,v;
	do
	{
		printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit \n");
		printf("Enter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				if(isfull())
				{
					printf("Queue is full");
				}
				else
				{
					printf("Enter the element to insert:");
					scanf("%d",&v);
					insertq(v);
				}
				break;
			case 2:
				if(isempty())
				{
					printf("Queue is empty");
				}
				else
				{
					int d=deleteq();
					printf("Deleted item is %d",d);
				}
				break;
			case 3:
				if(isempty())
				{
					printf("Queue is empty");
				}
				else
				{
					display();
				}
				break;
			case 4:
				exit(0);
			default: printf("Invalid choice");
		}
	}while(c!=4);
}

					
				
				

							
				
