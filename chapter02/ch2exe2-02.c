/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*
	*		<C Programming Language Book>             *
	*	Chapter 2 ----- Exercise 2-02      	          *
	* Manual: Loop equivalent to the for loop without &&, ||  *
*/
#include <stdio.h>
#define BUFF 1024

int main()
{
	int i;
	char c;
	char text[BUFF];

	i = 0;
	while((c = getchar()) != EOF)
	{
		if(c != '\n')
			text[i] = c;
		++i;
	}
	printf("%s",text);

	printf("\n");
	return 0;
}
