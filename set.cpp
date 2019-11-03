#include<stdio.h>
#include<stdlib.h>
#define M 40
int Create(int s[]);		                	   
void Set_print(int s[],int x);		                   
int Union(int s1[],int s2[],int s3[],int m,int n);	   
int Intersection(int s1[],int s2[],int s3[],int m,int n);   
int Difference(int s1[],int s2[],int s3[],int m,int n);     
int Symmdiff(int s1[],int s2[],int s3[],int m,int n);	    

int main()
{
  	int s1[M],s2[M],s3[M],m,n,k=0;
  	int ch;
  	do
  	{
		printf("\n *** MENU ***");  
		printf("\n 1.Create");  
		printf("\n 2.Print"); 
		printf("\n 3.Union");
		printf("\n 4.Intersection");   
		printf("\n 5.Difference");   
		printf("\n 6.Symmetric Difference");
		printf("\n 7.Quit");   
		printf("\n\n Enter your choice: ");   
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("\nCreating first Set:");    
					m=Create(s1); 
					printf("\nCreating second Set:");       
					n=Create(s2);
			break;
			case 2: printf("\nFirst set is:\n");	       
					Set_print(s1,m);
					printf("\n\nSecond set is:\n");	       
					Set_print(s2,n);
					printf("\n\nThird set is:\n");	       
					Set_print(s3,k);
			break;
			case 3: printf("Union of sets is:");	       
					k=Union(s1,s2,s3,m,n);	       
					Set_print(s3,k);
			break;
			case 4: printf("Intersection of sets is:");               
					k=Intersection(s1,s2,s3,m,n);	       
					Set_print(s3,k);
			break;
			case 5: printf("Difference of sets is:");               
					k=Difference(s1,s2,s3,m,n);	       
					Set_print(s3,k);
			break;
			case 6: printf("Symm_Diff of sets is:");	       
					k=Symmdiff(s1,s2,s3,m,n);	       
					Set_print(s3,k);
			break;
			case 7:  exit(0);
			default: printf("Invalid choice");
			break;
		}
   	}while(ch!=7);
 }
int Create(int s[])    
{
    int n,i,x;
    printf("\n Enter number of elements:=");    scanf("%d",&n);
    printf("\n Enter %d set elements:=",n);
    for(i=0;i<n;i++)
	 scanf("%d",&s[i]);
    return(n);
}
void Set_print(int s[],int x)      
{
    int i;
    printf("\t\t{ ");
    for(i=0;i<x;i++)
       printf(" %d ",s[i]);
    printf(" }");
}
int Union(int s1[],int s2[],int s3[],int m,int n)       
{
    int i,j,f,k=0;
     for(i=0;i<m+n;i++)
    {
	 	s3[i]=0;
    }
    for(i=0;i<m;i++)
    {
		s3[k]=s1[i];	 
		k++;
    }		
    for(i=0;i<n;i++)
    {
		f=0;
		for(j=0;j<m;j++)
	  	{
	    	if(s2[i]==s1[j])
	       	{
		 		f=1;	 
				break;
	       	}
	   	}
		if(f==0)
	   	{
	    	s3[k]=s2[i];	      
			k++;
	   	}
    }
    return(k);
}
int Intersection(int s1[],int s2[],int s3[],int m,int n)       
{
    int i,j,k=0,f;
	for(i=0;i<m+n;i++)
    s3[i]=0;
    for(i=0;i<m;i++)
   	{          
        f=1;  
		for(j=0;j<n;j++)
  		{
      		if(s1[i]==s2[j])
       		{
	 			f=0;                 
				break;
       		}
  		}
        if(f==0)
        {
        	s3[k]=s1[i];           
			k++;
        }
 	}
	return(k);
}
int Difference(int s1[],int s2[],int s3[],int m,int n)      
{
	int i,j,k=0,f;
	for(i=0;i<m+n;i++)
   	s3[i]=0;
   	for(i=0;i<m;i++)
	{
	    f=0;
	    for(j=0;j<n;j++)
	    {
			if(s1[i]==s2[j])
			{
				f=1;		   
				break;
			}
		}
	    if(f==0)
		{
		  	s3[k]=s1[i];    
			k++;
		}
	}
	return(k);
}
int Symmdiff(int s1[],int s2[],int s3[],int m,int n)              
{
	int i,j,k=0,f;
	for(i=0;i<m+n;i++)
    s3[i]=0;
    for(i=0;i<m;i++)
	{
	    f=0;
	    for(j=0;j<n;j++)
	    {
	       	if(s1[i]==s2[j])
			{
				f=1;	  
				break;
			}
	    }
	    if(f==0)
	    {
	      	s3[k]=s1[i];	      
			k++;
	    }
	}
	for(i=0;i<n;i++)
	{
	    f=0;
	    for(j=0;j<m;j++)
	    {
			if(s2[i]==s1[j])
		 	{
		   		f=1;	   
				break;
		 	}
	    }
	    if(f==0)
	    {
			s3[k]=s2[i];	
			k++;
	    }
	}
	return(k);
}
