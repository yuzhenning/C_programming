/* UNIVERSITY OF MACAU - JUSITN-YU
   Chapter3-01
   Mannal: rewrite search function with one test
*/

#include<stdio.h>
#define MAX 51
int binsearch(int x, int v[], int n );

int main()
{
	int num = 22, top = MAX;
	int sp[MAX] ;
	int i , data = 12;

	for(i=0; data<top; i++)
		sp[i] = data++;

	printf("\nlocate:%d",binsearch(num,sp,top));
	printf("\n---End---\n");
	return 0;
}

int binsearch(int x, int v[], int n )
{
	int low, high, mid;
	low = 0;
	high = n-1;
		mid = (low +high)/2;

	while((low <= high) && (x != v[mid]))
	{
		mid = (low +high)/2;
		if(x < v[mid])
			high = mid - 1;
		else
			low = mid + 1 ;
	}
	return (x == v[mid]) ? mid : -1;
}
