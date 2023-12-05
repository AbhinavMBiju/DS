#include <stdio.h>
void read(int a[],int n);
void swap(int* a, int* b);
int partition(int a[],int start,int end);
void qSort(int a[],int start,int end);
void print(int a[],int b);
void main()
{
	int a[20],n,start=0;
	printf("Enter number of elements:");
	scanf("%d",&n);
	int end=n-1;
	read(a,n);
	qSort(a,start,end);
	print(a,n);
}

void read(int a[],int n)
{
	int i;
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}		
		
void qSort(int a[], int start, int end)
{
	int pos;
	if (start<end) 
	{
		pos=partition(a,start,end);
		qSort(a, start, pos-1);
		qSort(a, pos+1, end);
	}
}		

int partition(int a[],int start,int end)
{
	int key,i,j;
	key=a[start];
	i=start+1;
	j=end;
	do
	{
		while(i<j && a[i]<key)
			i++;	
		while(j>start && a[j]>key)
			j--; 
		if(i<j) 
			swap(&a[i],&a[j]);	
	}
	while(i<j);
	swap(&a[start],&a[j]);
	return j;	
	
}

void swap(int* a, int* b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

void print(int a[],int b)
{
	int i;
	printf("Sorted array is \n");
	for (i=0;i<b;i++)
	{
		printf("%d \n",a[i]);
	}
}			







