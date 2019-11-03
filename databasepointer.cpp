#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct employee
{ 
   int code;
   char name[20];
   int  salary;
}employee;
void read(employee *st,int n);
void insert(employee *st,int position,int n);
void Delete(employee *st,int position,int n);
employee * search(employee *st,int code,int n);
void print(employee *st,int n);
void sort(employee *st,int n);
void modify(employee *st,int n);
int main()
{
     employee st[30],*pos;
    int n,i,ch,code,position;
      do
     {
       printf("\n1)Create\n2)Insert\n3)Delete\n4)Search");
       printf("\n5)Print\n6)Sort\n7)Modify\n8)Quit");
       printf("\nEnter Your Choice:");
       scanf("%d",&ch);
       switch(ch)
		{ 
            case 1: printf("\nEnter No. of employees:");
		  scanf("%d",&n);
		  read(st,n);
		  break;
	    case 2: printf("\n enter the position(no of %d):",n);
		   scanf("%d",&position);
		  if(position<=n+1)
		   {
		     insert(st,position,n);
		     n++;
		     print(st,n);
		   }
		  else
		   printf("\n can not insert");
		  break;
	  case 3:printf("\n enter the code : ");
		 scanf("%d",&code);
		 pos=search(st,code,n);
		 if(pos != NULL )
		  {
		    Delete(st,pos-st,n);
		    n--;
		    print(st,n);
		  }
		else
		 printf("\n can not delete ");
		 break;
	  case 4: printf("\nenter code:");
		  scanf("%d",&code);
		  pos=search(st,code,n);
		  if(pos==NULL)
		    printf("\nnot found");
		  else
		   { printf("\n found at location=%ld",pos-st+1);
		     printf("\n %s\t%d\t%d",pos->name,pos->code,pos->salary);
		   }
		  break;
	  case 5: print(st,n);
		  break;

	  case 6: sort(st,n);print(st,n);
                  break;
	  case 7: modify(st,n);
                  print(st,n);
                  break;
                 case 8: 
                       exit(0);
					break;
	  default:printf("Invalid choice");
		  break;
	}
    }while(ch!=8);
 }
void  insert( employee *st,int position,int n)
{ int i;
	  printf("\n enter data(name code  salary): ");
	  for(i=n-1;i>=position-1;i--) 
		*(st+i+1)=*(st+i);
	  scanf("%s%d%d",(st+position-1)->name,&(st+position-1)->code,&(st+position-1)->salary);
}
void  Delete(employee st[],int position,int n)
{ int i;
	for(i=position+1;i<n;i++)
	    *(st+i-1)=*(st+i);
}
employee * search(employee *st,int code,int n)
{ employee *p;
	 for(p=st;p<st+n;p++)
	     if(code==p->code)
		 return(p);
	 return(NULL);
}
void print(employee *st,int n)
{ employee *p;
	 for(p=st;p<st+n;p++)
	      printf("\n %20s%5d%5d",p->name,p->code,p->salary);
}
void read(employee *st,int n)
{      employee *p;
	  printf("\n enter data(name code salary): ");
	  for(p=st;p<st+n;p++)
	       scanf("%s%d%d",p->name,&p->code,&p->salary);
}
void modify(employee *st, int n)
{
   int code;
   employee *pos;
   printf("\n Enter the code : ");
   scanf("%d",&code);
   pos=search(st,code,n);
   if(pos==NULL)
       printf("\nNo such rollno  ");
   else
     {
	  printf("\n enter data(name code salary): ");
	  scanf("%s%d%d",pos->name,&pos->code,&pos->salary);
      }
}
void sort(employee *st,int n)
{ int i,j;
   employee temp,*p;
   for(i=1;i<n;i++)
      for(p=st;p<st+n-i;p++)
       if(p->code > (p+1)->code)
	   {
	      temp=*p;
	      *p=*(p+1);
	      *(p+1)=temp;
	   }
}
