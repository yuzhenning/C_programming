/*	University of Macau -- Zhenning Yu (Justin)
	Exercise 4-13
	reverse function
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define LINE 1024

int m = 0;
char memory[LINE];
void reverse(char s[]);

int main()
{
	char s[] = "!!ecnetnes esrever a si sihT";

	reverse(s);
	printf("%s\n", s);

	return 0;
}

void reverse(char s[])
{
	static int i = 0 , j = 0;
	extern char memory[];
	extern int m;

	if ( i < strlen(s) )
	{
		memory[m++] = s[i++];
		reverse(s);
	}
	i = 0;
	s[j++] = memory[--m];
	s[j] = '\0';
}
