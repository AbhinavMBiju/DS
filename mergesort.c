#include <stdio.h>
void read(int a[],int n);
void merge(int a[], int start, int end);
void mergearray(int a[],int first,int part,int end);
void display(int a[],int n);
void main()
{
	int n;
	printf("Enter number of elements:");
	scanf("%d",&n);
	int a[n];
	read(a,n);
	merge(a,0,n-1);
	display(a,n);
}
					
void read(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter the element %d:",i+1);
		scanf("%d",&a[i]);
	}
}
			
void merge(int a[], int start, int end)
{
	int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		merge(a,start,mid);
		merge(a,mid+1,end);
		mergearray(a,start,mid,end);
	}
}


void mergearray(int a[],int start,int part,int end)
{
	int i, j, k;
	int temp[100];
	k=0;
	
	for(i=start,j=part+1,k=start;i<=part&&j<=end;k++)
	{
		if(a[i]<=a[j])
			temp[k]=a[i++];
		else
			temp[k]=a[j++];
	}			
	while(i<=part)
		temp[k++]=a[i++];
	while(j<=end)
		temp[k++]=a[j++];	
	for(i=start;i<=end;i++)
		a[i]=temp[i];	
}
 
void display(int a[],int n)
{
	int i;
	printf("Sorted array is \n");
	for (i=0;i<n;i++)
	{
		printf("%d \n",a[i]);
	}
}
		
