/* This is an exercise of c programming language book chapter1 */
/* ===== Chapter 1 --- Exercise 1-6  ===== */
/*
	C Programming Language Book>
	Chapter 1 ----- Exercise 1-6
*/
#include<stdio.h>

int main()
{
	char c;

	printf("\nThe getchar() != EOF value is: %d\n",((c = getchar())!=EOF));
/*	while((c = getchar()) != EOF)
	{
		printf("1");
	}
*/
	return 0;
}

