#include<stdio.h>
void insertion(int a[],int n);
void main()
{
	int a[20],n,i;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements in the array:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	insertion(a,n);	
}

void insertion(int a[],int n)
{
	int i,j,key,k;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	printf("The sorted array is: \n");
	for(k=0;k<n;k++)
		printf("%d \n",a[k]);
}			
