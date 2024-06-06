/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-11
*/
#include<stdio.h>
#include<ctype.h>

int main()
{
	char c;
	int count = 0;

	while((c = getchar())!=EOF)
	{
		if(isalpha(c))
		{
			count++;
		}
	}
	printf("words:%d\n",count);
	return 0;
}

