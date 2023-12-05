#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int info;
	struct Node*next;
};
typedef struct Node node;
node*head=NULL;
node*newnode()
{
	node*p;
	p=(node*)malloc(sizeof(node));
	return(p);
}

void insertfirst(int val)
{
	node*p;
	p=newnode();
	p->info=val;
	p->next=head;
	head=p;
}

void insertafter(int item,int val)
{
	node*curr=head;
	while(curr!=NULL&&curr->info!=item)
		curr=curr->next;
	if(curr==NULL)
		printf("No such nodes");
	else
	{
		node*p=newnode();
		p->info=val;
		p->next=curr->next;
		curr->next=p;
	}	
}

void insertbefore(int item,int val)
{
	node*curr=head,*prev=NULL;
	while(curr!=NULL&&curr->info!=item)
	{
		prev=curr;
		curr=curr->next;
	}
	if(curr==NULL)
		printf("No such node");
	else
	{
		node*p=newnode();
		p->info=val;
		p->next=curr;
	if(prev==NULL)
		head=p;
	else
		prev->next=p;
	}	
}

void deletenode(int item)
{
	node*curr=head,*prev=NULL;
	while(curr!=NULL&&curr->info!=item)
	{
		prev=curr;
		curr=curr->next;
	}
	if(curr==NULL)
		printf("No such nodes");
	else
	{
		if(prev!=NULL)
			prev->next=curr->next;
		else
			head=curr->next;
		free(curr);
	}
}	
												
void display()
{
	node *curr;
	curr=head;
	while(curr!=NULL)
	{
		printf("%d\t",curr->info);
		curr=curr->next;
	}
}

void main()
{
	int c,in,ip;
	printf("1.Insert A Node\n2.Insert after an item\n3.Insert before an item\n4.Delete an item\n5.Display\n6.Exit\n");
	do
	{
		printf("\nEnter choice:\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter an element to add:");
				scanf("%d",&in);
				insertfirst(in);
				break;
			case 2:
				printf("Enter an element to add:");
				scanf("%d",&in);
				printf("Enter the element after which it needs to be added:");
				scanf("%d",&ip);
				insertafter(ip,in);
				break;
			case 3:
				printf("Enter an element to add:");
				scanf("%d",&in);
				printf("Enter the element before which it needs to be added:");
				scanf("%d",&ip);
				insertbefore(ip,in);
				break;
			case 4:
				printf("Enter the element to be deleted:");
				scanf("%d",&ip);
				deletenode(ip);
				break;
			case 5:
				display();
				break;
			case 6:
				printf("Exiting Program");
				break;
			default:printf("Invalid input");	
		}
	}while(c!=6);
}							
		
		
