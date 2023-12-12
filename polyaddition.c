#include<stdio.h>
#include<malloc.h>
struct Node
{
	int cons;
	int exp;
	struct Node*next;
};
typedef struct Node node;
node *newnode()
{
	return(node *)malloc(sizeof(node));
}
node *Readpoly();
node *addpoly(node *A,node *B);
void displayPoly(node *poly);
node *newnode();
node *Readpoly()
{
	int c,e,choice;
	node *head,*curr;
	head=newnode();
	curr=head;
	do{
		printf("Enter constant and exponents:");
		scanf("%d%d",&c,&e);
		curr->cons=c;
		curr->exp=e;
		printf("Do you have more terms: 1-Yes 0-No");
		scanf("%d",&choice);
		if(choice)
		{
			curr->next=newnode();
			curr=curr->next;
		}
	} while(choice==1);
	curr->next=NULL;
	return(head);
}
node *addpoly(node *A,node *B)
{
	node *C,*curr;
	C=newnode();
	curr=C;
	while(A!=NULL && B!=NULL)
	{
		if(A->exp==B->exp)
		{
			curr->cons=A->cons+B->cons;
			curr->exp=A->exp;
			A=A->next;
			B=B->next;
		}
		else if(A->exp > B->exp)
		{
			curr->cons=A->cons;
			curr->exp=A->exp;
			A=A->next;
		}
		else
		{
			curr->cons=B->cons;
			curr->exp=B->exp;
			B=B->next;
		}
		if(A!=NULL || B!=NULL)
		{
			curr->next=newnode();
			curr=curr->next;
		}
	}
	while(A != NULL)
	{
		curr->cons=A->cons;
		curr->exp=A->exp;
		A=A->next;
		if(A!=NULL)
		{
			curr->next=newnode();
			curr=curr->next;
		}
	}
	while(B!=NULL)
	{
		curr->cons=B->cons;
		curr->exp=B->exp;
		B=B->next;
		if(B!=NULL)
		{
		curr->next=newnode();
		curr=curr->next;
		}
	}
	return(C);
}
void displayPoly(node *poly)
{
	while (poly != NULL)
	{
		printf("%dx^%d ", poly->cons, poly->exp);
		if (poly->next != NULL)
			printf("+ ");
		poly = poly->next;
	}
	printf("\n");
}
void main()
{
	node *A,*B,*C;
	printf("First polynomial\n");
	A=Readpoly();
	printf("Second polynomial\n");
	B=Readpoly();
	C=addpoly(A,B);
	printf("Polynomial A: ");
	displayPoly(A);
	printf("Polynomial B: ");
	displayPoly(B);
	printf("Resultant Polynomial C (A + B): ");
	displayPoly(C);
}
