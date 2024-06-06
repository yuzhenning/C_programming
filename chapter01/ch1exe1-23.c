/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*
	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-23
	Check comments
*/

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 2048

char text[MAXLINE];	/* current input char line */
int loadtext(void);

int main()
{
	extern char text[];
	int  textlength;
	int  in_comments;
	int  in_quote;
	int  i;

	in_comments = 0;
	in_quote = 0;
	textlength = loadtext();

	i = 0;
/* 	checkerror result		*/
	printf("Check Error Results: \n");

	while(i < textlength)
	{
		if(text[i] == '"')
			in_quote = 1;
		if(!in_quote)
		{
			if(!in_comments)
			{
				if(text[i] == '/' && text[i+1] == '*')
					in_comments = 1;
			}
			else if(in_comments)
			{
				if(text[i] == '*' && text[i+1] == '/')
					in_comments = 0;
			}
			else
				printf("%c",text[i]);
		}
		else
			printf("%c",text[i]);
		++i;
	}

/*----------END----------*/
	printf("\n");

	return 0;
}

/*	Loadline and return it to line[]	*/
int loadtext(void)
{
	extern char text[];
	int  i;
	char t;
	for(i = 0;i < MAXLINE-1 && (t = getchar()) != EOF; ++i)
		text[i] = t;
	text[i] = '\0';
	return i;
}

