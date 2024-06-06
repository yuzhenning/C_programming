/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*
	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-24
	Check Syntax C-language Error of { [ (
*/
#include <stdio.h>
#include <ctype.h>
#define MAXLINE 2048


static char text[MAXLINE];	/* current input char line */

/*   SubFunctions   */
int loadtext(void);
int checking(char need, char now);

int main()
{
	extern char text[];
	int  memory[MAXLINE];
	char th;
	char bth;
	int  textlength;
	int  dismatch;
	int  i;
	int  j;
	int  m;

	i = 0;
	m = 0;

	textlength = loadtext();

/* 	checkerror result		*/
	printf("Check Error Results: \n");

	while(i < textlength)
	{
		th = text[i];
		if(th == '{' || th == '(' || th == '[')
			memory[m++] = th;
		else if(th == '}' || th == ')' || th == ']')
		{
			bth = memory[m-1];
			dismatch = checking(bth, th);
			if(dismatch)
			{
				if(m >= 1)
					printf("Dismatch as:%c %c\n",bth,th);
				else if(m < 1)
					printf("Dismatch as: %c\n",th);
			}
			m--;
		}
		++i;
	}

	for(j = 0; j < m; j++)
		printf("Dismatch as: %c\n",memory[j]);


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

/* checking matching syntax */
int checking(char need, char now)
{
	int dims;
	if(need == '{' && now == '}')
		dims = 0;
	else if(need == '[' && now == ']')
		dims = 0;
	else if(need == '(' && now == ')')
		dims = 0;
	else
		dims = 1;

	return dims;
}
