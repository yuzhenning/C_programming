/*	University of Macau -- Zhenning Yu (Justin)
	Exercise 4-01
	Man: function strrindex(s,t)
*/

#include<stdio.h>
#include<string.h>
#define MAXLINE 1024

/*void reverse(char str[]);
*/
int getline(char s[], int lim);
int strrindex(char s[],char t[]);
char pattern[] = "ould";

int main()
{
	char line[MAXLINE];
	int loc = 0;

	while ( getline(line, MAXLINE) > 0)
	{
/*		printf("%s",line);
*/		loc = strrindex(line, pattern);
			printf("%d\n",loc);
	}
	printf("\n");
	return loc;
}

int getline(char s[], int lim)
{
	int i ;
	char c;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n' )
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* return position of rightmost occurrence of t in s */
int strrindex(char s[], char t[])
{
	int cs, ct, ls, lt, pos;
	pos = -1;
	ls = strlen(s)-1;
	/* return the rightest location t occure in eachline-s */
	for(cs = 0; cs < ls; cs++)
	{
		for(ct = 0, lt = strlen(t); s[cs]==t[ct]; cs++, ct++);
		if(ct > 0 && ct == lt)
			pos = cs -lt ;
	}
	return pos;
}
/*
void reverse(char str[])
{
	char c;
	int i , j;

	for(i = strlen(str), j = 0; i > j  ; i--, j++)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
}
*/
