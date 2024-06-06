/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-11
	Manual: Words count program
*/
#include<stdio.h>
#include<ctype.h>

int main()
{
	int wordnum;
	char c;

	wordnum = 0;
	while((c = getchar())!=EOF)
	{
		if (isalpha(c))
			++wordnum;
	}
	printf("There are %d words.\n",wordnum);
	return 0;
}

