/* UNIVERSITY OF MACAU - JUSITN-YU
   Chapter3-02
   Mannal: escape function
*/

#include<stdio.h>
#include<ctype.h>
#define MAX 1024

void escape(char *s, char *t);
void unescape(char *s, char *t)
int main()
{
	char  c;
	char text2[MAX];
	int  i = 0;
/*
	while((c = getchar())!=EOF)
		text1[i++] = c;
	text1[i] = '\0';
*/
	char text1[50] = "THis \tis a \n testing file: b\b,a\a,v\v,f\f,!";
	escape(text2,text1);

	printf("\n%s",text2);
	printf("\n---End---\n");
	return 0;
}

void escape(char *s, char *t)
{
	int i = 0 ,j = 0;

	while(t[i])
	{
		switch (t[i])
		{
		case '\n':
			s[j++]='\\';
			s[j]='n';
			break ;
		case '\t':
			s[j++]='\\';
			s[j]='t';
			break ;
		case '\a':
			s[j++]='\\';
			s[j]='a';
			break ;
		case '\b':
			s[j++]='\\';
			s[j]='b';
			break ;
		case '\f':
			s[j++]='\\';
			s[j]='f';
			break ;
		case '\r':
			s[j++]='\\';
			s[j]='r';
			break ;
		case '\\':
			s[j++]='\\';
			s[j]='\\';
			break ;
		case '\"':
			s[j++]='\\';
			s[j]='\"';
			break ;
		default:
			s[j] = t[i];
			break;
		}
		j++;
		i++;
	}
	s[i] = t[j];
	return;
}


void unescape(char *s, char *t)
{
	int i = 0 ,j = 0;

	while(t[i])
	{
		switch(t[i])
		{
		case '\\':
			switch(t[i])
			{
				case 't':
					s[j] = '\t';
					break;
				case 'n':
					s[j] = '\t';
					break;
				case 'a':
					s[j] = '\t';
					break;
				case 'b':
					s[j] = '\t';
					break;
				case 'v':
					s[j] = '\t';
					break;
				case 'f':
					s[j] = '\t';
					break;
				case '\\':
					s[j] = '\\';
					break;
				case '"':
					s[j] = '\"';
					break;
				default:
					s[j] = t[i];
			}
			break;
		default:
			s[j] = t[i];
		}
		j++;
		i++;
	}
	s[i] = t[j];
	return;
}
