/* 	Author Justin Yu --- University of Macau	*/
/*	Chapter 2 ----- Exercise 2-10      	          */
/*	Manual:   rewrite lower function */

#include<stdio.h>

char lower(char x);

int main()
{
	char c;
	c = 'E';

	printf("\n%c",lower(c));
	printf("\n---end!---\n");
	return 0;
}

char lower(char x)
{
	return  x = (91>x)?x+32:x ;
}
