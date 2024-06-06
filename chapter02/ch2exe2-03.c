/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/
/*	Chapter 2 ----- Exercise 2-03-2nd      	          */
/*	Manual: function converts hexadecimal to integer value  */
/*
	1.load hexadecimal numbers as char
	2.recogonize char, classificate with a-f, digit and 0x
	3.transfer hex to integer
	4.compute  relate decimal value as:
		2AF3 = 2*16^3 + 10*16^2 + 15*16^1 + 3*16^0
*/

#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define MAX 1024

char line[MAX];

int htoi(char hex);
int loadline(void);
int nsquare(int n);

int main()
{
	extern char line[];
	char c;
	int  dec;
	int  expo;
	int  linecounter = 0;
	int  length;
	int  ans = 0;

	while((length = loadline()) > 0)
	{
		expo = length-2;
		if(line[0] == '0' && (line[1] == 'x' || line[1] == 'X'))
		{
			expo = expo-2;

			for(linecounter = 2; linecounter < length-1; linecounter++)
			{
				c = line[linecounter];
				/* ----- computing hex-string ----- */
					dec = htoi(c);
					ans = ans + dec*nsquare(expo);
					expo--;
			}
		}

		else
		{
			for(linecounter = 0; linecounter < length-1; linecounter++)
			{
				c = line[linecounter];
				/* ----- computing hex-string ----- */
					dec = htoi(c);
					ans = ans + dec*nsquare(expo);
					expo--;
			}
		}
		if(length > 1)
		{
			printf("Answer:%2.0d\n",ans);
			ans = 0;
		}
	}
/*      END !!     */
	printf("\n---end!---\n");

	return 0;
}

int htoi(char hex)
{
	int decimal;

	if(isdigit(hex))
		decimal = hex-'0';
	else if(hex > '@' && hex < 'G')
		decimal = hex-55;
	else if(hex > '`' && hex < 'g')
		decimal = hex-87;
/*
	else if(hex == 'x' || hex == 'X')
		decimal = 0;
*/
	else
		printf("error!\n");
	return decimal;
}

int loadline(void)
{
	extern char line[];
	char c;
	int i;

	for(i = 0;(c = getchar())!=EOF && c != '\n' && c!= ' ' && c!= '\t'; ++i)
		line[i] = c;
	if(c == '\n')
	{
		line[i] = c;
		++i;
	}
	else if(c == ' ' || c == '\t')
	{
		++i;
	}
	line[i] = '\0';

	return i;
}

/* computing 16 n times square */
int nsquare(int n)
{
	int i;
	int answer = 1;

	for(i = 0 ; i < n; ++i)
		answer = answer*16;

	return answer;
}

