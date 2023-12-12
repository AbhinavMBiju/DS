#include<stdio.h>
int left(int i)
{
	return(2*i);
}
int right(int i)
{
	return(2*i+1);
}
void swap(int *p,int *q)
{
	int t;
	t=*p;
	*p=*q;
	*q= t;
}
void heapify(int a[],int i, int size)
{
	int lar=i,lc,rc;
	lc=left(i);rc=right(i);
	if(a[lc]>a[lar] && lc<=size)
		lar=lc;
	if(a[rc]>a[lar] && rc<=size)
		lar=rc;
	if(lar!=i)
	{
		swap(&a[lar],&a[i]);heapify(a,lar,size);}
	}  
void buildheap(int a[],int n)
{	
	int i;
  	for(i=n/2;i>=1;i--)
   		heapify(a,i,n);
}
void heapsort(int a[],int n)
{
	int i,size=n;
	buildheap(a,n);
	for(i=1;i<n;i++)
	{
		swap(&a[1],&a[size]);
   		size--;
   		heapify(a,1,size);
   	}
}
void main()
{
	int n,i,a[100];
	printf("\nEnter number of elements:\n");
	scanf("%d",&n);
	printf("Enter  %d elements\n",n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	heapsort(a,n);
	printf("\nSorted elements are:\n");
	for(i=1;i<=n;i++)
		printf(" \n  %d",a[i]);
}
