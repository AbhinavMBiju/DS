#include<stdio.h>
void readnum(int x[],int n);
void sortnum(int x[],int n);
void swap(int *a,int *b);
void printnum(int x[],int n);
void main()
{
	int a[20],n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	readnum(a,n);
	sortnum(a,n);
	printnum(a,n);
}

void readnum(int x[],int n)
{
	int i;
	printf("Enter the elements in the array:");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
}

void sortnum(int x[],int n)
{
	int p,c,k;
	for(p=1;p<n;p++)
	{
		k=1;
		for(c=0;c<n-p;c++)
		{
			if(x[c]>x[c+1])
			{
				swap(&x[c],&x[c+1]);
				k=0;
			}
		}
		if(k==1)
			return;						
	}
}

void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

void printnum(int x[],int n)
{
	int i;
	printf("The sorted array is:");
	for(i=0;i<n;i++)
		printf("%d \t",x[i]);
}						
