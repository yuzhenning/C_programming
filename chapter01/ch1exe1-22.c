/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*
	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-22
	Manual:   Fold long input lines
*/
#include <stdio.h>
#include <ctype.h>
#define MAXLINE 2048
#define LINELIMIT 10

char text[MAXLINE];
int loadtext(void);

int main()
{
	int  l;
	int  ct;
	int  linelength;
	char th;		/* present char */
	extern char text[];

 	linelength = 1;
	l = loadtext();

/*	printf("length limit:%d \n",LINELIMIT);
	printf("1---5---10---15---20---25---30---35---40---45---50\n");
*/
	for (ct = 0; ct < l; ++ct)
	{
		th = text[ct];
		if(linelength > (LINELIMIT-1))
		{
			if (th == ' ')
			{
				th = '\n';  	/* record there is a new line!!! */
				printf("\n");
				linelength = 1;
			}
			else
				printf("%c",th);
		}
		else
			printf("%c",th);
		++linelength;
	}

/*----------END----------*/
	printf("\n");

	return 0;
}

/* 	remove all space with single one blank! 	*/
int loadtext(void)
{
	int i;
	char c;
	char bc;
	extern char text[];

	while((c = getchar())!= EOF)
	{
//		if(c == ' ' || c == '\t' || c == '\n')
		if(isspace(c))
		{
			if((bc != ' ') && (bc != '\t') && (bc != '\n'))
			{
				text[i] = ' ';
				++i;
			}
		}
		else if(c != ' ' && c != '\t' && c != '\n')
		{
			text[i] = c;
			++i;
		}
		bc = c;
	}
	return i;
}

