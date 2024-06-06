/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*
	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-18
	Manual: 1.remove line trailing blanks and tabs,
		2.delete entire blank lines
	tips: keep continue spaces in lines
*/

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 2048

char line[MAXLINE];
int loadline(void);

int main()
{
	int  textlength;		/* total text length */
	int  spacelength;		/* space length */
	int  tn;			/* there are text in line or not */
	int  s;				/* space string counter */
	int  l;				/* text  string counter*/
	extern char line[];		/* total data line */
	char space[MAXLINE];		/* a string record contiunes blanks and tabs */
	char t;				/* present char */
	char bt;			/* before char */

	spacelength = 0;
	tn= 0;
	s = 0;
	l = 0;
	bt= 'a';

/* 	Read characters in line[], separated lines-with \n	*/
	textlength = loadline();

/*	Scan the characters line[] save each line into memory[]
	Reorganize memory[] and print it!  	*/
	for(l = 0; l < textlength; ++l)
	{
		t = line[l];

		if(t == ' ' || t == '\t' )
		{
			++spacelength;
			space[s] = t;
			++s;
		}
		else if(t == '\n')
		{
			if(bt != '\n' && tn != 0)
			{
// 				printf("NL");	/* just for checking end of line */
				printf("\n");
			}
			tn = 0;
		}
		else
		{
			if(bt == ' ' || bt == '\t')
				printf("%s",space);
			printf("%c",t);
			for(s = 0; s < spacelength; ++s)
				space[s] = '\0';
			spacelength = 0;
			++tn;
		}
		bt = t;
	}

/*	END 	 */
	printf("\n");

	return 0;
}

/*	Loadline and return it to line[]	*/

int loadline(void)
{
	extern char line[];
	int  i;
	char t;
	while( (t = getchar()) != EOF)
	{
		line[i] = t;
		++i;
	}
	return i;
}
