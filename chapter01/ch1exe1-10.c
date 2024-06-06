/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-10
	Manual:\t Copy and replace tab and backspace with backslash
*/
#include<stdio.h>

int main()
{
	char c;

	while((c = getchar()) != EOF)
	{
		if (c=='\t')
		{
			putchar('\\');
			putchar('t');
		}
		else if (c=='\b')
		{
			putchar('\\');
			putchar('b');
		}
		else if (c=='\\')
		{
			putchar('\\');
			putchar('\\');
		}
		else
			putchar(c);
	}

	return 0;
}
