#include <math.h>
#include <stdio.h>
#include <string.h>
 #include <stdlib.h>
typedef struct mobile
{ 
   long  mobileno;
   char name[20];
   float  billamt;
}mobile;
void read(mobile  st[],int n);
void print(mobile st[],int n);
int  binsearch(mobile st[],long mobileno,int n);
void insertionsort(mobile a[],int n); //sort in descending order on MobileNo
void selectionsort(mobile a[],int n);
int main()
{ 
    mobile st[30];
    int n,i,ch,pos;
    long mobileno;
  
    do
     {
       
       printf("\n1)create\n2)print");
       printf("\n3)Display the data in descending order of mobileno(insertion sort)");
       printf("\n4)Display the data in ascending order of name(selection sort)");
       printf("\n5)Display details for mobileno specified by user(binary search)");
       printf("\n6)Quit");
       printf("\nEnter Your Choice:");
       scanf("%d",&ch);
       switch(ch)
	{ 
                case 1: printf("\nEnter No. of Users :");
	             scanf("%d",&n);
	             read(st,n);
	             break;

                case 2: print(st,n);
                            break;

                case 3: insertionsort(st,n); 
                            print(st,n);
                            break;

	 case 4: selectionsort(st,n);
                            print(st,n); 
                            break;

	 case 5: printf("\nPlease ensure that data is sorted using option no.3");
	             printf("\nEnter Mobile number : ");
	             scanf("%ld",&mobileno);
		  pos=binsearch(st,mobileno,n);
		  if(pos==-1)
		    printf("\nNot found");
		  else
		   {
             printf("\n Found at location=%d",pos+1);
		     printf("\n %s\t%ld\t%6.2f",st[pos].name,st[pos].mobileno,st[pos].billamt);
		   }
		 break;
            
        case 6: 
                       exit(0);
                              break;
    
                default: printf("Invalid choice");
                             break;

	}
    }while(ch!=6);
}
int   binsearch(mobile st[],long  mobileno,int n)
{ 
          int i,j,k,comp=0;
          i=0;
          j=n-1;
          while(i<=j)
            {
	k=(i+j)/2;
	comp++;
	if(mobileno==st[k].mobileno)
	 {
	     printf("\nNo. of comparisons = %d ",comp);
	     return(k);
	  }
	 else
	    if(mobileno > st[k].mobileno)
	      j=k-1;
	    else
	      i=k+1;
	    }
	 printf("\nNo. of comparisons = %d ",comp);
	 return(-1);
}
void print(mobile  st[],int n)
{
   int i;
   for(i=0;i<n;i++)
   printf("\n%20s %15ld  %6.2f",st[i].name,st[i].mobileno,st[i].billamt);
}
void read(mobile st[],int n)
{ 
     int i;
     float billamt;
     long mobileno;
     printf("\n enter data(name   mobile No.(9 disgits max)   Bill Amount ): ");
      for(i=0;i<n;i++)
       {
         scanf("%s%ld%f",st[i].name,&mobileno,&billamt);
   	st[i].billamt=billamt;
	st[i].mobileno=mobileno;
       }
}

void insertionsort(mobile  a[],int n)
{
   int i,j,k,passes=0,comp=0;
   mobile temp;
   for(i=1;i<n;i++)
    {
        passes++;
       temp=a[i];
       for(j=i-1;j>=0 && a[j].mobileno < temp.mobileno;j--)
        {
           comp++;
           a[j+1]=a[j];
        }
        a[j+1]=temp;
    }

   printf("\nPasses = %d\t Comparisons = %d",passes,comp);
}

void selectionsort(mobile  a[],int n)
{
   int i,j,k,passes=0,comp=0;
   mobile temp;
    for(i=0;i<n-1;i++)
      {
         passes++;
         k=i;
         for(j=i+1;j<n;j++)
          {
             comp++;
             if(strcmp(a[j].name,a[k].name)< 0 )
	  k=j;
          }
            temp=a[i];
            a[i]=a[k];
            a[k]=temp;
       }
   printf("\nPasses = %d\t Comparisons = %d",passes,comp);
}
