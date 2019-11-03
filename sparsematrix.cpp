#include<stdio.h>
#include <stdlib.h>
#define M 20
void printsparse(int[][3]);
void readsparse(int[][3]);
void transpose(int[][3],int[][3]);
void Fast_transpose(int B1[M][3],int B2[M][3]);
void addsparse(int b1[M][3],int b2[M][3],int b3[M][3]);
int main()
{
	int b1[M][3],b2[M][3],m,n,b3[M][3],op;
	do
	  {
	    printf("\n1)Read the First Sparse Matrix");
	    printf("\n2)Read the second sparse matrix");
	    printf("\n3)Display the first matrix");
	    printf("\n4)Display the second matrix");
	    printf("\n5)Addition of two matrices");
	    printf("\n6)Simple transpose of the first matrix");
	    printf("\n7)Fast transpose of the first matrix");
	    printf("\n8)Quit");
	    printf("\nEnter your choice : ");
	    scanf("%d",&op);
	    switch(op)
	     {
		case 1: readsparse(b1);
                                         break;
		case 2: readsparse(b2);
                                         break;
		case 3: printsparse(b1);
                                         break;
		case 4: printsparse(b2);
                                         break;
		case 5: addsparse(b1,b2,b3);
                                         printsparse(b3);
                                         break;
		case 6: transpose(b1,b3);
                                         printsparse(b3);
                                         break;
		case 7: Fast_transpose(b1,b3);
                                         printsparse(b3);
                                         break;
                             case 8: 
exit(0);
                            default : printf("Invalid Choice");
                                           break; 
	     }
	 }while(op!=8);
}
void readsparse(int b[M][3])
{
	int i,t,m,n;
	printf("\n Enter the size of matrix (rows,columns)");
	scanf("%d%d",&m,&n);
	b[0][0]=m;
	b[0][1]=n;
	printf("\nEnter no. of non-zero elements:");
	scanf("%d",&t);
	b[0][2]=t;
	for(i=1;i<=t;i++)
	{
		printf("\n Enter the next triple(row,column,value) :");
		scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
	}
}
void printsparse(int b[M][3])
{
	int i,n;
	n=b[0][2];   //no of 3-triples
	printf("\nrows = %d\tcolumns = %d\tNon Zero Elements=%d",b[0][0],b[0][1],b[0][2]);
	printf("\n");
	for(i=1;i<=n;i++)
		printf("%d\t%d\t%d\n",b[i][0],b[i][1],b[i][2]);
}
void transpose(int b1[][3],int b2[][3])
{
	int i,j,k,n;
	b2[0][0]=b1[0][1];
	b2[0][1]=b1[0][0];
	b2[0][2]=b1[0][2];
	k=1;
	n=b1[0][2];
	for(i=0;i<b1[0][1];i++)
		for(j=1;j<=n;j++)
		if(i== b1[j][1])
		{
			b2[k][0]=i;
			b2[k][1]=b1[j][0];
			b2[k][2]=b1[j][2];
			k++;
		}
}

void Fast_transpose(int B1[M][3],int B2[M][3])
{
	int m,n,t,i,col_num,loc;
	int total[M],index[M];
	m=B1[0][0];n=B1[0][1];t=B1[0][2];
	B2[0][0]=n;B2[0][1]=m;B2[0][2]=t;
	for(i=0;i<n;i++)
		total[i]=0;
	for(i=1;i<=t;i++)
	{
		col_num=B1[i][1];
		total[col_num]++;
	}
	index[0]=1;
	for(i=1;i<n;i++)
		index[i]=index[i-1]+total[i-1];

	for(i=1;i<=t;i++)
	{
		col_num=B1[i][1];
		loc=index[col_num];
		index[col_num]++;
		B2[loc][0]=B1[i][1];
		B2[loc][1]=B1[i][0];
		B2[loc][2]=B1[i][2];
	}
}

void addsparse(int b1[M][3],int b2[M][3],int b3[M][3])
{
	int t1,t2,i,j,k;
	t1=b1[0][2];
	t2=b2[0][2];
	i=j=k=0;
	b3[0][0]=b1[0][0];
	b3[0][1]=b1[0][1];
	while(i<=t1 && j<=t2)
	{
		if(b1[i][0] < b2[j][0])
		{
			b3[k][0]=b1[i][0];
			b3[k][1]=b1[i][1];
			b3[k][2]=b1[i][2];
			k++;
			i++;
			continue;
		}
		if(b2[j][0] < b1[i][0])
		{
			b3[k][0]=b2[j][0];
			b3[k][1]=b2[j][1];
			b3[k][2]=b2[j][2];
			k++;
			j++;
			continue;
		}
		if(b1[i][1] < b2[j][1])
		{
			b3[k][0]=b1[i][0];
			b3[k][1]=b1[i][1];
			b3[k][2]=b1[i][2];
			k++;
			i++;
			continue;
		}
		if(b2[j][1] < b1[i][1])
		{
			b3[k][0]=b2[j][0];
			b3[k][1]=b2[j][1];
			b3[k][2]=b2[j][2];
			k++;
			j++;
			continue; 
		}
		b3[k][0]=b1[i][0];
		b3[k][1]=b1[i][1];
		b3[k][2]=b1[i][2]+b2[j][2];
		k++;
		i++;
		j++;

     }
		while(i<=t1)
		{
			b3[k][0]=b1[i][0];
			b3[k][1]=b1[i][1];
			b3[k][2]=b1[i][2];
			i++;
			k++;
		}
		while(j<=t2)
		{
			b3[k][0]=b2[j][0];
			b3[k][1]=b1[j][1];
			b3[k][2]=b1[j][2];
			j++;
			k++;
		}
		b3[0][2]=k-1;
  }
