/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*
	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-16
	Manual: print length of arbitrarily long input lines
*/

#include <stdio.h>
#define MA 10

int readline (char line[] , int limit);
void copy (char to[], char from[]);

/*	print longest input line	*/
int main()
{
	int len;
	int max;
	char line[MA];
	char longest[MA];

	max = 0;
	while ((len = readline(line,MA)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	}
	printf("The longest line length is %d, as following:\n",max-1);
	if (max > 0)
		printf("%s",longest);

	printf("\n");

	return 0;
}

/*	read a line into s , return length	*/
int readline (char s[] , int lim)
{
	int i, inf;
	char c;

	inf = 0;
	i = 0;
/*	for(i = 0; i < lim-1 && (c=getchar())!= EOF && c!= '\n'; ++i)
*/
	while(i < lim-1 && (c=getchar())!= EOF && c!= '\n')
	{
		if(i == lim-2)
			i = 0;
		s[i] = c;
		++inf;
		++i;
	}
	if(c == '\n')
	{
		s[i] = c;
		++inf;
	}

	s[i] = '\0';
	return inf;
}

/*	copy 'from' to ; assume 'to' is long enough	*/
void copy (char to[], char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
