/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*
	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-20
	Manual:   detab function
*/

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 2048

char text[MAXLINE];	/* current input char line */

void detab(void);
int  loadtext(void);

int main()
{
	int  textlength;
	extern char text[];

/* 	Read characters in text[], separated lines-with \n	*/
	textlength = loadtext();

/* 	Replace tab output to memory[] and print it!		*/
	detab();
/*----------END----------*/
	printf("\n");
	return 0;
}

void detab(void)
{
	extern char text[];

	int i ;
	int j ;
	int o ;
	int numb;
	int tabsize;
	char th;

	i = 0;
	o = 0;
	tabsize = 8;

	while((th = text[i]) != '\0')
	{
		if(th != '\t')
		{
			if(th == '\n')
			{
				printf("\n");
				o = 0;
			}
			else
			{
				printf("%c",th);
				++o;
			}
		}
		else
		{
			numb = tabsize - (o % tabsize);
			for (j = 0; j < numb; ++j)
			{
				printf(" ");
				++o;
			}
		}
		++i;
	}
	return;
}

/*	Loadline and return it to line[]	*/
int  loadtext(void)
{
	extern char text[];

	int  i = 0;
	char t;
	while((t = getchar()) != EOF)
	{
		text[i] = t;
		++i;
	}
	text[i] = '\0';
	return i;
}

