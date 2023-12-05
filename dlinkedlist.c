#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int info;
	struct Node*prev;
	struct Node*next;
};
typedef struct Node node;
node*head=NULL;
node*tail=NULL;
node*newnode()
{
	node*p;
	p=(node*)malloc(sizeof(node));
	return(p);
}
void insertfirst(int val)
{
	node*p=newnode();
	p->info=val;
	p->prev=NULL;
	p->next=head;
	if(head==NULL)
		head=tail=p;
	else
		head->prev=p;	
		head=p;
}
void insertlast(int val)
{
	node*p=newnode();
	p->info=val;
	p->prev=tail;
	p->next=NULL;
	if(tail==NULL)
		head=tail=p;
	else
		tail->next=p;
		tail=p;
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
		p->prev=curr;
	if(curr->next==NULL)
		tail=p;
	else
	{
		curr->next->prev=p;
		curr->next=p;
	}
	}
}
void insertbefore(int item,int val)
{
	node*curr=head;
	while(curr!=NULL&&curr->info!=item)
		curr=curr->next;
	if(curr=NULL)
		printf("No such nodes");
	else
	{
		node*p=newnode();
		p->info=val;
		p->prev=curr->prev;
		p->next=curr;
	if(curr->prev==NULL)
		head=p;
	else
	{
		curr->prev->next=p;
		curr->prev=p;
	}
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
		if(curr->prev==NULL)
			head=curr->next;
		else
		{
			curr->prev->next=curr->next;
		if(curr->next==NULL)
			tail=curr->prev;
		else
			curr->next->prev=curr->prev;	
		free(curr);
		}
	}
}
void displayltr()
{
	node *curr=head;
	while(curr!=NULL)
	{
		printf("%d\t",curr->info);
		curr=curr->next;
	}
}
void displayrtl()
{
	node *curr=tail;
	while(curr!=NULL)
	{
		printf("%d\t",curr->info);
		curr=curr->prev;
	}
}	
void main()
{
	int c,in,ip;
	printf("\n1.Insert a Node from first\n2.Insert a Node from last\n3.Insert after an item\n4.Insert before an item\n5.Delete an item\n6.Display from left to right\n7.Display from right to left\n8.Exit\n");
	do
	{
		printf("Enter choice:");
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
				insertlast(in);
				break;
			case 3:
				printf("Enter an element to add:");
				scanf("%d",&in);
				printf("Enter the element after which it needs to be added:");
				scanf("%d",&ip);
				insertafter(ip,in);
				break;
			case 4:
				printf("Enter an element to add:");
				scanf("%d",&in);
				printf("Enter the element before which it needs to be added:");
				scanf("%d",&ip);
				insertbefore(ip,in);
				break;
			case 5:
				printf("Enter the element to be deleted:");
				scanf("%d",&ip);
				deletenode(ip);
				break;
			case 6:
				displayltr();
				break;
			case 7:
				displayrtl();
				break;
			case 8:
				printf("Exiting Program");
				break;
			default:printf("Invalid input");
		}
	}while(c!=8);
}				
