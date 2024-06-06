/* This is an exercise of c programming language book chapter1 */
/* chapter 1 	exercise 1-4 */
/* Print Celsius-Fahrenheit table for fahr = 0,20,...,300 */

#include<stdio.h>

int main()
{
	int fahr , celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature scale */
	upper = 300;	/* upper limit */
	step  = 20;	/* step size */

	celsius  = lower;
	printf("Celsius \t Fahrenheit \n");
	while (celsius <= upper)
	{
		fahr = ((celsius * 9 )/ 5)+32;
		printf("%d \t\t %d \n",celsius,fahr);
		celsius = celsius + step;
	}
	return 0;
}
