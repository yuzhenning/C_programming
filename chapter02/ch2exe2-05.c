/* 	Author Justin Yu --- University of Macau	*/
/*	Chapter 2 ----- Exercise 2-05      	          */
/*	Manual: any function to demo the first march position   */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 1024

int any(char s1[], char s2[]);

int main()
{
	char check[] = {"the"};
	char text[MAX];
	char c;
	int p, i = 0;

	while((c = getchar())!= EOF)	text[i++] = c ;
	text[i] = '\0';

	p = any(text, check);

	printf("\n%d",p);
	printf("\n---end!---\n");

	return 0;
}

int any(char s1[], char s2[])
{
	int a=0 , b=0 , p = -1;

	while( s1[a] != '\0' )
	{
		for(b= 0; b < 3; b++)
			if(s1[a] == s2[b])
			{
				p = a;
				return p;
			}
		a++;
	}
	return p;
}
