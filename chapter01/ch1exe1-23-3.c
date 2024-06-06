/* 	This is an exercise of <C Programing Language> book Exercise 1-23 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*	Manual:   Remove Comments 	*/
#include <stdio.h>
#include <ctype.h>
#define MAXLINE 2048

char text[MAXLINE];	/* current input char line */
int loadline(void);

int main()
{
	extern char text[];
 	int  i;
	int  in_quote;
	int  comstar;
	int  comslsh;
	int  linelength;

	in_quote = 0;
	comstar = 0;
	comslsh = 0;

/*	inload characters	*/
/* 	Uncomments c program 	*/
/*	printf("uncomments:\n");
*/	while((linelength = loadline()) > 0)
	{
		i = 0;
		comslsh = 0;
		while(i < linelength)
		{
			if(text[i] == '"')
				in_quote = 1;
			if(! in_quote)
			{
				if(text[i] == '/' && text[i+1] == '*')
				{
					i=i+2;
					comstar = 1;
				}
				if(text[i] == '*' && text[i+1] == '/')
				{
					i=i+2;
					comstar = 0;
				}
				if(text[i] == '/' && text[i+1] == '/')
				{
					i=i+2;
					comslsh = 1;
				}
				if(comstar == 1 || comslsh == 1)
				{
					i++;
					if(text[i] == '\n')
						comslsh = 0;
				}
				else
				{
					printf("%c",text[i]);
					i++;
				}
			}
			else
			{
				printf("%c",text[i]);
				i++;
			}
		}

	}

/*----------END----------*/
	printf("\n");
	return 0;
}

/*	Loadline and return it to line[]	*/
int loadline(void)
{
	extern char text[];
	int  k;
	char t;
	for(k = 0;(t = getchar()) != EOF && t != '\n'; ++k)
		text[k] = t;
	if(t == '\n')
	{
		text[k] = t;
		++k;
	}
	text[k] = '\0';
	return k;
}
