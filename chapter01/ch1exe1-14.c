/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*
	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-14
	Manual: Print histogram of the frequencies of different characters in input
*/
#include<stdio.h>
#include<ctype.h>
#define MAX 26

int main()
{
	int num , wnum, cnum;
	int nalpha[MAX];
	int i, count;
	float x;
	char c;

	num = 0; wnum = 0; cnum = 0; i = 0; count = 0;

	for (i = 0; i < MAX; ++i)
	{
		nalpha[i] = 0;
	}
	while((c = getchar())!=EOF)
	{
		if ((c >= 'a') && (c <= 'z'))
		{
			++cnum;
			++nalpha[c-'a'];
		}
		else if ((c >= 'A') && (c <= 'Z'))
		{
			++cnum;
			++nalpha[c-'A'];
		}
		else if (isspace(c))
			++wnum;
	}

	printf("Total Charters: %d \n",cnum);
	printf("Total Spaces: %d \n",wnum);

	for (i = 0; i < MAX; ++i)
	{
		if (cnum > 0)
			x = (nalpha[i] /(float) cnum);
	/*	this is important for division	*/

		count = 'A' + i;
		printf ("%c is:%3d |%2.3f%c:",count,nalpha[i],x,37);

		for(num = 0; num < nalpha[i]; ++num)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("Program Terminated!\n");
	return 0;
}
