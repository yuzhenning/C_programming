/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-12
	Manual: Prints inputs one word perline
	All the words must be separated by space	*/

#include<stdio.h>
#include<ctype.h>

int main()
{
	char c;
	char b = 'a';

	while((c = getchar())!=EOF)
	{
		if (!isspace(c))
		{
			putchar(c);
		}
		else if(isspace(c))
		{
			if (b!=' ' && b!='\t' && b!='\n')
			{
				printf("\n");
			}
		}
		b = c;
	}
	printf("\n");
	return 0;
}

