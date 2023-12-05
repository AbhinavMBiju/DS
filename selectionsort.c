#include<stdio.h>
void selsort(int a[],int n);
void swap(int *a,int *b);
void main()
{
	int a[50],n,i;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	selsort(a,n);	
}

void selsort(int a[],int n)
{
	int i,lar,x,j,k;
	for(j=0;j<n-1;j++)
	{
		lar=a[0];
		x=0;
		for(i=1;i<n-j;i++)
		{
			if(a[i]>lar)
			{
				lar=a[i];
				x=i;
			}
		}
		swap(&a[x],&a[n-j-1]);
	}
	printf("The sorted array is:");
	for(k=0;k<n;k++)
		printf("%d \t",a[k]);
}

void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}					
			
