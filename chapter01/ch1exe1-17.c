/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*	<C Programming Language Book>
	Chapter 1 ----- Exercise 1-17
	Manual: print all lines longer than 80 characters
*/
#include <stdio.h>
#define MAXLINE 2048
#define LONGER 80

int main()
{
	int length;
	int i , m;
	char line[MAXLINE];
	char memory[MAXLINE];
	char t ;

	i = 0;
/* 	Read characters in line[], different lines are recogonized by \n	*/
	while((t = getchar()) != EOF)
	{
		line[i] = t;
		++i;
	}

/*	Scan the characters line[] into memory[]
	If length is ok, print memory[] 	*/
	printf("All the text larger than %d are:\n",LONGER);
	length = 0;
	for (m = 0 ; m < i ; ++m)
	{
		t = line[m];
		memory[length] = t;
		if (t == '\n')
		{
			if (length > LONGER)
				printf("%s",memory);
			length = 0;
		}
		else
			++length;
	}
	return 0;
}
