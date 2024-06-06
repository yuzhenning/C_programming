/* This is an exercise of c programming language book chapter1 */
/* ===== Chapter 1 --- Exercise 1-5 ===== */

#include<stdio.h>

int main()
{
	float fahr , celsius;
	int step;

	step = 20;

	printf("Celsius Fahrenheit \n");

	for (celsius = 300; celsius >= 0; celsius = celsius - step)
	{
		fahr = (9.0/5.0)*celsius+32;
		printf("%3.2f \t %3.2f\n", celsius, fahr);
	}
	return 0;
}
