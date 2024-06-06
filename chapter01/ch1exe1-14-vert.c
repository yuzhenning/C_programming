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
	int wnum, cnum;
	int nalpha[MAX];
	int cig[MAX];
	int i, count, k;
	float cfre;
	char c;
	int top;
	int diff;

	top   = 0;
	wnum  = 0;
	cnum  = 0;
	i     = 0;
	count = 0;
	for (i = 0; i < MAX; ++i)
	{
		nalpha[i] = 0;
	}

	printf("Please input words: \n");

	/* Scan and classify Characters */
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

	/* Searching the top value of histogram */
	for (i = 0; i < MAX ; ++i)
	{
		cig[i] = nalpha[i];
		if (top < nalpha[i])
			 top = nalpha[i];
	}

	/* computing each characters frequency */
	if (cnum > 0)
		cfre = (nalpha[i] /(float) cnum);

	printf("Words Vertical Histogram: \n");
	/*Counting from the top line*/
	for ( k = top; k > 0; --k )
	{
		printf("%2d | ",k);
		for( i = 0 ; i < MAX ; ++i)
		{
			diff = k - cig[i];
			if (diff > 0)
				printf("     ");
			else if (diff == 0)
				printf("  *  ");
			else
				printf("  *  ");
		}
		printf("\n");
	}
	/* Vertical histogram end */
	printf("------------------------------------------------------------\n");

	/* Printf A - Z characters*/
	printf("     ");
	for(i = 0 ; i < MAX ; ++i )
	{
		count = 'A' + i;
		printf("  %c  ", count);
	}
	printf("\n");

	/* Printf the value of each characters*/
	printf("     ");
	for(i = 0 ; i < MAX ; ++i )
	{
		printf(" %2d  ", nalpha[i]);
	}
	printf("\n");

	/* Printf the Frequency of each characters*/
	printf("   ");
	for(i = 0 ; i < MAX ; ++i )
	{
		printf ("%2.2f%c",cfre,37);
	}
	printf("\n");
	printf("Question: How to control histogram window's width? \n");

	printf("Program Terminated!\n");
	return 0;
}
