/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/

#include<stdio.h>

int main()
{
	int blank, tab, newline;
	char c;

		blank = 0;
		tab = 0;
		newline = 0;

		while((c = getchar())!=EOF)
		{
			if (c == ' ')
				++blank;
			if (c == '\t')
				++tab;
			if (c == '\n')
				++newline;
		}
		printf("\nNumber of blank is %d,\nNumber of tab is %d,\nNumber of newline is %d.\n\n",blank,tab,newline);

	return 0;
}
