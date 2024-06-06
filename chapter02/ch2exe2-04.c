/* 	Author Justin Yu --- University of Macau	*/
/*	Chapter 2 ----- Exercise 2-04-2      	          */
/*	Manual: function squeeze  */

#include<stdio.h>
#define MAX 1024

void squeeze(char s1[], char s2[]);
char words[]  = { "abc" };

int main()
{
	char txt[MAX];
	extern char words[];
	char c;
	int  i = 0;

	while((c = getchar()) != EOF)
		txt[i++] = c;

	txt[i] = '\0';
 	squeeze( txt, words );

	printf("\n %s",txt);
	return 0;
}

void squeeze( char s1[], char s2[] )
{
	int i = 0, j = 0, k= 0, s = 1;

	while( s1[i] != '\0' )
	{
		for(k = 0;k < 3 ; k++ )
			if(s1[i] == s2[k] )	s = 0;
		if(s)
			s1[j++] = s1[i];
		s = 1;
		i++;
	}
	s1[j] = '\0';
	return;
}

