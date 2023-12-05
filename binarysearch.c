#include <stdio.h>
int binary(int a[],int n,int key);
void main()
{
	int a[20],n,key,i,b,large,j,x;
	printf("Enter number of elements in the array:");
	scanf("%d",&n);
	printf("Enter the elements in ascending order:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the number to be searched :");
	scanf("%d",&key);
	b=binary(a,n,key);
	if(b==-1)
		printf("The number is not present");
	else
		printf("The number is found at %d index",b);		
}

int binary(int a[],int n,int key)
{
	int top,mid,bot;
	top=0,bot=n-1;
	while(top<=bot)
	{
		mid=(top+bot)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
			bot=mid-1;
		else
			top=mid+1;
	}
	return (-1);					
}
