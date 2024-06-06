/* UNIVERSITY OF MACAU - JUSITN-YU
   Chapter3-06
   Mannal: funciton itoa(n,s,b) with minimum field width
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024

void reverse(char s[]);
void itoa(int n, char s[], int b);
int main()
{
	int num = 0x1a4c ;
	char string[MAX];
	itoa(num, string, 12);

	printf("\ndec:%d",num);
	printf("\nstr:%s",string);
	printf("\n");
	return 0;
}

void itoa(int n, char s[], int w)
{
	int i = 0, sign;
	if ((sign = n) < 0 )
		n = -n;  /* if n is negative, make it positive */

	do{
		s[i++] = n % 10 + '0';
	}
	while(( n /= 10 ) > 0);
	if(sign < 0)
		s[i++] = '-';
	while(i < w)
		s[i++] = ' ';
	s[i] = '\0';
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
