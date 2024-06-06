/* 	Author Justin Yu --- University of Macau	*/
/*	Chapter 2 ----- Exercise 2-08      	          */
/*	Manual:   turn n length in x from right to left */

#include<stdio.h>

unsigned rightrot(unsigned x, int n);

int main()
{
	int  n = 3 ;
	unsigned x = 301;

	printf("\nx:%u,ans:%u\n",x,rightrot(x,n));
	printf("\n---end!---\n");
	return 0;
}

unsigned rightrot(unsigned x,int n)
{
	unsigned rest, data, posi;
	posi = ~(~0<<(n)) ;
	rest = x & ~posi;
	data = x &  posi;
/*
	printf("rest:%u\n",rest);
	printf("data:%u\n",data);

*/	rest >>= n;
	data <<= (32-n);

	return rest | data;
}
