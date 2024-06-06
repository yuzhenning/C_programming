/*	University of Macau -- Zhenning Yu (Justin)
	Exercise 4-12
	rewrite itoa function in recurition style
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define LINE 1024

void itoa(int in, char s[]);

int main()
{
	int i = -123;
	char s[LINE];

	itoa(i, s);
	printf("%s\n", s);

	return 0;
}

void itoa(int in, char s[])
{
	static int i ;

	if (in / 10)
		itoa(in / 10, s);
	else
	{
		i = 0;
		if(in < 0)
			s[i++] = '-';
	}
	s[i++] = abs(in) % 10 + '0';
	s[i] = '\0';
}
