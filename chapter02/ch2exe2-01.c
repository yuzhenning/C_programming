/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*
	*		<C Programming Language Book>             *
	*	Chapter 2 ----- Exercise 2-01      	          *
	* Manual: Determine ranges of char short int etc          *
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("size of   Signed char  is %d, values between %d and %d\n",CHAR_BIT,CHAR_MIN,CHAR_MAX);
	printf("size of   Signed int   is between %d and %d\n",INT_MIN,INT_MAX);
	printf("size of   Signed long  is between %ld and %ld\n",LONG_MIN,LONG_MAX);
	printf("size of   Signed short is between %d and %d\n",SHRT_MIN,SHRT_MAX);
	printf("size of Unsigned char  is %u\n",UCHAR_MAX);
	printf("size of Unsigned int   is %u\n",UINT_MAX);
	printf("size of Unsigned long  is %lu\n",ULONG_MAX);
	printf("size of Unsigned short is %u\n",USHRT_MAX);

	printf("\n");
	return 0;
}
