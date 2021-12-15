#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char **string;
char *temp=NULL;
char* generate_parantheses1(int n)
{
	int i=0;
	char *str=(char *)malloc((sizeof(char)*n*2)+1);
	for (i=0;i<n;i++)
	{
		str[i]='(';
	}
	for (i=0;i<n;i++)
	{
		str[i+n]=')';
	}
	return str;
}

char* generate_parantheses2(int n)
{
	int i=0;
	char* str=(char *)malloc((sizeof(char)*n*2)+1);
	for (i=0;i<2*n;i++)
	{
		if (i%2==0)
		{
			str[i]='(';
		}
		else
		{
			str[i]=')';
		}	
	}
	return str;
}

char* generate_parantheses3(int n)
{
	int i=0;
	char *str=(char *)malloc((sizeof(char)*2)+1);
	if (n==1)
	{
		strcpy(str,"()");
	}
	
	str[0]='(';
	for (i=1;i<2*n-1;i++)
	{
		if (i%2==0)
		{
			str[i]=')';
		}
		else
		{	
			str[i]='(';
		}
	}
	str[2*n-1]=')';
	return str;
}

int check_pattern(char *str,int n)
{
	int lcount=0;
	int rcount=0;
	int i=0;
	for (i=0;i<strlen(str);i++)
	{
		if (str[i]=='(') lcount++;
		if (str[i]==')') rcount++;
	}
	printf("\n");
	if ((lcount == rcount) && lcount==n) return 1;
	return 0;
}

int main(int argc, char **argv)
{
	int n,i=0,len=0,j=0,len1=0,len2=0;
	int count=0;
	printf("\nEnter value for n:");
	scanf("%d",&n);
	string=(char **)malloc((sizeof(char*)*3*n)+1);
	for (i=n;i>0;i--)
	{
		string[count]=(generate_parantheses1(i));
		count++;
	}
	for (i=n;i>0;i--)
	{
		string[count]=(generate_parantheses2(i));
		count++;
	}
	for (i=n;i>0;i--)
	{
		string[count]=(generate_parantheses3(i));
		count++;
	}
	printf("\n");
	for (i=0;i<3*n;i++)
	{
		if (check_pattern(string[i],n)==1)
		{
			printf("\nValid pattern: %s",string[i]);
		}
	}
}
