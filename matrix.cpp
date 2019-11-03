#include<stdio.h>
#include<stdlib.h>
int create(int a[10][10],int m,int n);
void add(int  a[10][10],int b[10][10],int c[10][10],int m1,int n1);
void mul(int  a[10][10],int b[10][10],int c[10][10],int m1,int n1);
void transpose(int a[10][10],int c[10][10],int m1,int n1);
int saddle(int a[][10],int m,int n);
int main()
{
	int a[10][10],b[10][10],c[10][10],m1,n1,m2,n2,ch;
	do
	{
		printf("\n\t********MENU********");
		printf("\n\t1.ADDITION");
		printf("\n\t2.MULTIPLICATION");
		printf("\n\t3.TRANSPOSE");
		printf("\n\t4.SADDLE POINT");
		printf("\n\t5.QUIT");

		printf("\n\n\tEnter your choice:");
		scanf("%d",&ch);
	
	
	switch(ch)
	{
		case 1:
			printf("\nEnter the size of first the Matrix:");
			scanf("%d%d",&m1,&n1);
			create(a,m1,n1);
			printf("\nEnter the size of seocnd the Matrix:");
			scanf("%d%d",&m2,&n2);
			create(b,m1,n1);
			if(m1==m2 & n1==n2)
				add(a,b,c,m1,n1);
			else
				printf("Can not Add");
			break;

		case 2:
			printf("\nEnter the size of first the Matrix:");
			scanf("%d%d",&m1,&n1);
			create(a,m1,n1);
			printf("\nEnter the size of seocnd the Matrix:");
			scanf("%d%d",&m2,&n2);
			create(b,m1,n1);
			if(n1==m2)
				mul(a,b,c,m1,n1);
			else
				printf("Can not Multiply");
			break;
		case 3:
			printf("\nEnter the size of the Matrix:");
			scanf("%d%d",&m1,&n1);
			create(a,m1,n1);
			if(m1==n1)
				transpose(a,c,m1,n1);
			else
				   printf("Not a square matrix :");
			break;
			
		case 4:   
				printf(" Enter the size of the 1st matrix:");
		   	 	scanf("%d%d",&m1,&n1);
		   	 	create(a,m1,n1);
		   		saddle(a,m1,n1);
		    		break;
		
		case 5:exit(0);
		default:
			printf("\n!! Invalid Choice !!");
			break;
	}}while(ch!=5);
return 0;
}
int create(int a[10][10],int m,int n)
{
	int i,j;
	printf("\nEnter your data");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
}
void add(int  a[10][10],int b[10][10],int c[10][10],int m,int n)
{
	printf("\nAddition of Matrix:\n");
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			{
			c[i][j]=a[i][j]+b[i][j];
			printf("%d\t",c[i][j]);
			}
		printf("\n");
	}
}
void mul(int  a[10][10],int b[10][10],int c[10][10],int m,int n)
{
	printf("\nMultiplication of Matrix:\n");
	int i,j,k=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
			for(k=0;k<m;k++)
			{
				c[i][j]=c[i][j]+a[i][j]*b[i][j];	
			}	
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",c[i][j]);
		}
	printf("\n");
	}
}
void transpose(int a[10][10],int c[10][10],int m,int n)
{
	printf("\nTranspose of Matrix:\n");
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			//c[i][j]=a[j][i];
			printf("%d\t",a[j][i]);
		}
	printf("\n");
	}
}
int  saddle(int a[][10],int m,int n)
{ 
	int i,j,small,large,col_of_small,row_of_large;
    	for(i=0;i<m;i++) 
     { 	
		small=a[i][0];
		col_of_small=0;
		for(j=1;j<n;j++)
	  	if(a[i][j] < small)
	    	{
	      	small=a[i][j];
	     	 col_of_small=j;
	    	}
		large= a[0][col_of_small];
		row_of_large=0;
		for(j=1;j<m;j++)
	  	if(a[j][col_of_small]>large)
	    	{ 
			large=a[j][col_of_small];
	      	row_of_large=j;
	    }
	 	if(i==row_of_large)
	   	{
printf("  Saddle point exist at (%d,%d) with value as %d",i,col_of_small,a[i][col_of_small]);
return(1);
	  	}
      }
printf("Saddle point does not exist ");
return(0);
}
