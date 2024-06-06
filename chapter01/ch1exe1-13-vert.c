/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*
	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-13
	Manual: Lengths of words vertical histogram
*/

#include<stdio.h>
#include<ctype.h>
#define MAX 26

int main()
{
	int leng, numwords, top;
	int diff;
	int i, k, m;
	int dig[MAX];
	int cig[MAX];
	char c;

	for (i = 0; i < MAX; ++i)
		dig[i] = 0;

        	leng = 0;
	    numwords = 0;
	         top = 0;
		   m = 0;

	while((c = getchar())!=EOF)
	{
		if (isalpha(c) || c == '-' || c == '\'')
			++leng;
		else if (isspace(c))
		{
			if (m < leng)
				m = leng;
			++numwords;
			++dig[leng];
			leng = 0;
		}
	}

	for (i = 1; i < MAX ; ++i)
	{
		cig[i] = dig[i];
		if (top < dig[i])
			 top = dig[i];
	}

	printf("There are %d Words \n",numwords);
	printf("The longest length is: %d \n",m);
	printf("Words Vertical Histogram: \n");

	for ( k = top; k > 0; --k )
	{
		printf("%2d | ",k);
		for( i = 1 ; i < MAX ; ++i)
		{
			diff = k - cig[i];
			if (diff > 0)
				printf("   ");
			else if (diff == 0)
				printf(" * ");
			else
				printf(" * ");
		}
		printf("\n");
	}

	printf("     ");
	for(i = 1 ; i < MAX ; ++i )
	{
		printf("%2d ", dig[i]);
	}

	printf("\n");
	printf("     ");
	for(i = 1 ; i < MAX ; ++i )
	{
		printf("%2d ", i);
	}

	printf("\n END \n");
	return 0;
}
