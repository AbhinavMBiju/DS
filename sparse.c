#include<stdio.h>
void sparse(int A[10][10],int r,int c,int S[20][3]);
void addsparse(int S[20][3],int T[20][3],int r,int c);
void printsparse(int S[20][3],int k);

void main()
{
	int i,j,A[10][10],B[10][10],r,c,S[20][3],T[20][3];
	printf("Enter the row and column size:");
	scanf("%d %d",&r,&c);
	printf("Enter the matrix 1:");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	printf("Matrix 1 is:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
	sparse(A,r,c,S);
	printf("Enter the matrix 2:");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
	printf("Matrix 2 is:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",B[i][j]);
		}
		printf("\n");
	}
	sparse(B,r,c,S);
	addsparse(S,T,r,c);
}

void sparse(int A[10][10],int r,int c,int S[20][3])
{
	int i,j,k=1;
	S[0][0]=r;
	S[0][1]=c;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(A[i][j]!=0)
			{
				S[k][0]=i;
				S[k][1]=j;
				S[k][2]=A[i][j];
				k++;
			}
		}
	}
	S[0][2]=k-1;
	printsparse(S,k);
}

void addsparse(int S[20][3],int T[20][3],int r,int c)
{
	int A[20][3],i,j,m=1,n=1,k=1;
	A[0][0]=S[0][0];
	A[0][1]=S[0][1];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(S[m][0]==i && T[n][0]==i && T[n][1]==j)
			{
				A[k][0]=S[m][0];
				A[k][1]=S[m][1];
				A[k][2]=S[m][2]+T[n][2];
				m++;
				n++;
				k++;
			}
			else if(S[m][0]==i && S[m][1]==j)
			{
				A[k][0]=S[m][0];
				A[k][1]=S[m][1];
				A[k][2]=S[m][2];
				m++;
				k++;
			}
			else if(T[n][0]==i && T[n][1]==j)
			{
				A[k][0]=T[n][0];
				A[k][1]=T[n][1];
				A[k][2]=T[n][2];
				n++;
				k++;
			}
		}
	}
	A[0][2]=k-1;
	printf("Sum:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
}

void printsparse(int S[20][3],int k)
{
	int i,j;
	printf("The sparse is:\n");
	for (i=0;i<k;i++)
	{
		for(j=0;j<3l;j++)
		{
			printf("%d\t",S[i][j]);
		}
		printf("\n");
	}
}			
							

				
