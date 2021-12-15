#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* generate_parantheses1(int n)
{
	int i=0;
	char *str=(char *)malloc((sizeof(char)*n*2)+1);
	printf("\nn=%d",n);
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

int main(int argc, char **argv)
{
	int n,i=0;
	char **string;
	printf("\nEnter value for n:");
	string=(char **)malloc((sizeof(char)*3*n)+1);
	scanf("%d",&n);
	for (i=n;i>0;i--)
	{
		string[n-i]=(char *)malloc((sizeof(char)*2*n)+1);
		string[n-i]=generate_parantheses1(i);
	}
	for (i=n;i>0;i--)
	{
		string[2*n-i]=(char *)malloc((sizeof(char)*2*n)+1);
		string[2*n-i]=generate_parantheses2(i);
	}
	for (i=n;i>0;i--)
	{
		string[3*n-i]=(char *)malloc((sizeof(char)*2*n)+1);
		string[3*n-i]=generate_parantheses3(i);
	}
	for (i=0;i<3*n;i++)
	{
		printf("\nstring[%d]=%s",i,string[i]);
	}
}
