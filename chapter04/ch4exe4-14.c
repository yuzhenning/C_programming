/*	University of Macau -- Zhenning Yu (Justin)
	Exercise 4-14
	macro swap(t,x,y)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define LINE 1024
#define swap(t,x,y) { t   _z; \
 _z =  y; \
  y =  x; \
  x = _z; }

int main()
{	int a = 8, b = 10;

	swap(int,a,b);
	printf("%d,%d\n", a,b);

	return 0;
}
