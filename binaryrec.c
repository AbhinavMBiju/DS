#include<stdio.h>
int binaryrec(int a[],int top,int bot,int key);
void main()
{
	int a[20],i,n,top,bot,key,b;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements in ascending order:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the number to be searched :");
	scanf("%d",&key);
	top=0;
	bot=n-1;
	b=binaryrec(a,top,bot,key);
	if(b==-1)
		printf("The number is not present");
	else
		printf("The number is found at %d index",b);	
}

int binaryrec(int a[],int top,int bot,int key)
{
	int mid;
	if(top<=bot)
	{
		mid=(top+bot)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
			binaryrec(a,top,mid-1,key);
		else
			binaryrec(a,mid+1,bot,key);
	}
	return (-1);	
}	
