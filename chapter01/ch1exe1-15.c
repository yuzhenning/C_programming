/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*
	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-15
	Manual: Tempreture table with subfunction
*/

#include<stdio.h>
float fahr_to_celsius(float fahr);

int main()
{
	float fahr;
	float celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature scale */
	upper = 300;	/* upper limit */
	step  = 20;	/* step size */

	fahr  = lower;
	printf("\nfahr   celsius:\n");
	while (fahr <= upper)
	{
		celsius = fahr_to_celsius(fahr);
		printf("%3.2f\t%3.2f\n",fahr,celsius);

		fahr = fahr + step;
	}
	return 0;
}

float fahr_to_celsius(float f)
{
	return (5 * (f - 32)/9);
}
