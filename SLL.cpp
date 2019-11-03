#include<stdio.h>
#include<stdlib.h>
typedef struct node
   { int data;
     struct node *next;
   }node;

node *create();
node *insert_b(node *head,int x);
node *insert_e(node *head,int x);
node *insert_in(node *head,int x);
node *delete_b(node *head);
node *delete_e(node *head);
node *delete_in(node *head);
node *reverse(node *head);
void search(node *head);
void print(node *head);
void printreverse(node *head);
void main()
{ int ch,ch1,x;
  node *head=NULL;
  do
    {
      printf("\n\n1)create\n2)Insert\n3)Delete ");
      printf("\n4)Reverse\n5)Print\n6)Quit");
      printf("\nEnter your Choice:");
      scanf("%d",&ch);
      switch(ch)
       { 	
	  case 1: head=create();
                             break;

	  case 2: printf("\nEnter the data to be inserted : ");
		scanf("%d",&x);  
                             printf("\n\t1)Beginning\n\t2)End\n\t3)In between");
		printf("\nEnter your choice : ");
		scanf("%d",&ch1);
		switch(ch1)
		 {  case 1: head=insert_b(head,x);
			    break;
		    case 2: head=insert_e(head,x);
			    break;
		    case 3: head=insert_in(head, x);
			    break;
		  }
		break;
	 case 3:printf("\n\t1)Beginning\n\t2)End\n\t3)In between");
		printf("\nEnter your choice : ");
		scanf("%d",&ch1);
		switch(ch1)
		 {  case 1:head=delete_b(head);
			   break;
		    case 2:head=delete_e(head);
			   break;
		    case 3:head=delete_in(head);
			   break;
		  }
		 break;
	 
	 case 4:head=reverse(head);
	            print(head);
	            break;
	 case 5:print(head);
                           break;
               case 6:exit(0);
             default:printf("Invalid Choice");
                         break;
       }
    }while(ch!=7);
}

void printreverse(node *head)
  {
    if(head !=NULL)
       {
	  printreverse(head->next);
	  printf("%d   ",head->data);
       }
  }
node *create()
{ 
  node *head,*p;
  int i,n;
  head=NULL;
  printf("\n Enter no of data:");
  scanf("%d",&n);
  printf("\nEnter the data:");
  for(i=0;i<n;i++)
   {
     if(head==NULL)
	 p=head=(node*)malloc(sizeof(node));
     else
       {
	 p->next=(node*)malloc(sizeof(node));
	 p=p->next;
       }
       p->next=NULL;
       scanf("%d",&(p->data));
   }
 return(head);
}

node *insert_b(node *head,int x)
{   node *p;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    p->next=head;
    head=p;
    return(head);
}

node *insert_e(node *head,int x)
{   node *p,*q;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    p->next=NULL;
    if(head==NULL)
       return(p);
   for(q=head;q->next!=NULL;q=q->next);
    q->next=p;
    return(head);
}

node *insert_in(node *head,int x)
{   node *p,*q;
    int y;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    p->next=NULL;
    printf("\nInsert after which number ? : ");
    scanf("%d",&y);
   for(q=head ; q != NULL && q->data != y ; q=q->next);
    if(q!=NULL)
      {
	p->next=q->next;
	q->next=p;
      }
    else
       printf("\nData not found ");
    return(head);
}
node *delete_b(node *head)
{
  node *p,*q;
  if(head==NULL)
     {
	printf("\nLinked List is Empty");
	return(head);
     }
  p=head;
  head=head->next;
  free(p);
  return(head);

}
node *delete_e(node *head)
{
  node *p,*q;
  if(head==NULL)
     {
	printf("\nLinked List is Empty");
	return(head);
     }
  p=head;
  if(head->next==NULL)
     { 

       head=NULL;
       free(p);
       return(head);
     }

   for(q=head;q->next->next !=NULL;q=q->next)
   ;
   p=q->next;
   q->next=NULL;
   free(p);			
   return(head);
}
node *delete_in(node *head)
{
  node *p,*q;
  int x,i;
  if(head==NULL)
     {
	printf("\nLinked List is Empty");
	return(head);
     }
  printf("\nEnter the data to be deleted : ");
  scanf("%d",&x);
  if(head->data==x)
     { 
       p=head;
       head=head->next;
       free(p);
       return(head);
     }

   for(q=head;q->next->data!=x && q->next !=NULL;q=q->next )
   ;
   if(q->next==NULL)
     {
       printf("\nData not found");
       return(head);
     }
   p=q->next;
   q->next=q->next->next;
   free(p);
   return(head);
}

void print(node *head)
{ node *p;
 printf("\n\n");
 for(p=head;p!=NULL;p=p->next)
  printf("%d  ",p->data);
}

node *reverse(node *head)
  { node *p,*q,*r;
    p=NULL;
    q=head;
    r=q->next;
    while(q!=NULL)
      {
	q->next=p;
	p=q;
	q=r;
	if(q!=NULL)
	   r=q->next;
      }
   return(p);
  }
