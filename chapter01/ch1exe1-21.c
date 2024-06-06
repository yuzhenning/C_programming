/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-21
	Manual:   Entab function
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

	int i;		/* i counting texts */
	int j, k;       /* k counting blanks, j counting tabs*/
	int numb  = 0;	/* number of total spaces  */
	int numpt = 0;	/* number of printf tabs   */
	int numpb = 0;	/* number of printf blanks */
	char th; 	/* Present char */

	i = 0;
	while((th = text[i]) != '\0')
	{
		if(th != ' ' && th != '\t')
		{
			numpb = (numb % 8);
				for(k = 0; k < numpb; ++k)
					printf(" ");
			numpt = (numb - numpb)/8;
				for(j = 0; j < numpt; ++j)
					printf("\t");
			printf("%c",th);
			numb = 0;
		}
		else
		{
			if(th == ' ')
				++numb;
			else if(th == '\t')
				numb = numb + 8;
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

