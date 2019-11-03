#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
void reverse(char *a);
int palindrome(char *a);
void copy(char *b,char *a);
int compare(char *a,char *b);
void search(char *a,char *b);

int main()
  { char a[50],b[50];
    int result,ch;
    do
      {printf("\n***MENU****");
	 printf("\n1.Reverse");
	 printf("\n2.Palindrome");
	 printf("\n3.Copy");
	 printf("\n4.String Comparison");
	 printf("\n5.String Searching(substring)");
	 printf("\n6.Quit");
	 printf("\n\nEnter Your Choice:");
	 scanf("%d",&ch);
	 switch(ch)
	  {
	    case 1: printf("Enter a String:");
		   scanf("%s",a);
		    reverse(a);
		    printf("\n Result=%s",a);
		    break;

	     case 2:  printf("\nEnter a String:");
		    scanf("%s",a);
		    result=palindrome(a);
		    if(result==0)
		      printf("\n  Not a palindrome");
		    else
		      printf("\n  A palindrome");
		      break;

	    case 3:  printf("\n Enter a String:");
		   scanf("%s",a);
		    copy(b,a);
		    printf("\n  Result=%s",b);
		    break;

	    case 4:  printf("\nEnter 1st string:");
		    scanf("%s",a);
		    printf("\nEnter 2nd string:");
		    scanf("%s",b);
		    result=compare(a,b);
		    if(result==0)
		      printf("\nBoth are same.");
		    else
		       if(result>0)
			 printf("\n  1st>2nd");
			   else
			     printf("\n  1st<2nd");
		     break;

	    case 5: printf("\nEnter 1st string:");
		    scanf("%s",a);
		    printf("\nEnter 2nd string:");
		    scanf("%s",b);
		    search(a,b);
		    break;
       case 6:    exit(0);
       default:    printf("Invalid choice");
	                   break;
	  }
  }while(ch!=6);
}

void reverse(char *a)
{ char *p,*q;
     char temp;
      p=q=a;
      while(*q!='\0')
       q++;	
      q--;		
      while(p<q)
       { 
         temp=*p;
         *p=*q;
         *q=temp;
           p++;q--;
       }
 }
int palindrome(char *a)
{ 
     char *p,*q;
      p=q=a;
      while(*q!='\0')
       q++;	
       q--;	
      while(p<q)
       { 
          if(*p!=*q)
	 return(0);
	 p++;q--;
       }
      return(1);
}
void copy(char *b,char *a)
     { 
       while(*a!='\0')
	{
                *b=*a;
	  a++;b++;
	}
       *b='\0';
     }
int compare(char *a,char *b)
{   
       while(*a!='\0')
        {
	if(*a > *b)
	     return(1);
	if(*a < *b)
	     return(-1);
	a++;b++;
      }
       return(0);
}
void search(char *a ,char *b)
{
     int lena,lenb;
    char *i,*j,*k;
    for(lena=0;*(a+lena)!='\0';lena++);
   for(lenb=0;*(b+lenb)!='\0';lenb++);
   for(i=a;i<=a+lena-lenb+1;i++)
    {  
       k=i;
       for(j=b;*k==*j&& *j!='\0';j++,k++);
       if(*j=='\0')
	     printf("\nString found at location:%ld",i-a+1);
    }
}
