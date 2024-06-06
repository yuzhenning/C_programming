/* 	This is an exercise of <C Programing Language> book Exercise 1-23-2 	*/
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
//	char memory[MAXLINE];
 	int  i;
	int  comstar;
	int  comslsh;
	int  linelength;
	char prev ;
	char now ;
	char next ;
//	int  m = 1;

	comstar = 0;
	comslsh = 0;

/*	inload characters	*/
	linelength = loadline();
//	printf("original:\n");
//	printf("%s",text);

	prev = text[0];
	now  = text[1];

/* 	Uncomments c program:
	run on next-char, depend on now-char 	*/
	printf("uncomments:\n");
	for(i = 2; i < linelength; ++i)
	{
		next = text[i];
		/* if comments are not open */
		if(!comstar && !comslsh)
		{
			if(now != '/')
//				memory[m++] = now;
				printf("%c",now);
			else if(now == '/')
			{
				if(next != '*' && next != '/')
//					memory[m++] = now;
					printf("%c",now);
				else if(next == '/' )
					comslsh = 1;
				else if(next == '*' )
				{
					comstar = 1;
					++i;
				}
			}
		}
		else if(comstar || comslsh)
		{
			if(prev == '*' && now == '/')
				comstar = 0;
			else if(now == '\n')
			{
				comslsh = 0;
//				memory[m++] = now;
				printf("\n");
			}
			else if(now == '/')
			{
				if(next == '/' )
					comslsh = 1;
				else if(next == '*' )
				{
					comstar = 1;
					++i;
				}
			}
		}
		prev = now;
		now = next;
	}
//	memory[m] = next;
	printf("%c",next);

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
	for(k = 0;(t = getchar()) != EOF; ++k)
	{
		text[k] = t;
	}
	text[k] = '\0';
	return k-1;
}
