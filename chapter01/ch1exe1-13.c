/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*
	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-13
	Manual: Lengths of words horizontal histogram
*/

#include<stdio.h>
#include<ctype.h>
#define MAX 20

int main()
{
	int leng, numwords;
	int i, k ,n;
	int dig[MAX];
	char c;

	for (n = 0; n < MAX; ++n)
		dig[n] = 0;

	leng = 0;
	numwords = 0;

	while((c = getchar())!=EOF)
	{
		if (isalpha(c) || c == '-' || c == '\'')
			++leng;
		else if (isspace(c))
		{
			++numwords;
			++dig[leng];
			leng = 0;
		}
	}

	printf("The Words Amount is: %d \n",numwords);
	printf("Words histogram \n");
	printf("Length: Amount: \n");

	for ( i = 1; i <= MAX ; ++i)
	{
		printf("   %2d: %3d |",i,dig[i]);
		for (k = 1; k <= dig[i]; ++k)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n END \n");

	return 0;
}
