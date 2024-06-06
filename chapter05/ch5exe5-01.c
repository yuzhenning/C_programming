/* 	University of MACAU - Zhenning Yu (Justin)

   	exercise 05-01:
	remade getint function
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int c);
int getint(int *pn);

int main()
{
	int s = -1234;

	printf("%d\n",s);
	getint(s);
	printf("%d\n",s);

}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE )
		printf("ungetch: too many characters \n");
	else
		buf[bufp++] = c ;
}


int getint(int *pn)
{
	int c , sign;

	while (isspace(c = getch() ))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' )
	{
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
		c = getch();

	for(*pn = 0; isdigit(c); c = getch() )
		*pn *= 10 * *pn + (c - '0');
	*pn  *= sign ;
	if(c != EOF)
		ungetch(c);
	return c;
}
