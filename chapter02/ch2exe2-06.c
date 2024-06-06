/* 	Author Justin Yu --- University of Macau	*/
/*	Chapter 2 ----- Exercise 2-06      	          */
/*	Manual:   replace n length bits at y tail to  x at position */

#include<stdio.h>
#include<stdlib.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
	int p = 5, n = 3 ;
	unsigned x = 181;
	unsigned y = 41;

	printf("x:%u,y:%u,ans:%u\n",x,y,setbits(x,p,n,y));
	printf("\n---end!---\n");
	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x& ( (~0 << (p))|(~(~0 << (p-n))) ) )|( ( y&(~(~0 << n)) ) << (p-n) );
}
