#include<stdio.h>
void length(char s[10]);
void copy(char s[10],char t[10]);
void concate(char s[10],char t[10]);
void reverse(char s[10],char t[10]);
int palindrome(char s[10]);
int compare(char s[10],char t[10]);

void main()
{
	int ch,n;
	char s[10],t[10];
	do
	{
	printf("\nMenu\n");
	printf("\n1) Lenth\n");
	printf("\n2) Copy\n");
	printf("\n3) Concate\n");
	printf("\n4) Reverse\n");
	printf("\n5) Palindrome\n");
	printf("\n6) Compare\n");
	printf("\nEnter your choice\n");
	scanf("%d",&ch);
	switch(ch)
		{
		case 1: printf("\nEnter string\n");   scanf("%s",s);
			length(s); 
			break;
		case 2: printf("\nEnter string\n");  scanf("%s",s);
			copy(s,t);
			break;
		case 3: printf("\nEnter first string\n");  scanf("%s",s); 
			printf("\nEnter second string\n");  scanf("%s",t);
			concate(s,t);
			break;
		case 4: printf("\nEnter the string\n");  scanf("%s",s);
			printf("\nReverse of string is \n");
			reverse(s,t);
			break;
		case 5: printf("\nEnter the string\n");   scanf("%s",s);
			n=palindrome(s);
			if(n==0)
			{	printf("\nString is palindrome\n"); }
			else
			{	printf("\nString is not palindrome\n"); }
			break;
		case 6: printf("\nEnter the first string\n"); scanf("%s",s);
		        printf("\nEnter the second string\n"); scanf("%s",t);
			n=compare(s,t);
			if(n==0)
			{  printf("\nStrings are equal\n"); }
			else if(n==-1)
			{  printf("\nSecond string is greater\n"); }
			else
			{  printf("\nFirst string is greater\n"); }
			break;
                default: printf("\nINVALID CHOICE. ");
                        break;  
		}				
	}
	while(ch<7);
}

void length(char s[10])
{
	int i=0;
	while(s[i]!='\0')
	{	i++;	}
	printf("\nLength of string is %d\n",i);
}

void copy(char s[10],char t[10])
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{	t[i]=s[i];	}
	t[i]='\0';
	printf("\nCopied string is %s\n",t);
}

void concate(char s[10],char t[10])
{
	int i;
	for(i=0;s[i]!='\0';)
	{	i++;	}
	int j;
	for(j=0;t[j]!='\0';)
	{
		s[i]=t[j];
		i++;
		j++;
	}
	s[i]='\0';
	printf("\nConcated string is %s\n",s);
}

void reverse(char s[10],char t[10])
{
	int i=0,j=0;
	while(s[i]!='\0')
	{	i++;	}
	i--;
	while(i>=0)
	{
		t[j]=s[i];
		i--;
		j++;
	}
	t[j]='\0';
	printf("%s",t);

}

int palindrome(char s[10])
{
	int i=0,j=0;
	while(s[i]!='\0')
	{	i++;	}
	i--;
	while(i>j)
	{
		if(s[i]==s[j])
		{	i--;	j++;	}
		else
		{	return 1;	}
	}
	return 0;
}

int compare(char s[10],char t[10])
{
	int i=0,j=0;
	while(s[i]!='\0')
	{
		if(s[i]==t[j])
		{	i++;	j++;	}
		else if(s[i]<t[j])
		{	return -1;	}
		else
		{	return 1;	}
	}
	return 0;
}
