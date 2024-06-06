/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-09
	Manual: Copy and replace one or more blanks with only one blank
*/

#include<stdio.h>

int main()
{
	char c;
	char beforec;

		beforec = 'a';
		while((c = getchar())!=EOF)
		{
			if (c!=' ')
			{
				putchar(c);
			}
			else if (c==' ')
			{
				if (beforec != ' ')
					putchar(c);
			}
			beforec=c;
		}

	return 0;
}

