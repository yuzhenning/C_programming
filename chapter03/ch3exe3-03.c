/* UNIVERSITY OF MACAU - JUSITN-YU
   Chapter3-03
   Mannal: funciton expand a-z in s1 to s2 as a...z
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 1024

void expand(char s1[], char s2[]);
int main()
{
	char s2[MAX];
	char s1[MAX];
/*		s1[] = {"a-D-i0-9\0"};
*/	char c;
	int  i= 0;
	while((c=getchar())!= EOF)
		s1[i++]=c;

	expand(s1,s2);
	printf("\ns1:%s",s1);
	printf("\ns2:%s",s2);
	printf("\n");
	return 0;
}

void expand(char s1[], char s2[])
{
	char rec;
	int i ,j ,incount, str, end;
	i = j = incount = str = end = 0;

	while(s1[i] != '\0')
	{
		rec = s1[i];
		if(isupper(s1[i]))
			s1[i] = tolower(s1[i]);
		if(!incount)
		{
			if((isalpha(s1[i]) || isdigit(s1[i]) ) && (s1[i+1] == '-') )
			{
				incount = 1;
				str = s1[i];
			}
		}
		else if(incount)
		{
			if((isalpha(s1[i]) || isdigit(s1[i]) ) && (s1[i+1] != '-') )
			{
				incount = 0;
				end = s1[i];
				while(str <= end)
					s2[j++] = str++;
			}
		}
		i++;
	}
	return;
}

