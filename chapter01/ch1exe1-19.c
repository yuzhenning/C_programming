/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*
	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-19
	Manual: reverses input a line at a time
*/

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 2048

void reverse(char s[], char rev[], int l);
void demo (char characters[], int lim);
int  loadtext(char textline[]);

int main()
{
	char text[MAXLINE];
	char revtext[MAXLINE];
	char line[MAXLINE];
	char t;
	int  textlength;
	int  linelength;
	int  count;

/* 	Read characters in text[], separated lines-with \n	*/
//	printf("Input character strings: \n");

	textlength = loadtext(text);
//	printf("%s",text);

/*	reverse the text line   	*/
//	printf("Reverse character strings: \n");

	linelength = 0;
	for(count = 0; count < textlength; ++count)
	{
		t = text[count];
		line[linelength] = t;

		if(t == '\n')
		{
			reverse(line, revtext, linelength);

		/*	Demonstrate the revtext 	*/
			demo(revtext, linelength);
			linelength = 0;
		}

		else
			++linelength;
	}

/*----------END----------*/
//	printf("\n---Program END !--- \n");

	return 0;
}

void  reverse(char s[], char rev[], int l)
{
	int i, j;
	j = l;
	for(i = 0; i <= l; ++i)
	{
		rev[j] = s[i];
		--j;
	}
}

/*	Demonstrate lines      */
void demo (char characters[], int lim)
{
	int i = 0;
	char th;

	for (i = 0 ; i <= lim ; ++i)
	{
		th = characters[i];
		printf("%c",th);
	}
}

/*	Loadline and return it to line[]	*/
int  loadtext(char textline[])
{
	int  i = 0;
	char t;
	while((t = getchar()) != EOF)
	{
		textline[i] = t;
		++i;
	}
	return i;
}
