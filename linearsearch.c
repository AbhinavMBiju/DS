#include <stdio.h>
int linearsearch(int a[],int n,int key);
void main()
{
	int a[20],n,i,key,b;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the number to be searched:");
	scanf("%d",&key);
	b=linearsearch(a,n,key);
	if(b==-1)
		printf("The number is not present");
	else
		printf("The number is present at %d index",b);
}


int linearsearch(int a[],int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
			return i;
	}
	return (-1);
}			
