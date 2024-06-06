/* 	Author Justin Yu --- University of Macau	*/
/*	Chapter 2 ----- Exercise 2-04      	          */
/*	Manual: function converts hexadecimal to integer value  */

#include<stdio.h>
#include<ctype.h>
#define MAX 1024

char text[MAX];	/* s1: the string for correct	*/
int squeeze(char s1[], char s2[]);

int main()
{
	extern char text[];
	int i , k;
	char check[] = "abc";

	k = squeeze(text, check);

/*      END !!     */
	for(i = 0; text[i] != '\0'; i++)
		printf("%c",text[i]);

	printf("\n---end!---\n");

	return 0;
}

int loadline(void)
{
	extern char text[];
	char c;
	int i = 0;

	while((c = getchar())!=EOF)
		text[i++] = c;
	text[i] = '\0';

	return i;
}

int squeeze(char s1[], char s2[])
{
	int s , k , j;
	int state;
	j = k = 0;

	for(k = 0; s1[k] != EOF; k++)
	{
		state = 0;
		for(s = 0; s2[s] != EOF; s++)
		{
			if(s1[k] == s2[s])
				state = 1;
			else
				state = 0;
		}
		if(state)
			s1[j++] = s1[k];
		k++;
	}
	s1[j] = '\0';

	return state;
}
