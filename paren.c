#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char **string;
char **copystring;
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
	if ((lcount == rcount) && lcount==n) return 1;
	return 0;
}

int main(int argc, char **argv)
{
	int n,i=0,len=0,j=0,len1=0,len2=0,found=0;
	FILE *fp=NULL;
	int count=0;
	printf("\nEnter value for n:");
	scanf("%d",&n);
	string=(char **)malloc((sizeof(char*)*3*n)+1);
	fp=fopen("output.txt","w");
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
	for (i=0;i<3*n;i++)
	{
		if (check_pattern(string[i],n)==1)
		{
			printf("\nValid pattern: %s",string[i]);
			fwrite(string[i],strlen(string[i]),sizeof(char),fp);
			fwrite("\n",1,sizeof(char),fp);
		}
		if (check_pattern(string[i],n-2)==1)
		{
			printf("\nValid pattern: ()%s()",string[i]);
			fwrite("()",2,sizeof(char),fp);
			fwrite(string[i],strlen(string[i]),sizeof(char),fp);
			fwrite("()\n",3,sizeof(char),fp);
		}
	}
	/* assume same stack size as string */
	copystring=(char **)malloc((sizeof(char*)*3*n)+1);
	for (i=0;i<3*n;i++)
	{
		copystring[i]=(char *)malloc((sizeof(char)*strlen(string[i]))+1);
		strcpy(copystring[i],"");
	}
	for (i=0;i<3*n;i++)
	{
		for (j=0;j<3*n;j++)
		{
			if (strcmp(string[i],copystring[j])!=0 && strcmp(copystring[j],"")==0)
			{
				strcpy(copystring[j],string[i]);
				break;
			}
			else
			{
				if (strcmp(string[i],copystring[j])==0) break;
				else
					continue;
			}
		}
	}

	for (i=0;i<3*n;i++)
		printf("\ncopystring[%d]=%s",i,copystring[i]);
	for (i=0;i<3*n;i++)
	{
		for (j=3*n-1;j>=0;j--)
		{
			len1=strlen(copystring[i]);
			len2=strlen(copystring[j]);
			len=len1+len2;
			if (len == 2*n)
			{
				printf("\nValid Pattern: %s%s",copystring[i],copystring[j]);
				fwrite(copystring[i],strlen(copystring[i]),sizeof(char),fp);
				fwrite(copystring[j],strlen(copystring[j]),sizeof(char),fp);
				fwrite("\n",1,sizeof(char),fp);
				continue;
			}
		}
		printf("\n");
	}
	fclose(fp);
}
