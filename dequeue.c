#include<stdio.h>
#define size 10
int q[size];
int f=-1,r=-1;

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

void insertrear(int item)
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

int deletefront()
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
	int i,s=(f<=r)?r:(r+size);
	for(i=f;i<=s;i++)
	{
		printf("%d \t",q[i%size]);
	}
} 

void insertfront(int item)
{
	if(isfull())
		printf("Queue is full");
	else
	{
		 if(f==-1)
		 	r=0,f=0;
		 else if(f==0)
		 	f=size-1;
		 else
		 	f--;	 		
	}
	q[f]=item;
}



int deleterear()
{
	int item=q[r];
	if(isempty())
	{
		printf("Queue is empty");
	}
	else
	{
		if(f==r)
		{
			f=-1;
			r=-1;
		}	
		else if(r==0)
			r=size-1;
		else
			r--;
	}
	return(item);
}

int main()
{
	int c,item,v;
	printf("\n1.Insert front\n2.Delete rear\n3.Insert rear\n4.Delete front\n5.Display\n6.Exit\n");		
	do{
		printf("\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				if(isfull())
					printf("\nQueue is full");
				else
				{
					printf("Enter the element to be inserted:");
					scanf("%d",&v);
					insertfront(v);
				}
				break;
			case 2:
				if(isempty())
					printf("Empty");
				else
					printf("Deleted item is:%d",deleterear());
				break;
			case 3:
				if(isfull())
					printf("\nQueue is full");
				else
				{
					printf("Enter the element to be inserted");
					scanf("%d",&v);
					insertrear(v);
				}
				break;
			case 4:
				if(isempty())
					printf("Empty");
				else
					printf("Deleted item is:%d",deletefront());
				break;
			case 5:
				if(isempty())
					printf("Empty");
				else
					display();
				break;
			case 6:
				return(0);
			default:printf("Wrong choice");
		}
	}while(c!=6);
}								
							
			
