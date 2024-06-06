/* UNIVERSITY OF MACAU - JUSITN-YU
   Chapter3-04
   Mannal: reverse function itoa
*/

#include<stdio.h>
#include<string.h>
#define MAX 32

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
	char s[MAX] = {"-123947593094"};
	int  n = 10;
	printf("\n%s",s);

	itoa(n, s);

	printf("\n%s",s);
	printf("\n");

	return 0;
}

void itoa(int n, char s[])
{
	int i , sign;
	void reverse(char s[]);

	if ((sign = n) < 0 )
		n = -n;
	i = 0;
	do{
		s[i++] = n % 10 + '0';
	}	while( (n/=10) > 0 );
	if(sign < 0)
		s[i++] = '-';
	reverse(s);
}

void reverse(char s[])
{
	int c, i, j;
	for(i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
