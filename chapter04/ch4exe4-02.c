/*	University of Macau -- Zhenning Yu (Justin)
	Exercise 4-02
	Man: rewrite function atof(char s)
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAXLINE 1024

int getline(char s[], int lim);
double atof(char s[]);

int main()
{
	double sum, atof(char s[]) ;
	char line[MAXLINE];
	int getline(char line[], int max);

	sum = 0;
	while(getline(line, MAXLINE) > 0)
		printf("%g\n", atof(line));

	printf("\n");
	return 0;
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

double atof(char s[])
{
	double val, power;
	int i = 0, sign, k;

	for(; isspace(s[i]); i++);	/*pass space before num*/

	sign = (s[i] == '-')? -1: 1;	/*identity posi or nega */
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 *val + (s[i] - '0');	/*record int num */
	if(s[i] == '.')			/* pass . */
		i++;

	for(power = 1.0; isdigit(s[i]); i++)	/*record num after. and count*/
	{
		val = 10.0 *val + (s[i] - '0');
		power *= 10.0;
	}

	if(s[i] == 'e' || s[i] == 'E')		/*inv count */
	{
		for(k = 0; k < (s[i+2]-'0');k++)
			power /= 10.0;
	}

	return sign * val /power;

}
