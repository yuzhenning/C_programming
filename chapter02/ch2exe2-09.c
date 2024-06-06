/* 	Author Justin Yu --- University of Macau	*/
/*	Chapter 2 ----- Exercise 2-09    */
/*	Manual:   faster bitcount function, count 1 bit in x */

#include<stdio.h>

unsigned bitcount(unsigned x);

int main()
{
	unsigned x = 300;

	printf("\nx:%u,ans:%u\n",x,bitcount(x));
	printf("\n---end!---\n");
	return 0;
}

unsigned bitcount(unsigned x)
{
	int b = 0;

	for(b = 0;x!= 0; x&= (x-1))
		b++;
	return b;
}
