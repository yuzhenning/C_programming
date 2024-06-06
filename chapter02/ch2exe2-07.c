/* 	Author Justin Yu --- University of Macau	*/
/*	Chapter 2 ----- Exercise 2-07      	          */
/*	Manual:   invert n length bits in x at position */

#include<stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
	int p = 5, n = 3 ;
	unsigned x = 85;

	printf("x:%u,ans:%u\n",x,invert(x,p,n));
	printf("\n---end!---\n");
	return 0;
}

unsigned invert(unsigned x, int p, int n)
{
	unsigned rest, invx, posi;
	posi = (~0<<p)^(~0<<(p-n)) ;
	rest = x & (~posi);
	invx = x | (~posi);
	invx  = ~invx;
	return rest | invx;
}
