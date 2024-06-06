/* UNIVERSITY OF MACAU - JUSITN-YU
   Chapter3-05
   Mannal: funciton itob(n,s,b)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024

void reverse(char s[]);
void itob(int n, char s[], int b);
int main()
{
	int num = 12 ;
	char string[MAX];
	itob(num, string,2);

	printf("\ndec:%d",num);
	printf("\nstr:%s",string);
	printf("\n");
	return 0;
}

void itob(int n, char s[], int b)
{
	int i = 0, j, sign;
	if ((sign = n) < 0 )
		n = -n;  /* if n is negative, make it positive */

	do{
		s[i++] = ((j=n%b) < 9) ? j + '0' : j+'a'-10;
	/* this is complex part:
		if j = n % b smaller than 9, donnot need characters.
				otherwise, use a-z represent
	*/
	}
	while(( n /= b) > 0);
	/*
		record the number if n = n/b is larger than 0
	*/
	if(sign < 0)
		s[i++] = '-';
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
